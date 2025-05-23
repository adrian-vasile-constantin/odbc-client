﻿module;

#include "intellisense/project_headers.hh"

export module HelpCommand;

#if !defined MSVC_INTELLISENSE
import std;
import Context;
import CommandHandler;
#endif

class HelpCommand: public CommandHandler
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

inline std::unique_ptr<HandlerFunctor> HelpCommand::handlerFunctor(Context &context, istream &cin, ostream &cout, ostream &cerr, ostream &clog)
{
    return std::make_unique<Functor>(*this, context, cin, cout, cerr, clog);
}

module :private;

using std::set;
using std::map;
using std::string;
using std::string_view;
using std::for_each;
using namespace std::literals::string_literals;

set<string> const &HelpCommand::commandNames() const
{
    static set<string> nameList { ".help" };

    return nameList;
}

string const &HelpCommand::helpSubject() const
{
    static string subjectLine = "\t.help <.command-name>			Show help for a command"s;

    return subjectLine;
}

string const &HelpCommand::helpText() const
{
    static string textLines =
	"\t.help			    Show summary of commands\n"
	"\t.help <.command-name>	    Show help for specified command\n"s;

    return textLines;
}

static set<string> helpSummary;
static map<string, CommandHandler *> helpCommandHandlers;

void HelpCommand::Functor::operator ()(string const &command, string::const_iterator it)
{
    string commandName;

    while (it != command.end() && " \t\r\n\f\v"s.find(*it) != string::npos)
	it++;

    if (it != command.end())
	commandName = string { it, command.end() };

    if (helpSummary.empty())
    {
	for (string const &subjectLine : { "\t.exit					Exit DB Cmd", "\t.disconnect				Disconnect the active ODBC connection." })
	    helpSummary.insert(subjectLine);

	for (CommandHandler *handler = CommandHandler::first; handler; handler = handler->next)
	{
	    helpSummary.insert(handler->helpSubject());

	    for (auto const &commandName : handler->commandNames())
		helpCommandHandlers.emplace(commandName, handler);
	}
    }

    if (commandName.empty())
    {
	for_each(helpSummary.begin(), helpSummary.end(), [this](auto const &helpLine) -> void
	    {
		clog << helpLine << '\n';
	    });
    }
    else
    {
	auto it = helpCommandHandlers.find(commandName);

	if (it == helpCommandHandlers.end())
	    clog << "No such command\n";
	else
	    clog << it->second->helpText();
    }

    clog << '\n';
};

HelpCommand helpCommand;
