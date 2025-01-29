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

#include "gen.hpp"

GEN_NS_BEGIN

#pragma region Scanner

// This is a simple file reader that reads the entire file into memory.
// It has an extra option to skip the first few lines for undesired includes.
// This is done so that includes can be kept in dependency and component files so that intellisense works.
GEN_API Code scan_file( char const* path );

GEN_API CodeBody parse_file( const char* path );

// The follow is basic support for light csv parsing (use it as an example)
// Make something robust if its more serious.

typedef struct CSV_Column CSV_Column;
struct CSV_Column {
	CSV_Object      ADT;
	Array(ADT_Node) Content;
};

typedef struct CSV_Columns2 CSV_Columns2;
struct CSV_Columns2 {
	CSV_Object      ADT;
	Array(ADT_Node) Col_1;
	Array(ADT_Node) Col_2;
};

GEN_API CSV_Column parse_csv_one_column(AllocatorInfo allocator, char const* path);
GEN_API CSV_Columns2 parse_csv_two_columns(AllocatorInfo allocator, char const* path);

#pragma endregion Scanner

GEN_NS_END

#ifdef __clang__
#	pragma clang diagnostic pop
#endif

#ifdef __GNUC__
#	pragma GCC diagnostic pop
#endif
