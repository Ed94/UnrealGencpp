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

#include "gen.builder.hpp"

GEN_NS_BEGIN

#pragma region Builder

Builder builder_open( char const* path )
{
	Builder result;

	FileError error = file_open_mode( & result.File, EFileMode_WRITE, path );
	if ( error != EFileError_NONE )
	{
		log_failure( "gen::File::open - Could not open file: %s", path);
		return result;
	}

	Context* ctx = get_context();
	GEN_ASSERT_NOT_NULL(ctx);
	result.Buffer = strbuilder_make_reserve( ctx->Allocator_Temp, ctx->InitSize_BuilderBuffer );

	// log_fmt("$Builder - Opened file: %s\n", result.File.filename );
	return result;
}

void builder_pad_lines( Builder* builder, s32 num )
{
	strbuilder_append_str( & builder->Buffer, txt("\n") );
}

void builder_print( Builder* builder, Code code )
{
	StrBuilder   str = code_to_strbuilder(code);
	// const ssize len = str.length();
	// log_fmt( "%s - print: %.*s\n", File.filename, len > 80 ? 80 : len, str.Data );
	strbuilder_append_string( & builder->Buffer, str );
}

void builder_print_fmt_va( Builder* builder, char const* fmt, va_list va )
{
	ssize   res;
	char buf[ GEN_PRINTF_MAXLEN ] = { 0 };

	res = c_str_fmt_va( buf, count_of( buf ) - 1, fmt, va ) - 1;

	strbuilder_append_c_str_len( (StrBuilder*) & (builder->Buffer), (char const*)buf, res);
}

void builder_write(Builder* builder)
{
	b32 result = file_write( & builder->File, builder->Buffer, strbuilder_length(builder->Buffer) );

	if ( result == false )
		log_failure("gen::File::write - Failed to write to file: %s\n", file_name( & builder->File ) );

	log_fmt( "Generated: %s\n", builder->File.filename );
	file_close( & builder->File );
	strbuilder_free(& builder->Buffer);
}

#pragma endregion Builder

GEN_NS_END

#ifdef __clang__
#	pragma clang diagnostic pop
#endif

#ifdef __GNUC__
#	pragma GCC diagnostic pop
#endif
