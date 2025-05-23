module;

#if defined(_WINDOWS)
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#include <windef.h>
#include <WinBase.h>

export module winapi.WinBase;

#if !defined __INTELLISENSE__
import winapi.WinDef;
#endif

namespace
{
    auto constexpr
	local_FORMAT_MESSAGE_ALLOCATE_BUFFER = FORMAT_MESSAGE_ALLOCATE_BUFFER,
	local_FORMAT_MESSAGE_ARGUMENT_ARRAY  = FORMAT_MESSAGE_ARGUMENT_ARRAY,
	local_FORMAT_MESSAGE_FROM_HMODULE    = FORMAT_MESSAGE_FROM_HMODULE,
	local_FORMAT_MESSAGE_FROM_STRING     = FORMAT_MESSAGE_FROM_STRING,
	local_FORMAT_MESSAGE_FROM_SYSTEM     = FORMAT_MESSAGE_FROM_SYSTEM,
	local_FORMAT_MESSAGE_IGNORE_INSERTS  = FORMAT_MESSAGE_IGNORE_INSERTS,
	
	local_FORMAT_MESSAGE_MAX_WIDTH_MASK  = FORMAT_MESSAGE_MAX_WIDTH_MASK;

    auto constexpr
	local_LHND		= LHND,
	local_LMEM_FIXED	= LMEM_FIXED,
	local_LMEM_MOVEABLE	= LMEM_MOVEABLE,
	local_LMEM_ZEROINIT	= LMEM_ZEROINIT,
	local_LPTR		= LPTR,
	local_NONZEROLHND	= NONZEROLHND,
	local_NONZEROLPTR	= NONZEROLPTR,
	local_LMEM_DISCARDABLE	= LMEM_DISCARDABLE,
	local_LMEM_NOCOMPACT	= LMEM_NOCOMPACT,
	local_LMEM_NODISCARD	= LMEM_NODISCARD;

    auto constexpr
	local_GHND		= GHND,
	local_GMEM_FIXED	= GMEM_FIXED,
	local_GMEM_MOVEABLE	= GMEM_MOVEABLE,
	local_GMEM_ZEROINIT	= GMEM_ZEROINIT,
	local_GPTR		= GPTR,
	local_GMEM_DDESHARE	= GMEM_DDESHARE,
	local_GMEM_DISCARDABLE	= GMEM_DISCARDABLE,
	local_GMEM_LOWER	= GMEM_LOWER,
	local_GMEM_SHARE	= GMEM_SHARE,
	local_GMEM_NOCOMPACT	= GMEM_NOCOMPACT,
	local_GMEM_NODISCARD	= GMEM_NODISCARD,
	local_GMEM_NOT_BANKED	= GMEM_NOT_BANKED,
	local_GMEM_NOTIFY	= GMEM_NOTIFY;

    constexpr auto
	local_STD_INPUT_HANDLE	  = STD_INPUT_HANDLE,
	local_STD_OUTPUT_HANDLE   = STD_OUTPUT_HANDLE,
	local_STD_ERROR_HANDLE    = STD_ERROR_HANDLE;
}

#undef FORMAT_MESSAGE_ALLOCATE_BUFFER
#undef FORMAT_MESSAGE_ARGUMENT_ARRAY
#undef FORMAT_MESSAGE_FROM_HMODULE
#undef FORMAT_MESSAGE_FROM_STRING
#undef FORMAT_MESSAGE_FROM_SYSTEM
#undef FORMAT_MESSAGE_IGNORE_INSERTS
	
#undef FORMAT_MESSAGE_MAX_WIDTH_MASK

#undef LHND
#undef LMEM_FIXED
#undef LMEM_MOVEABLE
#undef LMEM_ZEROINIT
#undef LPTR
#undef NONZEROLHND
#undef NONZEROLPTR
#undef LMEM_DISCARDABLE
#undef LMEM_NOCOMPACT
#undef LMEM_NODISCARD

#undef GHND
#undef GMEM_FIXED
#undef GMEM_MOVEABLE
#undef GMEM_ZEROINIT
#undef GPTR
#undef GMEM_DDESHARE
#undef GMEM_DISCARDABLE
#undef GMEM_LOWER
#undef GMEM_SHARE
#undef GMEM_NOCOMPACT
#undef GMEM_NODISCARD
#undef GMEM_NOT_BANKED
#undef GMEM_NOTIFY

#undef STD_INPUT_HANDLE
#undef STD_OUTPUT_HANDLE
#undef STD_ERROR_HANDLE

#undef FormatMessage
#undef GetEnvironmentVariable
#undef SetEnvironmentVariable

namespace winapi
{
    export auto constexpr
	FORMAT_MESSAGE_ALLOCATE_BUFFER = local_FORMAT_MESSAGE_ALLOCATE_BUFFER,
	FORMAT_MESSAGE_ARGUEMENT_ARRAY = local_FORMAT_MESSAGE_ARGUMENT_ARRAY,
	FORMAT_MESSAGE_FROM_HMODULE    = local_FORMAT_MESSAGE_FROM_HMODULE,
	FORMAT_MESSAGE_FROM_STRING     = local_FORMAT_MESSAGE_FROM_STRING,
	FORMAT_MESSAGE_FROM_SYSTEM     = local_FORMAT_MESSAGE_FROM_SYSTEM,
	FORMAT_MESSAGE_IGNORE_INSERTS  = local_FORMAT_MESSAGE_IGNORE_INSERTS,
	
	FORMAT_MESSAGE_MAX_WIDTH_MASK  = local_FORMAT_MESSAGE_MAX_WIDTH_MASK;

    export auto constexpr
	LHND		    = local_LHND,
	LMEM_FIXED	    = local_LMEM_FIXED,
	LMEM_MOVEABLE	    = local_LMEM_MOVEABLE,
	LMEM_ZEROINIT	    = local_LMEM_ZEROINIT,
	LPTR		    = local_LPTR,
	NONZEROLHND	    = local_NONZEROLHND,
	NONZEROLPTR	    = local_NONZEROLPTR,
	LMEM_DISCARDABLE    = local_LMEM_DISCARDABLE,
	LMEM_NOCOMPACT	    = local_LMEM_NOCOMPACT,
	LMEM_NODISCARD	    = local_LMEM_NODISCARD;

    export auto constexpr
	GHND		    = local_GHND,
	GMEM_FIXED	    = local_GMEM_FIXED,
	GMEM_MOVEABLE	    = local_GMEM_MOVEABLE,
	GMEM_ZEROINIT	    = local_GMEM_ZEROINIT,
	GPTR		    = local_GPTR,
	GMEM_DDESHARE	    = local_GMEM_DDESHARE,
	GMEM_DISCARDABLE    = local_GMEM_DISCARDABLE,
	GMEM_LOWER	    = local_GMEM_LOWER,
	GMEM_SHARE	    = local_GMEM_SHARE,
	GMEM_NOCOMPACT	    = local_GMEM_NOCOMPACT,
	GMEM_NODISCARD	    = local_GMEM_NODISCARD,
	GMEM_NOT_BANKED	    = local_GMEM_NOT_BANKED,
	GMEM_NOTIFY	    = local_GMEM_NOTIFY;

    export constexpr auto
	STD_INPUT_HANDLE    = local_STD_INPUT_HANDLE,
	STD_OUTPUT_HANDLE   = local_STD_OUTPUT_HANDLE,
	STD_ERROR_HANDLE    = local_STD_ERROR_HANDLE;

    export using ::OVERLAPPED;
    export using ::LPOVERLAPPED;

    export using ::LocalAlloc;
    export using ::GlobalAlloc;
    export using ::LocalFree;
    export using ::GlobalFree;

    export using ::FormatMessageA;
    export using ::FormatMessageW;

    export using ::GetEnvironmentVariableA;
    export using ::GetEnvironmentVariableW;

    export using ::SetEnvironmentVariableA;
    export using ::SetEnvironmentVariableW;

#if defined UNICODE || defined _UNICODE
    export constexpr auto const &FormatMessage = ::FormatMessageW;
    export constexpr auto const &GetEnvironmentVariable = ::GetEnvironmentVariableW;
    export constexpr auto const &SetEnvironmentVariable = ::SetEnvironmentVariableW;
#else
    export constexpr auto const &FormatMessage = ::FormatMessageA;
    export constexpr auto const &GetEnvironmentVariable = ::GetEnvironmentVariableA;
    export constexpr auto const &SetEnvironmentVariable = ::SetEnvironmentVariableA;
#endif
}
