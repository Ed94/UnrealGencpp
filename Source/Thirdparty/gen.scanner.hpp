// This file was generated automatially by gencpp's unreal.cpp (See: https://github.com/Ed94/gencpp)

#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-const-variable"
#pragma clang diagnostic ignored "-Wunused-but-set-variable"
#pragma clang diagnostic ignored "-Wswitch"
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wvarargs"
#pragma clang diagnostic ignored "-Wunused-function"
#endif

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wcomment"
#pragma GCC diagnostic ignored "-Wswitch"
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#include "gen.hpp"

GEN_NS_BEGIN

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
	u8       props : 4;
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
		Array<ADT_Node> nodes;    ///< zpl_array

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
ADT_Node* adt_alloc_at( ADT_Node* parent, sw index );

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
ADT_Node* adt_move_node_at( ADT_Node* node, ADT_Node* new_parent, sw index );

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
ADT_Error adt_str_to_number( ADT_Node* node );

/**
 * @brief Parses and converts an existing string node into a number.
 * This function expects the entire input to be a number.
 *
 * @param node
 * @return
 */
ADT_Error adt_str_to_number_strict( ADT_Node* node );

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

GEN_DEF_INLINE u8 csv_parse( CSV_Object* root, char* text, AllocatorInfo allocator, b32 has_header );
u8                csv_parse_delimiter( CSV_Object* root, char* text, AllocatorInfo allocator, b32 has_header, char delim );
void              csv_free( CSV_Object* obj );

GEN_DEF_INLINE void   csv_write( FileInfo* file, CSV_Object* obj );
GEN_DEF_INLINE String csv_write_string( AllocatorInfo a, CSV_Object* obj );
void                  csv_write_delimiter( FileInfo* file, CSV_Object* obj, char delim );
String                csv_write_string_delimiter( AllocatorInfo a, CSV_Object* obj, char delim );

/* inline */

GEN_IMPL_INLINE u8 csv_parse( CSV_Object* root, char* text, AllocatorInfo allocator, b32 has_header )
{
	return csv_parse_delimiter( root, text, allocator, has_header, ',' );
}

GEN_IMPL_INLINE void csv_write( FileInfo* file, CSV_Object* obj )
{
	csv_write_delimiter( file, obj, ',' );
}

GEN_IMPL_INLINE String csv_write_string( AllocatorInfo a, CSV_Object* obj )
{
	return csv_write_string_delimiter( a, obj, ',' );
}

#pragma endregion CSV

// This is a simple file reader that reads the entire file into memory.
// It has an extra option to skip the first few lines for undesired includes.
// This is done so that includes can be kept in dependency and component files so that intellisense works.
inline Code scan_file( char const* path )
{
	FileInfo file;

	FileError error = file_open_mode( &file, EFileMode_READ, path );
	if ( error != EFileError_NONE )
	{
		GEN_FATAL( "scan_file: Could not open: %s", path );
	}

	sw fsize = file_size( &file );
	if ( fsize <= 0 )
	{
		GEN_FATAL( "scan_file: %s is empty", path );
	}

	String str = String::make_reserve( GlobalAllocator, fsize );
	file_read( &file, str, fsize );
	str.get_header().Length = fsize;

	// Skip GEN_INTELLISENSE_DIRECTIVES preprocessor blocks
	// Its designed so that the directive should be the first thing in the file.
	// Anything that comes before it will also be omitted.
	{
#define current ( *scanner )
#define matched 0
#define move_fwd() \
	do             \
	{              \
		++scanner; \
		--left;    \
	} while ( 0 )
		const StrC directive_start  = txt( "ifdef" );
		const StrC directive_end    = txt( "endif" );
		const StrC def_intellisense = txt( "GEN_INTELLISENSE_DIRECTIVES" );

		bool        found_directive = false;
		char const* scanner         = str.Data;
		s32         left            = fsize;
		while ( left )
		{
			// Processing directive.
			if ( current == '#' )
			{
				move_fwd();
				while ( left && char_is_space( current ) )
					move_fwd();

				if ( ! found_directive )
				{
					if ( left && str_compare( scanner, directive_start.Ptr, directive_start.Len ) == matched )
					{
						scanner += directive_start.Len;
						left    -= directive_start.Len;

						while ( left && char_is_space( current ) )
							move_fwd();

						if ( left && str_compare( scanner, def_intellisense.Ptr, def_intellisense.Len ) == matched )
						{
							scanner         += def_intellisense.Len;
							left            -= def_intellisense.Len;

							found_directive  = true;
						}
					}

					// Skip to end of line
					while ( left && current != '\r' && current != '\n' )
						move_fwd();
					move_fwd();

					if ( left && current == '\n' )
						move_fwd();

					continue;
				}

				if ( left && str_compare( scanner, directive_end.Ptr, directive_end.Len ) == matched )
				{
					scanner += directive_end.Len;
					left    -= directive_end.Len;

					// Skip to end of line
					while ( left && current != '\r' && current != '\n' )
						move_fwd();
					move_fwd();

					if ( left && current == '\n' )
						move_fwd();

					// sptr skip_size = fsize - left;
					if ( ( scanner + 2 ) >= ( str.Data + fsize ) )
					{
						mem_move( str, scanner, left );
						str.get_header().Length = left;
						break;
					}

					mem_move( str, scanner, left );
					str.get_header().Length = left;

					break;
				}
			}

			move_fwd();
		}
#undef move_fwd
#undef matched
#undef current
	}

	file_close( &file );
	return untyped_str( str );
}

#if 0
struct CodeFile
{
	using namespace Parser;

	String              FilePath;
	TokArray            Tokens;
	Array<ParseFailure> ParseFailures;
	Code                CodeRoot;
};

namespace Parser
{
	struct ParseFailure
	{
		String Reason;
		Code   Node;
	};
}

CodeFile scan_file( char const* path )
{
	using namespace Parser;

	CodeFile
	result = {};
	result.FilePath = String::make( GlobalAllocator, path );

	Code code = scan_file( path );
	result.CodeRoot = code;

	ParseContext context = parser_get_last_context();
	result.Tokens        = context.Tokens;
	result.ParseFailures = context.Failures;

	return result;
}
#endif
GEN_NS_END

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
