﻿module;

#include "intellisense/project_headers.hh"

export module BrowseConnect;

#if !defined MSVC_INTELLISENSE
import std;
import Context;
import CommandHandler;
#endif

class BrowseConnect: public CommandHandler
{
public:
    class Functor: public HandlerFunctor
    {
    public:
	using HandlerFunctor::HandlerFunctor;
	virtual void operator ()(string const &command, string::const_iterator it) override;
    };

    virtual set<string> const &commandNames() const override;
    virtual string const &helpSubject() const override;
    virtual string const &helpText() const override;
    virtual unique_ptr<HandlerFunctor> handlerFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog) override;
};

inline std::unique_ptr<HandlerFunctor> BrowseConnect::handlerFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog)
{
    return std::make_unique<Functor>(*this, context, cin, cout, cerr, clog);
}

module: private;

using std::size_t;
using std::set;
using std::pair;
using std::tuple;
using std::string;
using std::string_view;
using std::find;
using std::find_if;
using std::max;
using std::setw;
using std::left;
using namespace std::literals::string_literals;
namespace execution = std::execution;

using odbc::Environment;
using odbc::Connection;

set<string> const &BrowseConnect::commandNames() const
{
    static set<string> const names { ".browseConnect" };

    return names;
}

string const &BrowseConnect::helpSubject() const
{
    static string subjectLine = "\t.browseConnect <attribute>=<value>;...  Query ODBC driver for the connection attributes"s;

    return subjectLine;
}

string const &BrowseConnect::helpText() const
{
    static string textLines =
	"\t.browseConnect <attribute>=<value>;...   Query ODBC driver for the connection attributes\n"
	"\n"
	"Start with the DRIVER or DSN attribute, then provide values for the parameters displayed by .browseConnect by running\n"
	"the command again, with the new parameters. The selected driver must support the needed connect function.This is\n"
	"given in the driver ConnectFunctions attribute on character position 3. An asterisk * displayed in front of an \n"
	"attribute name means the attribute is optional. After providing all the needed attributes using repeated calls to\n"
	".browseConnect, the command will establish a new connection to the data source described by the accumulated attribute\n"
	"values.\n"s;

    return textLines;
}

static tuple<string, string, string> parseConnectionAttribute(pair<string, string> const &attribute)
{
    auto it = find(execution::par_unseq, attribute.first.begin(), attribute.first.end(), ':');
    string optionalMarker, attributeName, displayName;

    if (!attribute.first.empty() && *attribute.first.cbegin() == '*')
    {
	optionalMarker = string { attribute.first.cbegin(), ++attribute.first.cbegin() };

	if (it == attribute.first.end())
	    attributeName = string { ++attribute.first.cbegin(), attribute.first.end() };
	else
	{
	    attributeName = string { ++attribute.first.cbegin(), it };
	    displayName = string { ++it, attribute.first.end() };
	}
    }
    else
	if (it == attribute.first.end())
	    attributeName = string { attribute.first.cbegin(), attribute.first.end() };
	else
	{
	    attributeName = string { attribute.first.cbegin(), it };
	    displayName = string { ++it, attribute.first.end() };
	}

    return tuple { optionalMarker, attributeName, displayName };
}

void BrowseConnect::Functor::operator ()(string const &command, string::const_iterator it)
{
    while (it != command.end() && " \t\r\n\f\v"s.find(*it) != string::npos)
	it++;

    if (it != command.end() || conn->connected())
    {
	auto attributes = conn->browseConnect(Environment::splitAttributes(string(it, command.end()), ';'));

	unsigned optionalMarkerLength = 0u, attributeNameLength = 0u, displayNameLength = 0u;

	for (auto const &attribute: attributes)
	{
	    auto [optionalMarker, attributeName, displayName] = parseConnectionAttribute(attribute);

	    optionalMarkerLength = (std::max<size_t>)(optionalMarkerLength, optionalMarker.size());
	    attributeNameLength = (std::max<size_t>)(attributeNameLength, attributeName.size());
	    displayNameLength = (std::max<size_t>)(displayNameLength, displayName.size());
	}

	for (auto const &attribute: attributes)
	{
	    auto [optionalMarker, attributeName, displayName] = parseConnectionAttribute(attribute);

	    if (optionalMarkerLength && optionalMarker.empty())
		optionalMarker = string_view { " " };


	    cout << '\t' << optionalMarker
		<< setw(attributeNameLength) << left << attributeName << " : "
		<< setw(displayNameLength) << left << displayName << " => "
		<< attribute.second << '\n';
	}
    }
    else
    {
	cout
	    << '\t' << "DSN    = ?\n"
	    << '\t' << "DRIVER = ?\n";
    }

    cout << '\n';
}

static BrowseConnect browseConnectCmd;
