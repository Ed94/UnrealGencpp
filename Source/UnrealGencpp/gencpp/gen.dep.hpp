// This file was generated automatially by gencpp's unreal.cpp (See: https://github.com/Ed94/gencpp)

#pragma once
#ifdef __clang__
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wunused-const-variable"
#	pragma clang diagnostic ignored "-Wunused-but-set-variable"
#	pragma clang diagnostic ignored "-Wswitch"
#	pragma clang diagnostic ignored "-Wunused-variable"
#   pragma clang diagnostic ignored "-Wunknown-pragmas"
#	pragma clang diagnostic ignored "-Wvarargs"
#	pragma clang diagnostic ignored "-Wunused-function"
#	pragma clang diagnostic ignored "-Wbraced-scalar-init"
#   pragma clang diagnostic ignored "-W#pragma-messages"
#	pragma clang diagnostic ignored "-Wstatic-in-inline"
#endif

#ifdef __GNUC__
#	pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunknown-pragmas"
#	pragma GCC diagnostic ignored "-Wcomment"
#	pragma GCC diagnostic ignored "-Wswitch"
#	pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#pragma region Platform Detection

/* Platform architecture */

#if defined( _WIN64 ) || defined( __x86_64__ ) || defined( _M_X64 ) || defined( __64BIT__ ) || defined( __powerpc64__ ) || defined( __ppc64__ ) || defined( __aarch64__ )
#	ifndef GEN_ARCH_64_BIT
#		define GEN_ARCH_64_BIT 1
#	endif
#else
#	ifndef GEN_ARCH_32_BItxt_StrCaT
#		define GEN_ARCH_32_BIT 1
#	endif
#endif

/* Platform OS */

#if defined( _WIN32 ) || defined( _WIN64 )
#	ifndef GEN_SYSTEM_WINDOWS
#		define GEN_SYSTEM_WINDOWS 1
#	endif
#elif defined( __APPLE__ ) && defined( __MACH__ )
#	ifndef GEN_SYSTEM_OSX
#		define GEN_SYSTEM_OSX 1
#	endif
#	ifndef GEN_SYSTEM_MACOS
#		define GEN_SYSTEM_MACOS 1
#	endif
#elif defined( __unix__ )
#	ifndef GEN_SYSTEM_UNIX
#		define GEN_SYSTEM_UNIX 1
#	endif
#	if defined( ANDROID ) || defined( __ANDROID__ )
#		ifndef GEN_SYSTEM_ANDROID
#			define GEN_SYSTEM_ANDROID 1
#		endif
#		ifndef GEN_SYSTEM_LINUX
#			define GEN_SYSTEM_LINUX 1
#		endif
#	elif defined( __linux__ )
#		ifndef GEN_SYSTEM_LINUX
#			define GEN_SYSTEM_LINUX 1
#		endif
#	elif defined( __FreeBSD__ ) || defined( __FreeBSD_kernel__ )
#		ifndef GEN_SYSTEM_FREEBSD
#			define GEN_SYSTEM_FREEBSD 1
#		endif
#	elif defined( __OpenBSD__ )
#		ifndef GEN_SYSTEM_OPENBSD
#			define GEN_SYSTEM_OPENBSD 1
#		endif
#	elif defined( __EMSCRIPTEN__ )
#		ifndef GEN_SYSTEM_EMSCRIPTEN
#			define GEN_SYSTEM_EMSCRIPTEN 1
#		endif
#	elif defined( __CYGWIN__ )
#		ifndef GEN_SYSTEM_CYGWIN
#			define GEN_SYSTEM_CYGWIN 1
#		endif
#	else
#		error This UNIX operating system is not supported
#	endif
#else
#	error This operating system is not supported
#endif

/* Platform compiler */

#if defined( _MSC_VER )
#	pragma message("Detected MSVC")
// #	define GEN_COMPILER_CLANG 0
#	define GEN_COMPILER_MSVC  1
// #	define GEN_COMPILER_GCC   0
#elif defined( __GNUC__ )
#	pragma message("Detected GCC")
// #	define GEN_COMPILER_CLANG 0
// #	define GEN_COMPILER_MSVC  0
#	define GEN_COMPILER_GCC   1
#elif defined( __clang__ )
#	pragma message("Detected CLANG")
#	define GEN_COMPILER_CLANG 1
// #	define GEN_COMPILER_MSVC  0
// #	define GEN_COMPILER_GCC   0
#else
#	error Unknown compiler
#endif

#if defined( __has_attribute )
#	define GEN_HAS_ATTRIBUTE( attribute ) __has_attribute( attribute )
#else
#	define GEN_HAS_ATTRIBUTE( attribute ) ( 0 )
#endif

#if defined(GEN_GCC_VERSION_CHECK)
#  undef GEN_GCC_VERSION_CHECK
#endif
#if defined(GEN_GCC_VERSION)
#  define GEN_GCC_VERSION_CHECK(major,minor,patch) (GEN_GCC_VERSION >= GEN_VERSION_ENCODE(major, minor, patch))
#else
#  define GEN_GCC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if !defined(GEN_COMPILER_C)
#	ifdef __cplusplus
#		define GEN_COMPILER_C   0
#		define GEN_COMPILER_CPP 1
#	else
#		if defined(__STDC__)
#			define GEN_COMPILER_C   1
#		    define GEN_COMPILER_CPP 0
#		else
            // Fallback for very old C compilers
#			define GEN_COMPILER_C   1
#		    define GEN_COMPILER_CPP 0
#		endif
#   endif
#endif

#if GEN_COMPILER_C
#pragma message("GENCPP: Detected C")
#endif

#pragma endregion Platform Detection

#pragma region Mandatory Includes

#	include <stdarg.h>
#	include <stddef.h>

#	if defined( GEN_SYSTEM_WINDOWS )
#		include <intrin.h>
#	endif

#if GEN_COMPILER_C
#include <assert.h>
#include <stdbool.h>
#endif

#pragma endregion Mandatory Includes

#if GEN_DONT_USE_NAMESPACE || GEN_COMPILER_C
#	if GEN_COMPILER_C
#		define GEN_NS
#		define GEN_NS_BEGIN
#		define GEN_NS_END
#	else
#		define GEN_NS              ::
#		define GEN_NS_BEGIN
#		define GEN_NS_END
#	endif
#else
#	define GEN_NS              gen::
#	define GEN_NS_BEGIN        namespace gen {
#	define GEN_NS_END          }
#endif

GEN_NS_BEGIN

#pragma region Macros


#if GEN_COMPILER_MSVC
#ifdef GEN_DYN_LINK

#ifdef GEN_DYN_EXPORT

#define GEN_API __declspec( dllexport )
#else
#define GEN_API __declspec( dllimport )
#endif
#else
#define GEN_API    // Empty for static builds
#endif
#else
#ifdef GEN_DYN_LINK

#define GEN_API __attribute__( ( visibility( "default" ) ) )
#else
#define GEN_API    // Empty for static builds
#endif
#endif

#ifndef global
#define global    // Global variables
#endif
#ifndef internal
#define internal static    // Internal linkage
#endif
#ifndef local_persist
#define local_persist static    // Local Persisting variables
#endif

#ifndef bit
#define bit( Value )                         ( 1 << Value )
#define bitfield_is_set( Type, Field, Mask ) ( ( scast( Type, Mask ) & scast( Type, Field ) ) == scast( Type, Mask ) )
#endif

// Mainly intended for forcing the base library to utilize only C-valid constructs or type coercion
#ifndef GEN_C_LIKE_CPP
#define GEN_C_LIKE_CPP 0
#endif

#if GEN_COMPILER_CPP
#ifndef cast
#define cast( type, value ) ( tmpl_cast<type>( value ) )
#endif
#else
#ifndef cast
#define cast( type, value ) ( (type)( value ) )
#endif
#endif

#if GEN_COMPILER_CPP
#ifndef ccast
#define ccast( type, value ) ( const_cast<type>( ( value ) ) )
#endif
#ifndef pcast
#define pcast( type, value ) ( *reinterpret_cast<type*>( &( value ) ) )
#endif
#ifndef rcast
#define rcast( type, value ) reinterpret_cast<type>( value )
#endif
#ifndef scast
#define scast( type, value ) static_cast<type>( value )
#endif
#else
#ifndef ccast
#define ccast( type, value ) ( (type)( value ) )
#endif
#ifndef pcast
#define pcast( type, value ) ( *(type*)( &value ) )
#endif
#ifndef rcast
#define rcast( type, value ) ( (type)( value ) )
#endif
#ifndef scast
#define scast( type, value ) ( (type)( value ) )
#endif
#endif

#ifndef stringize
#define stringize_va( ... ) #__VA_ARGS__
#define stringize( ... )    stringize_va( __VA_ARGS__ )
#endif

#define src_line_str stringize( __LINE__ )

#ifndef do_once
#define do_once()                                           \
	local_persist int __do_once_counter_##src_line_str = 0; \
	for ( ; __do_once_counter_##src_line_str != 1; __do_once_counter_##src_line_str = 1 )
#define do_once_defer( expression )                         \
	local_persist int __do_once_counter_##src_line_str = 0; \
	for ( ; __do_once_counter_##src_line_str != 1; __do_once_counter_##src_line_str = 1, ( expression ) )
#define do_once_start                    \
	do                                   \
	{                                    \
		local_persist bool done = false; \
		if ( done )                      \
			break;                       \
		done = true;

#define do_once_end \
	}               \
	while ( 0 )     \
		;
#endif

#ifndef labeled_scope_start
#define labeled_scope_start \
	if ( false )            \
	{
#define labeled_scope_end }
#endif

#ifndef compiler_decorated_func_name
#ifdef COMPILER_CLANG

#define compiler_decorated_func_name __PRETTY_NAME__
#elif defined( COMPILER_MSVC )

#define compiler_decorated_func_name __FUNCDNAME__
#endif
#endif

#ifndef num_args_impl

// This is essentially an arg couneter version of GEN_SELECT_ARG macros
// See section : _Generic function overloading for that usage (explains this heavier case)

#define num_args_impl( \
    _0,                \
    _1,                \
    _2,                \
    _3,                \
    _4,                \
    _5,                \
    _6,                \
    _7,                \
    _8,                \
    _9,                \
    _10,               \
    _11,               \
    _12,               \
    _13,               \
    _14,               \
    _15,               \
    _16,               \
    _17,               \
    _18,               \
    _19,               \
    _20,               \
    _21,               \
    _22,               \
    _23,               \
    _24,               \
    _25,               \
    _26,               \
    _27,               \
    _28,               \
    _29,               \
    _30,               \
    _31,               \
    _32,               \
    _33,               \
    _34,               \
    _35,               \
    _36,               \
    _37,               \
    _38,               \
    _39,               \
    _40,               \
    _41,               \
    _42,               \
    _43,               \
    _44,               \
    _45,               \
    _46,               \
    _47,               \
    _48,               \
    _49,               \
    _50,               \
    _51,               \
    _52,               \
    _53,               \
    _54,               \
    _55,               \
    _56,               \
    _57,               \
    _58,               \
    _59,               \
    _60,               \
    _61,               \
    _62,               \
    _63,               \
    _64,               \
    _65,               \
    _66,               \
    _67,               \
    _68,               \
    _69,               \
    _70,               \
    _71,               \
    _72,               \
    _73,               \
    _74,               \
    _75,               \
    _76,               \
    _77,               \
    _78,               \
    _79,               \
    _80,               \
    _81,               \
    _82,               \
    _83,               \
    _84,               \
    _85,               \
    _86,               \
    _87,               \
    _88,               \
    _89,               \
    _90,               \
    _91,               \
    _92,               \
    _93,               \
    _94,               \
    _95,               \
    _96,               \
    _97,               \
    _98,               \
    _99,               \
    _100,              \
    N,                 \
    ...                \
)                      \
	N

// ## deletes preceding comma if _VA_ARGS__ is empty (GCC, Clang)
#define num_args( ... ) \
	num_args_impl(      \
	    _,              \
	    ##__VA_ARGS__,  \
	    100,            \
	    99,             \
	    98,             \
	    97,             \
	    96,             \
	    95,             \
	    94,             \
	    93,             \
	    92,             \
	    91,             \
	    90,             \
	    89,             \
	    88,             \
	    87,             \
	    86,             \
	    85,             \
	    84,             \
	    83,             \
	    82,             \
	    81,             \
	    80,             \
	    79,             \
	    78,             \
	    77,             \
	    76,             \
	    75,             \
	    74,             \
	    73,             \
	    72,             \
	    71,             \
	    70,             \
	    69,             \
	    68,             \
	    67,             \
	    66,             \
	    65,             \
	    64,             \
	    63,             \
	    62,             \
	    61,             \
	    60,             \
	    59,             \
	    58,             \
	    57,             \
	    56,             \
	    55,             \
	    54,             \
	    53,             \
	    52,             \
	    51,             \
	    50,             \
	    49,             \
	    48,             \
	    47,             \
	    46,             \
	    45,             \
	    44,             \
	    43,             \
	    42,             \
	    41,             \
	    40,             \
	    39,             \
	    38,             \
	    37,             \
	    36,             \
	    35,             \
	    34,             \
	    33,             \
	    32,             \
	    31,             \
	    30,             \
	    29,             \
	    28,             \
	    27,             \
	    26,             \
	    25,             \
	    24,             \
	    23,             \
	    22,             \
	    21,             \
	    20,             \
	    19,             \
	    18,             \
	    17,             \
	    16,             \
	    15,             \
	    14,             \
	    13,             \
	    12,             \
	    11,             \
	    10,             \
	    9,              \
	    8,              \
	    7,              \
	    6,              \
	    5,              \
	    4,              \
	    3,              \
	    2,              \
	    1,              \
	    0               \
	)
#endif

#ifndef clamp
#define clamp( x, lower, upper ) min( max( ( x ), ( lower ) ), ( upper ) )
#endif
#ifndef count_of
#define count_of( x ) ( ( size_of( x ) / size_of( 0 [x] ) ) / ( (ssize)( ! ( size_of( x ) % size_of( 0 [x] ) ) ) ) )
#endif
#ifndef is_between
#define is_between( x, lower, upper ) ( ( ( lower ) <= ( x ) ) && ( ( x ) <= ( upper ) ) )
#endif
#ifndef size_of
#define size_of( x ) ( ssize )( sizeof( x ) )
#endif

#ifndef max
#define max( a, b ) ( ( a > b ) ? ( a ) : ( b ) )
#endif
#ifndef min
#define min( a, b ) ( ( a < b ) ? ( a ) : ( b ) )
#endif

#if GEN_COMPILER_MSVC || GEN_COMPILER_TINYC
#define offset_of( Type, element ) ( ( GEN_NS( ssize ) ) & ( ( (Type*)0 )->element ) )
#else
#define offset_of( Type, element ) __builtin_offsetof( Type, element )
#endif

#ifndef FORCEINLINE
#if GEN_COMPILER_MSVC
#define FORCEINLINE __forceinline
#define neverinline __declspec( noinline )
#elif GEN_COMPILER_GCC

#define FORCEINLINE inline __attribute__( ( __always_inline__ ) )
#define neverinline __attribute__( ( __noinline__ ) )
#elif GEN_COMPILER_CLANG

#if __has_attribute( __always_inline__ )
#define FORCEINLINE inline __attribute__( ( __always_inline__ ) )
#define neverinline __attribute__( ( __noinline__ ) )
#else
#define FORCEINLINE

#define neverinline

#endif
#else
#define FORCEINLINE

#define neverinline

#endif
#endif

#ifndef neverinline
#if GEN_COMPILER_MSVC
#define neverinline __declspec( noinline )
#elif GEN_COMPILER_GCC

#define neverinline __attribute__( ( __noinline__ ) )
#elif GEN_COMPILER_CLANG

#if __has_attribute( __always_inline__ )
#define neverinline __attribute__( ( __noinline__ ) )
#else
#define neverinline

#endif
#else
#define neverinline

#endif
#endif

#if GEN_COMPILER_C
#ifndef static_assert
#undef static_assert
#if GEN_COMPILER_C && __STDC_VERSION__ >= 201112L
#define static_assert( condition, message ) _Static_assert( condition, message )
#else
#define static_assert( condition, message ) typedef char static_assertion_##__LINE__[( condition ) ? 1 : -1]
#endif
#endif
#endif

#if GEN_COMPILER_CPP
// Already Defined
#elif GEN_COMPILER_C && __STDC_VERSION__ >= 201112L

#define thread_local _Thread_local
#elif GEN_COMPILER_MSVC

#define thread_local __declspec( thread )
#elif GEN_COMPILER_CLANG

#define thread_local __thread
#else
#error "No thread local support"
#endif

#if ! defined( typeof ) && ( ! GEN_COMPILER_C || __STDC_VERSION__ < 202311L )
#if ! GEN_COMPILER_C
#define typeof decltype
#elif defined( _MSC_VER )

#define typeof __typeof__
#elif defined( __GNUC__ ) || defined( __clang__ )

#define typeof __typeof__
#else
#error "Compiler not supported"
#endif
#endif

#ifndef GEN_API_C_BEGIN
#if GEN_COMPILER_C
#define GEN_API_C_BEGIN

#define GEN_API_C_END

#else
#define GEN_API_C_BEGIN \
	extern "C"          \
	{
#define GEN_API_C_END }
#endif
#endif

#if GEN_COMPILER_C
#if __STDC_VERSION__ >= 202311L
#define enum_underlying( type ) : type
#else
#define enum_underlying( type )

#endif
#else
#define enum_underlying( type ) : type
#endif

#if GEN_COMPILER_C
#ifndef nullptr
#define nullptr NULL
#endif

#ifndef GEN_REMOVE_PTR
#define GEN_REMOVE_PTR( type ) typeof( *( (type)NULL ) )
#endif
#endif

#if ! defined( GEN_PARAM_DEFAULT ) && GEN_COMPILER_CPP
#define GEN_PARAM_DEFAULT = {}
#else
#define GEN_PARAM_DEFAULT

#endif

#if GEN_COMPILER_CPP
#define struct_init( type, value ) \
	{                              \
		value                      \
	}
#else
#define struct_init( type, value ) \
	{                              \
		value                      \
	}
#endif

#if 0
#ifndef GEN_OPTIMIZE_MAPPINGS_BEGIN
#define GEN_OPTIMIZE_MAPPINGS_BEGIN _pragma( optimize( "gt", on ) )
#define GEN_OPITMIZE_MAPPINGS_END   _pragma( optimize( "", on ) )
#endif
#else
#define GEN_OPTIMIZE_MAPPINGS_BEGIN

#define GEN_OPITMIZE_MAPPINGS_END

#endif

#pragma endregion Macros

#pragma region Basic Types

#define GEN_U8_MIN 0u
#define GEN_U8_MAX 0xffu
#define GEN_I8_MIN ( -0x7f - 1 )
#define GEN_I8_MAX 0x7f

#define GEN_U16_MIN 0u
#define GEN_U16_MAX 0xffffu
#define GEN_I16_MIN ( -0x7fff - 1 )
#define GEN_I16_MAX 0x7fff

#define GEN_U32_MIN 0u
#define GEN_U32_MAX 0xffffffffu
#define GEN_I32_MIN ( -0x7fffffff - 1 )
#define GEN_I32_MAX 0x7fffffff

#define GEN_U64_MIN 0ull
#define GEN_U64_MAX 0xffffffffffffffffull
#define GEN_I64_MIN ( -0x7fffffffffffffffll - 1 )
#define GEN_I64_MAX 0x7fffffffffffffffll

#if defined( GEN_ARCH_32_BIT )
#	define GEN_USIZE_MIN GEN_U32_MIN
#	define GEN_USIZE_MAX GEN_U32_MAX
#	define GEN_ISIZE_MIN GEN_S32_MIN
#	define GEN_ISIZE_MAX GEN_S32_MAX
#elif defined( GEN_ARCH_64_BIT )
#	define GEN_USIZE_MIN GEN_U64_MIN
#	define GEN_USIZE_MAX GEN_U64_MAX
#	define GEN_ISIZE_MIN GEN_I64_MIN
#	define GEN_ISIZE_MAX GEN_I64_MAX
#else
#	error Unknown architecture size. This library only supports 32 bit and 64 bit architectures.
#endif

#define GEN_F32_MIN 1.17549435e-38f
#define GEN_F32_MAX 3.40282347e+38f
#define GEN_F64_MIN 2.2250738585072014e-308
#define GEN_F64_MAX 1.7976931348623157e+308

#if defined( GEN_COMPILER_MSVC )
#	if _MSC_VER < 1300
typedef unsigned char  u8;
typedef signed   char  s8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int   u32;
typedef signed   int   s32;
#    else
typedef unsigned __int8  u8;
typedef signed   __int8  s8;
typedef unsigned __int16 u16;
typedef signed   __int16 s16;
typedef unsigned __int32 u32;
typedef signed   __int32 s32;
#    endif
typedef unsigned __int64 u64;
typedef signed   __int64 s64;
#else
#	include <stdint.h>

typedef uint8_t  u8;
typedef int8_t   s8;
typedef uint16_t u16;
typedef int16_t  s16;
typedef uint32_t u32;
typedef int32_t  s32;
typedef uint64_t u64;
typedef int64_t  s64;
#endif

static_assert( sizeof( u8 )  == sizeof( s8 ),  "sizeof(u8) != sizeof(s8)" );
static_assert( sizeof( u16 ) == sizeof( s16 ), "sizeof(u16) != sizeof(s16)" );
static_assert( sizeof( u32 ) == sizeof( s32 ), "sizeof(u32) != sizeof(s32)" );
static_assert( sizeof( u64 ) == sizeof( s64 ), "sizeof(u64) != sizeof(s64)" );

static_assert( sizeof( u8 )  == 1, "sizeof(u8) != 1" );
static_assert( sizeof( u16 ) == 2, "sizeof(u16) != 2" );
static_assert( sizeof( u32 ) == 4, "sizeof(u32) != 4" );
static_assert( sizeof( u64 ) == 8, "sizeof(u64) != 8" );

typedef size_t    usize;
typedef ptrdiff_t ssize;

static_assert( sizeof( usize ) == sizeof( ssize ), "sizeof(usize) != sizeof(ssize)" );

// NOTE: (u)zpl_intptr is only here for semantic reasons really as this library will only support 32/64 bit OSes.
#if defined( _WIN64 )
typedef signed __int64   sptr;
typedef unsigned __int64 uptr;
#elif defined( _WIN32 )
// NOTE; To mark types changing their size, e.g. zpl_intptr
#	ifndef _W64
#		if ! defined( __midl ) && ( defined( _X86_ ) || defined( _M_IX86 ) ) && _MSC_VER >= 1300
#			define _W64 __w64
#		else
#			define _W64
#		endif
#	endif
typedef _W64 signed int   sptr;
typedef _W64 unsigned int uptr;
#else
typedef uintptr_t uptr;
typedef intptr_t  sptr;
#endif

static_assert( sizeof( uptr ) == sizeof( sptr ), "sizeof(uptr) != sizeof(sptr)" );

typedef float  f32;
typedef double f64;

static_assert( sizeof( f32 ) == 4, "sizeof(f32) != 4" );
static_assert( sizeof( f64 ) == 8, "sizeof(f64) != 8" );

typedef s8  b8;
typedef s16 b16;
typedef s32 b32;

typedef void*       mem_ptr;
typedef void const* mem_ptr_const ;

#if GEN_COMPILER_CPP
template<typename Type> uptr to_uptr( Type* ptr ) { return (uptr)ptr; }
template<typename Type> sptr to_sptr( Type* ptr ) { return (sptr)ptr; }

template<typename Type> mem_ptr       to_mem_ptr      ( Type ptr ) { return (mem_ptr)      ptr; }
template<typename Type> mem_ptr_const to_mem_ptr_const( Type ptr ) { return (mem_ptr_const)ptr; }
#else
#define to_uptr( ptr ) ((uptr)(ptr))
#define to_sptr( ptr ) ((sptr)(ptr))

#define to_mem_ptr( ptr)       ((mem_ptr)ptr)
#define to_mem_ptr_const( ptr) ((mem_ptr)ptr)
#endif

#pragma endregion Basic Types

#pragma region Debug

#if GEN_BUILD_DEBUG
#	if defined( GEN_COMPILER_MSVC )
#		if _MSC_VER < 1300
// #pragma message("GEN_BUILD_DEBUG: __asm int 3")
#			define GEN_DEBUG_TRAP() __asm int 3 /* Trap to debugger! */
#		else
// #pragma message("GEN_BUILD_DEBUG: __debugbreak()")
#			define GEN_DEBUG_TRAP() __debugbreak()
#		endif
#	elif defined( GEN_COMPILER_TINYC )
#		define GEN_DEBUG_TRAP() process_exit( 1 )
#	else
#		define GEN_DEBUG_TRAP() __builtin_trap()
#	endif
#else
// #pragma message("GEN_BUILD_DEBUG: omitted")
#	define GEN_DEBUG_TRAP()
#endif

#define GEN_ASSERT( cond ) GEN_ASSERT_MSG( cond, NULL )

#define GEN_ASSERT_MSG( cond, msg, ... )                                                              \
	do                                                                                                \
	{                                                                                                 \
		if ( ! ( cond ) )                                                                             \
		{                                                                                             \
			assert_handler( #cond, __FILE__, __func__, scast( s64, __LINE__ ), msg, ##__VA_ARGS__ );  \
			GEN_DEBUG_TRAP();                                                                         \
		}                                                                                             \
	} while ( 0 )

#define GEN_ASSERT_NOT_NULL( ptr ) GEN_ASSERT_MSG( ( ptr ) != NULL, #ptr " must not be NULL" )

// NOTE: Things that shouldn't happen with a message!
#define GEN_PANIC( msg, ... ) GEN_ASSERT_MSG( 0, msg, ##__VA_ARGS__ )

#if GEN_BUILD_DEBUG
	#define GEN_FATAL( ... )                               \
	do                                                     \
	{                                                      \
		local_persist thread_local                         \
		char buf[GEN_PRINTF_MAXLEN] = { 0 };               \
		                                                   \
		c_str_fmt(buf, GEN_PRINTF_MAXLEN, __VA_ARGS__);    \
		GEN_PANIC(buf);                                    \
	}                                                      \
	while (0)
#else

#	define GEN_FATAL( ... )                  \
	do                                       \
	{                                        \
		c_str_fmt_out_err( __VA_ARGS__ );    \
		GEN_DEBUG_TRAP();                    \
		process_exit(1);                     \
	}                                        \
	while (0)
#endif

void assert_handler( char const* condition, char const* file, char const* function, s32 line, char const* msg, ... );
s32  assert_crash( char const* condition );
void process_exit( u32 code );

#pragma endregion Debug

#pragma region Memory

#define kilobytes( x ) (          ( x ) * ( s64 )( 1024 ) )
#define megabytes( x ) ( kilobytes( x ) * ( s64 )( 1024 ) )
#define gigabytes( x ) ( megabytes( x ) * ( s64 )( 1024 ) )
#define terabytes( x ) ( gigabytes( x ) * ( s64 )( 1024 ) )

#define GEN__ONES          ( scast( GEN_NS usize, - 1) / GEN_U8_MAX )
#define GEN__HIGHS         ( GEN__ONES * ( GEN_U8_MAX / 2 + 1 ) )
#define GEN__HAS_ZERO( x ) ( ( ( x ) - GEN__ONES ) & ~( x ) & GEN__HIGHS )

template< class Type >
void swap( Type& a, Type& b )
{
	Type tmp = a;
	a = b;
	b = tmp;
}

//! Checks if value is power of 2.
b32 is_power_of_two( ssize x );

//! Aligns address to specified alignment.
void* align_forward( void* ptr, ssize alignment );

//! Aligns value to a specified alignment.
s64 align_forward_by_value( s64 value, ssize alignment );

//! Moves pointer forward by bytes.
void* pointer_add( void* ptr, ssize bytes );

//! Moves pointer forward by bytes.
void const* pointer_add_const( void const* ptr, ssize bytes );

//! Calculates difference between two addresses.
ssize pointer_diff( void const* begin, void const* end );

//! Copy non-overlapping memory from source to destination.
void* mem_copy( void* dest, void const* source, ssize size );

//! Search for a constant value within the size limit at memory location.
void const* mem_find( void const* data, u8 byte_value, ssize size );

//! Copy memory from source to destination.
void* mem_move( void* dest, void const* source, ssize size );

//! Set constant value at memory location with specified size.
void* mem_set( void* data, u8 byte_value, ssize size );

//! @param ptr Memory location to clear up.
//! @param size The size to clear up with.
void zero_size( void* ptr, ssize size );

//! Clears up an item.
#define zero_item( t ) zero_size( ( t ), size_of( *( t ) ) )    // NOTE: Pass pointer of struct

//! Clears up an array.
#define zero_array( a, count ) zero_size( ( a ), size_of( *( a ) ) * count )

enum AllocType : u8
{
	EAllocation_ALLOC,
	EAllocation_FREE,
	EAllocation_FREE_ALL,
	EAllocation_RESIZE,
};

typedef void*(AllocatorProc)( void* allocator_data, AllocType type, ssize size, ssize alignment, void* old_memory, ssize old_size, u64 flags );

struct AllocatorInfo
{
	AllocatorProc* Proc;
	void*          Data;
};

enum AllocFlag
{
	ALLOCATOR_FLAG_CLEAR_TO_ZERO = bit( 0 ),
};

#ifndef GEN_DEFAULT_MEMORY_ALIGNMENT
#	define GEN_DEFAULT_MEMORY_ALIGNMENT ( 2 * size_of( void* ) )
#endif

#ifndef GEN_DEFAULT_ALLOCATOR_FLAGS
#	define GEN_DEFAULT_ALLOCATOR_FLAGS ( ALLOCATOR_FLAG_CLEAR_TO_ZERO )
#endif

//! Allocate memory with default alignment.
void* alloc( AllocatorInfo a, ssize size );

//! Allocate memory with specified alignment.
void* alloc_align( AllocatorInfo a, ssize size, ssize alignment );

//! Free allocated memory.
void allocator_free( AllocatorInfo a, void* ptr );

//! Free all memory allocated by an allocator.
void free_all( AllocatorInfo a );

//! Resize an allocated memory.
void* resize( AllocatorInfo a, void* ptr, ssize old_size, ssize new_size );

//! Resize an allocated memory with specified alignment.
void* resize_align( AllocatorInfo a, void* ptr, ssize old_size, ssize new_size, ssize alignment );

//! Allocate memory for an item.
#define alloc_item( allocator_, Type ) ( Type* )alloc( allocator_, size_of( Type ) )

//! Allocate memory for an array of items.
#define alloc_array( allocator_, Type, count ) ( Type* )alloc( allocator_, size_of( Type ) * ( count ) )

/* heap memory analysis tools */
/* define GEN_HEAP_ANALYSIS to enable this feature */
/* call zpl_heap_stats_init at the beginning of the entry point */
/* you can call zpl_heap_stats_check near the end of the execution to validate any possible leaks */
void  heap_stats_init( void );
ssize heap_stats_used_memory( void );
ssize heap_stats_alloc_count( void );
void  heap_stats_check( void );

//! Allocate/Resize memory using default options.

//! Use this if you don't need a "fancy" resize allocation
void* default_resize_align( AllocatorInfo a, void* ptr, ssize old_size, ssize new_size, ssize alignment );

void* heap_allocator_proc( void* allocator_data, AllocType type, ssize size, ssize alignment, void* old_memory, ssize old_size, u64 flags );

//! The heap allocator backed by operating system's memory manager.
constexpr AllocatorInfo heap( void ) { AllocatorInfo allocator = { heap_allocator_proc, nullptr }; return allocator; }

//! Helper to allocate memory using heap allocator.
#define malloc( sz ) alloc( heap(), sz )

//! Helper to free memory allocated by heap allocator.
#define mfree( ptr ) free( heap(), ptr )

struct VirtualMemory
{
	void*  data;
	ssize size;
};

//! Initialize virtual memory from existing data.
VirtualMemory vm_from_memory( void* data, ssize size );

//! Allocate virtual memory at address with size.

//! @param addr The starting address of the region to reserve. If NULL, it lets operating system to decide where to allocate it.
//! @param size The size to serve.
VirtualMemory vm_alloc( void* addr, ssize size );

//! Release the virtual memory.
b32 vm_free( VirtualMemory vm );

//! Trim virtual memory.
VirtualMemory vm_trim( VirtualMemory vm, ssize lead_size, ssize size );

//! Purge virtual memory.
b32 vm_purge( VirtualMemory vm );

//! Retrieve VM's page size and alignment.
ssize virtual_memory_page_size( ssize* alignment_out );

#pragma region Arena
struct Arena;

AllocatorInfo arena_allocator_info( Arena* arena );

// Remove static keyword and rename allocator_proc
void* arena_allocator_proc(void* allocator_data, AllocType type, ssize size, ssize alignment, void* old_memory, ssize old_size, u64 flags);

// Add these declarations after the Arena struct
Arena arena_init_from_allocator(AllocatorInfo backing, ssize size);
Arena arena_init_from_memory   ( void* start, ssize size );

Arena arena_init_sub      (Arena* parent, ssize size);
ssize arena_alignment_of  (Arena* arena, ssize alignment);
void  arena_check         (Arena* arena);
void  arena_free          (Arena* arena);
ssize arena_size_remaining(Arena* arena, ssize alignment);

struct Arena
{
	AllocatorInfo Backing;
	void*         PhysicalStart;
	ssize         TotalSize;
	ssize         TotalUsed;
	ssize         TempCount;

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
#pragma region Member Mapping
	FORCEINLINE operator AllocatorInfo() { return arena_allocator_info(this); }

	FORCEINLINE static void* allocator_proc( void* allocator_data, AllocType type, ssize size, ssize alignment, void* old_memory, ssize old_size, u64 flags ) { return arena_allocator_proc( allocator_data, type, size, alignment, old_memory, old_size, flags ); }
	FORCEINLINE static Arena init_from_memory( void* start, ssize size )                                                                                      { return arena_init_from_memory( start, size ); }
	FORCEINLINE static Arena init_from_allocator( AllocatorInfo backing, ssize size )                                                                         { return arena_init_from_allocator( backing, size ); }
	FORCEINLINE static Arena init_sub( Arena& parent, ssize size )                                                                                            { return arena_init_from_allocator( parent.Backing, size ); }
	FORCEINLINE        ssize alignment_of( ssize alignment )                                                                                                  { return arena_alignment_of(this, alignment); }
	FORCEINLINE        void  free()                                                                                                                           { return arena_free(this);  }
	FORCEINLINE        ssize size_remaining( ssize alignment )                                                                                                { return arena_size_remaining(this, alignment); }

// This id is defined by Unreal for asserts
#pragma push_macro("check")
#undef check
	FORCEINLINE void check() { arena_check(this); }
#pragma pop_macro("check")

#pragma endregion Member Mapping
#endif
};

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
FORCEINLINE AllocatorInfo allocator_info(Arena& arena )                 { return arena_allocator_info(& arena); }
FORCEINLINE Arena         init_sub      (Arena& parent, ssize size)     { return arena_init_sub( & parent, size); }
FORCEINLINE ssize         alignment_of  (Arena& arena, ssize alignment) { return arena_alignment_of( & arena, alignment); }
FORCEINLINE void          free          (Arena& arena)                  { return arena_free(& arena); }
FORCEINLINE ssize         size_remaining(Arena& arena, ssize alignment) { return arena_size_remaining(& arena, alignment); }

// This id is defined by Unreal for asserts
#pragma push_macro("check")
#undef check
FORCEINLINE void check(Arena& arena) { return arena_check(& arena); }
#pragma pop_macro("check")
#endif

inline
AllocatorInfo arena_allocator_info( Arena* arena ) {
	GEN_ASSERT(arena != nullptr);
	AllocatorInfo info = { arena_allocator_proc, arena };
	return info;
}

inline
Arena arena_init_from_memory( void* start, ssize size )
{
	Arena arena = {
		{ nullptr, nullptr },
		start,
		size,
		0,
		0
	};
	return arena;
}

inline
Arena arena_init_from_allocator(AllocatorInfo backing, ssize size) {
	Arena result = {
		backing,
		alloc(backing, size),
		size,
		0,
		0
	};
	return result;
}

inline
Arena arena_init_sub(Arena* parent, ssize size) {
	GEN_ASSERT(parent != nullptr);
	return arena_init_from_allocator(parent->Backing, size);
}

inline
ssize arena_alignment_of(Arena* arena, ssize alignment)
{
	GEN_ASSERT(arena != nullptr);
	ssize alignment_offset, result_pointer, mask;
	GEN_ASSERT(is_power_of_two(alignment));

	alignment_offset = 0;
	result_pointer  = (ssize)arena->PhysicalStart + arena->TotalUsed;
	mask            = alignment - 1;

	if (result_pointer & mask)
	alignment_offset = alignment - (result_pointer & mask);

	return alignment_offset;
}

inline
void arena_check(Arena* arena)
{
    GEN_ASSERT(arena != nullptr );
    GEN_ASSERT(arena->TempCount == 0);
}

inline
void arena_free(Arena* arena)
{
	GEN_ASSERT(arena != nullptr);
	if (arena->Backing.Proc)
	{
		allocator_free(arena->Backing, arena->PhysicalStart);
		arena->PhysicalStart = nullptr;
	}
}

inline
ssize arena_size_remaining(Arena* arena, ssize alignment)
{
	GEN_ASSERT(arena != nullptr);
	ssize result = arena->TotalSize - (arena->TotalUsed + arena_alignment_of(arena, alignment));
	return result;
}
#pragma endregion Arena

#pragma region FixedArena
template<s32 Size>
struct FixedArena;

template<s32 Size> FixedArena<Size> fixed_arena_init();
template<s32 Size> AllocatorInfo    fixed_arena_allocator_info(FixedArena<Size>* fixed_arena );
template<s32 Size> ssize            fixed_arena_size_remaining(FixedArena<Size>* fixed_arena, ssize alignment);
template<s32 Size> void             fixed_arena_free(FixedArena<Size>* fixed_arena);

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
template<s32 Size> AllocatorInfo    allocator_info( FixedArena<Size>& fixed_arena )                { return allocator_info(& fixed_arena); }
template<s32 Size> ssize            size_remaining(FixedArena<Size>& fixed_arena, ssize alignment) { return size_remaining( & fixed_arena, alignment); }
#endif

// Just a wrapper around using an arena with memory associated with its scope instead of from an allocator.
// Used for static segment or stack allocations.
template< s32 Size >
struct FixedArena
{
	char  memory[Size];
	Arena arena;

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
#pragma region Member Mapping
	FORCEINLINE operator AllocatorInfo() { return fixed_arena_allocator_info(this); }

	FORCEINLINE static FixedArena init()                          { FixedArena result; fixed_arena_init<Size>(result); return result; }
	FORCEINLINE ssize             size_remaining(ssize alignment) { fixed_arena_size_remaining(this, alignment); }
#pragma endregion Member Mapping
#endif
};

template<s32 Size> inline
AllocatorInfo fixed_arena_allocator_info( FixedArena<Size>* fixed_arena ) {
	GEN_ASSERT(fixed_arena);
	return { arena_allocator_proc, & fixed_arena->arena };
}

template<s32 Size> inline
void fixed_arena_init(FixedArena<Size>* result) {
    zero_size(& result->memory[0], Size);
    result->arena = arena_init_from_memory(& result->memory[0], Size);
}

template<s32 Size> inline
void fixed_arena_free(FixedArena<Size>* fixed_arena) {
	arena_free( & fixed_arena->arena);
}

template<s32 Size> inline
ssize fixed_arena_size_remaining(FixedArena<Size>* fixed_arena, ssize alignment) {
    return size_remaining(fixed_arena->arena, alignment);
}

using FixedArena_1KB   = FixedArena< kilobytes( 1 ) >;
using FixedArena_4KB   = FixedArena< kilobytes( 4 ) >;
using FixedArena_8KB   = FixedArena< kilobytes( 8 ) >;
using FixedArena_16KB  = FixedArena< kilobytes( 16 ) >;
using FixedArena_32KB  = FixedArena< kilobytes( 32 ) >;
using FixedArena_64KB  = FixedArena< kilobytes( 64 ) >;
using FixedArena_128KB = FixedArena< kilobytes( 128 ) >;
using FixedArena_256KB = FixedArena< kilobytes( 256 ) >;
using FixedArena_512KB = FixedArena< kilobytes( 512 ) >;
using FixedArena_1MB   = FixedArena< megabytes( 1 ) >;
using FixedArena_2MB   = FixedArena< megabytes( 2 ) >;
using FixedArena_4MB   = FixedArena< megabytes( 4 ) >;
#pragma endregion FixedArena

#pragma region Pool
struct Pool;

void* pool_allocator_proc(void* allocator_data, AllocType type, ssize size, ssize alignment, void* old_memory, ssize old_size, u64 flags);

Pool          pool_init(AllocatorInfo backing, ssize num_blocks, ssize block_size);
Pool          pool_init_align(AllocatorInfo backing, ssize num_blocks, ssize block_size, ssize block_align);
AllocatorInfo pool_allocator_info(Pool* pool);
void          pool_clear(Pool* pool);
void          pool_free(Pool* pool);

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
FORCEINLINE AllocatorInfo allocator_info(Pool& pool) { return pool_allocator_info(& pool); }
FORCEINLINE void          clear(Pool& pool)          { return pool_clear(& pool); }
FORCEINLINE void          free(Pool& pool)           { return pool_free(& pool); }
#endif

struct Pool
{
	AllocatorInfo Backing;
	void*         PhysicalStart;
	void*         FreeList;
	ssize         BlockSize;
	ssize         BlockAlign;
	ssize         TotalSize;
	ssize         NumBlocks;

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
#pragma region Member Mapping
    FORCEINLINE operator AllocatorInfo() { return pool_allocator_info(this); }

    FORCEINLINE static void* allocator_proc(void* allocator_data, AllocType type, ssize size, ssize alignment, void* old_memory, ssize old_size, u64 flags) { return pool_allocator_proc(allocator_data, type, size, alignment, old_memory, old_size, flags); }
    FORCEINLINE static Pool  init(AllocatorInfo backing, ssize num_blocks, ssize block_size)                                                                { return pool_init(backing, num_blocks, block_size); }
    FORCEINLINE static Pool  init_align(AllocatorInfo backing, ssize num_blocks, ssize block_size, ssize block_align)                                       { return pool_init_align(backing, num_blocks, block_size, block_align); }
    FORCEINLINE        void  clear() { pool_clear( this); }
    FORCEINLINE        void  free()  { pool_free( this); }
#pragma endregion
#endif
};

inline
AllocatorInfo pool_allocator_info(Pool* pool) {
	AllocatorInfo info = { pool_allocator_proc, pool };
	return info;
}

inline
Pool pool_init(AllocatorInfo backing, ssize num_blocks, ssize block_size) {
	return pool_init_align(backing, num_blocks, block_size, GEN_DEFAULT_MEMORY_ALIGNMENT);
}

inline
void pool_free(Pool* pool) {
	if(pool->Backing.Proc) {
		allocator_free(pool->Backing, pool->PhysicalStart);
	}
}
#pragma endregion Pool

inline
b32 is_power_of_two( ssize x ) {
	if ( x <= 0 )
		return false;
	return ! ( x & ( x - 1 ) );
}

inline
mem_ptr align_forward( void* ptr, ssize alignment )
{
	GEN_ASSERT( is_power_of_two( alignment ) );
	uptr p       = to_uptr(ptr);
	uptr forward = (p + ( alignment - 1 ) ) & ~( alignment - 1 );

	return to_mem_ptr(forward);
}

inline s64 align_forward_s64( s64 value, ssize alignment ) { return value + ( alignment - value % alignment ) % alignment; }

inline void*       pointer_add      ( void*       ptr, ssize bytes ) { return rcast(void*,         rcast( u8*,        ptr) + bytes ); }
inline void const* pointer_add_const( void const* ptr, ssize bytes ) { return rcast(void const*, rcast( u8 const*,  ptr) + bytes ); }

inline sptr pointer_diff( mem_ptr_const begin, mem_ptr_const end ) {
	return scast( ssize, rcast( u8 const*, end) - rcast(u8 const*, begin) );
}

inline
void* mem_move( void* destination, void const* source, ssize byte_count )
{
	if ( destination == NULL )
	{
		return NULL;
	}

	u8*       dest_ptr = rcast( u8*, destination);
	u8 const* src_ptr  = rcast( u8 const*, source);

	if ( dest_ptr == src_ptr )
		return dest_ptr;

	if ( src_ptr + byte_count <= dest_ptr || dest_ptr + byte_count <= src_ptr )    // NOTE: Non-overlapping
		return mem_copy( dest_ptr, src_ptr, byte_count );

	if ( dest_ptr < src_ptr )
	{
		if ( to_uptr(src_ptr) % size_of( ssize ) == to_uptr(dest_ptr) % size_of( ssize ) )
		{
			while ( pcast( uptr, dest_ptr) % size_of( ssize ) )
			{
				if ( ! byte_count-- )
					return destination;

				*dest_ptr++ = *src_ptr++;
			}
			while ( byte_count >= size_of( ssize ) )
			{
				* rcast(ssize*, dest_ptr)  = * rcast(ssize const*, src_ptr);
				byte_count -= size_of( ssize );
				dest_ptr   += size_of( ssize );
				src_ptr    += size_of( ssize );
			}
		}
		for ( ; byte_count; byte_count-- )
			*dest_ptr++ = *src_ptr++;
	}
	else
	{
		if ( ( to_uptr(src_ptr) % size_of( ssize ) ) == ( to_uptr(dest_ptr) % size_of( ssize ) ) )
		{
			while ( to_uptr( dest_ptr + byte_count ) % size_of( ssize ) )
			{
				if ( ! byte_count-- )
					return destination;

				dest_ptr[ byte_count ] = src_ptr[ byte_count ];
			}
			while ( byte_count >= size_of( ssize ) )
			{
				byte_count                              -= size_of( ssize );
				* rcast(ssize*, dest_ptr + byte_count )  = * rcast( ssize const*, src_ptr + byte_count );
			}
		}
		while ( byte_count )
			byte_count--, dest_ptr[ byte_count ] = src_ptr[ byte_count ];
	}

	return destination;
}

inline
void* mem_set( void* destination, u8 fill_byte, ssize byte_count )
{
	if ( destination == NULL )
	{
		return NULL;
	}

	ssize align_offset;
	u8*   dest_ptr  = rcast( u8*, destination);
	u32   fill_word = ( ( u32 )-1 ) / 255 * fill_byte;

	if ( byte_count == 0 )
		return destination;

	dest_ptr[ 0 ] = dest_ptr[ byte_count - 1 ] = fill_byte;
	if ( byte_count < 3 )
		return destination;

	dest_ptr[ 1 ] = dest_ptr[ byte_count - 2 ] = fill_byte;
	dest_ptr[ 2 ] = dest_ptr[ byte_count - 3 ] = fill_byte;
	if ( byte_count < 7 )
		return destination;

	dest_ptr[ 3 ] = dest_ptr[ byte_count - 4 ] = fill_byte;
	if ( byte_count < 9 )
		return destination;

	align_offset  = -to_sptr( dest_ptr ) & 3;
	dest_ptr     += align_offset;
	byte_count   -= align_offset;
	byte_count   &= -4;

	* rcast( u32*, ( dest_ptr + 0              ) ) = fill_word;
	* rcast( u32*, ( dest_ptr + byte_count - 4 ) ) = fill_word;
	if ( byte_count < 9 )
		return destination;

	* rcast( u32*, dest_ptr + 4 )               = fill_word;
	* rcast( u32*, dest_ptr + 8 )               = fill_word;
	* rcast( u32*, dest_ptr + byte_count - 12 ) = fill_word;
	* rcast( u32*, dest_ptr + byte_count - 8 )  = fill_word;
	if ( byte_count < 25 )
		return destination;

	* rcast( u32*, dest_ptr + 12 )              = fill_word;
	* rcast( u32*, dest_ptr + 16 )              = fill_word;
	* rcast( u32*, dest_ptr + 20 )              = fill_word;
	* rcast( u32*, dest_ptr + 24 )              = fill_word;
	* rcast( u32*, dest_ptr + byte_count - 28 ) = fill_word;
	* rcast( u32*, dest_ptr + byte_count - 24 ) = fill_word;
	* rcast( u32*, dest_ptr + byte_count - 20 ) = fill_word;
	* rcast( u32*, dest_ptr + byte_count - 16 ) = fill_word;

	align_offset  = 24 + to_uptr( dest_ptr ) & 4;
	dest_ptr     += align_offset;
	byte_count   -= align_offset;

	{
		u64 fill_doubleword = ( scast( u64, fill_word) << 32 ) | fill_word;
		while ( byte_count > 31 )
		{
			* rcast( u64*, dest_ptr + 0 )  = fill_doubleword;
			* rcast( u64*, dest_ptr + 8 )  = fill_doubleword;
			* rcast( u64*, dest_ptr + 16 ) = fill_doubleword;
			* rcast( u64*, dest_ptr + 24 ) = fill_doubleword;

			byte_count -= 32;
			dest_ptr += 32;
		}
	}

	return destination;
}

inline
void* alloc_align( AllocatorInfo a, ssize size, ssize alignment ) {
	return a.Proc( a.Data, EAllocation_ALLOC, size, alignment, nullptr, 0, GEN_DEFAULT_ALLOCATOR_FLAGS );
}

inline
void* alloc( AllocatorInfo a, ssize size ) {
	return alloc_align( a, size, GEN_DEFAULT_MEMORY_ALIGNMENT );
}

inline
void allocator_free( AllocatorInfo a, void* ptr ) {
	if ( ptr != nullptr )
		a.Proc( a.Data, EAllocation_FREE, 0, 0, ptr, 0, GEN_DEFAULT_ALLOCATOR_FLAGS );
}

inline
void free_all( AllocatorInfo a ) {
	a.Proc( a.Data, EAllocation_FREE_ALL, 0, 0, nullptr, 0, GEN_DEFAULT_ALLOCATOR_FLAGS );
}

inline
void* resize( AllocatorInfo a, void* ptr, ssize old_size, ssize new_size ) {
	return resize_align( a, ptr, old_size, new_size, GEN_DEFAULT_MEMORY_ALIGNMENT );
}

inline
void* resize_align( AllocatorInfo a, void* ptr, ssize old_size, ssize new_size, ssize alignment ) {
	return a.Proc( a.Data, EAllocation_RESIZE, new_size, alignment, ptr, old_size, GEN_DEFAULT_ALLOCATOR_FLAGS );
}

inline
void* default_resize_align( AllocatorInfo a, void* old_memory, ssize old_size, ssize new_size, ssize alignment )
{
	if ( ! old_memory )
		return alloc_align( a, new_size, alignment );

	if ( new_size == 0 )
	{
		allocator_free( a, old_memory );
		return nullptr;
	}

	if ( new_size < old_size )
		new_size = old_size;

	if ( old_size == new_size )
	{
		return old_memory;
	}
	else
	{
		void*  new_memory = alloc_align( a, new_size, alignment );
		if ( ! new_memory )
			return nullptr;

		mem_move( new_memory, old_memory, min( new_size, old_size ) );
		allocator_free( a, old_memory );
		return new_memory;
	}
}

inline
void zero_size( void* ptr, ssize size ) {
	mem_set( ptr, 0, size );
}

#pragma endregion Memory

#pragma region String Ops

const char* char_first_occurence( const char* str, char c );

b32   char_is_alpha( char c );
b32   char_is_alphanumeric( char c );
b32   char_is_digit( char c );
b32   char_is_hex_digit( char c );
b32   char_is_space( char c );
char  char_to_lower( char c );
char  char_to_upper( char c );

s32  digit_to_int( char c );
s32  hex_digit_to_int( char c );

s32         c_str_compare( const char* s1, const char* s2 );
s32         c_str_compare_len( const char* s1, const char* s2, ssize len );
char*       c_str_copy( char* dest, const char* source, ssize len );
ssize       c_str_copy_nulpad( char* dest, const char* source, ssize len );
ssize       c_str_len( const char* str );
ssize       c_str_len_capped( const char* str, ssize max_len );
char*       c_str_reverse( char* str );    // NOTE: ASCII only
char const* c_str_skip( char const* str, char c );
char const* c_str_skip_any( char const* str, char const* char_list );
char const* c_str_trim( char const* str, b32 catch_newline );

// NOTE: ASCII only
void c_str_to_lower( char* str );
void c_str_to_upper( char* str );

s64  c_str_to_i64( const char* str, char** end_ptr, s32 base );
void i64_to_str( s64 value, char* string, s32 base );
void u64_to_str( u64 value, char* string, s32 base );
f64  c_str_to_f64( const char* str, char** end_ptr );

inline
const char* char_first_occurence( const char* s, char c )
{
	char ch = c;
	for ( ; *s != ch; s++ )
	{
		if ( *s == '\0' )
			return NULL;
	}
	return s;
}

inline
b32 char_is_alpha( char c )
{
	if ( ( c >= 'A' && c <= 'Z' ) || ( c >= 'a' && c <= 'z' ) )
		return true;
	return false;
}

inline
b32 char_is_alphanumeric( char c )
{
	return char_is_alpha( c ) || char_is_digit( c );
}

inline
b32 char_is_digit( char c )
{
	if ( c >= '0' && c <= '9' )
		return true;
	return false;
}

inline
b32 char_is_hex_digit( char c )
{
	if ( char_is_digit( c ) || ( c >= 'a' && c <= 'f' ) || ( c >= 'A' && c <= 'F' ) )
		return true;
	return false;
}

inline
b32 char_is_space( char c )
{
	if ( c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v' )
		return true;
	return false;
}

inline
char char_to_lower( char c )
{
	if ( c >= 'A' && c <= 'Z' )
		return 'a' + ( c - 'A' );
	return c;
}

inline char char_to_upper( char c )
{
	if ( c >= 'a' && c <= 'z' )
		return 'A' + ( c - 'a' );
	return c;
}

inline
s32 digit_to_int( char c )
{
	return char_is_digit( c ) ? c - '0' : c - 'W';
}

inline
s32 hex_digit_to_int( char c )
{
	if ( char_is_digit( c ) )
		return digit_to_int( c );
	else if ( is_between( c, 'a', 'f' ) )
		return c - 'a' + 10;
	else if ( is_between( c, 'A', 'F' ) )
		return c - 'A' + 10;
	return -1;
}

inline
s32 c_str_compare( const char* s1, const char* s2 )
{
	while ( *s1 && ( *s1 == *s2 ) )
	{
		s1++, s2++;
	}
	return *( u8* )s1 - *( u8* )s2;
}

inline
s32 c_str_compare_len( const char* s1, const char* s2, ssize len )
{
	for ( ; len > 0; s1++, s2++, len-- )
	{
		if ( *s1 != *s2 )
			return ( ( s1 < s2 ) ? -1 : +1 );
		else if ( *s1 == '\0' )
			return 0;
	}
	return 0;
}

inline
char* c_str_copy( char* dest, const char* source, ssize len )
{
	GEN_ASSERT_NOT_NULL( dest );
	if ( source )
	{
		char* str = dest;
		while ( len > 0 && *source )
		{
			*str++ = *source++;
			len--;
		}
		while ( len > 0 )
		{
			*str++ = '\0';
			len--;
		}
	}
	return dest;
}

inline
ssize c_str_copy_nulpad( char* dest, const char* source, ssize len )
{
	ssize result = 0;
	GEN_ASSERT_NOT_NULL( dest );
	if ( source )
	{
		const char* source_start = source;
		char*       str          = dest;
		while ( len > 0 && *source )
		{
			*str++ = *source++;
			len--;
		}
		while ( len > 0 )
		{
			*str++ = '\0';
			len--;
		}

		result = source - source_start;
	}
	return result;
}

inline
ssize c_str_len( const char* str )
{
	if ( str == NULL )
	{
		return 0;
	}
	const char* p = str;
	while ( *str )
		str++;
	return str - p;
}

inline
ssize c_str_len_capped( const char* str, ssize max_len )
{
	const char* end = rcast(const char*, mem_find( str, 0, max_len ));
	if ( end )
		return end - str;
	return max_len;
}

inline
char* c_str_reverse( char* str )
{
	ssize    len  = c_str_len( str );
	char* a    = str + 0;
	char* b    = str + len - 1;
	len       /= 2;
	while ( len-- )
	{
		swap( *a, *b );
		a++, b--;
	}
	return str;
}

inline
char const* c_str_skip( char const* str, char c )
{
	while ( *str && *str != c )
	{
		++str;
	}
	return str;
}

inline
char const* c_str_skip_any( char const* str, char const* char_list )
{
	char const* closest_ptr     = rcast( char const*, pointer_add_const( rcast(mem_ptr_const, str), c_str_len( str ) ));
	ssize       char_list_count = c_str_len( char_list );
	for ( ssize i = 0; i < char_list_count; i++ )
	{
		char const* p = c_str_skip( str, char_list[ i ] );
		closest_ptr   = min( closest_ptr, p );
	}
	return closest_ptr;
}

inline
char const* c_str_trim( char const* str, b32 catch_newline )
{
	while ( *str && char_is_space( *str ) && ( ! catch_newline || ( catch_newline && *str != '\n' ) ) )
	{
		++str;
	}
	return str;
}

inline
void c_str_to_lower( char* str )
{
	if ( ! str )
		return;
	while ( *str )
	{
		*str = char_to_lower( *str );
		str++;
	}
}

inline
void c_str_to_upper( char* str )
{
	if ( ! str )
		return;
	while ( *str )
	{
		*str = char_to_upper( *str );
		str++;
	}
}

#pragma endregion String Ops

#pragma region Printing

typedef struct FileInfo FileInfo;

#ifndef GEN_PRINTF_MAXLEN
#	define GEN_PRINTF_MAXLEN kilobytes(128)
#endif
typedef char PrintF_Buffer[GEN_PRINTF_MAXLEN];

// NOTE: A locally persisting buffer is used internally
char*  c_str_fmt_buf       ( char const* fmt, ... );
char*  c_str_fmt_buf_va    ( char const* fmt, va_list va );
ssize  c_str_fmt           ( char* str, ssize n, char const* fmt, ... );
ssize  c_str_fmt_va        ( char* str, ssize n, char const* fmt, va_list va );
ssize  c_str_fmt_out_va    ( char const* fmt, va_list va );
ssize  c_str_fmt_out_err   ( char const* fmt, ... );
ssize  c_str_fmt_out_err_va( char const* fmt, va_list va );
ssize  c_str_fmt_file      ( FileInfo* f, char const* fmt, ... );
ssize  c_str_fmt_file_va   ( FileInfo* f, char const* fmt, va_list va );

constexpr
char const* Msg_Invalid_Value = "INVALID VALUE PROVIDED";

inline
ssize log_fmt(char const* fmt, ...)
{
	ssize res;
	va_list va;

	va_start(va, fmt);
	res = c_str_fmt_out_va(fmt, va);
	va_end(va);

	return res;
}

#pragma endregion Printing

#pragma region Containers

template<class TType>             struct RemoveConst                    { typedef TType Type;       };
template<class TType>             struct RemoveConst<const TType>       { typedef TType Type;       };
template<class TType>             struct RemoveConst<const TType[]>     { typedef TType Type[];     };
template<class TType, usize Size> struct RemoveConst<const TType[Size]> { typedef TType Type[Size]; };

template<class TType> using TRemoveConst = typename RemoveConst<TType>::Type;

template <class TType> struct RemovePtr         { typedef TType Type; };
template <class TType> struct RemovePtr<TType*> { typedef TType Type; };

template <class TType> using TRemovePtr = typename RemovePtr<TType>::Type;


#pragma region Array
#define Array(Type) Array<Type>

// #define array_init(Type, ...)         array_init        <Type>(__VA_ARGS__)
// #define array_init_reserve(Type, ...) array_init_reserve<Type>(__VA_ARGS__)

struct ArrayHeader;

#if GEN_COMPILER_CPP
	template<class Type> struct Array;
#	define get_array_underlying_type(array) typename TRemovePtr<typeof(array)>:: DataType
#endif

usize array_grow_formula(ssize value);

template<class Type> Array<Type>  array_init           (AllocatorInfo allocator);
template<class Type> Array<Type>  array_init_reserve   (AllocatorInfo allocator, ssize capacity);
template<class Type> bool         array_append_array   (Array<Type>* array, Array<Type> other);
template<class Type> bool         array_append         (Array<Type>* array, Type value);
template<class Type> bool         array_append_items   (Array<Type>* array, Type* items, usize item_num);
template<class Type> bool         array_append_at      (Array<Type>* array, Type item, usize idx);
template<class Type> bool         array_append_items_at(Array<Type>* array, Type* items, usize item_num, usize idx);
template<class Type> Type*        array_back           (Array<Type>  array);
template<class Type> void         array_clear          (Array<Type>  array);
template<class Type> bool         array_fill           (Array<Type>  array, usize begin, usize end, Type value);
template<class Type> void         array_free           (Array<Type>* array);
template<class Type> bool         arary_grow           (Array<Type>* array, usize min_capacity);
template<class Type> usize        array_num            (Array<Type>  array);
template<class Type> void         arary_pop            (Array<Type>  array);
template<class Type> void         arary_remove_at      (Array<Type>  array, usize idx);
template<class Type> bool         arary_reserve        (Array<Type>* array, usize new_capacity);
template<class Type> bool         arary_resize         (Array<Type>* array, usize num);
template<class Type> bool         arary_set_capacity   (Array<Type>* array, usize new_capacity);
template<class Type> ArrayHeader* arary_get_header     (Array<Type>  array);

struct ArrayHeader {
	AllocatorInfo Allocator;
	usize         Capacity;
	usize         Num;
};

#if GEN_COMPILER_CPP
template<class Type>
struct Array
{
	Type* Data;

#pragma region Member Mapping
	FORCEINLINE static Array  init(AllocatorInfo allocator)                         { return array_init<Type>(allocator); }
	FORCEINLINE static Array  init_reserve(AllocatorInfo allocator, ssize capacity) { return array_init_reserve<Type>(allocator, capacity); }
	FORCEINLINE static usize  grow_formula(ssize value)                             { return array_grow_formula<Type>(value); }

	FORCEINLINE bool         append(Array other)                               { return array_append_array<Type>(this, other); }
	FORCEINLINE bool         append(Type value)                                { return array_append<Type>(this, value); }
	FORCEINLINE bool         append(Type* items, usize item_num)               { return array_append_items<Type>(this, items, item_num); }
	FORCEINLINE bool         append_at(Type item, usize idx)                   { return array_append_at<Type>(this, item, idx); }
	FORCEINLINE bool         append_at(Type* items, usize item_num, usize idx) { return array_append_items_at<Type>(this, items, item_num, idx); }
	FORCEINLINE Type*        back()                                            { return array_back<Type>(* this); }
	FORCEINLINE void         clear()                                           {        array_clear<Type>(* this); }
	FORCEINLINE bool         fill(usize begin, usize end, Type value)          { return array_fill<Type>(* this, begin, end, value); }
	FORCEINLINE void         free()                                            {        array_free<Type>(this); }
	FORCEINLINE ArrayHeader* get_header()                                      { return array_get_header<Type>(* this); }
	FORCEINLINE bool         grow(usize min_capacity)                          { return array_grow<Type>(this, min_capacity); }
	FORCEINLINE usize        num()                                             { return array_num<Type>(*this); }
	FORCEINLINE void         pop()                                             {        array_pop<Type>(* this); }
	FORCEINLINE void         remove_at(usize idx)                              {        array_remove_at<Type>(* this, idx); }
	FORCEINLINE bool         reserve(usize new_capacity)                       { return array_reserve<Type>(this, new_capacity); }
	FORCEINLINE bool         resize(usize num)                                 { return array_resize<Type>(this, num); }
	FORCEINLINE bool         set_capacity(usize new_capacity)                  { return array_set_capacity<Type>(this, new_capacity); }
#pragma endregion Member Mapping

	FORCEINLINE operator Type*()             { return Data; }
	FORCEINLINE operator Type const*() const { return Data; }
	FORCEINLINE Type* begin()                { return Data; }
	FORCEINLINE Type* end()                  { return Data + get_header()->Num; }

	FORCEINLINE Type&       operator[](ssize index)       { return Data[index]; }
	FORCEINLINE Type const& operator[](ssize index) const { return Data[index]; }

	using DataType = Type;
};
#endif

#if GEN_COMPILER_CPP && 0
template<class Type> bool append(Array<Type>& array, Array<Type> other)                         { return append( & array, other ); }
template<class Type> bool append(Array<Type>& array, Type value)                                { return append( & array, value ); }
template<class Type> bool append(Array<Type>& array, Type* items, usize item_num)               { return append( & array, items, item_num ); }
template<class Type> bool append_at(Array<Type>& array, Type item, usize idx)                   { return append_at( & array, item, idx ); }
template<class Type> bool append_at(Array<Type>& array, Type* items, usize item_num, usize idx) { return append_at( & array, items, item_num, idx ); }
template<class Type> void free(Array<Type>& array)                                              { return free( & array ); }
template<class Type> bool grow(Array<Type>& array, usize min_capacity)                          { return grow( & array, min_capacity); }
template<class Type> bool reserve(Array<Type>& array, usize new_capacity)                       { return reserve( & array, new_capacity); }
template<class Type> bool resize(Array<Type>& array, usize num)                                 { return resize( & array, num); }
template<class Type> bool set_capacity(Array<Type>& array, usize new_capacity)                  { return set_capacity( & array, new_capacity); }

template<class Type> FORCEINLINE Type* begin(Array<Type>& array)             { return array;      }
template<class Type> FORCEINLINE Type* end(Array<Type>& array)               { return array + array_get_header(array)->Num; }
template<class Type> FORCEINLINE Type* next(Array<Type>& array, Type* entry) { return entry + 1; }
#endif

template<class Type> FORCEINLINE Type* array_begin(Array<Type> array)             { return array;      }
template<class Type> FORCEINLINE Type* array_end(Array<Type> array)               { return array + array_get_header(array)->Num; }
template<class Type> FORCEINLINE Type* array_next(Array<Type> array, Type* entry) { return ++ entry; }

template<class Type> inline
Array<Type> array_init(AllocatorInfo allocator) {
	return array_init_reserve<Type>(allocator, array_grow_formula(0));
}

template<class Type> inline
Array<Type> array_init_reserve(AllocatorInfo allocator, ssize capacity)
{
	GEN_ASSERT(capacity > 0);
	ArrayHeader* header = rcast(ArrayHeader*, alloc(allocator, sizeof(ArrayHeader) + sizeof(Type) * capacity));

	if (header == nullptr)
		return {nullptr};

	header->Allocator = allocator;
	header->Capacity  = capacity;
	header->Num       = 0;

	return {rcast(Type*, header + 1)};
}

FORCEINLINE
usize array_grow_formula(ssize value) {
	return 2 * value + 8;
}

template<class Type> inline
bool array_append_array(Array<Type>* array, Array<Type> other) {
	return array_append_items(array, (Type*)other, array_num(other));
}

template<class Type> inline
bool array_append(Array<Type>* array, Type value)
{
	GEN_ASSERT(  array != nullptr);
	GEN_ASSERT(* array != nullptr);
	ArrayHeader* header = array_get_header(* array);

	if (header->Num == header->Capacity)
	{
		if ( ! array_grow(array, header->Capacity))
			return false;
		header = array_get_header(* array);
	}

	(*array)[ header->Num] = value;
	header->Num++;

	return true;
}

template<class Type> inline
bool array_append_items(Array<Type>* array, Type* items, usize item_num)
{
	GEN_ASSERT(  array != nullptr);
	GEN_ASSERT(* array != nullptr);
	GEN_ASSERT(items != nullptr);
	GEN_ASSERT(item_num > 0);
	ArrayHeader* header = array_get_header(* array);

	if (header->Num + item_num > header->Capacity)
	{
		if ( ! array_grow(array, header->Capacity + item_num))
			return false;
		header = array_get_header(* array);
	}

	mem_copy((Type*)array + header->Num, items, item_num * sizeof(Type));
	header->Num += item_num;

	return true;
}

template<class Type> inline
bool array_append_at(Array<Type>* array, Type item, usize idx)
{
	GEN_ASSERT(  array != nullptr);
	GEN_ASSERT(* array != nullptr);
	ArrayHeader* header = array_get_header(* array);

	ssize slot = idx;
	if (slot >= (ssize)(header->Num))
		slot = header->Num - 1;

	if (slot < 0)
		slot = 0;

	if (header->Capacity < header->Num + 1)
	{
		if ( ! array_grow(array, header->Capacity + 1))
			return false;

		header = array_get_header(* array);
	}

	Type* target = &(*array)[slot];

	mem_move(target + 1, target, (header->Num - slot) * sizeof(Type));
	header->Num++;

	return true;
}

template<class Type> inline
bool array_append_items_at(Array<Type>* array, Type* items, usize item_num, usize idx)
{
	GEN_ASSERT(  array != nullptr);
	GEN_ASSERT(* array != nullptr);
	ArrayHeader* header = get_header(array);

	if (idx >= header->Num)
	{
		return array_append_items(array, items, item_num);
	}

	if (item_num > header->Capacity)
	{
		if (! grow(array, header->Capacity + item_num))
			return false;

		header = get_header(array);
	}

	Type* target = array.Data + idx + item_num;
	Type* src    = array.Data + idx;

	mem_move(target, src, (header->Num - idx) * sizeof(Type));
	mem_copy(src, items, item_num * sizeof(Type));
	header->Num += item_num;

	return true;
}

template<class Type> inline
Type* array_back(Array<Type> array)
{
	GEN_ASSERT(array != nullptr);

	ArrayHeader* header = array_get_header(array);
	if (header->Num <= 0)
		return nullptr;

	return & (array)[header->Num - 1];
}

template<class Type> inline
void array_clear(Array<Type> array) {
	GEN_ASSERT(array != nullptr);
	ArrayHeader* header = array_get_header(array);
	header->Num = 0;
}

template<class Type> inline
bool array_fill(Array<Type> array, usize begin, usize end, Type value)
{
	GEN_ASSERT(array != nullptr);
	GEN_ASSERT(begin <= end);
	ArrayHeader* header = array_get_header(array);

	if (begin < 0 || end > header->Num)
		return false;

	for (ssize idx = ssize(begin); idx < ssize(end); idx++) {
		array[idx] = value;
	}

	return true;
}

template<class Type> FORCEINLINE
void array_free(Array<Type>* array) {
	GEN_ASSERT(  array != nullptr);
	GEN_ASSERT(* array != nullptr);
	ArrayHeader* header = array_get_header(* array);
	allocator_free(header->Allocator, header);
	Type** Data = (Type**)array;
	*Data = nullptr;
}

template<class Type> FORCEINLINE
ArrayHeader* array_get_header(Array<Type> array) {
	GEN_ASSERT(array != nullptr);
    Type* Data = array;

	using NonConstType = TRemoveConst<Type>;
    return rcast(ArrayHeader*, const_cast<NonConstType*>(Data)) - 1;
}
template<class Type> FORCEINLINE
bool array_grow(Array<Type>* array, usize min_capacity)
{
	GEN_ASSERT(  array != nullptr);
	GEN_ASSERT(* array != nullptr);
	GEN_ASSERT( min_capacity > 0 );
	ArrayHeader* header       = array_get_header(* array);
	usize        new_capacity = array_grow_formula(header->Capacity);

	if (new_capacity < min_capacity)
		new_capacity = min_capacity;

	return array_set_capacity(array, new_capacity);
}

template<class Type> FORCEINLINE
usize array_num(Array<Type> array) {
	GEN_ASSERT(array != nullptr);
	return array_get_header(array)->Num;
}

template<class Type> FORCEINLINE
void array_pop(Array<Type> array) {
	GEN_ASSERT(array != nullptr);
	ArrayHeader* header = array_get_header(array);
	GEN_ASSERT(header->Num > 0);
	header->Num--;
}

template<class Type> inline
void array_remove_at(Array<Type> array, usize idx)
{
	GEN_ASSERT(array != nullptr);
	ArrayHeader* header = array_get_header(array);
	GEN_ASSERT(idx < header->Num);

	mem_move(array + idx, array + idx + 1, sizeof(Type) * (header->Num - idx - 1));
	header->Num--;
}

template<class Type> inline
bool array_reserve(Array<Type>* array, usize new_capacity)
{
	GEN_ASSERT(  array != nullptr);
	GEN_ASSERT(* array != nullptr);
	ArrayHeader* header = array_get_header(array);

	if (header->Capacity < new_capacity)
		return set_capacity(array, new_capacity);

	return true;
}

template<class Type> inline
bool array_resize(Array<Type>* array, usize num)
{
	GEN_ASSERT(  array != nullptr);
	GEN_ASSERT(* array != nullptr);
	ArrayHeader* header = array_get_header(* array);

	if (header->Capacity < num) {
		if (! array_grow( array, num))
			return false;
		header = array_get_header(* array);
	}

	header->Num = num;
	return true;
}

template<class Type> inline
bool array_set_capacity(Array<Type>* array, usize new_capacity)
{
	GEN_ASSERT(  array != nullptr);
	GEN_ASSERT(* array != nullptr);
	ArrayHeader* header = array_get_header(* array);

	if (new_capacity == header->Capacity)
		return true;

	if (new_capacity < header->Num)
	{
		header->Num = new_capacity;
		return true;
	}

	ssize        size       = sizeof(ArrayHeader) + sizeof(Type) * new_capacity;
	ArrayHeader* new_header = rcast(ArrayHeader*, alloc(header->Allocator, size));

	if (new_header == nullptr)
		return false;

	mem_move(new_header, header, sizeof(ArrayHeader) + sizeof(Type) * header->Num);

	new_header->Capacity = new_capacity;

	allocator_free(header->Allocator, header);

	Type** Data = (Type**)array;
	* Data = rcast(Type*, new_header + 1);
	return true;
}

// These are intended for use in the base library of gencpp and the C-variant of the library
// It provides a interoperability between the C++ and C implementation of arrays. (not letting these do any crazy substiution though)
// They are undefined in gen.hpp and gen.cpp at the end of the files.
// We cpp library expects the user to use the regular calls as they can resolve the type fine.

#define array_init(type, allocator)                        array_init           <type>                               (allocator )
#define array_init_reserve(type, allocator, cap)           array_init_reserve   <type>                               (allocator, cap)
#define array_append_array(array, other)                   array_append_array   < get_array_underlying_type(array) > (& array, other )
#define array_append(array, value)                         array_append         < get_array_underlying_type(array) > (& array, value )
#define array_append_items(array, items, item_num)         array_append_items   < get_array_underlying_type(array) > (& array, items, item_num )
#define array_append_at(array, item, idx )                 array_append_at      < get_array_underlying_type(array) > (& array, item, idx )
#define array_append_at_items(array, items, item_num, idx) array_append_at_items< get_array_underlying_type(array) > (& items, item_num, idx )
#define array_back(array)                                  array_back           < get_array_underlying_type(array) > (array )
#define array_clear(array)                                 array_clear          < get_array_underlying_type(array) > (array )
#define array_fill(array, begin, end, value)               array_fill           < get_array_underlying_type(array) > (array, begin, end, value )
#define array_free(array)                                  array_free           < get_array_underlying_type(array) > (& array )
#define arary_grow(array, min_capacity)                    arary_grow           < get_array_underlying_type(array) > (& array, min_capacity)
#define array_num(array)                                   array_num            < get_array_underlying_type(array) > (array )
#define arary_pop(array)                                   arary_pop            < get_array_underlying_type(array) > (array )
#define arary_remove_at(array, idx)                        arary_remove_at      < get_array_underlying_type(array) > (idx)
#define arary_reserve(array, new_capacity)                 arary_reserve        < get_array_underlying_type(array) > (& array, new_capacity )
#define arary_resize(array, num)                           arary_resize         < get_array_underlying_type(array) > (& array, num)
#define arary_set_capacity(new_capacity)                   arary_set_capacity   < get_array_underlying_type(array) > (& array, new_capacity )
#define arary_get_header(array)                            arary_get_header     < get_array_underlying_type(array) > (array )

#pragma endregion Array

#pragma region HashTable
#define HashTable(Type) HashTable<Type>

template<class Type> struct HashTable;

#ifndef get_hashtable_underlying_type
#define get_hashtable_underlying_type(table) typename TRemovePtr<typeof(table)>:: DataType
#endif

struct HashTableFindResult {
	ssize HashIndex;
	ssize PrevIndex;
	ssize EntryIndex;
};

template<class Type>
struct HashTableEntry {
	u64   Key;
	ssize Next;
	Type  Value;
};

#define HashTableEntry(Type) HashTableEntry<Type>

template<class Type> HashTable<Type>       hashtable_init        (AllocatorInfo allocator);
template<class Type> HashTable<Type>       hashtable_init_reserve(AllocatorInfo allocator, usize num);
template<class Type> void                  hashtable_clear       (HashTable<Type>  table);
template<class Type> void                  hashtable_destroy     (HashTable<Type>* table);
template<class Type> Type*                 hashtable_get         (HashTable<Type>  table, u64 key);
template<class Type> void                  hashtable_grow        (HashTable<Type>* table);
template<class Type> void                  hashtable_rehash      (HashTable<Type>* table, ssize new_num);
template<class Type> void                  hashtable_rehash_fast (HashTable<Type>  table);
template<class Type> void                  hashtable_remove      (HashTable<Type>  table, u64 key);
template<class Type> void                  hashtable_remove_entry(HashTable<Type>  table, ssize idx);
template<class Type> void                  hashtable_set         (HashTable<Type>* table, u64 key, Type value);
template<class Type> ssize                 hashtable_slot        (HashTable<Type>  table, u64 key);
template<class Type> void                  hashtable_map         (HashTable<Type>  table, void (*map_proc)(u64 key, Type value));
template<class Type> void                  hashtable_map_mut     (HashTable<Type>  table, void (*map_proc)(u64 key, Type* value));

template<class Type> ssize                 hashtable__add_entry  (HashTable<Type>* table, u64 key);
template<class Type> HashTableFindResult   hashtable__find       (HashTable<Type>  table, u64 key);
template<class Type> bool                  hashtable__full       (HashTable<Type>  table);

static constexpr f32 HashTable_CriticalLoadScale = 0.7f;

template<typename Type>
struct HashTable
{
	Array<ssize>                Hashes;
	Array<HashTableEntry<Type>> Entries;

#if ! GEN_C_LIKE_CPP
#pragma region Member Mapping
	FORCEINLINE static HashTable init(AllocatorInfo allocator)                    { return	hashtable_init<Type>(allocator); }
	FORCEINLINE static HashTable init_reserve(AllocatorInfo allocator, usize num) { return	hashtable_init_reserve<Type>(allocator, num); }

	FORCEINLINE void  clear()                           {        clear<Type>(*this); }
	FORCEINLINE void  destroy()                         {        destroy<Type>(*this); }
	FORCEINLINE Type* get(u64 key)                      { return get<Type>(*this, key); }
	FORCEINLINE void  grow()                            {        grow<Type>(*this); }
	FORCEINLINE void  rehash(ssize new_num)             {        rehash<Type>(*this, new_num); }
	FORCEINLINE void  rehash_fast()                     {        rehash_fast<Type>(*this); }
	FORCEINLINE void  remove(u64 key)                   {        remove<Type>(*this, key); }
	FORCEINLINE void  remove_entry(ssize idx)           {        remove_entry<Type>(*this, idx); }
	FORCEINLINE void  set(u64 key, Type value)          {        set<Type>(*this, key, value); }
	FORCEINLINE ssize slot(u64 key)                     { return slot<Type>(*this, key); }
	FORCEINLINE void  map(void (*proc)(u64, Type))      {        map<Type>(*this, proc); }
	FORCEINLINE void  map_mut(void (*proc)(u64, Type*)) {        map_mut<Type>(*this, proc); }
#pragma endregion Member Mapping
#endif

	using DataType = Type;
};

#if GEN_SUPPORT_CPP_REFERENCES
template<class Type> void  destroy  (HashTable<Type>& table)                      { destroy(& table); }
template<class Type> void  grow     (HashTable<Type>& table)                      { grow(& table); }
template<class Type> void  rehash   (HashTable<Type>& table, ssize new_num)       { rehash(& table, new_num); }
template<class Type> void  set      (HashTable<Type>& table, u64 key, Type value) { set(& table, key, value); }
template<class Type> ssize add_entry(HashTable<Type>& table, u64 key)             { add_entry(& table, key); }
#endif

template<typename Type> inline
HashTable<Type> hashtable_init(AllocatorInfo allocator) {
	HashTable<Type> result = hashtable_init_reserve<Type>(allocator, 8);
	return result;
}

template<typename Type> inline
HashTable<Type> hashtable_init_reserve(AllocatorInfo allocator, usize num)
{
	HashTable<Type> result = { { nullptr }, { nullptr } };

	result.Hashes = array_init_reserve<ssize>(allocator, num);
	array_get_header(result.Hashes)->Num = num;
	array_resize(& result.Hashes, num);
	array_fill(result.Hashes, 0, num, (ssize)-1);

	result.Entries = array_init_reserve<HashTableEntry<Type>>(allocator, num);
	return result;
}

template<typename Type> FORCEINLINE
void hashtable_clear(HashTable<Type> table) {
	GEN_ASSERT_NOT_NULL(table.Hashes);
	GEN_ASSERT_NOT_NULL(table.Entries);
	array_clear(table.Entries);
	array_fill(table.Hashes, 0, array_num(table.Hashes), (ssize)-1);
}

template<typename Type> FORCEINLINE
void hashtable_destroy(HashTable<Type>* table) {
	GEN_ASSERT_NOT_NULL(table->Hashes);
	GEN_ASSERT_NOT_NULL(table->Entries);
	if (table->Hashes && array_get_header(table->Hashes)->Capacity) {
		array_free(table->Hashes);
		array_free(table->Entries);
	}
}

template<typename Type> FORCEINLINE
Type* hashtable_get(HashTable<Type> table, u64 key) {
	GEN_ASSERT_NOT_NULL(table.Hashes);
	GEN_ASSERT_NOT_NULL(table.Entries);
	ssize idx = hashtable__find(table, key).EntryIndex;
	if (idx >= 0)
		return & table.Entries[idx].Value;

	return nullptr;
}

template<typename Type> FORCEINLINE
void hashtable_map(HashTable<Type> table, void (*map_proc)(u64 key, Type value)) {
	GEN_ASSERT_NOT_NULL(table.Hashes);
	GEN_ASSERT_NOT_NULL(table.Entries);
	GEN_ASSERT_NOT_NULL(map_proc);

	for (ssize idx = 0; idx < ssize(num(table.Entries)); ++idx) {
		map_proc(table.Entries[idx].Key, table.Entries[idx].Value);
	}
}

template<typename Type> FORCEINLINE
void hashtable_map_mut(HashTable<Type> table, void (*map_proc)(u64 key, Type* value)) {
	GEN_ASSERT_NOT_NULL(table.Hashes);
	GEN_ASSERT_NOT_NULL(table.Entries);
	GEN_ASSERT_NOT_NULL(map_proc);

	for (ssize idx = 0; idx < ssize(num(table.Entries)); ++idx) {
		map_proc(table.Entries[idx].Key, & table.Entries[idx].Value);
	}
}

template<typename Type> FORCEINLINE
void hashtable_grow(HashTable<Type>* table) {
	GEN_ASSERT_NOT_NULL(table);
	GEN_ASSERT_NOT_NULL(table->Hashes);
	GEN_ASSERT_NOT_NULL(table->Entries);
	ssize new_num = array_grow_formula( array_num(table->Entries));
	hashtable_rehash(table, new_num);
}

template<typename Type> inline
void hashtable_rehash(HashTable<Type>* table, ssize new_num)
{
	GEN_ASSERT_NOT_NULL(table);
	GEN_ASSERT_NOT_NULL(table->Hashes);
	GEN_ASSERT_NOT_NULL(table->Entries);
	ssize last_added_index;
	HashTable<Type> new_ht = hashtable_init_reserve<Type>( array_get_header(table->Hashes)->Allocator, new_num);

	for (ssize idx = 0; idx < ssize( array_num(table->Entries)); ++idx)
	{
		HashTableFindResult find_result;
		HashTableEntry<Type>& entry = table->Entries[idx];

		find_result = hashtable__find(new_ht, entry.Key);
		last_added_index = hashtable__add_entry(& new_ht, entry.Key);

		if (find_result.PrevIndex < 0)
			new_ht.Hashes[find_result.HashIndex] = last_added_index;
		else
			new_ht.Entries[find_result.PrevIndex].Next = last_added_index;

		new_ht.Entries[last_added_index].Next = find_result.EntryIndex;
		new_ht.Entries[last_added_index].Value = entry.Value;
	}

	hashtable_destroy(table);
	* table = new_ht;
}

template<typename Type> inline
void hashtable_rehash_fast(HashTable<Type> table)
{
	GEN_ASSERT_NOT_NULL(table.Hashes);
	GEN_ASSERT_NOT_NULL(table.Entries);
	ssize idx;

	for (idx = 0; idx < ssize(num(table.Entries)); idx++)
		table.Entries[idx].Next = -1;

	for (idx = 0; idx < ssize(num(table.Hashes)); idx++)
		table.Hashes[idx] = -1;

	for (idx = 0; idx < ssize(num(table.Entries)); idx++)
	{
		HashTableEntry<Type>* entry;
		HashTableFindResult find_result;

		entry = &table.Entries[idx];
		find_result = find(table, entry->Key);

		if (find_result.PrevIndex < 0)
			table.Hashes[find_result.HashIndex] = idx;
		else
			table.Entries[find_result.PrevIndex].Next = idx;
	}
}

template<typename Type> FORCEINLINE
void hashtable_remove(HashTable<Type> table, u64 key) {
	GEN_ASSERT_NOT_NULL(table.Hashes);
	GEN_ASSERT_NOT_NULL(table.Entries);
	HashTableFindResult find_result = find(table, key);

	if (find_result.EntryIndex >= 0) {
		remove_at(table.Entries, find_result.EntryIndex);
		rehash_fast(table);
	}
}

template<typename Type> FORCEINLINE
void hashtable_remove_entry(HashTable<Type> table, ssize idx) {
	GEN_ASSERT_NOT_NULL(table.Hashes);
	GEN_ASSERT_NOT_NULL(table.Entries);
	remove_at(table.Entries, idx);
}

template<typename Type> inline
void hashtable_set(HashTable<Type>* table, u64 key, Type value)
{
	GEN_ASSERT_NOT_NULL(table);
	GEN_ASSERT_NOT_NULL(table->Hashes);
	GEN_ASSERT_NOT_NULL(table->Entries);
	ssize idx;
	HashTableFindResult find_result;

	if (hashtable_full(* table))
		hashtable_grow(table);

	find_result = hashtable__find(* table, key);
	if (find_result.EntryIndex >= 0) {
		idx = find_result.EntryIndex;
	}
	else
	{
		idx = hashtable__add_entry(table, key);

		if (find_result.PrevIndex >= 0) {
			table->Entries[find_result.PrevIndex].Next = idx;
		}
		else {
			table->Hashes[find_result.HashIndex] = idx;
		}
	}

	table->Entries[idx].Value = value;

	if (hashtable_full(* table))
		hashtable_grow(table);
}

template<typename Type> FORCEINLINE
ssize hashtable_slot(HashTable<Type> table, u64 key) {
	GEN_ASSERT_NOT_NULL(table.Hashes);
	GEN_ASSERT_NOT_NULL(table.Entries);
	for (ssize idx = 0; idx < ssize(num(table.Hashes)); ++idx)
		if (table.Hashes[idx] == key)
			return idx;

	return -1;
}

template<typename Type> FORCEINLINE
ssize hashtable__add_entry(HashTable<Type>* table, u64 key) {
	GEN_ASSERT_NOT_NULL(table);
	GEN_ASSERT_NOT_NULL(table->Hashes);
	GEN_ASSERT_NOT_NULL(table->Entries);
	ssize idx;
	HashTableEntry<Type> entry = { key, -1 };

	idx = array_num(table->Entries);
	array_append( table->Entries, entry);
	return idx;
}

template<typename Type> inline
HashTableFindResult hashtable__find(HashTable<Type> table, u64 key)
{
	GEN_ASSERT_NOT_NULL(table.Hashes);
	GEN_ASSERT_NOT_NULL(table.Entries);
	HashTableFindResult result = { -1, -1, -1 };

	if (array_num(table.Hashes) > 0)
	{
		result.HashIndex = key % array_num(table.Hashes);
		result.EntryIndex = table.Hashes[result.HashIndex];

		while (result.EntryIndex >= 0)
		{
			if (table.Entries[result.EntryIndex].Key == key)
				break;

			result.PrevIndex  = result.EntryIndex;
			result.EntryIndex = table.Entries[result.EntryIndex].Next;
		}
	}

	return result;
}

template<typename Type> FORCEINLINE
b32 hashtable_full(HashTable<Type> table) {
	GEN_ASSERT_NOT_NULL(table.Hashes);
	GEN_ASSERT_NOT_NULL(table.Entries);
	usize critical_load = usize(HashTable_CriticalLoadScale * f32(array_num(table.Hashes)));
	b32 result = array_num(table.Entries) > critical_load;
	return result;
}

#define hashtable_init(type, allocator)              hashtable_init        <type              >(allocator)
#define hashtable_init_reserve(type, allocator, num) hashtable_init_reserve<type              >(allocator, num)
#define hashtable_clear(table)                       hashtable_clear       < get_hashtable_underlying_type(table) >(table)
#define hashtable_destroy(table)                     hashtable_destroy     < get_hashtable_underlying_type(table) >(& table)
#define hashtable_get(table, key)                    hashtable_get         < get_hashtable_underlying_type(table) >(table, key)
#define hashtable_grow(table)                        hashtable_grow        < get_hashtable_underlying_type(table) >(& table)
#define hashtable_rehash(table, new_num)             hashtable_rehash      < get_hashtable_underlying_type(table) >(& table, new_num)
#define hashtable_rehash_fast(table)                 hashtable_rehash_fast < get_hashtable_underlying_type(table) >(table)
#define hashtable_remove(table, key)                 hashtable_remove      < get_hashtable_underlying_type(table) >(table, key)
#define hashtable_remove_entry(table, idx)           hashtable_remove_entry< get_hashtable_underlying_type(table) >(table, idx)
#define hashtable_set(table, key, value)             hashtable_set         < get_hashtable_underlying_type(table) >(& table, key, value)
#define hashtable_slot(table, key)                   hashtable_slot        < get_hashtable_underlying_type(table) >(table, key)
#define hashtable_map(table, map_proc)               hashtable_map         < get_hashtable_underlying_type(table) >(table, map_proc)
#define hashtable_map_mut(table, map_proc)           hashtable_map_mut     < get_hashtable_underlying_type(table) >(table, map_proc)

//#define hashtable_add_entry(table, key)              hashtable_add_entry   < get_hashtable_underlying_type(table) >(& table, key)
//#define hashtable_find(table, key)                   hashtable_find        < get_hashtable_underlying_type(table) >(table, key)
//#define hashtable_full(table)                        hashtable_full        < get_hashtable_underlying_type(table) >(table)

#pragma endregion HashTable

#pragma endregion Containers

#pragma region Hashing

u32 crc32( void const* data, ssize len );
u64 crc64( void const* data, ssize len );

#pragma endregion Hashing

#pragma region Strings

struct Str;

Str         to_str_from_c_str       (char const* bad_string);
bool        str_are_equal           (Str lhs, Str rhs);
char const* str_back                (Str str);
bool        str_contains            (Str str, Str substring);
Str         str_duplicate           (Str str, AllocatorInfo allocator);
b32         str_starts_with         (Str str, Str substring);
Str         str_visualize_whitespace(Str str, AllocatorInfo allocator);

// Constant string with length.
struct Str
{
	char const* Ptr;
	ssize       Len;

#if GEN_COMPILER_CPP
	FORCEINLINE operator char const* ()               const { return Ptr; }
	FORCEINLINE char const& operator[]( ssize index ) const { return Ptr[index]; }

#if ! GEN_C_LIKE_CPP
	FORCEINLINE bool        is_equal            (Str rhs)                 const { return str_are_equal(* this, rhs); }
	FORCEINLINE char const* back                ()                        const { return str_back(* this); }
	FORCEINLINE bool        contains            (Str substring)           const { return str_contains(* this, substring); }
	FORCEINLINE Str         duplicate           (AllocatorInfo allocator) const { return str_duplicate(* this, allocator); }
	FORCEINLINE b32         starts_with         (Str substring)           const { return str_starts_with(* this, substring); }
	FORCEINLINE Str         visualize_whitespace(AllocatorInfo allocator) const { return str_visualize_whitespace(* this, allocator); }
#endif
#endif
};

#define cast_to_str( str ) * rcast( Str*, (str) - sizeof(ssize) )

#ifndef txt
#	if GEN_COMPILER_CPP
#		define txt( text )          GEN_NS Str { ( text ), sizeof( text ) - 1 }
#	else
#		define txt( text )         (GEN_NS Str){ ( text ), sizeof( text ) - 1 }
#	endif
#endif

GEN_API_C_BEGIN
FORCEINLINE char const* str_begin(Str str)                   { return str.Ptr; }
FORCEINLINE char const* str_end  (Str str)                   { return str.Ptr + str.Len; }
FORCEINLINE char const* str_next (Str str, char const* iter) { return iter + 1; }
GEN_API_C_END

#if GEN_COMPILER_CPP
FORCEINLINE char const* begin(Str str)                   { return str.Ptr; }
FORCEINLINE char const* end  (Str str)                   { return str.Ptr + str.Len; }
FORCEINLINE char const* next (Str str, char const* iter) { return iter + 1; }
#endif

inline
bool str_are_equal(Str lhs, Str rhs)
{
	if (lhs.Len != rhs.Len)
		return false;

	for (ssize idx = 0; idx < lhs.Len; ++idx)
		if (lhs.Ptr[idx] != rhs.Ptr[idx])
			return false;

	return true;
}

inline
char const* str_back(Str str) {
	return & str.Ptr[str.Len - 1];
}

inline
bool str_contains(Str str, Str substring)
{
	if (substring.Len > str.Len)
		return false;

	ssize main_len = str.Len;
	ssize sub_len  = substring.Len;
	for (ssize idx = 0; idx <= main_len - sub_len; ++idx)
	{
		if (c_str_compare_len(str.Ptr + idx, substring.Ptr, sub_len) == 0)
			return true;
	}
	return false;
}

inline
b32 str_starts_with(Str str, Str substring) {
	if (substring.Len > str.Len)
		return false;

	b32 result = c_str_compare_len(str.Ptr, substring.Ptr, substring.Len) == 0;
		return result;
}

inline
Str to_str_from_c_str( char const* bad_str ) {
	Str result = { bad_str, c_str_len( bad_str ) };
	return result;
}

// Dynamic StrBuilder
// This is directly based off the ZPL string api.
// They used a header pattern
// I kept it for simplicty of porting but its not necessary to keep it that way.
#pragma region StrBuilder
struct StrBuilderHeader;

#if GEN_COMPILER_C
typedef char* StrBuilder;
#else
struct StrBuilder;
#endif

FORCEINLINE usize strbuilder_grow_formula(usize value);

StrBuilder        strbuilder_make_c_str          (AllocatorInfo allocator, char const*  str);
StrBuilder        strbuilder_make_str            (AllocatorInfo allocator, Str         str);
StrBuilder        strbuilder_make_reserve        (AllocatorInfo allocator, ssize        capacity);
StrBuilder        strbuilder_make_length         (AllocatorInfo allocator, char const*  str,   ssize length);
StrBuilder        strbuilder_fmt                 (AllocatorInfo allocator, char*        buf,   ssize buf_size,  char const* fmt, ...);
StrBuilder        strbuilder_fmt_buf             (AllocatorInfo allocator, char const*  fmt, ...);
StrBuilder        strbuilder_join                (AllocatorInfo allocator, char const** parts, ssize num_parts, char const* glue);
bool              strbuilder_are_equal           (StrBuilder const lhs, StrBuilder const rhs);
bool              strbuilder_are_equal_str       (StrBuilder const lhs, Str rhs);
bool              strbuilder_make_space_for      (StrBuilder*      str, char const*  to_append, ssize add_len);
bool              strbuilder_append_char         (StrBuilder*      str, char         c);
bool              strbuilder_append_c_str        (StrBuilder*      str, char const*  c_str_to_append);
bool              strbuilder_append_c_str_len    (StrBuilder*      str, char const*  c_str_to_append, ssize length);
bool              strbuilder_append_str          (StrBuilder*      str, Str         c_str_to_append);
bool              strbuilder_append_string       (StrBuilder*      str, StrBuilder const other);
bool              strbuilder_append_fmt          (StrBuilder*      str, char const*  fmt, ...);
ssize             strbuilder_avail_space         (StrBuilder const str);
char*             strbuilder_back                (StrBuilder       str);
bool              strbuilder_contains_str        (StrBuilder const str, Str         substring);
bool              strbuilder_contains_string     (StrBuilder const str, StrBuilder const substring);
ssize             strbuilder_capacity            (StrBuilder const str);
void              strbuilder_clear               (StrBuilder       str);
StrBuilder        strbuilder_duplicate           (StrBuilder const str, AllocatorInfo allocator);
void              strbuilder_free                (StrBuilder*      str);
StrBuilderHeader* strbuilder_get_header          (StrBuilder       str);
ssize             strbuilder_length              (StrBuilder const str);
b32               strbuilder_starts_with_str     (StrBuilder const str, Str   substring);
b32               strbuilder_starts_with_string  (StrBuilder const str, StrBuilder substring);
void              strbuilder_skip_line           (StrBuilder       str);
void              strbuilder_strip_space         (StrBuilder       str);
Str               strbuilder_to_str              (StrBuilder       str);
void              strbuilder_trim                (StrBuilder       str, char const* cut_set);
void              strbuilder_trim_space          (StrBuilder       str);
StrBuilder        strbuilder_visualize_whitespace(StrBuilder const str);

struct StrBuilderHeader {
	AllocatorInfo Allocator;
	ssize         Capacity;
	ssize         Length;
};

#if GEN_COMPILER_CPP
struct StrBuilder
{
	char* Data;

	FORCEINLINE operator char*()             { return Data; }
	FORCEINLINE operator char const*() const { return Data; }
	FORCEINLINE operator Str()         const { return { Data, strbuilder_length(* this) }; }

	StrBuilder const& operator=(StrBuilder const& other) const {
		if (this == &other)
			return *this;

		StrBuilder* this_ = ccast(StrBuilder*, this);
		this_->Data = other.Data;

		return *this;
	}

	FORCEINLINE char&       operator[](ssize index)       { return Data[index]; }
	FORCEINLINE char const& operator[](ssize index) const { return Data[index]; }

	       FORCEINLINE bool operator==(std::nullptr_t) const                 { return     Data == nullptr; }
	       FORCEINLINE bool operator!=(std::nullptr_t) const                 { return     Data != nullptr; }
	friend FORCEINLINE bool operator==(std::nullptr_t, const StrBuilder str) { return str.Data == nullptr; }
	friend FORCEINLINE bool operator!=(std::nullptr_t, const StrBuilder str) { return str.Data != nullptr; }

#if ! GEN_C_LIKE_CPP
	FORCEINLINE char* begin() const { return Data; }
	FORCEINLINE char* end()   const { return Data + strbuilder_length(* this); }

#pragma region Member Mapping
	FORCEINLINE static StrBuilder make(AllocatorInfo allocator, char const* str)                { return strbuilder_make_c_str(allocator, str); }
	FORCEINLINE static StrBuilder make(AllocatorInfo allocator, Str str)                        { return strbuilder_make_str(allocator, str); }
	FORCEINLINE static StrBuilder make_reserve(AllocatorInfo allocator, ssize cap)              { return strbuilder_make_reserve(allocator, cap); }
	FORCEINLINE static StrBuilder make_length(AllocatorInfo a, char const* s, ssize l)          { return strbuilder_make_length(a, s, l); }
	FORCEINLINE static StrBuilder join(AllocatorInfo a, char const** p, ssize n, char const* g) { return strbuilder_join(a, p, n, g); }
	FORCEINLINE static usize      grow_formula(usize value)                                     { return strbuilder_grow_formula(value); }

	static
	StrBuilder fmt(AllocatorInfo allocator, char* buf, ssize buf_size, char const* fmt, ...) {
		va_list va;
		va_start(va, fmt);
		ssize res = c_str_fmt_va(buf, buf_size, fmt, va) - 1;
		va_end(va);
		return strbuilder_make_length(allocator, buf, res);
	}

	static
	StrBuilder fmt_buf(AllocatorInfo allocator, char const* fmt, ...) {
		local_persist thread_local
		char buf[GEN_PRINTF_MAXLEN] = { 0 };
		va_list va;
		va_start(va, fmt);
		ssize res = c_str_fmt_va(buf, GEN_PRINTF_MAXLEN, fmt, va) - 1;
		va_end(va);
		return strbuilder_make_length(allocator, buf, res);
	}

	FORCEINLINE bool              make_space_for(char const* str, ssize add_len) { return strbuilder_make_space_for(this, str, add_len); }
	FORCEINLINE bool              append(char c)                                 { return strbuilder_append_char(this, c); }
	FORCEINLINE bool              append(char const* str)                        { return strbuilder_append_c_str(this, str); }
	FORCEINLINE bool              append(char const* str, ssize length)          { return strbuilder_append_c_str_len(this, str, length); }
	FORCEINLINE bool              append(Str str)                                { return strbuilder_append_str(this, str); }
	FORCEINLINE bool              append(const StrBuilder other)                 { return strbuilder_append_string(this, other); }
	FORCEINLINE ssize             avail_space() const                            { return strbuilder_avail_space(* this); }
	FORCEINLINE char*             back()                                         { return strbuilder_back(* this); }
	FORCEINLINE bool              contains(Str substring) const                  { return strbuilder_contains_str(* this, substring); }
	FORCEINLINE bool              contains(StrBuilder const& substring) const    { return strbuilder_contains_string(* this, substring); }
	FORCEINLINE ssize             capacity() const                               { return strbuilder_capacity(* this); }
	FORCEINLINE void              clear()                                        {        strbuilder_clear(* this); }
	FORCEINLINE StrBuilder        duplicate(AllocatorInfo allocator) const       { return strbuilder_duplicate(* this, allocator); }
	FORCEINLINE void              free()                                         {        strbuilder_free(this); }
	FORCEINLINE bool              is_equal(StrBuilder const& other) const        { return strbuilder_are_equal(* this, other); }
	FORCEINLINE bool              is_equal(Str other) const                      { return strbuilder_are_equal_str(* this, other); }
	FORCEINLINE ssize             length() const                                 { return strbuilder_length(* this); }
	FORCEINLINE b32               starts_with(Str substring) const               { return strbuilder_starts_with_str(* this, substring); }
	FORCEINLINE b32               starts_with(StrBuilder substring) const        { return strbuilder_starts_with_string(* this, substring); }
	FORCEINLINE void              skip_line()                                    {        strbuilder_skip_line(* this); }
	FORCEINLINE void              strip_space()                                  {        strbuilder_strip_space(* this); }
	FORCEINLINE Str               to_str()                                       { return { Data, strbuilder_length(*this) }; }
	FORCEINLINE void              trim(char const* cut_set)                      {        strbuilder_trim(* this, cut_set); }
	FORCEINLINE void              trim_space()                                   {        strbuilder_trim_space(* this); }
	FORCEINLINE StrBuilder        visualize_whitespace() const                   { return strbuilder_visualize_whitespace(* this); }
	FORCEINLINE StrBuilderHeader& get_header()                                   { return * strbuilder_get_header(* this); }

	bool append_fmt(char const* fmt, ...) {
		ssize res;
		char buf[GEN_PRINTF_MAXLEN] = { 0 };

		va_list va;
		va_start(va, fmt);
		res = c_str_fmt_va(buf, count_of(buf) - 1, fmt, va) - 1;
		va_end(va);

		return strbuilder_append_c_str_len(this, buf, res);
	}
#pragma endregion Member Mapping
#endif
};
#endif

FORCEINLINE char* strbuilder_begin(StrBuilder str)                   { return ((char*) str); }
FORCEINLINE char* strbuilder_end  (StrBuilder str)                   { return ((char*) str + strbuilder_length(str)); }
FORCEINLINE char* strbuilder_next (StrBuilder str, char const* iter) { return ((char*) iter + 1); }

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
FORCEINLINE char* begin(StrBuilder str)             { return ((char*) str); }
FORCEINLINE char* end  (StrBuilder str)             { return ((char*) str + strbuilder_length(str)); }
FORCEINLINE char* next (StrBuilder str, char* iter) { return ((char*) iter + 1); }
#endif

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
FORCEINLINE bool  make_space_for(StrBuilder& str, char const* to_append, ssize add_len);
FORCEINLINE bool  append(StrBuilder& str, char c);
FORCEINLINE bool  append(StrBuilder& str, char const* c_str_to_append);
FORCEINLINE bool  append(StrBuilder& str, char const* c_str_to_append, ssize length);
FORCEINLINE bool  append(StrBuilder& str, Str c_str_to_append);
FORCEINLINE bool  append(StrBuilder& str, const StrBuilder other);
FORCEINLINE bool  append_fmt(StrBuilder& str, char const* fmt, ...);
FORCEINLINE char& back(StrBuilder& str);
FORCEINLINE void  clear(StrBuilder& str);
FORCEINLINE void  free(StrBuilder& str);
#endif

FORCEINLINE
usize strbuilder_grow_formula(usize value) {
	// Using a very aggressive growth formula to reduce time mem_copying with recursive calls to append in this library.
	return 4 * value + 8;
}

FORCEINLINE
StrBuilder strbuilder_make_c_str(AllocatorInfo allocator, char const* str) {
	ssize length = str ? c_str_len(str) : 0;
	return strbuilder_make_length(allocator, str, length);
}

FORCEINLINE
StrBuilder strbuilder_make_str(AllocatorInfo allocator, Str str) {
	return strbuilder_make_length(allocator, str.Ptr, str.Len);
}

inline
StrBuilder strbuilder_fmt(AllocatorInfo allocator, char* buf, ssize buf_size, char const* fmt, ...) {
	va_list va;
	va_start(va, fmt);
	ssize res = c_str_fmt_va(buf, buf_size, fmt, va) - 1;
	va_end(va);

	return strbuilder_make_length(allocator, buf, res);
}

inline
StrBuilder strbuilder_fmt_buf(AllocatorInfo allocator, char const* fmt, ...)
{
	local_persist thread_local
	PrintF_Buffer buf = struct_init(PrintF_Buffer, {0});

	va_list va;
	va_start(va, fmt);
	ssize res = c_str_fmt_va(buf, GEN_PRINTF_MAXLEN, fmt, va) -1;
	va_end(va);

	return strbuilder_make_length(allocator, buf, res);
}

inline
StrBuilder strbuilder_join(AllocatorInfo allocator, char const** parts, ssize num_parts, char const* glue)
{
	StrBuilder result = strbuilder_make_c_str(allocator, "");

	for (ssize idx = 0; idx < num_parts; ++idx)
	{
		strbuilder_append_c_str(& result, parts[idx]);

		if (idx < num_parts - 1)
			strbuilder_append_c_str(& result, glue);
	}

	return result;
}

FORCEINLINE
bool strbuilder_append_char(StrBuilder* str, char c) {
	GEN_ASSERT(str != nullptr);
	return strbuilder_append_c_str_len( str, (char const*)& c, (ssize)1);
}

FORCEINLINE
bool strbuilder_append_c_str(StrBuilder* str, char const* c_str_to_append) {
	GEN_ASSERT(str != nullptr);
	return strbuilder_append_c_str_len(str, c_str_to_append, c_str_len(c_str_to_append));
}

inline
bool strbuilder_append_c_str_len(StrBuilder* str, char const* c_str_to_append, ssize append_length)
{
	GEN_ASSERT(str != nullptr);
	if ( rcast(sptr, c_str_to_append) > 0)
	{
		ssize curr_len = strbuilder_length(* str);

		if ( ! strbuilder_make_space_for(str, c_str_to_append, append_length))
			return false;

		StrBuilderHeader* header = strbuilder_get_header(* str);

		char* Data = * str;
		mem_copy( Data + curr_len, c_str_to_append, append_length);

		Data[curr_len + append_length] = '\0';

		header->Length = curr_len + append_length;
	}
	return c_str_to_append != nullptr;
}

FORCEINLINE
bool strbuilder_append_str(StrBuilder* str, Str c_str_to_append) {
	GEN_ASSERT(str != nullptr);
	return strbuilder_append_c_str_len(str, c_str_to_append.Ptr, c_str_to_append.Len);
}

FORCEINLINE
bool strbuilder_append_string(StrBuilder* str, StrBuilder const other) {
	GEN_ASSERT(str != nullptr);
	return strbuilder_append_c_str_len(str, (char const*)other, strbuilder_length(other));
}

inline
bool strbuilder_append_fmt(StrBuilder* str, char const* fmt, ...) {
	GEN_ASSERT(str != nullptr);
	ssize res;
	char buf[GEN_PRINTF_MAXLEN] = { 0 };

	va_list va;
	va_start(va, fmt);
	res = c_str_fmt_va(buf, count_of(buf) - 1, fmt, va) - 1;
	va_end(va);

	return strbuilder_append_c_str_len(str, (char const*)buf, res);
}

inline
bool strbuilder_are_equal_string(StrBuilder const lhs, StrBuilder const rhs)
{
	if (strbuilder_length(lhs) != strbuilder_length(rhs))
		return false;

	for (ssize idx = 0; idx < strbuilder_length(lhs); ++idx)
		if (lhs[idx] != rhs[idx])
			return false;

	return true;
}

inline
bool strbuilder_are_equal_str(StrBuilder const lhs, Str rhs)
{
	if (strbuilder_length(lhs) != (rhs.Len))
		return false;

	for (ssize idx = 0; idx < strbuilder_length(lhs); ++idx)
		if (lhs[idx] != rhs.Ptr[idx])
			return false;

	return true;
}

FORCEINLINE
ssize strbuilder_avail_space(StrBuilder const str) {
	StrBuilderHeader const* header = rcast(StrBuilderHeader const*, scast(char const*, str) - sizeof(StrBuilderHeader));
	return header->Capacity - header->Length;
}

FORCEINLINE
char* strbuilder_back(StrBuilder str) {
	return & (str)[strbuilder_length(str) - 1];
}

inline
bool strbuilder_contains_StrC(StrBuilder const str, Str substring)
{
	StrBuilderHeader const* header = rcast(StrBuilderHeader const*, scast(char const*, str) - sizeof(StrBuilderHeader));

	if (substring.Len > header->Length)
		return false;

	ssize main_len = header->Length;
	ssize sub_len  = substring.Len;

	for (ssize idx = 0; idx <= main_len - sub_len; ++idx)
	{
		if (c_str_compare_len(str + idx, substring.Ptr, sub_len) == 0)
			return true;
	}

	return false;
}

inline
bool strbuilder_contains_string(StrBuilder const str, StrBuilder const substring)
{
	StrBuilderHeader const* header = rcast(StrBuilderHeader const*, scast(char const*, str) - sizeof(StrBuilderHeader));

	if (strbuilder_length(substring) > header->Length)
		return false;

	ssize main_len = header->Length;
	ssize sub_len  = strbuilder_length(substring);

	for (ssize idx = 0; idx <= main_len - sub_len; ++idx)
	{
		if (c_str_compare_len(str + idx, substring, sub_len) == 0)
			return true;
	}

	return false;
}

FORCEINLINE
ssize strbuilder_capacity(StrBuilder const str) {
	StrBuilderHeader const* header = rcast(StrBuilderHeader const*, scast(char const*, str) - sizeof(StrBuilderHeader));
	return header->Capacity;
}

FORCEINLINE
void strbuilder_clear(StrBuilder str) {
	strbuilder_get_header(str)->Length = 0;
}

FORCEINLINE
StrBuilder strbuilder_duplicate(StrBuilder const str, AllocatorInfo allocator) {
	return strbuilder_make_length(allocator, str, strbuilder_length(str));
}

FORCEINLINE
void strbuilder_free(StrBuilder* str) {
	GEN_ASSERT(str != nullptr);
	if (! (* str))
		return;

	StrBuilderHeader* header = strbuilder_get_header(* str);
	allocator_free(header->Allocator, header);
}

FORCEINLINE
StrBuilderHeader* strbuilder_get_header(StrBuilder str) {
	return (StrBuilderHeader*)(scast(char*, str) - sizeof(StrBuilderHeader));
}

FORCEINLINE
ssize strbuilder_length(StrBuilder const str)
{
	StrBuilderHeader const* header = rcast(StrBuilderHeader const*, scast(char const*, str) - sizeof(StrBuilderHeader));
	return header->Length;
}

inline
bool strbuilder_make_space_for(StrBuilder* str, char const* to_append, ssize add_len)
{
	ssize available = strbuilder_avail_space(* str);

	if (available >= add_len) {
		return true;
	}
	else
	{
		ssize new_len, old_size, new_size;
		void* ptr;
		void* new_ptr;

		AllocatorInfo allocator = strbuilder_get_header(* str)->Allocator;
		StrBuilderHeader* header    = nullptr;

		new_len  = strbuilder_grow_formula(strbuilder_length(* str) + add_len);
		ptr      = strbuilder_get_header(* str);
		old_size = size_of(StrBuilderHeader) + strbuilder_length(* str) + 1;
		new_size = size_of(StrBuilderHeader) + new_len + 1;

		new_ptr = resize(allocator, ptr, old_size, new_size);

		if (new_ptr == nullptr)
			return false;

		header = rcast(StrBuilderHeader*, new_ptr);
		header->Allocator = allocator;
		header->Capacity  = new_len;

		char** Data = rcast(char**, str);
		* Data = rcast(char*, header + 1);

		return true;
	}
}

FORCEINLINE
b32 strbuilder_starts_with_str(StrBuilder const str, Str substring) {
	if (substring.Len > strbuilder_length(str))
	return false;

	b32 result = c_str_compare_len(str, substring.Ptr, substring.Len) == 0;
	return result;
}

FORCEINLINE
b32 strbuilder_starts_with_string(StrBuilder const str, StrBuilder substring) {
	if (strbuilder_length(substring) > strbuilder_length(str))
		return false;

	b32 result = c_str_compare_len(str, substring, strbuilder_length(substring) - 1) == 0;
	return result;
}

inline
void strbuilder_skip_line(StrBuilder str)
{
#define current (*scanner)
	char* scanner = str;
	while (current != '\r' && current != '\n') {
		++scanner;
	}

	s32 new_length = scanner - str;

	if (current == '\r') {
		new_length += 1;
	}

	mem_move((char*)str, scanner, new_length);

	StrBuilderHeader* header = strbuilder_get_header(str);
	header->Length = new_length;
#undef current
}

inline
void strbuilder_strip_space(StrBuilder str)
{
	char* write_pos = str;
	char* read_pos  = str;

	while (* read_pos)
	{
		if (! char_is_space(* read_pos))
		{
   			* write_pos = * read_pos;
			write_pos++;
		}
		read_pos++;
	}
   write_pos[0] = '\0';  // Null-terminate the modified string

	// Update the length if needed
	strbuilder_get_header(str)->Length = write_pos - str;
}

FORCEINLINE
Str strbuilder_to_str(StrBuilder str) {
	Str result = { (char const*)str, strbuilder_length(str) };
	return result;
}

inline
void strbuilder_trim(StrBuilder str, char const* cut_set)
{
	ssize len = 0;

	char* start_pos = str;
	char* end_pos   = scast(char*, str) + strbuilder_length(str) - 1;

	while (start_pos <= end_pos && char_first_occurence(cut_set, *start_pos))
	start_pos++;

	while (end_pos > start_pos && char_first_occurence(cut_set, *end_pos))
	end_pos--;

	len = scast(ssize, (start_pos > end_pos) ? 0 : ((end_pos - start_pos) + 1));

	if (str != start_pos)
		mem_move(str, start_pos, len);

	str[len] = '\0';

	strbuilder_get_header(str)->Length = len;
}

FORCEINLINE
void strbuilder_trim_space(StrBuilder str) {
	strbuilder_trim(str, " \t\r\n\v\f");
}

inline
StrBuilder strbuilder_visualize_whitespace(StrBuilder const str)
{
	StrBuilderHeader* header = (StrBuilderHeader*)(scast(char const*, str) - sizeof(StrBuilderHeader));
	StrBuilder        result = strbuilder_make_reserve(header->Allocator, strbuilder_length(str) * 2); // Assume worst case for space requirements.

	for (char const* c = strbuilder_begin(str); c != strbuilder_end(str); c = strbuilder_next(str, c))
	switch ( * c )
	{
		case ' ':
			strbuilder_append_str(& result, txt("·"));
		break;
		case '\t':
			strbuilder_append_str(& result, txt("→"));
		break;
		case '\n':
			strbuilder_append_str(& result, txt("↵"));
		break;
		case '\r':
			strbuilder_append_str(& result, txt("⏎"));
		break;
		case '\v':
			strbuilder_append_str(& result, txt("⇕"));
		break;
		case '\f':
			strbuilder_append_str(& result, txt("⌂"));
		break;
		default:
			strbuilder_append_char(& result, * c);
		break;
	}

	return result;
}
#pragma endregion StrBuilder

#if GEN_COMPILER_CPP
struct StrBuilder_POD {
	char* Data;
};
static_assert( sizeof( StrBuilder_POD ) == sizeof( StrBuilder ), "StrBuilder is not a POD" );
#endif

FORCEINLINE
Str str_duplicate(Str str, AllocatorInfo allocator) {
	Str result = strbuilder_to_str( strbuilder_make_length(allocator, str.Ptr, str.Len));
	return result;
}

inline
Str str_visualize_whitespace(Str str, AllocatorInfo allocator)
{
	StrBuilder result = strbuilder_make_reserve(allocator, str.Len * 2); // Assume worst case for space requirements.
	for (char const* c = str_begin(str); c != str_end(str); c = str_next(str, c))
	switch ( * c )
	{
		case ' ':
			strbuilder_append_str(& result, txt("·"));
		break;
		case '\t':
			strbuilder_append_str(& result, txt("→"));
		break;
		case '\n':
			strbuilder_append_str(& result, txt("↵"));
		break;
		case '\r':
			strbuilder_append_str(& result, txt("⏎"));
		break;
		case '\v':
			strbuilder_append_str(& result, txt("⇕"));
		break;
		case '\f':
			strbuilder_append_str(& result, txt("⌂"));
		break;
		default:
			strbuilder_append_char(& result, * c);
		break;
}
	return strbuilder_to_str(result);
}

// Represents strings cached with the string table.
// Should never be modified, if changed string is desired, cache_string( str ) another.
typedef Str StrCached;

// Implements basic string interning. Data structure is based off the ZPL Hashtable.
typedef HashTable(StrCached) StringTable;
#pragma endregion Strings

#pragma region File Handling

enum FileModeFlag
{
	EFileMode_READ   = bit( 0 ),
	EFileMode_WRITE  = bit( 1 ),
	EFileMode_APPEND = bit( 2 ),
	EFileMode_RW     = bit( 3 ),
	GEN_FILE_MODES   = EFileMode_READ | EFileMode_WRITE | EFileMode_APPEND | EFileMode_RW,
};

// NOTE: Only used internally and for the file operations
enum SeekWhenceType
{
	ESeekWhence_BEGIN   = 0,
	ESeekWhence_CURRENT = 1,
	ESeekWhence_END     = 2,
};

enum FileError
{
	EFileError_NONE,
	EFileError_INVALID,
	EFileError_INVALID_FILENAME,
	EFileError_EXISTS,
	EFileError_NOT_EXISTS,
	EFileError_PERMISSION,
	EFileError_TRUNCATION_FAILURE,
	EFileError_NOT_EMPTY,
	EFileError_NAME_TOO_LONG,
	EFileError_UNKNOWN,
};

union FileDescriptor
{
	void* p;
	sptr  i;
	uptr  u;
};

typedef u32                   FileMode;
typedef struct FileOperations FileOperations;

#define GEN_FILE_OPEN_PROC( name )     FileError name( FileDescriptor* fd, FileOperations* ops, FileMode mode, char const* filename )
#define GEN_FILE_READ_AT_PROC( name )  b32 name( FileDescriptor fd, void* buffer, ssize size, s64 offset, ssize* bytes_read, b32 stop_at_newline )
#define GEN_FILE_WRITE_AT_PROC( name ) b32 name( FileDescriptor fd, mem_ptr_const buffer, ssize size, s64 offset, ssize* bytes_written )
#define GEN_FILE_SEEK_PROC( name )     b32 name( FileDescriptor fd, s64 offset, SeekWhenceType whence, s64* new_offset )
#define GEN_FILE_CLOSE_PROC( name )    void name( FileDescriptor fd )

typedef GEN_FILE_OPEN_PROC( file_open_proc );
typedef GEN_FILE_READ_AT_PROC( FileReadProc );
typedef GEN_FILE_WRITE_AT_PROC( FileWriteProc );
typedef GEN_FILE_SEEK_PROC( FileSeekProc );
typedef GEN_FILE_CLOSE_PROC( FileCloseProc );

struct FileOperations
{
	FileReadProc*  read_at;
	FileWriteProc* write_at;
	FileSeekProc*  seek;
	FileCloseProc* close;
};

extern FileOperations const default_file_operations;

typedef u64 FileTime;

enum DirType
{
	GEN_DIR_TYPE_FILE,
	GEN_DIR_TYPE_FOLDER,
	GEN_DIR_TYPE_UNKNOWN,
};

struct DirInfo;

struct DirEntry
{
	char const* filename;
	DirInfo*    dir_info;
	u8          type;
};

struct DirInfo
{
	char const* fullpath;
	DirEntry*   entries;    // zpl_array

	// Internals
	char** filenames;    // zpl_array
	StrBuilder buf;
};

struct FileInfo
{
	FileOperations ops;
	FileDescriptor fd;
	b32            is_temp;

	char const* filename;
	FileTime    last_write_time;
	DirEntry*   dir;
};

enum FileStandardType
{
	EFileStandard_INPUT,
	EFileStandard_OUTPUT,
	EFileStandard_ERROR,

	EFileStandard_COUNT,
};

/**
	* Get standard file I/O.
	* @param  std Check zpl_file_standard_type
	* @return     File handle to standard I/O
	*/
FileInfo* file_get_standard( FileStandardType std );

/**
	* Closes the file
	* @param  file
	*/
FileError file_close( FileInfo* file );

/**
	* Returns the currently opened file's name
	* @param  file
	*/
inline
	char const* file_name( FileInfo* file )
{
	return file->filename ? file->filename : "";
}

/**
	* Opens a file
	* @param  file
	* @param  filename
	*/
FileError file_open( FileInfo* file, char const* filename );

/**
	* Opens a file using a specified mode
	* @param  file
	* @param  mode     Access mode to use
	* @param  filename
	*/
FileError file_open_mode( FileInfo* file, FileMode mode, char const* filename );

/**
	* Reads from a file
	* @param  file
	* @param  buffer Buffer to read to
	* @param  size   Size to read
	*/
b32 file_read( FileInfo* file, void* buffer, ssize size );

/**
	* Reads file at a specific offset
	* @param  file
	* @param  buffer     Buffer to read to
	* @param  size       Size to read
	* @param  offset     Offset to read from
	* @param  bytes_read How much data we've actually read
	*/
b32 file_read_at( FileInfo* file, void* buffer, ssize size, s64 offset );

/**
	* Reads file safely
	* @param  file
	* @param  buffer     Buffer to read to
	* @param  size       Size to read
	* @param  offset     Offset to read from
	* @param  bytes_read How much data we've actually read
	*/
b32 file_read_at_check( FileInfo* file, void* buffer, ssize size, s64 offset, ssize* bytes_read );

typedef struct FileContents FileContents;
struct FileContents
{
	AllocatorInfo allocator;
	void*         data;
	ssize            size;
};

constexpr b32 file_zero_terminate    = true;
constexpr b32 file_no_zero_terminate = false;

/**
	* Reads the whole file contents
	* @param  a              Allocator to use
	* @param  zero_terminate End the read data with null terminator
	* @param  filepath       Path to the file
	* @return                File contents data
	*/
FileContents file_read_contents( AllocatorInfo a, b32 zero_terminate, char const* filepath );

/**
	* Returns a size of the file
	* @param  file
	* @return      File size
	*/
s64 file_size( FileInfo* file );

/**
	* Seeks the file cursor from the beginning of file to a specific position
	* @param  file
	* @param  offset Offset to seek to
	*/
s64 file_seek( FileInfo* file, s64 offset );

/**
	* Seeks the file cursor to the end of the file
	* @param  file
	*/
s64 file_seek_to_end( FileInfo* file );

/**
	* Returns the length from the beginning of the file we've read so far
	* @param  file
	* @return      Our current position in file
	*/
s64 file_tell( FileInfo* file );

/**
	* Writes to a file
	* @param  file
	* @param  buffer Buffer to read from
	* @param  size   Size to read
	*/
b32 file_write( FileInfo* file, void const* buffer, ssize size );

/**
	* Writes to file at a specific offset
	* @param  file
	* @param  buffer        Buffer to read from
	* @param  size          Size to write
	* @param  offset        Offset to write to
	* @param  bytes_written How much data we've actually written
	*/
b32 file_write_at( FileInfo* file, void const* buffer, ssize size, s64 offset );

/**
	* Writes to file safely
	* @param  file
	* @param  buffer        Buffer to read from
	* @param  size          Size to write
	* @param  offset        Offset to write to
	* @param  bytes_written How much data we've actually written
	*/
b32 file_write_at_check( FileInfo* file, void const* buffer, ssize size, s64 offset, ssize* bytes_written );

enum FileStreamFlags : u32
{
	/* Allows us to write to the buffer directly. Beware: you can not append a new data! */
	EFileStream_WRITABLE = bit( 0 ),

	/* Clones the input buffer so you can write (zpl_file_write*) data into it. */
	/* Since we work with a clone, the buffer size can dynamically grow as well. */
	EFileStream_CLONE_WRITABLE = bit( 1 ),

	EFileStream_UNDERLYING = GEN_U32_MAX,
};

/**
	* Opens a new memory stream
	* @param file
	* @param allocator
	*/
b8 file_stream_new( FileInfo* file, AllocatorInfo allocator );

/**
	* Opens a memory stream over an existing buffer
	* @param  file
	* @param  allocator
	* @param  buffer   Memory to create stream from
	* @param  size     Buffer's size
	* @param  flags
	*/
b8 file_stream_open( FileInfo* file, AllocatorInfo allocator, u8* buffer, ssize size, FileStreamFlags flags );

/**
	* Retrieves the stream's underlying buffer and buffer size.
	* @param file memory stream
	* @param size (Optional) buffer size
	*/
u8* file_stream_buf( FileInfo* file, ssize* size );

extern FileOperations const memory_file_operations;

inline
s64 file_seek( FileInfo* f, s64 offset )
{
	s64 new_offset = 0;

	if ( ! f->ops.read_at )
		f->ops = default_file_operations;

	f->ops.seek( f->fd, offset, ESeekWhence_BEGIN, &new_offset );

	return new_offset;
}

inline
s64 file_seek_to_end( FileInfo* f )
{
	s64 new_offset = 0;

	if ( ! f->ops.read_at )
		f->ops = default_file_operations;

	f->ops.seek( f->fd, 0, ESeekWhence_END, &new_offset );

	return new_offset;
}

inline
s64 file_tell( FileInfo* f )
{
	s64 new_offset = 0;

	if ( ! f->ops.read_at )
		f->ops = default_file_operations;

	f->ops.seek( f->fd, 0, ESeekWhence_CURRENT, &new_offset );

	return new_offset;
}

inline
b32 file_read( FileInfo* f, void* buffer, ssize size )
{
	s64 cur_offset = file_tell( f );
	b32 result     = file_read_at( f, buffer, size, file_tell( f ) );
	file_seek( f, cur_offset + size );
	return result;
}

inline
b32 file_read_at( FileInfo* f, void* buffer, ssize size, s64 offset )
{
	return file_read_at_check( f, buffer, size, offset, NULL );
}

inline
b32 file_read_at_check( FileInfo* f, void* buffer, ssize size, s64 offset, ssize* bytes_read )
{
	if ( ! f->ops.read_at )
		f->ops = default_file_operations;
	return f->ops.read_at( f->fd, buffer, size, offset, bytes_read, false );
}

inline
b32 file_write( FileInfo* f, void const* buffer, ssize size )
{
	s64 cur_offset = file_tell( f );
	b32 result     = file_write_at( f, buffer, size, file_tell( f ) );

	file_seek( f, cur_offset + size );

	return result;
}

inline
b32 file_write_at( FileInfo* f, void const* buffer, ssize size, s64 offset )
{
	return file_write_at_check( f, buffer, size, offset, NULL );
}

inline
b32 file_write_at_check( FileInfo* f, void const* buffer, ssize size, s64 offset, ssize* bytes_written )
{
	if ( ! f->ops.read_at )
		f->ops = default_file_operations;

	return f->ops.write_at( f->fd, buffer, size, offset, bytes_written );
}

#pragma endregion File Handling

#pragma region Timing

#ifdef GEN_BENCHMARK
//! Return CPU timestamp.
u64 read_cpu_time_stamp_counter( void );

//! Return relative time (in seconds) since the application start.
f64 time_rel( void );

//! Return relative time since the application start.
u64 time_rel_ms( void );
#endif

#pragma endregion Timing

#pragma region ADT

enum ADT_Type : u32
{
	EADT_TYPE_UNINITIALISED, /* node was not initialised, this is a programming error! */
	EADT_TYPE_ARRAY,
	EADT_TYPE_OBJECT,
	EADT_TYPE_STRING,
	EADT_TYPE_MULTISTRING,
	EADT_TYPE_INTEGER,
	EADT_TYPE_REAL,
};

enum ADT_Props : u32
{
	EADT_PROPS_NONE,
	EADT_PROPS_NAN,
	EADT_PROPS_NAN_NEG,
	EADT_PROPS_INFINITY,
	EADT_PROPS_INFINITY_NEG,
	EADT_PROPS_FALSE,
	EADT_PROPS_TRUE,
	EADT_PROPS_NULL,
	EADT_PROPS_IS_EXP,
	EADT_PROPS_IS_HEX,

	// Used internally so that people can fill in real numbers they plan to write.
	EADT_PROPS_IS_PARSED_REAL,
};

enum ADT_NamingStyle : u32
{
	EADT_NAME_STYLE_DOUBLE_QUOTE,
	EADT_NAME_STYLE_SINGLE_QUOTE,
	EADT_NAME_STYLE_NO_QUOTES,
};

enum ADT_AssignStyle : u32
{
	EADT_ASSIGN_STYLE_COLON,
	EADT_ASSIGN_STYLE_EQUALS,
	EADT_ASSIGN_STYLE_LINE,
};

enum ADT_DelimStyle : u32
{
	EADT_DELIM_STYLE_COMMA,
	EADT_DELIM_STYLE_LINE,
	EADT_DELIM_STYLE_NEWLINE,
};

enum ADT_Error : u32
{
	EADT_ERROR_NONE,
	EADT_ERROR_INTERNAL,
	EADT_ERROR_ALREADY_CONVERTED,
	EADT_ERROR_INVALID_TYPE,
	EADT_ERROR_OUT_OF_MEMORY,
};

struct ADT_Node
{
	char const*      name;
	struct ADT_Node* parent;

	/* properties */
	ADT_Type type  : 4;
	u8 props : 4;
#ifndef GEN_PARSER_DISABLE_ANALYSIS
	u8 cfg_mode          : 1;
	u8 name_style        : 2;
	u8 assign_style      : 2;
	u8 delim_style       : 2;
	u8 delim_line_width  : 4;
	u8 assign_line_width : 4;
#endif

	/* adt data */
	union
	{
		char const*     string;
		Array(ADT_Node) nodes;    ///< zpl_array

		struct
		{
			union
			{
				f64 real;
				s64 integer;
			};

#ifndef GEN_PARSER_DISABLE_ANALYSIS
			/* number analysis */
			s32 base;
			s32 base2;
			u8  base2_offset : 4;
			s8  exp          : 4;
			u8  neg_zero     : 1;
			u8  lead_digit   : 1;
#endif
		};
	};
};

/* ADT NODE LIMITS
	* delimiter and assignment segment width is limited to 128 whitespace symbols each.
	* real number limits decimal position to 128 places.
	* real number exponent is limited to 64 digits.
	*/

/**
	* @brief Initialise an ADT object or array
	*
	* @param node
	* @param backing Memory allocator used for descendants
	* @param name Node's name
	* @param is_array
	* @return error code
	*/
u8 adt_make_branch( ADT_Node* node, AllocatorInfo backing, char const* name, b32 is_array );

/**
	* @brief Destroy an ADT branch and its descendants
	*
	* @param node
	* @return error code
	*/
u8 adt_destroy_branch( ADT_Node* node );

/**
	* @brief Initialise an ADT leaf
	*
	* @param node
	* @param name Node's name
	* @param type Node's type (use zpl_adt_make_branch for container nodes)
	* @return error code
	*/
u8 adt_make_leaf( ADT_Node* node, char const* name, ADT_Type type );


/**
	* @brief Fetch a node using provided URI string.
	*
	* This method uses a basic syntax to fetch a node from the ADT. The following features are available
	* to retrieve the data:
	*
	* - "a/b/c" navigates through objects "a" and "b" to get to "c"
	* - "arr/[foo=123]/bar" iterates over "arr" to find any object with param "foo" that matches the value "123", then gets its field called "bar"
	* - "arr/3" retrieves the 4th element in "arr"
	* - "arr/[apple]" retrieves the first element of value "apple" in "arr"
	*
	* @param node ADT node
	* @param uri Locator string as described above
	* @return zpl_adt_node*
	*
	* @see code/apps/examples/json_get.c
	*/
ADT_Node* adt_query( ADT_Node* node, char const* uri );

/**
	* @brief Find a field node within an object by the given name.
	*
	* @param node
	* @param name
	* @param deep_search Perform search recursively
	* @return zpl_adt_node * node
	*/
ADT_Node* adt_find( ADT_Node* node, char const* name, b32 deep_search );

/**
	* @brief Allocate an unitialised node within a container at a specified index.
	*
	* @param parent
	* @param index
	* @return zpl_adt_node * node
	*/
ADT_Node* adt_alloc_at( ADT_Node* parent, ssize index );

/**
	* @brief Allocate an unitialised node within a container.
	*
	* @param parent
	* @return zpl_adt_node * node
	*/
ADT_Node* adt_alloc( ADT_Node* parent );

/**
	* @brief Move an existing node to a new container at a specified index.
	*
	* @param node
	* @param new_parent
	* @param index
	* @return zpl_adt_node * node
	*/
ADT_Node* adt_move_node_at( ADT_Node* node, ADT_Node* new_parent, ssize index );

/**
	* @brief Move an existing node to a new container.
	*
	* @param node
	* @param new_parent
	* @return zpl_adt_node * node
	*/
ADT_Node* adt_move_node( ADT_Node* node, ADT_Node* new_parent );

/**
	* @brief Swap two nodes.
	*
	* @param node
	* @param other_node
	* @return
	*/
void adt_swap_nodes( ADT_Node* node, ADT_Node* other_node );

/**
	* @brief Remove node from container.
	*
	* @param node
	* @return
	*/
void adt_remove_node( ADT_Node* node );

/**
	* @brief Initialise a node as an object
	*
	* @param obj
	* @param name
	* @param backing
	* @return
	*/
b8 adt_set_obj( ADT_Node* obj, char const* name, AllocatorInfo backing );

/**
	* @brief Initialise a node as an array
	*
	* @param obj
	* @param name
	* @param backing
	* @return
	*/
b8 adt_set_arr( ADT_Node* obj, char const* name, AllocatorInfo backing );

/**
	* @brief Initialise a node as a string
	*
	* @param obj
	* @param name
	* @param value
	* @return
	*/
b8 adt_set_str( ADT_Node* obj, char const* name, char const* value );

/**
	* @brief Initialise a node as a float
	*
	* @param obj
	* @param name
	* @param value
	* @return
	*/
b8 adt_set_flt( ADT_Node* obj, char const* name, f64 value );

/**
	* @brief Initialise a node as a signed integer
	*
	* @param obj
	* @param name
	* @param value
	* @return
	*/
b8 adt_set_int( ADT_Node* obj, char const* name, s64 value );

/**
	* @brief Append a new node to a container as an object
	*
	* @param parent
	* @param name
	* @return*
	*/
ADT_Node* adt_append_obj( ADT_Node* parent, char const* name );

/**
	* @brief Append a new node to a container as an array
	*
	* @param parent
	* @param name
	* @return*
	*/
ADT_Node* adt_append_arr( ADT_Node* parent, char const* name );

/**
	* @brief Append a new node to a container as a string
	*
	* @param parent
	* @param name
	* @param value
	* @return*
	*/
ADT_Node* adt_append_str( ADT_Node* parent, char const* name, char const* value );

/**
	* @brief Append a new node to a container as a float
	*
	* @param parent
	* @param name
	* @param value
	* @return*
	*/
ADT_Node* adt_append_flt( ADT_Node* parent, char const* name, f64 value );

/**
	* @brief Append a new node to a container as a signed integer
	*
	* @param parent
	* @param name
	* @param value
	* @return*
	*/
ADT_Node* adt_append_int( ADT_Node* parent, char const* name, s64 value );

/* parser helpers */

/**
	* @brief Parses a text and stores the result into an unitialised node.
	*
	* @param node
	* @param base
	* @return*
	*/
char* adt_parse_number( ADT_Node* node, char* base );

/**
	* @brief Parses a text and stores the result into an unitialised node.
	* This function expects the entire input to be a number.
	*
	* @param node
	* @param base
	* @return*
	*/
char* adt_parse_number_strict( ADT_Node* node, char* base_str );

/**
	* @brief Parses and converts an existing string node into a number.
	*
	* @param node
	* @return
	*/
ADT_Error adt_c_str_to_number( ADT_Node* node );

/**
	* @brief Parses and converts an existing string node into a number.
	* This function expects the entire input to be a number.
	*
	* @param node
	* @return
	*/
ADT_Error adt_c_str_to_number_strict( ADT_Node* node );

/**
	* @brief Prints a number into a file stream.
	*
	* The provided file handle can also be a memory mapped stream.
	*
	* @see zpl_file_stream_new
	* @param file
	* @param node
	* @return
	*/
ADT_Error adt_print_number( FileInfo* file, ADT_Node* node );

/**
	* @brief Prints a string into a file stream.
	*
	* The provided file handle can also be a memory mapped stream.
	*
	* @see zpl_file_stream_new
	* @param file
	* @param node
	* @param escaped_chars
	* @param escape_symbol
	* @return
	*/
ADT_Error adt_print_string( FileInfo* file, ADT_Node* node, char const* escaped_chars, char const* escape_symbol );

#pragma endregion ADT

#pragma region CSV

enum CSV_Error : u32
{
	ECSV_Error__NONE,
	ECSV_Error__INTERNAL,
	ECSV_Error__UNEXPECTED_END_OF_INPUT,
	ECSV_Error__MISMATCHED_ROWS,
};

typedef ADT_Node CSV_Object;

u8   csv_parse( CSV_Object* root, char* text, AllocatorInfo allocator, b32 has_header );
u8   csv_parse_delimiter( CSV_Object* root, char* text, AllocatorInfo allocator, b32 has_header, char delim );
void csv_free( CSV_Object* obj );

void   csv_write( FileInfo* file, CSV_Object* obj );
StrBuilder csv_write_string( AllocatorInfo a, CSV_Object* obj );
void   csv_write_delimiter( FileInfo* file, CSV_Object* obj, char delim );
StrBuilder csv_write_strbuilder_delimiter( AllocatorInfo a, CSV_Object* obj, char delim );

/* inline */

inline
u8 csv_parse( CSV_Object* root, char* text, AllocatorInfo allocator, b32 has_header )
{
	return csv_parse_delimiter( root, text, allocator, has_header, ',' );
}

inline
void csv_write( FileInfo* file, CSV_Object* obj )
{
	csv_write_delimiter( file, obj, ',' );
}

inline
StrBuilder csv_write_string( AllocatorInfo a, CSV_Object* obj )
{
	return csv_write_strbuilder_delimiter( a, obj, ',' );
}

#pragma endregion CSV

GEN_NS_END

#ifdef __clang__
#	pragma clang diagnostic pop
#endif

#ifdef __GNUC__
#	pragma GCC diagnostic pop
#endif
