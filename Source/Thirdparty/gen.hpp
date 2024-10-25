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

/*
    gencpp: An attempt at "simple" staged metaprogramming for c/c++.

    See Readme.md for more information from the project repository.

    Public Address:
    https://github.com/Ed94/gencpp

    This is a variant intended for use with Unreal Engine 5
*/
#if ! defined( GEN_DONT_ENFORCE_GEN_TIME_GUARD ) && ! defined( GEN_TIME )
#error Gen.hpp : GEN_TIME not defined
#endif

//! If its desired to roll your own dependencies, define GEN_ROLL_OWN_DEPENDENCIES before including this file.
// Dependencies are derived from the c-zpl library: https://github.com/zpl-c/zpl
#ifndef GEN_ROLL_OWN_DEPENDENCIES
#include "gen.dep.hpp"
#endif

#ifndef GEN_NS_BEGIN
#ifdef GEN_DONT_USE_NAMESPACE
#define GEN_NS
#define GEN_NS_BEGIN
#define GEN_NS_END
#else
#define GEN_NS gen::
#define GEN_NS_BEGIN \
	namespace gen    \
	{
#define GEN_NS_END }
#endif
#endif

GEN_NS_BEGIN

#pragma region Types

using LogFailType = sw ( * )( char const*, ... );

// By default this library will either crash or exit if an error is detected while generating codes.
// Even if set to not use GEN_FATAL, GEN_FATAL will still be used for memory failures as the library is unusable when they occur.
#ifdef GEN_DONT_USE_FATAL
#define log_failure log_fmt
#else
#define log_failure GEN_FATAL
#endif

enum class AccessSpec : u32
{
	Default,
	Private,
	Protected,
	Public,

	Num_AccessSpec,
	Invalid,
};

inline char const* to_str( AccessSpec type )
{
	local_persist char const* lookup[(u32)AccessSpec::Num_AccessSpec] = {
		"",
		"private",
		"protected",
		"public",
	};

	if ( type > AccessSpec::Public )
		return "Invalid";

	return lookup[(u32)type];
}

enum CodeFlag : u32
{
	None          = 0,
	FunctionType  = bit( 0 ),
	ParamPack     = bit( 1 ),
	Module_Export = bit( 2 ),
	Module_Import = bit( 3 ),
};

// Used to indicate if enum definitoin is an enum class or regular enum.
enum class EnumT : u8
{
	Regular,
	Class
};

constexpr EnumT EnumClass   = EnumT::Class;
constexpr EnumT EnumRegular = EnumT::Regular;

enum class ModuleFlag : u32
{
	None   = 0,
	Export = bit( 0 ),
	Import = bit( 1 ),

	Num_ModuleFlags,
	Invalid,
};

inline StrC to_str( ModuleFlag flag )
{
	local_persist StrC lookup[(u32)ModuleFlag::Num_ModuleFlags] = {
		{ sizeof( "__none__" ), "__none__" },
		{ sizeof( "export" ),   "export"   },
		{ sizeof( "import" ),   "import"   },
	};

	if ( flag > ModuleFlag::Import )
		return { sizeof( "invalid" ), "invalid" };

	return lookup[(u32)flag];
}

inline ModuleFlag operator|( ModuleFlag A, ModuleFlag B )
{
	return (ModuleFlag)( (u32)A | (u32)B );
}

enum class EPreprocessCond : u32
{
	If,
	IfDef,
	IfNotDef,
	ElIf
};

constexpr EPreprocessCond PreprocessCond_If       = EPreprocessCond::If;
constexpr EPreprocessCond PreprocessCond_IfDef    = EPreprocessCond::IfDef;
constexpr EPreprocessCond PreprocessCond_IfNotDef = EPreprocessCond::IfNotDef;
constexpr EPreprocessCond PreprocessCond_ElIf     = EPreprocessCond::ElIf;

namespace ECode
{
	enum Type : u32
	{
		Invalid,
		Untyped,
		NewLine,
		Comment,
		Access_Private,
		Access_Protected,
		Access_Public,
		PlatformAttributes,
		Class,
		Class_Fwd,
		Class_Body,
		Constructor,
		Constructor_Fwd,
		Destructor,
		Destructor_Fwd,
		Enum,
		Enum_Fwd,
		Enum_Body,
		Enum_Class,
		Enum_Class_Fwd,
		Execution,
		Export_Body,
		Extern_Linkage,
		Extern_Linkage_Body,
		Friend,
		Function,
		Function_Fwd,
		Function_Body,
		Global_Body,
		Module,
		Namespace,
		Namespace_Body,
		Operator,
		Operator_Fwd,
		Operator_Member,
		Operator_Member_Fwd,
		Operator_Cast,
		Operator_Cast_Fwd,
		Parameters,
		Preprocess_Define,
		Preprocess_Include,
		Preprocess_If,
		Preprocess_IfDef,
		Preprocess_IfNotDef,
		Preprocess_ElIf,
		Preprocess_Else,
		Preprocess_EndIf,
		Preprocess_Pragma,
		Specifiers,
		Struct,
		Struct_Fwd,
		Struct_Body,
		Template,
		Typedef,
		Typename,
		Union,
		Union_Body,
		Using,
		Using_Namespace,
		Variable,
		NumTypes
	};

	inline StrC to_str( Type type )
	{
		local_persist StrC lookup[] {
			{ sizeof( "Invalid" ),             "Invalid"             },
			{ sizeof( "Untyped" ),             "Untyped"             },
			{ sizeof( "NewLine" ),             "NewLine"             },
			{ sizeof( "Comment" ),             "Comment"             },
			{ sizeof( "Access_Private" ),      "Access_Private"      },
			{ sizeof( "Access_Protected" ),    "Access_Protected"    },
			{ sizeof( "Access_Public" ),       "Access_Public"       },
			{ sizeof( "PlatformAttributes" ),  "PlatformAttributes"  },
			{ sizeof( "Class" ),               "Class"               },
			{ sizeof( "Class_Fwd" ),           "Class_Fwd"           },
			{ sizeof( "Class_Body" ),          "Class_Body"          },
			{ sizeof( "Constructor" ),         "Constructor"         },
			{ sizeof( "Constructor_Fwd" ),     "Constructor_Fwd"     },
			{ sizeof( "Destructor" ),          "Destructor"          },
			{ sizeof( "Destructor_Fwd" ),      "Destructor_Fwd"      },
			{ sizeof( "Enum" ),                "Enum"                },
			{ sizeof( "Enum_Fwd" ),            "Enum_Fwd"            },
			{ sizeof( "Enum_Body" ),           "Enum_Body"           },
			{ sizeof( "Enum_Class" ),          "Enum_Class"          },
			{ sizeof( "Enum_Class_Fwd" ),      "Enum_Class_Fwd"      },
			{ sizeof( "Execution" ),           "Execution"           },
			{ sizeof( "Export_Body" ),         "Export_Body"         },
			{ sizeof( "Extern_Linkage" ),      "Extern_Linkage"      },
			{ sizeof( "Extern_Linkage_Body" ), "Extern_Linkage_Body" },
			{ sizeof( "Friend" ),              "Friend"              },
			{ sizeof( "Function" ),            "Function"            },
			{ sizeof( "Function_Fwd" ),        "Function_Fwd"        },
			{ sizeof( "Function_Body" ),       "Function_Body"       },
			{ sizeof( "Global_Body" ),         "Global_Body"         },
			{ sizeof( "Module" ),              "Module"              },
			{ sizeof( "Namespace" ),           "Namespace"           },
			{ sizeof( "Namespace_Body" ),      "Namespace_Body"      },
			{ sizeof( "Operator" ),            "Operator"            },
			{ sizeof( "Operator_Fwd" ),        "Operator_Fwd"        },
			{ sizeof( "Operator_Member" ),     "Operator_Member"     },
			{ sizeof( "Operator_Member_Fwd" ), "Operator_Member_Fwd" },
			{ sizeof( "Operator_Cast" ),       "Operator_Cast"       },
			{ sizeof( "Operator_Cast_Fwd" ),   "Operator_Cast_Fwd"   },
			{ sizeof( "Parameters" ),          "Parameters"          },
			{ sizeof( "Preprocess_Define" ),   "Preprocess_Define"   },
			{ sizeof( "Preprocess_Include" ),  "Preprocess_Include"  },
			{ sizeof( "Preprocess_If" ),       "Preprocess_If"       },
			{ sizeof( "Preprocess_IfDef" ),    "Preprocess_IfDef"    },
			{ sizeof( "Preprocess_IfNotDef" ), "Preprocess_IfNotDef" },
			{ sizeof( "Preprocess_ElIf" ),     "Preprocess_ElIf"     },
			{ sizeof( "Preprocess_Else" ),     "Preprocess_Else"     },
			{ sizeof( "Preprocess_EndIf" ),    "Preprocess_EndIf"    },
			{ sizeof( "Preprocess_Pragma" ),   "Preprocess_Pragma"   },
			{ sizeof( "Specifiers" ),          "Specifiers"          },
			{ sizeof( "Struct" ),              "Struct"              },
			{ sizeof( "Struct_Fwd" ),          "Struct_Fwd"          },
			{ sizeof( "Struct_Body" ),         "Struct_Body"         },
			{ sizeof( "Template" ),            "Template"            },
			{ sizeof( "Typedef" ),             "Typedef"             },
			{ sizeof( "Typename" ),            "Typename"            },
			{ sizeof( "Union" ),               "Union"               },
			{ sizeof( "Union_Body" ),          "Union_Body"          },
			{ sizeof( "Using" ),               "Using"               },
			{ sizeof( "Using_Namespace" ),     "Using_Namespace"     },
			{ sizeof( "Variable" ),            "Variable"            },
		};
		return lookup[type];
	}

}    // namespace ECode

using CodeT = ECode::Type;

namespace EOperator
{
	enum Type : u32
	{
		Invalid,
		Assign,
		Assign_Add,
		Assign_Subtract,
		Assign_Multiply,
		Assign_Divide,
		Assign_Modulo,
		Assign_BAnd,
		Assign_BOr,
		Assign_BXOr,
		Assign_LShift,
		Assign_RShift,
		Increment,
		Decrement,
		Unary_Plus,
		Unary_Minus,
		UnaryNot,
		Add,
		Subtract,
		Multiply,
		Divide,
		Modulo,
		BNot,
		BAnd,
		BOr,
		BXOr,
		LShift,
		RShift,
		LAnd,
		LOr,
		LEqual,
		LNot,
		Lesser,
		Greater,
		LesserEqual,
		GreaterEqual,
		Subscript,
		Indirection,
		AddressOf,
		MemberOfPointer,
		PtrToMemOfPtr,
		FunctionCall,
		Comma,
		New,
		NewArray,
		Delete,
		DeleteArray,
		NumOps
	};

	inline StrC to_str( Type op )
	{
		local_persist StrC lookup[] {
			{ sizeof( "INVALID" ),  "INVALID"  },
			{ sizeof( "=" ),        "="        },
			{ sizeof( "+=" ),       "+="       },
			{ sizeof( "-=" ),       "-="       },
			{ sizeof( "*=" ),       "*="       },
			{ sizeof( "/=" ),       "/="       },
			{ sizeof( "%=" ),       "%="       },
			{ sizeof( "&=" ),       "&="       },
			{ sizeof( "|=" ),       "|="       },
			{ sizeof( "^=" ),       "^="       },
			{ sizeof( "<<=" ),      "<<="      },
			{ sizeof( ">>=" ),      ">>="      },
			{ sizeof( "++" ),       "++"       },
			{ sizeof( "--" ),       "--"       },
			{ sizeof( "+" ),        "+"        },
			{ sizeof( "-" ),        "-"        },
			{ sizeof( "!" ),        "!"        },
			{ sizeof( "+" ),        "+"        },
			{ sizeof( "-" ),        "-"        },
			{ sizeof( "*" ),        "*"        },
			{ sizeof( "/" ),        "/"        },
			{ sizeof( "%" ),        "%"        },
			{ sizeof( "~" ),        "~"        },
			{ sizeof( "&" ),        "&"        },
			{ sizeof( "|" ),        "|"        },
			{ sizeof( "^" ),        "^"        },
			{ sizeof( "<<" ),       "<<"       },
			{ sizeof( ">>" ),       ">>"       },
			{ sizeof( "&&" ),       "&&"       },
			{ sizeof( "||" ),       "||"       },
			{ sizeof( "==" ),       "=="       },
			{ sizeof( "!=" ),       "!="       },
			{ sizeof( "<" ),        "<"        },
			{ sizeof( ">" ),        ">"        },
			{ sizeof( "<=" ),       "<="       },
			{ sizeof( ">=" ),       ">="       },
			{ sizeof( "[]" ),       "[]"       },
			{ sizeof( "*" ),        "*"        },
			{ sizeof( "&" ),        "&"        },
			{ sizeof( "->" ),       "->"       },
			{ sizeof( "->*" ),      "->*"      },
			{ sizeof( "()" ),       "()"       },
			{ sizeof( "," ),        ","        },
			{ sizeof( "new" ),      "new"      },
			{ sizeof( "new[]" ),    "new[]"    },
			{ sizeof( "delete" ),   "delete"   },
			{ sizeof( "delete[]" ), "delete[]" },
		};
		return lookup[op];
	}

}    // namespace EOperator

using OperatorT = EOperator::Type;

namespace ESpecifier
{
	enum Type : u32
	{
		Invalid,
		Consteval,
		Constexpr,
		Constinit,
		Explicit,
		External_Linkage,
		ForceInline,
		Global,
		Inline,
		Internal_Linkage,
		Local_Persist,
		Mutable,
		NeverInline,
		Ptr,
		Ref,
		Register,
		RValue,
		Static,
		Thread_Local,
		Virtual,
		Const,
		Final,
		NoExceptions,
		Override,
		Pure,
		Volatile,
		NumSpecifiers
	};

	inline bool is_trailing( Type specifier )
	{
		return specifier > Virtual;
	}

	inline StrC to_str( Type type )
	{
		local_persist StrC lookup[] {
			{ sizeof( "INVALID" ),       "INVALID"       },
			{ sizeof( "consteval" ),     "consteval"     },
			{ sizeof( "constexpr" ),     "constexpr"     },
			{ sizeof( "constinit" ),     "constinit"     },
			{ sizeof( "explicit" ),      "explicit"      },
			{ sizeof( "extern" ),        "extern"        },
			{ sizeof( "FORCEINLINE" ),   "FORCEINLINE"   },
			{ sizeof( "global" ),        "global"        },
			{ sizeof( "inline" ),        "inline"        },
			{ sizeof( "internal" ),      "internal"      },
			{ sizeof( "local_persist" ), "local_persist" },
			{ sizeof( "mutable" ),       "mutable"       },
			{ sizeof( "neverinline" ),   "neverinline"   },
			{ sizeof( "*" ),             "*"             },
			{ sizeof( "&" ),             "&"             },
			{ sizeof( "register" ),      "register"      },
			{ sizeof( "&&" ),            "&&"            },
			{ sizeof( "static" ),        "static"        },
			{ sizeof( "thread_local" ),  "thread_local"  },
			{ sizeof( "virtual" ),       "virtual"       },
			{ sizeof( "const" ),         "const"         },
			{ sizeof( "final" ),         "final"         },
			{ sizeof( "noexcept" ),      "noexcept"      },
			{ sizeof( "override" ),      "override"      },
			{ sizeof( "= 0" ),           "= 0"           },
			{ sizeof( "volatile" ),      "volatile"      },
		};
		return lookup[type];
	}

	inline Type to_type( StrC str )
	{
		local_persist u32 keymap[NumSpecifiers];
		do_once_start for ( u32 index = 0; index < NumSpecifiers; index++ )
		{
			StrC enum_str = to_str( (Type)index );
			keymap[index] = crc32( enum_str.Ptr, enum_str.Len - 1 );
		}
		do_once_end u32 hash = crc32( str.Ptr, str.Len );
		for ( u32 index = 0; index < NumSpecifiers; index++ )
		{
			if ( keymap[index] == hash )
				return (Type)index;
		}
		return Invalid;
	}

}    // namespace ESpecifier

using SpecifierT = ESpecifier::Type;

#pragma endregion Types

#pragma region AST

struct AST;
struct AST_Body;
struct AST_Attributes;
struct AST_Comment;
struct AST_Constructor;
// struct AST_BaseClass;
struct AST_Class;
struct AST_Define;
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
struct AST_Param;
struct AST_Pragma;
struct AST_PreprocessCond;
struct AST_Specifiers;

#if GEN_EXECUTION_EXPRESSION_SUPPORT
struct AST_Expr;
struct AST_Expr_Assign;
struct AST_Expr_Alignof;
struct AST_Expr_Binary;
struct AST_Expr_CStyleCast;
struct AST_Expr_FunctionalCast;
struct AST_Expr_CppCast;
struct AST_Expr_ProcCall;
struct AST_Expr_Decltype;
struct AST_Expr_Comma;    // TODO(Ed) : This is a binary op not sure if it needs its own AST...
struct AST_Expr_AMS;      // Access Member Symbol
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
struct AST_Stmt_Expr;    // TODO(Ed) : Is this distinction needed? (Should it be a flag instead?)
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
struct AST_Type;
struct AST_Typedef;
struct AST_Union;
struct AST_Using;
struct AST_Var;

struct Code;
struct CodeBody;
// These are to offer ease of use and optionally strong type safety for the AST.
struct CodeAttributes;
// struct CodeBaseClass;
struct CodeComment;
struct CodeClass;
struct CodeConstructor;
struct CodeDefine;
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
struct CodeParam;
struct CodePreprocessCond;
struct CodePragma;
struct CodeSpecifiers;

#if GEN_EXECUTION_EXPRESSION_SUPPORT
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
struct CodeExpr_AMS;    // Access Member Symbol
struct CodeExpr_Sizeof;
struct CodeExpr_Subscript;
struct CodeExpr_Ternary;
struct CodeExpr_UnaryPrefix;
struct CodeExpr_UnaryPostfix;

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

struct CodeStruct;
struct CodeTemplate;
struct CodeType;
struct CodeTypedef;
struct CodeUnion;
struct CodeUsing;
struct CodeVar;

namespace parser
{
	struct Token;
}

/*
    AST* wrapper
    - Not constantly have to append the '*' as this is written often..
    - Allows for implicit conversion to any of the ASTs (raw or filtered).
*/
struct Code
{
#pragma region Statics
	// Used to identify ASTs that should always be duplicated. (Global constant ASTs)
	static Code Global;

	// Used to identify invalid generated code.
	static Code Invalid;
#pragma endregion Statics

#define Using_Code( Typename )            \
	char const* debug_str();              \
	Code        duplicate();              \
	bool        is_equal( Code other );   \
	bool        is_valid();               \
	void        set_global();             \
	String      to_string();              \
	Typename&   operator=( AST* other );  \
	Typename&   operator=( Code other );  \
	bool        operator==( Code other ); \
	bool        operator!=( Code other ); \
	operator bool();

	Using_Code( Code );

	template<class Type>
	FORCEINLINE Type cast()
	{
		return *rcast( Type*, this );
	}

	AST* operator->()
	{
		return ast;
	}

	Code& operator++();

	// TODO(Ed) : Remove this overload.
	auto& operator*()
	{
		local_persist thread_local Code NullRef = { nullptr };

		if ( ast == nullptr )
			return NullRef;

		return *this;
	}

	AST* ast;

#ifdef GEN_ENFORCE_STRONG_CODE_TYPES
#define operator explicit operator
#endif
	operator CodeBody() const;
	operator CodeAttributes() const;
	// operator CodeBaseClass() const;
	operator CodeComment() const;
	operator CodeClass() const;
	operator CodeConstructor() const;
	operator CodeDefine() const;
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
	operator CodeParam() const;
	operator CodePragma() const;
	operator CodePreprocessCond() const;
	operator CodeSpecifiers() const;
	operator CodeStruct() const;
	operator CodeTemplate() const;
	operator CodeType() const;
	operator CodeTypedef() const;
	operator CodeUnion() const;
	operator CodeUsing() const;
	operator CodeVar() const;
#undef operator
};

struct Code_POD
{
	AST* ast;
};

static_assert( sizeof( Code ) == sizeof( Code_POD ), "ERROR: Code is not POD" );

// Desired width of the AST data structure.
constexpr int const AST_POD_Size = 128;

/*
    Simple AST POD with functionality to seralize into C++ syntax.
*/
struct AST
{
#pragma region Member Functions
	void        append( AST* other );
	char const* debug_str();
	AST*        duplicate();
	Code&       entry( u32 idx );
	bool        has_entries();
	bool        is_equal( AST* other );
	char const* type_str();
	bool        validate_body();

	String to_string();

	neverinline void to_string( String& result );

	template<class Type>
	FORCEINLINE Type cast()
	{
		return *this;
	}

	operator Code();
	operator CodeBody();
	operator CodeAttributes();
	// operator CodeBaseClass();
	operator CodeComment();
	operator CodeConstructor();
	operator CodeDestructor();
	operator CodeClass();
	operator CodeDefine();
	operator CodeEnum();
	operator CodeExec();
	operator CodeExtern();
	operator CodeInclude();
	operator CodeFriend();
	operator CodeFn();
	operator CodeModule();
	operator CodeNS();
	operator CodeOperator();
	operator CodeOpCast();
	operator CodeParam();
	operator CodePragma();
	operator CodePreprocessCond();
	operator CodeSpecifiers();
	operator CodeStruct();
	operator CodeTemplate();
	operator CodeType();
	operator CodeTypedef();
	operator CodeUnion();
	operator CodeUsing();
	operator CodeVar();
#pragma endregion Member Functions

	constexpr static int ArrSpecs_Cap = ( AST_POD_Size - sizeof( AST* ) * 3 - sizeof( parser::Token* ) - sizeof( AST* ) - sizeof( StringCached )
	                                      - sizeof( CodeT ) - sizeof( ModuleFlag ) - sizeof( int ) )
	        / sizeof( int )
	    - 1;    // -1 for 4 extra bytes

	union
	{
		struct
		{
			AST* InlineCmt;     // Class, Constructor, Destructor, Enum, Friend, Functon, Operator, OpCast, Struct, Typedef, Using, Variable
			AST* Attributes;    // Class, Enum, Function, Struct, Typedef, Union, Using, Variable
			AST* Specs;         // Destructor, Function, Operator, Typename, Variable

			union
			{
				AST* InitializerList;    // Constructor
				AST* ParentType;         // Class, Struct, ParentType->Next has a possible list of interfaces.
				AST* ReturnType;         // Function, Operator, Typename
				AST* UnderlyingType;     // Enum, Typedef
				AST* ValueType;          // Parameter, Variable
			};

			union
			{
				AST* Macro;           // Parameter
				AST* BitfieldSize;    // Variable (Class/Struct Data Member)
				AST* Params;          // Constructor, Function, Operator, Template, Typename
			};

			union
			{
				AST* ArrExpr;        // Typename
				AST* Body;           // Class, Constructor, Destructor, Enum, Friend, Function, Namespace, Struct, Union
				AST* Declaration;    // Friend, Template
				AST* Value;          // Parameter, Variable
			};

			union
			{
				AST* NextVar;    // Variable; Possible way to handle comma separated variables declarations. ( , NextVar->Specs NextVar->Name NextVar->ArrExpr =
				                 // NextVar->Value )
				AST* SuffixSpecs;      // Only used with typenames, to store the function suffix if typename is function signature. ( May not be needed )
				AST* PostNameMacro;    // Only used with parameters for specifically UE_REQUIRES (Thanks Unreal)
			};
		};

		StringCached Content;    // Attributes, Comment, Execution, Include

		struct
		{
			SpecifierT ArrSpecs[ArrSpecs_Cap];    // Specifiers
			AST*       NextSpecs;                 // Specifiers; If ArrSpecs is full, then NextSpecs is used.
		};
	};

	union
	{
		AST* Prev;
		AST* Front;
		AST* Last;
	};

	union
	{
		AST* Next;
		AST* Back;
	};

	parser::Token* Token;    // Reference to starting token, only avaialble if it was derived from parsing.
	AST*           Parent;
	StringCached   Name;
	CodeT          Type;
	//	CodeFlag          CodeFlags;
	ModuleFlag ModuleFlags;

	union
	{
		b32        IsFunction;     // Used by typedef to not serialize the name field.
		b32        IsParamPack;    // Used by typename to know if type should be considered a parameter pack.
		OperatorT  Op;
		AccessSpec ParentAccess;
		s32        NumEntries;
		s32 VarConstructorInit;    // Used by variables to know that initialization is using a constructor expression instead of an assignment expression.
	};
};

struct AST_POD
{
	union
	{
		struct
		{
			AST* InlineCmt;     // Class, Constructor, Destructor, Enum, Friend, Functon, Operator, OpCast, Struct, Typedef, Using, Variable
			AST* Attributes;    // Class, Enum, Function, Struct, Typedef, Union, Using, Variable
			AST* Specs;         // Destructor, Function, Operator, Typename, Variable

			union
			{
				AST* InitializerList;    // Constructor
				AST* ParentType;         // Class, Struct, ParentType->Next has a possible list of interfaces.
				AST* ReturnType;         // Function, Operator, Typename
				AST* UnderlyingType;     // Enum, Typedef
				AST* ValueType;          // Parameter, Variable
			};

			union
			{
				AST* Macro;           // Parameter
				AST* BitfieldSize;    // Variable (Class/Struct Data Member)
				AST* Params;          // Constructor, Function, Operator, Template, Typename
			};

			union
			{
				AST* ArrExpr;        // Typename
				AST* Body;           // Class, Constructr, Destructor, Enum, Friend, Function, Namespace, Struct, Union
				AST* Declaration;    // Friend, Template
				AST* Value;          // Parameter, Variable
			};

			union
			{
				AST* NextVar;    // Variable; Possible way to handle comma separated variables declarations. ( , NextVar->Specs NextVar->Name NextVar->ArrExpr =
				                 // NextVar->Value )
				AST* SuffixSpecs;      // Only used with typenames, to store the function suffix if typename is function signature. ( May not be needed )
				AST* PostNameMacro;    // Only used with parameters for specifically UE_REQUIRES (Thanks Unreal)
			};
		};

		StringCached Content;    // Attributes, Comment, Execution, Include

		struct
		{
			SpecifierT ArrSpecs[AST::ArrSpecs_Cap];    // Specifiers
			AST*       NextSpecs;                      // Specifiers; If ArrSpecs is full, then NextSpecs is used.
		};
	};

	union
	{
		AST* Prev;
		AST* Front;
		AST* Last;
	};

	union
	{
		AST* Next;
		AST* Back;
	};

	parser::Token* Token;    // Reference to starting token, only avaialble if it was derived from parsing.
	AST*           Parent;
	StringCached   Name;
	CodeT          Type;
	CodeFlag       CodeFlags;
	ModuleFlag     ModuleFlags;

	union
	{
		b32        IsFunction;     // Used by typedef to not serialize the name field.
		b32        IsParamPack;    // Used by typename to know if type should be considered a parameter pack.
		OperatorT  Op;
		AccessSpec ParentAccess;
		s32        NumEntries;
		s32 VarConstructorInit;    // Used by variables to know that initialization is using a constructor expression instead of an assignment expression.
	};
};

struct test
{
	SpecifierT ArrSpecs[AST::ArrSpecs_Cap];    // Specifiers
	AST*       NextSpecs;                      // Specifiers; If ArrSpecs is full, then NextSpecs is used.
};

constexpr int pls = sizeof( test );

// Its intended for the AST to have equivalent size to its POD.
// All extra functionality within the AST namespace should just be syntatic sugar.
static_assert( sizeof( AST ) == sizeof( AST_POD ), "ERROR: AST IS NOT POD" );
static_assert( sizeof( AST_POD ) == AST_POD_Size, "ERROR: AST POD is not size of AST_POD_Size" );

// Used when the its desired when omission is allowed in a definition.
#define NoCode  \
	{           \
		nullptr \
	}
#define CodeInvalid ( *Code::Invalid.ast )    // Uses an implicitly overloaded cast from the AST to the desired code type.

#pragma region Code Types

struct CodeBody
{
	Using_Code( CodeBody );

	void append( Code other )
	{
		raw()->append( other.ast );
	}

	void append( CodeBody body )
	{
		for ( Code entry : body )
		{
			append( entry );
		}
	}

	bool has_entries()
	{
		return rcast( AST*, ast )->has_entries();
	}

	void to_string( String& result );
	void to_string_export( String& result );

	AST* raw()
	{
		return rcast( AST*, ast );
	}

	AST_Body* operator->()
	{
		return ast;
	}

	operator Code()
	{
		return *rcast( Code*, this );
	}

#pragma region Iterator

	Code begin()
	{
		if ( ast )
			return { rcast( AST*, ast )->Front };

		return { nullptr };
	}

	Code end()
	{
		return { rcast( AST*, ast )->Back->Next };
	}

#pragma endregion Iterator

	AST_Body* ast;
};

struct CodeClass
{
	Using_Code( CodeClass );

	void add_interface( CodeType interface );

	void to_string_def( String& result );
	void to_string_fwd( String& result );

	AST* raw()
	{
		return rcast( AST*, ast );
	}

	operator Code()
	{
		return *rcast( Code*, this );
	}

	AST_Class* operator->()
	{
		if ( ast == nullptr )
		{
			log_failure( "Attempt to dereference a nullptr" );
			return nullptr;
		}
		return ast;
	}

	AST_Class* ast;
};

struct CodeParam
{
	Using_Code( CodeParam );

	void append( CodeParam other );

	CodeParam get( s32 idx );
	bool      has_entries();
	void      to_string( String& result );

	AST* raw()
	{
		return rcast( AST*, ast );
	}

	AST_Param* operator->()
	{
		if ( ast == nullptr )
		{
			log_failure( "Attempt to dereference a nullptr!" );
			return nullptr;
		}
		return ast;
	}

	operator Code()
	{
		return { (AST*)ast };
	}

#pragma region Iterator

	CodeParam begin()
	{
		if ( ast )
			return { ast };

		return { nullptr };
	}

	CodeParam end()
	{
		// return { (AST_Param*) rcast( AST*, ast)->Last };
		return { nullptr };
	}

	CodeParam& operator++();

	CodeParam operator*()
	{
		return *this;
	}

#pragma endregion Iterator

	AST_Param* ast;
};

struct CodeSpecifiers
{
	Using_Code( CodeSpecifiers );

	bool append( SpecifierT spec )
	{
		if ( ast == nullptr )
		{
			log_failure( "CodeSpecifiers: Attempted to append to a null specifiers AST!" );
			return false;
		}

		if ( raw()->NumEntries == AST::ArrSpecs_Cap )
		{
			log_failure( "CodeSpecifiers: Attempted to append over %d specifiers to a specifiers AST!", AST::ArrSpecs_Cap );
			return false;
		}

		raw()->ArrSpecs[raw()->NumEntries] = spec;
		raw()->NumEntries++;
		return true;
	}

	s32 has( SpecifierT spec )
	{
		for ( s32 idx = 0; idx < raw()->NumEntries; idx++ )
		{
			if ( raw()->ArrSpecs[idx] == spec )
				return idx;
		}

		return -1;
	}

	void to_string( String& result );

	AST* raw()
	{
		return rcast( AST*, ast );
	}

	AST_Specifiers* operator->()
	{
		if ( ast == nullptr )
		{
			log_failure( "Attempt to dereference a nullptr!" );
			return nullptr;
		}
		return ast;
	}

	operator Code()
	{
		return { (AST*)ast };
	}

#pragma region Iterator

	SpecifierT* begin()
	{
		if ( ast )
			return &raw()->ArrSpecs[0];

		return nullptr;
	}

	SpecifierT* end()
	{
		return raw()->ArrSpecs + raw()->NumEntries;
	}

#pragma endregion Iterator

	AST_Specifiers* ast;
};

struct CodeStruct
{
	Using_Code( CodeStruct );

	void add_interface( CodeType interface );

	void to_string_def( String& result );
	void to_string_fwd( String& result );

	AST* raw()
	{
		return rcast( AST*, ast );
	}

	operator Code()
	{
		return *rcast( Code*, this );
	}

	AST_Struct* operator->()
	{
		if ( ast == nullptr )
		{
			log_failure( "Attempt to dereference a nullptr" );
			return nullptr;
		}
		return ast;
	}

	AST_Struct* ast;
};

#define Define_CodeType( Typename )   \
	struct Code##Typename             \
	{                                 \
		Using_Code( Code##Typename ); \
		AST* raw();                   \
		operator Code();              \
		AST_##Typename* operator->(); \
		AST_##Typename* ast;          \
	}

Define_CodeType( Attributes );
// Define_CodeType( BaseClass );
Define_CodeType( Comment );

struct CodeConstructor
{
	Using_Code( CodeConstructor );

	void to_string_def( String& result );
	void to_string_fwd( String& result );

	AST* raw();
	operator Code();
	AST_Constructor* operator->();
	AST_Constructor* ast;
};

struct CodeDefine
{
	Using_Code( CodeDefine );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Define* operator->();
	AST_Define* ast;
};

struct CodeDestructor
{
	Using_Code( CodeDestructor );

	void to_string_def( String& result );
	void to_string_fwd( String& result );

	AST* raw();
	operator Code();
	AST_Destructor* operator->();
	AST_Destructor* ast;
};

struct CodeEnum
{
	Using_Code( CodeEnum );

	void to_string_def( String& result );
	void to_string_fwd( String& result );
	void to_string_class_def( String& result );
	void to_string_class_fwd( String& result );

	AST* raw();
	operator Code();
	AST_Enum* operator->();
	AST_Enum* ast;
};

Define_CodeType( Exec );

#if GEN_EXECUTION_EXPRESSION_SUPPORT
struct CodeExpr
{
	Using_Code( CodeExpr );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr* operator->();
	AST_Expr* ast;
};

struct CodeExpr_Assign
{
	Using_Code( CodeExpr_Assign );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_Assign* operator->();
	AST_Expr_Assign* ast;
};

struct CodeExpr_Alignof
{
	Using_Code( CodeExpr_Alignof );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_Alignof* operator->();
	AST_Expr_Alignof* ast;
};

struct CodeExpr_Binary
{
	Using_Code( CodeExpr_Binary );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_Binary* operator->();
	AST_Expr_Binary* ast;
};

struct CodeExpr_CStyleCast
{
	Using_Code( CodeExpr_CStyleCast );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_CStyleCast* operator->();
	AST_Expr_CStyleCast* ast;
};

struct CodeExpr_FunctionalCast
{
	Using_Code( CodeExpr_FunctionalCast );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_FunctionalCast* operator->();
	AST_Expr_FunctionalCast* ast;
};

struct CodeExpr_CppCast
{
	Using_Code( CodeExpr_CppCast );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_CppCast* operator->();
	AST_Expr_CppCast* ast;
};

struct CodeExpr_Element
{
	Using_Code( CodeExpr_Element );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_Element* operator->();
	AST_Expr_Element* ast;
};

struct CodeExpr_ProcCall
{
	Using_Code( CodeExpr_ProcCall );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_ProcCall* operator->();
	AST_Expr_ProcCall* ast;
};

struct CodeExpr_Decltype
{
	Using_Code( CodeExpr_Decltype );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_Decltype* operator->();
	AST_Expr_Decltype* ast;
};

struct CodeExpr_Comma
{
	Using_Code( CodeExpr_Comma );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_Comma* operator->();
	AST_Expr_Comma* ast;
};

struct CodeExpr_AMS
{
	Using_Code( CodeExpr_AMS );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_AMS* operator->();
	AST_Expr_AMS* ast;
};

struct CodeExpr_Sizeof
{
	Using_Code( CodeExpr_Sizeof );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_Sizeof* operator->();
	AST_Expr_Sizeof* ast;
};

struct CodeExpr_Subscript
{
	Using_Code( CodeExpr_Subscript );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_Subscript* operator->();
	AST_Expr_Subscript* ast;
};

struct CodeExpr_Ternary
{
	Using_Code( CodeExpr_Ternary );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_Ternary* operator->();
	AST_Expr_Ternary* ast;
};

struct CodeExpr_UnaryPrefix
{
	Using_Code( CodeExpr_UnaryPrefix );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_UnaryPrefix* operator->();
	AST_Expr_UnaryPrefix* ast;
};

struct CodeExpr_UnaryPostfix
{
	Using_Code( CodeExpr_UnaryPostfix );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Expr_UnaryPostfix* operator->();
	AST_Expr_UnaryPostfix* ast;
};
#endif

struct CodeExtern
{
	Using_Code( CodeExtern );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Extern* operator->();
	AST_Extern* ast;
};

struct CodeInclude
{
	Using_Code( CodeInclude );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Include* operator->();
	AST_Include* ast;
};

struct CodeFriend
{
	Using_Code( CodeFriend );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Friend* operator->();
	AST_Friend* ast;
};

struct CodeFn
{
	Using_Code( CodeFn );

	void to_string_def( String& result );
	void to_string_fwd( String& result );

	AST* raw();
	operator Code();
	AST_Fn* operator->();
	AST_Fn* ast;
};

struct CodeModule
{
	Using_Code( CodeModule );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Module* operator->();
	AST_Module* ast;
};

struct CodeNS
{
	Using_Code( CodeNS );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_NS* operator->();
	AST_NS* ast;
};

struct CodeOperator
{
	Using_Code( CodeOperator );

	void to_string_def( String& result );
	void to_string_fwd( String& result );

	AST* raw();
	operator Code();
	AST_Operator* operator->();
	AST_Operator* ast;
};

struct CodeOpCast
{
	Using_Code( CodeOpCast );

	void to_string_def( String& result );
	void to_string_fwd( String& result );

	AST* raw();
	operator Code();
	AST_OpCast* operator->();
	AST_OpCast* ast;
};

struct CodePragma
{
	Using_Code( CodePragma );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Pragma* operator->();
	AST_Pragma* ast;
};

struct CodePreprocessCond
{
	Using_Code( CodePreprocessCond );

	void to_string_if( String& result );
	void to_string_ifdef( String& result );
	void to_string_ifndef( String& result );
	void to_string_elif( String& result );
	void to_string_else( String& result );
	void to_string_endif( String& result );

	AST* raw();
	operator Code();
	AST_PreprocessCond* operator->();
	AST_PreprocessCond* ast;
};

#if GEN_EXECUTION_EXPRESSION_SUPPORT
struct CodeStmt
{
	Using_Code( CodeStmt );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt* operator->();
	AST_Stmt* ast;
};

struct CodeStmt_Break
{
	Using_Code( CodeStmt_Break );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_Break* operator->();
	AST_Stmt_Break* ast;
};

struct CodeStmt_Case
{
	Using_Code( CodeStmt_Case );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_Case* operator->();
	AST_Stmt_Case* ast;
};

struct CodeStmt_Continue
{
	Using_Code( CodeStmt_Continue );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_Continue* operator->();
	AST_Stmt_Continue* ast;
};

struct CodeStmt_Decl
{
	Using_Code( CodeStmt_Decl );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_Decl* operator->();
	AST_Stmt_Decl* ast;
};

struct CodeStmt_Do
{
	Using_Code( CodeStmt_Do );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_Do* operator->();
	AST_Stmt_Do* ast;
};

struct CodeStmt_Expr
{
	Using_Code( CodeStmt_Expr );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_Expr* operator->();
	AST_Stmt_Expr* ast;
};

struct CodeStmt_Else
{
	Using_Code( CodeStmt_Else );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_Else* operator->();
	AST_Stmt_Else* ast;
};

struct CodeStmt_If
{
	Using_Code( CodeStmt_If );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_If* operator->();
	AST_Stmt_If* ast;
};

struct CodeStmt_For
{
	Using_Code( CodeStmt_For );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_For* operator->();
	AST_Stmt_For* ast;
};

struct CodeStmt_Goto
{
	Using_Code( CodeStmt_Goto );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_Goto* operator->();
	AST_Stmt_Goto* ast;
};

struct CodeStmt_Label
{
	Using_Code( CodeStmt_Label );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_Label* operator->();
	AST_Stmt_Label* ast;
};

struct CodeStmt_Switch
{
	Using_Code( CodeStmt_Switch );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_Switch* operator->();
	AST_Stmt_Switch* ast;
};

struct CodeStmt_While
{
	Using_Code( CodeStmt_While );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Stmt_While* operator->();
	AST_Stmt_While* ast;
};
#endif

struct CodeTemplate
{
	Using_Code( CodeTemplate );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Template* operator->();
	AST_Template* ast;
};

struct CodeType
{
	Using_Code( CodeType );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Type* operator->();
	AST_Type* ast;
};

struct CodeTypedef
{
	Using_Code( CodeTypedef );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Typedef* operator->();
	AST_Typedef* ast;
};

struct CodeUnion
{
	Using_Code( CodeUnion );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Union* operator->();
	AST_Union* ast;
};

struct CodeUsing
{
	Using_Code( CodeUsing );

	void to_string( String& result );
	void to_string_ns( String& result );

	AST* raw();
	operator Code();
	AST_Using* operator->();
	AST_Using* ast;
};

struct CodeVar
{
	Using_Code( CodeVar );

	void to_string( String& result );

	AST* raw();
	operator Code();
	AST_Var* operator->();
	AST_Var* ast;
};

#undef Define_CodeType
#undef Using_Code

#pragma endregion Code Types

#pragma region AST Types

/*
    Show only relevant members of the AST for its type.
    AST* fields are replaced with Code types.
        - Guards assignemnts to AST* fields to ensure the AST is duplicated if assigned to another parent.
*/

struct AST_Body
{
	char           _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	Code           Front;
	Code           Back;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag )];
	s32            NumEntries;
};

static_assert( sizeof( AST_Body ) == sizeof( AST ), "ERROR: AST_Body is not the same size as AST" );

struct AST_Attributes
{
	union
	{
		char         _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
		StringCached Content;
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Attributes ) == sizeof( AST ), "ERROR: AST_Attributes is not the same size as AST" );

#if 0
struct AST_BaseClass
{
	union {
		char          _PAD_[ sizeof(SpecifierT) * AST::ArrSpecs_Cap + sizeof(AST*) ];
	};
	Code              Prev;
	Code              Next;
	parser::Token*    Tok;
	Code              Parent;
	StringCached      Name;
	CodeT             Type;
	char              _PAD_UNUSED_[ sizeof(ModuleFlag) + sizeof(u32) ];
};
static_assert( sizeof(AST_BaseClass) == sizeof(AST), "ERROR: AST_BaseClass is not the same size as AST");
#endif

struct AST_Comment
{
	union
	{
		char         _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
		StringCached Content;
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Comment ) == sizeof( AST ), "ERROR: AST_Comment is not the same size as AST" );

struct AST_Class
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment    InlineCmt;    // Only supported by forward declarations
			CodeAttributes Attributes;
			char           _PAD_SPECS_[sizeof( AST* )];
			CodeType       ParentType;
			char           _PAD_PARAMS_[sizeof( AST* )];
			CodeBody       Body;
			char           _PAD_PROPERTIES_2_[sizeof( AST* )];
		};
	};

	CodeType       Prev;
	CodeType       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	AccessSpec     ParentAccess;
};

static_assert( sizeof( AST_Class ) == sizeof( AST ), "ERROR: AST_Class is not the same size as AST" );

struct AST_Constructor
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment    InlineCmt;    // Only supported by forward declarations
			char           _PAD_PROPERTIES_[sizeof( AST* ) * 1];
			CodeSpecifiers Specs;
			Code           InitializerList;
			CodeParam      Params;
			Code           Body;
			char           _PAD_PROPERTIES_2_[sizeof( AST* ) * 2];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Constructor ) == sizeof( AST ), "ERROR: AST_Constructor is not the same size as AST" );

struct AST_Define
{
	union
	{
		char         _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
		StringCached Content;
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Define ) == sizeof( AST ), "ERROR: AST_Define is not the same size as AST" );

struct AST_Destructor
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment    InlineCmt;
			char           _PAD_PROPERTIES_[sizeof( AST* ) * 1];
			CodeSpecifiers Specs;
			char           _PAD_PROPERTIES_2_[sizeof( AST* ) * 2];
			Code           Body;
			char           _PAD_PROPERTIES_3_[sizeof( AST* )];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Destructor ) == sizeof( AST ), "ERROR: AST_Destructor is not the same size as AST" );

struct AST_Enum
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment    InlineCmt;
			CodeAttributes Attributes;
			char           _PAD_SPEC_[sizeof( AST* )];
			CodeType       UnderlyingType;
			char           _PAD_PARAMS_[sizeof( AST* )];
			CodeBody       Body;
			char           _PAD_PROPERTIES_2_[sizeof( AST* )];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	char           _PAD_UNUSED_[sizeof( u32 )];
};

static_assert( sizeof( AST_Enum ) == sizeof( AST ), "ERROR: AST_Enum is not the same size as AST" );

struct AST_Exec
{
	union
	{
		char         _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
		StringCached Content;
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Exec ) == sizeof( AST ), "ERROR: AST_Exec is not the same size as AST" );

#if GEN_EXECUTION_EXPRESSION_SUPPORT
struct AST_Expr
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr ) == sizeof( AST ), "ERROR: AST_Expr is not the same size as AST" );

struct AST_Expr_Assign
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_Assign ) == sizeof( AST ), "ERROR: AST_Expr_Assign is not the same size as AST" );

struct AST_Expr_Alignof
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_Alignof ) == sizeof( AST ), "ERROR: AST_Expr_Alignof is not the same size as AST" );

struct AST_Expr_Binary
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_Binary ) == sizeof( AST ), "ERROR: AST_Expr_Binary is not the same size as AST" );

struct AST_Expr_CStyleCast
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_CStyleCast ) == sizeof( AST ), "ERROR: AST_Expr_CStyleCast is not the same size as AST" );

struct AST_Expr_FunctionalCast
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_FunctionalCast ) == sizeof( AST ), "ERROR: AST_Expr_FunctionalCast is not the same size as AST" );

struct AST_Expr_CppCast
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_CppCast ) == sizeof( AST ), "ERROR: AST_Expr_CppCast is not the same size as AST" );

struct AST_Expr_ProcCall
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_ProcCall ) == sizeof( AST ), "ERROR: AST_Expr_Identifier is not the same size as AST" );

struct AST_Expr_Decltype
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_Decltype ) == sizeof( AST ), "ERROR: AST_Expr_Decltype is not the same size as AST" );

struct AST_Expr_Comma
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_Comma ) == sizeof( AST ), "ERROR: AST_Expr_Comma is not the same size as AST" );

struct AST_Expr_AMS
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_AMS ) == sizeof( AST ), "ERROR: AST_Expr_AMS is not the same size as AST" );

struct AST_Expr_Sizeof
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_Sizeof ) == sizeof( AST ), "ERROR: AST_Expr_Sizeof is not the same size as AST" );

struct AST_Expr_Subscript
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_Subscript ) == sizeof( AST ), "ERROR: AST_Expr_Subscript is not the same size as AST" );

struct AST_Expr_Ternary
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_Ternary ) == sizeof( AST ), "ERROR: AST_Expr_Ternary is not the same size as AST" );

struct AST_Expr_UnaryPrefix
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_UnaryPrefix ) == sizeof( AST ), "ERROR: AST_Expr_UnaryPrefix is not the same size as AST" );

struct AST_Expr_UnaryPostfix
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_UnaryPostfix ) == sizeof( AST ), "ERROR: AST_Expr_UnaryPostfix is not the same size as AST" );

struct AST_Expr_Element
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Expr_Element ) == sizeof( AST ), "ERROR: AST_Expr_Element is not the same size as AST" );
#endif

struct AST_Extern
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			char     _PAD_PROPERTIES_[sizeof( AST* ) * 5];
			CodeBody Body;
			char     _PAD_PROPERTIES_2_[sizeof( AST* )];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Extern ) == sizeof( AST ), "ERROR: AST_Extern is not the same size as AST" );

struct AST_Include
{
	union
	{
		char         _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
		StringCached Content;
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Include ) == sizeof( AST ), "ERROR: AST_Include is not the same size as AST" );

struct AST_Friend
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment InlineCmt;
			char        _PAD_PROPERTIES_[sizeof( AST* ) * 4];
			Code        Declaration;
			char        _PAD_PROPERTIES_2_[sizeof( AST* )];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Friend ) == sizeof( AST ), "ERROR: AST_Friend is not the same size as AST" );

struct AST_Fn
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment    InlineCmt;
			CodeAttributes Attributes;
			CodeSpecifiers Specs;
			CodeType       ReturnType;
			CodeParam      Params;
			CodeBody       Body;
			char           _PAD_PROPERTIES_[sizeof( AST* )];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	char           _PAD_UNUSED_[sizeof( u32 )];
};

static_assert( sizeof( AST_Fn ) == sizeof( AST ), "ERROR: AST_Fn is not the same size as AST" );

struct AST_Module
{
	char           _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	char           _PAD_UNUSED_[sizeof( u32 )];
};

static_assert( sizeof( AST_Module ) == sizeof( AST ), "ERROR: AST_Module is not the same size as AST" );

struct AST_NS
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			char     _PAD_PROPERTIES_[sizeof( AST* ) * 5];
			CodeBody Body;
			char     _PAD_PROPERTIES_2_[sizeof( AST* )];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	char           _PAD_UNUSED_[sizeof( u32 )];
};

static_assert( sizeof( AST_NS ) == sizeof( AST ), "ERROR: AST_NS is not the same size as AST" );

struct AST_Operator
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment    InlineCmt;
			CodeAttributes Attributes;
			CodeSpecifiers Specs;
			CodeType       ReturnType;
			CodeParam      Params;
			CodeBody       Body;
			char           _PAD_PROPERTIES_[sizeof( AST* )];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	OperatorT      Op;
};

static_assert( sizeof( AST_Operator ) == sizeof( AST ), "ERROR: AST_Operator is not the same size as AST" );

struct AST_OpCast
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment    InlineCmt;
			char           _PAD_PROPERTIES_[sizeof( AST* )];
			CodeSpecifiers Specs;
			CodeType       ValueType;
			char           _PAD_PROPERTIES_2_[sizeof( AST* )];
			CodeBody       Body;
			char           _PAD_PROPERTIES_3_[sizeof( AST* )];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_OpCast ) == sizeof( AST ), "ERROR: AST_OpCast is not the same size as AST" );

struct AST_Param
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			char     _PAD_PROPERTIES_2_[sizeof( AST* ) * 3];
			CodeType ValueType;
			Code     Macro;
			Code     Value;
			Code     PostNameMacro;    // Thanks Unreal
			                           // char     _PAD_PROPERTIES_3_[sizeof( AST* )];
		};
	};

	CodeParam      Last;
	CodeParam      Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag )];
	s32            NumEntries;
};

static_assert( sizeof( AST_Param ) == sizeof( AST ), "ERROR: AST_Param is not the same size as AST" );

struct AST_Pragma
{
	union
	{
		char         _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
		StringCached Content;
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Pragma ) == sizeof( AST ), "ERROR: AST_Pragma is not the same size as AST" );

struct AST_PreprocessCond
{
	union
	{
		char         _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
		StringCached Content;
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_PreprocessCond ) == sizeof( AST ), "ERROR: AST_PreprocessCond is not the same size as AST" );

struct AST_Specifiers
{
	SpecifierT     ArrSpecs[AST::ArrSpecs_Cap];
	CodeSpecifiers NextSpecs;
	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag )];
	s32            NumEntries;
};

static_assert( sizeof( AST_Specifiers ) == sizeof( AST ), "ERROR: AST_Specifier is not the same size as AST" );

#if GEN_EXECUTION_EXPRESSION_SUPPORT
struct AST_Stmt
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt ) == sizeof( AST ), "ERROR: AST_Stmt is not the same size as AST" );

struct AST_Stmt_Break
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_Break ) == sizeof( AST ), "ERROR: AST_Stmt_Break is not the same size as AST" );

struct AST_Stmt_Case
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_Case ) == sizeof( AST ), "ERROR: AST_Stmt_Case is not the same size as AST" );

struct AST_Stmt_Continue
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_Continue ) == sizeof( AST ), "ERROR: AST_Stmt_Continue is not the same size as AST" );

struct AST_Stmt_Decl
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_Decl ) == sizeof( AST ), "ERROR: AST_Stmt_Decl is not the same size as AST" );

struct AST_Stmt_Do
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_Do ) == sizeof( AST ), "ERROR: AST_Stmt_Do is not the same size as AST" );

struct AST_Stmt_Expr
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_Expr ) == sizeof( AST ), "ERROR: AST_Stmt_Expr is not the same size as AST" );

struct AST_Stmt_Else
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_Else ) == sizeof( AST ), "ERROR: AST_Stmt_Else is not the same size as AST" );

struct AST_Stmt_If
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_If ) == sizeof( AST ), "ERROR: AST_Stmt_If is not the same size as AST" );

struct AST_Stmt_For
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_For ) == sizeof( AST ), "ERROR: AST_Stmt_For is not the same size as AST" );

struct AST_Stmt_Goto
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_Goto ) == sizeof( AST ), "ERROR: AST_Stmt_Goto is not the same size as AST" );

struct AST_Stmt_Label
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_Label ) == sizeof( AST ), "ERROR: AST_Stmt_Label is not the same size as AST" );

struct AST_Stmt_Switch
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_Switch ) == sizeof( AST ), "ERROR: AST_Stmt_Switch is not the same size as AST" );

struct AST_Stmt_While
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];
	} CodeExpr Prev;

	CodeExpr       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag ) + sizeof( u32 )];
};

static_assert( sizeof( AST_Stmt_While ) == sizeof( AST ), "ERROR: AST_Stmt_While is not the same size as AST" );
#endif

struct AST_Struct
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment    InlineCmt;
			CodeAttributes Attributes;
			char           _PAD_SPECS_[sizeof( AST* )];
			CodeType       ParentType;
			char           _PAD_PARAMS_[sizeof( AST* )];
			CodeBody       Body;
			char           _PAD_PROPERTIES_2_[sizeof( AST* )];
		};
	};

	CodeType       Prev;
	CodeType       Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	AccessSpec     ParentAccess;
};

static_assert( sizeof( AST_Struct ) == sizeof( AST ), "ERROR: AST_Struct is not the same size as AST" );

struct AST_Template
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			char      _PAD_PROPERTIES_[sizeof( AST* ) * 4];
			CodeParam Params;
			Code      Declaration;
			char      _PAD_PROPERTIES_2_[sizeof( AST* )];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	char           _PAD_UNUSED_[sizeof( u32 )];
};

static_assert( sizeof( AST_Template ) == sizeof( AST ), "ERROR: AST_Template is not the same size as AST" );

#if 0
// WIP... The type ast is going to become more advanced and lead to a major change to AST design.
struct AST_Type
{
	union {
		char               _PAD_[ sizeof(SpecifierT) * AST::ArrSpecs_Cap + sizeof(AST*) ];
		struct
		{
			char           _PAD_INLINE_CMT_[ sizeof(AST*) ];
			CodeAttributes Attributes;
			CodeSpecifiers Specs;
			Code           QualifierID;
			// CodeType       ReturnType;      // Only used for function signatures
			// CodeParam      Params;          // Only used for function signatures
			Code           ArrExpr;
			// CodeSpecifiers SpecsFuncSuffix; // Only used for function signatures
		};
	};
	Code                   Prev;
	Code                   Next;
	parser::Token*         Tok;
	Code                   Parent;
	StringCached           Name;
	CodeT                  Type;
	char 			       _PAD_UNUSED_[ sizeof(ModuleFlag) ];
	b32                    IsParamPack;
};
static_assert( sizeof(AST_Type) == sizeof(AST), "ERROR: AST_Type is not the same size as AST");
#endif

struct AST_Type
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			char           _PAD_INLINE_CMT_[sizeof( AST* )];
			CodeAttributes Attributes;
			CodeSpecifiers Specs;
			CodeType       ReturnType;    // Only used for function signatures
			CodeParam      Params;        // Only used for function signatures
			Code           ArrExpr;
			CodeSpecifiers SpecsFuncSuffix;    // Only used for function signatures
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	char           _PAD_UNUSED_[sizeof( ModuleFlag )];
	b32            IsParamPack;
};

static_assert( sizeof( AST_Type ) == sizeof( AST ), "ERROR: AST_Type is not the same size as AST" );

struct AST_Typedef
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment InlineCmt;
			char        _PAD_PROPERTIES_[sizeof( AST* ) * 2];
			Code        UnderlyingType;
			char        _PAD_PROPERTIES_2_[sizeof( AST* ) * 3];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	b32            IsFunction;
};

static_assert( sizeof( AST_Typedef ) == sizeof( AST ), "ERROR: AST_Typedef is not the same size as AST" );

struct AST_Union
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			char           _PAD_INLINE_CMT_[sizeof( AST* )];
			CodeAttributes Attributes;
			char           _PAD_PROPERTIES_[sizeof( AST* ) * 3];
			CodeBody       Body;
			char           _PAD_PROPERTIES_2_[sizeof( AST* )];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	char           _PAD_UNUSED_[sizeof( u32 )];
};

static_assert( sizeof( AST_Union ) == sizeof( AST ), "ERROR: AST_Union is not the same size as AST" );

struct AST_Using
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment    InlineCmt;
			CodeAttributes Attributes;
			char           _PAD_SPECS_[sizeof( AST* )];
			CodeType       UnderlyingType;
			char           _PAD_PROPERTIES_[sizeof( AST* ) * 3];
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	char           _PAD_UNUSED_[sizeof( u32 )];
};

static_assert( sizeof( AST_Using ) == sizeof( AST ), "ERROR: AST_Using is not the same size as AST" );

struct AST_Var
{
	union
	{
		char _PAD_[sizeof( SpecifierT ) * AST::ArrSpecs_Cap + sizeof( AST* )];

		struct
		{
			CodeComment    InlineCmt;
			CodeAttributes Attributes;
			CodeSpecifiers Specs;
			CodeType       ValueType;
			Code           BitfieldSize;
			Code           Value;
			CodeVar        NextVar;
		};
	};

	Code           Prev;
	Code           Next;
	parser::Token* Tok;
	Code           Parent;
	StringCached   Name;
	CodeT          Type;
	ModuleFlag     ModuleFlags;
	s32            VarConstructorInit;
};

static_assert( sizeof( AST_Var ) == sizeof( AST ), "ERROR: AST_Var is not the same size as AST" );

#pragma endregion AST Types

#pragma endregion AST

#pragma region Gen Interface

// Initialize the library.
// This currently just initializes the CodePool.
void init();

// Currently manually free's the arenas, code for checking for leaks.
// However on Windows at least, it doesn't need to occur as the OS will clean up after the process.
void deinit();

// Clears the allocations, but doesn't return to the heap, the calls init() again.
// Ease of use.
void reset();

// Used internally to retrive or make string allocations.
// Strings are stored in a series of string arenas of fixed size (SizePer_StringArena)
StringCached get_cached_string( StrC str );

/*
    This provides a fresh Code AST.
    The gen interface use this as their method from getting a new AST object from the CodePool.
    Use this if you want to make your own API for formatting the supported Code Types.
*/
Code make_code();

// Set these before calling gen's init() procedure.

void set_allocator_data_arrays( AllocatorInfo data_array_allocator );
void set_allocator_code_pool( AllocatorInfo pool_allocator );
void set_allocator_lexer( AllocatorInfo lex_allocator );
void set_allocator_string_arena( AllocatorInfo string_allocator );
void set_allocator_string_table( AllocatorInfo string_allocator );
void set_allocator_type_table( AllocatorInfo type_reg_allocator );

#pragma region Upfront

CodeAttributes def_attributes( StrC content );
CodeComment    def_comment( StrC content );

CodeClass def_class(
    StrC           name,
    Code           body           = NoCode,
    CodeType       parent         = NoCode,
    AccessSpec     access         = AccessSpec::Default,
    CodeAttributes attributes     = NoCode,
    ModuleFlag     mflags         = ModuleFlag::None,
    CodeType*      interfaces     = nullptr,
    s32            num_interfaces = 0
);

CodeConstructor def_constructor( CodeParam params = NoCode, Code initializer_list = NoCode, Code body = NoCode );

CodeDefine def_define( StrC name, StrC content );

CodeDestructor def_destructor( Code body = NoCode, CodeSpecifiers specifiers = NoCode );

CodeEnum def_enum(
    StrC           name,
    Code           body       = NoCode,
    CodeType       type       = NoCode,
    EnumT          specifier  = EnumRegular,
    CodeAttributes attributes = NoCode,
    ModuleFlag     mflags     = ModuleFlag::None
);

CodeExec   def_execution( StrC content );
CodeExtern def_extern_link( StrC name, Code body );
CodeFriend def_friend( Code symbol );

CodeFn def_function(
    StrC           name,
    CodeParam      params     = NoCode,
    CodeType       ret_type   = NoCode,
    Code           body       = NoCode,
    CodeSpecifiers specifiers = NoCode,
    CodeAttributes attributes = NoCode,
    ModuleFlag     mflags     = ModuleFlag::None
);

CodeInclude def_include( StrC content, bool foreign = false );
CodeModule  def_module( StrC name, ModuleFlag mflags = ModuleFlag::None );
CodeNS      def_namespace( StrC name, Code body, ModuleFlag mflags = ModuleFlag::None );

CodeOperator def_operator(
    OperatorT      op,
    StrC           nspace,
    CodeParam      params     = NoCode,
    CodeType       ret_type   = NoCode,
    Code           body       = NoCode,
    CodeSpecifiers specifiers = NoCode,
    CodeAttributes attributes = NoCode,
    ModuleFlag     mflags     = ModuleFlag::None
);

CodeOpCast def_operator_cast( CodeType type, Code body = NoCode, CodeSpecifiers specs = NoCode );

CodeParam  def_param( CodeType type, StrC name, Code value = NoCode );
CodePragma def_pragma( StrC directive );

CodePreprocessCond def_preprocess_cond( EPreprocessCond type, StrC content );

CodeSpecifiers def_specifier( SpecifierT specifier );

CodeStruct def_struct(
    StrC           name,
    Code           body           = NoCode,
    CodeType       parent         = NoCode,
    AccessSpec     access         = AccessSpec::Default,
    CodeAttributes attributes     = NoCode,
    ModuleFlag     mflags         = ModuleFlag::None,
    CodeType*      interfaces     = nullptr,
    s32            num_interfaces = 0
);

CodeTemplate def_template( CodeParam params, Code definition, ModuleFlag mflags = ModuleFlag::None );

CodeType    def_type( StrC name, Code arrayexpr = NoCode, CodeSpecifiers specifiers = NoCode, CodeAttributes attributes = NoCode );
CodeTypedef def_typedef( StrC name, Code type, CodeAttributes attributes = NoCode, ModuleFlag mflags = ModuleFlag::None );

CodeUnion def_union( StrC name, Code body, CodeAttributes attributes = NoCode, ModuleFlag mflags = ModuleFlag::None );

CodeUsing def_using( StrC name, CodeType type = NoCode, CodeAttributes attributess = NoCode, ModuleFlag mflags = ModuleFlag::None );

CodeUsing def_using_namespace( StrC name );

CodeVar def_variable(
    CodeType       type,
    StrC           name,
    Code           value      = NoCode,
    CodeSpecifiers specifiers = NoCode,
    CodeAttributes attributes = NoCode,
    ModuleFlag     mflags     = ModuleFlag::None
);

// Constructs an empty body. Use AST::validate_body() to check if the body is was has valid entries.
CodeBody def_body( CodeT type );

// There are two options for defining a struct body, either varadically provided with the args macro to auto-deduce the arg num,
/// or provide as an array of Code objects.

CodeBody       def_class_body( s32 num, ... );
CodeBody       def_class_body( s32 num, Code* codes );
CodeBody       def_enum_body( s32 num, ... );
CodeBody       def_enum_body( s32 num, Code* codes );
CodeBody       def_export_body( s32 num, ... );
CodeBody       def_export_body( s32 num, Code* codes );
CodeBody       def_extern_link_body( s32 num, ... );
CodeBody       def_extern_link_body( s32 num, Code* codes );
CodeBody       def_function_body( s32 num, ... );
CodeBody       def_function_body( s32 num, Code* codes );
CodeBody       def_global_body( s32 num, ... );
CodeBody       def_global_body( s32 num, Code* codes );
CodeBody       def_namespace_body( s32 num, ... );
CodeBody       def_namespace_body( s32 num, Code* codes );
CodeParam      def_params( s32 num, ... );
CodeParam      def_params( s32 num, CodeParam* params );
CodeSpecifiers def_specifiers( s32 num, ... );
CodeSpecifiers def_specifiers( s32 num, SpecifierT* specs );
CodeBody       def_struct_body( s32 num, ... );
CodeBody       def_struct_body( s32 num, Code* codes );
CodeBody       def_union_body( s32 num, ... );
CodeBody       def_union_body( s32 num, Code* codes );

#pragma endregion Upfront

#pragma region Parsing

// TODO(Ed) : Implmeent the new parser API design.

#if 0
namespace parser {
	struct StackNode
	{
		StackNode* Prev;

		Token Start;
		Token Name;       // The name of the AST node (if parsed)
		StrC  FailedProc; // The name of the procedure that failed
	};
	// Stack nodes are allocated the error's allocator

	struct Error
	{
		String     message;
		StackNode* context_stack;
	};
}

struct ParseInfo

	Arena FileMem;
	Arena TokMem;
	Arena CodeMem;

	FileContents         FileContent;
	Array<parser::Token> Tokens;
	Array<parser::Error> Errors;
	// Errors are allocated to a dedicated general arena.
;

CodeBody parse_file( StrC path );
#endif

CodeClass       parse_class( StrC class_def );
CodeConstructor parse_constructor( StrC constructor_def );
CodeDestructor  parse_destructor( StrC destructor_def );
CodeEnum        parse_enum( StrC enum_def );
CodeBody        parse_export_body( StrC export_def );
CodeExtern      parse_extern_link( StrC exten_link_def );
CodeFriend      parse_friend( StrC friend_def );
CodeFn          parse_function( StrC fn_def );
CodeBody        parse_global_body( StrC body_def );
CodeNS          parse_namespace( StrC namespace_def );
CodeOperator    parse_operator( StrC operator_def );
CodeOpCast      parse_operator_cast( StrC operator_def );
CodeStruct      parse_struct( StrC struct_def );
CodeTemplate    parse_template( StrC template_def );
CodeType        parse_type( StrC type_def );
CodeTypedef     parse_typedef( StrC typedef_def );
CodeUnion       parse_union( StrC union_def );
CodeUsing       parse_using( StrC using_def );
CodeVar         parse_variable( StrC var_def );

#pragma endregion Parsing

#pragma region Untyped text

sw token_fmt_va( char* buf, uw buf_size, s32 num_tokens, va_list va );
//! Do not use directly. Use the token_fmt macro instead.
StrC token_fmt_impl( sw, ... );

Code untyped_str( StrC content );
Code untyped_fmt( char const* fmt, ... );
Code untyped_token_fmt( char const* fmt, s32 num_tokens, ... );

#pragma endregion Untyped text

#pragma endregion Gen Interface

#pragma region Inlines

inline void AST::append( AST* other )
{
	if ( other->Parent )
		other = other->duplicate();

	other->Parent = this;

	if ( Front == nullptr )
	{
		Front = other;
		Back  = other;

		NumEntries++;
		return;
	}

	AST* Current  = Back;
	Current->Next = other;
	other->Prev   = Current;
	Back          = other;
	NumEntries++;
}

inline Code& AST::entry( u32 idx )
{
	AST** current = &Front;
	while ( idx >= 0 && current != nullptr )
	{
		if ( idx == 0 )
			return *rcast( Code*, current );

		current = &( *current )->Next;
		idx--;
	}

	return *rcast( Code*, current );
}

inline bool AST::has_entries()
{
	return NumEntries > 0;
}

inline char const* AST::type_str()
{
	return ECode::to_str( Type );
}

inline AST::operator Code()
{
	return { this };
}

inline Code& Code::operator++()
{
	if ( ast )
		ast = ast->Next;

	return *this;
}

inline void CodeClass::add_interface( CodeType type )
{
	CodeType possible_slot = ast->ParentType;
	if ( possible_slot.ast )
	{
		// Were adding an interface to parent type, so we need to make sure the parent type is public.
		ast->ParentAccess = AccessSpec::Public;
		// If your planning on adding a proper parent,
		// then you'll need to move this over to ParentType->next and update ParentAccess accordingly.
	}

	while ( possible_slot.ast != nullptr )
	{
		possible_slot.ast = (AST_Type*)possible_slot->Next.ast;
	}

	possible_slot.ast = type.ast;
}

inline void CodeParam::append( CodeParam other )
{
	AST* self  = (AST*)ast;
	AST* entry = (AST*)other.ast;

	if ( entry->Parent )
		entry = entry->duplicate();

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

inline CodeParam CodeParam::get( s32 idx )
{
	CodeParam param = *this;
	do
	{
		if ( ! ++param )
			return { nullptr };

		param = { (AST_Param*)param.raw()->Next };
	} while ( --idx );

	return param;
}

inline bool CodeParam::has_entries()
{
	return ast->NumEntries > 0;
}

inline CodeParam& CodeParam::operator++()
{
	ast = ast->Next.ast;
	return *this;
}

inline void CodeStruct::add_interface( CodeType type )
{
	CodeType possible_slot = ast->ParentType;
	if ( possible_slot.ast )
	{
		// Were adding an interface to parent type, so we need to make sure the parent type is public.
		ast->ParentAccess = AccessSpec::Public;
		// If your planning on adding a proper parent,
		// then you'll need to move this over to ParentType->next and update ParentAccess accordingly.
	}

	while ( possible_slot.ast != nullptr )
	{
		possible_slot.ast = (AST_Type*)possible_slot->Next.ast;
	}

	possible_slot.ast = type.ast;
}

inline CodeBody def_body( CodeT type )
{
	switch ( type )
	{
		using namespace ECode;
		case Class_Body :
		case Enum_Body :
		case Export_Body :
		case Extern_Linkage :
		case Function_Body :
		case Global_Body :
		case Namespace_Body :
		case Struct_Body :
		case Union_Body :
			break;

		default :
			log_failure( "def_body: Invalid type %s", (char const*)ECode::to_str( type ) );
			return (CodeBody)Code::Invalid;
	}

	Code result  = make_code();
	result->Type = type;
	return (CodeBody)result;
}

inline StrC token_fmt_impl( sw num, ... )
{
	local_persist thread_local char buf[GEN_PRINTF_MAXLEN] = { 0 };
	mem_set( buf, 0, GEN_PRINTF_MAXLEN );

	va_list va;
	va_start( va, num );
	sw result = token_fmt_va( buf, GEN_PRINTF_MAXLEN, num, va );
	va_end( va );

	return { result, buf };
}

#pragma region generated code inline implementation

inline char const* Code::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code Code::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool Code::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool Code::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void Code::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline Code& Code::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool Code::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool Code::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline Code::operator bool()
{
	return ast != nullptr;
}

inline char const* CodeBody::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeBody::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeBody::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeBody::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeBody::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeBody& CodeBody::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeBody::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeBody::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeBody::operator bool()
{
	return ast != nullptr;
}

inline char const* CodeAttributes::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeAttributes::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeAttributes::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeAttributes::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeAttributes::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeAttributes& CodeAttributes::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeAttributes::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeAttributes::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeAttributes::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeAttributes::raw()
{
	return rcast( AST*, ast );
}

inline CodeAttributes::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Attributes* CodeAttributes::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeComment::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeComment::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeComment::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeComment::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeComment::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeComment& CodeComment::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeComment::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeComment::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeComment::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeComment::raw()
{
	return rcast( AST*, ast );
}

inline CodeComment::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Comment* CodeComment::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeConstructor::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeConstructor::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeConstructor::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeConstructor::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeConstructor::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeConstructor& CodeConstructor::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeConstructor::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeConstructor::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeConstructor::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeConstructor::raw()
{
	return rcast( AST*, ast );
}

inline CodeConstructor::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Constructor* CodeConstructor::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeClass::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeClass::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeClass::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeClass::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeClass::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeClass& CodeClass::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeClass::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeClass::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeClass::operator bool()
{
	return ast != nullptr;
}

inline char const* CodeDefine::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeDefine::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeDefine::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeDefine::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeDefine::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeDefine& CodeDefine::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeDefine::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeDefine::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeDefine::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeDefine::raw()
{
	return rcast( AST*, ast );
}

inline CodeDefine::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Define* CodeDefine::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeDestructor::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeDestructor::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeDestructor::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeDestructor::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeDestructor::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeDestructor& CodeDestructor::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeDestructor::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeDestructor::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeDestructor::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeDestructor::raw()
{
	return rcast( AST*, ast );
}

inline CodeDestructor::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Destructor* CodeDestructor::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeEnum::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeEnum::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeEnum::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeEnum::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeEnum::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeEnum& CodeEnum::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeEnum::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeEnum::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeEnum::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeEnum::raw()
{
	return rcast( AST*, ast );
}

inline CodeEnum::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Enum* CodeEnum::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeExec::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeExec::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeExec::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeExec::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeExec::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeExec& CodeExec::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeExec::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeExec::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeExec::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeExec::raw()
{
	return rcast( AST*, ast );
}

inline CodeExec::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Exec* CodeExec::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeExtern::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeExtern::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeExtern::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeExtern::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeExtern::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeExtern& CodeExtern::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeExtern::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeExtern::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeExtern::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeExtern::raw()
{
	return rcast( AST*, ast );
}

inline CodeExtern::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Extern* CodeExtern::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeFriend::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeFriend::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeFriend::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeFriend::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeFriend::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeFriend& CodeFriend::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeFriend::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeFriend::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeFriend::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeFriend::raw()
{
	return rcast( AST*, ast );
}

inline CodeFriend::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Friend* CodeFriend::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeFn::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeFn::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeFn::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeFn::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeFn::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeFn& CodeFn::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeFn::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeFn::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeFn::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeFn::raw()
{
	return rcast( AST*, ast );
}

inline CodeFn::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Fn* CodeFn::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeInclude::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeInclude::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeInclude::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeInclude::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeInclude::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeInclude& CodeInclude::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeInclude::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeInclude::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeInclude::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeInclude::raw()
{
	return rcast( AST*, ast );
}

inline CodeInclude::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Include* CodeInclude::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeModule::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeModule::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeModule::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeModule::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeModule::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeModule& CodeModule::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeModule::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeModule::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeModule::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeModule::raw()
{
	return rcast( AST*, ast );
}

inline CodeModule::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Module* CodeModule::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeNS::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeNS::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeNS::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeNS::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeNS::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeNS& CodeNS::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeNS::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeNS::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeNS::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeNS::raw()
{
	return rcast( AST*, ast );
}

inline CodeNS::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_NS* CodeNS::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeOperator::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeOperator::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeOperator::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeOperator::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeOperator::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeOperator& CodeOperator::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeOperator::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeOperator::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeOperator::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeOperator::raw()
{
	return rcast( AST*, ast );
}

inline CodeOperator::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Operator* CodeOperator::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeOpCast::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeOpCast::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeOpCast::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeOpCast::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeOpCast::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeOpCast& CodeOpCast::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeOpCast::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeOpCast::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeOpCast::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeOpCast::raw()
{
	return rcast( AST*, ast );
}

inline CodeOpCast::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_OpCast* CodeOpCast::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeParam::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeParam::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeParam::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeParam::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeParam::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeParam& CodeParam::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeParam::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeParam::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeParam::operator bool()
{
	return ast != nullptr;
}

inline char const* CodePragma::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodePragma::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodePragma::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodePragma::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodePragma::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodePragma& CodePragma::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodePragma::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodePragma::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodePragma::operator bool()
{
	return ast != nullptr;
}

inline AST* CodePragma::raw()
{
	return rcast( AST*, ast );
}

inline CodePragma::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Pragma* CodePragma::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodePreprocessCond::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodePreprocessCond::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodePreprocessCond::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodePreprocessCond::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodePreprocessCond::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodePreprocessCond& CodePreprocessCond::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodePreprocessCond::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodePreprocessCond::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodePreprocessCond::operator bool()
{
	return ast != nullptr;
}

inline AST* CodePreprocessCond::raw()
{
	return rcast( AST*, ast );
}

inline CodePreprocessCond::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_PreprocessCond* CodePreprocessCond::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeSpecifiers::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeSpecifiers::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeSpecifiers::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeSpecifiers::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeSpecifiers::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeSpecifiers& CodeSpecifiers::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeSpecifiers::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeSpecifiers::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeSpecifiers::operator bool()
{
	return ast != nullptr;
}

inline char const* CodeStruct::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeStruct::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeStruct::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeStruct::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeStruct::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeStruct& CodeStruct::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeStruct::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeStruct::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeStruct::operator bool()
{
	return ast != nullptr;
}

inline char const* CodeTemplate::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeTemplate::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeTemplate::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeTemplate::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeTemplate::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeTemplate& CodeTemplate::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeTemplate::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeTemplate::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeTemplate::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeTemplate::raw()
{
	return rcast( AST*, ast );
}

inline CodeTemplate::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Template* CodeTemplate::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeType::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeType::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeType::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeType::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeType::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeType& CodeType::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeType::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeType::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeType::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeType::raw()
{
	return rcast( AST*, ast );
}

inline CodeType::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Type* CodeType::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeTypedef::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeTypedef::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeTypedef::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeTypedef::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeTypedef::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeTypedef& CodeTypedef::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeTypedef::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeTypedef::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeTypedef::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeTypedef::raw()
{
	return rcast( AST*, ast );
}

inline CodeTypedef::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Typedef* CodeTypedef::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeUnion::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeUnion::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeUnion::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeUnion::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeUnion::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeUnion& CodeUnion::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeUnion::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeUnion::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeUnion::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeUnion::raw()
{
	return rcast( AST*, ast );
}

inline CodeUnion::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Union* CodeUnion::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeUsing::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeUsing::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeUsing::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeUsing::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeUsing::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeUsing& CodeUsing::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeUsing::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeUsing::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeUsing::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeUsing::raw()
{
	return rcast( AST*, ast );
}

inline CodeUsing::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Using* CodeUsing::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

inline char const* CodeVar::debug_str()
{
	if ( ast == nullptr )
		return "Code::debug_str: AST is null!";
	return rcast( AST*, ast )->debug_str();
}

inline Code CodeVar::duplicate()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::duplicate: Cannot duplicate code, AST is null!" );
		return Code::Invalid;
	}
	return { rcast( AST*, ast )->duplicate() };
}

inline bool CodeVar::is_equal( Code other )
{
	if ( ast == nullptr || other.ast == nullptr )
	{
		return ast == nullptr && other.ast == nullptr;
	}
	return rcast( AST*, ast )->is_equal( other.ast );
}

inline bool CodeVar::is_valid()
{
	return (AST*)ast != nullptr && rcast( AST*, ast )->Type != CodeT::Invalid;
}

inline void CodeVar::set_global()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::set_global: Cannot set code as global, AST is null!" );
		return;
	}
	rcast( AST*, ast )->Parent = Code::Global.ast;
}

inline CodeVar& CodeVar::operator=( Code other )
{
	if ( other.ast && other->Parent )
	{
		ast                        = rcast( decltype( ast ), other.ast->duplicate() );
		rcast( AST*, ast )->Parent = nullptr;
	}
	ast = rcast( decltype( ast ), other.ast );
	return *this;
}

inline bool CodeVar::operator==( Code other )
{
	return (AST*)ast == other.ast;
}

inline bool CodeVar::operator!=( Code other )
{
	return (AST*)ast != other.ast;
}

inline CodeVar::operator bool()
{
	return ast != nullptr;
}

inline AST* CodeVar::raw()
{
	return rcast( AST*, ast );
}

inline CodeVar::operator Code()
{
	return *rcast( Code*, this );
}

inline AST_Var* CodeVar::operator->()
{
	if ( ast == nullptr )
	{
		log_failure( "Attempt to dereference a nullptr!" );
		return nullptr;
	}
	return ast;
}

#pragma endregion generated code inline implementation

#pragma region generated AST/Code cast implementation

inline AST::operator CodeBody()
{
	return { rcast( AST_Body*, this ) };
}

inline Code::operator CodeBody() const
{
	return { (AST_Body*)ast };
}

inline AST::operator CodeAttributes()
{
	return { rcast( AST_Attributes*, this ) };
}

inline Code::operator CodeAttributes() const
{
	return { (AST_Attributes*)ast };
}

inline AST::operator CodeComment()
{
	return { rcast( AST_Comment*, this ) };
}

inline Code::operator CodeComment() const
{
	return { (AST_Comment*)ast };
}

inline AST::operator CodeConstructor()
{
	return { rcast( AST_Constructor*, this ) };
}

inline Code::operator CodeConstructor() const
{
	return { (AST_Constructor*)ast };
}

inline AST::operator CodeClass()
{
	return { rcast( AST_Class*, this ) };
}

inline Code::operator CodeClass() const
{
	return { (AST_Class*)ast };
}

inline AST::operator CodeDefine()
{
	return { rcast( AST_Define*, this ) };
}

inline Code::operator CodeDefine() const
{
	return { (AST_Define*)ast };
}

inline AST::operator CodeDestructor()
{
	return { rcast( AST_Destructor*, this ) };
}

inline Code::operator CodeDestructor() const
{
	return { (AST_Destructor*)ast };
}

inline AST::operator CodeEnum()
{
	return { rcast( AST_Enum*, this ) };
}

inline Code::operator CodeEnum() const
{
	return { (AST_Enum*)ast };
}

inline AST::operator CodeExec()
{
	return { rcast( AST_Exec*, this ) };
}

inline Code::operator CodeExec() const
{
	return { (AST_Exec*)ast };
}

inline AST::operator CodeExtern()
{
	return { rcast( AST_Extern*, this ) };
}

inline Code::operator CodeExtern() const
{
	return { (AST_Extern*)ast };
}

inline AST::operator CodeFriend()
{
	return { rcast( AST_Friend*, this ) };
}

inline Code::operator CodeFriend() const
{
	return { (AST_Friend*)ast };
}

inline AST::operator CodeFn()
{
	return { rcast( AST_Fn*, this ) };
}

inline Code::operator CodeFn() const
{
	return { (AST_Fn*)ast };
}

inline AST::operator CodeInclude()
{
	return { rcast( AST_Include*, this ) };
}

inline Code::operator CodeInclude() const
{
	return { (AST_Include*)ast };
}

inline AST::operator CodeModule()
{
	return { rcast( AST_Module*, this ) };
}

inline Code::operator CodeModule() const
{
	return { (AST_Module*)ast };
}

inline AST::operator CodeNS()
{
	return { rcast( AST_NS*, this ) };
}

inline Code::operator CodeNS() const
{
	return { (AST_NS*)ast };
}

inline AST::operator CodeOperator()
{
	return { rcast( AST_Operator*, this ) };
}

inline Code::operator CodeOperator() const
{
	return { (AST_Operator*)ast };
}

inline AST::operator CodeOpCast()
{
	return { rcast( AST_OpCast*, this ) };
}

inline Code::operator CodeOpCast() const
{
	return { (AST_OpCast*)ast };
}

inline AST::operator CodeParam()
{
	return { rcast( AST_Param*, this ) };
}

inline Code::operator CodeParam() const
{
	return { (AST_Param*)ast };
}

inline AST::operator CodePragma()
{
	return { rcast( AST_Pragma*, this ) };
}

inline Code::operator CodePragma() const
{
	return { (AST_Pragma*)ast };
}

inline AST::operator CodePreprocessCond()
{
	return { rcast( AST_PreprocessCond*, this ) };
}

inline Code::operator CodePreprocessCond() const
{
	return { (AST_PreprocessCond*)ast };
}

inline AST::operator CodeSpecifiers()
{
	return { rcast( AST_Specifiers*, this ) };
}

inline Code::operator CodeSpecifiers() const
{
	return { (AST_Specifiers*)ast };
}

inline AST::operator CodeStruct()
{
	return { rcast( AST_Struct*, this ) };
}

inline Code::operator CodeStruct() const
{
	return { (AST_Struct*)ast };
}

inline AST::operator CodeTemplate()
{
	return { rcast( AST_Template*, this ) };
}

inline Code::operator CodeTemplate() const
{
	return { (AST_Template*)ast };
}

inline AST::operator CodeType()
{
	return { rcast( AST_Type*, this ) };
}

inline Code::operator CodeType() const
{
	return { (AST_Type*)ast };
}

inline AST::operator CodeTypedef()
{
	return { rcast( AST_Typedef*, this ) };
}

inline Code::operator CodeTypedef() const
{
	return { (AST_Typedef*)ast };
}

inline AST::operator CodeUnion()
{
	return { rcast( AST_Union*, this ) };
}

inline Code::operator CodeUnion() const
{
	return { (AST_Union*)ast };
}

inline AST::operator CodeUsing()
{
	return { rcast( AST_Using*, this ) };
}

inline Code::operator CodeUsing() const
{
	return { (AST_Using*)ast };
}

inline AST::operator CodeVar()
{
	return { rcast( AST_Var*, this ) };
}

inline Code::operator CodeVar() const
{
	return { (AST_Var*)ast };
}

#pragma endregion generated AST / Code cast implementation

#pragma endregion Inlines

#pragma region Constants

#ifndef GEN_GLOBAL_BUCKET_SIZE
#define GEN_GLOBAL_BUCKET_SIZE megabytes( 8 )
#endif
#ifndef GEN_CODEPOOL_NUM_BLOCKS
#define GEN_CODEPOOL_NUM_BLOCKS kilobytes( 16 )
#endif
#ifndef GEN_SIZE_PER_STRING_ARENA
#define GEN_SIZE_PER_STRING_ARENA megabytes( 1 )
#endif
#ifndef GEN_MAX_COMMENT_LINE_LENGTH
#define GEN_MAX_COMMENT_LINE_LENGTH 1024
#endif
#ifndef GEN_MAX_NAME_LENGTH
#define GEN_MAX_NAME_LENGTH 128
#endif
#ifndef GEN_MAX_UNTYPED_STR_LENGTH
#define GEN_MAX_UNTYPED_STR_LENGTH megabytes( 1 )
#endif
#ifndef GEN_TOKEN_FMT_TOKEN_MAP_MEM_SIZE
#define GEN_TOKEN_FMT_TOKEN_MAP_MEM_SIZE kilobytes( 4 )
#endif
#ifndef GEN_LEX_ALLOCATOR_SIZE
#define GEN_LEX_ALLOCATOR_SIZE megabytes( 4 )
#endif
#ifndef GEN_BUILDER_STR_BUFFER_RESERVE
#define GEN_BUILDER_STR_BUFFER_RESERVE megabytes( 2 )
#endif

// These constexprs are used for allocation behavior of data structures
// or string handling while constructing or serializing.
// Change them to suit your needs.

constexpr s32 InitSize_DataArrays = 16;

// NOTE: This limits the maximum size of an allocation
// If you are generating a string larger than this, increase the size of the bucket here.
constexpr uw  Global_BucketSize         = GEN_GLOBAL_BUCKET_SIZE;
constexpr s32 CodePool_NumBlocks        = GEN_CODEPOOL_NUM_BLOCKS;
constexpr s32 SizePer_StringArena       = GEN_SIZE_PER_STRING_ARENA;

constexpr s32 MaxCommentLineLength      = GEN_MAX_COMMENT_LINE_LENGTH;
constexpr s32 MaxNameLength             = GEN_MAX_NAME_LENGTH;
constexpr s32 MaxUntypedStrLength       = GEN_MAX_UNTYPED_STR_LENGTH;
constexpr s32 TokenFmt_TokenMap_MemSize = GEN_TOKEN_FMT_TOKEN_MAP_MEM_SIZE;
constexpr s32 LexAllocator_Size         = GEN_LEX_ALLOCATOR_SIZE;
constexpr s32 Builder_StrBufferReserve  = GEN_BUILDER_STR_BUFFER_RESERVE;

extern Code access_public;
extern Code access_protected;
extern Code access_private;

extern CodeAttributes attrib_api_export;
extern CodeAttributes attrib_api_import;

extern Code module_global_fragment;
extern Code module_private_fragment;

extern Code fmt_newline;

extern CodePragma pragma_once;

extern CodeParam param_varadic;

extern CodePreprocessCond preprocess_else;
extern CodePreprocessCond preprocess_endif;

extern CodeSpecifiers spec_const;
extern CodeSpecifiers spec_consteval;
extern CodeSpecifiers spec_constexpr;
extern CodeSpecifiers spec_constinit;
extern CodeSpecifiers spec_extern_linkage;
extern CodeSpecifiers spec_final;
extern CodeSpecifiers spec_FORCEINLINE;
extern CodeSpecifiers spec_global;
extern CodeSpecifiers spec_inline;
extern CodeSpecifiers spec_internal_linkage;
extern CodeSpecifiers spec_local_persist;
extern CodeSpecifiers spec_mutable;
extern CodeSpecifiers spec_neverinline;
extern CodeSpecifiers spec_noexcept;
extern CodeSpecifiers spec_override;
extern CodeSpecifiers spec_ptr;
extern CodeSpecifiers spec_pure;
extern CodeSpecifiers spec_ref;
extern CodeSpecifiers spec_register;
extern CodeSpecifiers spec_rvalue;
extern CodeSpecifiers spec_static_member;
extern CodeSpecifiers spec_thread_local;
extern CodeSpecifiers spec_virtual;
extern CodeSpecifiers spec_volatile;

extern CodeType t_empty;    // Used with varaidc parameters. (Exposing just in case its useful for another circumstance)
extern CodeType t_auto;
extern CodeType t_void;
extern CodeType t_int;
extern CodeType t_bool;
extern CodeType t_char;
extern CodeType t_wchar_t;
extern CodeType t_class;
extern CodeType t_typename;

#ifdef GEN_DEFINE_LIBRARY_CODE_CONSTANTS
// Predefined typename codes. Are set to readonly and are setup during gen::init()

extern CodeType t_b32;

extern CodeType t_s8;
extern CodeType t_s16;
extern CodeType t_s32;
extern CodeType t_s64;

extern CodeType t_u8;
extern CodeType t_u16;
extern CodeType t_u32;
extern CodeType t_u64;

extern CodeType t_sw;
extern CodeType t_uw;

extern CodeType t_f32;
extern CodeType t_f64;
#endif

#pragma endregion Constants

#pragma region Macros

#define gen_main main

#define __       NoCode

//	Convienence for defining any name used with the gen api.
//  Lets you provide the length and string literal to the functions without the need for the DSL.
#define name( Id_ )                                      \
	{                                                    \
		sizeof( stringize( Id_ ) ) - 1, stringize( Id_ ) \
	}

//  Same as name just used to indicate intention of literal for code instead of names.
#define code( ... )                                                      \
	{                                                                    \
		sizeof( stringize( __VA_ARGS__ ) ) - 1, stringize( __VA_ARGS__ ) \
	}

#define args( ... )     num_args( __VA_ARGS__ ), __VA_ARGS__

#define code_str( ... ) GEN_NS untyped_str( code( __VA_ARGS__ ) )
#define code_fmt( ... ) GEN_NS untyped_str( token_fmt( __VA_ARGS__ ) )

// Takes a format string (char const*) and a list of tokens (StrC) and returns a StrC of the formatted string.
#define token_fmt( ... ) GEN_NS token_fmt_impl( ( num_args( __VA_ARGS__ ) + 1 ) / 2, __VA_ARGS__ )

#pragma endregion Macros

// Used by the lexer to persistently treat all these identifiers as preprocessor defines.
// Populate with strings via gen::get_cached_string.
// Functional defines must have format: id( ;at minimum to indicate that the define is only valid with arguments.
extern Array<StringCached> PreprocessorDefines;

#ifdef GEN_EXPOSE_BACKEND

// Global allocator used for data with process lifetime.
extern AllocatorInfo GlobalAllocator;
extern Array<Arena>  Global_AllocatorBuckets;

extern Array<Pool>  CodePools;
extern Array<Arena> StringArenas;

extern StringTable StringCache;

extern Arena LexArena;

extern AllocatorInfo Allocator_DataArrays;
extern AllocatorInfo Allocator_CodePool;
extern AllocatorInfo Allocator_Lexer;
extern AllocatorInfo Allocator_StringArena;
extern AllocatorInfo Allocator_StringTable;
extern AllocatorInfo Allocator_TypeTable;

#endif
GEN_NS_END

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
