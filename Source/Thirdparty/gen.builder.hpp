// This file was generated automatially by gencpp's unreal.cpp (See: https://github.com/Ed94/gencpp)

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

#pragma once

#include "gen.hpp"

GEN_NS_BEGIN

#pragma region Builder

struct Builder;
typedef struct Builder Builder;

Builder builder_open        ( char const* path );
void    builder_pad_lines   ( Builder* builder, s32 num );
void    builder_print       ( Builder* builder, Code code );
void    builder_print_fmt_va( Builder* builder, char const* fmt, va_list va );
void    builder_write       ( Builder* builder );

FORCEINLINE void builder_print_fmt   ( Builder* builder, char const* fmt, ... ) {
	va_list va;
	va_start( va, fmt );
	builder_print_fmt_va( builder, fmt, va );
	va_end( va );
}

struct Builder
{
	FileInfo File;
	StrBuilder   Buffer;

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
	FORCEINLINE static Builder open( char const* path ) { return builder_open(path); }

	FORCEINLINE void pad_lines( s32 num ) { return builder_pad_lines(this, num); }

	FORCEINLINE void print( Code code )                { return builder_print(this, code); }
	FORCEINLINE void print_fmt( char const* fmt, ... ) {
		va_list va;
		va_start( va, fmt );
		builder_print_fmt_va( this, fmt, va );
		va_end( va );
	}

	FORCEINLINE void write() { return builder_write(this); }
#endif
};

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
FORCEINLINE void    builder_pad_lines( Builder& builder, s32 num )    { return builder_pad_lines(& builder, num); }
FORCEINLINE void    builder_print    ( Builder& builder, Code code )  { return builder_print(& builder, code); }
FORCEINLINE void    builder_write    ( Builder& builder )             { return builder_write(& builder ); }
FORCEINLINE void    builder_print_fmt( Builder& builder, char const* fmt, ...) {
	va_list va;
	va_start( va, fmt );
	builder_print_fmt_va( & builder, fmt, va );
	va_end( va );
}
#endif

#pragma endregion Builder

GEN_NS_END

#ifdef __clang__
#	pragma clang diagnostic pop
#endif

#ifdef __GNUC__
#	pragma GCC diagnostic pop
#endif
