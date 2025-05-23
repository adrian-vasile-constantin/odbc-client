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
#include <winbase.h>
#include <errhandlingapi.h>

export module winapi.ErrHandling;

#if !defined __INTELLISENSE__
import winapi.WinDef;
#endif

namespace
{
    auto constexpr
	local_SEM_FAILCRITICALERRORS	    = SEM_FAILCRITICALERRORS,
	local_SEM_NOALIGNMENTFAULTEXCEPT    = SEM_NOALIGNMENTFAULTEXCEPT,
	local_SEM_NOGPFAULTERRORBOX	    = SEM_NOGPFAULTERRORBOX,
	local_SEM_NOOPENFILEERRORBOX	    = SEM_NOOPENFILEERRORBOX;

    auto constexpr
	local_EXCEPTION_ACCESS_VIOLATION	    = EXCEPTION_ACCESS_VIOLATION,
	local_EXCEPTION_ARRAY_BOUNDS_EXCEEDED	    = EXCEPTION_ARRAY_BOUNDS_EXCEEDED,
	local_EXCEPTION_BREAKPOINT		    = EXCEPTION_BREAKPOINT,
	local_EXCEPTION_DATATYPE_MISALIGNMENT	    = EXCEPTION_DATATYPE_MISALIGNMENT,
	local_EXCEPTION_FLT_DENORMAL_OPERAND	    = EXCEPTION_FLT_DENORMAL_OPERAND,
	local_EXCEPTION_FLT_DIVIDE_BY_ZERO	    = EXCEPTION_FLT_DIVIDE_BY_ZERO,
	local_EXCEPTION_FLT_INEXACT_RESULT	    = EXCEPTION_FLT_INEXACT_RESULT,
	local_EXCEPTION_FLT_INVALID_OPERATION	    = EXCEPTION_FLT_INVALID_OPERATION,
	local_EXCEPTION_FLT_OVERFLOW		    = EXCEPTION_FLT_OVERFLOW,
	local_EXCEPTION_FLT_STACK_CHECK		    = EXCEPTION_FLT_STACK_CHECK,
	local_EXCEPTION_FLT_UNDERFLOW		    = EXCEPTION_FLT_UNDERFLOW,
	local_EXCEPTION_GUARD_PAGE		    = EXCEPTION_GUARD_PAGE,
	local_EXCEPTION_ILLEGAL_INSTRUCTION	    = EXCEPTION_ILLEGAL_INSTRUCTION,
	local_EXCEPTION_IN_PAGE_ERROR		    = EXCEPTION_IN_PAGE_ERROR,
	local_EXCEPTION_INT_DIVIDE_BY_ZERO	    = EXCEPTION_INT_DIVIDE_BY_ZERO,
	local_EXCEPTION_INT_OVERFLOW		    = EXCEPTION_INT_OVERFLOW,
	local_EXCEPTION_INVALID_DISPOSITION	    = EXCEPTION_INVALID_DISPOSITION,
	local_EXCEPTION_INVALID_HANDLE		    = EXCEPTION_INVALID_HANDLE,
	local_EXCEPTION_NONCONTINUABLE_EXCEPTION    = EXCEPTION_NONCONTINUABLE_EXCEPTION,
	local_EXCEPTION_PRIV_INSTRUCTION	    = EXCEPTION_PRIV_INSTRUCTION,
	local_EXCEPTION_SINGLE_STEP		    = EXCEPTION_SINGLE_STEP,
	local_EXCEPTION_STACK_OVERFLOW		    = EXCEPTION_STACK_OVERFLOW,
	local_STATUS_UNWIND_CONSOLIDATE		    = STATUS_UNWIND_CONSOLIDATE;
}

#undef SEM_FAILCRITICALERRORS
#undef SEM_NOALIGNMENTFAULTEXCEPT
#undef SEM_NOGPFAULTERRORBOX
#undef SEM_NOOPENFILEERRORBOX

#undef EXCEPTION_ACCESS_VIOLATION
#undef EXCEPTION_ARRAY_BOUNDS_EXCEEDED
#undef EXCEPTION_BREAKPOINT
#undef EXCEPTION_DATATYPE_MISALIGNMENT
#undef EXCEPTION_FLT_DENORMAL_OPERAND
#undef EXCEPTION_FLT_DIVIDE_BY_ZERO
#undef EXCEPTION_FLT_INEXACT_RESULT
#undef EXCEPTION_FLT_INVALID_OPERATION
#undef EXCEPTION_FLT_OVERFLOW
#undef EXCEPTION_FLT_STACK_CHECK
#undef EXCEPTION_FLT_UNDERFLOW
#undef EXCEPTION_GUARD_PAGE
#undef EXCEPTION_ILLEGAL_INSTRUCTION
#undef EXCEPTION_IN_PAGE_ERROR
#undef EXCEPTION_INT_DIVIDE_BY_ZERO
#undef EXCEPTION_INT_OVERFLOW
#undef EXCEPTION_INVALID_DISPOSITION
#undef EXCEPTION_INVALID_HANDLE
#undef EXCEPTION_NONCONTINUABLE_EXCEPTION
#undef EXCEPTION_PRIV_INSTRUCTION
#undef EXCEPTION_SINGLE_STEP
#undef EXCEPTION_STACK_OVERFLOW
#undef STATUS_UNWIND_CONSOLIDATE


namespace winapi
{
    export auto constexpr
	SEM_FAILCRITICALERRORS	    = local_SEM_FAILCRITICALERRORS,
	SEM_NOALIGNMENTFAULTEXCEPT  = local_SEM_NOALIGNMENTFAULTEXCEPT,
	SEM_NOGPFAULTERRORBOX	    = local_SEM_NOGPFAULTERRORBOX,
	SEM_NOOPENFILEERRORBOX	    = local_SEM_NOOPENFILEERRORBOX;

    export auto constexpr
	EXCEPTION_ACCESS_VIOLATION	    = local_EXCEPTION_ACCESS_VIOLATION,
	EXCEPTION_ARRAY_BOUNDS_EXCEEDED	    = local_EXCEPTION_ARRAY_BOUNDS_EXCEEDED,
	EXCEPTION_BREAKPOINT		    = local_EXCEPTION_BREAKPOINT,
	EXCEPTION_DATATYPE_MISALIGNMENT	    = local_EXCEPTION_DATATYPE_MISALIGNMENT,
	EXCEPTION_FLT_DENORMAL_OPERAND	    = local_EXCEPTION_FLT_DENORMAL_OPERAND,
	EXCEPTION_FLT_DIVIDE_BY_ZERO	    = local_EXCEPTION_FLT_DIVIDE_BY_ZERO,
	EXCEPTION_FLT_INEXACT_RESULT	    = local_EXCEPTION_FLT_INEXACT_RESULT,
	EXCEPTION_FLT_INVALID_OPERATION	    = local_EXCEPTION_FLT_INVALID_OPERATION,
	EXCEPTION_FLT_OVERFLOW		    = local_EXCEPTION_FLT_OVERFLOW,
	EXCEPTION_FLT_STACK_CHECK	    = local_EXCEPTION_FLT_STACK_CHECK,
	EXCEPTION_FLT_UNDERFLOW		    = local_EXCEPTION_FLT_UNDERFLOW,
	EXCEPTION_GUARD_PAGE		    = local_EXCEPTION_GUARD_PAGE,
	EXCEPTION_ILLEGAL_INSTRUCTION	    = local_EXCEPTION_ILLEGAL_INSTRUCTION,
	EXCEPTION_IN_PAGE_ERROR		    = local_EXCEPTION_IN_PAGE_ERROR,
	EXCEPTION_INT_DIVIDE_BY_ZERO	    = local_EXCEPTION_INT_DIVIDE_BY_ZERO,
	EXCEPTION_INT_OVERFLOW		    = local_EXCEPTION_INT_OVERFLOW,
	EXCEPTION_INVALID_DISPOSITION	    = local_EXCEPTION_INVALID_DISPOSITION,
	EXCEPTION_INVALID_HANDLE	    = local_EXCEPTION_INVALID_HANDLE,
	EXCEPTION_NONCONTINUABLE_EXCEPTION  = local_EXCEPTION_NONCONTINUABLE_EXCEPTION,
	EXCEPTION_PRIV_INSTRUCTION	    = local_EXCEPTION_PRIV_INSTRUCTION,
	EXCEPTION_SINGLE_STEP		    = local_EXCEPTION_SINGLE_STEP,
	EXCEPTION_STACK_OVERFLOW	    = local_EXCEPTION_STACK_OVERFLOW,
	STATUS_UNWIND_CONSOLIDATE	    = local_STATUS_UNWIND_CONSOLIDATE;


    export using ::GetLastError;
    export using ::GetErrorMode;
    export using ::SetLastError;
    export using ::SetErrorMode;
    export using ::RaiseException;
}
