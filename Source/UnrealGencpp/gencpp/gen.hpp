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

/*
	gencpp: An attempt at "simple" staged metaprogramming for c/c++.

	See Readme.md for more information from the project repository.

	Public Address:
	https://github.com/Ed94/gencpp

	This is a variant intended for use with Unreal Engine 5
	https://github.com/Ed94/gencpp  --------------------------------------------------------------.
	|   _____                               _____ _                       _                        |
	|  / ____)                             / ____} |                     | |                       |
	| | / ___  ___ _ __   ___ _ __  _ __  | {___ | |__ _ _, __ _, ___  __| |                       |
	| | |{_  |/ _ \ '_ \ / __} '_ l| '_ l `\___ \| __/ _` |/ _` |/ _ \/ _` |                       |
	| | l__j | ___/ | | | {__; |+l } |+l | ____) | l| (_| | {_| | ___/ (_| |                       |
	|  \_____|\___}_l |_|\___} ,__/| ,__/ (_____/ \__\__/_|\__, |\___}\__,_l                       |
	|  Unreal Engine         | |   | |                      __} |                                  |
	|                        l_l   l_l                     {___/                                   |
	! ----------------------------------------------------------------------- VERSION: v0.23-Alpha |
	! ============================================================================================ |
	! WARNING: THIS IS AN ALPHA VERSION OF THE LIBRARY, USE AT YOUR OWN DISCRETION                 |
	! NEVER DO CODE GENERATION WITHOUT AT LEAST HAVING CONTENT IN A CODEBASE UNDER VERSION CONTROL |
	! ============================================================================================ /
*/
#if ! defined(GEN_DONT_ENFORCE_GEN_TIME_GUARD) && ! defined(GEN_TIME)
#	error Gen.hpp : GEN_TIME not defined
#endif

//! If its desired to roll your own dependencies, define GEN_ROLL_OWN_DEPENDENCIES before including this file.
// Dependencies are derived from the c-zpl library: https://github.com/zpl-c/zpl
#ifndef GEN_ROLL_OWN_DEPENDENCIES
#	include "gen.dep.hpp"
#endif

#ifndef GEN_NS_BEGIN
#	ifdef GEN_DONT_USE_NAMESPACE
#		define GEN_NS
#		define GEN_NS_BEGIN
#		define GEN_NS_END
#	else
#		define GEN_NS       gen::
#		define GEN_NS_BEGIN namespace gen {
#		define GEN_NS_END   }
#	endif
#endif

GEN_NS_BEGIN

#pragma region Types

/*
 ________                                              __    __      ________
|        \                                            |  \  |  \    |        \
| ▓▓▓▓▓▓▓▓_______  __    __ ______ ____   _______     | ▓▓\ | ▓▓     \▓▓▓▓▓▓▓▓__    __  ______   ______   _______
| ▓▓__   |       \|  \  |  \      \    \ /       \    | ▓▓▓\| ▓▓       | ▓▓  |  \  |  \/      \ /      \ /       \
| ▓▓  \  | ▓▓▓▓▓▓▓\ ▓▓  | ▓▓ ▓▓▓▓▓▓\▓▓▓▓\  ▓▓▓▓▓▓▓    | ▓▓▓▓\ ▓▓       | ▓▓  | ▓▓  | ▓▓  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\  ▓▓▓▓▓▓▓
| ▓▓▓▓▓  | ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓ | ▓▓ | ▓▓\▓▓    \     | ▓▓\▓▓ ▓▓       | ▓▓  | ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓    ▓▓\▓▓    \
| ▓▓_____| ▓▓  | ▓▓ ▓▓__/ ▓▓ ▓▓ | ▓▓ | ▓▓_\▓▓▓▓▓▓\    | ▓▓ \▓▓▓▓       | ▓▓  | ▓▓__/ ▓▓ ▓▓__/ ▓▓ ▓▓▓▓▓▓▓▓_\▓▓▓▓▓▓\
| ▓▓     \ ▓▓  | ▓▓\▓▓    ▓▓ ▓▓ | ▓▓ | ▓▓       ▓▓    | ▓▓  \▓▓▓       | ▓▓   \▓▓    ▓▓ ▓▓    ▓▓\▓▓     \       ▓▓
 \▓▓▓▓▓▓▓▓\▓▓   \▓▓ \▓▓▓▓▓▓ \▓▓  \▓▓  \▓▓\▓▓▓▓▓▓▓      \▓▓   \▓▓        \▓▓   _\▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓  \▓▓▓▓▓▓▓\▓▓▓▓▓▓▓
                                                                             |  \__| ▓▓ ▓▓
                                                                              \▓▓    ▓▓ ▓▓
                                                                               \▓▓▓▓▓▓ \▓▓

*/

using LogFailType = ssize(*)(char const*, ...);

// By default this library will either crash or exit if an error is detected while generating codes.
// Even if set to not use GEN_FATAL, GEN_FATAL will still be used for memory failures as the library is unusable when they occur.
#ifdef GEN_DONT_USE_FATAL
	#define log_failure log_fmt
#else
	#define log_failure GEN_FATAL
#endif

enum AccessSpec : u32
{
	AccessSpec_Default,
	AccessSpec_Private,
	AccessSpec_Protected,
	AccessSpec_Public,

	AccessSpec_Num_AccessSpec,
	AccessSpec_Invalid,

	AccessSpec_SizeDef = GEN_U32_MAX,
};
static_assert( size_of(AccessSpec) == size_of(u32), "AccessSpec not u32 size" );

inline
Str access_spec_to_str( AccessSpec type )
{
	local_persist
	Str lookup[ (u32)AccessSpec_Num_AccessSpec ] = {
		{ "",        sizeof( "" )        - 1 },
		{ "private", sizeof("prviate")   - 1 },
		{ "private", sizeof("protected") - 1 },
		{ "public",  sizeof("public")    - 1 },
	};

	Str invalid = { "Invalid", sizeof("Invalid") - 1 };
	if ( type > AccessSpec_Public )
		return invalid;

	return lookup[ (u32)type ];
}

enum CodeFlag : u32
{
	CodeFlag_None          = 0,
	CodeFlag_FunctionType  = bit(0),
	CodeFlag_ParamPack     = bit(1),
	CodeFlag_Module_Export = bit(2),
	CodeFlag_Module_Import = bit(3),

	CodeFlag_SizeDef = GEN_U32_MAX,
};
static_assert( size_of(CodeFlag) == size_of(u32), "CodeFlag not u32 size" );

// Used to indicate if enum definitoin is an enum class or regular enum.
enum EnumDecl : u8
{
	EnumDecl_Regular,
	EnumDecl_Class,

	EnumT_SizeDef = GEN_U8_MAX,
};
typedef u8 EnumT;

enum ModuleFlag : u32
{
	ModuleFlag_None    = 0,
	ModuleFlag_Export  = bit(0),
	ModuleFlag_Import  = bit(1),

	Num_ModuleFlags,
	ModuleFlag_Invalid,

	ModuleFlag_SizeDef = GEN_U32_MAX,
};
static_assert( size_of(ModuleFlag) == size_of(u32), "ModuleFlag not u32 size" );

inline
Str module_flag_to_str( ModuleFlag flag )
{
	local_persist
	Str lookup[ (u32)Num_ModuleFlags ] = {
		{ "__none__", sizeof("__none__") - 1 },
		{ "export",   sizeof("export")   - 1 },
		{ "import",   sizeof("import")   - 1 },
	};

	local_persist
	Str invalid_flag = { "invalid", sizeof("invalid") };
	if ( flag > ModuleFlag_Import )
		return invalid_flag;

	return lookup[ (u32)flag ];
}

enum EPreprocessCond : u32
{
	PreprocessCond_If,
	PreprocessCond_IfDef,
	PreprocessCond_IfNotDef,
	PreprocessCond_ElIf,

	EPreprocessCond_SizeDef = GEN_U32_MAX,
};
static_assert( size_of(EPreprocessCond) == size_of(u32), "EPreprocessCond not u32 size" );

enum ETypenameTag : u16
{
	Tag_None,
	Tag_Class,
	Tag_Enum,
	Tag_Struct,
	Tag_Union,

	Tag_UnderlyingType = GEN_U16_MAX,
};
static_assert( size_of(ETypenameTag) == size_of(u16), "ETypenameTag is not u16 size");

enum CodeType : u32
{
	CT_Invalid,
	CT_Untyped,
	CT_NewLine,
	CT_Comment,
	CT_Access_Private,
	CT_Access_Protected,
	CT_Access_Public,
	CT_PlatformAttributes,
	CT_Class,
	CT_Class_Fwd,
	CT_Class_Body,
	CT_Constructor,
	CT_Constructor_Fwd,
	CT_Destructor,
	CT_Destructor_Fwd,
	CT_Enum,
	CT_Enum_Fwd,
	CT_Enum_Body,
	CT_Enum_Class,
	CT_Enum_Class_Fwd,
	CT_Execution,
	CT_Export_Body,
	CT_Extern_Linkage,
	CT_Extern_Linkage_Body,
	CT_Friend,
	CT_Function,
	CT_Function_Fwd,
	CT_Function_Body,
	CT_Global_Body,
	CT_Module,
	CT_Namespace,
	CT_Namespace_Body,
	CT_Operator,
	CT_Operator_Fwd,
	CT_Operator_Member,
	CT_Operator_Member_Fwd,
	CT_Operator_Cast,
	CT_Operator_Cast_Fwd,
	CT_Parameters,
	CT_Parameters_Define,
	CT_Preprocess_Define,
	CT_Preprocess_Include,
	CT_Preprocess_If,
	CT_Preprocess_IfDef,
	CT_Preprocess_IfNotDef,
	CT_Preprocess_ElIf,
	CT_Preprocess_Else,
	CT_Preprocess_EndIf,
	CT_Preprocess_Pragma,
	CT_Specifiers,
	CT_Struct,
	CT_Struct_Fwd,
	CT_Struct_Body,
	CT_Template,
	CT_Typedef,
	CT_Typename,
	CT_Union,
	CT_Union_Fwd,
	CT_Union_Body,
	CT_Using,
	CT_Using_Namespace,
	CT_Variable,
	CT_NumTypes,
	CT_UnderlyingType = GEN_U32_MAX
};

inline Str codetype_to_str(CodeType type)
{
	local_persist Str lookup[] = {
		{ "Invalid",             sizeof("Invalid") - 1             },
		{ "Untyped",             sizeof("Untyped") - 1             },
		{ "NewLine",             sizeof("NewLine") - 1             },
		{ "Comment",             sizeof("Comment") - 1             },
		{ "Access_Private",      sizeof("Access_Private") - 1      },
		{ "Access_Protected",    sizeof("Access_Protected") - 1    },
		{ "Access_Public",       sizeof("Access_Public") - 1       },
		{ "PlatformAttributes",  sizeof("PlatformAttributes") - 1  },
		{ "Class",               sizeof("Class") - 1               },
		{ "Class_Fwd",           sizeof("Class_Fwd") - 1           },
		{ "Class_Body",          sizeof("Class_Body") - 1          },
		{ "Constructor",         sizeof("Constructor") - 1         },
		{ "Constructor_Fwd",     sizeof("Constructor_Fwd") - 1     },
		{ "Destructor",          sizeof("Destructor") - 1          },
		{ "Destructor_Fwd",      sizeof("Destructor_Fwd") - 1      },
		{ "Enum",                sizeof("Enum") - 1                },
		{ "Enum_Fwd",            sizeof("Enum_Fwd") - 1            },
		{ "Enum_Body",           sizeof("Enum_Body") - 1           },
		{ "Enum_Class",          sizeof("Enum_Class") - 1          },
		{ "Enum_Class_Fwd",      sizeof("Enum_Class_Fwd") - 1      },
		{ "Execution",           sizeof("Execution") - 1           },
		{ "Export_Body",         sizeof("Export_Body") - 1         },
		{ "Extern_Linkage",      sizeof("Extern_Linkage") - 1      },
		{ "Extern_Linkage_Body", sizeof("Extern_Linkage_Body") - 1 },
		{ "Friend",              sizeof("Friend") - 1              },
		{ "Function",            sizeof("Function") - 1            },
		{ "Function_Fwd",        sizeof("Function_Fwd") - 1        },
		{ "Function_Body",       sizeof("Function_Body") - 1       },
		{ "Global_Body",         sizeof("Global_Body") - 1         },
		{ "Module",              sizeof("Module") - 1              },
		{ "Namespace",           sizeof("Namespace") - 1           },
		{ "Namespace_Body",      sizeof("Namespace_Body") - 1      },
		{ "Operator",            sizeof("Operator") - 1            },
		{ "Operator_Fwd",        sizeof("Operator_Fwd") - 1        },
		{ "Operator_Member",     sizeof("Operator_Member") - 1     },
		{ "Operator_Member_Fwd", sizeof("Operator_Member_Fwd") - 1 },
		{ "Operator_Cast",       sizeof("Operator_Cast") - 1       },
		{ "Operator_Cast_Fwd",   sizeof("Operator_Cast_Fwd") - 1   },
		{ "Parameters",          sizeof("Parameters") - 1          },
		{ "Parameters_Define",   sizeof("Parameters_Define") - 1   },
		{ "Preprocess_Define",   sizeof("Preprocess_Define") - 1   },
		{ "Preprocess_Include",  sizeof("Preprocess_Include") - 1  },
		{ "Preprocess_If",       sizeof("Preprocess_If") - 1       },
		{ "Preprocess_IfDef",    sizeof("Preprocess_IfDef") - 1    },
		{ "Preprocess_IfNotDef", sizeof("Preprocess_IfNotDef") - 1 },
		{ "Preprocess_ElIf",     sizeof("Preprocess_ElIf") - 1     },
		{ "Preprocess_Else",     sizeof("Preprocess_Else") - 1     },
		{ "Preprocess_EndIf",    sizeof("Preprocess_EndIf") - 1    },
		{ "Preprocess_Pragma",   sizeof("Preprocess_Pragma") - 1   },
		{ "Specifiers",          sizeof("Specifiers") - 1          },
		{ "Struct",              sizeof("Struct") - 1              },
		{ "Struct_Fwd",          sizeof("Struct_Fwd") - 1          },
		{ "Struct_Body",         sizeof("Struct_Body") - 1         },
		{ "Template",            sizeof("Template") - 1            },
		{ "Typedef",             sizeof("Typedef") - 1             },
		{ "Typename",            sizeof("Typename") - 1            },
		{ "Union",               sizeof("Union") - 1               },
		{ "Union_Fwd",           sizeof("Union_Fwd") - 1           },
		{ "Union_Body",          sizeof("Union_Body") - 1          },
		{ "Using",               sizeof("Using") - 1               },
		{ "Using_Namespace",     sizeof("Using_Namespace") - 1     },
		{ "Variable",            sizeof("Variable") - 1            },
	};
	return lookup[type];
}

inline Str codetype_to_keyword_str(CodeType type)
{
	local_persist Str lookup[] = {
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "//",              sizeof("//") - 1              },
		{ "private",         sizeof("private") - 1         },
		{ "protected",       sizeof("protected") - 1       },
		{ "public",          sizeof("public") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "class",           sizeof("class") - 1           },
		{ "clsss",           sizeof("clsss") - 1           },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "enum",            sizeof("enum") - 1            },
		{ "enum",            sizeof("enum") - 1            },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "enum class",      sizeof("enum class") - 1      },
		{ "enum class",      sizeof("enum class") - 1      },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "extern",          sizeof("extern") - 1          },
		{ "extern",          sizeof("extern") - 1          },
		{ "friend",          sizeof("friend") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "module",          sizeof("module") - 1          },
		{ "namespace",       sizeof("namespace") - 1       },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "operator",        sizeof("operator") - 1        },
		{ "operator",        sizeof("operator") - 1        },
		{ "operator",        sizeof("operator") - 1        },
		{ "operator",        sizeof("operator") - 1        },
		{ "operator",        sizeof("operator") - 1        },
		{ "operator",        sizeof("operator") - 1        },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "define",          sizeof("define") - 1          },
		{ "include",         sizeof("include") - 1         },
		{ "if",              sizeof("if") - 1              },
		{ "ifdef",           sizeof("ifdef") - 1           },
		{ "ifndef",          sizeof("ifndef") - 1          },
		{ "elif",            sizeof("elif") - 1            },
		{ "else",            sizeof("else") - 1            },
		{ "endif",           sizeof("endif") - 1           },
		{ "pragma",          sizeof("pragma") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "struct",          sizeof("struct") - 1          },
		{ "struct",          sizeof("struct") - 1          },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "template",        sizeof("template") - 1        },
		{ "typedef",         sizeof("typedef") - 1         },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "union",           sizeof("union") - 1           },
		{ "union",           sizeof("union") - 1           },
		{ "__NA__",          sizeof("__NA__") - 1          },
		{ "using",           sizeof("using") - 1           },
		{ "using namespace", sizeof("using namespace") - 1 },
		{ "__NA__",          sizeof("__NA__") - 1          },
	};
	return lookup[type];
}

FORCEINLINE Str to_str(CodeType type)
{
	return codetype_to_str(type);
}

FORCEINLINE Str to_keyword_str(CodeType type)
{
	return codetype_to_keyword_str(type);
}

enum Operator : u32
{
	Op_Invalid,
	Op_Assign,
	Op_Assign_Add,
	Op_Assign_Subtract,
	Op_Assign_Multiply,
	Op_Assign_Divide,
	Op_Assign_Modulo,
	Op_Assign_BAnd,
	Op_Assign_BOr,
	Op_Assign_BXOr,
	Op_Assign_LShift,
	Op_Assign_RShift,
	Op_Increment,
	Op_Decrement,
	Op_Unary_Plus,
	Op_Unary_Minus,
	Op_UnaryNot,
	Op_Add,
	Op_Subtract,
	Op_Multiply,
	Op_Divide,
	Op_Modulo,
	Op_BNot,
	Op_BAnd,
	Op_BOr,
	Op_BXOr,
	Op_LShift,
	Op_RShift,
	Op_LAnd,
	Op_LOr,
	Op_LEqual,
	Op_LNot,
	Op_Lesser,
	Op_Greater,
	Op_LesserEqual,
	Op_GreaterEqual,
	Op_Subscript,
	Op_Indirection,
	Op_AddressOf,
	Op_MemberOfPointer,
	Op_PtrToMemOfPtr,
	Op_FunctionCall,
	Op_Comma,
	Op_New,
	Op_NewArray,
	Op_Delete,
	Op_DeleteArray,
	Op_NumOps,
	Op_UnderlyingType = 0xffffffffu
};

inline Str operator_to_str(Operator op)
{
	local_persist Str lookup[] = {
		{ "INVALID",  sizeof("INVALID") - 1  },
		{ "=",        sizeof("=") - 1        },
		{ "+=",       sizeof("+=") - 1       },
		{ "-=",       sizeof("-=") - 1       },
		{ "*=",       sizeof("*=") - 1       },
		{ "/=",       sizeof("/=") - 1       },
		{ "%=",       sizeof("%=") - 1       },
		{ "&=",       sizeof("&=") - 1       },
		{ "|=",       sizeof("|=") - 1       },
		{ "^=",       sizeof("^=") - 1       },
		{ "<<=",      sizeof("<<=") - 1      },
		{ ">>=",      sizeof(">>=") - 1      },
		{ "++",       sizeof("++") - 1       },
		{ "--",       sizeof("--") - 1       },
		{ "+",        sizeof("+") - 1        },
		{ "-",        sizeof("-") - 1        },
		{ "!",        sizeof("!") - 1        },
		{ "+",        sizeof("+") - 1        },
		{ "-",        sizeof("-") - 1        },
		{ "*",        sizeof("*") - 1        },
		{ "/",        sizeof("/") - 1        },
		{ "%",        sizeof("%") - 1        },
		{ "~",        sizeof("~") - 1        },
		{ "&",        sizeof("&") - 1        },
		{ "|",        sizeof("|") - 1        },
		{ "^",        sizeof("^") - 1        },
		{ "<<",       sizeof("<<") - 1       },
		{ ">>",       sizeof(">>") - 1       },
		{ "&&",       sizeof("&&") - 1       },
		{ "||",       sizeof("||") - 1       },
		{ "==",       sizeof("==") - 1       },
		{ "!=",       sizeof("!=") - 1       },
		{ "<",        sizeof("<") - 1        },
		{ ">",        sizeof(">") - 1        },
		{ "<=",       sizeof("<=") - 1       },
		{ ">=",       sizeof(">=") - 1       },
		{ "[]",       sizeof("[]") - 1       },
		{ "*",        sizeof("*") - 1        },
		{ "&",        sizeof("&") - 1        },
		{ "->",       sizeof("->") - 1       },
		{ "->*",      sizeof("->*") - 1      },
		{ "()",       sizeof("()") - 1       },
		{ ",",        sizeof(",") - 1        },
		{ "new",      sizeof("new") - 1      },
		{ "new[]",    sizeof("new[]") - 1    },
		{ "delete",   sizeof("delete") - 1   },
		{ "delete[]", sizeof("delete[]") - 1 },
	};
	return lookup[op];
}

FORCEINLINE Str to_str(Operator op)
{
	return operator_to_str(op);
}

enum Specifier : u32
{
	Spec_Invalid,
	Spec_Consteval,
	Spec_Constexpr,
	Spec_Constinit,
	Spec_Explicit,
	Spec_External_Linkage,
	Spec_ForceInline,
	Spec_ForceInline_Debuggable,
	Spec_Global,
	Spec_Inline,
	Spec_Internal_Linkage,
	Spec_Local_Persist,
	Spec_Mutable,
	Spec_NeverInline,
	Spec_Ptr,
	Spec_Ref,
	Spec_Register,
	Spec_RValue,
	Spec_Static,
	Spec_Thread_Local,
	Spec_Virtual,
	Spec_Const,
	Spec_Final,
	Spec_NoExceptions,
	Spec_Override,
	Spec_Pure,
	Spec_Delete,
	Spec_Volatile,
	Spec_NumSpecifiers,
	Spec_UnderlyingType = 0xffffffffu
};

inline Str spec_to_str(Specifier type)
{
	local_persist Str lookup[] = {
		{ "INVALID",                sizeof("INVALID") - 1                },
		{ "consteval",              sizeof("consteval") - 1              },
		{ "constexpr",              sizeof("constexpr") - 1              },
		{ "constinit",              sizeof("constinit") - 1              },
		{ "explicit",               sizeof("explicit") - 1               },
		{ "extern",                 sizeof("extern") - 1                 },
		{ "FORCEINLINE",            sizeof("FORCEINLINE") - 1            },
		{ "FORCEINLINE_DEBUGGABLE", sizeof("FORCEINLINE_DEBUGGABLE") - 1 },
		{ "global",                 sizeof("global") - 1                 },
		{ "inline",                 sizeof("inline") - 1                 },
		{ "internal",               sizeof("internal") - 1               },
		{ "local_persist",          sizeof("local_persist") - 1          },
		{ "mutable",                sizeof("mutable") - 1                },
		{ "neverinline",            sizeof("neverinline") - 1            },
		{ "*",		              sizeof("*") - 1                      },
		{ "&",		              sizeof("&") - 1                      },
		{ "register",               sizeof("register") - 1               },
		{ "&&",		             sizeof("&&") - 1                     },
		{ "static",                 sizeof("static") - 1                 },
		{ "thread_local",           sizeof("thread_local") - 1           },
		{ "virtual",                sizeof("virtual") - 1                },
		{ "const",                  sizeof("const") - 1                  },
		{ "final",                  sizeof("final") - 1                  },
		{ "noexcept",               sizeof("noexcept") - 1               },
		{ "override",               sizeof("override") - 1               },
		{ "= 0",		            sizeof("= 0") - 1                    },
		{ "= delete",		            sizeof("= delete") - 1                    },
		{ "volatile",               sizeof("volatile") - 1               },
	};
	return lookup[type];
}

inline bool spec_is_trailing(Specifier specifier)
{
	switch (specifier)
	{
		case Spec_Const:
		case Spec_Final:
		case Spec_NoExceptions:
		case Spec_Override:
		case Spec_Pure:
		case Spec_Delete:
		case Spec_Volatile:
			return true;
		default:
			return false;
	}
}

inline Specifier str_to_specifier(Str str)
{
	local_persist u32 keymap[Spec_NumSpecifiers];
	do_once_start for (u32 index = 0; index < Spec_NumSpecifiers; index++)
	{
		Str enum_str  = spec_to_str((Specifier)index);
		keymap[index] = crc32(enum_str.Ptr, enum_str.Len);
	}
	do_once_end u32 hash = crc32(str.Ptr, str.Len);
	for (u32 index = 0; index < Spec_NumSpecifiers; index++)
	{
		if (keymap[index] == hash)
			return (Specifier)index;
	}
	return Spec_Invalid;
}

FORCEINLINE Str to_str(Specifier spec)
{
	return spec_to_str(spec);
}

FORCEINLINE Specifier to_type(Str str)
{
	return str_to_specifier(str);
}

FORCEINLINE bool is_trailing(Specifier specifier)
{
	return spec_is_trailing(specifier);
}

#define GEN_DEFINE_ATTRIBUTE_TOKENS                                                                                     \
	Entry(Tok_Attribute_API_Export, "GEN_API_Export_Code") Entry(Tok_Attribute_API_Import, "GEN_API_Import_Code")       \
	    Entry(Tok_Attribute_COREUOBJECT_API, "COREUOBJECT_API") Entry(Tok_Attribute_ENGINE_API, "ENGINE_API")           \
	        Entry(Tok_Attribute_GAMEPLAYABILITIES_API, "GAMEPLAYABILITIES_API") Entry(Tok_Attribute_UMG_API, "UMG_API") \
	            Entry(Tok_Attribute_UNREALGENCPP_API, "UNREALGENCPP_API")

enum TokType : u32
{
	Tok_Invalid,
	Tok_Access_Private,
	Tok_Access_Protected,
	Tok_Access_Public,
	Tok_Access_MemberSymbol,
	Tok_Access_StaticSymbol,
	Tok_Ampersand,
	Tok_Ampersand_DBL,
	Tok_Assign_Classifer,
	Tok_Attribute_Open,
	Tok_Attribute_Close,
	Tok_BraceCurly_Open,
	Tok_BraceCurly_Close,
	Tok_BraceSquare_Open,
	Tok_BraceSquare_Close,
	Tok_Paren_Open,
	Tok_Paren_Close,
	Tok_Comment,
	Tok_Comment_End,
	Tok_Comment_Start,
	Tok_Char,
	Tok_Comma,
	Tok_Decl_Class,
	Tok_Decl_GNU_Attribute,
	Tok_Decl_MSVC_Attribute,
	Tok_Decl_Enum,
	Tok_Decl_Extern_Linkage,
	Tok_Decl_Friend,
	Tok_Decl_Module,
	Tok_Decl_Namespace,
	Tok_Decl_Operator,
	Tok_Decl_Struct,
	Tok_Decl_Template,
	Tok_Decl_Typedef,
	Tok_Decl_Using,
	Tok_Decl_Union,
	Tok_Identifier,
	Tok_Module_Import,
	Tok_Module_Export,
	Tok_NewLine,
	Tok_Number,
	Tok_Operator,
	Tok_Preprocess_Hash,
	Tok_Preprocess_Define,
	Tok_Preprocess_Define_Param,
	Tok_Preprocess_If,
	Tok_Preprocess_IfDef,
	Tok_Preprocess_IfNotDef,
	Tok_Preprocess_ElIf,
	Tok_Preprocess_Else,
	Tok_Preprocess_EndIf,
	Tok_Preprocess_Include,
	Tok_Preprocess_Pragma,
	Tok_Preprocess_Content,
	Tok_Preprocess_Macro_Expr,
	Tok_Preprocess_Macro_Stmt,
	Tok_Preprocess_Macro_Typename,
	Tok_Preprocess_Unsupported,
	Tok_Spec_Alignas,
	Tok_Spec_Const,
	Tok_Spec_Consteval,
	Tok_Spec_Constexpr,
	Tok_Spec_Constinit,
	Tok_Spec_Explicit,
	Tok_Spec_Extern,
	Tok_Spec_Final,
	Tok_Spec_ForceInline,
	Tok_Spec_ForceInline_Debuggable,
	Tok_Spec_Global,
	Tok_Spec_Inline,
	Tok_Spec_Internal_Linkage,
	Tok_Spec_LocalPersist,
	Tok_Spec_Mutable,
	Tok_Spec_NeverInline,
	Tok_Spec_Override,
	Tok_Spec_Static,
	Tok_Spec_ThreadLocal,
	Tok_Spec_Volatile,
	Tok_Spec_Virtual,
	Tok_Star,
	Tok_Statement_End,
	Tok_StaticAssert,
	Tok_String,
	Tok_Type_Typename,
	Tok_Type_Unsigned,
	Tok_Type_Signed,
	Tok_Type_Short,
	Tok_Type_Long,
	Tok_Type_bool,
	Tok_Type_char,
	Tok_Type_int,
	Tok_Type_double,
	Tok_Type_MS_int8,
	Tok_Type_MS_int16,
	Tok_Type_MS_int32,
	Tok_Type_MS_int64,
	Tok_Type_MS_W64,
	Tok_Varadic_Argument,
	Tok___Attributes_Start,
	Tok_Attribute_API_Export,
	Tok_Attribute_API_Import,
	Tok_Attribute_COREUOBJECT_API,
	Tok_Attribute_ENGINE_API,
	Tok_Attribute_GAMEPLAYABILITIES_API,
	Tok_Attribute_UMG_API,
	Tok_Attribute_UNREALGENCPP_API,
	Tok_NumTokens
};

inline Str toktype_to_str(TokType type)
{
	local_persist Str lookup[] = {
		{ "__invalid__",            sizeof("__invalid__") - 1            },
		{ "private",                sizeof("private") - 1                },
		{ "protected",              sizeof("protected") - 1              },
		{ "public",                 sizeof("public") - 1                 },
		{ ".",		              sizeof(".") - 1                      },
		{ "::",		             sizeof("::") - 1                     },
		{ "&",		              sizeof("&") - 1                      },
		{ "&&",		             sizeof("&&") - 1                     },
		{ ":",		              sizeof(":") - 1                      },
		{ "[[",		             sizeof("[[") - 1                     },
		{ "]]",		             sizeof("]]") - 1                     },
		{ "{",		              sizeof("{") - 1                      },
		{ "}",		              sizeof("}") - 1                      },
		{ "[",		              sizeof("[") - 1                      },
		{ "]",		              sizeof("]") - 1                      },
		{ "(",		              sizeof("(") - 1                      },
		{ ")",		              sizeof(")") - 1                      },
		{ "__comment__",            sizeof("__comment__") - 1            },
		{ "__comment_end__",        sizeof("__comment_end__") - 1        },
		{ "__comment_start__",      sizeof("__comment_start__") - 1      },
		{ "__character__",          sizeof("__character__") - 1          },
		{ ",",		              sizeof(",") - 1                      },
		{ "class",                  sizeof("class") - 1                  },
		{ "__attribute__",          sizeof("__attribute__") - 1          },
		{ "__declspec",             sizeof("__declspec") - 1             },
		{ "enum",		           sizeof("enum") - 1                   },
		{ "extern",                 sizeof("extern") - 1                 },
		{ "friend",                 sizeof("friend") - 1                 },
		{ "module",                 sizeof("module") - 1                 },
		{ "namespace",              sizeof("namespace") - 1              },
		{ "operator",               sizeof("operator") - 1               },
		{ "struct",                 sizeof("struct") - 1                 },
		{ "template",               sizeof("template") - 1               },
		{ "typedef",                sizeof("typedef") - 1                },
		{ "using",                  sizeof("using") - 1                  },
		{ "union",                  sizeof("union") - 1                  },
		{ "__identifier__",         sizeof("__identifier__") - 1         },
		{ "import",                 sizeof("import") - 1                 },
		{ "export",                 sizeof("export") - 1                 },
		{ "__new_line__",           sizeof("__new_line__") - 1           },
		{ "__number__",             sizeof("__number__") - 1             },
		{ "__operator__",           sizeof("__operator__") - 1           },
		{ "#",		              sizeof("#") - 1                      },
		{ "define",                 sizeof("define") - 1                 },
		{ "__define_param__",       sizeof("__define_param__") - 1       },
		{ "if",		             sizeof("if") - 1                     },
		{ "ifdef",                  sizeof("ifdef") - 1                  },
		{ "ifndef",                 sizeof("ifndef") - 1                 },
		{ "elif",		           sizeof("elif") - 1                   },
		{ "else",		           sizeof("else") - 1                   },
		{ "endif",                  sizeof("endif") - 1                  },
		{ "include",                sizeof("include") - 1                },
		{ "pragma",                 sizeof("pragma") - 1                 },
		{ "__macro_content__",      sizeof("__macro_content__") - 1      },
		{ "__macro_expression__",   sizeof("__macro_expression__") - 1   },
		{ "__macro_statment__",     sizeof("__macro_statment__") - 1     },
		{ "__macro_typename__",     sizeof("__macro_typename__") - 1     },
		{ "__unsupported__",        sizeof("__unsupported__") - 1        },
		{ "alignas",                sizeof("alignas") - 1                },
		{ "const",                  sizeof("const") - 1                  },
		{ "consteval",              sizeof("consteval") - 1              },
		{ "constexpr",              sizeof("constexpr") - 1              },
		{ "constinit",              sizeof("constinit") - 1              },
		{ "explicit",               sizeof("explicit") - 1               },
		{ "extern",                 sizeof("extern") - 1                 },
		{ "final",                  sizeof("final") - 1                  },
		{ "FORCEINLINE",            sizeof("FORCEINLINE") - 1            },
		{ "FORCEINLINE_DEBUGGABLE", sizeof("FORCEINLINE_DEBUGGABLE") - 1 },
		{ "global",                 sizeof("global") - 1                 },
		{ "inline",                 sizeof("inline") - 1                 },
		{ "internal",               sizeof("internal") - 1               },
		{ "local_persist",          sizeof("local_persist") - 1          },
		{ "mutable",                sizeof("mutable") - 1                },
		{ "neverinline",            sizeof("neverinline") - 1            },
		{ "override",               sizeof("override") - 1               },
		{ "static",                 sizeof("static") - 1                 },
		{ "thread_local",           sizeof("thread_local") - 1           },
		{ "volatile",               sizeof("volatile") - 1               },
		{ "virtual",                sizeof("virtual") - 1                },
		{ "*",		              sizeof("*") - 1                      },
		{ ";",		              sizeof(";") - 1                      },
		{ "static_assert",          sizeof("static_assert") - 1          },
		{ "__string__",             sizeof("__string__") - 1             },
		{ "typename",               sizeof("typename") - 1               },
		{ "unsigned",               sizeof("unsigned") - 1               },
		{ "signed",                 sizeof("signed") - 1                 },
		{ "short",                  sizeof("short") - 1                  },
		{ "long",		           sizeof("long") - 1                   },
		{ "bool",		           sizeof("bool") - 1                   },
		{ "char",		           sizeof("char") - 1                   },
		{ "int",		            sizeof("int") - 1                    },
		{ "double",                 sizeof("double") - 1                 },
		{ "__int8",                 sizeof("__int8") - 1                 },
		{ "__int16",                sizeof("__int16") - 1                },
		{ "__int32",                sizeof("__int32") - 1                },
		{ "__int64",                sizeof("__int64") - 1                },
		{ "_W64",		           sizeof("_W64") - 1                   },
		{ "...",		            sizeof("...") - 1                    },
		{ "__attrib_start__",       sizeof("__attrib_start__") - 1       },
		{ "GEN_API_Export_Code",    sizeof("GEN_API_Export_Code") - 1    },
		{ "GEN_API_Import_Code",    sizeof("GEN_API_Import_Code") - 1    },
		{ "COREUOBJECT_API",        sizeof("COREUOBJECT_API") - 1        },
		{ "ENGINE_API",             sizeof("ENGINE_API") - 1             },
		{ "GAMEPLAYABILITIES_API",  sizeof("GAMEPLAYABILITIES_API") - 1  },
		{ "UMG_API",                sizeof("UMG_API") - 1                },
		{ "UNREALGENCPP_API",       sizeof("UNREALGENCPP_API") - 1       },
	};
	return lookup[type];
}

inline TokType str_to_toktype(Str str)
{
	local_persist u32 keymap[Tok_NumTokens];
	do_once_start for (u32 index = 0; index < Tok_NumTokens; index++)
	{
		Str enum_str  = toktype_to_str((TokType)index);
		keymap[index] = crc32(enum_str.Ptr, enum_str.Len);
	}
	do_once_end u32 hash = crc32(str.Ptr, str.Len);
	for (u32 index = 0; index < Tok_NumTokens; index++)
	{
		if (keymap[index] == hash)
			return (TokType)index;
	}
	return Tok_Invalid;
}

enum TokFlags : u32
{
	TF_Operator              = bit(0),
	TF_Assign                = bit(1),
	TF_Preprocess            = bit(2),
	TF_Preprocess_Cond       = bit(3),
	TF_Attribute             = bit(6),
	TF_AccessOperator        = bit(7),
	TF_AccessSpecifier       = bit(8),
	TF_Specifier             = bit(9),
	TF_EndDefinition         = bit(10),    // Either ; or }
	TF_Formatting            = bit(11),
	TF_Literal               = bit(12),
	TF_Macro_Functional      = bit(13),
	TF_Macro_Expects_Body    = bit(14),

	TF_Null = 0,
	TF_UnderlyingType = GEN_U32_MAX,
};

struct Token
{
	Str     Text;
	TokType Type;
	s32     Line;
	s32     Column;
	u32     Flags;
};

constexpr Token NullToken { {}, Tok_Invalid, 0, 0, TF_Null };

FORCEINLINE
AccessSpec tok_to_access_specifier(Token tok) {
	return scast(AccessSpec, tok.Type);
}

FORCEINLINE
bool tok_is_valid( Token tok ) {
	return tok.Text.Ptr && tok.Text.Len && tok.Type != Tok_Invalid;
}

FORCEINLINE
bool tok_is_access_operator(Token tok) {
	return bitfield_is_set( u32, tok.Flags, TF_AccessOperator );
}

FORCEINLINE
bool tok_is_access_specifier(Token tok) {
	return bitfield_is_set( u32, tok.Flags, TF_AccessSpecifier );
}

FORCEINLINE
bool tok_is_attribute(Token tok) {
	return bitfield_is_set( u32, tok.Flags, TF_Attribute );
}

FORCEINLINE
bool tok_is_operator(Token tok) {
	return bitfield_is_set( u32, tok.Flags, TF_Operator );
}

FORCEINLINE
bool tok_is_preprocessor(Token tok) {
	return bitfield_is_set( u32, tok.Flags, TF_Preprocess );
}

FORCEINLINE
bool tok_is_preprocess_cond(Token tok) {
	return bitfield_is_set( u32, tok.Flags, TF_Preprocess_Cond );
}

FORCEINLINE
bool tok_is_specifier(Token tok) {
	return bitfield_is_set( u32, tok.Flags, TF_Specifier );
}

FORCEINLINE
bool tok_is_end_definition(Token tok) {
	return bitfield_is_set( u32, tok.Flags, TF_EndDefinition );
}

StrBuilder tok_to_strbuilder(Token tok);

struct TokArray 
{
	Array(Token) Arr;
	s32          Idx;
};

struct LexContext
{
	Str             content;
	s32             left;
	char const*     scanner;
	s32             line;
	s32             column;
	// StringTable     defines;
	Token           token;
};

struct StackNode
{
	StackNode* Prev;

	Token* Start;
	Str    Name;          // The name of the AST node (if parsed)
	Str    ProcName;    // The name of the procedure
};

struct ParseContext
{
	TokArray   Tokens;
	StackNode* Scope;
};

enum MacroType : u16
{
	MT_Expression,     // A macro is assumed to be a expression if not resolved.
	MT_Statement,      
	MT_Typename,
	MT_Block_Start,    // Not Supported yet
	MT_Block_End,      // Not Supported yet
	MT_Case_Statement, // Not Supported yet

	MT_UnderlyingType = GEN_U16_MAX,
};

FORCEINLINE
TokType macrotype_to_toktype( MacroType type ) {
	switch ( type ) {
		case MT_Statement  : return Tok_Preprocess_Macro_Stmt;
		case MT_Expression : return Tok_Preprocess_Macro_Expr;
		case MT_Typename   : return Tok_Preprocess_Macro_Typename;
	}
	// All others unsupported for now.
	return Tok_Invalid;
}

inline
Str macrotype_to_str( MacroType type )
{
	local_persist
	Str lookup[] = {
		{ "Statement",        sizeof("Statement")        - 1 },
		{ "Expression",       sizeof("Expression")       - 1 },
		{ "Typename",         sizeof("Typename")         - 1 },
		{ "Block_Start",      sizeof("Block_Start")      - 1 },
		{ "Block_End",        sizeof("Block_End")        - 1 },
		{ "Case_Statement",   sizeof("Case_Statement")   - 1 },
	};
	local_persist
	Str invalid = { "Invalid", sizeof("Invalid") };
	if ( type > MT_Case_Statement )
		return invalid;

	return lookup[ type ];
}

enum EMacroFlags : u16
{
	MF_Functional          = bit(0), // Macro has parameters (args expected to be passed)
	MF_Expects_Body        = bit(1), // Expects to assign a braced scope to its body.

	// lex__eat wil treat this macro as an identifier if the parser attempts to consume it as one.
	//  ^^^ This is a kludge because we don't support push/pop macro pragmas rn.
	MF_Allow_As_Identifier = bit(2), 

	// lex__eat wil treat this macro as an attribute if the parser attempts to consume it as one.
	//  ^^^ This a kludge because unreal has a macro that behaves as both a 'statement' and an attribute (UE_DEPRECATED, PRAGMA_ENABLE_DEPRECATION_WARNINGS, etc)
	// TODO(Ed): We can keep the MF_Allow_As_Attribute flag for macros, however, we need to add the ability of AST_Attributes to chain themselves.
	// Its thats already a thing in the standard language anyway
	// & it would allow UE_DEPRECATED, (UE_PROPERTY / UE_FUNCTION) to chain themselves as attributes of a resolved member function/variable definition
	MF_Allow_As_Attribute  = bit(3),

	// When a macro is encountered after attributes and specifiers while parsing a function, or variable:
	// It will consume the macro and treat it as resolving the definition. (Yes this is for Unreal Engine)
	// (MUST BE OF MT_Statement TYPE)
	MF_Allow_As_Definition = bit(4),

	MF_Allow_As_Specifier = bit(5), // Created for Unreal's PURE_VIRTUAL

	MF_Null           = 0,
	MF_UnderlyingType = GEN_U16_MAX,
};
typedef u16 MacroFlags;

struct Macro
{
	StrCached  Name;
	MacroType  Type;
	MacroFlags Flags;
};

FORCEINLINE
b32 macro_is_functional( Macro macro ) {
	return bitfield_is_set( b16, macro.Flags, MF_Functional );
}

FORCEINLINE
b32 macro_expects_body( Macro macro ) {
	return bitfield_is_set( b16, macro.Flags, MF_Expects_Body );
}

#if GEN_COMPILER_CPP && ! GEN_C_LIKE_CPP
FORCEINLINE b32 is_functional( Macro macro ) { return bitfield_is_set( b16, macro.Flags, MF_Functional ); }
FORCEINLINE b32 expects_body ( Macro macro ) { return bitfield_is_set( b16, macro.Flags, MF_Expects_Body ); }
#endif

typedef HashTable(Macro) MacroTable;
#pragma endregion Types

#pragma region AST

/*
  ______   ______  ________      __    __       ______                 __
 /      \ /      \|        \    |  \  |  \     /      \               |  \
|  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\\▓▓▓▓▓▓▓▓    | ▓▓\ | ▓▓    |  ▓▓▓▓▓▓\ ______   ____| ▓▓ ______
| ▓▓__| ▓▓ ▓▓___\▓▓  | ▓▓       | ▓▓▓\| ▓▓    | ▓▓   \▓▓/      \ /      ▓▓/      \
| ▓▓    ▓▓\▓▓    \   | ▓▓       | ▓▓▓▓\ ▓▓    | ▓▓     |  ▓▓▓▓▓▓\  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓\
| ▓▓▓▓▓▓▓▓_\▓▓▓▓▓▓\  | ▓▓       | ▓▓\▓▓ ▓▓    | ▓▓   __| ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓    ▓▓
| ▓▓  | ▓▓  \__| ▓▓  | ▓▓       | ▓▓ \▓▓▓▓    | ▓▓__/  \ ▓▓__/ ▓▓ ▓▓__| ▓▓ ▓▓▓▓▓▓▓▓
| ▓▓  | ▓▓\▓▓    ▓▓  | ▓▓       | ▓▓  \▓▓▓     \▓▓    ▓▓\▓▓    ▓▓\▓▓    ▓▓\▓▓     \
 \▓▓   \▓▓ \▓▓▓▓▓▓    \▓▓        \▓▓   \▓▓      \▓▓▓▓▓▓  \▓▓▓▓▓▓  \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓
*/

struct AST;
struct AST_Body;
struct AST_Attributes;
struct AST_Comment;
struct AST_Constructor;
// struct AST_BaseClass;
struct AST_Class;
struct AST_Define;
struct AST_DefineParams;
struct AST_Destructor;
struct AST_Enum;
struct AST_Exec;
struct AST_Extern;
struct AST_Include;
struct AST_Friend;
struct AST_Fn;
struct AST_Module;
struct AST_NS;
struct AST_Operator;
struct AST_OpCast;
struct AST_Params;
struct AST_Pragma;
struct AST_PreprocessCond;
struct AST_Specifiers;

#ifdef GEN_EXECUTION_EXPRESSION_SUPPORT
struct AST_Expr;
struct AST_Expr_Assign;
struct AST_Expr_Alignof;
struct AST_Expr_Binary;
struct AST_Expr_CStyleCast;
struct AST_Expr_FunctionalCast;
struct AST_Expr_CppCast;
struct AST_Expr_ProcCall;
struct AST_Expr_Decltype;
struct AST_Expr_Comma;  // TODO(Ed) : This is a binary op not sure if it needs its own AST...
struct AST_Expr_AMS;    // Access Member Symbol
struct AST_Expr_Sizeof;
struct AST_Expr_Subscript;
struct AST_Expr_Ternary;
struct AST_Expr_UnaryPrefix;
struct AST_Expr_UnaryPostfix;
struct AST_Expr_Element;

struct AST_Stmt;
struct AST_Stmt_Break;
struct AST_Stmt_Case;
struct AST_Stmt_Continue;
struct AST_Stmt_Decl;
struct AST_Stmt_Do;
struct AST_Stmt_Expr;  // TODO(Ed) : Is this distinction needed? (Should it be a flag instead?)
struct AST_Stmt_Else;
struct AST_Stmt_If;
struct AST_Stmt_For;
struct AST_Stmt_Goto;
struct AST_Stmt_Label;
struct AST_Stmt_Switch;
struct AST_Stmt_While;
#endif

struct AST_Struct;
struct AST_Template;
struct AST_Typename;
struct AST_Typedef;
struct AST_Union;
struct AST_Using;
struct AST_Var;

#if GEN_COMPILER_C
typedef AST* Code;
#else
struct Code;
#endif

#if GEN_COMPILER_C
typedef AST_Body*           CodeBody;
typedef AST_Attributes*     CodeAttributes;
typedef AST_Comment*        CodeComment;
typedef AST_Class*          CodeClass;
typedef AST_Constructor*    CodeConstructor;
typedef AST_Define*         CodeDefine;
typedef AST_DefineParams*   CodeDefineParams;
typedef AST_Destructor*     CodeDestructor;
typedef AST_Enum*           CodeEnum;
typedef AST_Exec*           CodeExec;
typedef AST_Extern*         CodeExtern;
typedef AST_Include*        CodeInclude;
typedef AST_Friend*         CodeFriend;
typedef AST_Fn*             CodeFn;
typedef AST_Module*         CodeModule;
typedef AST_NS*             CodeNS;
typedef AST_Operator*       CodeOperator;
typedef AST_OpCast*         CodeOpCast;
typedef AST_Params*         CodeParams;
typedef AST_PreprocessCond* CodePreprocessCond;
typedef AST_Pragma*         CodePragma;
typedef AST_Specifiers*     CodeSpecifiers;
#else
struct CodeBody;
struct CodeAttributes;
struct CodeComment;
struct CodeClass;
struct CodeConstructor;
struct CodeDefine;
struct CodeDefineParams;
struct CodeDestructor;
struct CodeEnum;
struct CodeExec;
struct CodeExtern;
struct CodeInclude;
struct CodeFriend;
struct CodeFn;
struct CodeModule;
struct CodeNS;
struct CodeOperator;
struct CodeOpCast;
struct CodeParams;
struct CodePreprocessCond;
struct CodePragma;
struct CodeSpecifiers;
#endif

#ifdef GEN_EXECUTION_EXPRESSION_SUPPORT

#if GEN_COMPILER_C
typedef AST_Expr*                CodeExpr;
typedef AST_Expr_Assign*         CodeExpr_Assign;
typedef AST_Expr_Alignof*        CodeExpr_Alignof;
typedef AST_Expr_Binary*         CodeExpr_Binary;
typedef AST_Expr_CStyleCast*     CodeExpr_CStyleCast;
typedef AST_Expr_FunctionalCast* CodeExpr_FunctionalCast;
typedef AST_Expr_CppCast*        CodeExpr_CppCast;
typedef AST_Expr_Element*        CodeExpr_Element;
typedef AST_Expr_ProcCall*       CodeExpr_ProcCall;
typedef AST_Expr_Decltype*       CodeExpr_Decltype;
typedef AST_Expr_Comma*          CodeExpr_Comma;
typedef AST_Expr_AMS*            CodeExpr_AMS; // Access Member Symbol
typedef AST_Expr_Sizeof*         CodeExpr_Sizeof;
typedef AST_Expr_Subscript*      CodeExpr_Subscript;
typedef AST_Expr_Ternary*        CodeExpr_Ternary;
typedef AST_Expr_UnaryPrefix*    CodeExpr_UnaryPrefix;
typedef AST_Expr_UnaryPostfix*   CodeExpr_UnaryPostfix;
#else
struct CodeExpr;
struct CodeExpr_Assign;
struct CodeExpr_Alignof;
struct CodeExpr_Binary;
struct CodeExpr_CStyleCast;
struct CodeExpr_FunctionalCast;
struct CodeExpr_CppCast;
struct CodeExpr_Element;
struct CodeExpr_ProcCall;
struct CodeExpr_Decltype;
struct CodeExpr_Comma;
struct CodeExpr_AMS; // Access Member Symbol
struct CodeExpr_Sizeof;
struct CodeExpr_Subscript;
struct CodeExpr_Ternary;
struct CodeExpr_UnaryPrefix;
struct CodeExpr_UnaryPostfix;
#endif

#if GEN_COMPILER_C
typedef AST_Stmt*          CodeStmt;
typedef AST_Stmt_Break*    CodeStmt_Break;
typedef AST_Stmt_Case*     CodeStmt_Case;
typedef AST_Stmt_Continue* CodeStmt_Continue;
typedef AST_Stmt_Decl*     CodeStmt_Decl;
typedef AST_Stmt_Do*       CodeStmt_Do;
typedef AST_Stmt_Expr*     CodeStmt_Expr;
typedef AST_Stmt_Else*     CodeStmt_Else;
typedef AST_Stmt_If*       CodeStmt_If;
typedef AST_Stmt_For*      CodeStmt_For;
typedef AST_Stmt_Goto*     CodeStmt_Goto;
typedef AST_Stmt_Label*    CodeStmt_Label;
typedef AST_Stmt_Switch*   CodeStmt_Switch;
typedef AST_Stmt_While*    CodeStmt_While;
#else
struct CodeStmt;
struct CodeStmt_Break;
struct CodeStmt_Case;
struct CodeStmt_Continue;
struct CodeStmt_Decl;
struct CodeStmt_Do;
struct CodeStmt_Expr;
struct CodeStmt_Else;
struct CodeStmt_If;
struct CodeStmt_For;
struct CodeStmt_Goto;
struct CodeStmt_Label;
struct CodeStmt_Switch;
struct CodeStmt_While;
#endif

// GEN_EXECUTION_EXPRESSION_SUPPORT
#endif

#if GEN_COMPILER_C
typedef AST_Struct*   CodeStruct;
typedef AST_Template* CodeTemplate;
typedef AST_Typename* CodeTypename;
typedef AST_Typedef*  CodeTypedef;
typedef AST_Union*    CodeUnion;
typedef AST_Using*    CodeUsing;
typedef AST_Var*      CodeVar;
#else
struct CodeStruct;
struct CodeTemplate;
struct CodeTypename;
struct CodeTypedef;
struct CodeUnion;
struct CodeUsing;
struct CodeVar;
#endif

#if GEN_COMPILER_CPP
template< class Type> FORCEINLINE Type tmpl_cast( Code self ) { return * rcast( Type*, & self ); }
#endif

#pragma region Code C-Interface

GEN_API void       code_append           (Code code, Code other );
GEN_API Str        code_debug_str        (Code code);
GEN_API Code       code_duplicate        (Code code);
GEN_API Code*      code_entry            (Code code, u32 idx );
GEN_API bool       code_has_entries      (Code code);
GEN_API bool       code_is_body          (Code code);
GEN_API bool       code_is_equal         (Code code, Code other);
GEN_API bool       code_is_valid         (Code code);
GEN_API void       code_set_global       (Code code);
GEN_API StrBuilder code_to_strbuilder    (Code self );
GEN_API void       code_to_strbuilder_ptr(Code self, StrBuilder* result );
GEN_API Str        code_type_str         (Code self );
GEN_API bool       code_validate_body    (Code self );

#pragma endregion Code C-Interface

#if GEN_COMPILER_CPP
/*
	AST* wrapper
	- Not constantly have to append the '*' as this is written often..
	- Allows for implicit conversion to any of the ASTs (raw or filtered).
*/
struct Code
{
	AST* ast;

#	define Using_Code( Typename )                                                        \
	FORCEINLINE Str  debug_str()                { return code_debug_str(* this); }       \
	FORCEINLINE Code duplicate()                { return code_duplicate(* this); }	     \
	FORCEINLINE bool is_equal( Code other )     { return code_is_equal(* this, other); } \
	FORCEINLINE bool is_body()                  { return code_is_body(* this); }         \
	FORCEINLINE bool is_valid()                 { return code_is_valid(* this); }        \
	FORCEINLINE void set_global()               { return code_set_global(* this); }

#	define Using_CodeOps( Typename )                                                                           \
	FORCEINLINE Typename&  operator = ( Code other );                                                          \
	FORCEINLINE bool       operator ==( Code other )                        { return (AST*)ast == other.ast; } \
	FORCEINLINE bool       operator !=( Code other )                        { return (AST*)ast != other.ast; } \
	FORCEINLINE bool       operator ==(std::nullptr_t) const                { return ast == nullptr; }         \
	FORCEINLINE bool       operator !=(std::nullptr_t) const                { return ast != nullptr;  }        \
	operator bool();

#if ! GEN_C_LIKE_CPP
	Using_Code( Code );
	FORCEINLINE void       append(Code other)                { return code_append(* this, other); }
	FORCEINLINE Code*      entry(u32 idx)                    { return code_entry(* this, idx); }
	FORCEINLINE bool       has_entries()                     { return code_has_entries(* this); }
	FORCEINLINE StrBuilder to_strbuilder()                   { return code_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder(StrBuilder& result) { return code_to_strbuilder_ptr(* this, & result); }
	FORCEINLINE Str        type_str()                        { return code_type_str(* this); }
	FORCEINLINE bool       validate_body()                   { return code_validate_body(*this); }
#endif

	Using_CodeOps( Code );
	FORCEINLINE Code operator *() { return * this; } // Required to support for-range iteration.
	FORCEINLINE AST* operator ->() { return ast; }

	Code& operator ++();

#ifdef GEN_ENFORCE_STRONG_CODE_TYPES
#	define operator explicit operator
#endif
	operator CodeBody() const;
	operator CodeAttributes() const;
	// operator CodeBaseClass() const;
	operator CodeComment() const;
	operator CodeClass() const;
	operator CodeConstructor() const;
	operator CodeDefine() const;
	operator CodeDefineParams() const;
	operator CodeDestructor() const;
	operator CodeExec() const;
	operator CodeEnum() const;
	operator CodeExtern() const;
	operator CodeInclude() const;
	operator CodeFriend() const;
	operator CodeFn() const;
	operator CodeModule() const;
	operator CodeNS() const;
	operator CodeOperator() const;
	operator CodeOpCast() const;
	operator CodeParams() const;
	operator CodePragma() const;
	operator CodePreprocessCond() const;
	operator CodeSpecifiers() const;
	operator CodeStruct() const;
	operator CodeTemplate() const;
	operator CodeTypename() const;
	operator CodeTypedef() const;
	operator CodeUnion() const;
	operator CodeUsing() const;
	operator CodeVar() const;
	#undef operator
};
#endif

#pragma region Statics
// Used to identify ASTs that should always be duplicated. (Global constant ASTs)
GEN_API extern Code Code_Global;

// Used to identify invalid generated code.
GEN_API extern Code Code_Invalid;
#pragma endregion Statics

struct Code_POD
{
	AST* ast;
};
static_assert( sizeof(Code) == sizeof(Code_POD), "ERROR: Code is not POD" );

// Desired width of the AST data structure.
constexpr int const AST_POD_Size = 128;

constexpr static
int AST_ArrSpecs_Cap =
(
	AST_POD_Size
	- sizeof(Code)
	- sizeof(StrCached)
	- sizeof(Code) * 2
	- sizeof(Token*)
	- sizeof(Code)
	- sizeof(CodeType)
	- sizeof(ModuleFlag)
	- sizeof(u32)
)
/ sizeof(Specifier) - 1;

/*
	Simple AST POD with functionality to seralize into C++ syntax.
	TODO(Ed): Eventually haven't a transparent AST like this will longer be viable once statements & expressions are in (most likely....)
*/
struct AST
{
	union {
		struct
		{
			Code      InlineCmt;       // Class, Constructor, Destructor, Enum, Friend, Functon, Operator, OpCast, Struct, Typedef, Using, Variable
			Code      Attributes;      // Class, Enum, Function, Struct, Typedef, Union, Using, Variable // TODO(Ed): Parameters can have attributes
			Code      Specs;           // Class, Destructor, Function, Operator, Struct, Typename, Variable
			union {
				Code  InitializerList; // Constructor
				Code  ParentType;      // Class, Struct, ParentType->Next has a possible list of interfaces.
				Code  ReturnType;      // Function, Operator, Typename
				Code  UnderlyingType;  // Enum, Typedef
				Code  ValueType;       // Parameter, Variable
			};
			union {
				Code  Macro;               // Parameter
				Code  BitfieldSize;        // Variable (Class/Struct Data Member)
				Code  Params;              // Constructor, Define, Function, Operator, Template, Typename
				Code  UnderlyingTypeMacro; // Enum
			};
			union {
				Code  ArrExpr;          // Typename
				Code  Body;             // Class, Constructor, Define, Destructor, Enum, Friend, Function, Namespace, Struct, Union
				Code  Declaration;      // Friend, Template
				Code  Value;            // Parameter, Variable
			};
			union {
				Code  NextVar;          // Variable; Possible way to handle comma separated variables declarations. ( , NextVar->Specs NextVar->Name NextVar->ArrExpr = NextVar->Value )
				Code  SuffixSpecs;      // Typename, Function (Thanks Unreal)
				Code  PostNameMacro;    // Only used with parameters for specifically UE_REQUIRES (Thanks Unreal)
			};
		};
		StrCached  Content;          // Attributes, Comment, Execution, Include
		struct {
			Specifier  ArrSpecs[AST_ArrSpecs_Cap]; // Specifiers
			Code       NextSpecs;              // Specifiers; If ArrSpecs is full, then NextSpecs is used.
		};
	};
	StrCached      Name;
	union {
		Code Prev;
		Code Front;
		Code Last;
	};
	union {
		Code Next;
		Code Back;
	};
	Token*            Token; // Reference to starting token, only available if it was derived from parsing.
	Code              Parent;
	CodeType          Type;
//	CodeFlag          CodeFlags;
	ModuleFlag        ModuleFlags;
	union {
		b32           IsFunction;  // Used by typedef to not serialize the name field.
		struct {
			b16           IsParamPack;   // Used by typename to know if type should be considered a parameter pack.
			ETypenameTag  TypeTag;       // Used by typename to keep track of explicitly declared tags for the identifier (enum, struct, union)
		};
		Operator      Op;
		AccessSpec    ParentAccess;
		s32           NumEntries;
		s32           VarParenthesizedInit;  // Used by variables to know that initialization is using a constructor expression instead of an assignment expression.
	};
};
static_assert( sizeof(AST) == AST_POD_Size, "ERROR: AST is not size of AST_POD_Size" );

#if GEN_COMPILER_CPP
// Uses an implicitly overloaded cast from the AST to the desired code type.
// Necessary if the user wants GEN_ENFORCE_STRONG_CODE_TYPES
struct  InvalidCode_ImplictCaster;
#define InvalidCode (InvalidCode_ImplictCaster{})
#else
#define InvalidCode (void*){ (void*)Code_Invalid }
#endif

#if GEN_COMPILER_CPP
struct NullCode_ImplicitCaster;
// Used when the its desired when omission is allowed in a definition.
#define NullCode    (NullCode_ImplicitCaster{})
#else
#define NullCode    nullptr
#endif

/*
  ______                 __               ______            __                        ______
 /      \               |  \             |      \          |  \                      /      \
|  ▓▓▓▓▓▓\ ______   ____| ▓▓ ______       \▓▓▓▓▓▓_______  _| ▓▓_    ______   ______ |  ▓▓▓▓▓▓\ ______   _______  ______
| ▓▓   \▓▓/      \ /      ▓▓/      \       | ▓▓ |       \|   ▓▓ \  /      \ /      \| ▓▓_  \▓▓|      \ /       \/      \
| ▓▓     |  ▓▓▓▓▓▓\  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓\      | ▓▓ | ▓▓▓▓▓▓▓\\▓▓▓▓▓▓ |  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\ ▓▓ \     \▓▓▓▓▓▓\  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓\
| ▓▓   __| ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓    ▓▓      | ▓▓ | ▓▓  | ▓▓ | ▓▓ __| ▓▓    ▓▓ ▓▓   \▓▓ ▓▓▓▓    /      ▓▓ ▓▓     | ▓▓    ▓▓
| ▓▓__/  \ ▓▓__/ ▓▓ ▓▓__| ▓▓ ▓▓▓▓▓▓▓▓     _| ▓▓_| ▓▓  | ▓▓ | ▓▓|  \ ▓▓▓▓▓▓▓▓ ▓▓     | ▓▓     |  ▓▓▓▓▓▓▓ ▓▓_____| ▓▓▓▓▓▓▓▓
 \▓▓    ▓▓\▓▓    ▓▓\▓▓    ▓▓\▓▓     \    |   ▓▓ \ ▓▓  | ▓▓  \▓▓  ▓▓\▓▓     \ ▓▓     | ▓▓      \▓▓    ▓▓\▓▓     \\▓▓     \
  \▓▓▓▓▓▓  \▓▓▓▓▓▓  \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓     \▓▓▓▓▓▓\▓▓   \▓▓   \▓▓▓▓  \▓▓▓▓▓▓▓\▓▓      \▓▓       \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓
*/

#pragma region Code Type C-Interface

GEN_API void       body_append              ( CodeBody body, Code     other );
GEN_API void       body_append_body         ( CodeBody body, CodeBody other );
GEN_API StrBuilder body_to_strbuilder       ( CodeBody body );
GEN_API void       body_to_strbuilder_ref   ( CodeBody body, StrBuilder* result );
GEN_API void       body_to_strbuilder_export( CodeBody body, StrBuilder* result );

GEN_API Code begin_CodeBody( CodeBody body);
GEN_API Code end_CodeBody  ( CodeBody body );
GEN_API Code next_CodeBody ( CodeBody body, Code entry_iter );

GEN_API void       class_add_interface    ( CodeClass self, CodeTypename interface );
GEN_API StrBuilder class_to_strbuilder    ( CodeClass self );
GEN_API void       class_to_strbuilder_def( CodeClass self, StrBuilder* result );
GEN_API void       class_to_strbuilder_fwd( CodeClass self, StrBuilder* result );

GEN_API void             define_params_append           (CodeDefineParams appendee, CodeDefineParams other );
GEN_API CodeDefineParams define_params_get              (CodeDefineParams params, s32 idx);
GEN_API bool             define_params_has_entries      (CodeDefineParams params );
GEN_API StrBuilder       define_params_to_strbuilder    (CodeDefineParams params );
GEN_API void             define_params_to_strbuilder_ref(CodeDefineParams params, StrBuilder* result );

GEN_API CodeDefineParams begin_CodeDefineParams(CodeDefineParams params);
GEN_API CodeDefineParams end_CodeDefineParams  (CodeDefineParams params);
GEN_API CodeDefineParams next_CodeDefineParams (CodeDefineParams params, CodeDefineParams entry_iter);

GEN_API void       params_append           (CodeParams appendee, CodeParams other );
GEN_API CodeParams params_get              (CodeParams params, s32 idx);
GEN_API bool       params_has_entries      (CodeParams params );
GEN_API StrBuilder params_to_strbuilder    (CodeParams params );
GEN_API void       params_to_strbuilder_ref(CodeParams params, StrBuilder* result );

GEN_API CodeParams begin_CodeParams(CodeParams params);
GEN_API CodeParams end_CodeParams  (CodeParams params);
GEN_API CodeParams next_CodeParams (CodeParams params, CodeParams entry_iter);

GEN_API bool       specifiers_append           (CodeSpecifiers specifiers, Specifier spec);
GEN_API s32        specifiers_has              (CodeSpecifiers specifiers, Specifier spec);
GEN_API s32        specifiers_remove           (CodeSpecifiers specifiers, Specifier to_remove );
GEN_API StrBuilder specifiers_to_strbuilder    (CodeSpecifiers specifiers);
GEN_API void       specifiers_to_strbuilder_ref(CodeSpecifiers specifiers, StrBuilder* result);

GEN_API Specifier* begin_CodeSpecifiers(CodeSpecifiers specifiers);
GEN_API Specifier* end_CodeSpecifiers  (CodeSpecifiers specifiers);
GEN_API Specifier* next_CodeSpecifiers (CodeSpecifiers specifiers, Specifier* spec_iter);

GEN_API void       struct_add_interface    (CodeStruct self, CodeTypename interface);
GEN_API StrBuilder struct_to_strbuilder    (CodeStruct self);
GEN_API void       struct_to_strbuilder_fwd(CodeStruct self, StrBuilder* result);
GEN_API void       struct_to_strbuilder_def(CodeStruct self, StrBuilder* result);

GEN_API StrBuilder attributes_to_strbuilder    (CodeAttributes attributes);
GEN_API void       attributes_to_strbuilder_ref(CodeAttributes attributes, StrBuilder* result);

GEN_API StrBuilder comment_to_strbuilder    (CodeComment comment );
GEN_API void       comment_to_strbuilder_ref(CodeComment comment, StrBuilder* result );

GEN_API StrBuilder constructor_to_strbuilder    (CodeConstructor constructor);
GEN_API void       constructor_to_strbuilder_def(CodeConstructor constructor, StrBuilder* result );
GEN_API void       constructor_to_strbuilder_fwd(CodeConstructor constructor, StrBuilder* result );

GEN_API StrBuilder define_to_strbuilder    (CodeDefine self);
GEN_API void       define_to_strbuilder_ref(CodeDefine self, StrBuilder* result);

GEN_API StrBuilder destructor_to_strbuilder    (CodeDestructor destructor);
GEN_API void       destructor_to_strbuilder_fwd(CodeDestructor destructor, StrBuilder* result );
GEN_API void       destructor_to_strbuilder_def(CodeDestructor destructor, StrBuilder* result );

GEN_API StrBuilder enum_to_strbuilder          (CodeEnum self);
GEN_API void       enum_to_strbuilder_def      (CodeEnum self, StrBuilder* result );
GEN_API void       enum_to_strbuilder_fwd      (CodeEnum self, StrBuilder* result );
GEN_API void       enum_to_strbuilder_class_def(CodeEnum self, StrBuilder* result );
GEN_API void       enum_to_strbuilder_class_fwd(CodeEnum self, StrBuilder* result );

GEN_API StrBuilder exec_to_strbuilder    (CodeExec exec);
GEN_API void       exec_to_strbuilder_ref(CodeExec exec, StrBuilder* result);

GEN_API void extern_to_strbuilder(CodeExtern self, StrBuilder* result);

GEN_API StrBuilder include_to_strbuilder    (CodeInclude self);
GEN_API void       include_to_strbuilder_ref(CodeInclude self, StrBuilder* result);

GEN_API StrBuilder friend_to_strbuilder     (CodeFriend self);
GEN_API void       friend_to_strbuilder_ref(CodeFriend self, StrBuilder* result);

GEN_API StrBuilder fn_to_strbuilder    (CodeFn self);
GEN_API void       fn_to_strbuilder_def(CodeFn self, StrBuilder* result);
GEN_API void       fn_to_strbuilder_fwd(CodeFn self, StrBuilder* result);

GEN_API StrBuilder module_to_strbuilder    (CodeModule self);
GEN_API void       module_to_strbuilder_ref(CodeModule self, StrBuilder* result);

GEN_API StrBuilder namespace_to_strbuilder    (CodeNS self);
GEN_API void       namespace_to_strbuilder_ref(CodeNS self, StrBuilder* result);

GEN_API StrBuilder code_op_to_strbuilder    (CodeOperator self);
GEN_API void       code_op_to_strbuilder_fwd(CodeOperator self, StrBuilder* result );
GEN_API void       code_op_to_strbuilder_def(CodeOperator self, StrBuilder* result );

GEN_API StrBuilder opcast_to_strbuilder     (CodeOpCast op_cast );
GEN_API void       opcast_to_strbuilder_def(CodeOpCast op_cast, StrBuilder* result );
GEN_API void       opcast_to_strbuilder_fwd(CodeOpCast op_cast, StrBuilder* result );

GEN_API StrBuilder pragma_to_strbuilder    (CodePragma self);
GEN_API void       pragma_to_strbuilder_ref(CodePragma self, StrBuilder* result);

GEN_API StrBuilder preprocess_to_strbuilder       (CodePreprocessCond cond);
GEN_API void       preprocess_to_strbuilder_if    (CodePreprocessCond cond, StrBuilder* result );
GEN_API void       preprocess_to_strbuilder_ifdef (CodePreprocessCond cond, StrBuilder* result );
GEN_API void       preprocess_to_strbuilder_ifndef(CodePreprocessCond cond, StrBuilder* result );
GEN_API void       preprocess_to_strbuilder_elif  (CodePreprocessCond cond, StrBuilder* result );
GEN_API void       preprocess_to_strbuilder_else  (CodePreprocessCond cond, StrBuilder* result );
GEN_API void       preprocess_to_strbuilder_endif (CodePreprocessCond cond, StrBuilder* result );

GEN_API StrBuilder template_to_strbuilder    (CodeTemplate self);
GEN_API void       template_to_strbuilder_ref(CodeTemplate self, StrBuilder* result);

GEN_API StrBuilder typename_to_strbuilder    (CodeTypename self);
GEN_API void       typename_to_strbuilder_ref(CodeTypename self, StrBuilder* result);

GEN_API StrBuilder typedef_to_strbuilder    (CodeTypedef self);
GEN_API void       typedef_to_strbuilder_ref(CodeTypedef self, StrBuilder* result );

GEN_API StrBuilder union_to_strbuilder    (CodeUnion self);
GEN_API void       union_to_strbuilder_def(CodeUnion self, StrBuilder* result);
GEN_API void       union_to_strbuilder_fwd(CodeUnion self, StrBuilder* result);

GEN_API StrBuilder using_to_strbuilder    (CodeUsing op_cast );
GEN_API void       using_to_strbuilder_ref(CodeUsing op_cast, StrBuilder* result );
GEN_API void       using_to_strbuilder_ns (CodeUsing op_cast, StrBuilder* result );

GEN_API StrBuilder var_to_strbuilder    (CodeVar self);
GEN_API void       var_to_strbuilder_ref(CodeVar self, StrBuilder* result);

#pragma endregion Code Type C-Interface

#if GEN_COMPILER_CPP
#pragma region Code Types C++

// These structs are not used at all by the C vairant.
static_assert( GEN_COMPILER_CPP, "This should not be compiled with the C-library" );

#define Verify_POD(Type) static_assert(size_of(Code##Type) == size_of(AST_##Type), "ERROR: Code##Type is not a POD")

struct CodeBody
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeBody );
	FORCEINLINE void       append( Code other )                       { return body_append( *this, other ); }
	FORCEINLINE void       append( CodeBody body )                    { return body_append(*this, body); }
	FORCEINLINE bool       has_entries()                              { return code_has_entries(* this); }
	FORCEINLINE StrBuilder to_strbuilder()                            { return body_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result )        { return body_to_strbuilder_ref(* this, & result ); }
	FORCEINLINE void       to_strbuilder_export( StrBuilder& result ) { return body_to_strbuilder_export(* this, & result); }

#endif
	FORCEINLINE Code begin() { return begin_CodeBody(* this); }
	FORCEINLINE Code end()   { return end_CodeBody(* this); }
	Using_CodeOps( CodeBody );
	FORCEINLINE operator Code() { return * rcast( Code*, this ); }
	FORCEINLINE AST_Body* operator->() { return ast; }
	AST_Body* ast;
};

struct CodeClass
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeClass );
	FORCEINLINE void       add_interface( CodeType interface );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder_def( StrBuilder& result );
	FORCEINLINE void       to_strbuilder_fwd( StrBuilder& result );
#endif
	Using_CodeOps( CodeClass );
	FORCEINLINE operator Code() { return * rcast( Code*, this ); }
	FORCEINLINE AST_Class* operator->() {
		GEN_ASSERT(ast);
		return ast;
	}
	AST_Class* ast;
};

struct CodeParams
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeParams );
	FORCEINLINE void          append( CodeParams other )          { return params_append(* this, other); }
	FORCEINLINE CodeParams    get( s32 idx )                      { return params_get( * this, idx); }
	FORCEINLINE bool          has_entries()                       { return params_has_entries(* this); }
	FORCEINLINE StrBuilder    to_strbuilder()                     { return params_to_strbuilder(* this); }
	FORCEINLINE void          to_strbuilder( StrBuilder& result ) { return params_to_strbuilder_ref(*this, & result); }
#endif
	Using_CodeOps( CodeParams );
	FORCEINLINE CodeParams begin() { return begin_CodeParams(* this); }
	FORCEINLINE CodeParams end()   { return end_CodeParams(* this); }
	FORCEINLINE operator Code() { return { (AST*)ast }; }
	FORCEINLINE CodeParams  operator *() { return * this; } // Required to support for-range iteration.
	FORCEINLINE AST_Params* operator->() {
		GEN_ASSERT(ast);
		return ast;
	}
	CodeParams& operator++();
	AST_Params* ast;
};

struct CodeDefineParams
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeDefineParams );
	FORCEINLINE void             append( CodeDefineParams other )    { return params_append( cast(CodeParams, * this), cast(CodeParams, other)); }
	FORCEINLINE CodeDefineParams get( s32 idx )                      { return (CodeDefineParams) (Code) params_get( cast(CodeParams, * this), idx); }
	FORCEINLINE bool             has_entries()                       { return params_has_entries( cast(CodeParams, * this)); }
	FORCEINLINE StrBuilder       to_strbuilder()                     { return define_params_to_strbuilder(* this); }
	FORCEINLINE void             to_strbuilder( StrBuilder& result ) { return define_params_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps( CodeDefineParams );
	FORCEINLINE CodeDefineParams begin() { return (CodeDefineParams) (Code) begin_CodeParams( cast(CodeParams, * this)); }
	FORCEINLINE CodeDefineParams end()   { return (CodeDefineParams) (Code) end_CodeParams( cast(CodeParams, * this)); }
	FORCEINLINE operator Code() { return { (AST*)ast }; }
	FORCEINLINE CodeDefineParams  operator *() { return * this; } // Required to support for-range iteration.
	FORCEINLINE AST_DefineParams* operator->() {
		GEN_ASSERT(ast);
		return ast;
	}
	FORCEINLINE CodeDefineParams& operator++();
	AST_DefineParams* ast;
};

struct CodeSpecifiers
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeSpecifiers );
	bool       append( Specifier spec )            { return specifiers_append(* this, spec); }
	s32        has( Specifier spec )               { return specifiers_has(* this, spec); }
	s32        remove( Specifier to_remove )       { return specifiers_remove(* this, to_remove); }
	StrBuilder to_strbuilder()                     { return specifiers_to_strbuilder(* this ); }
	void       to_strbuilder( StrBuilder& result ) { return specifiers_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps(CodeSpecifiers);
	FORCEINLINE operator Code() { return { (AST*) ast }; }
	FORCEINLINE Code            operator *() { return * this; } // Required to support for-range iteration.
	FORCEINLINE AST_Specifiers* operator->() {
		GEN_ASSERT(ast);
		return ast;
	}
	AST_Specifiers* ast;
};

struct CodeAttributes
{
#if ! GEN_C_LIKE_CPP
	Using_Code(CodeAttributes);
	FORCEINLINE StrBuilder to_strbuilder()                   { return attributes_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder(StrBuilder& result) { return attributes_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps(CodeAttributes);
	operator Code();
	AST_Attributes *operator->();
	AST_Attributes *ast;
};

// Define_CodeType( BaseClass );

struct CodeComment
{
#if ! GEN_C_LIKE_CPP
	Using_Code(CodeComment);
	FORCEINLINE StrBuilder to_strbuilder()                   { return comment_to_strbuilder    (* this); }
	FORCEINLINE void       to_strbuilder(StrBuilder& result) { return comment_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps(CodeComment);
	operator Code();
	AST_Comment *operator->();
	AST_Comment *ast;
};

struct CodeConstructor
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeConstructor );
	FORCEINLINE StrBuilder to_strbuilder()                         { return constructor_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder_def( StrBuilder& result ) { return constructor_to_strbuilder_def(* this, & result); }
	FORCEINLINE void       to_strbuilder_fwd( StrBuilder& result ) { return constructor_to_strbuilder_fwd(* this, & result); }
#endif
	Using_CodeOps(CodeConstructor);
	operator         Code();
	AST_Constructor* operator->();
	AST_Constructor* ast;
};

struct CodeDefine
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeDefine );
	FORCEINLINE StrBuilder to_strbuilder()                     { return define_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result ) { return define_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps(CodeDefine);
	operator    Code();
	AST_Define* operator->();
	AST_Define* ast;
};

struct CodeDestructor
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeDestructor );
	FORCEINLINE StrBuilder to_strbuilder()                         { return destructor_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder_def( StrBuilder& result ) { return destructor_to_strbuilder_def(* this, & result); }
	FORCEINLINE void       to_strbuilder_fwd( StrBuilder& result ) { return destructor_to_strbuilder_fwd(* this, & result); }
#endif
	Using_CodeOps(CodeDestructor);
	operator         Code();
	AST_Destructor* operator->();
	AST_Destructor* ast;
};

struct CodeEnum
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeEnum );
	FORCEINLINE StrBuilder to_strbuilder()                                { return enum_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder_def( StrBuilder& result )        { return enum_to_strbuilder_def(* this, & result); }
	FORCEINLINE void       to_strbuilder_fwd( StrBuilder& result )        { return enum_to_strbuilder_fwd(* this, & result); }
	FORCEINLINE void       to_strbuilder_class_def( StrBuilder& result )  { return enum_to_strbuilder_class_def(* this, & result); }
	FORCEINLINE void       to_strbuilder_class_fwd( StrBuilder& result )  { return enum_to_strbuilder_class_fwd(* this, & result); }
#endif
	Using_CodeOps(CodeEnum);
	operator  Code();
	AST_Enum* operator->();
	AST_Enum* ast;
};

struct CodeExec
{
#if ! GEN_C_LIKE_CPP
	Using_Code(CodeExec);
	FORCEINLINE StrBuilder to_strbuilder()               { return exec_to_strbuilder(* this); }
	FORCEINLINE void   to_strbuilder(StrBuilder& result) { return exec_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps(CodeExec);
	operator Code();
	AST_Exec *operator->();
	AST_Exec *ast;
};

#ifdef GEN_EXECUTION_EXPRESSION_SUPPORT
struct CodeExpr
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator  Code();
	AST_Expr* operator->();
	AST_Expr* ast;
};

struct CodeExpr_Assign
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_Assign );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator         Code();
	AST_Expr_Assign* operator->();
	AST_Expr_Assign* ast;
};

struct CodeExpr_Alignof
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_Alignof );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator          Code();
	AST_Expr_Alignof* operator->();
	AST_Expr_Alignof* ast;
};

struct CodeExpr_Binary
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_Binary );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator         Code();
	AST_Expr_Binary* operator->();
	AST_Expr_Binary* ast;
};

struct CodeExpr_CStyleCast
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_CStyleCast );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator             Code();
	AST_Expr_CStyleCast* operator->();
	AST_Expr_CStyleCast* ast;
};

struct CodeExpr_FunctionalCast
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_FunctionalCast );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator                 Code();
	AST_Expr_FunctionalCast* operator->();
	AST_Expr_FunctionalCast* ast;
};

struct CodeExpr_CppCast
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_CppCast );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator          Code();
	AST_Expr_CppCast* operator->();
	AST_Expr_CppCast* ast;
};

struct CodeExpr_Element
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_Element );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator          Code();
	AST_Expr_Element* operator->();
	AST_Expr_Element* ast;
};

struct CodeExpr_ProcCall
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_ProcCall );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator           Code();
	AST_Expr_ProcCall* operator->();
	AST_Expr_ProcCall* ast;
};

struct CodeExpr_Decltype
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_Decltype );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator  Code();
	AST_Expr_Decltype* operator->();
	AST_Expr_Decltype* ast;
};

struct CodeExpr_Comma
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_Comma );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator  Code();
	AST_Expr_Comma* operator->();
	AST_Expr_Comma* ast;
};

struct CodeExpr_AMS
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_AMS );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator      Code();
	AST_Expr_AMS* operator->();
	AST_Expr_AMS* ast;
};

struct CodeExpr_Sizeof
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_Sizeof );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator         Code();
	AST_Expr_Sizeof* operator->();
	AST_Expr_Sizeof* ast;
};

struct CodeExpr_Subscript
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_Subscript );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator            Code();
	AST_Expr_Subscript* operator->();
	AST_Expr_Subscript* ast;
};

struct CodeExpr_Ternary
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_Ternary );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator          Code();
	AST_Expr_Ternary* operator->();
	AST_Expr_Ternary* ast;
};

struct CodeExpr_UnaryPrefix
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_UnaryPrefix );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	operator              Code();
	AST_Expr_UnaryPrefix* operator->();
	AST_Expr_UnaryPrefix* ast;
};

struct CodeExpr_UnaryPostfix
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExpr_UnaryPostfix );
	FORCEINLINE void to_strbuilder( StrBuilder& result );
#endif
	AST*                   raw();
	operator               Code();
	AST_Expr_UnaryPostfix* operator->();
	AST_Expr_UnaryPostfix* ast;
};
#endif

struct CodeExtern
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeExtern );
	FORCEINLINE void to_strbuilder( StrBuilder& result ) { return extern_to_strbuilder(* this, & result); }
#endif
	Using_CodeOps(CodeExtern);
	operator    Code();
	AST_Extern* operator->();
	AST_Extern* ast;
};

struct CodeInclude
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeInclude );
	FORCEINLINE StrBuilder to_strbuilder()                      { return include_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result )  { return include_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps(CodeInclude);
	operator     Code();
	AST_Include* operator->();
	AST_Include* ast;
};

struct CodeFriend
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeFriend );
	FORCEINLINE StrBuilder to_strbuilder()                     { return friend_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result ) { return friend_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps(CodeFriend);
	operator    Code();
	AST_Friend* operator->();
	AST_Friend* ast;
};

struct CodeFn
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeFn );
	FORCEINLINE StrBuilder to_strbuilder()                         { return fn_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder_def( StrBuilder& result ) { return fn_to_strbuilder_def(* this, & result); }
	FORCEINLINE void       to_strbuilder_fwd( StrBuilder& result ) { return fn_to_strbuilder_fwd(* this, & result); }
#endif
	Using_CodeOps(CodeFn);
	operator Code();
	AST_Fn*  operator->();
	AST_Fn*  ast;
};

struct CodeModule
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeModule );
	FORCEINLINE StrBuilder to_strbuilder()                     { return module_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result ) { return module_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps(CodeModule);
	operator    Code();
	AST_Module* operator->();
	AST_Module* ast;
};

struct CodeNS
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeNS );
	FORCEINLINE StrBuilder to_strbuilder()                     { return namespace_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result ) { return namespace_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps(CodeNS);
	operator Code();
	AST_NS*  operator->();
	AST_NS*  ast;
};

struct CodeOperator
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeOperator );
	FORCEINLINE StrBuilder to_strbuilder()                         { return code_op_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder_def( StrBuilder& result ) { return code_op_to_strbuilder_def(* this, & result); }
	FORCEINLINE void       to_strbuilder_fwd( StrBuilder& result ) { return code_op_to_strbuilder_fwd(* this, & result); }
#endif
	Using_CodeOps(CodeOperator);
	operator      Code();
	AST_Operator* operator->();
	AST_Operator* ast;
};

struct CodeOpCast
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeOpCast );
	FORCEINLINE StrBuilder to_strbuilder()                         { return opcast_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder_def( StrBuilder& result ) { return opcast_to_strbuilder_def(* this, & result); }
	FORCEINLINE void       to_strbuilder_fwd( StrBuilder& result ) { return opcast_to_strbuilder_fwd(* this, & result); }
#endif
	Using_CodeOps(CodeOpCast);
	operator    Code();
	AST_OpCast* operator->();
	AST_OpCast* ast;
};

struct CodePragma
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodePragma );
	FORCEINLINE StrBuilder to_strbuilder()                     { return pragma_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result ) { return pragma_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps( CodePragma );
	operator    Code();
	AST_Pragma* operator->();
	AST_Pragma* ast;
};

struct CodePreprocessCond
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodePreprocessCond );
	FORCEINLINE StrBuilder to_strbuilder()                            { return preprocess_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder_if( StrBuilder& result )     { return preprocess_to_strbuilder_if(* this, & result); }
	FORCEINLINE void       to_strbuilder_ifdef( StrBuilder& result )  { return preprocess_to_strbuilder_ifdef(* this, & result); }
	FORCEINLINE void       to_strbuilder_ifndef( StrBuilder& result ) { return preprocess_to_strbuilder_ifndef(* this, & result); }
	FORCEINLINE void       to_strbuilder_elif( StrBuilder& result )   { return preprocess_to_strbuilder_elif(* this, & result); }
	FORCEINLINE void       to_strbuilder_else( StrBuilder& result )   { return preprocess_to_strbuilder_else(* this, & result); }
	FORCEINLINE void       to_strbuilder_endif( StrBuilder& result )  { return preprocess_to_strbuilder_endif(* this, & result); }
#endif
	Using_CodeOps( CodePreprocessCond );
	operator            Code();
	AST_PreprocessCond* operator->();
	AST_PreprocessCond* ast;
};

#ifdef GEN_EXECUTION_EXPRESSION_SUPPORT
struct CodeStmt
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator  Code();
	AST_Stmt* operator->();
	AST_Stmt* ast;
};

struct CodeStmt_Break
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_Break );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator        Code();
	AST_Stmt_Break* operator->();
	AST_Stmt_Break* ast;
};

struct CodeStmt_Case
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_Case );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator       Code();
	AST_Stmt_Case* operator->();
	AST_Stmt_Case* ast;
};

struct CodeStmt_Continue
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_Continue );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator           Code();
	AST_Stmt_Continue* operator->();
	AST_Stmt_Continue* ast;
};

struct CodeStmt_Decl
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_Decl );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator       Code();
	AST_Stmt_Decl* operator->();
	AST_Stmt_Decl* ast;
};

struct CodeStmt_Do
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_Do );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator     Code();
	AST_Stmt_Do* operator->();
	AST_Stmt_Do* ast;
};

struct CodeStmt_Expr
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_Expr );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator       Code();
	AST_Stmt_Expr* operator->();
	AST_Stmt_Expr* ast;
};

struct CodeStmt_Else
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_Else );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator       Code();
	AST_Stmt_Else* operator->();
	AST_Stmt_Else* ast;
};

struct CodeStmt_If
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_If );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator     Code();
	AST_Stmt_If* operator->();
	AST_Stmt_If* ast;
};

struct CodeStmt_For
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_For );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator      Code();
	AST_Stmt_For* operator->();
	AST_Stmt_For* ast;
};

struct CodeStmt_Goto
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_Goto );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator       Code();
	AST_Stmt_Goto* operator->();
	AST_Stmt_Goto* ast;
};

struct CodeStmt_Label
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_Label );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator        Code();
	AST_Stmt_Label* operator->();
	AST_Stmt_Label* ast;
};

struct CodeStmt_Switch
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_Switch );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator       Code();
	AST_Stmt_Switch* operator->();
	AST_Stmt_Switch* ast;
};

struct CodeStmt_While
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStmt_While );
	FORCEINLINE StrBuilder to_strbuilder();
	FORCEINLINE void       to_strbuilder( StrBuilder& result );
#endif
	operator       Code();
	AST_Stmt_While* operator->();
	AST_Stmt_While* ast;
};
#endif

struct CodeTemplate
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeTemplate );
	FORCEINLINE StrBuilder to_strbuilder()                     { return template_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result ) { return template_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps( CodeTemplate );
	operator      Code();
	AST_Template* operator->();
	AST_Template* ast;
};

struct CodeTypename
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeTypename );
	FORCEINLINE StrBuilder to_strbuilder()                     { return typename_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result ) { return typename_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps( CodeTypename );
	operator      Code();
	AST_Typename* operator->();
	AST_Typename* ast;
};

struct CodeTypedef
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeTypedef );
	FORCEINLINE StrBuilder to_strbuilder()                     { return typedef_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result ) { return typedef_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps( CodeTypedef );
	operator     Code();
	AST_Typedef* operator->();
	AST_Typedef* ast;
};

struct CodeUnion
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeUnion );
	FORCEINLINE StrBuilder to_strbuilder()                         { return union_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder_def( StrBuilder& result ) { return union_to_strbuilder_def(* this, & result); }
	FORCEINLINE void       to_strbuilder_fwd( StrBuilder& result ) { return union_to_strbuilder_fwd(* this, & result); }
#endif
	Using_CodeOps(CodeUnion);
	operator   Code();
	AST_Union* operator->();
	AST_Union* ast;
};

struct CodeUsing
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeUsing );
	FORCEINLINE StrBuilder to_strbuilder()                        { return using_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result )    { return using_to_strbuilder_ref(* this, & result); }
	FORCEINLINE void       to_strbuilder_ns( StrBuilder& result ) { return using_to_strbuilder_ns(* this, & result); }
#endif
	Using_CodeOps(CodeUsing);
	operator   Code();
	AST_Using* operator->();
	AST_Using* ast;
};

struct CodeVar
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeVar );
	FORCEINLINE StrBuilder to_strbuilder()                     { return var_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder( StrBuilder& result ) { return var_to_strbuilder_ref(* this, & result); }
#endif
	Using_CodeOps(CodeVar);
	operator Code();
	AST_Var* operator->();
	AST_Var* ast;
};

struct CodeStruct
{
#if ! GEN_C_LIKE_CPP
	Using_Code( CodeStruct );
	FORCEINLINE void       add_interface( CodeTypename interface ) { return struct_add_interface(* this, interface); }
	FORCEINLINE StrBuilder to_strbuilder()                         { return struct_to_strbuilder(* this); }
	FORCEINLINE void       to_strbuilder_fwd( StrBuilder& result ) { return struct_to_strbuilder_fwd(* this, & result); }
	FORCEINLINE void       to_strbuilder_def( StrBuilder& result ) { return struct_to_strbuilder_def(* this, & result); }
#endif
	Using_CodeOps( CodeStruct );
	FORCEINLINE operator Code() { return * rcast( Code*, this ); }
	FORCEINLINE AST_Struct* operator->() {
		GEN_ASSERT(ast);
		return ast;
	}
	AST_Struct* ast;
};

#undef Define_CodeType
#undef Using_Code
#undef Using_CodeOps

#undef Verify_POD

struct InvalidCode_ImplictCaster
{
	// operator CodeBaseClass() const;
    operator Code              () const { return Code_Invalid; }
    operator CodeBody          () const { return cast(CodeBody,           Code_Invalid); }
    operator CodeAttributes    () const { return cast(CodeAttributes,     Code_Invalid); }
    operator CodeComment       () const { return cast(CodeComment,        Code_Invalid); }
    operator CodeClass         () const { return cast(CodeClass,          Code_Invalid); }
    operator CodeConstructor   () const { return cast(CodeConstructor,    Code_Invalid); }
    operator CodeDefine        () const { return cast(CodeDefine,         Code_Invalid); }
    operator CodeDefineParams  () const { return cast(CodeDefineParams,   Code_Invalid); }
    operator CodeDestructor    () const { return cast(CodeDestructor,     Code_Invalid); }
    operator CodeExec          () const { return cast(CodeExec,           Code_Invalid); }
    operator CodeEnum          () const { return cast(CodeEnum,           Code_Invalid); }
    operator CodeExtern        () const { return cast(CodeExtern,         Code_Invalid); }
    operator CodeInclude       () const { return cast(CodeInclude,        Code_Invalid); }
    operator CodeFriend        () const { return cast(CodeFriend,         Code_Invalid); }
    operator CodeFn            () const { return cast(CodeFn,             Code_Invalid); }
    operator CodeModule        () const { return cast(CodeModule,         Code_Invalid); }
    operator CodeNS            () const { return cast(CodeNS,             Code_Invalid); }
    operator CodeOperator      () const { return cast(CodeOperator,       Code_Invalid); }
    operator CodeOpCast        () const { return cast(CodeOpCast,         Code_Invalid); }
    operator CodeParams        () const { return cast(CodeParams,         Code_Invalid); }
    operator CodePragma        () const { return cast(CodePragma,         Code_Invalid); }
    operator CodePreprocessCond() const { return cast(CodePreprocessCond, Code_Invalid); }
    operator CodeSpecifiers    () const { return cast(CodeSpecifiers,     Code_Invalid); }
    operator CodeStruct        () const { return cast(CodeStruct,         Code_Invalid); }
    operator CodeTemplate      () const { return cast(CodeTemplate,       Code_Invalid); }
    operator CodeTypename      () const { return cast(CodeTypename,       Code_Invalid); }
    operator CodeTypedef       () const { return cast(CodeTypedef,        Code_Invalid); }
    operator CodeUnion         () const { return cast(CodeUnion,          Code_Invalid); }
    operator CodeUsing         () const { return cast(CodeUsing,          Code_Invalid); }
    operator CodeVar           () const { return cast(CodeVar,            Code_Invalid); }
};

struct NullCode_ImplicitCaster
{
    operator Code              () const { return {nullptr}; }
    operator CodeBody          () const { return {(AST_Body*)      nullptr}; }
    operator CodeAttributes    () const { return {(AST_Attributes*)nullptr}; }
    operator CodeComment       () const { return {nullptr}; }
    operator CodeClass         () const { return {nullptr}; }
    operator CodeConstructor   () const { return {nullptr}; }
    operator CodeDefine        () const { return {nullptr}; }
    operator CodeDefineParams  () const { return {nullptr}; }
    operator CodeDestructor    () const { return {nullptr}; }
    operator CodeExec          () const { return {nullptr}; }
    operator CodeEnum          () const { return {nullptr}; }
    operator CodeExtern        () const { return {nullptr}; }
    operator CodeInclude       () const { return {nullptr}; }
    operator CodeFriend        () const { return {nullptr}; }
    operator CodeFn            () const { return {nullptr}; }
    operator CodeModule        () const { return {nullptr}; }
    operator CodeNS            () const { return {nullptr}; }
    operator CodeOperator      () const { return {nullptr}; }
    operator CodeOpCast        () const { return {nullptr}; }
    operator CodeParams        () const { return {nullptr}; }
    operator CodePragma        () const { return {nullptr}; }
    operator CodePreprocessCond() const { return {nullptr}; }
    operator CodeSpecifiers    () const { return {nullptr}; }
    operator CodeStruct        () const { return {nullptr}; }
    operator CodeTemplate      () const { return {nullptr}; }
    operator CodeTypename      () const { return CodeTypename{(AST_Typename*)nullptr}; }
    operator CodeTypedef       () const { return {nullptr}; }
    operator CodeUnion         () const { return {nullptr}; }
    operator CodeUsing         () const { return {nullptr}; }
    operator CodeVar           () const { return {nullptr}; }
};

FORCEINLINE Code begin( CodeBody body)                   { return begin_CodeBody(body); }
FORCEINLINE Code end  ( CodeBody body )                  { return end_CodeBody(body); }
FORCEINLINE Code next ( CodeBody body, Code entry_iter ) { return next_CodeBody(body, entry_iter); }

FORCEINLINE CodeParams begin(CodeParams params)                        { return begin_CodeParams(params); }
FORCEINLINE CodeParams end  (CodeParams params)                        { return end_CodeParams(params); }
FORCEINLINE CodeParams next (CodeParams params, CodeParams entry_iter) { return next_CodeParams(params, entry_iter); }

FORCEINLINE Specifier* begin(CodeSpecifiers specifiers)                       { return begin_CodeSpecifiers(specifiers); }
FORCEINLINE Specifier* end  (CodeSpecifiers specifiers)                       { return end_CodeSpecifiers(specifiers); }
FORCEINLINE Specifier* next (CodeSpecifiers specifiers, Specifier& spec_iter) { return next_CodeSpecifiers(specifiers, & spec_iter); }

#if ! GEN_C_LIKE_CPP
GEN_OPTIMIZE_MAPPINGS_BEGIN

FORCEINLINE void       append              ( CodeBody body, Code     other )     { return body_append(body, other); }
FORCEINLINE void       append              ( CodeBody body, CodeBody other )     { return body_append_body(body, other); }
FORCEINLINE StrBuilder to_strbuilder       ( CodeBody body )                     { return body_to_strbuilder(body); }
FORCEINLINE void       to_strbuilder       ( CodeBody body, StrBuilder& result ) { return body_to_strbuilder_ref(body, & result); }
FORCEINLINE void       to_strbuilder_export( CodeBody body, StrBuilder& result ) { return body_to_strbuilder_export(body, & result); }

FORCEINLINE void       add_interface    ( CodeClass self, CodeTypename interface ) { return class_add_interface(self, interface); }
FORCEINLINE StrBuilder to_strbuilder    ( CodeClass self )                         { return class_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder_def( CodeClass self, StrBuilder& result )     { return class_to_strbuilder_def(self, & result); }
FORCEINLINE void       to_strbuilder_fwd( CodeClass self, StrBuilder& result )     { return class_to_strbuilder_fwd(self, & result); }

FORCEINLINE void             append       (CodeDefineParams appendee, CodeDefineParams other ) {        params_append(cast(CodeParams, appendee), cast(CodeParams, other)); }
FORCEINLINE CodeDefineParams get          (CodeDefineParams params, s32 idx)                   { return (CodeDefineParams) (Code) params_get(cast(CodeParams, params), idx); }
FORCEINLINE bool             has_entries  (CodeDefineParams params )                           { return params_has_entries(cast(CodeParams, params)); }
FORCEINLINE StrBuilder       to_strbuilder(CodeDefineParams params )                           { return define_params_to_strbuilder(params); }
FORCEINLINE void             to_strbuilder(CodeDefineParams params, StrBuilder& result )       { return define_params_to_strbuilder_ref(params, & result); }

FORCEINLINE void       append       (CodeParams appendee, CodeParams other )   { return params_append(appendee, other); }
FORCEINLINE CodeParams get          (CodeParams params, s32 idx)               { return params_get(params, idx); }
FORCEINLINE bool       has_entries  (CodeParams params )                       { return params_has_entries(params); }
FORCEINLINE StrBuilder to_strbuilder(CodeParams params )                       { return params_to_strbuilder(params); }
FORCEINLINE void       to_strbuilder(CodeParams params, StrBuilder& result )   { return params_to_strbuilder_ref(params, & result); }
  
FORCEINLINE bool       append       (CodeSpecifiers specifiers, Specifier spec)       { return specifiers_append(specifiers, spec); }
FORCEINLINE s32        has          (CodeSpecifiers specifiers, Specifier spec)       { return specifiers_has(specifiers, spec); }
FORCEINLINE s32        remove       (CodeSpecifiers specifiers, Specifier to_remove ) { return specifiers_remove(specifiers, to_remove); }
FORCEINLINE StrBuilder to_strbuilder(CodeSpecifiers specifiers)                       { return specifiers_to_strbuilder(specifiers); }
FORCEINLINE void       to_strbuilder(CodeSpecifiers specifiers, StrBuilder& result)   { return specifiers_to_strbuilder_ref(specifiers, & result);  }

FORCEINLINE void       add_interface    (CodeStruct self, CodeTypename interface) { return struct_add_interface(self, interface); }
FORCEINLINE StrBuilder to_strbuilder    (CodeStruct self)                         { return struct_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder_fwd(CodeStruct self, StrBuilder& result)     { return struct_to_strbuilder_fwd(self, & result); }
FORCEINLINE void       to_strbuilder_def(CodeStruct self, StrBuilder& result)     { return struct_to_strbuilder_def(self, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeAttributes attributes)                     { return attributes_to_strbuilder(attributes); }
FORCEINLINE void       to_strbuilder(CodeAttributes attributes, StrBuilder& result) { return attributes_to_strbuilder_ref(attributes, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeComment comment )                      { return comment_to_strbuilder(comment); }
FORCEINLINE void       to_strbuilder(CodeComment comment, StrBuilder& result )  { return comment_to_strbuilder_ref(comment, & result); }

FORCEINLINE StrBuilder to_strbuilder    (CodeConstructor constructor)                      { return constructor_to_strbuilder(constructor); }
FORCEINLINE void       to_strbuilder_def(CodeConstructor constructor, StrBuilder& result ) { return constructor_to_strbuilder_def(constructor, & result); }
FORCEINLINE void       to_strbuilder_fwd(CodeConstructor constructor, StrBuilder& result ) { return constructor_to_strbuilder_fwd(constructor, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeDefine self)                     { return define_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder(CodeDefine self, StrBuilder& result) { return define_to_strbuilder_ref(self, & result); }

FORCEINLINE StrBuilder to_strbuilder    (CodeDestructor destructor)                      { return destructor_to_strbuilder(destructor); }
FORCEINLINE void       to_strbuilder_def(CodeDestructor destructor, StrBuilder& result ) { return destructor_to_strbuilder_def(destructor, & result); }
FORCEINLINE void       to_strbuilder_fwd(CodeDestructor destructor, StrBuilder& result ) { return destructor_to_strbuilder_fwd(destructor, & result); }

FORCEINLINE StrBuilder to_strbuilder          (CodeEnum self)                      { return enum_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder_def      (CodeEnum self, StrBuilder& result ) { return enum_to_strbuilder_def(self, & result); }
FORCEINLINE void       to_strbuilder_fwd      (CodeEnum self, StrBuilder& result ) { return enum_to_strbuilder_fwd(self, & result); }
FORCEINLINE void       to_strbuilder_class_def(CodeEnum self, StrBuilder& result ) { return enum_to_strbuilder_class_def(self, & result); }
FORCEINLINE void       to_strbuilder_class_fwd(CodeEnum self, StrBuilder& result ) { return enum_to_strbuilder_class_fwd(self, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeExec exec)                     { return exec_to_strbuilder(exec); }
FORCEINLINE void       to_strbuilder(CodeExec exec, StrBuilder& result) { return exec_to_strbuilder_ref(exec, & result); }

FORCEINLINE void to_strbuilder(CodeExtern self, StrBuilder& result) { return extern_to_strbuilder(self, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeInclude self)                     { return include_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder(CodeInclude self, StrBuilder& result) { return include_to_strbuilder_ref(self, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeFriend self)                     { return friend_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder(CodeFriend self, StrBuilder& result) { return friend_to_strbuilder_ref(self, & result); }

FORCEINLINE StrBuilder to_strbuilder    (CodeFn self)                     { return fn_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder_def(CodeFn self, StrBuilder& result) { return fn_to_strbuilder_def(self, & result); }
FORCEINLINE void       to_strbuilder_fwd(CodeFn self, StrBuilder& result) { return fn_to_strbuilder_fwd(self, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeModule self)                     { return module_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder(CodeModule self, StrBuilder& result) { return module_to_strbuilder_ref(self, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeNS self)                     { return namespace_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder(CodeNS self, StrBuilder& result) { return namespace_to_strbuilder_ref(self,  & result); }

FORCEINLINE StrBuilder to_strbuilder    (CodeOperator self)                      { return code_op_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder_fwd(CodeOperator self, StrBuilder& result ) { return code_op_to_strbuilder_fwd(self, & result); }
FORCEINLINE void       to_strbuilder_def(CodeOperator self, StrBuilder& result ) { return code_op_to_strbuilder_def(self, & result); }

FORCEINLINE StrBuilder to_strbuilder    (CodeOpCast op_cast )                     { return opcast_to_strbuilder(op_cast); }
FORCEINLINE void       to_strbuilder_def(CodeOpCast op_cast, StrBuilder& result ) { return opcast_to_strbuilder_def(op_cast, & result); }
FORCEINLINE void       to_strbuilder_fwd(CodeOpCast op_cast, StrBuilder& result ) { return opcast_to_strbuilder_fwd(op_cast, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodePragma self)                     { return pragma_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder(CodePragma self, StrBuilder& result) { return pragma_to_strbuilder_ref(self, & result); }

FORCEINLINE StrBuilder to_strbuilder       (CodePreprocessCond cond)                      { return preprocess_to_strbuilder(cond); }
FORCEINLINE void       to_strbuilder_if    (CodePreprocessCond cond, StrBuilder& result ) { return preprocess_to_strbuilder_if(cond, & result); }
FORCEINLINE void       to_strbuilder_ifdef (CodePreprocessCond cond, StrBuilder& result ) { return preprocess_to_strbuilder_ifdef(cond, & result); }
FORCEINLINE void       to_strbuilder_ifndef(CodePreprocessCond cond, StrBuilder& result ) { return preprocess_to_strbuilder_ifndef(cond, & result); }
FORCEINLINE void       to_strbuilder_elif  (CodePreprocessCond cond, StrBuilder& result ) { return preprocess_to_strbuilder_elif(cond, & result); }
FORCEINLINE void       to_strbuilder_else  (CodePreprocessCond cond, StrBuilder& result ) { return preprocess_to_strbuilder_else(cond, & result); }
FORCEINLINE void       to_strbuilder_endif (CodePreprocessCond cond, StrBuilder& result ) { return preprocess_to_strbuilder_endif(cond, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeTemplate self)                     { return template_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder(CodeTemplate self, StrBuilder& result) { return template_to_strbuilder_ref(self, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeTypename self)                     { return typename_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder(CodeTypename self, StrBuilder& result) { return typename_to_strbuilder_ref(self, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeTypedef self)                      { return typedef_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder(CodeTypedef self, StrBuilder& result ) { return typedef_to_strbuilder_ref(self, & result); }

FORCEINLINE StrBuilder to_strbuilder    (CodeUnion self)                     { return union_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder_def(CodeUnion self, StrBuilder& result) { return union_to_strbuilder_def(self, & result); }
FORCEINLINE void       to_strbuilder_fwd(CodeUnion self, StrBuilder& result) { return union_to_strbuilder_fwd(self, & result); }

FORCEINLINE StrBuilder to_strbuilder   (CodeUsing op_cast )                     { return using_to_strbuilder(op_cast); }
FORCEINLINE void       to_strbuilder   (CodeUsing op_cast, StrBuilder& result ) { return using_to_strbuilder_ref(op_cast, & result); }
FORCEINLINE void       to_strbuilder_ns(CodeUsing op_cast, StrBuilder& result ) { return using_to_strbuilder_ns(op_cast, & result); }

FORCEINLINE StrBuilder to_strbuilder(CodeVar self)                     { return var_to_strbuilder(self); }
FORCEINLINE void       to_strbuilder(CodeVar self, StrBuilder& result) { return var_to_strbuilder_ref(self, & result); }

GEN_OPITMIZE_MAPPINGS_END
#endif //if GEN_C_LIKE_CPP

#pragma endregion Code Types C++
#endif //if GEN_COMPILER_CPP

#pragma region AST Types

/*
  ______   ______  ________      ________
 /      \ /      \|        \    |        \
|  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\\▓▓▓▓▓▓▓▓     \▓▓▓▓▓▓▓▓__    __  ______   ______   _______
| ▓▓__| ▓▓ ▓▓___\▓▓  | ▓▓          | ▓▓  |  \  |  \/      \ /      \ /       \
| ▓▓    ▓▓\▓▓    \   | ▓▓          | ▓▓  | ▓▓  | ▓▓  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\  ▓▓▓▓▓▓▓
| ▓▓▓▓▓▓▓▓_\▓▓▓▓▓▓\  | ▓▓          | ▓▓  | ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓    ▓▓\▓▓    \
| ▓▓  | ▓▓  \__| ▓▓  | ▓▓          | ▓▓  | ▓▓__/ ▓▓ ▓▓__/ ▓▓ ▓▓▓▓▓▓▓▓_\▓▓▓▓▓▓\
| ▓▓  | ▓▓\▓▓    ▓▓  | ▓▓          | ▓▓   \▓▓    ▓▓ ▓▓    ▓▓\▓▓     \       ▓▓
 \▓▓   \▓▓ \▓▓▓▓▓▓    \▓▓           \▓▓   _\▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓  \▓▓▓▓▓▓▓\▓▓▓▓▓▓▓
                                         |  \__| ▓▓ ▓▓
                                          \▓▓    ▓▓ ▓▓
                                           \▓▓▓▓▓▓ \▓▓
*/

/*
	Show only relevant members of the AST for its type.
	AST* fields are replaced with Code types.
		- Guards assignemnts to AST* fields to ensure the AST is duplicated if assigned to another parent.
*/

struct AST_Body
{
	union {
		char  _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached Name;
	Code      Front;
	Code      Back;
	Token*    Tok;
	Code      Parent;
	CodeType  Type;
	char      _PAD_UNUSED_[ sizeof(ModuleFlag) ];
	s32       NumEntries;
};
static_assert( sizeof(AST_Body) == sizeof(AST), "ERROR: AST_Body is not the same size as AST");

// TODO(Ed): Support chaining attributes (Use parameter linkage pattern)
struct AST_Attributes
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		StrCached     Content;
	};
	StrCached         Name;
	Code              Prev;
	Code              Next;
	Token*            Tok;
	Code              Parent;
	CodeType          Type;
	char              _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Attributes) == sizeof(AST), "ERROR: AST_Attributes is not the same size as AST");

#if 0
struct AST_BaseClass
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached         Name;
	Code              Prev;
	Code              Next;
	Token*            Tok;
	Code              Parent;
	CodeType          Type;
	char              _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_BaseClass) == sizeof(AST), "ERROR: AST_BaseClass is not the same size as AST");
#endif

struct AST_Comment
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		StrCached  Content;
	};
	StrCached         Name;
	Code              Prev;
	Code              Next;
	Token*            Tok;
	Code              Parent;
	CodeType          Type;
	char              _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Comment) == sizeof(AST), "ERROR: AST_Comment is not the same size as AST");

struct AST_Class
{
	union {
		char                _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment     InlineCmt; // Only supported by forward declarations
			CodeAttributes  Attributes;
			CodeSpecifiers  Specs; // Support for final
			CodeTypename    ParentType;
			char            _PAD_PARAMS_[ sizeof(AST*) ];
			CodeBody        Body;
			char            _PAD_PROPERTIES_2_[ sizeof(AST*) ];
		};
	};
	StrCached               Name;
	CodeTypename            Prev;
	CodeTypename            Next;
	Token*                  Tok;
	Code                    Parent;
	CodeType                Type;
	ModuleFlag              ModuleFlags;
	AccessSpec              ParentAccess;
};
static_assert( sizeof(AST_Class) == sizeof(AST), "ERROR: AST_Class is not the same size as AST");

struct AST_Constructor
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment    InlineCmt; // Only supported by forward declarations
			char           _PAD_PROPERTIES_ [ sizeof(AST*) * 1 ];
			CodeSpecifiers Specs;
			Code           InitializerList;
			CodeParams     Params;
			Code           Body;
			char           _PAD_PROPERTIES_2_ [ sizeof(AST*) * 2 ];
		};
	};
	StrCached         Name;
	Code              Prev;
	Code              Next;
	Token*            Tok;
	Code              Parent;
	CodeType          Type;
	char              _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Constructor) == sizeof(AST), "ERROR: AST_Constructor is not the same size as AST");

struct AST_Define
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			char              _PAD_PROPERTIES_ [ sizeof(AST*) * 4 ];
			CodeDefineParams  Params;
			Code              Body; // Should be completely serialized for now to a: StrCached Content.
			char              _PAD_PROPERTIES_2_ [ sizeof(AST*) * 1 ];
		};
	};
	StrCached Name;
	Code      Prev;
	Code      Next;
	Token*    Tok;
	Code      Parent;
	CodeType  Type;
	char      _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Define) == sizeof(AST), "ERROR: AST_Define is not the same size as AST");

struct AST_DefineParams
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached         Name;
	CodeDefineParams  Last;
	CodeDefineParams  Next;
	Token*            Tok;
	Code              Parent;
	CodeType          Type;
	char              _PAD_UNUSED_[ sizeof(ModuleFlag) ];
	s32               NumEntries;
};
static_assert( sizeof(AST_DefineParams) == sizeof(AST), "ERROR: AST_DefineParams is not the same size as AST");

struct AST_Destructor
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment    InlineCmt;
			char           _PAD_PROPERTIES_ [ sizeof(AST*) * 1 ];
			CodeSpecifiers Specs;
			char           _PAD_PROPERTIES_2_ [ sizeof(AST*) * 2 ];
			Code           Body;
			char           _PAD_PROPERTIES_3_ [ sizeof(AST*) ];
		};
	};
	StrCached              Name;
	Code                   Prev;
	Code                   Next;
	Token*                 Tok;
	Code                   Parent;
	CodeType               Type;
	char                   _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Destructor) == sizeof(AST), "ERROR: AST_Destructor is not the same size as AST");

struct AST_Enum
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment    InlineCmt;
			CodeAttributes Attributes;
			char           _PAD_SPEC_  [ sizeof(AST*) ];
			CodeTypename   UnderlyingType;
			Code           UnderlyingTypeMacro;
			CodeBody       Body;
			char           _PAD_PROPERTIES_2_[ sizeof(AST*) ];
		};
	};
	StrCached              Name;
	Code                   Prev;
	Code                   Next;
	Token*                 Tok;
	Code                   Parent;
	CodeType               Type;
	ModuleFlag             ModuleFlags;
	char                   _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Enum) == sizeof(AST), "ERROR: AST_Enum is not the same size as AST");

struct AST_Exec
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		StrCached  Content;
	};
	StrCached         Name;
	Code              Prev;
	Code              Next;
	Token*            Tok;
	Code              Parent;
	CodeType          Type;
	char              _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Exec) == sizeof(AST), "ERROR: AST_Exec is not the same size as AST");

#ifdef GEN_EXECUTION_EXPRESSION_SUPPORT
struct AST_Expr
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr) == sizeof(AST), "ERROR: AST_Expr is not the same size as AST");

struct AST_Expr_Assign
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_Assign) == sizeof(AST), "ERROR: AST_Expr_Assign is not the same size as AST");

struct AST_Expr_Alignof
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_Alignof) == sizeof(AST), "ERROR: AST_Expr_Alignof is not the same size as AST");

struct AST_Expr_Binary
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_Binary) == sizeof(AST), "ERROR: AST_Expr_Binary is not the same size as AST");

struct AST_Expr_CStyleCast
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_CStyleCast) == sizeof(AST), "ERROR: AST_Expr_CStyleCast is not the same size as AST");

struct AST_Expr_FunctionalCast
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_FunctionalCast) == sizeof(AST), "ERROR: AST_Expr_FunctionalCast is not the same size as AST");

struct AST_Expr_CppCast
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_CppCast) == sizeof(AST), "ERROR: AST_Expr_CppCast is not the same size as AST");

struct AST_Expr_ProcCall
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_ProcCall) == sizeof(AST), "ERROR: AST_Expr_Identifier is not the same size as AST");

struct AST_Expr_Decltype
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_Decltype) == sizeof(AST), "ERROR: AST_Expr_Decltype is not the same size as AST");

struct AST_Expr_Comma
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_Comma) == sizeof(AST), "ERROR: AST_Expr_Comma is not the same size as AST");

struct AST_Expr_AMS
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_AMS) == sizeof(AST), "ERROR: AST_Expr_AMS is not the same size as AST");

struct AST_Expr_Sizeof
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_Sizeof) == sizeof(AST), "ERROR: AST_Expr_Sizeof is not the same size as AST");

struct AST_Expr_Subscript
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_Subscript) == sizeof(AST), "ERROR: AST_Expr_Subscript is not the same size as AST");

struct AST_Expr_Ternary
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_Ternary) == sizeof(AST), "ERROR: AST_Expr_Ternary is not the same size as AST");

struct AST_Expr_UnaryPrefix
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_UnaryPrefix) == sizeof(AST), "ERROR: AST_Expr_UnaryPrefix is not the same size as AST");

struct AST_Expr_UnaryPostfix
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_UnaryPostfix) == sizeof(AST), "ERROR: AST_Expr_UnaryPostfix is not the same size as AST");

struct AST_Expr_Element
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached   Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Expr_Element) == sizeof(AST), "ERROR: AST_Expr_Element is not the same size as AST");
#endif

struct AST_Extern
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			char      _PAD_PROPERTIES_[ sizeof(AST*) * 5 ];
			CodeBody  Body;
			char      _PAD_PROPERTIES_2_[ sizeof(AST*) ];
		};
	};
	StrCached         Name;
	Code              Prev;
	Code              Next;
	Token*            Tok;
	Code              Parent;
	CodeType          Type;
	char              _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Extern) == sizeof(AST), "ERROR: AST_Extern is not the same size as AST");

struct AST_Include
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		StrCached  Content;
	};
	StrCached Name;
	Code      Prev;
	Code      Next;
	Token*    Tok;
	Code      Parent;
	CodeType  Type;
	char      _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Include) == sizeof(AST), "ERROR: AST_Include is not the same size as AST");

struct AST_Friend
{
	union {
		char            _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment InlineCmt;
			char        _PAD_PROPERTIES_[ sizeof(AST*) * 4 ];
			Code        Declaration;
			char        _PAD_PROPERTIES_2_[ sizeof(AST*) ];
		};
	};
	StrCached Name;
	Code      Prev;
	Code      Next;
	Token*    Tok;
	Code      Parent;
	CodeType  Type;
	char      _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Friend) == sizeof(AST), "ERROR: AST_Friend is not the same size as AST");

struct AST_Fn
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment     InlineCmt;
			CodeAttributes  Attributes;
			CodeSpecifiers  Specs;
			CodeTypename    ReturnType;
			CodeParams      Params;
			CodeBody        Body;
			Code            SuffixSpecs;  // Thanks Unreal
		};
	};
	StrCached  Name;
	Code       Prev;
	Code       Next;
	Token*     Tok;
	Code       Parent;
	CodeType   Type;
	ModuleFlag ModuleFlags;
	char       _PAD_UNUSED_[ sizeof(u32) ];
};
static_assert( sizeof(AST_Fn) == sizeof(AST), "ERROR: AST_Fn is not the same size as AST");

struct AST_Module
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached         Name;
	Code              Prev;
	Code              Next;
	Token*            Tok;
	Code              Parent;
	CodeType          Type;
	ModuleFlag        ModuleFlags;
	char             _PAD_UNUSED_[ sizeof(u32) ];
};
static_assert( sizeof(AST_Module) == sizeof(AST), "ERROR: AST_Module is not the same size as AST");

struct AST_NS
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct {
			char      _PAD_PROPERTIES_[ sizeof(AST*) * 5 ];
			CodeBody  Body;
			char      _PAD_PROPERTIES_2_[ sizeof(AST*) ];
		};
	};
	StrCached  Name;
	Code       Prev;
	Code       Next;
	Token*     Tok;
	Code       Parent;
	CodeType   Type;
	ModuleFlag ModuleFlags;
	char       _PAD_UNUSED_[ sizeof(u32) ];
};
static_assert( sizeof(AST_NS) == sizeof(AST), "ERROR: AST_NS is not the same size as AST");

struct AST_Operator
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment    InlineCmt;
			CodeAttributes Attributes;
			CodeSpecifiers Specs;
			CodeTypename   ReturnType;
			CodeParams 	   Params;
			CodeBody       Body;
			char           _PAD_PROPERTIES_ [ sizeof(AST*) ];
		};
	};
	StrCached  Name;
	Code       Prev;
	Code       Next;
	Token*     Tok;
	Code       Parent;
	CodeType   Type;
	ModuleFlag ModuleFlags;
	Operator   Op;
};
static_assert( sizeof(AST_Operator) == sizeof(AST), "ERROR: AST_Operator is not the same size as AST");

struct AST_OpCast
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment    InlineCmt;
			char           _PAD_PROPERTIES_[ sizeof(AST*)  ];
			CodeSpecifiers Specs;
			CodeTypename   ValueType;
			char           _PAD_PROPERTIES_2_[ sizeof(AST*) ];
			CodeBody       Body;
			char           _PAD_PROPERTIES_3_[ sizeof(AST*) ];
		};
	};
	StrCached Name;
	Code      Prev;
	Code      Next;
	Token*    Tok;
	Code      Parent;
	CodeType  Type;
	char      _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_OpCast) == sizeof(AST), "ERROR: AST_OpCast is not the same size as AST");

struct AST_Params
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			// TODO(Ed): Support attributes for parameters (Some prefix macros can be converted to that...)
			char         _PAD_PROPERTIES_2_[ sizeof(AST*) * 3 ];
			CodeTypename ValueType;
			Code         Macro;
			Code         Value;
			Code         PostNameMacro; // Thanks Unreal
			// char     _PAD_PROPERTIES_3_[sizeof( AST* )];
		};
	};
	StrCached  Name;
	CodeParams Last;
	CodeParams Next;
	Token*     Tok;
	Code       Parent;
	CodeType   Type;
	char       _PAD_UNUSED_[ sizeof(ModuleFlag) ];
	s32        NumEntries;
};
static_assert( sizeof(AST_Params) == sizeof(AST), "ERROR: AST_Params is not the same size as AST");

struct AST_Pragma
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		StrCached  Content;
	};
	StrCached Name;
	Code      Prev;
	Code      Next;
	Token*    Tok;
	Code      Parent;
	CodeType  Type;
	char      _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Pragma) == sizeof(AST), "ERROR: AST_Pragma is not the same size as AST");

struct AST_PreprocessCond
{
	union {
		char          _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		StrCached     Content;
	};
	StrCached Name;
	Code      Prev;
	Code      Next;
	Token*    Tok;
	Code      Parent;
	CodeType  Type;
	char      _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_PreprocessCond) == sizeof(AST), "ERROR: AST_PreprocessCond is not the same size as AST");

struct AST_Specifiers
{
	Specifier      ArrSpecs[ AST_ArrSpecs_Cap ];
	StrCached      Name;
	CodeSpecifiers NextSpecs;
	Code           Prev;
	Code           Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) ];
	s32            NumEntries;
};
static_assert( sizeof(AST_Specifiers) == sizeof(AST), "ERROR: AST_Specifier is not the same size as AST");

#ifdef GEN_EXECUTION_EXPRESSION_SUPPORT
struct AST_Stmt
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt) == sizeof(AST), "ERROR: AST_Stmt is not the same size as AST");

struct AST_Stmt_Break
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_Break) == sizeof(AST), "ERROR: AST_Stmt_Break is not the same size as AST");

struct AST_Stmt_Case
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_Case) == sizeof(AST), "ERROR: AST_Stmt_Case is not the same size as AST");

struct AST_Stmt_Continue
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_Continue) == sizeof(AST), "ERROR: AST_Stmt_Continue is not the same size as AST");

struct AST_Stmt_Decl
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_Decl) == sizeof(AST), "ERROR: AST_Stmt_Decl is not the same size as AST");

struct AST_Stmt_Do
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_Do) == sizeof(AST), "ERROR: AST_Stmt_Do is not the same size as AST");

struct AST_Stmt_Expr
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_Expr) == sizeof(AST), "ERROR: AST_Stmt_Expr is not the same size as AST");

struct AST_Stmt_Else
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_Else) == sizeof(AST), "ERROR: AST_Stmt_Else is not the same size as AST");

struct AST_Stmt_If
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_If) == sizeof(AST), "ERROR: AST_Stmt_If is not the same size as AST");

struct AST_Stmt_For
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_For) == sizeof(AST), "ERROR: AST_Stmt_For is not the same size as AST");

struct AST_Stmt_Goto
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_Goto) == sizeof(AST), "ERROR: AST_Stmt_Goto is not the same size as AST");

struct AST_Stmt_Label
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_Label) == sizeof(AST), "ERROR: AST_Stmt_Label is not the same size as AST");

struct AST_Stmt_Switch
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_Switch) == sizeof(AST), "ERROR: AST_Stmt_Switch is not the same size as AST");

struct AST_Stmt_While
{
	union {
		char _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
	};
	StrCached      Name;
	CodeExpr       Prev;
	CodeExpr       Next;
	Token*         Tok;
	Code           Parent;
	CodeType       Type;
	char           _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_Stmt_While) == sizeof(AST), "ERROR: AST_Stmt_While is not the same size as AST");
#endif

struct AST_Struct
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment    InlineCmt;
			CodeAttributes Attributes;
			CodeSpecifiers Specs; // Support for final
			CodeTypename   ParentType;
			char           _PAD_PARAMS_[ sizeof(AST*) ];
			CodeBody       Body;
			char          _PAD_PROPERTIES_2_[ sizeof(AST*) ];
		};
	};
	StrCached              Name;
	CodeTypename           Prev;
	CodeTypename           Next;
	Token*                 Tok;
	Code                   Parent;
	CodeType               Type;
	ModuleFlag             ModuleFlags;
	AccessSpec             ParentAccess;
};
static_assert( sizeof(AST_Struct) == sizeof(AST), "ERROR: AST_Struct is not the same size as AST");

struct AST_Template
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			char           _PAD_PROPERTIES_[ sizeof(AST*) * 4 ];
			CodeParams 	   Params;
			Code           Declaration;
			char           _PAD_PROPERTIES_2_[ sizeof(AST*) ];
		};
	};
	StrCached  Name;
	Code       Prev;
	Code       Next;
	Token*     Tok;
	Code       Parent;
	CodeType   Type;
	ModuleFlag ModuleFlags;
	char       _PAD_UNUSED_[ sizeof(u32) ];
};
static_assert( sizeof(AST_Template) == sizeof(AST), "ERROR: AST_Template is not the same size as AST");

#if 0
// WIP... The type ast is going to become more advanced and lead to a major change to AST design.
struct AST_Type
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			char           _PAD_INLINE_CMT_[ sizeof(AST*) ];
			CodeAttributes  Attributes;
			CodeSpecifiers  Specs;
			Code            QualifierID;
			// CodeTypename ReturnType;      // Only used for function signatures
			// CodeParams    Params;          // Only used for function signatures
			Code            ArrExpr;
			// CodeSpecifiers SpecsFuncSuffix; // Only used for function signatures
		};
	};
	StrCached              Name;
	Code                   Prev;
	Code                   Next;
	Token*                 Tok;
	Code                   Parent;
	CodeType               Type;
	char                   _PAD_UNUSED_[ sizeof(ModuleFlag) ];
	b32                    IsParamPack;
};
static_assert( sizeof(AST_Type) == sizeof(AST), "ERROR: AST_Type is not the same size as AST");
#endif

struct AST_Typename
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			char           _PAD_INLINE_CMT_[ sizeof(AST*) ];
			CodeAttributes Attributes;
			CodeSpecifiers Specs;
			CodeTypename   ReturnType;      // Only used for function signatures
			CodeParams     Params;          // Only used for function signatures
			Code           ArrExpr;
			CodeSpecifiers SpecsFuncSuffix; // Only used for function signatures
		};
	};
	StrCached           Name;
	Code                   Prev;
	Code                   Next;
	Token*                 Tok;
	Code                   Parent;
	CodeType               Type;
	char                   _PAD_UNUSED_[ sizeof(ModuleFlag) ];
	struct {
		b16                IsParamPack;   // Used by typename to know if type should be considered a parameter pack.
		ETypenameTag       TypeTag;       // Used by typename to keep track of explicitly declared tags for the identifier (enum, struct, union)
	};
};
static_assert( sizeof(AST_Typename) == sizeof(AST), "ERROR: AST_Type is not the same size as AST");

struct AST_Typedef
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment    InlineCmt;
			char           _PAD_PROPERTIES_[ sizeof(AST*) * 2 ];
			Code           UnderlyingType;
			char           _PAD_PROPERTIES_2_[ sizeof(AST*) * 3 ];
		};
	};
	StrCached           Name;
	Code                   Prev;
	Code                   Next;
	Token*                 Tok;
	Code                   Parent;
	CodeType               Type;
	ModuleFlag             ModuleFlags;
	b32                    IsFunction;
};
static_assert( sizeof(AST_Typedef) == sizeof(AST), "ERROR: AST_Typedef is not the same size as AST");

struct AST_Union
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			char           _PAD_INLINE_CMT_[ sizeof(AST*) ];
			CodeAttributes Attributes;
			char           _PAD_PROPERTIES_[ sizeof(AST*) * 3 ];
			CodeBody       Body;
			char           _PAD_PROPERTIES_2_[ sizeof(AST*) ];
		};
	};
	StrCached  Name;
	Code       Prev;
	Code       Next;
	Token*     Tok;
	Code       Parent;
	CodeType   Type;
	ModuleFlag ModuleFlags;
	char       _PAD_UNUSED_[ sizeof(u32) ];
};
static_assert( sizeof(AST_Union) == sizeof(AST), "ERROR: AST_Union is not the same size as AST");

struct AST_Using
{
	union {
		char                _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment     InlineCmt;
			CodeAttributes  Attributes;
			char            _PAD_SPECS_     [ sizeof(AST*) ];
			CodeTypename    UnderlyingType;
			char            _PAD_PROPERTIES_[ sizeof(AST*) * 3 ];
		};
	};
	StrCached  Name;
	Code       Prev;
	Code       Next;
	Token*     Tok;
	Code       Parent;
	CodeType   Type;
	ModuleFlag ModuleFlags;
	char       _PAD_UNUSED_[ sizeof(u32) ];
};
static_assert( sizeof(AST_Using) == sizeof(AST), "ERROR: AST_Using is not the same size as AST");

struct AST_Var
{
	union {
		char               _PAD_[ sizeof(Specifier) * AST_ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			CodeComment    InlineCmt;
			CodeAttributes Attributes;
			CodeSpecifiers Specs;
			CodeTypename   ValueType;
			Code           BitfieldSize;
			Code           Value;
			CodeVar        NextVar;
		};
	};
	StrCached  Name;
	Code       Prev;
	Code       Next;
	Token*     Tok;
	Code       Parent;
	CodeType   Type;
	ModuleFlag ModuleFlags;
	s32        VarParenthesizedInit;
};
static_assert( sizeof(AST_Var) == sizeof(AST), "ERROR: AST_Var is not the same size as AST");

#pragma endregion AST Types

#pragma endregion AST

#pragma region Gen Interface
/*
 /      \                       |      \          |  \                      /      \
|  ▓▓▓▓▓▓\ ______  _______       \▓▓▓▓▓▓_______  _| ▓▓_    ______   ______ |  ▓▓▓▓▓▓\ ______   _______  ______
| ▓▓ __\▓▓/      \|       \       | ▓▓ |       \|   ▓▓ \  /      \ /      \| ▓▓_  \▓▓|      \ /       \/      \
| ▓▓|    \  ▓▓▓▓▓▓\ ▓▓▓▓▓▓▓\      | ▓▓ | ▓▓▓▓▓▓▓\\▓▓▓▓▓▓ |  ▓▓▓▓▓▓\  ▓▓▓▓▓▓\ ▓▓ \     \▓▓▓▓▓▓\  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓\
| ▓▓ \▓▓▓▓ ▓▓    ▓▓ ▓▓  | ▓▓      | ▓▓ | ▓▓  | ▓▓ | ▓▓ __| ▓▓    ▓▓ ▓▓   \▓▓ ▓▓▓▓    /      ▓▓ ▓▓     | ▓▓    ▓▓
| ▓▓__| ▓▓ ▓▓▓▓▓▓▓▓ ▓▓  | ▓▓     _| ▓▓_| ▓▓  | ▓▓ | ▓▓|  \ ▓▓▓▓▓▓▓▓ ▓▓     | ▓▓     |  ▓▓▓▓▓▓▓ ▓▓_____| ▓▓▓▓▓▓▓▓
 \▓▓    ▓▓\▓▓     \ ▓▓  | ▓▓    |   ▓▓ \ ▓▓  | ▓▓  \▓▓  ▓▓\▓▓     \ ▓▓     | ▓▓      \▓▓    ▓▓\▓▓     \\▓▓     \
  \▓▓▓▓▓▓  \▓▓▓▓▓▓▓\▓▓   \▓▓     \▓▓▓▓▓▓\▓▓   \▓▓   \▓▓▓▓  \▓▓▓▓▓▓▓\▓▓      \▓▓       \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓
*/

#if 0
enum LogLevel : u32
{
	Info,
	Warning,
	Panic,
};

struct LogEntry
{
	Str   msg;
	u32   line_num;
	void* data;
};

typedef void LoggerCallback(LogEntry entry);
#endif

// Note(Ed): This is subject to heavily change 
// with upcoming changes to the library's fallback (default) allocations strategy;
// and major changes to lexer/parser context usage.
struct Context
{
// User Configuration

// Persistent Data Allocation
	AllocatorInfo Allocator_DyanmicContainers; // By default will use a genral slab allocator (TODO(Ed): Currently does not)
	AllocatorInfo Allocator_Pool;              // By default will use the growing vmem reserve (TODO(Ed): Currently does not)
	AllocatorInfo Allocator_StrCache;          // By default will use a dedicated slab allocator (TODO(Ed): Currently does not)

// Temporary Allocation
	AllocatorInfo Allocator_Temp;

	// LoggerCallaback* log_callback; // TODO(Ed): Impl user logger callback as an option.

// Initalization config
	u32 Max_CommentLineLength; // Used by def_comment
	u32 Max_StrCacheLength;    // Any cached string longer than this is always allocated again.

	u32 InitSize_BuilderBuffer;
	u32 InitSize_CodePoolsArray;
	u32 InitSize_StringArenasArray;

	u32 CodePool_NumBlocks;

	// TODO(Ed): Review these... (No longer needed if using the proper allocation strategy)
	u32 InitSize_LexerTokens;
	u32 SizePer_StringArena;

// TODO(Ed): Symbol Table
	// Keep track of all resolved symbols (naemspaced identifiers)

// Parser

	// Used by the lexer to persistently treat all these identifiers as preprocessor defines.
	// Populate with strings via gen::cache_str.
	// Functional defines must have format: id( ;at minimum to indicate that the define is only valid with arguments.
	MacroTable Macros;

// Backend

	// The fallback allocator is utilized if any fo the three above allocators is not specified by the user.
	u32 InitSize_Fallback_Allocator_Bucket_Size;
	Array(Arena) Fallback_AllocatorBuckets;

	StringTable token_fmt_map;

	// Array(Token) LexerTokens;

	Array(Pool)  CodePools;
	Array(Arena) StringArenas;

	StringTable StrCache;

	// TODO(Ed): This needs to be just handled by a parser context
	Array(Token) Lexer_Tokens;

	// TODO(Ed): Active parse context vs a parse result need to be separated conceptually
	ParseContext parser;

	// TODO(Ed): Formatting - This will eventually be in a separate struct when in the process of serialization of the builder.
	s32 temp_serialize_indent;
};

// Initialize the library. There first ctx initialized must exist for lifetime of other contextes that come after as its the one that
GEN_API void init(Context* ctx);

// Currently manually free's the arenas, code for checking for leaks.
// However on Windows at least, it doesn't need to occur as the OS will clean up after the process.
GEN_API void deinit(Context* ctx);

// Retrieves the active context (not usually needed, but here in case...)
GEN_API Context* get_context();

// Clears the allocations, but doesn't free the memoery, then calls init() again.
// Ease of use.
GEN_API void reset(Context* ctx);

GEN_API void set_context(Context* ctx);

// Mostly intended for the parser
GEN_API Macro* lookup_macro( Str Name );

// Alternative way to add a preprocess define entry for the lexer & parser to utilize 
// if the user doesn't want to use def_define
// Macros are tracked by name so if the name already exists the entry will be overwritten.
GEN_API void register_macro( Macro macro );

// Ease of use batch registration
GEN_API void register_macros( s32 num, ... );
GEN_API void register_macros_arr( s32 num, Macro* macros );

#if GEN_COMPILER_CPP
FORCEINLINE void register_macros( s32 num, Macro* macros ) { return register_macros_arr(num, macros); }
#endif

// Used internally to retrive or make string allocations.
// Strings are stored in a series of string arenas of fixed size (SizePer_StringArena)
GEN_API StrCached cache_str( Str str );

/*
	This provides a fresh Code AST.
	The gen interface use this as their method from getting a new AST object from the CodePool.
	Use this if you want to make your own API for formatting the supported Code Types.
*/
GEN_API Code make_code();

// Set these before calling gen's init() procedure.

#pragma region Upfront

GEN_API CodeAttributes def_attributes( Str content );
GEN_API CodeComment    def_comment   ( Str content );

struct Opts_def_struct {
	CodeBody       body;
	CodeTypename   parent;
	AccessSpec     parent_access;
	CodeAttributes attributes;
	CodeTypename*  interfaces;
	s32            num_interfaces;
	CodeSpecifiers specifers; // Only used for final specifier for now.
	ModuleFlag     mflags;
};
GEN_API CodeClass def_class( Str name, Opts_def_struct opts GEN_PARAM_DEFAULT );

struct Opts_def_constructor {
	CodeParams params;
	Code      initializer_list;
	Code      body;
};
GEN_API CodeConstructor def_constructor( Opts_def_constructor opts GEN_PARAM_DEFAULT );

struct Opts_def_define {
	CodeDefineParams params;
	Str              content;
	MacroFlags       flags;
	b32              dont_register_to_preprocess_macros;
};
GEN_API CodeDefine def_define( Str name, MacroType type, Opts_def_define opts GEN_PARAM_DEFAULT );

struct Opts_def_destructor {
	Code           body;
	CodeSpecifiers specifiers;
};
GEN_API CodeDestructor def_destructor( Opts_def_destructor opts GEN_PARAM_DEFAULT );

struct Opts_def_enum {
	CodeBody       body;
	CodeTypename   type;
	EnumT          specifier;
	CodeAttributes attributes;
	ModuleFlag     mflags;
	Code           type_macro;
};
GEN_API CodeEnum def_enum( Str name, Opts_def_enum opts GEN_PARAM_DEFAULT );

GEN_API CodeExec   def_execution  ( Str content );
GEN_API CodeExtern def_extern_link( Str name, CodeBody body );
GEN_API CodeFriend def_friend     ( Code symbol );

struct Opts_def_function {
	CodeParams      params;
	CodeTypename    ret_type;
	CodeBody        body;
	CodeSpecifiers  specs;
	CodeAttributes  attrs;
	ModuleFlag      mflags;
};
GEN_API CodeFn def_function( Str name, Opts_def_function opts GEN_PARAM_DEFAULT );

struct Opts_def_include   { b32        foreign; };
struct Opts_def_module    { ModuleFlag mflags;  };
struct Opts_def_namespace { ModuleFlag mflags;  };
GEN_API CodeInclude def_include  ( Str content,             Opts_def_include   opts GEN_PARAM_DEFAULT );
GEN_API CodeModule  def_module   ( Str name,                Opts_def_module    opts GEN_PARAM_DEFAULT );
GEN_API CodeNS      def_namespace( Str name, CodeBody body, Opts_def_namespace opts GEN_PARAM_DEFAULT );

struct Opts_def_operator {
	CodeParams      params;
	CodeTypename    ret_type;
	CodeBody        body;
	CodeSpecifiers  specifiers;
	CodeAttributes  attributes;
	ModuleFlag      mflags;
};
GEN_API CodeOperator def_operator( Operator op, Str nspace, Opts_def_operator opts GEN_PARAM_DEFAULT );

struct Opts_def_operator_cast {
	CodeBody       body;
	CodeSpecifiers specs;
};
GEN_API CodeOpCast def_operator_cast( CodeTypename type, Opts_def_operator_cast opts GEN_PARAM_DEFAULT );

struct Opts_def_param { Code value; };
GEN_API CodeParams  def_param ( CodeTypename type, Str name, Opts_def_param opts GEN_PARAM_DEFAULT );
GEN_API CodePragma def_pragma( Str directive );

GEN_API CodePreprocessCond def_preprocess_cond( EPreprocessCond type, Str content );

GEN_API CodeSpecifiers def_specifier( Specifier specifier );

GEN_API CodeStruct def_struct( Str name, Opts_def_struct opts GEN_PARAM_DEFAULT );

struct Opts_def_template { ModuleFlag mflags; };
GEN_API CodeTemplate def_template( CodeParams params, Code definition, Opts_def_template opts GEN_PARAM_DEFAULT );

struct Opts_def_type {
	ETypenameTag   type_tag;
	Code           arrayexpr;
	CodeSpecifiers specifiers;
	CodeAttributes attributes;
};
GEN_API CodeTypename def_type( Str name, Opts_def_type opts GEN_PARAM_DEFAULT );

struct Opts_def_typedef {
	CodeAttributes attributes;
	ModuleFlag     mflags;
};
GEN_API CodeTypedef def_typedef( Str name, Code type, Opts_def_typedef opts GEN_PARAM_DEFAULT );

struct Opts_def_union {
	CodeAttributes attributes;
	ModuleFlag     mflags;
};
GEN_API CodeUnion def_union( Str name, CodeBody body, Opts_def_union opts GEN_PARAM_DEFAULT );

struct Opts_def_using {
	CodeAttributes attributes;
	ModuleFlag     mflags;
};
GEN_API CodeUsing def_using( Str name, CodeTypename type, Opts_def_using opts GEN_PARAM_DEFAULT );

GEN_API CodeUsing def_using_namespace( Str name );

struct Opts_def_variable
{
	Code           value;
	CodeSpecifiers specifiers;
	CodeAttributes attributes;
	ModuleFlag     mflags;
};
GEN_API CodeVar def_variable( CodeTypename type, Str name, Opts_def_variable opts GEN_PARAM_DEFAULT );

// Constructs an empty body. Use AST::validate_body() to check if the body is was has valid entries.
GEN_API CodeBody def_body( CodeType type );

// There are two options for defining a struct body, either varadically provided with the args macro to auto-deduce the arg num,
/// or provide as an array of Code objects.

GEN_API CodeBody         def_class_body           ( s32 num, ... );
GEN_API CodeBody         def_class_body_arr       ( s32 num, Code* codes );
GEN_API CodeDefineParams def_define_params        ( s32 num, ... );
GEN_API CodeDefineParams def_define_params_arr    ( s32 num, CodeDefineParams* codes );
GEN_API CodeBody         def_enum_body            ( s32 num, ... );
GEN_API CodeBody         def_enum_body_arr        ( s32 num, Code* codes );
GEN_API CodeBody         def_export_body          ( s32 num, ... );
GEN_API CodeBody         def_export_body_arr      ( s32 num, Code* codes);
GEN_API CodeBody         def_extern_link_body     ( s32 num, ... );
GEN_API CodeBody         def_extern_link_body_arr ( s32 num, Code* codes );
GEN_API CodeBody         def_function_body        ( s32 num, ... );
GEN_API CodeBody         def_function_body_arr    ( s32 num, Code* codes );
GEN_API CodeBody         def_global_body          ( s32 num, ... );
GEN_API CodeBody         def_global_body_arr      ( s32 num, Code* codes );
GEN_API CodeBody         def_namespace_body       ( s32 num, ... );
GEN_API CodeBody         def_namespace_body_arr   ( s32 num, Code* codes );
GEN_API CodeParams       def_params               ( s32 num, ... );
GEN_API CodeParams       def_params_arr           ( s32 num, CodeParams* params );
GEN_API CodeSpecifiers   def_specifiers           ( s32 num, ... );
GEN_API CodeSpecifiers   def_specifiers_arr       ( s32 num, Specifier* specs );
GEN_API CodeBody         def_struct_body          ( s32 num, ... );
GEN_API CodeBody         def_struct_body_arr      ( s32 num, Code* codes );
GEN_API CodeBody         def_union_body           ( s32 num, ... );
GEN_API CodeBody         def_union_body_arr       ( s32 num, Code* codes );

#if GEN_COMPILER_CPP
FORCEINLINE CodeBody         def_class_body      ( s32 num, Code* codes )             { return def_class_body_arr(num, codes); }
FORCEINLINE CodeDefineParams def_define_params   ( s32 num, CodeDefineParams* codes ) { return def_define_params_arr(num, codes); }
FORCEINLINE CodeBody         def_enum_body       ( s32 num, Code* codes )             { return def_enum_body_arr(num, codes); }
FORCEINLINE CodeBody         def_export_body     ( s32 num, Code* codes)              { return def_export_body_arr(num, codes); }
FORCEINLINE CodeBody         def_extern_link_body( s32 num, Code* codes )             { return def_extern_link_body_arr(num, codes); }
FORCEINLINE CodeBody         def_function_body   ( s32 num, Code* codes )             { return def_function_body_arr(num, codes); }
FORCEINLINE CodeBody         def_global_body     ( s32 num, Code* codes )             { return def_global_body_arr(num, codes); }
FORCEINLINE CodeBody         def_namespace_body  ( s32 num, Code* codes )             { return def_namespace_body_arr(num, codes); }
FORCEINLINE CodeParams       def_params          ( s32 num, CodeParams* params )      { return def_params_arr(num, params); }
FORCEINLINE CodeSpecifiers   def_specifiers      ( s32 num, Specifier* specs )        { return def_specifiers_arr(num, specs); }
FORCEINLINE CodeBody         def_struct_body     ( s32 num, Code* codes )             { return def_struct_body_arr(num, codes); }
FORCEINLINE CodeBody         def_union_body      ( s32 num, Code* codes )             { return def_union_body_arr(num, codes); }
#endif

#pragma endregion Upfront

#pragma region Parsing

#if 0
struct StackNode
{
	StackNode* Prev;

	Token Start;
	Token Name;       // The name of the AST node (if parsed)
	Str  FailedProc; // The name of the procedure that failed
};
// Stack nodes are allocated the error's allocator

struct Error
{
	StrBuilder     message;
	StackNode* context_stack;
};

struct ParseInfo
{
	Arena FileMem;
	Arena TokMem;
	Arena CodeMem;

	FileContents FileContent;
	Array<Token> Tokens;
	Array<Error> Errors;
	// Errors are allocated to a dedicated general arena.
};

CodeBody parse_file( Str path );
#endif

GEN_API CodeClass       parse_class        ( Str class_def       );
GEN_API CodeConstructor parse_constructor  ( Str constructor_def );
GEN_API CodeDefine      parse_define       ( Str define_def      );
GEN_API CodeDestructor  parse_destructor   ( Str destructor_def  );
GEN_API CodeEnum        parse_enum         ( Str enum_def        );
GEN_API CodeBody        parse_export_body  ( Str export_def      );
GEN_API CodeExtern      parse_extern_link  ( Str exten_link_def  );
GEN_API CodeFriend      parse_friend       ( Str friend_def      );
GEN_API CodeFn          parse_function     ( Str fn_def          );
GEN_API CodeBody        parse_global_body  ( Str body_def        );
GEN_API CodeNS          parse_namespace    ( Str namespace_def   );
GEN_API CodeOperator    parse_operator     ( Str operator_def    );
GEN_API CodeOpCast      parse_operator_cast( Str operator_def    );
GEN_API CodeStruct      parse_struct       ( Str struct_def      );
GEN_API CodeTemplate    parse_template     ( Str template_def    );
GEN_API CodeTypename    parse_type         ( Str type_def        );
GEN_API CodeTypedef     parse_typedef      ( Str typedef_def     );
GEN_API CodeUnion       parse_union        ( Str union_def       );
GEN_API CodeUsing       parse_using        ( Str using_def       );
GEN_API CodeVar         parse_variable     ( Str var_def         );

#pragma endregion Parsing

#pragma region Untyped text

GEN_API ssize token_fmt_va( char* buf, usize buf_size, s32 num_tokens, va_list va );
//! Do not use directly. Use the token_fmt macro instead.
GEN_API Str token_fmt_impl( ssize, ... );

GEN_API Code untyped_str( Str content);
GEN_API Code untyped_fmt      ( char const* fmt, ... );
GEN_API Code untyped_token_fmt( s32 num_tokens, char const* fmt, ... );

#pragma endregion Untyped text

#pragma region Macros

#ifndef gen_main
#define gen_main main
#endif

#ifndef name
//	Convienence for defining any name used with the gen api.
//  Lets you provide the length and string literal to the functions without the need for the DSL.
#	if GEN_COMPILER_C
#		define name( Id_ ) (Str){ stringize(Id_), sizeof(stringize( Id_ )) - 1 }
#	else
#		define name( Id_ )  Str { stringize(Id_), sizeof(stringize( Id_ )) - 1 }
#	endif
#endif

#ifndef code
//  Same as name just used to indicate intention of literal for code instead of names.
#	if GEN_COMPILER_C
#		define code( ... ) (Str){ stringize( __VA_ARGS__ ), sizeof(stringize(__VA_ARGS__)) - 1 }
#	else
#		define code( ... )  Str { stringize( __VA_ARGS__ ), sizeof(stringize(__VA_ARGS__)) - 1 }
#	endif
#endif

#ifndef args
// Provides the number of arguments while passing args inplace.
#define args( ... ) num_args( __VA_ARGS__ ), __VA_ARGS__
#endif

#ifndef code_str
// Just wrappers over common untyped code definition constructions.
#define code_str( ... ) GEN_NS untyped_str( code( __VA_ARGS__ ) )
#endif

#ifndef code_fmt
#define code_fmt( ... ) GEN_NS untyped_str( token_fmt( __VA_ARGS__ ) )
#endif

#ifndef parse_fmt
#define parse_fmt( type, ... ) GEN_NS parse_##type( token_fmt( __VA_ARGS__ ) )
#endif

#ifndef token_fmt
/*
Takes a format string (char const*) and a list of tokens (Str) and returns a Str of the formatted string.
Tokens are provided in '<'identifier'>' format where '<' '>' are just angle brackets (you can change it in token_fmt_va)
---------------------------------------------------------
	Example - A string with:
		typedef <type> <name> <name>;
	Will have a token_fmt arguments populated with:
		"type", str_for_type,
		"name", str_for_name,
	and:
		stringize( typedef <type> <name> <name>; )
-----------------------------------------------------------
So the full call for this example would be:
	token_fmt(
		"type", str_for_type
	,	"name", str_for_name
	,	stringize(
		typedef <type> <name> <name>
	));
!----------------------------------------------------------
! Note: token_fmt_va is whitespace sensitive for the tokens.
! This can be alleviated by skipping whitespace between brackets but it was choosen to not have that implementation by default.
*/
#define token_fmt( ... ) GEN_NS token_fmt_impl( (num_args( __VA_ARGS__ ) + 1) / 2, __VA_ARGS__ )
#endif

#pragma endregion Macros

#pragma endregion Gen Interface

#pragma region Inlines

#pragma region Code
inline
void code_append( Code self, Code other )
{
	GEN_ASSERT(self);
	GEN_ASSERT(other);
	GEN_ASSERT_MSG(self != other, "Attempted to recursively append Code AST to itself.");

	if ( other->Parent != nullptr )
		other = code_duplicate(other);

	other->Parent = self;

	if ( self->Front == nullptr )
	{
		self->Front = other;
		self->Back  = other;

		self->NumEntries++;
		return;
	}

	Code
	Current       = self->Back;
	Current->Next = other;
	other->Prev   = Current;
	self->Back    = other;
	self->NumEntries++;
}
inline
bool code_is_body(Code self)
{
	GEN_ASSERT(self);
	switch (self->Type)
	{
		case CT_Enum_Body:
		case CT_Class_Body:
		case CT_Union_Body:
		case CT_Export_Body:
		case CT_Global_Body:
		case CT_Struct_Body:
		case CT_Function_Body:
		case CT_Namespace_Body:
		case CT_Extern_Linkage_Body:
			return true;
	}
	return false;
}
inline
Code* code_entry( Code self, u32 idx )
{
	GEN_ASSERT(self != nullptr);
	Code* current = & self->Front;
	while ( idx >= 0 && current != nullptr )
	{
		if ( idx == 0 )
			return rcast( Code*, current);

		current = & ( * current )->Next;
		idx--;
	}

	return rcast( Code*, current);
}
FORCEINLINE
bool code_is_valid(Code self)
{
	GEN_ASSERT(self);
	return self != nullptr && self->Type != CT_Invalid;
}
FORCEINLINE
bool code_has_entries(AST* self)
{
	GEN_ASSERT(self);
	return self->NumEntries > 0;
}
FORCEINLINE
void code_set_global(Code self)
{
	if ( self == nullptr )
	{
		log_failure("Code::set_global: Cannot set code as global, AST is null!");
		return;
	}

	self->Parent = Code_Global;
}
#if GEN_COMPILER_CPP
FORCEINLINE
Code& Code::operator ++()
{
	if ( ast )
		ast = ast->Next.ast;

	return * this;
}
#endif
FORCEINLINE
Str code_type_str(Code self)
{
	GEN_ASSERT(self != nullptr);
	return codetype_to_str( self->Type );
}
#pragma endregion Code

#pragma region CodeBody
inline
void body_append( CodeBody self, Code other )
{
	GEN_ASSERT(self);
	GEN_ASSERT(other);

	if (code_is_body(other)) {
		body_append_body( self, cast(CodeBody, other) );
		return;
	}

	code_append( cast(Code, self), other );
}
inline
void body_append_body( CodeBody self, CodeBody body )
{
	GEN_ASSERT(self);
	GEN_ASSERT(body);
	GEN_ASSERT_MSG(self != body, "Attempted to append body to itself.");

	for ( Code entry = begin_CodeBody(body); entry != end_CodeBody(body); entry = next_CodeBody(body, entry) ) {
		body_append( self, entry );
	}
}
inline
Code begin_CodeBody( CodeBody body) {
	GEN_ASSERT(body);
	if ( body != nullptr )
		return body->Front;

	return NullCode;
}
FORCEINLINE
Code end_CodeBody(CodeBody body ){
	GEN_ASSERT(body);
	return body->Back->Next;
}
inline
Code next_CodeBody(CodeBody body, Code entry) {
	GEN_ASSERT(body);
	GEN_ASSERT(entry);
	return entry->Next;
}
#pragma endregion CodeBody

#pragma region CodeClass
inline
void class_add_interface( CodeClass self, CodeTypename type )
{
	GEN_ASSERT(self);
	GEN_ASSERT(type);
	CodeTypename possible_slot = self->ParentType;
	if ( possible_slot != nullptr )
	{
		// Were adding an interface to parent type, so we need to make sure the parent type is public.
		self->ParentAccess = AccessSpec_Public;
		// If your planning on adding a proper parent,
		// then you'll need to move this over to ParentType->next and update ParentAccess accordingly.
	}

	while ( possible_slot != nullptr )
	{
		possible_slot = cast(CodeTypename, possible_slot->Next);
	}

	possible_slot = type;
}
#pragma endregion CodeClass

#pragma region CodeParams
inline
void params_append( CodeParams appendee, CodeParams other )
{
	GEN_ASSERT(appendee);
	GEN_ASSERT(other);
	GEN_ASSERT_MSG(appendee != other, "Attempted to append parameter to itself.");
	Code self  = cast(Code, appendee);
	Code entry = cast(Code, other);

	if ( entry->Parent != nullptr )
		entry = code_duplicate( entry );

	entry->Parent = self;

	if ( self->Last == nullptr )
	{
		self->Last = entry;
		self->Next = entry;
		self->NumEntries++;
		return;
	}

	self->Last->Next = entry;
	self->Last       = entry;
	self->NumEntries++;
}
inline
CodeParams params_get(CodeParams self, s32 idx )
{
	GEN_ASSERT(self);
	CodeParams param = self;
	do
	{
		if ( ++ param != nullptr )
			return NullCode;

		param = cast(CodeParams, cast(Code, param)->Next);
	}
	while ( --idx );

	return param;
}
FORCEINLINE
bool params_has_entries(CodeParams self)
{
	GEN_ASSERT(self);
	return self->NumEntries > 0;
}
#if GEN_COMPILER_CPP
FORCEINLINE
CodeParams& CodeParams::operator ++()
{
	* this = ast->Next;
	return * this;
}
#endif
FORCEINLINE
CodeParams begin_CodeParams(CodeParams params)
{
	if ( params != nullptr )
		return params;

	return NullCode;
}
FORCEINLINE
CodeParams end_CodeParams(CodeParams params)
{
	// return { (AST_Params*) rcast( AST*, ast)->Last };
	return NullCode;
}
FORCEINLINE
CodeParams next_CodeParams(CodeParams params, CodeParams param_iter)
{
	GEN_ASSERT(param_iter);
	return param_iter->Next;
}
#pragma endregion CodeParams

#pragma region CodeDefineParams
FORCEINLINE void             define_params_append     (CodeDefineParams appendee, CodeDefineParams other ) { params_append( cast(CodeParams, appendee), cast(CodeParams, other) ); }
FORCEINLINE CodeDefineParams define_params_get        (CodeDefineParams self, s32 idx )                    { return (CodeDefineParams) (Code) params_get( cast(CodeParams, self), idx); }
FORCEINLINE bool             define_params_has_entries(CodeDefineParams self)                              { return params_has_entries( cast(CodeParams, self)); }

FORCEINLINE CodeDefineParams begin_CodeDefineParams(CodeDefineParams params)                              { return (CodeDefineParams) (Code) begin_CodeParams( cast(CodeParams, (Code)params)); }
FORCEINLINE CodeDefineParams end_CodeDefineParams  (CodeDefineParams params)                              { return (CodeDefineParams) (Code) end_CodeParams  ( cast(CodeParams, (Code)params)); }
FORCEINLINE CodeDefineParams next_CodeDefineParams (CodeDefineParams params, CodeDefineParams entry_iter) { return (CodeDefineParams) (Code) next_CodeParams ( cast(CodeParams, (Code)params), cast(CodeParams, (Code)entry_iter)); }

#if GEN_COMPILER_CPP
FORCEINLINE
CodeDefineParams& CodeDefineParams::operator ++()
{
	* this = ast->Next;
	return * this;
}
#endif
#pragma endregion CodeDefineParams

#pragma region CodeSpecifiers
inline
bool specifiers_append(CodeSpecifiers self, Specifier spec )
{
	if ( self == nullptr )
	{
		log_failure("CodeSpecifiers: Attempted to append to a null specifiers AST!");
		return false;
	}
	if ( self->NumEntries == AST_ArrSpecs_Cap )
	{
		log_failure("CodeSpecifiers: Attempted to append over %d specifiers to a specifiers AST!", AST_ArrSpecs_Cap );
		return false;
	}

	self->ArrSpecs[ self->NumEntries ] = spec;
	self->NumEntries++;
	return true;
}
inline
s32 specifiers_has(CodeSpecifiers self, Specifier spec)
{
	GEN_ASSERT(self != nullptr);
	for ( s32 idx = 0; idx < self->NumEntries; idx++ ) {
		if ( self->ArrSpecs[ idx ] == spec )
			return idx;
	}
	return -1;
}
inline
s32 specifiers_remove( CodeSpecifiers self, Specifier to_remove )
{
	if ( self == nullptr )
	{
		log_failure("CodeSpecifiers: Attempted to append to a null specifiers AST!");
		return -1;
	}
	if ( self->NumEntries == AST_ArrSpecs_Cap )
	{
		log_failure("CodeSpecifiers: Attempted to append over %d specifiers to a specifiers AST!", AST_ArrSpecs_Cap );
		return -1;
	}

	s32 result = -1;

	s32 curr = 0;
	s32 next = 0;
	for(; next < self->NumEntries; ++ curr, ++ next)
	{
		Specifier spec = self->ArrSpecs[next];
		if (spec == to_remove)
		{
			result = next;

			next ++;
			if (next >= self->NumEntries)
				break;

			spec = self->ArrSpecs[next];
		}

		self->ArrSpecs[ curr ] = spec;
	}

	if (result > -1) {
		self->NumEntries --;
	}
	return result;
}
FORCEINLINE
Specifier* begin_CodeSpecifiers(CodeSpecifiers self)
{
	if ( self != nullptr )
		return & self->ArrSpecs[0];

	return nullptr;
}
FORCEINLINE
Specifier* end_CodeSpecifiers(CodeSpecifiers self)
{
	return self->ArrSpecs + self->NumEntries;
}
FORCEINLINE
Specifier* next_CodeSpecifiers(CodeSpecifiers self, Specifier* spec_iter)
{
	return spec_iter + 1;
}
#pragma endregion CodeSpecifiers

#pragma region CodeStruct
inline
void struct_add_interface(CodeStruct self, CodeTypename type )
{
	CodeTypename possible_slot = self->ParentType;
	if ( possible_slot != nullptr )
	{
		// Were adding an interface to parent type, so we need to make sure the parent type is public.
		self->ParentAccess = AccessSpec_Public;
		// If your planning on adding a proper parent,
		// then you'll need to move this over to ParentType->next and update ParentAccess accordingly.
	}

	while ( possible_slot != nullptr )
	{
		possible_slot = cast(CodeTypename, possible_slot->Next);
	}

	possible_slot = type;
}
#pragma endregion Code

#pragma region Interface
inline
CodeBody def_body( CodeType type )
{
	switch ( type )
	{
		case CT_Class_Body:
		case CT_Enum_Body:
		case CT_Export_Body:
		case CT_Extern_Linkage:
		case CT_Function_Body:
		case CT_Global_Body:
		case CT_Namespace_Body:
		case CT_Struct_Body:
		case CT_Union_Body:
			break;

		default:
			log_failure( "def_body: Invalid type %s", codetype_to_str(type).Ptr );
			return (CodeBody)Code_Invalid;
	}

	Code
	result       = make_code();
	result->Type = type;
	return (CodeBody)result;
}

inline
Str token_fmt_impl( ssize num, ... )
{
	local_persist thread_local
	char buf[GEN_PRINTF_MAXLEN] = { 0 };
	mem_set( buf, 0, GEN_PRINTF_MAXLEN );

	va_list va;
	va_start(va, num );
	ssize result = token_fmt_va(buf, GEN_PRINTF_MAXLEN, num, va);
	va_end(va);

	Str str = { buf, result };
	return str;
}
#pragma endregion Interface

#pragma region generated code inline implementation

inline Code& Code::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline Code::operator bool()
{
	return ast != nullptr;
}

inline CodeBody& CodeBody::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeBody::operator bool()
{
	return ast != nullptr;
}

inline CodeAttributes& CodeAttributes::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeAttributes::operator bool()
{
	return ast != nullptr;
}

inline CodeAttributes::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Attributes* CodeAttributes::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeComment& CodeComment::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeComment::operator bool()
{
	return ast != nullptr;
}

inline CodeComment::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Comment* CodeComment::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeConstructor& CodeConstructor::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeConstructor::operator bool()
{
	return ast != nullptr;
}

inline CodeConstructor::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Constructor* CodeConstructor::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeClass& CodeClass::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeClass::operator bool()
{
	return ast != nullptr;
}

inline CodeDefine& CodeDefine::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeDefine::operator bool()
{
	return ast != nullptr;
}

inline CodeDefine::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Define* CodeDefine::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeDefineParams& CodeDefineParams::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeDefineParams::operator bool()
{
	return ast != nullptr;
}

inline CodeDestructor& CodeDestructor::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeDestructor::operator bool()
{
	return ast != nullptr;
}

inline CodeDestructor::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Destructor* CodeDestructor::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeEnum& CodeEnum::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeEnum::operator bool()
{
	return ast != nullptr;
}

inline CodeEnum::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Enum* CodeEnum::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeExec& CodeExec::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeExec::operator bool()
{
	return ast != nullptr;
}

inline CodeExec::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Exec* CodeExec::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeExtern& CodeExtern::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeExtern::operator bool()
{
	return ast != nullptr;
}

inline CodeExtern::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Extern* CodeExtern::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeFriend& CodeFriend::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeFriend::operator bool()
{
	return ast != nullptr;
}

inline CodeFriend::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Friend* CodeFriend::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeFn& CodeFn::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeFn::operator bool()
{
	return ast != nullptr;
}

inline CodeFn::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Fn* CodeFn::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeInclude& CodeInclude::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeInclude::operator bool()
{
	return ast != nullptr;
}

inline CodeInclude::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Include* CodeInclude::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeModule& CodeModule::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeModule::operator bool()
{
	return ast != nullptr;
}

inline CodeModule::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Module* CodeModule::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeNS& CodeNS::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeNS::operator bool()
{
	return ast != nullptr;
}

inline CodeNS::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_NS* CodeNS::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeOperator& CodeOperator::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeOperator::operator bool()
{
	return ast != nullptr;
}

inline CodeOperator::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Operator* CodeOperator::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeOpCast& CodeOpCast::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeOpCast::operator bool()
{
	return ast != nullptr;
}

inline CodeOpCast::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_OpCast* CodeOpCast::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeParams& CodeParams::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeParams::operator bool()
{
	return ast != nullptr;
}

inline CodePragma& CodePragma::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodePragma::operator bool()
{
	return ast != nullptr;
}

inline CodePragma::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Pragma* CodePragma::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodePreprocessCond& CodePreprocessCond::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodePreprocessCond::operator bool()
{
	return ast != nullptr;
}

inline CodePreprocessCond::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_PreprocessCond* CodePreprocessCond::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeSpecifiers& CodeSpecifiers::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeSpecifiers::operator bool()
{
	return ast != nullptr;
}

inline CodeStruct& CodeStruct::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeStruct::operator bool()
{
	return ast != nullptr;
}

inline CodeTemplate& CodeTemplate::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeTemplate::operator bool()
{
	return ast != nullptr;
}

inline CodeTemplate::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Template* CodeTemplate::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeTypename& CodeTypename::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeTypename::operator bool()
{
	return ast != nullptr;
}

inline CodeTypename::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Typename* CodeTypename::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeTypedef& CodeTypedef::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeTypedef::operator bool()
{
	return ast != nullptr;
}

inline CodeTypedef::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Typedef* CodeTypedef::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeUnion& CodeUnion::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeUnion::operator bool()
{
	return ast != nullptr;
}

inline CodeUnion::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Union* CodeUnion::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeUsing& CodeUsing::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeUsing::operator bool()
{
	return ast != nullptr;
}

inline CodeUsing::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Using* CodeUsing::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

inline CodeVar& CodeVar::operator=(Code other)
{
	if (other.ast != nullptr && other->Parent != nullptr)
	{
		ast         = rcast(decltype(ast), code_duplicate(other).ast);
		ast->Parent = { nullptr };
	}
	ast = rcast(decltype(ast), other.ast);
	return *this;
}

inline CodeVar::operator bool()
{
	return ast != nullptr;
}

inline CodeVar::operator Code()
{
	return *rcast(Code*, this);
}

inline AST_Var* CodeVar::operator->()
{
	if (ast == nullptr)
	{
		log_failure("Attempt to dereference a nullptr!\n");
		return nullptr;
	}
	return ast;
}

#pragma endregion generated code inline implementation

#pragma region generated AST/Code cast implementation
GEN_OPTIMIZE_MAPPINGS_BEGIN

FORCEINLINE Code::operator CodeBody() const
{
	return { (AST_Body*)ast };
}

FORCEINLINE Code::operator CodeAttributes() const
{
	return { (AST_Attributes*)ast };
}

FORCEINLINE Code::operator CodeComment() const
{
	return { (AST_Comment*)ast };
}

FORCEINLINE Code::operator CodeConstructor() const
{
	return { (AST_Constructor*)ast };
}

FORCEINLINE Code::operator CodeClass() const
{
	return { (AST_Class*)ast };
}

FORCEINLINE Code::operator CodeDefine() const
{
	return { (AST_Define*)ast };
}

FORCEINLINE Code::operator CodeDefineParams() const
{
	return { (AST_DefineParams*)ast };
}

FORCEINLINE Code::operator CodeDestructor() const
{
	return { (AST_Destructor*)ast };
}

FORCEINLINE Code::operator CodeEnum() const
{
	return { (AST_Enum*)ast };
}

FORCEINLINE Code::operator CodeExec() const
{
	return { (AST_Exec*)ast };
}

FORCEINLINE Code::operator CodeExtern() const
{
	return { (AST_Extern*)ast };
}

FORCEINLINE Code::operator CodeFriend() const
{
	return { (AST_Friend*)ast };
}

FORCEINLINE Code::operator CodeFn() const
{
	return { (AST_Fn*)ast };
}

FORCEINLINE Code::operator CodeInclude() const
{
	return { (AST_Include*)ast };
}

FORCEINLINE Code::operator CodeModule() const
{
	return { (AST_Module*)ast };
}

FORCEINLINE Code::operator CodeNS() const
{
	return { (AST_NS*)ast };
}

FORCEINLINE Code::operator CodeOperator() const
{
	return { (AST_Operator*)ast };
}

FORCEINLINE Code::operator CodeOpCast() const
{
	return { (AST_OpCast*)ast };
}

FORCEINLINE Code::operator CodeParams() const
{
	return { (AST_Params*)ast };
}

FORCEINLINE Code::operator CodePragma() const
{
	return { (AST_Pragma*)ast };
}

FORCEINLINE Code::operator CodePreprocessCond() const
{
	return { (AST_PreprocessCond*)ast };
}

FORCEINLINE Code::operator CodeSpecifiers() const
{
	return { (AST_Specifiers*)ast };
}

FORCEINLINE Code::operator CodeStruct() const
{
	return { (AST_Struct*)ast };
}

FORCEINLINE Code::operator CodeTemplate() const
{
	return { (AST_Template*)ast };
}

FORCEINLINE Code::operator CodeTypename() const
{
	return { (AST_Typename*)ast };
}

FORCEINLINE Code::operator CodeTypedef() const
{
	return { (AST_Typedef*)ast };
}

FORCEINLINE Code::operator CodeUnion() const
{
	return { (AST_Union*)ast };
}

FORCEINLINE Code::operator CodeUsing() const
{
	return { (AST_Using*)ast };
}

FORCEINLINE Code::operator CodeVar() const
{
	return { (AST_Var*)ast };
}

GEN_OPITMIZE_MAPPINGS_END
#pragma endregion generated AST / Code cast implementation

#pragma endregion Inlines

#pragma region Constants

GEN_API extern Macro enum_underlying_macro;

GEN_API extern Code access_public;
GEN_API extern Code access_protected;
GEN_API extern Code access_private;

GEN_API extern CodeAttributes attrib_api_export;
GEN_API extern CodeAttributes attrib_api_import;

GEN_API extern Code module_global_fragment;
GEN_API extern Code module_private_fragment;

GEN_API extern Code fmt_newline;

GEN_API extern CodePragma pragma_once;

GEN_API extern CodeParams param_varadic;

GEN_API extern CodePreprocessCond preprocess_else;
GEN_API extern CodePreprocessCond preprocess_endif;

GEN_API extern CodeSpecifiers spec_const;
GEN_API extern CodeSpecifiers spec_consteval;
GEN_API extern CodeSpecifiers spec_constexpr;
GEN_API extern CodeSpecifiers spec_constinit;
GEN_API extern CodeSpecifiers spec_extern_linkage;
GEN_API extern CodeSpecifiers spec_final;
GEN_API extern CodeSpecifiers spec_FORCEINLINE;
GEN_API extern CodeSpecifiers spec_global;
GEN_API extern CodeSpecifiers spec_inline;
GEN_API extern CodeSpecifiers spec_internal_linkage;
GEN_API extern CodeSpecifiers spec_local_persist;
GEN_API extern CodeSpecifiers spec_mutable;
GEN_API extern CodeSpecifiers spec_neverinline;
GEN_API extern CodeSpecifiers spec_noexcept;
GEN_API extern CodeSpecifiers spec_override;
GEN_API extern CodeSpecifiers spec_ptr;
GEN_API extern CodeSpecifiers spec_pure;
GEN_API extern CodeSpecifiers spec_ref;
GEN_API extern CodeSpecifiers spec_register;
GEN_API extern CodeSpecifiers spec_rvalue;
GEN_API extern CodeSpecifiers spec_static_member;
GEN_API extern CodeSpecifiers spec_thread_local;
GEN_API extern CodeSpecifiers spec_virtual;
GEN_API extern CodeSpecifiers spec_volatile;

GEN_API extern CodeTypename t_empty; // Used with varaidc parameters. (Exposing just in case its useful for another circumstance)
GEN_API extern CodeTypename t_auto;
GEN_API extern CodeTypename t_void;
GEN_API extern CodeTypename t_int;
GEN_API extern CodeTypename t_bool;
GEN_API extern CodeTypename t_char;
GEN_API extern CodeTypename t_wchar_t;
GEN_API extern CodeTypename t_class;
GEN_API extern CodeTypename t_typename;

#ifdef GEN_DEFINE_LIBRARY_CODE_CONSTANTS
	// Predefined typename codes. Are set to readonly and are setup during gen::init()
	GEN_API extern Context* _ctx;

	GEN_API extern CodeTypename t_b32;

	GEN_API extern CodeTypename t_s8;
	GEN_API extern CodeTypename t_s16;
	GEN_API extern CodeTypename t_s32;
	GEN_API extern CodeTypename t_s64;

	GEN_API extern CodeTypename t_u8;
	GEN_API extern CodeTypename t_u16;
	GEN_API extern CodeTypename t_u32;
	GEN_API extern CodeTypename t_u64;

	GEN_API extern CodeTypename t_ssize;
	GEN_API extern CodeTypename t_usize;

	GEN_API extern CodeTypename t_f32;
	GEN_API extern CodeTypename t_f64;
#endif

#pragma endregion Constants

GEN_NS_END

#ifdef __clang__
#	pragma clang diagnostic pop
#endif

#ifdef __GNUC__
#	pragma GCC diagnostic pop
#endif
