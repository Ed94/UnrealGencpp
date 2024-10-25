// This file was generated automatially by gencpp's unreal.cpp (See: https://github.com/Ed94/gencpp)

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

#if ! defined( GEN_DONT_ENFORCE_GEN_TIME_GUARD ) && ! defined( GEN_TIME )
#error Gen.hpp : GEN_TIME not defined
#endif

#include "gen.hpp"

GEN_NS_BEGIN

#pragma region StaticData

// TODO : Convert global allocation strategy to use a slab allocation strategy.
global AllocatorInfo GlobalAllocator;
global Array<Arena> Global_AllocatorBuckets;

// TODO(Ed) : Make the code pool a dynamic arena
global Array<Pool> CodePools     = { nullptr };
global Array<Arena> StringArenas = { nullptr };

global StringTable StringCache;

global Arena LexArena;

global AllocatorInfo Allocator_DataArrays  = heap();
global AllocatorInfo Allocator_CodePool    = heap();
global AllocatorInfo Allocator_Lexer       = heap();
global AllocatorInfo Allocator_StringArena = heap();
global AllocatorInfo Allocator_StringTable = heap();
global AllocatorInfo Allocator_TypeTable   = heap();

#pragma endregion StaticData

#pragma region Constants

global Code access_public;
global Code access_protected;
global Code access_private;

global CodeAttributes attrib_api_export;
global CodeAttributes attrib_api_import;

global Code module_global_fragment;
global Code module_private_fragment;

global Code fmt_newline;

global CodeParam param_varadic;

global CodePragma pragma_once;

global CodePreprocessCond preprocess_else;
global CodePreprocessCond preprocess_endif;

global CodeSpecifiers spec_const;
global CodeSpecifiers spec_consteval;
global CodeSpecifiers spec_constexpr;
global CodeSpecifiers spec_constinit;
global CodeSpecifiers spec_extern_linkage;
global CodeSpecifiers spec_final;
global CodeSpecifiers spec_FORCEINLINE;
global CodeSpecifiers spec_global;
global CodeSpecifiers spec_inline;
global CodeSpecifiers spec_internal_linkage;
global CodeSpecifiers spec_local_persist;
global CodeSpecifiers spec_mutable;
global CodeSpecifiers spec_noexcept;
global CodeSpecifiers spec_neverinline;
global CodeSpecifiers spec_override;
global CodeSpecifiers spec_ptr;
global CodeSpecifiers spec_pure;
global CodeSpecifiers spec_ref;
global CodeSpecifiers spec_register;
global CodeSpecifiers spec_rvalue;
global CodeSpecifiers spec_static_member;
global CodeSpecifiers spec_thread_local;
global CodeSpecifiers spec_virtual;
global CodeSpecifiers spec_volatile;

global CodeType t_empty;
global CodeType t_auto;
global CodeType t_void;
global CodeType t_int;
global CodeType t_bool;
global CodeType t_char;
global CodeType t_wchar_t;
global CodeType t_class;
global CodeType t_typename;

global Array<StringCached> PreprocessorDefines;

#ifdef GEN_DEFINE_LIBRARY_CODE_CONSTANTS
global CodeType t_b32;

global CodeType t_s8;
global CodeType t_s16;
global CodeType t_s32;
global CodeType t_s64;

global CodeType t_u8;
global CodeType t_u16;
global CodeType t_u32;
global CodeType t_u64;

global CodeType t_sw;
global CodeType t_uw;

global CodeType t_f32;
global CodeType t_f64;
#endif

#pragma endregion Constants

#pragma region AST

#define GEN_AST_BODY_CLASS_UNALLOWED_TYPES \
	case PlatformAttributes :              \
	case Class_Body :                      \
	case Enum_Body :                       \
	case Extern_Linkage :                  \
	case Function_Body :                   \
	case Function_Fwd :                    \
	case Global_Body :                     \
	case Namespace :                       \
	case Namespace_Body :                  \
	case Operator :                        \
	case Operator_Fwd :                    \
	case Parameters :                      \
	case Specifiers :                      \
	case Struct_Body :                     \
	case Typename :
#define GEN_AST_BODY_STRUCT_UNALLOWED_TYPES GEN_AST_BODY_CLASS_UNALLOWED_TYPES

#define GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES \
	case Access_Public :                      \
	case Access_Protected :                   \
	case Access_Private :                     \
	case PlatformAttributes :                 \
	case Class_Body :                         \
	case Enum_Body :                          \
	case Extern_Linkage :                     \
	case Friend :                             \
	case Function_Body :                      \
	case Function_Fwd :                       \
	case Global_Body :                        \
	case Namespace :                          \
	case Namespace_Body :                     \
	case Operator :                           \
	case Operator_Fwd :                       \
	case Operator_Member :                    \
	case Operator_Member_Fwd :                \
	case Parameters :                         \
	case Specifiers :                         \
	case Struct_Body :                        \
	case Typename :

#define GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES \
	case Access_Public :                    \
	case Access_Protected :                 \
	case Access_Private :                   \
	case PlatformAttributes :               \
	case Class_Body :                       \
	case Enum_Body :                        \
	case Execution :                        \
	case Friend :                           \
	case Function_Body :                    \
	case Namespace_Body :                   \
	case Operator_Member :                  \
	case Operator_Member_Fwd :              \
	case Parameters :                       \
	case Specifiers :                       \
	case Struct_Body :                      \
	case Typename :
#define GEN_AST_BODY_EXPORT_UNALLOWED_TYPES         GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES
#define GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES

#define GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES \
	case Access_Public :                       \
	case Access_Protected :                    \
	case Access_Private :                      \
	case PlatformAttributes :                  \
	case Class_Body :                          \
	case Enum_Body :                           \
	case Execution :                           \
	case Friend :                              \
	case Function_Body :                       \
	case Namespace_Body :                      \
	case Operator_Member :                     \
	case Operator_Member_Fwd :                 \
	case Parameters :                          \
	case Specifiers :                          \
	case Struct_Body :                         \
	case Typename :

Code Code::Global;
Code Code::Invalid;

// This serializes all the data-members in a "debug" format, where each member is printed with its associated value.
char const* AST::debug_str()
{
	String result = String::make_reserve( GlobalAllocator, kilobytes( 1 ) );

	if ( Parent )
		result.append_fmt( "\n\tParent       : %S %S", Parent->type_str(), Name ? Name : "" );
	else
		result.append_fmt( "\n\tParent       : %S", "Null" );

	result.append_fmt( "\n\tName         : %S", Name ? Name : "Null" );
	result.append_fmt( "\n\tType         : %S", type_str() );
	result.append_fmt( "\n\tModule Flags : %S", to_str( ModuleFlags ) );

	switch ( Type )
	{
		using namespace ECode;

		case Invalid :
		case NewLine :
		case Access_Private :
		case Access_Protected :
		case Access_Public :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			break;

		case Untyped :
		case Execution :
		case Comment :
		case PlatformAttributes :
		case Preprocess_Define :
		case Preprocess_Include :
		case Preprocess_Pragma :
		case Preprocess_If :
		case Preprocess_ElIf :
		case Preprocess_Else :
		case Preprocess_IfDef :
		case Preprocess_IfNotDef :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tContent: %S", Content );
			break;

		case Class :
		case Struct :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmd   : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tAttributes  : %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tParentAccess: %s", ParentType ? to_str( ParentAccess ) : "No Parent" );
			result.append_fmt( "\n\tParentType  : %s", ParentType ? ParentType->type_str() : "Null" );
			result.append_fmt( "\n\tBody        : %S", Body ? Body->debug_str() : "Null" );
			break;

		case Class_Fwd :
		case Struct_Fwd :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmd   : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tAttributes  : %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tParentAccess: %s", ParentType ? to_str( ParentAccess ) : "No Parent" );
			result.append_fmt( "\n\tParentType  : %s", ParentType ? ParentType->type_str() : "Null" );
			break;

		case Constructor :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt      : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tSpecs          : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tInitializerList: %S", InitializerList ? InitializerList->to_string() : "Null" );
			result.append_fmt( "\n\tParams         : %S", Params ? Params->to_string() : "Null" );
			result.append_fmt( "\n\tBody           : %S", Body ? Body->debug_str() : "Null" );
			break;

		case Constructor_Fwd :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt      : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tSpecs          : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tInitializerList: %S", InitializerList ? InitializerList->to_string() : "Null" );
			result.append_fmt( "\n\tParams         : %S", Params ? Params->to_string() : "Null" );
			break;

		case Destructor :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt      : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tSpecs          : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tBody           : %S", Body ? Body->debug_str() : "Null" );
			break;

		case Destructor_Fwd :
			break;

		case Enum :
		case Enum_Class :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt       : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tAttributes      : %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tUnderlying Type : %S", UnderlyingType ? UnderlyingType->to_string() : "Null" );
			result.append_fmt( "\n\tBody            : %S", Body ? Body->debug_str() : "Null" );
			break;

		case Enum_Fwd :
		case Enum_Class_Fwd :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt       : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tAttributes      : %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tUnderlying Type : %S", UnderlyingType ? UnderlyingType->to_string() : "Null" );
			break;

		case Extern_Linkage :
		case Namespace :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tBody: %S", Body ? Body->debug_str() : "Null" );
			break;

		case Friend :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt  : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tDeclaration: %S", Declaration ? Declaration->to_string() : "Null" );
			break;

		case Function :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tAttributes: %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tSpecs     : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tReturnType: %S", ReturnType ? ReturnType->to_string() : "Null" );
			result.append_fmt( "\n\tParams    : %S", Params ? Params->to_string() : "Null" );
			result.append_fmt( "\n\tBody      : %S", Body ? Body->debug_str() : "Null" );
			break;

		case Function_Fwd :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tAttributes: %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tSpecs     : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tReturnType: %S", ReturnType ? ReturnType->to_string() : "Null" );
			result.append_fmt( "\n\tParams    : %S", Params ? Params->to_string() : "Null" );
			break;

		case Module :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			break;

		case Operator :
		case Operator_Member :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tAttributes: %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tSpecs     : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tReturnType: %S", ReturnType ? ReturnType->to_string() : "Null" );
			result.append_fmt( "\n\tParams    : %S", Params ? Params->to_string() : "Null" );
			result.append_fmt( "\n\tBody      : %S", Body ? Body->debug_str() : "Null" );
			result.append_fmt( "\n\tOp        : %S", to_str( Op ) );
			break;

		case Operator_Fwd :
		case Operator_Member_Fwd :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tAttributes: %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tSpecs     : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tReturnType: %S", ReturnType ? ReturnType->to_string() : "Null" );
			result.append_fmt( "\n\tParams    : %S", Params ? Params->to_string() : "Null" );
			result.append_fmt( "\n\tOp        : %S", to_str( Op ) );
			break;

		case Operator_Cast :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tSpecs     : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tValueType : %S", ValueType ? ValueType->to_string() : "Null" );
			result.append_fmt( "\n\tBody      : %S", Body ? Body->debug_str() : "Null" );
			break;

		case Operator_Cast_Fwd :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tSpecs     : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tValueType : %S", ValueType ? ValueType->to_string() : "Null" );
			break;

		case Parameters :
			result.append_fmt( "\n\tNumEntries: %d", NumEntries );
			result.append_fmt( "\n\tLast      : %S", Last->Name );
			result.append_fmt( "\n\tNext      : %S", Next->Name );
			result.append_fmt( "\n\tValueType : %S", ValueType ? ValueType->to_string() : "Null" );
			result.append_fmt( "\n\tValue     : %S", Value ? Value->to_string() : "Null" );
			break;

		case Specifiers :
		{
			result.append_fmt( "\n\tNumEntries: %d", NumEntries );
			result.append( "\n\tArrSpecs: " );

			s32 idx  = 0;
			s32 left = NumEntries;
			while ( left-- )
			{
				StrC spec = ESpecifier::to_str( ArrSpecs[idx] );
				result.append_fmt( "%.*s, ", spec.Len, spec.Ptr );
				idx++;
			}
			result.append_fmt( "\n\tNextSpecs: %S", NextSpecs ? NextSpecs->debug_str() : "Null" );
		}
		break;

		case Template :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tParams     : %S", Params ? Params->to_string() : "Null" );
			result.append_fmt( "\n\tDeclaration: %S", Declaration ? Declaration->to_string() : "Null" );
			break;

		case Typedef :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt     : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tUnderlyingType: %S", UnderlyingType ? UnderlyingType->to_string() : "Null" );
			break;

		case Typename :
			result.append_fmt( "\n\tAttributes     : %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tSpecs          : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tReturnType     : %S", ReturnType ? ReturnType->to_string() : "Null" );
			result.append_fmt( "\n\tParams         : %S", Params ? Params->to_string() : "Null" );
			result.append_fmt( "\n\tArrExpr        : %S", ArrExpr ? ArrExpr->to_string() : "Null" );
			break;

		case Union :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tAttributes: %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tBody      : %S", Body ? Body->debug_str() : "Null" );
			break;

		case Using :
			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt     : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tAttributes    : %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tUnderlyingType: %S", UnderlyingType ? UnderlyingType->to_string() : "Null" );
			break;

		case Variable :

			if ( Parent && Parent->Type == Variable )
			{
				// Its a NextVar
				result.append_fmt( "\n\tSpecs       : %S", Specs ? Specs->to_string() : "Null" );
				result.append_fmt( "\n\tValue       : %S", Value ? Value->to_string() : "Null" );
				result.append_fmt( "\n\tBitfieldSize: %S", BitfieldSize ? BitfieldSize->to_string() : "Null" );
				result.append_fmt( "\n\tNextVar     : %S", NextVar ? NextVar->debug_str() : "Null" );
				break;
			}

			if ( Prev )
				result.append_fmt( "\n\tPrev: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );
			if ( Next )
				result.append_fmt( "\n\tNext: %S %S", Prev->type_str(), Prev->Name ? Prev->Name : "Null" );

			result.append_fmt( "\n\tInlineCmt   : %S", InlineCmt ? InlineCmt->Content : "Null" );
			result.append_fmt( "\n\tAttributes  : %S", Attributes ? Attributes->to_string() : "Null" );
			result.append_fmt( "\n\tSpecs       : %S", Specs ? Specs->to_string() : "Null" );
			result.append_fmt( "\n\tValueType   : %S", ValueType ? ValueType->to_string() : "Null" );
			result.append_fmt( "\n\tBitfieldSize: %S", BitfieldSize ? BitfieldSize->to_string() : "Null" );
			result.append_fmt( "\n\tValue       : %S", Value ? Value->to_string() : "Null" );
			result.append_fmt( "\n\tNextVar     : %S", NextVar ? NextVar->debug_str() : "Null" );
			break;
	}

	return result;
}

AST* AST::duplicate()
{
	using namespace ECode;

	AST* result = make_code().ast;

	mem_copy( result, this, sizeof( AST ) );

	result->Parent = nullptr;
	return result;
}

String AST::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void AST::to_string( String& result )
{
	local_persist thread_local char SerializationLevel = 0;

	switch ( Type )
	{
		using namespace ECode;

		case Invalid :
#ifdef GEN_DONT_ALLOW_INVALID_CODE
			log_failure( "Attempted to serialize invalid code! - %S", Parent ? Parent->debug_str() : Name );
#else
			result.append_fmt( "Invalid Code!" );
#endif
			break;

		case NewLine :
			result.append( "\n" );
			break;

		case Untyped :
		case Execution :
		case Comment :
		case PlatformAttributes :
			result.append( Content );
			break;

		case Access_Private :
		case Access_Protected :
		case Access_Public :
			result.append( Name );
			break;

		case Class :
			cast<CodeClass>().to_string_def( result );
			break;

		case Class_Fwd :
			cast<CodeClass>().to_string_fwd( result );
			break;

		case Constructor :
			cast<CodeConstructor>().to_string_def( result );
			break;

		case Constructor_Fwd :
			cast<CodeConstructor>().to_string_fwd( result );
			break;

		case Destructor :
			cast<CodeDestructor>().to_string_def( result );
			break;

		case Destructor_Fwd :
			cast<CodeDestructor>().to_string_fwd( result );
			break;

		case Enum :
			cast<CodeEnum>().to_string_def( result );
			break;

		case Enum_Fwd :
			cast<CodeEnum>().to_string_fwd( result );
			break;

		case Enum_Class :
			cast<CodeEnum>().to_string_class_def( result );
			break;

		case Enum_Class_Fwd :
			cast<CodeEnum>().to_string_class_fwd( result );
			break;

		case Export_Body :
			cast<CodeBody>().to_string_export( result );
			break;

		case Extern_Linkage :
			cast<CodeExtern>().to_string( result );
			break;

		case Friend :
			cast<CodeFriend>().to_string( result );
			break;

		case Function :
			cast<CodeFn>().to_string_def( result );
			break;

		case Function_Fwd :
			cast<CodeFn>().to_string_fwd( result );
			break;

		case Module :
			cast<CodeModule>().to_string( result );
			break;

		case Namespace :
			cast<CodeNS>().to_string( result );
			break;

		case Operator :
		case Operator_Member :
			cast<CodeOperator>().to_string_def( result );
			break;

		case Operator_Fwd :
		case Operator_Member_Fwd :
			cast<CodeOperator>().to_string_fwd( result );
			break;

		case Operator_Cast :
			cast<CodeOpCast>().to_string_def( result );
			break;

		case Operator_Cast_Fwd :
			cast<CodeOpCast>().to_string_fwd( result );
			break;

		case Parameters :
			cast<CodeParam>().to_string( result );
			break;

		case Preprocess_Define :
			cast<CodeDefine>().to_string( result );
			break;

		case Preprocess_If :
			cast<CodePreprocessCond>().to_string_if( result );
			break;

		case Preprocess_IfDef :
			cast<CodePreprocessCond>().to_string_ifdef( result );
			break;

		case Preprocess_IfNotDef :
			cast<CodePreprocessCond>().to_string_ifndef( result );
			break;

		case Preprocess_Include :
			cast<CodeInclude>().to_string( result );
			break;

		case Preprocess_ElIf :
			cast<CodePreprocessCond>().to_string_elif( result );
			break;

		case Preprocess_Else :
			cast<CodePreprocessCond>().to_string_else( result );
			break;

		case Preprocess_EndIf :
			cast<CodePreprocessCond>().to_string_endif( result );
			break;

		case Preprocess_Pragma :
			cast<CodePragma>().to_string( result );
			break;

		case Specifiers :
			cast<CodeSpecifiers>().to_string( result );
			break;

		case Struct :
			cast<CodeStruct>().to_string_def( result );
			break;

		case Struct_Fwd :
			cast<CodeStruct>().to_string_fwd( result );
			break;

		case Template :
			cast<CodeTemplate>().to_string( result );
			break;

		case Typedef :
			cast<CodeTypedef>().to_string( result );
			break;

		case Typename :
			cast<CodeType>().to_string( result );
			break;

		case Union :
			cast<CodeUnion>().to_string( result );
			break;

		case Using :
			cast<CodeUsing>().to_string( result );
			break;

		case Using_Namespace :
			cast<CodeUsing>().to_string_ns( result );
			break;

		case Variable :
			cast<CodeVar>().to_string( result );
			break;

		case Enum_Body :
		case Class_Body :
		case Extern_Linkage_Body :
		case Function_Body :
		case Global_Body :
		case Namespace_Body :
		case Struct_Body :
		case Union_Body :
			cast<CodeBody>().to_string( result );
			break;
	}
}

bool AST::is_equal( AST* other )
{
	/*
	    AST values are either some u32 value, a cached string, or a pointer to another AST.

	    u32 values are compared by value.
	    Cached strings are compared by pointer.
	    AST nodes are compared with AST::is_equal.
	*/
	if ( other == nullptr )
	{
		log_fmt( "AST::is_equal: other is null\nAST: %S", debug_str() );
		return false;
	}

	if ( Type != other->Type )
	{
		log_fmt( "AST::is_equal: Type check failure with other\nAST: %S\nOther: %S", debug_str(), other->debug_str() );

		return false;
	}

	switch ( Type )
	{
		using namespace ECode;

#define check_member_val( val )               \
	if ( val != other->val )                  \
	{                                         \
		log_fmt(                              \
		    "\nAST::is_equal: Member - " #val \
		    " failed\n"                       \
		    "AST  : %S\n"                     \
		    "Other: %S\n",                    \
		    debug_str(),                      \
		    other->debug_str()                \
		);                                    \
                                              \
		return false;                         \
	}

#define check_member_str( str )                      \
	if ( str != other->str )                         \
	{                                                \
		log_fmt(                                     \
		    "\nAST::is_equal: Member string - " #str \
		    " failed\n"                              \
		    "AST  : %S\n"                            \
		    "Other: %S\n",                           \
		    debug_str(),                             \
		    other->debug_str()                       \
		);                                           \
                                                     \
		return false;                                \
	}

#define check_member_content( content )                               \
	if ( content != other->content )                                  \
	{                                                                 \
		log_fmt(                                                      \
		    "\nAST::is_equal: Member content - " #content             \
		    " failed\n"                                               \
		    "AST  : %S\n"                                             \
		    "Other: %S\n",                                            \
		    debug_str(),                                              \
		    other->debug_str()                                        \
		);                                                            \
                                                                      \
		log_fmt(                                                      \
		    "Content cannot be trusted to be unique with this check " \
		    "so it must be verified by eye for now\n"                 \
		    "AST   Content:\n%S\n"                                    \
		    "Other Content:\n%S\n",                                   \
		    content.visualize_whitespace(),                           \
		    other->content.visualize_whitespace()                     \
		);                                                            \
	}

#define check_member_ast( ast )                            \
	if ( ast )                                             \
	{                                                      \
		if ( other->ast == nullptr )                       \
		{                                                  \
			log_fmt(                                       \
			    "\nAST::is_equal: Failed for member " #ast \
			    " other equivalent param is null\n"        \
			    "AST  : %s\n"                              \
			    "Other: %s\n"                              \
			    "For ast member: %s\n",                    \
			    debug_str(),                               \
			    other->debug_str(),                        \
			    ast->debug_str()                           \
			);                                             \
                                                           \
			return false;                                  \
		}                                                  \
                                                           \
		if ( ! ast->is_equal( other->ast ) )               \
		{                                                  \
			log_fmt(                                       \
			    "\nAST::is_equal: Failed for " #ast        \
			    "\n"                                       \
			    "AST  : %S\n"                              \
			    "Other: %S\n"                              \
			    "For     ast member: %S\n"                 \
			    "other's ast member: %S\n",                \
			    debug_str(),                               \
			    other->debug_str(),                        \
			    ast->debug_str(),                          \
			    other->ast->debug_str()                    \
			);                                             \
                                                           \
			return false;                                  \
		}                                                  \
	}

		case NewLine :
		case Access_Public :
		case Access_Protected :
		case Access_Private :
		case Preprocess_Else :
		case Preprocess_EndIf :
			return true;


		// Comments are not validated.
		case Comment :
			return true;

		case Execution :
		case PlatformAttributes :
		case Untyped :
		{
			check_member_content( Content );

			return true;
		}

		case Class_Fwd :
		case Struct_Fwd :
		{
			check_member_str( Name );
			check_member_ast( ParentType );
			check_member_val( ParentAccess );
			check_member_ast( Attributes );

			return true;
		}

		case Class :
		case Struct :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ParentType );
			check_member_val( ParentAccess );
			check_member_ast( Attributes );
			check_member_ast( Body );

			return true;
		}

		case Constructor :
		{
			check_member_ast( InitializerList );
			check_member_ast( Params );
			check_member_ast( Body );

			return true;
		}

		case Constructor_Fwd :
		{
			check_member_ast( InitializerList );
			check_member_ast( Params );

			return true;
		}

		case Destructor :
		{
			check_member_ast( Specs );
			check_member_ast( Body );

			return true;
		}

		case Destructor_Fwd :
		{
			check_member_ast( Specs );

			return true;
		}

		case Enum :
		case Enum_Class :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
			check_member_ast( UnderlyingType );
			check_member_ast( Body );

			return true;
		}

		case Enum_Fwd :
		case Enum_Class_Fwd :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
			check_member_ast( UnderlyingType );

			return true;
		}

		case Extern_Linkage :
		{
			check_member_str( Name );
			check_member_ast( Body );

			return true;
		}

		case Friend :
		{
			check_member_str( Name );
			check_member_ast( Declaration );

			return true;
		}

		case Function :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ReturnType );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( Params );
			check_member_ast( Body );

			return true;
		}

		case Function_Fwd :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ReturnType );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( Params );

			return true;
		}

		case Module :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );

			return true;
		}

		case Namespace :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Body );

			return true;
		}

		case Operator :
		case Operator_Member :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ReturnType );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( Params );
			check_member_ast( Body );

			return true;
		}

		case Operator_Fwd :
		case Operator_Member_Fwd :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ReturnType );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( Params );

			return true;
		}

		case Operator_Cast :
		{
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( ValueType );
			check_member_ast( Body );

			return true;
		}

		case Operator_Cast_Fwd :
		{
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( ValueType );

			return true;
		}

		case Parameters :
		{
			if ( NumEntries > 1 )
			{
				AST* curr       = this;
				AST* curr_other = other;
				while ( curr != nullptr )
				{
					if ( curr )
					{
						if ( curr_other == nullptr )
						{
							log_fmt(
							    "\nAST::is_equal: Failed for parameter, other equivalent param is null\n"
							    "AST  : %S\n"
							    "Other: %S\n"
							    "For ast member: %S\n",
							    curr->debug_str()
							);

							return false;
						}

						if ( curr->Name != curr_other->Name )
						{
							log_fmt(
							    "\nAST::is_equal: Failed for parameter name check\n"
							    "AST  : %S\n"
							    "Other: %S\n"
							    "For     ast member: %S\n"
							    "other's ast member: %S\n",
							    debug_str(),
							    other->debug_str(),
							    curr->debug_str(),
							    curr_other->debug_str()
							);
							return false;
						}

						if ( curr->ValueType && ! curr->ValueType->is_equal( curr_other->ValueType ) )
						{
							log_fmt(
							    "\nAST::is_equal: Failed for parameter value type check\n"
							    "AST  : %S\n"
							    "Other: %S\n"
							    "For     ast member: %S\n"
							    "other's ast member: %S\n",
							    debug_str(),
							    other->debug_str(),
							    curr->debug_str(),
							    curr_other->debug_str()
							);
							return false;
						}

						if ( curr->Value && ! curr->Value->is_equal( curr_other->Value ) )
						{
							log_fmt(
							    "\nAST::is_equal: Failed for parameter value check\n"
							    "AST  : %S\n"
							    "Other: %S\n"
							    "For     ast member: %S\n"
							    "other's ast member: %S\n",
							    debug_str(),
							    other->debug_str(),
							    curr->debug_str(),
							    curr_other->debug_str()
							);
							return false;
						}
					}

					curr       = curr->Next;
					curr_other = curr_other->Next;
				}

				check_member_val( NumEntries );

				return true;
			}

			check_member_str( Name );
			check_member_ast( ValueType );
			check_member_ast( Value );
			check_member_ast( ArrExpr );

			return true;
		}

		case Preprocess_Define :
		{
			check_member_str( Name );
			check_member_content( Content );

			return true;
		}

		case Preprocess_If :
		case Preprocess_IfDef :
		case Preprocess_IfNotDef :
		case Preprocess_ElIf :
		{
			check_member_content( Content );

			return true;
		}

		case Preprocess_Include :
		case Preprocess_Pragma :
		{
			check_member_content( Content );

			return true;
		}

		case Specifiers :
		{
			check_member_val( NumEntries );
			check_member_str( Name );
			for ( s32 idx = 0; idx < NumEntries; ++idx )
			{
				check_member_val( ArrSpecs[idx] );
			}
			return true;
		}

		case Template :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Params );
			check_member_ast( Declaration );

			return true;
		}

		case Typedef :
		{
			check_member_val( IsFunction );
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( UnderlyingType );

			return true;
		}
		case Typename :
		{
			check_member_val( IsParamPack );
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( ArrExpr );

			return true;
		}

		case Union :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
			check_member_ast( Body );

			return true;
		}

		case Using :
		case Using_Namespace :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( UnderlyingType );
			check_member_ast( Attributes );

			return true;
		}

		case Variable :
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ValueType );
			check_member_ast( BitfieldSize );
			check_member_ast( Value );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( NextVar );

			return true;
		}

		case Class_Body :
		case Enum_Body :
		case Export_Body :
		case Global_Body :
		case Namespace_Body :
		case Struct_Body :
		case Union_Body :
		{
			check_member_ast( Front );
			check_member_ast( Back );

			AST* curr       = Front;
			AST* curr_other = other->Front;
			while ( curr != nullptr )
			{
				if ( curr_other == nullptr )
				{
					log_fmt(
					    "\nAST::is_equal: Failed for body, other equivalent param is null\n"
					    "AST  : %S\n"
					    "Other: %S\n"
					    "For ast member: %S\n",
					    curr->debug_str()
					);

					return false;
				}

				if ( ! curr->is_equal( curr_other ) )
				{
					log_fmt(
					    "\nAST::is_equal: Failed for body\n"
					    "AST  : %S\n"
					    "Other: %S\n"
					    "For     ast member: %S\n"
					    "other's ast member: %S\n",
					    debug_str(),
					    other->debug_str(),
					    curr->debug_str(),
					    curr_other->debug_str()
					);

					return false;
				}

				curr       = curr->Next;
				curr_other = curr_other->Next;
			}

			check_member_val( NumEntries );

			return true;
		}

#undef check_member_val
#undef check_member_str
#undef check_member_ast
	}

	return true;
}

bool AST::validate_body()
{
	using namespace ECode;

#define CheckEntries( Unallowed_Types )                                                                           \
	do                                                                                                            \
	{                                                                                                             \
		for ( Code entry : cast<CodeBody>() )                                                                     \
		{                                                                                                         \
			switch ( entry->Type )                                                                                \
			{                                                                                                     \
				Unallowed_Types log_failure( "AST::validate_body: Invalid entry in body %s", entry.debug_str() ); \
				return false;                                                                                     \
			}                                                                                                     \
		}                                                                                                         \
	} while ( 0 );

	switch ( Type )
	{
		case Class_Body :
			CheckEntries( GEN_AST_BODY_CLASS_UNALLOWED_TYPES );
			break;
		case Enum_Body :
			for ( Code entry : cast<CodeBody>() )
			{
				if ( entry->Type != Untyped )
				{
					log_failure( "AST::validate_body: Invalid entry in enum body (needs to be untyped or comment) %s", entry.debug_str() );
					return false;
				}
			}
			break;
		case Export_Body :
			CheckEntries( GEN_AST_BODY_CLASS_UNALLOWED_TYPES );
			break;
		case Extern_Linkage :
			CheckEntries( GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES );
			break;
		case Function_Body :
			CheckEntries( GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES );
			break;
		case Global_Body :
			for ( Code entry : cast<CodeBody>() )
			{
				switch ( entry->Type )
				{
					case Access_Public :
					case Access_Protected :
					case Access_Private :
					case PlatformAttributes :
					case Class_Body :
					case Enum_Body :
					case Execution :
					case Friend :
					case Function_Body :
					case Global_Body :
					case Namespace_Body :
					case Operator_Member :
					case Operator_Member_Fwd :
					case Parameters :
					case Specifiers :
					case Struct_Body :
					case Typename :
						log_failure( "AST::validate_body: Invalid entry in body %s", entry.debug_str() );
						return false;
				}
			}
			break;
		case Namespace_Body :
			CheckEntries( GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES );
			break;
		case Struct_Body :
			CheckEntries( GEN_AST_BODY_STRUCT_UNALLOWED_TYPES );
			break;
		case Union_Body :
			for ( Code entry : Body->cast<CodeBody>() )
			{
				if ( entry->Type != Untyped )
				{
					log_failure( "AST::validate_body: Invalid entry in union body (needs to be untyped or comment) %s", entry.debug_str() );
					return false;
				}
			}
			break;

		default :
			log_failure( "AST::validate_body: Invalid this AST does not have a body %s", debug_str() );
			return false;
	}

	return false;

#undef CheckEntries
}

String Code::to_string()
{
	if ( ast == nullptr )
	{
		log_failure( "Code::to_string: Cannot convert code to string, AST is null!" );
		return { nullptr };
	}
	return rcast( AST*, ast )->to_string();
}

String CodeAttributes::to_string()
{
	return ast->Content.duplicate( GlobalAllocator );
}

String CodeBody::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Untyped :
		case Execution :
			result.append( raw()->Content );
			break;

		case Enum_Body :
		case Class_Body :
		case Extern_Linkage_Body :
		case Function_Body :
		case Global_Body :
		case Namespace_Body :
		case Struct_Body :
		case Union_Body :
			to_string( result );
			break;

		case Export_Body :
			to_string_export( result );
			break;
	}
	return result;
}

void CodeBody::to_string( String& result )
{
	Code curr = ast->Front;
	s32  left = ast->NumEntries;
	while ( left-- )
	{
		result.append_fmt( "%S", curr.to_string() );
		++curr;
	}
}

void CodeBody::to_string_export( String& result )
{
	result.append_fmt( "export\n{\n" );

	Code curr = *this;
	s32  left = ast->NumEntries;
	while ( left-- )
	{
		result.append_fmt( "%S", curr.to_string() );
		++curr;
	}

	result.append_fmt( "};\n" );
}

String CodeComment::to_string()
{
	return ast->Content.duplicate( GlobalAllocator );
}

String CodeConstructor::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Constructor :
			to_string_def( result );
			break;
		case Constructor_Fwd :
			to_string_fwd( result );
			break;
	}
	return result;
}

void CodeConstructor::to_string_def( String& result )
{
	AST* ClassStructParent = ast->Parent->Parent;
	if ( ClassStructParent )
	{
		result.append( ClassStructParent->Name );
	}
	else
	{
		result.append( ast->Name );
	}

	if ( ast->Params )
		result.append_fmt( "( %S )", ast->Params.to_string() );
	else
		result.append( "()" );

	if ( ast->InitializerList )
		result.append_fmt( " : %S", ast->InitializerList.to_string() );

	if ( ast->InlineCmt )
		result.append_fmt( " // %S", ast->InlineCmt->Content );

	result.append_fmt( "\n{\n%S\n}\n", ast->Body.to_string() );
}

void CodeConstructor::to_string_fwd( String& result )
{
	AST* ClassStructParent = ast->Parent->Parent;
	if ( ClassStructParent )
	{
		result.append( ClassStructParent->Name );
	}
	else
	{
		result.append( ast->Name );
	}

	if ( ast->Params )
		result.append_fmt( "( %S )", ast->Params.to_string() );
	else
		result.append_fmt( "()" );

	if ( ast->Body )
		result.append_fmt( " = %S", ast->Body.to_string() );

	if ( ast->InlineCmt )
		result.append_fmt( "; // %S\n", ast->InlineCmt->Content );
	else
		result.append( ";\n" );
}

String CodeClass::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Class :
			to_string_def( result );
			break;
		case Class_Fwd :
			to_string_fwd( result );
			break;
	}
	return result;
}

void CodeClass::to_string_def( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	result.append( "class " );

	if ( ast->Attributes )
	{
		result.append_fmt( "%S ", ast->Attributes.to_string() );
	}

	if ( ast->ParentType )
	{
		char const* access_level = to_str( ast->ParentAccess );

		result.append_fmt( "%S : %s %S", ast->Name, access_level, ast->ParentType.to_string() );

		CodeType interface = ast->ParentType->Next->cast<CodeType>();
		if ( interface )
			result.append( "\n" );

		while ( interface )
		{
			result.append_fmt( ", %S", interface.to_string() );
			interface = interface->Next ? interface->Next->cast<CodeType>() : CodeType { nullptr };
		}
	}
	else if ( ast->Name )
	{
		result.append( ast->Name );
	}

	if ( ast->InlineCmt )
	{
		result.append_fmt( " // %S", ast->InlineCmt->Content );
	}

	result.append_fmt( "\n{\n%S\n}", ast->Body.to_string() );

	if ( ast->Parent.ast == nullptr || ( ast->Parent->Type != ECode::Typedef && ast->Parent->Type != ECode::Variable ) )
		result.append( ";\n" );
}

void CodeClass::to_string_fwd( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Attributes )
		result.append_fmt( "class %S %S", ast->Attributes.to_string(), ast->Name );

	else
		result.append_fmt( "class %S", ast->Name );

	// Check if it can have an end-statement
	if ( ast->Parent.ast == nullptr || ( ast->Parent->Type != ECode::Typedef && ast->Parent->Type != ECode::Variable ) )
	{
		if ( ast->InlineCmt )
			result.append_fmt( "; // %S\n", ast->InlineCmt->Content );
		else
			result.append( ";\n" );
	}
}

String CodeDefine::to_string()
{
	return String::fmt_buf( GlobalAllocator, "#define %S %S\n", ast->Name, ast->Content );
}

void CodeDefine::to_string( String& result )
{
	result.append_fmt( "#define %S %S\n", ast->Name, ast->Content );
}

String CodeDestructor::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Destructor :
			to_string_def( result );
			break;
		case Destructor_Fwd :
			to_string_fwd( result );
			break;
	}
	return result;
}

void CodeDestructor::to_string_def( String& result )
{
	if ( ast->Name )
	{
		result.append_fmt( "%S()", ast->Name );
	}
	else if ( ast->Specs )
	{
		if ( ast->Specs.has( ESpecifier::Virtual ) )
			result.append_fmt( "virtual ~%S()", ast->Parent->Name );
		else
			result.append_fmt( "~%S()", ast->Parent->Name );
	}
	else
		result.append_fmt( "~%S()", ast->Parent->Name );

	result.append_fmt( "\n{\n%S\n}\n", ast->Body.to_string() );
}

void CodeDestructor::to_string_fwd( String& result )
{
	if ( ast->Specs )
	{
		if ( ast->Specs.has( ESpecifier::Virtual ) )
			result.append_fmt( "virtual ~%S();\n", ast->Parent->Name );
		else
			result.append_fmt( "~%S()", ast->Parent->Name );

		if ( ast->Specs.has( ESpecifier::Pure ) )
			result.append( " = 0;" );
		else if ( ast->Body )
			result.append_fmt( " = %S;", ast->Body.to_string() );
	}
	else
		result.append_fmt( "~%S();", ast->Parent->Name );

	if ( ast->InlineCmt )
		result.append_fmt( "  %S", ast->InlineCmt->Content );
	else
		result.append( "\n" );
}

String CodeEnum::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Enum :
			to_string_def( result );
			break;
		case Enum_Fwd :
			to_string_fwd( result );
			break;
		case Enum_Class :
			to_string_class_def( result );
			break;
		case Enum_Class_Fwd :
			to_string_class_fwd( result );
			break;
	}
	return result;
}

void CodeEnum::to_string_def( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Attributes || ast->UnderlyingType )
	{
		result.append( "enum " );

		if ( ast->Attributes )
			result.append_fmt( "%S ", ast->Attributes.to_string() );

		if ( ast->UnderlyingType )
			result.append_fmt( "%S : %S\n{\n%S\n}", ast->Name, ast->UnderlyingType.to_string(), ast->Body.to_string() );

		else
			result.append_fmt( "%S\n{\n%S\n}", ast->Name, ast->Body.to_string() );
	}
	else
		result.append_fmt( "enum %S\n{\n%S\n}", ast->Name, ast->Body.to_string() );

	if ( ast->Parent.ast == nullptr || ( ast->Parent->Type != ECode::Typedef && ast->Parent->Type != ECode::Variable ) )
		result.append( ";\n" );
}

void CodeEnum::to_string_fwd( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Attributes )
		result.append_fmt( "%S ", ast->Attributes.to_string() );

	result.append_fmt( "enum %S : %S", ast->Name, ast->UnderlyingType.to_string() );

	if ( ast->Parent.ast == nullptr || ( ast->Parent->Type != ECode::Typedef && ast->Parent->Type != ECode::Variable ) )
	{
		if ( ast->InlineCmt )
			result.append_fmt( ";  %S", ast->InlineCmt->Content );
		else
			result.append( ";\n" );
	}
}

void CodeEnum::to_string_class_def( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Attributes || ast->UnderlyingType )
	{
		result.append( "enum class " );

		if ( ast->Attributes )
		{
			result.append_fmt( "%S ", ast->Attributes.to_string() );
		}

		if ( ast->UnderlyingType )
		{
			result.append_fmt( "%S : %S\n{\n%S\n}", ast->Name, ast->UnderlyingType.to_string(), ast->Body.to_string() );
		}
		else
		{
			result.append_fmt( "%S\n{\n%S\n}", ast->Name, ast->Body.to_string() );
		}
	}
	else
	{
		result.append_fmt( "enum class %S\n{\n%S\n}", ast->Body.to_string() );
	}

	if ( ast->Parent.ast == nullptr || ( ast->Parent->Type != ECode::Typedef && ast->Parent->Type != ECode::Variable ) )
		result.append( ";\n" );
}

void CodeEnum::to_string_class_fwd( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	result.append( "enum class " );

	if ( ast->Attributes )
		result.append_fmt( "%S ", ast->Attributes.to_string() );

	result.append_fmt( "%S : %S", ast->Name, ast->UnderlyingType.to_string() );

	if ( ast->Parent.ast == nullptr || ( ast->Parent->Type != ECode::Typedef && ast->Parent->Type != ECode::Variable ) )
	{
		if ( ast->InlineCmt )
			result.append_fmt( ";  %S", ast->InlineCmt->Content );
		else
			result.append( ";\n" );
	}
}

String CodeExec::to_string()
{
	return ast->Content.duplicate( GlobalAllocator );
}

void CodeExtern::to_string( String& result )
{
	if ( ast->Body )
		result.append_fmt( "extern \"%S\"\n{\n%S\n}\n", ast->Name, ast->Body.to_string() );
	else
		result.append_fmt( "extern \"%S\"\n{}\n", ast->Name );
}

String CodeInclude::to_string()
{
	return String::fmt_buf( GlobalAllocator, "#include %S\n", ast->Content );
}

void CodeInclude::to_string( String& result )
{
	result.append_fmt( "#include %S\n", ast->Content );
}

String CodeFriend::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodeFriend::to_string( String& result )
{
	result.append_fmt( "friend %S", ast->Declaration->to_string() );

	if ( ast->Declaration->Type != ECode::Function && result[result.length() - 1] != ';' )
	{
		result.append( ";" );
	}

	if ( ast->InlineCmt )
		result.append_fmt( "  %S", ast->InlineCmt->Content );
	else
		result.append( "\n" );
}

String CodeFn::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Function :
			to_string_def( result );
			break;
		case Function_Fwd :
			to_string_fwd( result );
			break;
	}
	return result;
}

void CodeFn::to_string_def( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export" );

	if ( ast->Attributes )
		result.append_fmt( " %S ", ast->Attributes.to_string() );

	bool prefix_specs = false;
	if ( ast->Specs )
	{
		for ( SpecifierT spec : ast->Specs )
		{
			if ( ! ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( " %.*s", spec_str.Len, spec_str.Ptr );

				prefix_specs = true;
			}
		}
	}

	if ( ast->Attributes || prefix_specs )
		result.append( "\n" );

	if ( ast->ReturnType )
		result.append_fmt( "%S %S(", ast->ReturnType.to_string(), ast->Name );

	else
		result.append_fmt( "%S(", ast->Name );

	if ( ast->Params )
		result.append_fmt( "%S)", ast->Params.to_string() );

	else
		result.append( ")" );

	if ( ast->Specs )
	{
		for ( SpecifierT spec : ast->Specs )
		{
			if ( ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	result.append_fmt( "\n{\n%S\n}\n", ast->Body.to_string() );
}

void CodeFn::to_string_fwd( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Attributes )
		result.append_fmt( "%S ", ast->Attributes.to_string() );

	b32 prefix_specs = false;
	if ( ast->Specs )
	{
		for ( SpecifierT spec : ast->Specs )
		{
			if ( ! ESpecifier::is_trailing( spec ) || ! ( spec != ESpecifier::Pure ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( " %.*s", spec_str.Len, spec_str.Ptr );

				prefix_specs = true;
			}
		}
	}

	if ( ast->Attributes || prefix_specs )
	{
		result.append( "\n" );
	}

	if ( ast->ReturnType )
		result.append_fmt( "%S %S(", ast->ReturnType.to_string(), ast->Name );

	else
		result.append_fmt( "%S(", ast->Name );

	if ( ast->Params )
		result.append_fmt( "%S)", ast->Params.to_string() );

	else
		result.append( ")" );

	if ( ast->Specs )
	{
		for ( SpecifierT spec : ast->Specs )
		{
			if ( ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	if ( ast->Specs && ast->Specs.has( ESpecifier::Pure ) >= 0 )
		result.append( " = 0;" );
	else if ( ast->Body )
		result.append_fmt( " = %S;", ast->Body.to_string() );

	if ( ast->InlineCmt )
		result.append_fmt( ";  %S", ast->InlineCmt->Content );
	else
		result.append( ";\n" );
}

String CodeModule::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodeModule::to_string( String& result )
{
	if ( ( ( u32( ModuleFlag::Export ) & u32( ast->ModuleFlags ) ) == u32( ModuleFlag::Export ) ) )
		result.append( "export " );

	if ( ( ( u32( ModuleFlag::Import ) & u32( ast->ModuleFlags ) ) == u32( ModuleFlag::Import ) ) )
		result.append( "import " );

	result.append_fmt( "%S;\n", ast->Name );
}

String CodeNS::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodeNS::to_string( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	result.append_fmt( "namespace %S\n{\n%S\n}\n", ast->Name, ast->Body.to_string() );
}

String CodeOperator::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Operator :
		case Operator_Member :
			to_string_def( result );
			break;
		case Operator_Fwd :
		case Operator_Member_Fwd :
			to_string_fwd( result );
			break;
	}
	return result;
}

void CodeOperator::to_string_def( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Attributes )
		result.append_fmt( "%S ", ast->Attributes.to_string() );

	if ( ast->Attributes )
		result.append_fmt( "%S ", ast->Attributes.to_string() );

	if ( ast->Specs )
	{
		for ( SpecifierT spec : ast->Specs )
		{
			if ( ! ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	if ( ast->Attributes || ast->Specs )
	{
		result.append( "\n" );
	}

	if ( ast->ReturnType )
		result.append_fmt( "%S %S (", ast->ReturnType.to_string(), ast->Name );

	if ( ast->Params )
		result.append_fmt( "%S)", ast->Params.to_string() );

	else
		result.append( ")" );

	if ( ast->Specs )
	{
		for ( SpecifierT spec : ast->Specs )
		{
			if ( ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	result.append_fmt( "\n{\n%S\n}\n", ast->Body.to_string() );
}

void CodeOperator::to_string_fwd( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Attributes )
		result.append_fmt( "%S\n", ast->Attributes.to_string() );

	if ( ast->Specs )
	{
		for ( SpecifierT spec : ast->Specs )
		{
			if ( ! ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	if ( ast->Attributes || ast->Specs )
	{
		result.append( "\n" );
	}

	result.append_fmt( "%S %S (", ast->ReturnType.to_string(), ast->Name );

	if ( ast->Params )
		result.append_fmt( "%S)", ast->Params.to_string() );

	else
		result.append_fmt( ")" );

	if ( ast->Specs )
	{
		for ( SpecifierT spec : ast->Specs )
		{
			if ( ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	if ( ast->InlineCmt )
		result.append_fmt( ";  %S", ast->InlineCmt->Content );
	else
		result.append( ";\n" );
}

String CodeOpCast::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Operator_Cast :
			to_string_def( result );
			break;
		case Operator_Cast_Fwd :
			to_string_fwd( result );
			break;
	}
	return result;
}

void CodeOpCast::to_string_def( String& result )
{
	if ( ast->Specs )
	{
		for ( SpecifierT spec : ast->Specs )
		{
			if ( ! ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( "%*s ", spec_str.Len, spec_str.Ptr );
			}
		}

		if ( ast->Name && ast->Name.length() )
			result.append_fmt( "%Soperator %S()", ast->Name, ast->ValueType.to_string() );
		else
			result.append_fmt( "operator %S()", ast->ValueType.to_string() );

		for ( SpecifierT spec : ast->Specs )
		{
			if ( ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}

		result.append_fmt( "\n{\n%S\n}\n", ast->Body.to_string() );
		return;
	}

	if ( ast->Name && ast->Name.length() )
		result.append_fmt( "%Soperator %S()\n{\n%S\n}\n", ast->Name, ast->ValueType.to_string(), ast->Body.to_string() );
	else
		result.append_fmt( "operator %S()\n{\n%S\n}\n", ast->ValueType.to_string(), ast->Body.to_string() );
}

void CodeOpCast::to_string_fwd( String& result )
{
	if ( ast->Specs )
	{
		for ( SpecifierT spec : ast->Specs )
		{
			if ( ! ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( "%*s ", spec_str.Len, spec_str.Ptr );
			}
		}

		result.append_fmt( "operator %S()", ast->ValueType.to_string() );

		for ( SpecifierT spec : ast->Specs )
		{
			if ( ESpecifier::is_trailing( spec ) )
			{
				StrC spec_str = ESpecifier::to_str( spec );
				result.append_fmt( " %*s", spec_str.Len, spec_str.Ptr );
			}
		}

		if ( ast->InlineCmt )
			result.append_fmt( ";  %S", ast->InlineCmt->Content );
		else
			result.append( ";\n" );
		return;
	}

	if ( ast->InlineCmt )
		result.append_fmt( "operator %S();  %S", ast->ValueType.to_string() );
	else
		result.append_fmt( "operator %S();\n", ast->ValueType.to_string() );
}

String CodeParam::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodeParam::to_string( String& result )
{
	if ( ast->Macro )
	{
		// Related to parsing: ( <macro>, ... )
		result.append( ast->Macro.ast->Content );
		// Could also be: ( <macro> <type <name>, ... )
	}

	if ( ast->Name )
	{
		if ( ast->ValueType.ast == nullptr )
			result.append_fmt( " %S", ast->Name );
		else
			result.append_fmt( " %S %S", ast->ValueType.to_string(), ast->Name );
	}
	else if ( ast->ValueType )
		result.append_fmt( " %S", ast->ValueType.to_string() );

	if ( ast->PostNameMacro )
	{
		result.append_fmt( " %S", ast->PostNameMacro.to_string() );
	}

	if ( ast->Value )
		result.append_fmt( " = %S", ast->Value.to_string() );

	if ( ast->NumEntries - 1 > 0 )
	{
		for ( CodeParam param : ast->Next )
		{
			result.append_fmt( ", %S", param.to_string() );
		}
	}
}

String CodePreprocessCond::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Preprocess_If :
			to_string_if( result );
			break;
		case Preprocess_IfDef :
			to_string_ifdef( result );
			break;
		case Preprocess_IfNotDef :
			to_string_ifndef( result );
			break;
		case Preprocess_ElIf :
			to_string_elif( result );
			break;
		case Preprocess_Else :
			to_string_else( result );
			break;
		case Preprocess_EndIf :
			to_string_endif( result );
			break;
	}
	return result;
}

void CodePreprocessCond::to_string_if( String& result )
{
	result.append_fmt( "#if %S\n", ast->Content );
}

void CodePreprocessCond::to_string_ifdef( String& result )
{
	result.append_fmt( "#ifdef %S\n", ast->Content );
}

void CodePreprocessCond::to_string_ifndef( String& result )
{
	result.append_fmt( "#ifndef %S\n", ast->Content );
}

void CodePreprocessCond::to_string_elif( String& result )
{
	result.append_fmt( "#elif %S\n", ast->Content );
}

void CodePreprocessCond::to_string_else( String& result )
{
	result.append_fmt( "#else\n" );
}

void CodePreprocessCond::to_string_endif( String& result )
{
	result.append_fmt( "#endif\n" );
}

String CodePragma::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodePragma::to_string( String& result )
{
	result.append_fmt( "#pragma %S\n", ast->Content );
}

String CodeSpecifiers::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodeSpecifiers::to_string( String& result )
{
	s32 idx  = 0;
	s32 left = ast->NumEntries;
	while ( left-- )
	{
		StrC spec = ESpecifier::to_str( ast->ArrSpecs[idx] );
		result.append_fmt( "%.*s ", spec.Len, spec.Ptr );
		idx++;
	}
}

String CodeStruct::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Struct :
			to_string_def( result );
			break;
		case Struct_Fwd :
			to_string_fwd( result );
			break;
	}
	return result;
}

void CodeStruct::to_string_def( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	result.append( "struct " );

	if ( ast->Attributes )
	{
		result.append_fmt( "%S ", ast->Attributes.to_string() );
	}

	if ( ast->ParentType )
	{
		char const* access_level = to_str( ast->ParentAccess );

		result.append_fmt( "%S : %s %S", ast->Name, access_level, ast->ParentType.to_string() );

		CodeType interface = ast->ParentType->Next->cast<CodeType>();
		if ( interface )
			result.append( "\n" );

		while ( interface )
		{
			result.append_fmt( ", %S", interface.to_string() );
			interface = interface->Next ? interface->Next->cast<CodeType>() : CodeType { nullptr };
		}
	}
	else if ( ast->Name )
	{
		result.append( ast->Name );
	}

	if ( ast->InlineCmt )
	{
		result.append_fmt( " // %S", ast->InlineCmt->Content );
	}

	result.append_fmt( "\n{\n%S\n}", ast->Body.to_string() );

	if ( ast->Parent.ast == nullptr || ( ast->Parent->Type != ECode::Typedef && ast->Parent->Type != ECode::Variable ) )
		result.append( ";\n" );
}

void CodeStruct::to_string_fwd( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Attributes )
		result.append_fmt( "struct %S %S", ast->Attributes.to_string(), ast->Name );

	else
		result.append_fmt( "struct %S", ast->Name );

	if ( ast->Parent.ast == nullptr || ( ast->Parent->Type != ECode::Typedef && ast->Parent->Type != ECode::Variable ) )
	{
		if ( ast->InlineCmt )
			result.append_fmt( ";  %S", ast->InlineCmt->Content );
		else
			result.append( ";\n" );
	}
}

String CodeTemplate::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodeTemplate::to_string( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Params )
		result.append_fmt( "template< %S >\n%S", ast->Params.to_string(), ast->Declaration.to_string() );
	else
		result.append_fmt( "template<>\n%S", ast->Declaration.to_string() );
}

String CodeTypedef::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodeTypedef::to_string( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	result.append( "typedef " );

	// Determines if the typedef is a function typename
	if ( ast->UnderlyingType->ReturnType )
		result.append( ast->UnderlyingType.to_string() );
	else
		result.append_fmt( "%S %S", ast->UnderlyingType.to_string(), ast->Name );

	if ( ast->UnderlyingType->Type == ECode::Typename && ast->UnderlyingType->ArrExpr )
	{
		result.append_fmt( "[ %S ];", ast->UnderlyingType->ArrExpr->to_string() );

		AST* next_arr_expr = ast->UnderlyingType->ArrExpr->Next;
		while ( next_arr_expr )
		{
			result.append_fmt( "[ %S ];", next_arr_expr->to_string() );
			next_arr_expr = next_arr_expr->Next;
		}
	}
	else
	{
		result.append( ";" );
	}

	if ( ast->InlineCmt )
		result.append_fmt( "  %S", ast->InlineCmt->Content );
	else
		result.append( "\n" );
}

String CodeType::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodeType::to_string( String& result )
{
#if defined( GEN_USE_NEW_TYPENAME_PARSING )
	if ( ast->ReturnType && ast->Params )
	{
		if ( ast->Attributes )
			result.append_fmt( "%S ", ast->Attributes.to_string() );
		else
		{
			if ( ast->Specs )
				result.append_fmt( "%S ( %S ) ( %S ) %S", ast->ReturnType.to_string(), ast->Name, ast->Params.to_string(), ast->Specs.to_string() );
			else
				result.append_fmt( "%S ( %S ) ( %S )", ast->ReturnType.to_string(), ast->Name, ast->Params.to_string() );
		}

		break;
	}
#else
	if ( ast->ReturnType && ast->Params )
	{
		if ( ast->Attributes )
			result.append_fmt( "%S ", ast->Attributes.to_string() );
		else
		{
			if ( ast->Specs )
				result.append_fmt( "%S %S ( %S ) %S", ast->ReturnType.to_string(), ast->Name, ast->Params.to_string(), ast->Specs.to_string() );
			else
				result.append_fmt( "%S %S ( %S )", ast->ReturnType.to_string(), ast->Name, ast->Params.to_string() );
		}

		return;
	}
#endif

	if ( ast->Attributes )
		result.append_fmt( "%S ", ast->Attributes.to_string() );

	if ( ast->Specs )
		result.append_fmt( "%S %S", ast->Name, ast->Specs.to_string() );
	else
		result.append_fmt( "%S", ast->Name );

	if ( ast->IsParamPack )
		result.append( "..." );
}

String CodeUnion::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodeUnion::to_string( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	result.append( "union " );

	if ( ast->Attributes )
		result.append_fmt( "%S ", ast->Attributes.to_string() );

	if ( ast->Name )
	{
		result.append_fmt( "%S\n{\n%S\n}", ast->Name, ast->Body.to_string() );
	}
	else
	{
		// Anonymous union
		result.append_fmt( "\n{\n%S\n}", ast->Body.to_string() );
	}

	if ( ast->Parent.ast == nullptr || ( ast->Parent->Type != ECode::Typedef && ast->Parent->Type != ECode::Variable ) )
		result.append( ";\n" );
}

String CodeUsing::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	switch ( ast->Type )
	{
		using namespace ECode;
		case Using :
			to_string( result );
			break;
		case Using_Namespace :
			to_string_ns( result );
			break;
	}
	return result;
}

void CodeUsing::to_string( String& result )
{
	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Attributes )
		result.append_fmt( "%S ", ast->Attributes.to_string() );

	if ( ast->UnderlyingType )
	{
		result.append_fmt( "using %S = %S", ast->Name, ast->UnderlyingType.to_string() );

		if ( ast->UnderlyingType->ArrExpr )
		{
			result.append_fmt( "[ %S ]", ast->UnderlyingType->ArrExpr.to_string() );

			AST* next_arr_expr = ast->UnderlyingType->ArrExpr->Next;
			while ( next_arr_expr )
			{
				result.append_fmt( "[ %S ]", next_arr_expr->to_string() );
				next_arr_expr = next_arr_expr->Next;
			}
		}

		result.append( ";" );
	}
	else
		result.append_fmt( "using %S;", ast->Name );

	if ( ast->InlineCmt )
		result.append_fmt( "  %S\n", ast->InlineCmt->Content );
	else
		result.append( "\n" );
}

void CodeUsing::to_string_ns( String& result )
{
	if ( ast->InlineCmt )
		result.append_fmt( "using namespace $S;  %S", ast->Name, ast->InlineCmt->Content );
	else
		result.append_fmt( "using namespace %s;\n", ast->Name );
}

String CodeVar::to_string()
{
	String result = String::make( GlobalAllocator, "" );
	to_string( result );
	return result;
}

void CodeVar::to_string( String& result )
{
	if ( ast->Parent && ast->Parent->Type == ECode::Variable )
	{
		// Its a comma-separated variable ( a NextVar )

		if ( ast->Specs )
			result.append_fmt( "%S ", ast->Specs.to_string() );

		result.append( ast->Name );

		if ( ast->ValueType->ArrExpr )
		{
			result.append_fmt( "[ %S ]", ast->ValueType->ArrExpr.to_string() );

			AST* next_arr_expr = ast->ValueType->ArrExpr->Next;
			while ( next_arr_expr )
			{
				result.append_fmt( "[ %S ]", next_arr_expr->to_string() );
				next_arr_expr = next_arr_expr->Next;
			}
		}

		if ( ast->Value )
		{
			if ( ast->VarConstructorInit )
				result.append_fmt( "( %S ", ast->Value.to_string() );
			else
				result.append_fmt( " = %S", ast->Value.to_string() );
		}

		// Keep the chain going...
		if ( ast->NextVar )
			result.append_fmt( ", %S", ast->NextVar.to_string() );

		if ( ast->VarConstructorInit )
			result.append( " )" );

		return;
	}

	if ( bitfield_is_equal( u32, ast->ModuleFlags, ModuleFlag::Export ) )
		result.append( "export " );

	if ( ast->Attributes || ast->Specs )
	{
		if ( ast->Attributes )
			result.append_fmt( "%S ", ast->Specs.to_string() );

		if ( ast->Specs )
			result.append_fmt( "%S\n", ast->Specs.to_string() );

		result.append_fmt( "%S %S", ast->ValueType.to_string(), ast->Name );

		if ( ast->ValueType->ArrExpr )
		{
			result.append_fmt( "[ %S ]", ast->ValueType->ArrExpr.to_string() );

			AST* next_arr_expr = ast->ValueType->ArrExpr->Next;
			while ( next_arr_expr )
			{
				result.append_fmt( "[ %S ]", next_arr_expr->to_string() );
				next_arr_expr = next_arr_expr->Next;
			}
		}

		if ( ast->BitfieldSize )
			result.append_fmt( " : %S", ast->BitfieldSize.to_string() );

		if ( ast->Value )
		{
			if ( ast->VarConstructorInit )
				result.append_fmt( "( %S ", ast->Value.to_string() );
			else
				result.append_fmt( " = %S", ast->Value.to_string() );
		}

		if ( ast->NextVar )
			result.append_fmt( ", %S", ast->NextVar.to_string() );

		if ( ast->VarConstructorInit )
			result.append( " )" );

		if ( ast->InlineCmt )
			result.append_fmt( ";  %S", ast->InlineCmt->Content );
		else
			result.append( ";\n" );

		return;
	}

	if ( ast->BitfieldSize )
		result.append_fmt( "%S %S : %S", ast->ValueType.to_string(), ast->Name, ast->BitfieldSize.to_string() );

	else if ( ast->ValueType->ArrExpr )
	{
		result.append_fmt( "%S %S[ %S ]", ast->ValueType.to_string(), ast->Name, ast->ValueType->ArrExpr.to_string() );

		AST* next_arr_expr = ast->ValueType->ArrExpr->Next;
		while ( next_arr_expr )
		{
			result.append_fmt( "[ %S ]", next_arr_expr->to_string() );
			next_arr_expr = next_arr_expr->Next;
		}
	}

	else
		result.append_fmt( "%S %S", ast->ValueType.to_string(), ast->Name );

	if ( ast->Value )
	{
		if ( ast->VarConstructorInit )
			result.append_fmt( "( %S ", ast->Value.to_string() );
		else
			result.append_fmt( " = %S", ast->Value.to_string() );
	}

	if ( ast->NextVar )
		result.append_fmt( ", %S", ast->NextVar.to_string() );

	if ( ast->VarConstructorInit )
		result.append( " )" );

	result.append( ";" );

	if ( ast->InlineCmt )
		result.append_fmt( "  %S", ast->InlineCmt->Content );
	else
		result.append( "\n" );
}

#pragma endregion AST

#pragma region Interface

namespace parser
{
	internal void init();
	internal void deinit();
}

internal void* Global_Allocator_Proc( void* allocator_data, AllocType type, sw size, sw alignment, void* old_memory, sw old_size, u64 flags )
{
	Arena* last = &Global_AllocatorBuckets.back();

	switch ( type )
	{
		case EAllocation_ALLOC :
		{
			if ( ( last->TotalUsed + size ) > last->TotalSize )
			{
				Arena bucket = Arena::init_from_allocator( heap(), Global_BucketSize );

				if ( bucket.PhysicalStart == nullptr )
					GEN_FATAL( "Failed to create bucket for Global_AllocatorBuckets" );

				if ( ! Global_AllocatorBuckets.append( bucket ) )
					GEN_FATAL( "Failed to append bucket to Global_AllocatorBuckets" );

				last = &Global_AllocatorBuckets.back();
			}

			return alloc_align( *last, size, alignment );
		}
		case EAllocation_FREE :
		{
			// Doesn't recycle.
		}
		break;
		case EAllocation_FREE_ALL :
		{
			// Memory::cleanup instead.
		}
		break;
		case EAllocation_RESIZE :
		{
			if ( last->TotalUsed + size > last->TotalSize )
			{
				Arena bucket = Arena::init_from_allocator( heap(), Global_BucketSize );

				if ( bucket.PhysicalStart == nullptr )
					GEN_FATAL( "Failed to create bucket for Global_AllocatorBuckets" );

				if ( ! Global_AllocatorBuckets.append( bucket ) )
					GEN_FATAL( "Failed to append bucket to Global_AllocatorBuckets" );

				last = &Global_AllocatorBuckets.back();
			}

			void* result = alloc_align( last->Backing, size, alignment );

			if ( result != nullptr && old_memory != nullptr )
			{
				mem_copy( result, old_memory, old_size );
			}

			return result;
		}
	}

	return nullptr;
}

internal void define_constants()
{
	Code::Global          = make_code();
	Code::Global->Name    = get_cached_string( txt( "Global Code" ) );
	Code::Global->Content = Code::Global->Name;

	Code::Invalid         = make_code();
	Code::Invalid.set_global();

	t_empty       = (CodeType)make_code();
	t_empty->Type = ECode::Typename;
	t_empty->Name = get_cached_string( txt( "" ) );
	t_empty.set_global();

	access_private       = make_code();
	access_private->Type = ECode::Access_Private;
	access_private->Name = get_cached_string( txt( "private:\n" ) );
	access_private.set_global();

	access_protected       = make_code();
	access_protected->Type = ECode::Access_Protected;
	access_protected->Name = get_cached_string( txt( "protected:\n" ) );
	access_protected.set_global();

	access_public       = make_code();
	access_public->Type = ECode::Access_Public;
	access_public->Name = get_cached_string( txt( "public:\n" ) );
	access_public.set_global();

	attrib_api_export = def_attributes( code( GEN_API_Export_Code ) );
	attrib_api_export.set_global();

	attrib_api_import = def_attributes( code( GEN_API_Import_Code ) );
	attrib_api_import.set_global();

	module_global_fragment          = make_code();
	module_global_fragment->Type    = ECode::Untyped;
	module_global_fragment->Name    = get_cached_string( txt( "module;" ) );
	module_global_fragment->Content = module_global_fragment->Name;
	module_global_fragment.set_global();

	module_private_fragment          = make_code();
	module_private_fragment->Type    = ECode::Untyped;
	module_private_fragment->Name    = get_cached_string( txt( "module : private;" ) );
	module_private_fragment->Content = module_private_fragment->Name;
	module_private_fragment.set_global();

	fmt_newline       = make_code();
	fmt_newline->Type = ECode::NewLine;
	fmt_newline.set_global();

	pragma_once          = (CodePragma)make_code();
	pragma_once->Type    = ECode::Preprocess_Pragma;
	pragma_once->Name    = get_cached_string( txt( "once" ) );
	pragma_once->Content = pragma_once->Name;
	pragma_once.set_global();

	param_varadic            = (CodeType)make_code();
	param_varadic->Type      = ECode::Parameters;
	param_varadic->Name      = get_cached_string( txt( "..." ) );
	param_varadic->ValueType = t_empty;
	param_varadic.set_global();

	preprocess_else       = (CodePreprocessCond)make_code();
	preprocess_else->Type = ECode::Preprocess_Else;
	preprocess_else.set_global();

	preprocess_endif       = (CodePreprocessCond)make_code();
	preprocess_endif->Type = ECode::Preprocess_EndIf;
	preprocess_endif.set_global();

#define def_constant_code_type( Type_ )    \
	t_##Type_ = def_type( name( Type_ ) ); \
	t_##Type_.set_global();

	def_constant_code_type( auto );
	def_constant_code_type( void );
	def_constant_code_type( int );
	def_constant_code_type( bool );
	def_constant_code_type( char );
	def_constant_code_type( wchar_t );
	def_constant_code_type( class );
	def_constant_code_type( typename );

#ifdef GEN_DEFINE_LIBRARY_CODE_CONSTANTS
	t_b32 = def_type( name( b32 ) );

	def_constant_code_type( s8 );
	def_constant_code_type( s16 );
	def_constant_code_type( s32 );
	def_constant_code_type( s64 );

	def_constant_code_type( u8 );
	def_constant_code_type( u16 );
	def_constant_code_type( u32 );
	def_constant_code_type( u64 );

	def_constant_code_type( sw );
	def_constant_code_type( uw );

	def_constant_code_type( f32 );
	def_constant_code_type( f64 );
#endif
#undef def_constant_code_type


#define def_constant_spec( Type_, ... )                                    \
	spec_##Type_ = def_specifiers( num_args( __VA_ARGS__ ), __VA_ARGS__ ); \
	spec_##Type_.set_global();

#pragma push_macro( "FORCEINLINE" )
#pragma push_macro( "global" )
#pragma push_macro( "internal" )
#pragma push_macro( "local_persist" )
#pragma push_macro( "neverinline" )
#undef FORCEINLINE
#undef global
#undef internal
#undef local_persist
#undef neverinline
	def_constant_spec( const, ESpecifier::Const );
	def_constant_spec( consteval, ESpecifier::Consteval );
	def_constant_spec( constexpr, ESpecifier::Constexpr );
	def_constant_spec( constinit, ESpecifier::Constinit );
	def_constant_spec( extern_linkage, ESpecifier::External_Linkage );
	def_constant_spec( final, ESpecifier::Final );
	def_constant_spec( FORCEINLINE, ESpecifier::ForceInline );
	def_constant_spec( global, ESpecifier::Global );
	def_constant_spec( inline, ESpecifier::Inline );
	def_constant_spec( internal_linkage, ESpecifier::Internal_Linkage );
	def_constant_spec( local_persist, ESpecifier::Local_Persist );
	def_constant_spec( mutable, ESpecifier::Mutable );
	def_constant_spec( neverinline, ESpecifier::NeverInline );
	def_constant_spec( noexcept, ESpecifier::NoExceptions );
	def_constant_spec( override, ESpecifier::Override );
	def_constant_spec( ptr, ESpecifier::Ptr );
	def_constant_spec( pure, ESpecifier::Pure ) def_constant_spec( ref, ESpecifier::Ref );
	def_constant_spec( register, ESpecifier::Register );
	def_constant_spec( rvalue, ESpecifier::RValue );
	def_constant_spec( static_member, ESpecifier::Static );
	def_constant_spec( thread_local, ESpecifier::Thread_Local );
	def_constant_spec( virtual, ESpecifier::Virtual );
	def_constant_spec( volatile, ESpecifier::Volatile )

	    spec_local_persist = def_specifiers( 1, ESpecifier::Local_Persist );
	spec_local_persist.set_global();

#pragma pop_macro( "FORCEINLINE" )
#pragma pop_macro( "global" )
#pragma pop_macro( "internal" )
#pragma pop_macro( "local_persist" )
#pragma pop_macro( "neverinline" )

#undef def_constant_spec
}

void init()
{
	// Setup global allocator
	{
		GlobalAllocator         = AllocatorInfo { &Global_Allocator_Proc, nullptr };

		Global_AllocatorBuckets = Array<Arena>::init_reserve( heap(), 128 );

		if ( Global_AllocatorBuckets == nullptr )
			GEN_FATAL( "Failed to reserve memory for Global_AllocatorBuckets" );

		Arena bucket = Arena::init_from_allocator( heap(), Global_BucketSize );

		if ( bucket.PhysicalStart == nullptr )
			GEN_FATAL( "Failed to create first bucket for Global_AllocatorBuckets" );

		Global_AllocatorBuckets.append( bucket );
	}

	// Setup the arrays
	{
		CodePools = Array<Pool>::init_reserve( Allocator_DataArrays, InitSize_DataArrays );

		if ( CodePools == nullptr )
			GEN_FATAL( "gen::init: Failed to initialize the CodePools array" );

		StringArenas = Array<Arena>::init_reserve( Allocator_DataArrays, InitSize_DataArrays );

		if ( StringArenas == nullptr )
			GEN_FATAL( "gen::init: Failed to initialize the StringArenas array" );
	}

	// Setup the code pool and code entries arena.
	{
		Pool code_pool = Pool::init( Allocator_CodePool, CodePool_NumBlocks, sizeof( AST ) );

		if ( code_pool.PhysicalStart == nullptr )
			GEN_FATAL( "gen::init: Failed to initialize the code pool" );

		CodePools.append( code_pool );

		LexArena           = Arena::init_from_allocator( Allocator_Lexer, LexAllocator_Size );

		Arena string_arena = Arena::init_from_allocator( Allocator_StringArena, SizePer_StringArena );

		if ( string_arena.PhysicalStart == nullptr )
			GEN_FATAL( "gen::init: Failed to initialize the string arena" );

		StringArenas.append( string_arena );
	}

	// Setup the hash tables
	{
		StringCache = StringTable::init( Allocator_StringTable );

		if ( StringCache.Entries == nullptr )
			GEN_FATAL( "gen::init: Failed to initialize the StringCache" );
	}

	// Preprocessor Defines
	PreprocessorDefines = Array<StringCached>::init_reserve( GlobalAllocator, kilobytes( 1 ) );

	define_constants();
	parser::init();
}

void deinit()
{
	uw index = 0;
	uw left  = CodePools.num();
	do
	{
		Pool* code_pool = &CodePools[index];
		code_pool->free();
		index++;
	} while ( left--, left );

	index = 0;
	left  = StringArenas.num();
	do
	{
		Arena* string_arena = &StringArenas[index];
		string_arena->free();
		index++;
	} while ( left--, left );

	StringCache.destroy();

	CodePools.free();
	StringArenas.free();

	LexArena.free();

	PreprocessorDefines.free();

	index = 0;
	left  = Global_AllocatorBuckets.num();
	do
	{
		Arena* bucket = &Global_AllocatorBuckets[index];
		bucket->free();
		index++;
	} while ( left--, left );

	Global_AllocatorBuckets.free();
	parser::deinit();
}

void reset()
{
	s32 index = 0;
	s32 left  = CodePools.num();
	do
	{
		Pool* code_pool = &CodePools[index];
		code_pool->clear();
		index++;
	} while ( left--, left );

	index = 0;
	left  = StringArenas.num();
	do
	{
		Arena* string_arena     = &StringArenas[index];
		string_arena->TotalUsed = 0;
		;
		index++;
	} while ( left--, left );

	StringCache.clear();

	define_constants();
}

AllocatorInfo get_string_allocator( s32 str_length )
{
	Arena* last = &StringArenas.back();

	uw size_req = str_length + sizeof( String::Header ) + sizeof( char* );

	if ( last->TotalUsed + sw( size_req ) > last->TotalSize )
	{
		Arena new_arena = Arena::init_from_allocator( Allocator_StringArena, SizePer_StringArena );

		if ( ! StringArenas.append( new_arena ) )
			GEN_FATAL( "gen::get_string_allocator: Failed to allocate a new string arena" );

		last = &StringArenas.back();
	}

	return *last;
}

// Will either make or retrive a code string.
StringCached get_cached_string( StrC str )
{
	s32 hash_length = str.Len > kilobytes( 1 ) ? kilobytes( 1 ) : str.Len;
	u64 key         = crc32( str.Ptr, hash_length );
	{
		StringCached* result = StringCache.get( key );

		if ( result )
			return *result;
	}

	String result = String::make( get_string_allocator( str.Len ), str );
	StringCache.set( key, result );

	return result;
}

// Used internally to retireve a Code object form the CodePool.
Code make_code()
{
	Pool* allocator = &CodePools.back();
	if ( allocator->FreeList == nullptr )
	{
		Pool code_pool = Pool::init( Allocator_CodePool, CodePool_NumBlocks, sizeof( AST ) );

		if ( code_pool.PhysicalStart == nullptr )
			GEN_FATAL( "gen::make_code: Failed to allocate a new code pool - CodePool allcoator returned nullptr." );

		if ( ! CodePools.append( code_pool ) )
			GEN_FATAL( "gen::make_code: Failed to allocate a new code pool - CodePools failed to append new pool." );

		allocator = &CodePools.back();
	}

	Code result { rcast( AST*, alloc( *allocator, sizeof( AST ) ) ) };
	mem_set( result.ast, 0, sizeof( AST ) );
	// result->Type = ECode::Invalid;

	// result->Content     = { nullptr };
	// result->Prev        = { nullptr };
	// result->Next        = { nullptr };
	// result->Token		= nullptr;
	// result->Parent      = { nullptr };
	// result->Name        = { nullptr };
	// result->Type        = ECode::Invalid;
	// result->ModuleFlags = ModuleFlag::Invalid;
	// result->NumEntries  = 0;

	return result;
}

void set_allocator_data_arrays( AllocatorInfo allocator )
{
	Allocator_DataArrays = allocator;
}

void set_allocator_code_pool( AllocatorInfo allocator )
{
	Allocator_CodePool = allocator;
}

void set_allocator_lexer( AllocatorInfo allocator )
{
	Allocator_Lexer = allocator;
}

void set_allocator_string_arena( AllocatorInfo allocator )
{
	Allocator_StringArena = allocator;
}

void set_allocator_string_table( AllocatorInfo allocator )
{
	Allocator_StringArena = allocator;
}

#pragma region Upfront

enum class OpValidateResult : u32
{
	Fail,
	Global,
	Member
};

OpValidateResult operator__validate( OperatorT op, CodeParam params_code, CodeType ret_type, CodeSpecifiers specifier )
{
	using namespace EOperator;

	if ( op == EOperator::Invalid )
	{
		log_failure( "gen::def_operator: op cannot be invalid" );
		return OpValidateResult::Fail;
	}

#pragma region Helper Macros
#define check_params()                                                                                      \
	if ( ! params_code )                                                                                    \
	{                                                                                                       \
		log_failure( "gen::def_operator: params is null and operator%s requires it", to_str( op ) );        \
		return OpValidateResult::Fail;                                                                      \
	}                                                                                                       \
	if ( params_code->Type != ECode::Parameters )                                                           \
	{                                                                                                       \
		log_failure( "gen::def_operator: params is not of Parameters type - %s", params_code.debug_str() ); \
		return OpValidateResult::Fail;                                                                      \
	}

#define check_param_eq_ret()                                                                \
	if ( ! is_member_symbol && ! params_code->ValueType.is_equal( ret_type ) )              \
	{                                                                                       \
		log_failure(                                                                        \
		    "gen::def_operator: operator%s requires first parameter to equal return type\n" \
		    "param types: %s\n"                                                             \
		    "return type: %s",                                                              \
		    to_str( op ).Ptr,                                                               \
		    params_code.debug_str(),                                                        \
		    ret_type.debug_str()                                                            \
		);                                                                                  \
		return OpValidateResult::Fail;                                                      \
	}
#pragma endregion Helper Macros

	if ( ! ret_type )
	{
		log_failure( "gen::def_operator: ret_type is null but is required by operator%s", to_str( op ) );
	}

	if ( ret_type->Type != ECode::Typename )
	{
		log_failure( "gen::def_operator: ret_type is not of typename type - %s", ret_type.debug_str() );
		return OpValidateResult::Fail;
	}

	bool is_member_symbol = false;

	switch ( op )
	{
#define specs( ... ) num_args( __VA_ARGS__ ), __VA_ARGS__
		case Assign :
			check_params();

			if ( params_code->NumEntries > 1 )
			{
				log_failure(
				    "gen::def_operator: "
				    "operator%s does not support non-member definition (more than one parameter provided) - %s",
				    to_str( op ),
				    params_code.debug_str()
				);
				return OpValidateResult::Fail;
			}

			is_member_symbol = true;
			break;

		case Assign_Add :
		case Assign_Subtract :
		case Assign_Multiply :
		case Assign_Divide :
		case Assign_Modulo :
		case Assign_BAnd :
		case Assign_BOr :
		case Assign_BXOr :
		case Assign_LShift :
		case Assign_RShift :
			check_params();

			if ( params_code->NumEntries == 1 )
				is_member_symbol = true;

			else
				check_param_eq_ret();

			if ( params_code->NumEntries > 2 )
			{
				log_failure(
				    "gen::def_operator: operator%s may not be defined with more than two parametes - param count; %d\n%s",
				    to_str( op ),
				    params_code->NumEntries,
				    params_code.debug_str()
				);
				return OpValidateResult::Fail;
			}
			break;

		case Increment :
		case Decrement :
			// If its not set, it just means its a prefix member op.
			if ( params_code )
			{
				if ( params_code->Type != ECode::Parameters )
				{
					log_failure( "gen::def_operator: operator%s params code provided is not of Parameters type - %s", to_str( op ), params_code.debug_str() );
					return OpValidateResult::Fail;
				}

				switch ( params_code->NumEntries )
				{
					case 1 :
						if ( params_code->ValueType.is_equal( t_int ) )
							is_member_symbol = true;

						else
							check_param_eq_ret();
						break;

					case 2 :
						check_param_eq_ret();

						if ( ! params_code.get( 1 ).is_equal( t_int ) )
						{
							log_failure(
							    "gen::def_operator: "
							    "operator%s requires second parameter of non-member definition to be int for post-decrement",
							    to_str( op )
							);
							return OpValidateResult::Fail;
						}
						break;

					default :
						log_failure(
						    "gen::def_operator: operator%s recieved unexpected number of parameters recived %d instead of 0-2",
						    to_str( op ),
						    params_code->NumEntries
						);
						return OpValidateResult::Fail;
				}
			}
			break;

		case Unary_Plus :
		case Unary_Minus :
			if ( ! params_code )
				is_member_symbol = true;

			else
			{
				if ( params_code->Type != ECode::Parameters )
				{
					log_failure( "gen::def_operator: params is not of Parameters type - %s", params_code.debug_str() );
					return OpValidateResult::Fail;
				}

				if ( params_code->ValueType.is_equal( ret_type ) )
				{
					log_failure(
					    "gen::def_operator: "
					    "operator%s is non-member symbol yet first paramter does not equal return type\n"
					    "param type: %s\n"
					    "return type: %s\n",
					    params_code.debug_str(),
					    ret_type.debug_str()
					);
					return OpValidateResult::Fail;
				}

				if ( params_code->NumEntries > 1 )
				{
					log_failure(
					    "gen::def_operator: operator%s may not have more than one parameter - param count: %d",
					    to_str( op ),
					    params_code->NumEntries
					);
					return OpValidateResult::Fail;
				}
			}
			break;

		case BNot :
		{
			// Some compilers let you do this...
#if 0
			if ( ! ret_type.is_equal( t_bool) )
			{
				log_failure( "gen::def_operator: return type is not a boolean - %s", params_code.debug_str() );
				return OpValidateResult::Fail;
			}
#endif

			if ( ! params_code )
				is_member_symbol = true;

			else
			{
				if ( params_code->Type != ECode::Parameters )
				{
					log_failure( "gen::def_operator: params is not of Parameters type - %s", params_code.debug_str() );
					return OpValidateResult::Fail;
				}

				if ( params_code->NumEntries > 1 )
				{
					log_failure(
					    "gen::def_operator: operator%s may not have more than one parameter - param count: %d",
					    to_str( op ),
					    params_code->NumEntries
					);
					return OpValidateResult::Fail;
				}
			}
			break;
		}

		case Add :
		case Subtract :
		case Multiply :
		case Divide :
		case Modulo :
		case BAnd :
		case BOr :
		case BXOr :
		case LShift :
		case RShift :
			check_params();

			switch ( params_code->NumEntries )
			{
				case 1 :
					is_member_symbol = true;
					break;

				case 2 :
					if ( ! params_code->ValueType.is_equal( ret_type ) )
					{
						log_failure(
						    "gen::def_operator: "
						    "operator%s is non-member symbol yet first paramter does not equal return type\n"
						    "param type: %s\n"
						    "return type: %s\n",
						    params_code.debug_str(),
						    ret_type.debug_str()
						);
						return OpValidateResult::Fail;
					}
					break;

				default :
					log_failure(
					    "gen::def_operator: operator%s recieved unexpected number of paramters recived %d instead of 0-2",
					    to_str( op ),
					    params_code->NumEntries
					);
					return OpValidateResult::Fail;
			}
			break;

		case UnaryNot :
			if ( ! params_code )
				is_member_symbol = true;

			else
			{
				if ( params_code->Type != ECode::Parameters )
				{
					log_failure( "gen::def_operator: params is not of Parameters type - %s", params_code.debug_str() );
					return OpValidateResult::Fail;
				}

				if ( params_code->NumEntries != 1 )
				{
					log_failure(
					    "gen::def_operator: operator%s recieved unexpected number of paramters recived %d instead of 0-1",
					    to_str( op ),
					    params_code->NumEntries
					);
					return OpValidateResult::Fail;
				}
			}

			if ( ! ret_type.is_equal( t_bool ) )
			{
				log_failure( "gen::def_operator: operator%s return type must be of type bool - %s", to_str( op ), ret_type.debug_str() );
				return OpValidateResult::Fail;
			}
			break;

		case LAnd :
		case LOr :
		case LEqual :
		case LNot :
		case Lesser :
		case Greater :
		case LesserEqual :
		case GreaterEqual :
			check_params();

			switch ( params_code->NumEntries )
			{
				case 1 :
					is_member_symbol = true;
					break;

				case 2 :
					break;

				default :
					log_failure(
					    "gen::def_operator: operator%s recieved unexpected number of paramters recived %d instead of 1-2",
					    to_str( op ),
					    params_code->NumEntries
					);
					return OpValidateResult::Fail;
			}
			break;

		case Indirection :
		case AddressOf :
		case MemberOfPointer :
			if ( params_code && params_code->NumEntries > 1 )
			{
				log_failure(
				    "gen::def_operator: operator%s recieved unexpected number of paramters recived %d instead of 0-1",
				    to_str( op ),
				    params_code->NumEntries
				);
				return OpValidateResult::Fail;
			}
			else
			{
				is_member_symbol = true;
			}
			break;

		case PtrToMemOfPtr :
			if ( params_code )
			{
				log_failure( "gen::def_operator: operator%s expects no paramters - %s", to_str( op ), params_code.debug_str() );
				return OpValidateResult::Fail;
			}
			break;

		case Subscript :
		case FunctionCall :
		case Comma :
			check_params();
			break;

		case New :
		case Delete :
			// This library doesn't support validating new and delete yet.
			break;
#undef specs
	}

	return is_member_symbol ? OpValidateResult::Member : OpValidateResult::Global;
#undef check_params
#undef check_ret_type
#undef check_param_eq_ret
}

#pragma region Helper Marcos
// This snippet is used in nearly all the functions.
#define name_check( Context_, Name_ )                                                                      \
	{                                                                                                      \
		if ( Name_.Len <= 0 )                                                                              \
		{                                                                                                  \
			log_failure( "gen::" stringize( Context_ ) ": Invalid name length provided - %d", Name_.Len ); \
			return CodeInvalid;                                                                            \
		}                                                                                                  \
                                                                                                           \
		if ( Name_.Ptr == nullptr )                                                                        \
		{                                                                                                  \
			log_failure( "gen::" stringize( Context_ ) ": name is null" );                                 \
			return CodeInvalid;                                                                            \
		}                                                                                                  \
	}

#define null_check( Context_, Code_ )                                                             \
	if ( ! Code_ )                                                                                \
	{                                                                                             \
		log_failure( "gen::" stringize( Context_ ) ": " stringize( Code_ ) " provided is null" ); \
		return CodeInvalid;                                                                       \
	}

#define null_or_invalid_check( Context_, Code_ )                                                         \
	{                                                                                                    \
		if ( ! Code_ )                                                                                   \
		{                                                                                                \
			log_failure( "gen::" stringize( Context_ ) ": " stringize( Code_ ) " provided is null" );    \
			return CodeInvalid;                                                                          \
		}                                                                                                \
                                                                                                         \
		if ( Code_->is_invalid() )                                                                       \
		{                                                                                                \
			log_failure( "gen::" stringize( Context_ ) ": " stringize( Code_ ) " provided is invalid" ); \
			return CodeInvalid;                                                                          \
		}                                                                                                \
	}

#define not_implemented( Context_ )                             \
	log_failure( "gen::%s: This function is not implemented" ); \
	return CodeInvalid;
#pragma endregion Helper Marcos

/*
The implementaiton of the upfront constructors involves doing three things:
* Validate the arguments given to construct the intended type of AST is valid.
* Construct said AST type.
* Lock the AST (set to readonly) and return the valid object.

If any of the validation fails, it triggers a call to log_failure with as much info the give the user so that they can hopefully
identify the issue without having to debug too much (at least they can debug though...)

The largest of the functions is related to operator overload definitions.
The library validates a good protion of their form and thus the argument processing for is quite a bit.
*/
CodeAttributes def_attributes( StrC content )
{
	if ( content.Len <= 0 || content.Ptr == nullptr )
	{
		log_failure( "gen::def_attributes: Invalid attributes provided" );
		return CodeInvalid;
	}

	Code result     = make_code();
	result->Type    = ECode::PlatformAttributes;
	result->Name    = get_cached_string( content );
	result->Content = result->Name;

	return (CodeAttributes)result;
}

CodeComment def_comment( StrC content )
{
	if ( content.Len <= 0 || content.Ptr == nullptr )
	{
		log_failure( "gen::def_comment: Invalid comment provided:" );
		return CodeInvalid;
	}

	static char line[MaxCommentLineLength];

	String      cmt_formatted = String::make_reserve( GlobalAllocator, kilobytes( 1 ) );
	char const* end           = content.Ptr + content.Len;
	char const* scanner       = content.Ptr;
	s32         curr          = 0;
	do
	{
		char const* next   = scanner;
		s32         length = 0;
		while ( next != end && scanner[length] != '\n' )
		{
			next = scanner + length;
			length++;
		}
		length++;

		str_copy( line, scanner, length );
		cmt_formatted.append_fmt( "//%.*s", length, line );
		mem_set( line, 0, MaxCommentLineLength );

		scanner += length;
	} while ( scanner <= end );

	if ( cmt_formatted.back() != '\n' )
		cmt_formatted.append( "\n" );

	Code result     = make_code();
	result->Type    = ECode::Comment;
	result->Name    = get_cached_string( cmt_formatted );
	result->Content = result->Name;

	cmt_formatted.free();

	return (CodeComment)result;
}

CodeConstructor def_constructor( CodeParam params, Code initializer_list, Code body )
{
	using namespace ECode;

	if ( params && params->Type != Parameters )
	{
		log_failure( "gen::def_constructor: params must be of Parameters type - %s", params.debug_str() );
		return CodeInvalid;
	}

	CodeConstructor result = (CodeConstructor)make_code();

	if ( params )
	{
		result->Params = params;
	}

	if ( initializer_list )
	{
		result->InitializerList = initializer_list;
	}

	if ( body )
	{
		switch ( body->Type )
		{
			case Function_Body :
			case Untyped :
				break;

			default :
				log_failure( "gen::def_constructor: body must be either of Function_Body or Untyped type - %s", body.debug_str() );
				return CodeInvalid;
		}

		result->Type = Constructor;
		result->Body = body;
	}
	else
	{
		result->Type = Constructor_Fwd;
	}

	return result;
}

CodeClass def_class(
    StrC           name,
    Code           body,
    CodeType       parent,
    AccessSpec     parent_access,
    CodeAttributes attributes,
    ModuleFlag     mflags,
    CodeType*      interfaces,
    s32            num_interfaces
)
{
	using namespace ECode;

	name_check( def_class, name );

	if ( attributes && attributes->Type != PlatformAttributes )
	{
		log_failure( "gen::def_class: attributes was not a 'PlatformAttributes' type: %s", attributes.debug_str() );
		return CodeInvalid;
	}

	if ( parent && ( parent->Type != Class && parent->Type != Struct && parent->Type != Typename && parent->Type != Untyped ) )
	{
		log_failure( "gen::def_class: parent provided is not type 'Class', 'Struct', 'Typeanme', or 'Untyped': %s", parent.debug_str() );
		return CodeInvalid;
	}

	CodeClass result    = (CodeClass)make_code();
	result->Name        = get_cached_string( name );
	result->ModuleFlags = mflags;

	if ( body )
	{
		switch ( body->Type )
		{
			case Class_Body :
			case Untyped :
				break;

			default :
				log_failure( "gen::def_class: body must be either of Class_Body or Untyped type - %s", body.debug_str() );
				return CodeInvalid;
		}

		result->Type         = Class;
		result->Body         = body;
		result->Body->Parent = result;    // TODO(Ed): Review this?
	}
	else
	{
		result->Type = Class_Fwd;
	}

	if ( attributes )
		result->Attributes = attributes;

	if ( parent )
	{
		result->ParentAccess = parent_access;
		result->ParentType   = parent;
	}

	if ( interfaces )
	{
		for ( s32 idx = 0; idx < num_interfaces; idx++ )
		{
			result.add_interface( interfaces[idx] );
		}
	}

	return result;
}

CodeDefine def_define( StrC name, StrC content )
{
	using namespace ECode;

	name_check( def_define, name );

	// Defines can be empty definitions
#if 0
	if ( content.Len <= 0 || content.Ptr == nullptr )
	{
		log_failure( "gen::def_define: Invalid value provided" );
		return CodeInvalid;
	}
#endif

	CodeDefine result = (CodeDefine)make_code();
	result->Type      = Preprocess_Define;
	result->Name      = get_cached_string( name );
	if ( content.Len <= 0 || content.Ptr == nullptr )
	{
		result->Content = get_cached_string( txt( "" ) );
	}
	else
		result->Content = get_cached_string( content );

	return result;
}

CodeDestructor def_destructor( Code body, CodeSpecifiers specifiers )
{
	using namespace ECode;

	if ( specifiers && specifiers->Type != Specifiers )
	{
		log_failure( "gen::def_destructor: specifiers was not a 'Specifiers' type: %s", specifiers.debug_str() );
		return CodeInvalid;
	}

	CodeDestructor result = (CodeDestructor)make_code();

	if ( specifiers )
		result->Specs = specifiers;

	if ( body )
	{
		switch ( body->Type )
		{
			case Function_Body :
			case Untyped :
				break;

			default :
				log_failure( "gen::def_destructor: body must be either of Function_Body or Untyped type - %s", body.debug_str() );
				return CodeInvalid;
		}

		result->Type = Destructor;
		result->Body = body;
	}
	else
	{
		result->Type = Destructor_Fwd;
	}

	return result;
}

CodeEnum def_enum( StrC name, Code body, CodeType type, EnumT specifier, CodeAttributes attributes, ModuleFlag mflags )
{
	using namespace ECode;

	name_check( def_enum, name );

	if ( type && type->Type != Typename )
	{
		log_failure( "gen::def_enum: enum underlying type provided was not of type Typename: %s", type.debug_str() );
		return CodeInvalid;
	}

	if ( attributes && attributes->Type != PlatformAttributes )
	{
		log_failure( "gen::def_enum: attributes was not a 'PlatformAttributes' type: %s", attributes.debug_str() );
		return CodeInvalid;
	}

	CodeEnum result     = (CodeEnum)make_code();
	result->Name        = get_cached_string( name );
	result->ModuleFlags = mflags;

	if ( body )
	{
		switch ( body->Type )
		{
			case Enum_Body :
			case Untyped :
				break;

			default :
				log_failure( "gen::def_enum: body must be of Enum_Body or Untyped type %s", body.debug_str() );
				return CodeInvalid;
		}

		result->Type = specifier == EnumClass ? Enum_Class : Enum;

		result->Body = body;
	}
	else
	{
		result->Type = specifier == EnumClass ? Enum_Class_Fwd : Enum_Fwd;
	}

	if ( attributes )
		result->Attributes = attributes;

	if ( type )
	{
		result->UnderlyingType = type;
	}
	else if ( result->Type != Enum_Class_Fwd && result->Type != Enum_Fwd )
	{
		log_failure( "gen::def_enum: enum forward declaration must have an underlying type" );
		return CodeInvalid;
	}

	return result;
}

CodeExec def_execution( StrC content )
{
	if ( content.Len <= 0 || content.Ptr == nullptr )
	{
		log_failure( "gen::def_execution: Invalid execution provided" );
		return CodeInvalid;
	}

	Code result     = make_code();
	result->Type    = ECode::Execution;
	result->Name    = get_cached_string( content );
	result->Content = result->Name;

	return (CodeExec)result;
}

CodeExtern def_extern_link( StrC name, Code body )
{
	using namespace ECode;

	name_check( def_extern_linkage, name );
	null_check( def_extern_linkage, body );

	if ( body->Type != Extern_Linkage_Body && body->Type != Untyped )
	{
		log_failure( "gen::def_extern_linkage: body is not of extern_linkage or untyped type %s", body->debug_str() );
		return CodeInvalid;
	}

	CodeExtern result = (CodeExtern)make_code();
	result->Type      = Extern_Linkage;
	result->Name      = get_cached_string( name );
	result->Body      = body;

	return (CodeExtern)result;
}

CodeFriend def_friend( Code declaration )
{
	using namespace ECode;

	null_check( def_friend, declaration );

	switch ( declaration->Type )
	{
		case Class_Fwd :
		case Function_Fwd :
		case Operator_Fwd :
		case Struct_Fwd :
		case Class :
		case Function :
		case Operator :
		case Struct :
			break;

		default :
			log_failure( "gen::def_friend: requires declartion to have class, function, operator, or struct - %s", declaration->debug_str() );
			return CodeInvalid;
	}

	CodeFriend result   = (CodeFriend)make_code();
	result->Type        = Friend;

	result->Declaration = declaration;

	return result;
}

CodeFn def_function( StrC name, CodeParam params, CodeType ret_type, Code body, CodeSpecifiers specifiers, CodeAttributes attributes, ModuleFlag mflags )
{
	using namespace ECode;

	name_check( def_function, name );

	if ( params && params->Type != Parameters )
	{
		log_failure( "gen::def_function: params was not a `Parameters` type: %s", params.debug_str() );
		return CodeInvalid;
	}

	if ( ret_type && ret_type->Type != Typename )
	{
		log_failure( "gen::def_function: ret_type was not a Typename: %s", ret_type.debug_str() );
		return CodeInvalid;
	}

	if ( specifiers && specifiers->Type != Specifiers )
	{
		log_failure( "gen::def_function: specifiers was not a `Specifiers` type: %s", specifiers.debug_str() );
		return CodeInvalid;
	}

	if ( attributes && attributes->Type != PlatformAttributes )
	{
		log_failure( "gen::def_function: attributes was not a `PlatformAttributes` type: %s", attributes.debug_str() );
		return CodeInvalid;
	}

	CodeFn result       = (CodeFn)make_code();
	result->Name        = get_cached_string( name );
	result->ModuleFlags = mflags;

	if ( body )
	{
		switch ( body->Type )
		{
			case Function_Body :
			case Execution :
			case Untyped :
				break;

			default :
			{
				log_failure( "gen::def_function: body must be either of Function_Body, Execution, or Untyped type. %s", body->debug_str() );
				return CodeInvalid;
			}
		}

		result->Type = Function;
		result->Body = body;
	}
	else
	{
		result->Type = Function_Fwd;
	}

	if ( attributes )
		result->Attributes = attributes;

	if ( specifiers )
		result->Specs = specifiers;

	if ( ret_type )
	{
		result->ReturnType = ret_type;
	}
	else
	{
		result->ReturnType = t_void;
	}

	if ( params )
		result->Params = params;

	return result;
}

CodeInclude def_include( StrC path, bool foreign )
{
	if ( path.Len <= 0 || path.Ptr == nullptr )
	{
		log_failure( "gen::def_include: Invalid path provided - %d" );
		return CodeInvalid;
	}

	StrC content    = foreign ? to_str( str_fmt_buf( "<%.*s>", path.Len, path.Ptr ) ) : to_str( str_fmt_buf( "\"%.*s\"", path.Len, path.Ptr ) );

	Code result     = make_code();
	result->Type    = ECode::Preprocess_Include;
	result->Name    = get_cached_string( content );
	result->Content = result->Name;

	return (CodeInclude)result;
}

CodeModule def_module( StrC name, ModuleFlag mflags )
{
	name_check( def_module, name );

	Code result         = make_code();
	result->Type        = ECode::Module;
	result->Name        = get_cached_string( name );
	result->Content     = result->Name;
	result->ModuleFlags = mflags;

	return (CodeModule)result;
}

CodeNS def_namespace( StrC name, Code body, ModuleFlag mflags )
{
	using namespace ECode;

	name_check( def_namespace, name );
	null_check( def_namespace, body );

	if ( body->Type != Namespace_Body && body->Type != Untyped )
	{
		log_failure( "gen::def_namespace: body is not of namespace or untyped type %s", body.debug_str() );
		return CodeInvalid;
	}

	CodeNS result       = (CodeNS)make_code();
	result->Type        = Namespace;
	result->Name        = get_cached_string( name );
	result->ModuleFlags = mflags;
	result->Body        = body;

	return result;
}

CodeOperator def_operator(
    OperatorT      op,
    StrC           nspace,
    CodeParam      params_code,
    CodeType       ret_type,
    Code           body,
    CodeSpecifiers specifiers,
    CodeAttributes attributes,
    ModuleFlag     mflags
)
{
	using namespace ECode;

	if ( attributes && attributes->Type != PlatformAttributes )
	{
		log_failure( "gen::def_operator: PlatformAttributes was provided but its not of attributes type: %s", attributes.debug_str() );
		return CodeInvalid;
	}

	if ( specifiers && specifiers->Type != Specifiers )
	{
		log_failure( "gen::def_operator: Specifiers was provided but its not of specifiers type: %s", specifiers.debug_str() );
		return CodeInvalid;
	}

	OpValidateResult check_result = operator__validate( op, params_code, ret_type, specifiers );

	if ( check_result == OpValidateResult::Fail )
	{
		return CodeInvalid;
	}

	char const* name = nullptr;

	StrC op_str      = to_str( op );
	if ( nspace.Len > 0 )
		name = str_fmt_buf( "%.*soperator %.*s", nspace.Len, nspace.Ptr, op_str.Len, op_str.Ptr );
	else
		name = str_fmt_buf( "operator %.*s", op_str.Len, op_str.Ptr );
	CodeOperator result = (CodeOperator)make_code();
	result->Name        = get_cached_string( { str_len( name ), name } );
	result->ModuleFlags = mflags;
	result->Op          = op;

	if ( body )
	{
		switch ( body->Type )
		{
			case Function_Body :
			case Execution :
			case Untyped :
				break;

			default :
			{
				log_failure( "gen::def_operator: body must be either of Function_Body, Execution, or Untyped type. %s", body->debug_str() );
				return CodeInvalid;
			}
		}

		result->Type = check_result == OpValidateResult::Global ? Operator : Operator_Member;

		result->Body = body;
	}
	else
	{
		result->Type = check_result == OpValidateResult::Global ? Operator_Fwd : Operator_Member_Fwd;
	}

	if ( attributes )
		result->Attributes = attributes;

	if ( specifiers )
		result->Specs = specifiers;

	result->ReturnType = ret_type;

	if ( params_code )
		result->Params = params_code;

	return result;
}

CodeOpCast def_operator_cast( CodeType type, Code body, CodeSpecifiers const_spec )
{
	using namespace ECode;
	null_check( def_operator_cast, type );

	if ( type->Type != Typename )
	{
		log_failure( "gen::def_operator_cast: type is not a typename - %s", type.debug_str() );
		return CodeInvalid;
	}

	CodeOpCast result = (CodeOpCast)make_code();

	if ( body )
	{
		result->Type = Operator_Cast;

		if ( body->Type != Function_Body && body->Type != Execution )
		{
			log_failure( "gen::def_operator_cast: body is not of function body or execution type - %s", body.debug_str() );
			return CodeInvalid;
		}

		result->Body = body;
	}
	else
	{
		result->Type = Operator_Cast_Fwd;
	}

	if ( const_spec )
	{
		result->Specs = const_spec;
	}

	result->ValueType = type;
	return result;
}

CodeParam def_param( CodeType type, StrC name, Code value )
{
	using namespace ECode;

	name_check( def_param, name );
	null_check( def_param, type );

	if ( type->Type != Typename )
	{
		log_failure( "gen::def_param: type is not a typename - %s", type.debug_str() );
		return CodeInvalid;
	}

	if ( value && value->Type != Untyped )
	{
		log_failure( "gen::def_param: value is not untyped - %s", value.debug_str() );
		return CodeInvalid;
	}

	CodeParam result  = (CodeParam)make_code();
	result->Type      = Parameters;
	result->Name      = get_cached_string( name );

	result->ValueType = type;

	if ( value )
		result->Value = value;

	result->NumEntries++;

	return result;
}

CodePragma def_pragma( StrC directive )
{
	using namespace ECode;

	if ( directive.Len <= 0 || directive.Ptr == nullptr )
	{
		log_failure( "gen::def_comment: Invalid comment provided:" );
		return CodeInvalid;
	}

	CodePragma result = (CodePragma)make_code();
	result->Type      = Preprocess_Pragma;
	result->Content   = get_cached_string( directive );

	return result;
}

CodePreprocessCond def_preprocess_cond( EPreprocessCond type, StrC expr )
{
	using namespace ECode;

	if ( expr.Len <= 0 || expr.Ptr == nullptr )
	{
		log_failure( "gen::def_comment: Invalid comment provided:" );
		return CodeInvalid;
	}

	CodePreprocessCond result = (CodePreprocessCond)make_code();
	result->Content           = get_cached_string( expr );

	switch ( type )
	{
		case EPreprocessCond::If :
			result->Type = Preprocess_If;
			break;
		case EPreprocessCond::IfDef :
			result->Type = Preprocess_IfDef;
			break;
		case EPreprocessCond::IfNotDef :
			result->Type = Preprocess_IfNotDef;
			break;
		case EPreprocessCond::ElIf :
			result->Type = Preprocess_ElIf;
			break;
	}

	return result;
}

CodeSpecifiers def_specifier( SpecifierT spec )
{
	CodeSpecifiers result = (CodeSpecifiers)make_code();
	result->Type          = ECode::Specifiers;
	result.append( spec );

	return result;
}

CodeStruct def_struct(
    StrC           name,
    Code           body,
    CodeType       parent,
    AccessSpec     parent_access,
    CodeAttributes attributes,
    ModuleFlag     mflags,
    CodeType*      interfaces,
    s32            num_interfaces
)
{
	using namespace ECode;

	if ( attributes && attributes->Type != PlatformAttributes )
	{
		log_failure( "gen::def_struct: attributes was not a `PlatformAttributes` type - %s", attributes.debug_str() );
		return CodeInvalid;
	}

	if ( parent && parent->Type != Typename )
	{
		log_failure( "gen::def_struct: parent was not a `Struct` type - %s", parent.debug_str() );
		return CodeInvalid;
	}

	if ( body && body->Type != Struct_Body )
	{
		log_failure( "gen::def_struct: body was not a Struct_Body type - %s", body.debug_str() );
		return CodeInvalid;
	}

	CodeStruct result   = (CodeStruct)make_code();
	result->ModuleFlags = mflags;

	if ( name )
		result->Name = get_cached_string( name );

	if ( body )
	{
		result->Type = Struct;
		result->Body = body;
	}
	else
	{
		result->Type = Struct_Fwd;
	}

	if ( attributes )
		result->Attributes = attributes;

	if ( parent )
	{
		result->ParentAccess = parent_access;
		result->ParentType   = parent;
	}

	if ( interfaces )
	{
		for ( s32 idx = 0; idx < num_interfaces; idx++ )
		{
			result.add_interface( interfaces[idx] );
		}
	}

	return result;
}

CodeTemplate def_template( CodeParam params, Code declaration, ModuleFlag mflags )
{
	null_check( def_template, declaration );

	if ( params && params->Type != ECode::Parameters )
	{
		log_failure( "gen::def_template: params is not of parameters type - %s", params.debug_str() );
		return CodeInvalid;
	}

	switch ( declaration->Type )
	{
		case ECode::Class :
		case ECode::Function :
		case ECode::Struct :
		case ECode::Variable :
		case ECode::Using :
			break;

		default :
			log_failure( "gen::def_template: declaration is not of class, function, struct, variable, or using type - %s", declaration.debug_str() );
	}

	CodeTemplate result = (CodeTemplate)make_code();
	result->Type        = ECode::Template;
	result->ModuleFlags = mflags;
	result->Params      = params;
	result->Declaration = declaration;

	return result;
}

CodeType def_type( StrC name, Code arrayexpr, CodeSpecifiers specifiers, CodeAttributes attributes )
{
	name_check( def_type, name );

	if ( attributes && attributes->Type != ECode::PlatformAttributes )
	{
		log_failure( "gen::def_type: attributes is not of attributes type - %s", attributes.debug_str() );
		return CodeInvalid;
	}

	if ( specifiers && specifiers->Type != ECode::Specifiers )
	{
		log_failure( "gen::def_type: specifiers is not of specifiers type - %s", specifiers.debug_str() );
		return CodeInvalid;
	}

	if ( arrayexpr && arrayexpr->Type != ECode::Untyped )
	{
		log_failure( "gen::def_type: arrayexpr is not of untyped type - %s", arrayexpr->debug_str() );
		return CodeInvalid;
	}

	CodeType result = (CodeType)make_code();
	result->Name    = get_cached_string( name );
	result->Type    = ECode::Typename;

	if ( attributes )
		result->Attributes = attributes;

	if ( specifiers )
		result->Specs = specifiers;

	if ( arrayexpr )
		result->ArrExpr = arrayexpr;

	return result;
}

CodeTypedef def_typedef( StrC name, Code type, CodeAttributes attributes, ModuleFlag mflags )
{
	using namespace ECode;

	null_check( def_typedef, type );

	switch ( type->Type )
	{
		case Class :
		case Class_Fwd :
		case Enum :
		case Enum_Fwd :
		case Enum_Class :
		case Enum_Class_Fwd :
		case Function_Fwd :
		case Struct :
		case Struct_Fwd :
		case Union :
		case Typename :
			break;
		default :
			log_failure( "gen::def_typedef: type was not a Class, Enum, Function Forward, Struct, Typename, or Union - %s", type.debug_str() );
			return CodeInvalid;
	}

	if ( attributes && attributes->Type != ECode::PlatformAttributes )
	{
		log_failure( "gen::def_typedef: attributes was not a PlatformAttributes - %s", attributes.debug_str() );
		return CodeInvalid;
	}

	// Registering the type.
	Code registered_type = def_type( name );

	if ( ! registered_type )
	{
		log_failure( "gen::def_typedef: failed to register type" );
		return CodeInvalid;
	}

	CodeTypedef result     = (CodeTypedef)make_code();
	result->Type           = ECode::Typedef;
	result->ModuleFlags    = mflags;

	result->UnderlyingType = type;

	if ( name.Len <= 0 )
	{
		if ( type->Type != Untyped )
		{
			log_failure( "gen::def_typedef: name was empty and type was not untyped (indicating its a function typedef) - %s", type.debug_str() );
			return CodeInvalid;
		}

		result->Name       = get_cached_string( type->Name );
		result->IsFunction = true;
	}
	else
	{
		result->Name       = get_cached_string( name );
		result->IsFunction = false;
	}

	return result;
}

CodeUnion def_union( StrC name, Code body, CodeAttributes attributes, ModuleFlag mflags )
{
	null_check( def_union, body );

	if ( body->Type != ECode::Union_Body )
	{
		log_failure( "gen::def_union: body was not a Union_Body type - %s", body.debug_str() );
		return CodeInvalid;
	}

	if ( attributes && attributes->Type != ECode::PlatformAttributes )
	{
		log_failure( "gen::def_union: attributes was not a PlatformAttributes type - %s", attributes.debug_str() );
		return CodeInvalid;
	}

	CodeUnion result    = (CodeUnion)make_code();
	result->ModuleFlags = mflags;
	result->Type        = ECode::Union;

	if ( name.Ptr )
		result->Name = get_cached_string( name );

	result->Body = body;

	if ( attributes )
		result->Attributes = attributes;

	return result;
}

CodeUsing def_using( StrC name, CodeType type, CodeAttributes attributes, ModuleFlag mflags )
{
	name_check( def_using, name );
	null_check( def_using, type );

	Code register_type = def_type( name );

	if ( ! register_type )
	{
		log_failure( "gen::def_using: failed to register type" );
		return CodeInvalid;
	}

	if ( attributes && attributes->Type != ECode::PlatformAttributes )
	{
		log_failure( "gen::def_using: attributes was not a PlatformAttributes type - %s", attributes.debug_str() );
		return CodeInvalid;
	}

	CodeUsing result       = (CodeUsing)make_code();
	result->Name           = get_cached_string( name );
	result->ModuleFlags    = mflags;
	result->Type           = ECode::Using;

	result->UnderlyingType = type;

	if ( attributes )
		result->Attributes = attributes;

	return result;
}

CodeUsing def_using_namespace( StrC name )
{
	name_check( def_using_namespace, name );

	Code result     = make_code();
	result->Name    = get_cached_string( name );
	result->Content = result->Name;
	result->Type    = ECode::Using_Namespace;

	return (CodeUsing)result;
}

CodeVar def_variable( CodeType type, StrC name, Code value, CodeSpecifiers specifiers, CodeAttributes attributes, ModuleFlag mflags )
{
	name_check( def_variable, name );
	null_check( def_variable, type );

	if ( attributes && attributes->Type != ECode::PlatformAttributes )
	{
		log_failure( "gen::def_variable: attributes was not a `PlatformAttributes` type - %s", attributes.debug_str() );
		return CodeInvalid;
	}

	if ( specifiers && specifiers->Type != ECode::Specifiers )
	{
		log_failure( "gen::def_variable: specifiers was not a `Specifiers` type - %s", specifiers.debug_str() );
		return CodeInvalid;
	}

	if ( type->Type != ECode::Typename )
	{
		log_failure( "gen::def_variable: type was not a Typename - %s", type.debug_str() );
		return CodeInvalid;
	}

	if ( value && value->Type != ECode::Untyped )
	{
		log_failure( "gen::def_variable: value was not a `Untyped` type - %s", value.debug_str() );
		return CodeInvalid;
	}

	CodeVar result      = (CodeVar)make_code();
	result->Name        = get_cached_string( name );
	result->Type        = ECode::Variable;
	result->ModuleFlags = mflags;

	result->ValueType   = type;

	if ( attributes )
		result->Attributes = attributes;

	if ( specifiers )
		result->Specs = specifiers;

	if ( value )
		result->Value = value;

	return result;
}

#pragma region Helper Macros for def_**_body functions
#define def_body_start( Name_ )                                                       \
	using namespace ECode;                                                            \
                                                                                      \
	if ( num <= 0 )                                                                   \
	{                                                                                 \
		log_failure( "gen::" stringize( Name_ ) ": num cannot be zero or negative" ); \
		return CodeInvalid;                                                           \
	}

#define def_body_code_array_start( Name_ )                                             \
	using namespace ECode;                                                             \
                                                                                       \
	if ( num <= 0 )                                                                    \
	{                                                                                  \
		log_failure( "gen::" stringize( Name_ ) ": num cannot be zero or negative" );  \
		return CodeInvalid;                                                            \
	}                                                                                  \
                                                                                       \
	if ( codes == nullptr )                                                            \
	{                                                                                  \
		log_failure( "gen::" stringize( Name_ ) " : Provided a null array of codes" ); \
		return CodeInvalid;                                                            \
	}

#pragma endregion Helper Macros for def_** _body functions

CodeBody def_class_body( s32 num, ... )
{
	def_body_start( def_class_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Class_Body;

	va_list va;
	va_start( va, num );
	do
	{
		Code_POD pod   = va_arg( va, Code_POD );
		Code     entry = pcast( Code, pod );

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_class_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_CLASS_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_class_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );
	va_end( va );

	return result;
}

CodeBody def_class_body( s32 num, Code* codes )
{
	def_body_code_array_start( def_class_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Function_Body;

	do
	{
		Code entry = *codes;
		codes++;

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_class_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_CLASS_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_class_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );

	return result;
}

CodeBody def_enum_body( s32 num, ... )
{
	def_body_start( def_enum_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Enum_Body;

	va_list va;
	va_start( va, num );
	do
	{
		Code_POD pod   = va_arg( va, Code_POD );
		Code     entry = pcast( Code, pod );

		if ( ! entry )
		{
			log_failure( "gen::def_enum_body: Provided a null entry" );
			return CodeInvalid;
		}

		if ( entry->Type != Untyped && entry->Type != Comment )
		{
			log_failure( "gen::def_enum_body: Entry type is not allowed - %s. Must be of untyped or comment type.", entry.debug_str() );
			return CodeInvalid;
		}

		result.append( entry );
	} while ( num--, num > 0 );
	va_end( va );

	return (CodeBody)result;
}

CodeBody def_enum_body( s32 num, Code* codes )
{
	def_body_code_array_start( def_enum_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Enum_Body;

	do
	{
		Code entry = *codes;

		if ( ! entry )
		{
			log_failure( "gen::def_enum_body: Provided a null entry" );
			return CodeInvalid;
		}

		if ( entry->Type != Untyped && entry->Type != Comment )
		{
			log_failure( "gen::def_enum_body: Entry type is not allowed: %s", entry.debug_str() );
			return CodeInvalid;
		}

		result.append( entry );
	} while ( codes++, num--, num > 0 );

	return result;
}

CodeBody def_export_body( s32 num, ... )
{
	def_body_start( def_export_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Export_Body;

	va_list va;
	va_start( va, num );
	do
	{
		Code_POD pod   = va_arg( va, Code_POD );
		Code     entry = pcast( Code, pod );

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_export_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_EXPORT_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_export_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );
	va_end( va );

	return result;
}

CodeBody def_export_body( s32 num, Code* codes )
{
	def_body_code_array_start( def_export_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Export_Body;

	do
	{
		Code entry = *codes;
		codes++;

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_export_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_EXPORT_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_export_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );

	return result;
}

CodeBody def_extern_link_body( s32 num, ... )
{
	def_body_start( def_extern_linkage_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Extern_Linkage_Body;

	va_list va;
	va_start( va, num );
	do
	{
		Code_POD pod   = va_arg( va, Code_POD );
		Code     entry = pcast( Code, pod );

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_extern_linkage_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_extern_linkage_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );
	va_end( va );

	return result;
}

CodeBody def_extern_link_body( s32 num, Code* codes )
{
	def_body_code_array_start( def_extern_linkage_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Extern_Linkage_Body;

	do
	{
		Code entry = *codes;
		codes++;

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_extern_linkage_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_extern_linkage_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );

	} while ( num--, num > 0 );

	return result;
}

CodeBody def_function_body( s32 num, ... )
{
	def_body_start( def_function_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Function_Body;

	va_list va;
	va_start( va, num );
	do
	{
		Code_POD pod   = va_arg( va, Code_POD );
		Code     entry = pcast( Code, pod );

		if ( ! entry )
		{
			log_failure( "gen::" stringize( def_function_body ) ": Provided an null entry" );
			return CodeInvalid;
		}

		switch ( entry->Type )
		{

			GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES
			log_failure( "gen::" stringize( def_function_body ) ": Entry type is not allowed: %s", entry.debug_str() );
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );
	va_end( va );

	return result;
}

CodeBody def_function_body( s32 num, Code* codes )
{
	def_body_code_array_start( def_function_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Function_Body;

	do
	{
		Code entry = *codes;
		codes++;

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_function_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_function_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}
		result.append( entry );
	} while ( num--, num > 0 );

	return result;
}

CodeBody def_global_body( s32 num, ... )
{
	def_body_start( def_global_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Global_Body;

	va_list va;
	va_start( va, num );
	do
	{
		Code_POD pod   = va_arg( va, Code_POD );
		Code     entry = pcast( Code, pod );

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_global_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			case Global_Body :
				result.append( entry.cast<CodeBody>() );
				continue;

				GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES
				log_failure(
				    "gen::"
				    "def_global_body"
				    ": Entry type is not allowed: %s",
				    entry.debug_str()
				);
				return ( *Code::Invalid.ast );

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );
	va_end( va );

	return result;
}

CodeBody def_global_body( s32 num, Code* codes )
{
	def_body_code_array_start( def_global_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Global_Body;

	do
	{
		Code entry = *codes;
		codes++;

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_global_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			case Global_Body :
				result.append( entry.cast<CodeBody>() );
				continue;

				GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES
				log_failure(
				    "gen::"
				    "def_global_body"
				    ": Entry type is not allowed: %s",
				    entry.debug_str()
				);
				return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );

	return result;
}

CodeBody def_namespace_body( s32 num, ... )
{
	def_body_start( def_namespace_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Namespace_Body;

	va_list va;
	va_start( va, num );
	do
	{
		Code_POD pod   = va_arg( va, Code_POD );
		Code     entry = pcast( Code, pod );

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_namespace_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_namespace_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );
	va_end( va );

	return result;
}

CodeBody def_namespace_body( s32 num, Code* codes )
{
	def_body_code_array_start( def_namespace_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Global_Body;

	do
	{
		Code entry = *codes;
		codes++;

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_namespace_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_namespace_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );

	return result;
}

CodeParam def_params( s32 num, ... )
{
	def_body_start( def_params );

	va_list va;
	va_start( va, num );

	Code_POD  pod   = va_arg( va, Code_POD );
	CodeParam param = pcast( CodeParam, pod );

	null_check( def_params, param );

	if ( param->Type != Parameters )
	{
		log_failure( "gen::def_params: param %d is not a Parameters", num - num + 1 );
		return CodeInvalid;
	}

	CodeParam result = (CodeParam)param.duplicate();

	while ( --num )
	{
		pod   = va_arg( va, Code_POD );
		param = pcast( CodeParam, pod );

		if ( param->Type != Parameters )
		{
			log_failure( "gen::def_params: param %d is not a Parameters", num - num + 1 );
			return CodeInvalid;
		}

		result.append( param );
	}
	va_end( va );

	return result;
}

CodeParam def_params( s32 num, CodeParam* codes )
{
	def_body_code_array_start( def_params );

#define check_current()                                                                                         \
	if ( current.ast == nullptr )                                                                               \
	{                                                                                                           \
		log_failure( "gen::def_params: Provide a null code in codes array" );                                   \
		return CodeInvalid;                                                                                     \
	}                                                                                                           \
                                                                                                                \
	if ( current->Type != Parameters )                                                                          \
	{                                                                                                           \
		log_failure( "gen::def_params: Code in coes array is not of paramter type - %s", current.debug_str() ); \
		return CodeInvalid;                                                                                     \
	}

	CodeParam current = (CodeParam)codes->duplicate();
	check_current();

	CodeParam result  = (CodeParam)make_code();
	result->Name      = current->Name;
	result->Type      = current->Type;
	result->ValueType = current->ValueType;

	while ( codes++, current = *codes, num--, num > 0 )
	{
		check_current();
		result.append( current );
	}
#undef check_current

	return result;
}

CodeSpecifiers def_specifiers( s32 num, ... )
{
	if ( num <= 0 )
	{
		log_failure( "gen::def_specifiers: num cannot be zero or less" );
		return CodeInvalid;
	}

	if ( num > AST::ArrSpecs_Cap )
	{
		log_failure( "gen::def_specifiers: num of speciifers to define AST larger than AST specicifier capacity - %d", num );
		return CodeInvalid;
	}

	CodeSpecifiers result = (CodeSpecifiers)make_code();
	result->Type          = ECode::Specifiers;

	va_list va;
	va_start( va, num );
	do
	{
		SpecifierT type = (SpecifierT)va_arg( va, int );

		result.append( type );
	} while ( --num, num );
	va_end( va );

	return result;
}

CodeSpecifiers def_specifiers( s32 num, SpecifierT* specs )
{
	if ( num <= 0 )
	{
		log_failure( "gen::def_specifiers: num cannot be zero or less" );
		return CodeInvalid;
	}

	if ( num > AST::ArrSpecs_Cap )
	{
		log_failure( "gen::def_specifiers: num of speciifers to define AST larger than AST specicifier capacity - %d", num );
		return CodeInvalid;
	}

	CodeSpecifiers result = (CodeSpecifiers)make_code();
	result->Type          = ECode::Specifiers;

	s32 idx               = 0;
	do
	{
		result.append( specs[idx] );
		idx++;
	} while ( --num, num );

	return result;
}

CodeBody def_struct_body( s32 num, ... )
{
	def_body_start( def_struct_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Struct_Body;

	va_list va;
	va_start( va, num );
	do
	{
		Code_POD pod   = va_arg( va, Code_POD );
		Code     entry = pcast( Code, pod );

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_struct_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_STRUCT_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_struct_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );
	va_end( va );

	return result;
}

CodeBody def_struct_body( s32 num, Code* codes )
{
	def_body_code_array_start( def_struct_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Struct_Body;

	do
	{
		Code entry = *codes;
		codes++;

		if ( ! entry )
		{
			log_failure(
			    "gen::"
			    "def_struct_body"
			    ": Provided an null entry"
			);
			return CodeInvalid;
		}

		switch ( entry->Type )
		{
			GEN_AST_BODY_STRUCT_UNALLOWED_TYPES
			log_failure(
			    "gen::"
			    "def_struct_body"
			    ": Entry type is not allowed: %s",
			    entry.debug_str()
			);
			return CodeInvalid;

			default :
				break;
		}

		result.append( entry );
	} while ( num--, num > 0 );

	return result;
}

CodeBody def_union_body( s32 num, ... )
{
	def_body_start( def_union_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Union_Body;

	va_list va;
	va_start( va, num );
	do
	{
		Code_POD pod   = va_arg( va, Code_POD );
		Code     entry = pcast( Code, pod );

		if ( ! entry )
		{
			log_failure( "gen::def_union_body: Provided a null entry" );
			return CodeInvalid;
		}

		if ( entry->Type != Untyped && entry->Type != Comment )
		{
			log_failure( "gen::def_union_body: Entry type is not allowed - %s. Must be of untyped or comment type.", entry.debug_str() );
			return CodeInvalid;
		}

		result.append( entry );
	} while ( num--, num > 0 );
	va_end( va );

	return result;
}

CodeBody def_union_body( s32 num, CodeUnion* codes )
{
	def_body_code_array_start( def_union_body );

	CodeBody result = (CodeBody)make_code();
	result->Type    = Union_Body;

	do
	{
		Code entry = *codes;

		if ( ! entry )
		{
			log_failure( "gen::def_union_body: Provided a null entry" );
			return CodeInvalid;
		}

		if ( entry->Type != Untyped && entry->Type != Comment )
		{
			log_failure( "gen::def_union_body: Entry type is not allowed: %s", entry.debug_str() );
			return CodeInvalid;
		}

		result.append( entry );
	} while ( codes++, num--, num > 0 );

	return (CodeBody)result;
}

#undef name_check
#undef null_check
#undef null_or_invalid_check
#undef def_body_start
#undef def_body_code_array_start

#pragma endregion Upfront

#pragma region Parsing

namespace parser
{
	namespace ETokType
	{
#define GEN_DEFINE_ATTRIBUTE_TOKENS                                                                                 \
	Entry( Attribute_API_Export, "GEN_API_Export_Code" ) Entry( Attribute_API_Import, "GEN_API_Import_Code" )       \
	    Entry( Attribute_COREUOBJECT_API, "COREUOBJECT_API" ) Entry( Attribute_ENGINE_API, "ENGINE_API" )           \
	        Entry( Attribute_GAMEPLAYABILITIES_API, "GAMEPLAYABILITIES_API" ) Entry( Attribute_UMG_API, "UMG_API" ) \
	            Entry( Attribute_UE_DEPRECATED, "UE_DEPRECATED" ) Entry( Attribute_GASA_API, "GASA_API" )

		enum Type : u32
		{
			Invalid,
			Access_Private,
			Access_Protected,
			Access_Public,
			Access_MemberSymbol,
			Access_StaticSymbol,
			Ampersand,
			Ampersand_DBL,
			Assign_Classifer,
			Attribute_Open,
			Attribute_Close,
			BraceCurly_Open,
			BraceCurly_Close,
			BraceSquare_Open,
			BraceSquare_Close,
			Capture_Start,
			Capture_End,
			Comment,
			Comment_End,
			Comment_Start,
			Char,
			Comma,
			Decl_Class,
			Decl_GNU_Attribute,
			Decl_MSVC_Attribute,
			Decl_Enum,
			Decl_Extern_Linkage,
			Decl_Friend,
			Decl_Module,
			Decl_Namespace,
			Decl_Operator,
			Decl_Struct,
			Decl_Template,
			Decl_Typedef,
			Decl_Using,
			Decl_Union,
			Identifier,
			Module_Import,
			Module_Export,
			NewLine,
			Number,
			Operator,
			Preprocess_Hash,
			Preprocess_Define,
			Preprocess_If,
			Preprocess_IfDef,
			Preprocess_IfNotDef,
			Preprocess_ElIf,
			Preprocess_Else,
			Preprocess_EndIf,
			Preprocess_Include,
			Preprocess_Pragma,
			Preprocess_Content,
			Preprocess_Macro,
			Preprocess_Unsupported,
			Spec_Alignas,
			Spec_Const,
			Spec_Consteval,
			Spec_Constexpr,
			Spec_Constinit,
			Spec_Explicit,
			Spec_Extern,
			Spec_Final,
			Spec_ForceInline,
			Spec_Global,
			Spec_Inline,
			Spec_Internal_Linkage,
			Spec_LocalPersist,
			Spec_Mutable,
			Spec_NeverInline,
			Spec_Override,
			Spec_Static,
			Spec_ThreadLocal,
			Spec_Volatile,
			Spec_Virtual,
			Star,
			Statement_End,
			StaticAssert,
			String,
			Type_Typename,
			Type_Unsigned,
			Type_Signed,
			Type_Short,
			Type_Long,
			Type_bool,
			Type_char,
			Type_int,
			Type_double,
			Type_MS_int8,
			Type_MS_int16,
			Type_MS_int32,
			Type_MS_int64,
			Type_MS_W64,
			Varadic_Argument,
			__Attributes_Start,
			Attribute_API_Export,
			Attribute_API_Import,
			Attribute_COREUOBJECT_API,
			Attribute_ENGINE_API,
			Attribute_GAMEPLAYABILITIES_API,
			Attribute_UMG_API,
			Attribute_UE_DEPRECATED,
			Attribute_GASA_API,
			NumTokens
		};

		inline StrC to_str( Type type )
		{
			local_persist StrC lookup[] {
				{ sizeof( "__invalid__" ),           "__invalid__"           },
				{ sizeof( "private" ),               "private"               },
				{ sizeof( "protected" ),             "protected"             },
				{ sizeof( "public" ),                "public"                },
				{ sizeof( "." ),                     "."                     },
				{ sizeof( "::" ),                    "::"                    },
				{ sizeof( "&" ),                     "&"                     },
				{ sizeof( "&&" ),                    "&&"                    },
				{ sizeof( ":" ),                     ":"                     },
				{ sizeof( "[[" ),                    "[["                    },
				{ sizeof( "]]" ),                    "]]"                    },
				{ sizeof( "{" ),                     "{"                     },
				{ sizeof( "}" ),                     "}"                     },
				{ sizeof( "[" ),                     "["                     },
				{ sizeof( "]" ),                     "]"                     },
				{ sizeof( "(" ),                     "("                     },
				{ sizeof( ")" ),                     ")"                     },
				{ sizeof( "__comment__" ),           "__comment__"           },
				{ sizeof( "__comment_end__" ),       "__comment_end__"       },
				{ sizeof( "__comment_start__" ),     "__comment_start__"     },
				{ sizeof( "__character__" ),         "__character__"         },
				{ sizeof( "," ),                     ","                     },
				{ sizeof( "class" ),                 "class"                 },
				{ sizeof( "__attribute__" ),         "__attribute__"         },
				{ sizeof( "__declspec" ),            "__declspec"            },
				{ sizeof( "enum" ),                  "enum"                  },
				{ sizeof( "extern" ),                "extern"                },
				{ sizeof( "friend" ),                "friend"                },
				{ sizeof( "module" ),                "module"                },
				{ sizeof( "namespace" ),             "namespace"             },
				{ sizeof( "operator" ),              "operator"              },
				{ sizeof( "struct" ),                "struct"                },
				{ sizeof( "template" ),              "template"              },
				{ sizeof( "typedef" ),               "typedef"               },
				{ sizeof( "using" ),                 "using"                 },
				{ sizeof( "union" ),                 "union"                 },
				{ sizeof( "__identifier__" ),        "__identifier__"        },
				{ sizeof( "import" ),                "import"                },
				{ sizeof( "export" ),                "export"                },
				{ sizeof( "__new_line__" ),          "__new_line__"          },
				{ sizeof( "__number__" ),            "__number__"            },
				{ sizeof( "__operator__" ),          "__operator__"          },
				{ sizeof( "#" ),                     "#"                     },
				{ sizeof( "define" ),                "define"                },
				{ sizeof( "if" ),                    "if"                    },
				{ sizeof( "ifdef" ),                 "ifdef"                 },
				{ sizeof( "ifndef" ),                "ifndef"                },
				{ sizeof( "elif" ),                  "elif"                  },
				{ sizeof( "else" ),                  "else"                  },
				{ sizeof( "endif" ),                 "endif"                 },
				{ sizeof( "include" ),               "include"               },
				{ sizeof( "pragma" ),                "pragma"                },
				{ sizeof( "__macro_content__" ),     "__macro_content__"     },
				{ sizeof( "__macro__" ),             "__macro__"             },
				{ sizeof( "__unsupported__" ),       "__unsupported__"       },
				{ sizeof( "alignas" ),               "alignas"               },
				{ sizeof( "const" ),                 "const"                 },
				{ sizeof( "consteval" ),             "consteval"             },
				{ sizeof( "constexpr" ),             "constexpr"             },
				{ sizeof( "constinit" ),             "constinit"             },
				{ sizeof( "explicit" ),              "explicit"              },
				{ sizeof( "extern" ),                "extern"                },
				{ sizeof( "final" ),                 "final"                 },
				{ sizeof( "FORCEINLINE" ),           "FORCEINLINE"           },
				{ sizeof( "global" ),                "global"                },
				{ sizeof( "inline" ),                "inline"                },
				{ sizeof( "internal" ),              "internal"              },
				{ sizeof( "local_persist" ),         "local_persist"         },
				{ sizeof( "mutable" ),               "mutable"               },
				{ sizeof( "neverinline" ),           "neverinline"           },
				{ sizeof( "override" ),              "override"              },
				{ sizeof( "static" ),                "static"                },
				{ sizeof( "thread_local" ),          "thread_local"          },
				{ sizeof( "volatile" ),              "volatile"              },
				{ sizeof( "virtual" ),               "virtual"               },
				{ sizeof( "*" ),                     "*"                     },
				{ sizeof( ";" ),                     ";"                     },
				{ sizeof( "static_assert" ),         "static_assert"         },
				{ sizeof( "__string__" ),            "__string__"            },
				{ sizeof( "typename" ),              "typename"              },
				{ sizeof( "unsigned" ),              "unsigned"              },
				{ sizeof( "signed" ),                "signed"                },
				{ sizeof( "short" ),                 "short"                 },
				{ sizeof( "long" ),                  "long"                  },
				{ sizeof( "bool" ),                  "bool"                  },
				{ sizeof( "char" ),                  "char"                  },
				{ sizeof( "int" ),                   "int"                   },
				{ sizeof( "double" ),                "double"                },
				{ sizeof( "__int8" ),                "__int8"                },
				{ sizeof( "__int16" ),               "__int16"               },
				{ sizeof( "__int32" ),               "__int32"               },
				{ sizeof( "__int64" ),               "__int64"               },
				{ sizeof( "_W64" ),                  "_W64"                  },
				{ sizeof( "..." ),                   "..."                   },
				{ sizeof( "__attrib_start__" ),      "__attrib_start__"      },
				{ sizeof( "GEN_API_Export_Code" ),   "GEN_API_Export_Code"   },
				{ sizeof( "GEN_API_Import_Code" ),   "GEN_API_Import_Code"   },
				{ sizeof( "COREUOBJECT_API" ),       "COREUOBJECT_API"       },
				{ sizeof( "ENGINE_API" ),            "ENGINE_API"            },
				{ sizeof( "GAMEPLAYABILITIES_API" ), "GAMEPLAYABILITIES_API" },
				{ sizeof( "UMG_API" ),               "UMG_API"               },
				{ sizeof( "UE_DEPRECATED" ),         "UE_DEPRECATED"         },
				{ sizeof( "GASA_API" ),              "GASA_API"              },
			};
			return lookup[type];
		}

		inline Type to_type( StrC str )
		{
			local_persist u32 keymap[NumTokens];
			do_once_start for ( u32 index = 0; index < NumTokens; index++ )
			{
				StrC enum_str = to_str( (Type)index );
				keymap[index] = crc32( enum_str.Ptr, enum_str.Len - 1 );
			}
			do_once_end u32 hash = crc32( str.Ptr, str.Len );
			for ( u32 index = 0; index < NumTokens; index++ )
			{
				if ( keymap[index] == hash )
					return (Type)index;
			}
			return Invalid;
		}

	}    // namespace ETokType

	using TokType = ETokType::Type;

}    // namespace parser

namespace parser
{

	enum TokFlags : u32
	{
		TF_Operator        = bit( 0 ),
		TF_Assign          = bit( 1 ),
		TF_Preprocess      = bit( 2 ),
		TF_Preprocess_Cond = bit( 3 ),
		TF_Attribute       = bit( 6 ),
		TF_AccessOperator  = bit( 7 ),
		TF_AccessSpecifier = bit( 8 ),
		TF_Specifier       = bit( 9 ),
		TF_EndDefinition   = bit( 10 ),    // Either ; or }
		TF_Formatting      = bit( 11 ),
		TF_Literal         = bit( 12 ),

		TF_Null            = 0,
	};

	struct Token
	{
		char const* Text;
		sptr        Length;
		TokType     Type;
		s32         Line;
		s32         Column;
		u32         Flags;

		operator bool()
		{
			return Text && Length && Type != TokType::Invalid;
		}

		operator StrC()
		{
			return { Length, Text };
		}

		bool is_access_operator()
		{
			return bitfield_is_equal( u32, Flags, TF_AccessOperator );
		}

		bool is_access_specifier()
		{
			return bitfield_is_equal( u32, Flags, TF_AccessSpecifier );
		}

		bool is_attribute()
		{
			return bitfield_is_equal( u32, Flags, TF_Attribute );
		}

		bool is_operator()
		{
			return bitfield_is_equal( u32, Flags, TF_Operator );
		}

		bool is_preprocessor()
		{
			return bitfield_is_equal( u32, Flags, TF_Preprocess );
		}

		bool is_preprocess_cond()
		{
			return bitfield_is_equal( u32, Flags, TF_Preprocess_Cond );
		}

		bool is_specifier()
		{
			return bitfield_is_equal( u32, Flags, TF_Specifier );
		}

		bool is_end_definition()
		{
			return bitfield_is_equal( u32, Flags, TF_EndDefinition );
		}

		AccessSpec to_access_specifier()
		{
			return scast( AccessSpec, Type );
		}

		String to_string()
		{
			String result = String::make_reserve( GlobalAllocator, kilobytes( 4 ) );

			StrC type_str = ETokType::to_str( Type );

			result.append_fmt( "Line: %d Column: %d, Type: %.*s Content: %.*s", Line, Column, type_str.Len, type_str.Ptr, Length, Text );

			return result;
		}
	};

	constexpr Token NullToken { nullptr, 0, TokType::Invalid, false, 0, TF_Null };

	struct TokArray
	{
		Array<Token> Arr;
		s32          Idx;

		bool __eat( TokType type );

		Token& current( bool skip_formatting = true )
		{
			if ( skip_formatting )
			{
				while ( Arr[Idx].Type == TokType::NewLine || Arr[Idx].Type == TokType::Comment )
					Idx++;
			}

			return Arr[Idx];
		}

		Token& previous( bool skip_formatting = false )
		{
			s32 idx = this->Idx;

			if ( skip_formatting )
			{
				while ( Arr[idx].Type == TokType::NewLine )
					idx--;

				return Arr[idx];
			}

			return Arr[idx - 1];
		}

		Token& next( bool skip_formatting = false )
		{
			s32 idx = this->Idx;

			if ( skip_formatting )
			{
				while ( Arr[idx].Type == TokType::NewLine )
					idx++;

				return Arr[idx + 1];
			}

			return Arr[idx + 1];
		}

		Token& operator[]( s32 idx )
		{
			return Arr[idx];
		}
	};

	global Arena_256KB defines_map_arena;
	global HashTable<StrC> defines;
	global Array<Token> Tokens;

#define current ( *scanner )

#define move_forward()         \
	{                          \
		if ( current == '\n' ) \
		{                      \
			line++;            \
			column = 1;        \
		}                      \
		else                   \
		{                      \
			column++;          \
		}                      \
		left--;                \
		scanner++;             \
	}

#define SkipWhitespace()                       \
	while ( left && char_is_space( current ) ) \
	{                                          \
		move_forward();                        \
	}

#define end_line()                          \
	do                                      \
	{                                       \
		while ( left && current == ' ' )    \
		{                                   \
			move_forward();                 \
		}                                   \
		if ( left && current == '\r' )      \
		{                                   \
			move_forward();                 \
			move_forward();                 \
		}                                   \
		else if ( left && current == '\n' ) \
		{                                   \
			move_forward();                 \
		}                                   \
	} while ( 0 )

	enum
	{
		Lex_Continue,
		Lex_ReturnNull,
	};

	FORCEINLINE
	s32 lex_preprocessor_directive( StrC& content, s32& left, char const*& scanner, s32& line, s32& column, HashTable<StrC>& defines, Token& token )
	{
		char const* hash = scanner;
		Tokens.append( { hash, 1, TokType::Preprocess_Hash, line, column, TF_Preprocess } );

		move_forward();
		SkipWhitespace();

		token.Text = scanner;
		while ( left && ! char_is_space( current ) )
		{
			move_forward();
			token.Length++;
		}

		token.Type           = ETokType::to_type( token );

		bool is_preprocessor = token.Type >= TokType::Preprocess_Define && token.Type <= TokType::Preprocess_Pragma;
		if ( ! is_preprocessor )
		{
			token.Type = TokType::Preprocess_Unsupported;

			// Its an unsupported directive, skip it
			s32 within_string = false;
			s32 within_char   = false;
			while ( left )
			{
				if ( current == '"' && ! within_char )
					within_string ^= true;

				if ( current == '\'' && ! within_string )
					within_char ^= true;

				if ( current == '\\' && ! within_string && ! within_char )
				{
					move_forward();
					token.Length++;

					if ( current == '\r' )
					{
						move_forward();
						token.Length++;
					}

					if ( current == '\n' )
					{
						move_forward();
						token.Length++;
						continue;
					}
					else
					{
						log_failure(
						    "gen::Parser::lex: Invalid escape sequence '\\%c' (%d, %d)"
						    " in preprocessor directive (%d, %d)\n%.100s",
						    current,
						    line,
						    column,
						    token.Line,
						    token.Column,
						    token.Text
						);
						break;
					}
				}

				if ( current == '\r' )
				{
					move_forward();
					token.Length++;
				}

				if ( current == '\n' )
				{
					move_forward();
					token.Length++;
					break;
				}

				move_forward();
				token.Length++;
			}

			token.Length = token.Length + token.Text - hash;
			token.Text   = hash;
			Tokens.append( token );
			return Lex_Continue;    // Skip found token, its all handled here.
		}

		if ( token.Type == TokType::Preprocess_Else || token.Type == TokType::Preprocess_EndIf )
		{
			token.Flags |= TF_Preprocess_Cond;
			Tokens.append( token );
			end_line();
			return Lex_Continue;
		}
		else if ( token.Type >= TokType::Preprocess_If && token.Type <= TokType::Preprocess_ElIf )
		{
			token.Flags |= TF_Preprocess_Cond;
		}

		Tokens.append( token );

		SkipWhitespace();

		if ( token.Type == TokType::Preprocess_Define )
		{
			Token name  = { scanner, 0, TokType::Identifier, line, column, TF_Preprocess };

			name.Text   = scanner;
			name.Length = 1;
			move_forward();

			while ( left && ( char_is_alphanumeric( current ) || current == '_' ) )
			{
				move_forward();
				name.Length++;
			}

			if ( left && current == '(' )
			{
				move_forward();
				name.Length++;
			}

			Tokens.append( name );

			u64 key = crc32( name.Text, name.Length );
			defines.set( key, name );
		}

		Token preprocess_content = { scanner, 0, TokType::Preprocess_Content, line, column, TF_Preprocess };

		if ( token.Type == TokType::Preprocess_Include )
		{
			preprocess_content.Type = TokType::String;

			if ( current != '"' && current != '<' )
			{
				String directive_str = String::fmt_buf( GlobalAllocator, "%.*s", min( 80, left + preprocess_content.Length ), token.Text );

				log_failure(
				    "gen::Parser::lex: Expected '\"' or '<' after #include, not '%c' (%d, %d)\n%s",
				    current,
				    preprocess_content.Line,
				    preprocess_content.Column,
				    directive_str.Data
				);
				return Lex_ReturnNull;
			}
			move_forward();
			preprocess_content.Length++;

			while ( left && current != '"' && current != '>' )
			{
				move_forward();
				preprocess_content.Length++;
			}

			move_forward();
			preprocess_content.Length++;

			if ( current == '\r' && scanner[1] == '\n' )
			{
				move_forward();
				move_forward();
			}
			else if ( current == '\n' )
			{
				move_forward();
			}

			Tokens.append( preprocess_content );
			return Lex_Continue;    // Skip found token, its all handled here.
		}

		s32 within_string = false;
		s32 within_char   = false;

		// SkipWhitespace();
		while ( left )
		{
			if ( current == '"' && ! within_char )
				within_string ^= true;

			if ( current == '\'' && ! within_string )
				within_char ^= true;

			if ( current == '\\' && ! within_string && ! within_char )
			{
				move_forward();
				preprocess_content.Length++;

				if ( current == '\r' )
				{
					move_forward();
					preprocess_content.Length++;
				}

				if ( current == '\n' )
				{
					move_forward();
					preprocess_content.Length++;
					continue;
				}
				else
				{
					String directive_str = String::make_length( GlobalAllocator, token.Text, token.Length );
					String content_str   = String::fmt_buf( GlobalAllocator, "%.*s", min( 400, left + preprocess_content.Length ), preprocess_content.Text );

					log_failure(
					    "gen::Parser::lex: Invalid escape sequence '\\%c' (%d, %d)"
					    " in preprocessor directive '%s' (%d, %d)\n%s",
					    current,
					    line,
					    column,
					    directive_str,
					    preprocess_content.Line,
					    preprocess_content.Column,
					    content_str
					);
					break;
				}
			}

			if ( current == '\r' )
			{
				move_forward();
			}

			if ( current == '\n' )
			{
				move_forward();
				break;
			}

			move_forward();
			preprocess_content.Length++;
		}

		Tokens.append( preprocess_content );
		return Lex_Continue;    // Skip found token, its all handled here.
	}

	FORCEINLINE
	void lex_found_token( StrC& content, s32& left, char const*& scanner, s32& line, s32& column, HashTable<StrC>& defines, Token& token )
	{
		if ( token.Type != TokType::Invalid )
		{
			Tokens.append( token );
			return;
		}

		TokType type = ETokType::to_type( token );

		if ( type <= TokType::Access_Public && type >= TokType::Access_Private )
		{
			token.Flags |= TF_AccessSpecifier;
		}

		if ( type > TokType::__Attributes_Start )
		{
			token.Flags |= TF_Attribute;
		}

		if ( type == ETokType::Decl_Extern_Linkage )
		{
			SkipWhitespace();

			if ( current != '"' )
			{
				type         = ETokType::Spec_Extern;
				token.Flags |= TF_Specifier;
			}

			token.Type = type;
			Tokens.append( token );
			return;
		}

		if ( ( type <= TokType::Star && type >= TokType::Spec_Alignas ) || type == TokType::Ampersand || type == TokType::Ampersand_DBL )
		{
			token.Type   = type;
			token.Flags |= TF_Specifier;
			Tokens.append( token );
			return;
		}


		if ( type != TokType::Invalid )
		{
			token.Type = type;
			Tokens.append( token );
			return;
		}

		u64 key = 0;
		if ( current == '(' )
			key = crc32( token.Text, token.Length + 1 );
		else
			key = crc32( token.Text, token.Length );

		StrC* define = defines.get( key );
		if ( define )
		{
			token.Type = TokType::Preprocess_Macro;

			// Want to ignore any arguments the define may have as they can be execution expressions.
			if ( left && current == '(' )
			{
				move_forward();
				token.Length++;

				s32 level = 0;
				while ( left && ( current != ')' || level > 0 ) )
				{
					if ( current == '(' )
						level++;

					else if ( current == ')' && level > 0 )
						level--;

					move_forward();
					token.Length++;
				}

				move_forward();
				token.Length++;
			}

			if ( current == '\r' && scanner[1] == '\n' )
			{
				move_forward();
			}
			else if ( current == '\n' )
			{
				move_forward();
			}
		}
		else
		{
			token.Type = TokType::Identifier;
		}

		Tokens.append( token );
	}

	neverinline
	    // TokArray lex( Array<Token> tokens, StrC content )
	    TokArray
	    lex( StrC content )
	{
		s32         left        = content.Len;
		char const* scanner     = content.Ptr;

		char const* word        = scanner;
		s32         word_length = 0;

		s32 line                = 1;
		s32 column              = 1;

		SkipWhitespace();
		if ( left <= 0 )
		{
			log_failure( "gen::lex: no tokens found (only whitespace provided)" );
			return { { nullptr }, 0 };
		}

		for ( StringCached entry : PreprocessorDefines )
		{
			s32         length  = 0;
			char const* scanner = entry.Data;
			while ( entry.length() > length && ( char_is_alphanumeric( *scanner ) || *scanner == '_' ) )
			{
				scanner++;
				length++;
			}
			if ( scanner[0] == '(' )
			{
				length++;
			}

			u64 key = crc32( entry.Data, length );
			defines.set( key, entry );
		}

		Tokens.clear();

		while ( left )
		{
#if 0
		if (Tokens.num())
		{
			log_fmt("\nLastTok: %S", Tokens.back().to_string());
		}
#endif

			Token token    = { scanner, 0, TokType::Invalid, line, column, TF_Null };

			bool is_define = false;

			if ( column == 1 )
			{
				if ( current == '\r' )
				{
					move_forward();
					token.Length = 1;
				}

				if ( current == '\n' )
				{
					move_forward();

					token.Type = TokType::NewLine;
					token.Length++;

					Tokens.append( token );
					continue;
				}
			}

			token.Length = 0;

			SkipWhitespace();
			if ( left <= 0 )
				break;

			switch ( current )
			{
				case '#' :
				{
					s32 result = lex_preprocessor_directive( content, left, scanner, line, column, defines, token );
					switch ( result )
					{
						case Lex_Continue :
							continue;

						case Lex_ReturnNull :
							return { { nullptr }, 0 };
					}
				}
				case '.' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Access_MemberSymbol;
					token.Flags  = TF_AccessOperator;

					if ( left )
					{
						move_forward();
					}

					if ( current == '.' )
					{
						move_forward();
						if ( current == '.' )
						{
							token.Length = 3;
							token.Type   = TokType::Varadic_Argument;
							token.Flags  = TF_Null;
							move_forward();
						}
						else
						{
							String context_str = String::fmt_buf( GlobalAllocator, "%s", scanner, min( 100, left ) );

							log_failure( "gen::lex: invalid varadic argument, expected '...' got '..%c' (%d, %d)\n%s", current, line, column, context_str );
						}
					}

					goto FoundToken;
				}
				case '&' :
				{
					token.Text    = scanner;
					token.Length  = 1;
					token.Type    = TokType::Ampersand;
					token.Flags  |= TF_Operator;
					token.Flags  |= TF_Specifier;

					if ( left )
						move_forward();

					if ( current == '&' )    // &&
					{
						token.Length = 2;
						token.Type   = TokType::Ampersand_DBL;

						if ( left )
							move_forward();
					}

					goto FoundToken;
				}
				case ':' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Assign_Classifer;
					// Can be either a classifier (ParentType, Bitfield width), or ternary else
					// token.Type   = TokType::Colon;

					if ( left )
						move_forward();

					if ( current == ':' )
					{
						move_forward();
						token.Type = TokType::Access_StaticSymbol;
						token.Length++;
					}
					goto FoundToken;
				}
				case '{' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::BraceCurly_Open;

					if ( left )
						move_forward();
					goto FoundToken;
				}
				case '}' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::BraceCurly_Close;
					token.Flags  = TF_EndDefinition;

					if ( left )
						move_forward();

					end_line();
					goto FoundToken;
				}
				case '[' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::BraceSquare_Open;
					if ( left )
					{
						move_forward();

						if ( current == ']' )
						{
							token.Length = 2;
							token.Type   = TokType::Operator;
							move_forward();
						}
					}
					goto FoundToken;
				}
				case ']' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::BraceSquare_Close;

					if ( left )
						move_forward();
					goto FoundToken;
				}
				case '(' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Capture_Start;

					if ( left )
						move_forward();
					goto FoundToken;
				}
				case ')' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Capture_End;

					if ( left )
						move_forward();
					goto FoundToken;
				}
				case '\'' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Char;
					token.Flags  = TF_Literal;

					move_forward();

					if ( left && current == '\\' )
					{
						move_forward();
						token.Length++;

						if ( current == '\'' )
						{
							move_forward();
							token.Length++;
						}
					}

					while ( left && current != '\'' )
					{
						move_forward();
						token.Length++;
					}

					if ( left )
					{
						move_forward();
						token.Length++;
					}
					goto FoundToken;
				}
				case ',' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Comma;
					token.Flags  = TF_Operator;

					if ( left )
						move_forward();
					goto FoundToken;
				}
				case '*' :
				{
					token.Text    = scanner;
					token.Length  = 1;
					token.Type    = TokType::Star;
					token.Flags  |= TF_Specifier;
					token.Flags  |= TF_Operator;

					if ( left )
						move_forward();

					if ( current == '=' )
					{
						token.Length++;
						token.Flags |= TF_Assign;
						// token.Type = TokType::Assign_Multiply;

						if ( left )
							move_forward();
					}

					goto FoundToken;
				}
				case ';' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Statement_End;
					token.Flags  = TF_EndDefinition;

					if ( left )
						move_forward();

					end_line();
					goto FoundToken;
				}
				case '"' :
				{
					token.Text    = scanner;
					token.Length  = 1;
					token.Type    = TokType::String;
					token.Flags  |= TF_Literal;

					move_forward();
					while ( left )
					{
						if ( current == '"' )
						{
							move_forward();
							break;
						}

						if ( current == '\\' )
						{
							move_forward();
							token.Length++;

							if ( left )
							{
								move_forward();
								token.Length++;
							}
							continue;
						}

						move_forward();
						token.Length++;
					}
					goto FoundToken;
				}
				case '?' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Operator;
					// token.Type     = TokType::Ternary;
					token.Flags = TF_Operator;

					if ( left )
						move_forward();

					goto FoundToken;
				}
				case '=' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Operator;
					// token.Type     = TokType::Assign;
					token.Flags  = TF_Operator;
					token.Flags |= TF_Assign;

					if ( left )
						move_forward();

					if ( current == '=' )
					{
						token.Length++;
						token.Flags = TF_Operator;

						if ( left )
							move_forward();
					}

					goto FoundToken;
				}
				case '+' :
				{
					// token.Type = TokType::Add
				}
				case '%' :
				{
					// token.Type = TokType::Modulo;
				}
				case '^' :
				{
					// token.Type = TokType::B_XOr;
				}
				case '~' :
				{
					// token.Type = TokType::Unary_Not;
				}
				case '!' :
				{
					// token.Type = TokType::L_Not;
				}
				case '<' :
				{
					// token.Type = TokType::Lesser;
				}
				case '>' :
				{
					// token.Type = TokType::Greater;
				}
				case '|' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Operator;
					token.Flags  = TF_Operator;
					// token.Type   = TokType::L_Or;

					if ( left )
						move_forward();

					if ( current == '=' )
					{
						token.Length++;
						token.Flags |= TF_Assign;
						// token.Flags |= TokFlags::Assignment;
						// token.Type = TokType::Assign_L_Or;

						if ( left )
							move_forward();
					}
					else
						while ( left && current == *( scanner - 1 ) && token.Length < 3 )
						{
							token.Length++;

							if ( left )
								move_forward();
						}
					goto FoundToken;
				}

				// Dash is unfortunatlly a bit more complicated...
				case '-' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Operator;
					// token.Type = TokType::Subtract;
					token.Flags = TF_Operator;
					if ( left )
					{
						move_forward();

						if ( current == '>' )
						{
							token.Length++;
							//						token.Type = TokType::Access_PointerToMemberSymbol;
							token.Flags |= TF_AccessOperator;
							move_forward();

							if ( current == '*' )
							{
								//							token.Type = TokType::Access_PointerToMemberOfPointerSymbol;
								token.Length++;
								move_forward();
							}
						}
						else if ( current == '=' )
						{
							token.Length++;
							// token.Type = TokType::Assign_Subtract;
							token.Flags |= TF_Assign;

							if ( left )
								move_forward();
						}
						else
							while ( left && current == *( scanner - 1 ) && token.Length < 3 )
							{
								token.Length++;

								if ( left )
									move_forward();
							}
					}
					goto FoundToken;
				}
				case '/' :
				{
					token.Text   = scanner;
					token.Length = 1;
					token.Type   = TokType::Operator;
					// token.Type   = TokType::Divide;
					token.Flags = TF_Operator;
					move_forward();

					if ( left )
					{
						if ( current == '=' )
						{
							// token.Type = TokeType::Assign_Divide;
							move_forward();
							token.Length++;
							token.Flags = TF_Assign;
						}
						else if ( current == '/' )
						{
							token.Type   = TokType::Comment;
							token.Length = 2;
							token.Flags  = TF_Null;
							move_forward();

							while ( left && current != '\n' && current != '\r' )
							{
								move_forward();
								token.Length++;
							}

							if ( current == '\r' )
							{
								move_forward();
								token.Length++;
							}
							if ( current == '\n' )
							{
								move_forward();
								token.Length++;
							}
							Tokens.append( token );
							continue;
						}
						else if ( current == '*' )
						{
							token.Type   = TokType::Comment;
							token.Length = 2;
							token.Flags  = TF_Null;
							move_forward();

							bool star   = current == '*';
							bool slash  = scanner[1] == '/';
							bool at_end = star && slash;
							while ( left && ! at_end )
							{
								move_forward();
								token.Length++;

								star   = current == '*';
								slash  = scanner[1] == '/';
								at_end = star && slash;
							}
							token.Length += 2;
							move_forward();
							move_forward();

							if ( current == '\r' )
							{
								move_forward();
								token.Length++;
							}
							if ( current == '\n' )
							{
								move_forward();
								token.Length++;
							}
							Tokens.append( token );
							// end_line();
							continue;
						}
					}
					goto FoundToken;
				}
			}

			if ( char_is_alpha( current ) || current == '_' )
			{
				token.Text   = scanner;
				token.Length = 1;
				move_forward();

				while ( left && ( char_is_alphanumeric( current ) || current == '_' ) )
				{
					move_forward();
					token.Length++;
				}

				goto FoundToken;
			}
			else if ( char_is_digit( current ) )
			{
				// This is a very brute force lex, no checks are done for validity of literal.

				token.Text   = scanner;
				token.Length = 1;
				token.Type   = TokType::Number;
				token.Flags  = TF_Literal;
				move_forward();

				if ( left && ( current == 'x' || current == 'X' || current == 'b' || current == 'B' || current == 'o' || current == 'O' ) )
				{
					move_forward();
					token.Length++;

					while ( left && char_is_hex_digit( current ) )
					{
						move_forward();
						token.Length++;
					}

					goto FoundToken;
				}

				while ( left && char_is_digit( current ) )
				{
					move_forward();
					token.Length++;
				}

				if ( left && current == '.' )
				{
					move_forward();
					token.Length++;

					while ( left && char_is_digit( current ) )
					{
						move_forward();
						token.Length++;
					}

					// Handle number literal suffixes in a botched way
					if ( left
					     && ( current == 'l' || current == 'L' ||     // long/long long
					          current == 'u' || current == 'U' ||     // unsigned
					          current == 'f' || current == 'F' ||     // float
					          current == 'i' || current == 'I' ||     // imaginary
					          current == 'z' || current == 'Z' ) )    // complex
					{
						char prev = current;
						move_forward();
						token.Length++;

						// Handle 'll'/'LL' as a special case when we just processed an 'l'/'L'
						if ( left && ( prev == 'l' || prev == 'L' ) && ( current == 'l' || current == 'L' ) )
						{
							move_forward();
							token.Length++;
						}
					}
				}

				goto FoundToken;
			}
			else
			{
				s32 start = max( 0, Tokens.num() - 100 );
				log_fmt( "\n%d\n", start );
				for ( s32 idx = start; idx < Tokens.num(); idx++ )
				{
					log_fmt( "Token %d Type: %s : %.*s\n", idx, ETokType::to_str( Tokens[idx].Type ).Ptr, Tokens[idx].Length, Tokens[idx].Text );
				}

				String context_str = String::fmt_buf( GlobalAllocator, "%.*s", min( 100, left ), scanner );
				log_failure( "Failed to lex token '%c' (%d, %d)\n%s", current, line, column, context_str );

				// Skip to next whitespace since we can't know if anything else is valid until then.
				while ( left && ! char_is_space( current ) )
				{
					move_forward();
				}
			}

		FoundToken:
			lex_found_token( content, left, scanner, line, column, defines, token );
		}

		if ( Tokens.num() == 0 )
		{
			log_failure( "Failed to lex any tokens" );
			return { { nullptr }, 0 };
		}

		defines.clear();
		// defines_map_arena.free();
		return { Tokens, 0 };
	}

#undef current
#undef move_forward
#undef SkipWhitespace

	// namespace parser
}    // namespace parser

namespace parser
{

	// TODO(Ed) : Rename ETokType::Capture_Start, ETokType::Capture_End to Open_Parenthesis adn Close_Parenthesis

	constexpr bool dont_skip_formatting = false;

	struct StackNode
	{
		StackNode* Prev;

		Token Start;
		Token Name;        // The name of the AST node (if parsed)
		StrC  ProcName;    // The name of the procedure
	};

	struct ParseContext
	{
		TokArray   Tokens;
		StackNode* Scope;

		void push( StackNode* node )
		{
			node->Prev = Scope;
			Scope      = node;

#if 0 && Build_Debug
		log_fmt("\tEntering Context: %.*s\n", Scope->ProcName.Len, Scope->ProcName.Ptr );
#endif
		}

		void pop()
		{
#if 0 && Build_Debug
		log_fmt("\tPopping  Context: %.*s\n", Scope->ProcName.Len, Scope->ProcName.Ptr );
#endif
			Scope = Scope->Prev;
		}

		String to_string()
		{
			String result       = String::make_reserve( GlobalAllocator, kilobytes( 4 ) );

			Token scope_start   = Scope->Start;
			Token last_valid    = Tokens.Idx >= Tokens.Arr.num() ? Tokens.Arr[Tokens.Arr.num() - 1] : Tokens.current();

			sptr        length  = scope_start.Length;
			char const* current = scope_start.Text + length;
			while ( current <= Tokens.Arr.back().Text && *current != '\n' && length < 74 )
			{
				current++;
				length++;
			}

			String line = String::make( GlobalAllocator, { length, scope_start.Text } );
			result.append_fmt( "\tScope    : %s\n", line );
			line.free();

			sptr   dist            = (sptr)last_valid.Text - (sptr)scope_start.Text + 2;
			sptr   length_from_err = dist;
			String line_from_err   = String::make( GlobalAllocator, { length_from_err, last_valid.Text } );

			if ( length_from_err < 100 )
				result.append_fmt( "\t(%d, %d):%*c\n", last_valid.Line, last_valid.Column, length_from_err, '^' );
			else
				result.append_fmt( "\t(%d, %d)\n", last_valid.Line, last_valid.Column );

			StackNode* curr_scope = Scope;
			s32        level      = 0;
			do
			{
				if ( curr_scope->Name )
				{
					result.append_fmt( "\t%d: %s, AST Name: %.*s\n", level, curr_scope->ProcName.Ptr, curr_scope->Name.Length, curr_scope->Name.Text );
				}
				else
				{
					result.append_fmt( "\t%d: %s\n", level, curr_scope->ProcName.Ptr );
				}

				curr_scope = curr_scope->Prev;
				level++;
			} while ( curr_scope );
			return result;
		}
	};

	global ParseContext Context;

	bool TokArray::__eat( TokType type )
	{
		if ( Arr.num() - Idx <= 0 )
		{
			log_failure( "No tokens left.\n%s", Context.to_string() );
			return false;
		}

		if ( ( Arr[Idx].Type == TokType::NewLine && type != TokType::NewLine ) || ( Arr[Idx].Type == TokType::Comment && type != TokType::Comment ) )
		{
			Idx++;
		}

		if ( Arr[Idx].Type != type )
		{
			log_failure(
			    "Parse Error, TokArray::eat, Expected: ' %s ' not ' %.*s ' (%d, %d)`\n%s",
			    ETokType::to_str( type ).Ptr,
			    Arr[Idx].Length,
			    Arr[Idx].Text,
			    current().Line,
			    current().Column,
			    Context.to_string()
			);

			return false;
		}

#if 0 && Build_Debug
	log_fmt("Ate: %S\n", Arr[Idx].to_string() );
#endif

		Idx++;
		return true;
	}

	internal void init()
	{
		Tokens            = Array<Token>::init_reserve( LexArena, ( LexAllocator_Size - sizeof( Array<Token>::Header ) ) / sizeof( Token ) );

		defines_map_arena = Arena_256KB::init();
		defines           = HashTable<StrC>::init_reserve( defines_map_arena, 256 );
	}

	internal void deinit()
	{
		parser::Tokens = { nullptr };
	}

#pragma region Helper Macros

#define check_parse_args( def )                                                      \
	if ( def.Len <= 0 )                                                              \
	{                                                                                \
		log_failure( "gen::" stringize( __func__ ) ": length must greater than 0" ); \
		parser::Context.pop();                                                       \
		return CodeInvalid;                                                          \
	}                                                                                \
	if ( def.Ptr == nullptr )                                                        \
	{                                                                                \
		log_failure( "gen::" stringize( __func__ ) ": def was null" );               \
		parser::Context.pop();                                                       \
		return CodeInvalid;                                                          \
	}

#define currtok_noskip        Context.Tokens.current( dont_skip_formatting )
#define currtok               Context.Tokens.current()
#define prevtok               Context.Tokens.previous()
#define nexttok               Context.Tokens.next()
#define eat( Type_ )          Context.Tokens.__eat( Type_ )
#define left                  ( Context.Tokens.Arr.num() - Context.Tokens.Idx )

#define check_noskip( Type_ ) ( left && currtok_noskip.Type == Type_ )
#define check( Type_ )        ( left && currtok.Type == Type_ )

#define push_scope()                                                         \
	StackNode scope { nullptr, currtok_noskip, NullToken, txt( __func__ ) }; \
	Context.push( &scope )

#pragma endregion Helper Macros

	// Procedure Forwards ( Entire parser internal parser interface )

	internal Code           parse_array_decl();
	internal CodeAttributes parse_attributes();
	internal CodeComment    parse_comment();
	internal Code           parse_complicated_definition( TokType which );
	internal CodeBody       parse_class_struct_body( TokType which, Token name = NullToken );
	internal Code           parse_class_struct( TokType which, bool inplace_def );
	internal CodeDefine     parse_define();
	internal Code           parse_expression();
	internal Code           parse_forward_or_definition( TokType which, bool is_inplace );
	internal CodeFn         parse_function_after_name( ModuleFlag mflags, CodeAttributes attributes, CodeSpecifiers specifiers, CodeType ret_type, Token name );
	internal Code           parse_function_body();
	internal Code           parse_global_nspace();
	internal Code           parse_global_nspace_constructor_destructor( CodeSpecifiers specifiers );
	internal Token          parse_identifier( bool* possible_member_function = nullptr );
	internal CodeInclude    parse_include();
	internal CodeOperator   parse_operator_after_ret_type( ModuleFlag mflags, CodeAttributes attributes, CodeSpecifiers specifiers, CodeType ret_type );
	internal Code           parse_operator_function_or_variable( bool expects_function, CodeAttributes attributes, CodeSpecifiers specifiers );
	internal CodePragma     parse_pragma();
	internal CodeParam      parse_params( bool use_template_capture = false );
	internal CodePreprocessCond parse_preprocess_cond();
	internal Code               parse_simple_preprocess( TokType which );
	internal Code               parse_static_assert();
	internal void               parse_template_args( Token& token );
	internal CodeVar            parse_variable_after_name( ModuleFlag mflags, CodeAttributes attributes, CodeSpecifiers specifiers, CodeType type, StrC name );
	internal CodeVar            parse_variable_declaration_list();

	internal CodeClass       parse_class( bool inplace_def = false );
	internal CodeConstructor parse_constructor( CodeSpecifiers specifiers );
	internal CodeDestructor  parse_destructor( CodeSpecifiers specifiers = NoCode );
	internal CodeEnum        parse_enum( bool inplace_def = false );
	internal CodeBody        parse_export_body();
	internal CodeBody        parse_extern_link_body();
	internal CodeExtern      parse_extern_link();
	internal CodeFriend      parse_friend();
	internal CodeFn          parse_function();
	internal CodeNS          parse_namespace();
	internal CodeOpCast      parse_operator_cast( CodeSpecifiers specifiers = NoCode );
	internal CodeStruct      parse_struct( bool inplace_def = false );
	internal CodeVar         parse_variable();
	internal CodeTemplate    parse_template();
	internal CodeType        parse_type( bool from_template = false, bool* is_function = nullptr );
	internal CodeTypedef     parse_typedef();
	internal CodeUnion       parse_union( bool inplace_def = false );
	internal CodeUsing       parse_using();

	constexpr bool inplace_def = true;

	// Internal parsing functions

	constexpr bool strip_formatting_dont_preserve_newlines = false;

	/*
	    This function was an attempt at stripping formatting from any c++ code.
	    It has edge case failures that prevent it from being used in function bodies.
	*/
	internal String strip_formatting( StrC raw_text, bool preserve_newlines = true )
	{
		String content = String::make_reserve( GlobalAllocator, raw_text.Len );

		if ( raw_text.Len == 0 )
			return content;

#define cut_length ( scanner - raw_text.Ptr - last_cut )
#define cut_ptr    ( raw_text.Ptr + last_cut )
#define pos        ( sptr( scanner ) - sptr( raw_text.Ptr ) )
#define move_fwd() \
	do             \
	{              \
		scanner++; \
		tokleft--; \
	} while ( 0 )

		s32         tokleft  = raw_text.Len;
		sptr        last_cut = 0;
		char const* scanner  = raw_text.Ptr;

		if ( scanner[0] == ' ' )
		{
			move_fwd();
			last_cut = 1;
		}

		bool within_string     = false;
		bool within_char       = false;
		bool must_keep_newline = false;
		while ( tokleft )
		{
			// Skip over the content of string literals
			if ( scanner[0] == '"' )
			{
				move_fwd();

				while ( tokleft && ( scanner[0] != '"' || *( scanner - 1 ) == '\\' ) )
				{
					if ( scanner[0] == '\\' && tokleft > 1 )
					{
						scanner += 2;
						tokleft -= 2;
					}
					else
					{
						move_fwd();
					}
				}

				// Skip the closing "
				if ( tokleft )
					move_fwd();

				content.append( cut_ptr, cut_length );
				last_cut = sptr( scanner ) - sptr( raw_text.Ptr );
				continue;
			}

			// Skip over the content of character literals
			if ( scanner[0] == '\'' )
			{
				move_fwd();

				while ( tokleft && ( scanner[0] != '\'' || ( *( scanner - 1 ) == '\\' ) ) )
				{
					move_fwd();
				}

				// Skip the closing '
				if ( tokleft )
					move_fwd();

				content.append( cut_ptr, cut_length );
				last_cut = sptr( scanner ) - sptr( raw_text.Ptr );
				continue;
			}

			// Block comments
			if ( tokleft > 1 && scanner[0] == '/' && scanner[1] == '*' )
			{
				while ( tokleft > 1 && ! ( scanner[0] == '*' && scanner[1] == '/' ) )
					move_fwd();

				scanner += 2;
				tokleft -= 2;

				content.append( cut_ptr, cut_length );
				last_cut = sptr( scanner ) - sptr( raw_text.Ptr );
				continue;
			}

			// Line comments
			if ( tokleft > 1 && scanner[0] == '/' && scanner[1] == '/' )
			{
				must_keep_newline  = true;

				scanner           += 2;
				tokleft           -= 2;

				while ( tokleft && scanner[0] != '\n' )
					move_fwd();

				if ( tokleft )
					move_fwd();

				content.append( cut_ptr, cut_length );
				last_cut = sptr( scanner ) - sptr( raw_text.Ptr );
				continue;
			}

			// Tabs
			if ( scanner[0] == '\t' )
			{
				if ( pos > last_cut )
					content.append( cut_ptr, cut_length );

				if ( content.back() != ' ' )
					content.append( ' ' );

				move_fwd();
				last_cut = sptr( scanner ) - sptr( raw_text.Ptr );
				continue;
			}

			if ( tokleft > 1 && scanner[0] == '\r' && scanner[1] == '\n' )
			{
				if ( must_keep_newline || preserve_newlines )
				{
					must_keep_newline  = false;

					scanner           += 2;
					tokleft           -= 2;

					content.append( cut_ptr, cut_length );
					last_cut = sptr( scanner ) - sptr( raw_text.Ptr );
					continue;
				}

				if ( pos > last_cut )
					content.append( cut_ptr, cut_length );

				// Replace with a space
				if ( content.back() != ' ' )
					content.append( ' ' );

				scanner  += 2;
				tokleft  -= 2;

				last_cut  = sptr( scanner ) - sptr( raw_text.Ptr );
				continue;
			}

			if ( scanner[0] == '\n' )
			{
				if ( must_keep_newline || preserve_newlines )
				{
					must_keep_newline = false;

					move_fwd();

					content.append( cut_ptr, cut_length );
					last_cut = sptr( scanner ) - sptr( raw_text.Ptr );
					continue;
				}

				if ( pos > last_cut )
					content.append( cut_ptr, cut_length );

				// Replace with a space
				if ( content.back() != ' ' )
					content.append( ' ' );

				move_fwd();

				last_cut = sptr( scanner ) - sptr( raw_text.Ptr );
				continue;
			}

			// Escaped newlines
			if ( scanner[0] == '\\' )
			{
				content.append( cut_ptr, cut_length );

				s32 amount_to_skip = 1;
				if ( tokleft > 1 && scanner[1] == '\n' )
				{
					amount_to_skip = 2;
				}
				else if ( tokleft > 2 && scanner[1] == '\r' && scanner[2] == '\n' )
				{
					amount_to_skip = 3;
				}

				if ( amount_to_skip > 1 && pos == last_cut )
				{
					scanner += amount_to_skip;
					tokleft -= amount_to_skip;
				}
				else
					move_fwd();

				last_cut = sptr( scanner ) - sptr( raw_text.Ptr );
				continue;
			}

			// Consectuive spaces
			if ( tokleft > 1 && char_is_space( scanner[0] ) && char_is_space( scanner[1] ) )
			{
				content.append( cut_ptr, cut_length );
				do
				{
					move_fwd();
				} while ( tokleft && char_is_space( scanner[0] ) );

				last_cut = sptr( scanner ) - sptr( raw_text.Ptr );

				// Preserve only 1 space of formattting
				if ( content.back() != ' ' )
					content.append( ' ' );

				continue;
			}

			move_fwd();
		}

		if ( last_cut < raw_text.Len )
		{
			content.append( cut_ptr, raw_text.Len - last_cut );
		}

#undef cut_ptr
#undef cut_length
#undef pos
#undef move_fwd

		return content;
	}

	internal Code parse_array_decl()
	{
		push_scope();

		if ( check( TokType::Operator ) && currtok.Text[0] == '[' && currtok.Text[1] == ']' )
		{
			Code array_expr = untyped_str( currtok );
			eat( TokType::Operator );
			// []

			Context.pop();
			return array_expr;
		}

		if ( check( TokType::BraceSquare_Open ) )
		{
			eat( TokType::BraceSquare_Open );
			// [

			if ( left == 0 )
			{
				log_failure( "Error, unexpected end of array declaration ( '[]' scope started )\n%s", Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			if ( currtok.Type == TokType::BraceSquare_Close )
			{
				log_failure( "Error, empty array expression in definition\n%s", Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			Token untyped_tok = currtok;

			while ( left && currtok.Type != TokType::BraceSquare_Close )
			{
				eat( currtok.Type );
			}

			untyped_tok.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)untyped_tok.Text;

			Code array_expr    = untyped_str( untyped_tok );
			// [ <Content>

			if ( left == 0 )
			{
				log_failure( "Error, unexpected end of array declaration, expected ]\n%s", Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			if ( currtok.Type != TokType::BraceSquare_Close )
			{
				log_failure( "%s: Error, expected ] in array declaration, not %s\n%s", ETokType::to_str( currtok.Type ), Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			eat( TokType::BraceSquare_Close );
			// [ <Content> ]

			// Its a multi-dimensional array
			if ( check( TokType::BraceSquare_Open ) )
			{
				Code adjacent_arr_expr = parse_array_decl();
				// [ <Content> ][ <Content> ]...

				array_expr->Next = adjacent_arr_expr.ast;
			}

			Context.pop();
			return array_expr;
		}

		Context.pop();
		return { nullptr };
	}

	internal inline CodeAttributes parse_attributes()
	{
		push_scope();

		Token start = currtok;
		s32   len   = 0;

		// There can be more than one attribute. If there is flatten them to a single string.
		// TODO(Ed): Support keeping an linked list of attributes similar to parameters
		while ( left && currtok.is_attribute() )
		{
			if ( check( TokType::Attribute_Open ) )
			{
				eat( TokType::Attribute_Open );
				// [[

				while ( left && currtok.Type != TokType::Attribute_Close )
				{
					eat( currtok.Type );
				}
				// [[ <Content>

				eat( TokType::Attribute_Close );
				// [[ <Content> ]]

				len = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)start.Text;
			}
			else if ( check( TokType::Decl_GNU_Attribute ) )
			{
				eat( TokType::Decl_GNU_Attribute );
				eat( TokType::Capture_Start );
				eat( TokType::Capture_Start );
				// __attribute__((

				while ( left && currtok.Type != TokType::Capture_End )
				{
					eat( currtok.Type );
				}
				// __attribute__(( <Content>

				eat( TokType::Capture_End );
				eat( TokType::Capture_End );
				// __attribute__(( <Content> ))

				len = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)start.Text;
			}
			else if ( check( TokType::Decl_MSVC_Attribute ) )
			{
				eat( TokType::Decl_MSVC_Attribute );
				eat( TokType::Capture_Start );
				// __declspec(

				while ( left && currtok.Type != TokType::Capture_End )
				{
					eat( currtok.Type );
				}
				// __declspec( <Content>

				eat( TokType::Capture_End );
				// __declspec( <Content> )

				len = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)start.Text;
			}
			else if ( currtok.is_attribute() )
			{
				eat( currtok.Type );
				// <Attribute>

				// If its a macro based attribute, this could be a functional macro such as Unreal's UE_DEPRECATED(...)
				if ( check( TokType::Capture_Start ) )
				{
					eat( TokType::Capture_Start );

					s32 level = 0;
					while ( left && currtok.Type != TokType::Capture_End && level == 0 )
					{
						if ( currtok.Type == TokType::Capture_Start )
							++level;
						if ( currtok.Type == TokType::Capture_End )
							--level;
						eat( currtok.Type );
					}
					eat( TokType::Capture_End );
				}

				len = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)start.Text;
				// <Attribute> ( ... )
			}
		}

		if ( len > 0 )
		{
			StrC attribute_txt = { len, start.Text };
			Context.pop();

			String name_stripped = strip_formatting( attribute_txt, strip_formatting_dont_preserve_newlines );

			Code result          = make_code();
			result->Type         = ECode::PlatformAttributes;
			result->Name         = get_cached_string( name_stripped );
			result->Content      = result->Name;
			// result->Token   =

			return (CodeAttributes)result;
		}

		Context.pop();
		return { nullptr };
	}

	internal Code parse_class_struct( TokType which, bool inplace_def = false )
	{
		if ( which != TokType::Decl_Class && which != TokType::Decl_Struct )
		{
			log_failure( "Error, expected class or struct, not %s\n%s", ETokType::to_str( which ), Context.to_string() );
			return CodeInvalid;
		}

		Token name { nullptr, 0, TokType::Invalid };

		AccessSpec     access     = AccessSpec::Default;
		CodeType       parent     = { nullptr };
		CodeBody       body       = { nullptr };
		CodeAttributes attributes = { nullptr };
		ModuleFlag     mflags     = ModuleFlag::None;

		CodeClass result          = CodeInvalid;

		if ( check( TokType::Module_Export ) )
		{
			mflags = ModuleFlag::Export;
			eat( TokType::Module_Export );
		}
		// <ModuleFlags>

		eat( which );
		// <ModuleFlags> <class/struct>

		attributes = parse_attributes();
		// <ModuleFlags> <class/struct> <Attributes>

		if ( check( TokType::Identifier ) )
		{
			name                = parse_identifier();
			Context.Scope->Name = name;
		}
		// <ModuleFlags> <class/struct> <Attributes> <Name>

		local_persist char interface_arr_mem[kilobytes( 4 )] { 0 };
		Array<CodeType>    interfaces = Array<CodeType>::init_reserve( Arena::init_from_memory( interface_arr_mem, kilobytes( 4 ) ), 4 );

		// TODO(Ed) : Make an AST_DerivedType, we'll store any arbitary derived type into there as a linear linked list of them.
		if ( check( TokType::Assign_Classifer ) )
		{
			eat( TokType::Assign_Classifer );
			// <ModuleFlags> <class/struct> <Attributes> <Name> :

			if ( currtok.is_access_specifier() )
			{
				access = currtok.to_access_specifier();
				// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier>
				eat( currtok.Type );
			}

			Token parent_tok = parse_identifier();
			parent           = def_type( parent_tok );
			// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Parent/Interface Name>

			while ( check( TokType::Comma ) )
			{
				eat( TokType::Comma );
				// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Name>,

				if ( currtok.is_access_specifier() )
				{
					eat( currtok.Type );
				}
				Token interface_tok = parse_identifier();

				interfaces.append( def_type( interface_tok ) );
				// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Name>, ...
			}
		}

		if ( check( TokType::BraceCurly_Open ) )
		{
			body = parse_class_struct_body( which, name );
		}
		// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Name>, ... { <Body> }

		CodeComment inline_cmt = NoCode;
		if ( ! inplace_def )
		{
			Token stmt_end = currtok;
			eat( TokType::Statement_End );
			// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Name>, ... { <Body> };

			if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
				inline_cmt = parse_comment();
			// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Name>, ... { <Body> }; <InlineCmt>
		}

		if ( which == TokType::Decl_Class )
			result = def_class( name, body, parent, access, attributes, mflags );

		else
			result = def_struct( name, body, (CodeType)parent, access, attributes, mflags );

		if ( inline_cmt )
			result->InlineCmt = inline_cmt;

		interfaces.free();
		return result;
	}

	internal neverinline CodeBody parse_class_struct_body( TokType which, Token name )
	{
		using namespace ECode;
		push_scope();

		eat( TokType::BraceCurly_Open );
		// {

		CodeBody result = (CodeBody)make_code();

		if ( which == TokType::Decl_Class )
			result->Type = Class_Body;

		else
			result->Type = Struct_Body;

		while ( left && currtok_noskip.Type != TokType::BraceCurly_Close )
		{
			Code           member     = Code::Invalid;
			CodeAttributes attributes = { nullptr };
			CodeSpecifiers specifiers = { nullptr };

			bool expects_function     = false;

			// Context.Scope->Start = currtok_noskip;

			if ( currtok_noskip.Type == TokType::Preprocess_Hash )
				eat( TokType::Preprocess_Hash );

			switch ( currtok_noskip.Type )
			{
				case TokType::Statement_End :
				{
					// TODO(Ed): Convert this to a general warning procedure
					log_fmt( "Dangling end statement found %S\n", currtok_noskip.to_string() );
					eat( TokType::Statement_End );
					continue;
				}
				case TokType::NewLine :
					member = fmt_newline;
					eat( TokType::NewLine );
					break;

				case TokType::Comment :
					member = parse_comment();
					break;

				case TokType::Access_Public :
					member = access_public;
					eat( TokType::Access_Public );
					eat( TokType::Assign_Classifer );
					// public:
					break;

				case TokType::Access_Protected :
					member = access_protected;
					eat( TokType::Access_Protected );
					eat( TokType::Assign_Classifer );
					// protected:
					break;

				case TokType::Access_Private :
					member = access_private;
					eat( TokType::Access_Private );
					eat( TokType::Assign_Classifer );
					// private:
					break;

				case TokType::Decl_Class :
					member = parse_complicated_definition( TokType::Decl_Class );
					// class
					break;

				case TokType::Decl_Enum :
					member = parse_complicated_definition( TokType::Decl_Enum );
					// enum
					break;

				case TokType::Decl_Friend :
					member = parse_friend();
					// friend
					break;

				case TokType::Decl_Operator :
					member = parse_operator_cast();
					// operator <Type>()
					break;

				case TokType::Decl_Struct :
					member = parse_complicated_definition( TokType::Decl_Struct );
					// struct
					break;

				case TokType::Decl_Template :
					member = parse_template();
					// template< ... >
					break;

				case TokType::Decl_Typedef :
					member = parse_typedef();
					// typedef
					break;

				case TokType::Decl_Union :
					member = parse_complicated_definition( TokType::Decl_Union );
					// union
					break;

				case TokType::Decl_Using :
					member = parse_using();
					// using
					break;

				case TokType::Operator :
					if ( currtok.Text[0] != '~' )
					{
						log_failure( "Operator token found in global body but not destructor unary negation\n%s", Context.to_string() );
						return CodeInvalid;
					}

					member = parse_destructor();
					// ~<Name>()
					break;

				case TokType::Preprocess_Define :
					member = parse_define();
					// #define
					break;

				case TokType::Preprocess_Include :
					member = parse_include();
					// #include
					break;

				case TokType::Preprocess_If :
				case TokType::Preprocess_IfDef :
				case TokType::Preprocess_IfNotDef :
				case TokType::Preprocess_ElIf :
					member = parse_preprocess_cond();
					// #<Condition>
					break;

				case TokType::Preprocess_Else :
					member = preprocess_else;
					eat( TokType::Preprocess_Else );
					// #else
					break;

				case TokType::Preprocess_EndIf :
					member = preprocess_endif;
					eat( TokType::Preprocess_EndIf );
					// #endif
					break;

				case TokType::Preprocess_Macro :
					member = parse_simple_preprocess( TokType::Preprocess_Macro );
					// <Macro>
					break;

				case TokType::Preprocess_Pragma :
					member = parse_pragma();
					// #pragma
					break;

				case TokType::Preprocess_Unsupported :
					member = parse_simple_preprocess( TokType::Preprocess_Unsupported );
					// #<UNKNOWN>
					break;

				case TokType::StaticAssert :
					member = parse_static_assert();
					// static_assert
					break;

				case TokType::Attribute_Open :
				case TokType::Decl_GNU_Attribute :
				case TokType::Decl_MSVC_Attribute :
#define Entry( attribute, str ) case TokType::attribute :
					GEN_DEFINE_ATTRIBUTE_TOKENS
#undef Entry
					{
						attributes = parse_attributes();
						// <Attributes>
					}
				//! Fallthrough intended
				case TokType::Spec_Consteval :
				case TokType::Spec_Constexpr :
				case TokType::Spec_Constinit :
				case TokType::Spec_Explicit :
				case TokType::Spec_ForceInline :
				case TokType::Spec_Inline :
				case TokType::Spec_Mutable :
				case TokType::Spec_NeverInline :
				case TokType::Spec_Static :
				case TokType::Spec_Volatile :
				case TokType::Spec_Virtual :
				{
					SpecifierT specs_found[16] { ESpecifier::NumSpecifiers };
					s32        NumSpecifiers = 0;

					while ( left && currtok.is_specifier() )
					{
						SpecifierT spec = ESpecifier::to_type( currtok );

						b32 ignore_spec = false;

						switch ( spec )
						{
							case ESpecifier::Constexpr :
							case ESpecifier::Constinit :
							case ESpecifier::Explicit :
							case ESpecifier::Inline :
							case ESpecifier::ForceInline :
							case ESpecifier::Mutable :
							case ESpecifier::NeverInline :
							case ESpecifier::Static :
							case ESpecifier::Volatile :
							case ESpecifier::Virtual :
								break;

							case ESpecifier::Consteval :
								expects_function = true;
								break;

							case ESpecifier::Const :
								ignore_spec = true;
								break;

							default :
								log_failure( "Invalid specifier %s for variable\n%s", ESpecifier::to_str( spec ), Context.to_string() );
								Context.pop();
								return CodeInvalid;
						}

						// Every specifier after would be considered part of the type type signature
						if ( ignore_spec )
							break;

						specs_found[NumSpecifiers] = spec;
						NumSpecifiers++;
						eat( currtok.Type );
					}

					if ( NumSpecifiers )
					{
						specifiers = def_specifiers( NumSpecifiers, specs_found );
					}
					// <Attributes> <Specifiers>

					if ( currtok.is_attribute() )
					{
						// Unfortuantely Unreal has code where there is attirbutes before specifiers
						CodeAttributes more_attributes = parse_attributes();

						if ( attributes )
						{
							String fused = String::make_reserve( GlobalAllocator, attributes->Content.length() + more_attributes->Content.length() );
							fused.append_fmt( "%S %S", attributes->Content, more_attributes->Content );

							attributes->Name    = get_cached_string( fused );
							attributes->Content = attributes->Name;
							// <Attributes> <Specifiers> <Attributes>
						}

						attributes = more_attributes;
					}

					if ( currtok.Type == TokType::Operator && currtok.Text[0] == '~' )
					{
						member = parse_destructor( specifiers );
						// <Attribute> <Specifiers> ~<Name>()
						break;
					}

					if ( currtok.Type == TokType::Decl_Operator )
					{
						member = parse_operator_cast( specifiers );
						// <Attributes> <Specifiers> operator <Type>()
						break;
					}
				}
				//! Fallthrough intentional
				case TokType::Identifier :
				case TokType::Spec_Const :
				case TokType::Type_Unsigned :
				case TokType::Type_Signed :
				case TokType::Type_Short :
				case TokType::Type_Long :
				case TokType::Type_bool :
				case TokType::Type_char :
				case TokType::Type_int :
				case TokType::Type_double :
				{
					if ( nexttok.Type == TokType::Capture_Start && name.Length && currtok.Type == TokType::Identifier )
					{
						if ( str_compare( name.Text, currtok.Text, name.Length ) == 0 )
						{
							member = parse_constructor( specifiers );
							// <Attributes> <Specifiers> <Name>()
							break;
						}
					}

					member = parse_operator_function_or_variable( expects_function, attributes, specifiers );
					// <Attributes> <Specifiers> operator <Op> ...
					// or
					// <Attributes> <Specifiers> <Name> ...
				}
				break;

				default :
					Token untyped_tok = currtok;

					while ( left && currtok.Type != TokType::BraceCurly_Close )
					{
						untyped_tok.Length = ( (sptr)currtok.Text + currtok.Length ) - (sptr)untyped_tok.Text;
						eat( currtok.Type );
					}

					member = untyped_str( untyped_tok );
					// Something unknown
					break;
			}

			if ( member == Code::Invalid )
			{
				log_failure( "Failed to parse member\n%s", Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			result.append( member );
		}

		eat( TokType::BraceCurly_Close );
		// { <Members> }
		Context.pop();
		return result;
	}

	internal CodeComment parse_comment()
	{
		StackNode scope { nullptr, currtok_noskip, NullToken, txt( __func__ ) };
		Context.push( &scope );

		CodeComment result = (CodeComment)make_code();
		result->Type       = ECode::Comment;
		result->Content    = get_cached_string( currtok_noskip );
		result->Name       = result->Content;
		// result->Token   = currtok_noskip;
		eat( TokType::Comment );

		Context.pop();
		return result;
	}

	internal Code parse_complicated_definition( TokType which )
	{
		push_scope();

		bool is_inplace = false;

		TokArray tokens = Context.Tokens;

		s32 idx         = tokens.Idx;
		s32 level       = 0;
		for ( ; idx < tokens.Arr.num(); idx++ )
		{
			if ( tokens[idx].Type == TokType::BraceCurly_Open )
				level++;

			if ( tokens[idx].Type == TokType::BraceCurly_Close )
				level--;

			if ( level == 0 && tokens[idx].Type == TokType::Statement_End )
				break;
		}

		if ( ( idx - 2 ) == tokens.Idx )
		{
			// Its a forward declaration only
			Code result = parse_forward_or_definition( which, is_inplace );
			// <class, enum, struct, or union> <Name>;
			Context.pop();
			return result;
		}

		Token tok = tokens[idx - 1];
		if ( tok.is_specifier() && is_trailing( ESpecifier::to_type( tok ) ) )
		{
			// <which> <type_identifier>(...) <specifier> ...;

			s32   spec_idx = idx - 1;
			Token spec     = tokens[spec_idx];
			while ( spec.is_specifier() && is_trailing( ESpecifier::to_type( spec ) ) )
			{
				--spec_idx;
				spec = tokens[spec_idx];
			}

			if ( tokens[spec_idx].Type == TokType::Capture_End )
			{
				// Forward declaration with trailing specifiers for a procedure
				tok         = tokens[spec_idx];

				Code result = parse_operator_function_or_variable( false, { nullptr }, { nullptr } );
				// <Attributes> <Specifiers> <ReturnType/ValueType> <operator <Op>, or Name> ...
				Context.pop();
				return result;
			}

			log_failure( "Unsupported or bad member definition after %s declaration\n%s", to_str( which ), Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}
		if ( tok.Type == TokType::Identifier )
		{
			tok                 = tokens[idx - 2];
			bool is_indirection = tok.Type == TokType::Ampersand || tok.Type == TokType::Star;
			bool ok_to_parse    = false;

			if ( tok.Type == TokType::BraceCurly_Close )
			{
				// Its an inplace definition
				// <which> <type_identifier> { ... } <identifier>;
				ok_to_parse = true;
				is_inplace  = true;
			}
			else if ( tok.Type == TokType::Identifier && tokens[idx - 3].Type == which )
			{
				// Its a variable with type ID using <which> namespace.
				// <which> <type_identifier> <identifier>;
				ok_to_parse = true;
			}
			else if ( tok.Type == TokType::Assign_Classifer
			          && ( ( tokens[idx - 5].Type == which && tokens[idx - 4].Type == TokType::Decl_Class ) || ( tokens[idx - 4].Type == which ) ) )
			{
				// Its a forward declaration of an enum
				// <enum>         <type_identifier> : <identifier>;
				// <enum> <class> <type_identifier> : <identifier>;
				ok_to_parse = true;
				Code result = parse_enum();
				Context.pop();
				return result;
			}
			else if ( is_indirection )
			{
				// Its a indirection type with type ID using struct namespace.
				// <which> <type_identifier>* <identifier>;
				ok_to_parse = true;
			}

			if ( ! ok_to_parse )
			{
				log_failure( "Unsupported or bad member definition after %s declaration\n%s", to_str( which ), Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			Code result = parse_operator_function_or_variable( false, { nullptr }, { nullptr } );
			// <Attributes> <Specifiers> <ReturnType/ValueType> <operator <Op>, or Name> ...
			Context.pop();
			return result;
		}
		else if ( tok.Type >= TokType::Type_Unsigned && tok.Type <= TokType::Type_MS_W64 )
		{
			tok = tokens[idx - 2];

			if ( tok.Type != TokType::Assign_Classifer
			     || ( ( tokens[idx - 5].Type != which && tokens[idx - 4].Type != TokType::Decl_Class ) && ( tokens[idx - 4].Type != which ) ) )
			{
				log_failure( "Unsupported or bad member definition after %s declaration\n%s", to_str( which ), Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			// Its a forward declaration of an enum class
			// <enum>         <type_identifier> : <identifier>;
			// <enum> <class> <type_identifier> : <identifier>;
			Code result = parse_enum();
			Context.pop();
			return result;
		}
		else if ( tok.Type == TokType::BraceCurly_Close )
		{
			// Its a definition
			Code result = parse_forward_or_definition( which, is_inplace );
			// <which> { ... };
			Context.pop();
			return result;
		}
		else if ( tok.Type == TokType::BraceSquare_Close )
		{
			// Its an array definition
			Code result = parse_operator_function_or_variable( false, { nullptr }, { nullptr } );
			// <which> <type_identifier> <identifier> [ ... ];
			Context.pop();
			return result;
		}
		else
		{
			log_failure( "Unsupported or bad member definition after %s declaration\n%S", to_str( which ).Ptr, Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}
	}

	internal inline CodeDefine parse_define()
	{
		push_scope();
		eat( TokType::Preprocess_Define );
		// #define

		CodeDefine define = (CodeDefine)make_code();
		define->Type      = ECode::Preprocess_Define;

		if ( ! check( TokType::Identifier ) )
		{
			log_failure( "Error, expected identifier after #define\n%s", Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}

		Context.Scope->Name = currtok;
		define->Name        = get_cached_string( currtok );
		eat( TokType::Identifier );
		// #define <Name>

		if ( ! check( TokType::Preprocess_Content ) )
		{
			log_failure( "Error, expected content after #define %s\n%s", define->Name, Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}

		if ( currtok.Length == 0 )
		{
			define->Content = get_cached_string( currtok );
			eat( TokType::Preprocess_Content );
			// #define <Name> <Content>

			Context.pop();
			return define;
		}

		define->Content = get_cached_string( strip_formatting( currtok, strip_formatting_dont_preserve_newlines ) );
		eat( TokType::Preprocess_Content );
		// #define <Name> <Content>

		Context.pop();
		return define;
	}

	internal inline Code parse_assignment_expression()
	{
		Code expr = { nullptr };

		eat( TokType::Operator );
		// <Attributes> <Specifiers> <ValueType> <Name> =

		Token expr_tok = currtok;

		if ( currtok.Type == TokType::Statement_End && currtok.Type != TokType::Comma )
		{
			log_failure( "Expected expression after assignment operator\n%s", Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}

		s32 level = 0;
		while ( left && currtok.Type != TokType::Statement_End && ( currtok.Type != TokType::Comma || level > 0 ) )
		{
			if ( currtok.Type == TokType::BraceCurly_Open )
				level++;
			if ( currtok.Type == TokType::BraceCurly_Close )
				level--;
			if ( currtok.Type == TokType::Capture_Start )
				level++;
			else if ( currtok.Type == TokType::Capture_End )
				level--;

			eat( currtok.Type );
		}

		expr_tok.Length = ( (sptr)currtok.Text + currtok.Length ) - (sptr)expr_tok.Text - 1;
		expr            = untyped_str( expr_tok );
		// = <Expression>
		return expr;
	}

	internal inline Code parse_forward_or_definition( TokType which, bool is_inplace )
	{
		Code result = CodeInvalid;

		switch ( which )
		{
			case TokType::Decl_Class :
				result = parse_class( is_inplace );
				return result;

			case TokType::Decl_Enum :
				result = parse_enum( is_inplace );
				return result;

			case TokType::Decl_Struct :
				result = parse_struct( is_inplace );
				return result;

			case TokType::Decl_Union :
				result = parse_union( is_inplace );
				return result;

			default :
				log_failure(
				    "Error, wrong token type given to parse_complicated_definition "
				    "(only supports class, enum, struct, union) \n%s",
				    Context.to_string()
				);

				return CodeInvalid;
		}
	}

	// Function parsing is handled in multiple places because its initial signature is shared with variable parsing
	internal inline CodeFn parse_function_after_name( ModuleFlag mflags, CodeAttributes attributes, CodeSpecifiers specifiers, CodeType ret_type, Token name )
	{
		push_scope();
		CodeParam params = parse_params();
		// <Attributes> <Specifiers> <ReturnType> <Name> ( <Parameters> )

		// TODO(Ed), Review old comment : These have to be kept separate from the return type's specifiers.
		while ( left && currtok.is_specifier() )
		{
			if ( specifiers.ast == nullptr )
			{
				specifiers = def_specifier( ESpecifier::to_type( currtok ) );
				eat( currtok.Type );
				continue;
			}

			specifiers.append( ESpecifier::to_type( currtok ) );
			eat( currtok.Type );
		}
		// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>

		CodeBody    body       = NoCode;
		CodeComment inline_cmt = NoCode;
		if ( check( TokType::BraceCurly_Open ) )
		{
			body = parse_function_body();
			if ( body == Code::Invalid )
			{
				Context.pop();
				return CodeInvalid;
			}
			// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers> { <Body> }
		}
		else if ( check( TokType::Operator ) && currtok.Text[0] == '=' )
		{
			eat( TokType::Operator );
			specifiers.append( ESpecifier::Pure );

			eat( TokType::Number );
			Token stmt_end = currtok;
			eat( TokType::Statement_End );
			// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers> = 0;

			if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
				inline_cmt = parse_comment();
			// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>; <InlineCmt>
		}
		else
		{
			Token stmt_end = currtok;
			eat( TokType::Statement_End );
			// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>;

			if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
				inline_cmt = parse_comment();
			// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>; <InlineCmt>
		}

		using namespace ECode;

		String name_stripped = String::make( GlobalAllocator, name );
		name_stripped.strip_space();

		CodeFn result       = (CodeFn)make_code();
		result->Name        = get_cached_string( name_stripped );
		result->ModuleFlags = mflags;

		if ( body )
		{
			switch ( body->Type )
			{
				case Function_Body :
				case Untyped :
					break;

				default :
				{
					log_failure( "Body must be either of Function_Body or Untyped type, %s\n%s", body.debug_str(), Context.to_string() );
					Context.pop();
					return CodeInvalid;
				}
			}

			result->Type = Function;
			result->Body = body;
		}
		else
		{
			result->Type = Function_Fwd;
		}

		if ( attributes )
			result->Attributes = attributes;

		if ( specifiers )
			result->Specs = specifiers;

		result->ReturnType = ret_type;

		if ( params )
			result->Params = params;

		if ( inline_cmt )
			result->InlineCmt = inline_cmt;

		Context.pop();
		return result;
	}

	internal Code parse_function_body()
	{
		using namespace ECode;
		push_scope();

		eat( TokType::BraceCurly_Open );

		CodeBody result = (CodeBody)make_code();
		result->Type    = Function_Body;

		// TODO : Support actual parsing of function body
		Token start = currtok_noskip;

		s32 level   = 0;
		while ( left && ( currtok_noskip.Type != TokType::BraceCurly_Close || level > 0 ) )
		{
			if ( currtok_noskip.Type == TokType::BraceCurly_Open )
				level++;

			else if ( currtok_noskip.Type == TokType::BraceCurly_Close && level > 0 )
				level--;

			eat( currtok_noskip.Type );
		}

		Token previous = prevtok;

		s32 len        = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)start.Text;

		if ( len > 0 )
		{
			result.append( def_execution( { len, start.Text } ) );
		}

		eat( TokType::BraceCurly_Close );

		Context.pop();
		return result;
	}

	internal neverinline CodeBody parse_global_nspace( CodeT which )
	{
		using namespace ECode;

		push_scope();

		if ( which != Namespace_Body && which != Global_Body && which != Export_Body && which != Extern_Linkage_Body )
			return CodeInvalid;

		if ( which != Global_Body )
			eat( TokType::BraceCurly_Open );
		// {

		CodeBody result = (CodeBody)make_code();
		result->Type    = which;

		while ( left && currtok_noskip.Type != TokType::BraceCurly_Close )
		{
			Code           member     = Code::Invalid;
			CodeAttributes attributes = { nullptr };
			CodeSpecifiers specifiers = { nullptr };

			bool expects_function     = false;

			// Context.Scope->Start = currtok_noskip;

			if ( currtok_noskip.Type == TokType::Preprocess_Hash )
				eat( TokType::Preprocess_Hash );

			switch ( currtok_noskip.Type )
			{
				case TokType::Statement_End :
				{
					// TODO(Ed): Convert this to a general warning procedure
					log_fmt( "Dangling end statement found %S\n", currtok_noskip.to_string() );
					eat( TokType::Statement_End );
					continue;
				}
				case TokType::NewLine :
					// Empty lines are auto skipped by Tokens.current()
					member = fmt_newline;
					eat( TokType::NewLine );
					break;

				case TokType::Comment :
					member = parse_comment();
					break;

				case TokType::Decl_Class :
					member = parse_complicated_definition( TokType::Decl_Class );
					// class
					break;

				case TokType::Decl_Enum :
					member = parse_complicated_definition( TokType::Decl_Enum );
					// enum
					break;

				case TokType::Decl_Extern_Linkage :
					if ( which == Extern_Linkage_Body )
						log_failure( "Nested extern linkage\n%s", Context.to_string() );

					member = parse_extern_link();
					// extern "..." { ... }
					break;

				case TokType::Decl_Namespace :
					member = parse_namespace();
					// namespace <Name> { ... }
					break;

				case TokType::Decl_Struct :
					member = parse_complicated_definition( TokType::Decl_Struct );
					// struct ...
					break;

				case TokType::Decl_Template :
					member = parse_template();
					// template<...> ...
					break;

				case TokType::Decl_Typedef :
					member = parse_typedef();
					// typedef ...
					break;

				case TokType::Decl_Union :
					member = parse_complicated_definition( TokType::Decl_Union );
					// union ...
					break;

				case TokType::Decl_Using :
					member = parse_using();
					// using ...
					break;

				case TokType::Preprocess_Define :
					member = parse_define();
					// #define ...
					break;

				case TokType::Preprocess_Include :
					member = parse_include();
					// #include ...
					break;

				case TokType::Preprocess_If :
				case TokType::Preprocess_IfDef :
				case TokType::Preprocess_IfNotDef :
				case TokType::Preprocess_ElIf :
					member = parse_preprocess_cond();
					// #<Conditional> ...
					break;

				case TokType::Preprocess_Else :
					member = preprocess_else;
					eat( TokType::Preprocess_Else );
					// #else
					break;

				case TokType::Preprocess_EndIf :
					member = preprocess_endif;
					eat( TokType::Preprocess_EndIf );
					// #endif
					break;

				case TokType::Preprocess_Macro :
					member = parse_simple_preprocess( TokType::Preprocess_Macro );
					// <Macro>
					break;

				case TokType::Preprocess_Pragma :
					member = parse_pragma();
					// #pragma ...
					break;

				case TokType::Preprocess_Unsupported :
					member = parse_simple_preprocess( TokType::Preprocess_Unsupported );
					// #<UNSUPPORTED> ...
					break;

				case TokType::StaticAssert :
					member = parse_static_assert();
					// static_assert( <Conditional Expression>, ... );
					break;

				case TokType::Module_Export :
					if ( which == Export_Body )
						log_failure( "Nested export declaration\n%s", Context.to_string() );

					member = parse_export_body();
					// export { ... }
					break;

				case TokType::Module_Import :
				{
					not_implemented( context );
					// import ...
				}
				//! Fallthrough intentional
				case TokType::Attribute_Open :
				case TokType::Decl_GNU_Attribute :
				case TokType::Decl_MSVC_Attribute :
#define Entry( attribute, str ) case TokType::attribute :
					GEN_DEFINE_ATTRIBUTE_TOKENS
#undef Entry
					{
						attributes = parse_attributes();
						// <Attributes>
					}
				//! Fallthrough intentional
				case TokType::Spec_Consteval :
				case TokType::Spec_Constexpr :
				case TokType::Spec_Constinit :
				case TokType::Spec_Extern :
				case TokType::Spec_ForceInline :
				case TokType::Spec_Global :
				case TokType::Spec_Inline :
				case TokType::Spec_Internal_Linkage :
				case TokType::Spec_NeverInline :
				case TokType::Spec_Static :
				{
					SpecifierT specs_found[16] { ESpecifier::NumSpecifiers };
					s32        NumSpecifiers = 0;

					while ( left && currtok.is_specifier() )
					{
						SpecifierT spec  = ESpecifier::to_type( currtok );

						bool ignore_spec = false;

						switch ( spec )
						{
							case ESpecifier::Constexpr :
							case ESpecifier::Constinit :
							case ESpecifier::ForceInline :
							case ESpecifier::Global :
							case ESpecifier::External_Linkage :
							case ESpecifier::Internal_Linkage :
							case ESpecifier::Inline :
							case ESpecifier::Mutable :
							case ESpecifier::NeverInline :
							case ESpecifier::Static :
							case ESpecifier::Volatile :
								break;

							case ESpecifier::Consteval :
								expects_function = true;
								break;

							case ESpecifier::Const :
								ignore_spec = true;
								break;

							default :
								StrC spec_str = ESpecifier::to_str( spec );

								log_failure( "Invalid specifier %.*s for variable\n%s", spec_str.Len, spec_str, Context.to_string() );
								Context.pop();
								return CodeInvalid;
						}

						if ( ignore_spec )
							break;

						specs_found[NumSpecifiers] = spec;
						NumSpecifiers++;
						eat( currtok.Type );
					}

					if ( NumSpecifiers )
					{
						specifiers = def_specifiers( NumSpecifiers, specs_found );
					}
					// <Attributes> <Specifiers>
				}
				//! Fallthrough intentional
				case TokType::Identifier :
				case TokType::Spec_Const :
				case TokType::Type_Long :
				case TokType::Type_Short :
				case TokType::Type_Signed :
				case TokType::Type_Unsigned :
				case TokType::Type_bool :
				case TokType::Type_char :
				case TokType::Type_double :
				case TokType::Type_int :
				{
					Code constructor_destructor = parse_global_nspace_constructor_destructor( specifiers );
					// Possible constructor implemented at global file scope.
					if ( constructor_destructor )
					{
						member = constructor_destructor;
						break;
					}

					bool found_operator_cast_outside_class_implmentation = false;
					s32  idx                                             = Context.Tokens.Idx;

					for ( ; idx < Context.Tokens.Arr.num(); idx++ )
					{
						Token tok = Context.Tokens[idx];

						if ( tok.Type == TokType::Identifier )
						{
							idx++;
							tok = Context.Tokens[idx];
							if ( tok.Type == TokType::Access_StaticSymbol )
								continue;

							break;
						}

						if ( tok.Type == TokType::Decl_Operator )
							found_operator_cast_outside_class_implmentation = true;

						break;
					}

					if ( found_operator_cast_outside_class_implmentation )
					{
						member = parse_operator_cast( specifiers );
						// <Attributes> <Specifiers> <Name>::operator <Type>() { ... }
						break;
					}

					member = parse_operator_function_or_variable( expects_function, attributes, specifiers );
					// <Attributes> <Specifiers> ...
				}
			}

			if ( member == Code::Invalid )
			{
				log_failure( "Failed to parse member\n%s", Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			// log_fmt("Global Body Member: %s", member->debug_str());
			result.append( member );
		}

		if ( which != Global_Body )
			eat( TokType::BraceCurly_Close );
		// { <Body> }

		Context.pop();
		return result;
	}

	internal inline Code parse_global_nspace_constructor_destructor( CodeSpecifiers specifiers )
	{
		Code result = { nullptr };

		/*
		    To check if a definition is for a constructor we can go straight to the opening parenthesis for its parameters
		    From There we work backwards to see if we come across two identifiers with the same name between an member access
		    :: operator, there can be template parameters on the left of the :: so we ignore those.
		    Whats important is that	its back to back.

		    This has multiple possible faults. What we parse using this method may not filter out if something has a "return type"
		    This is bad since technically you could have a namespace nested into another namespace with the same name.
		    If this awful pattern is done the only way to distiguish with this coarse parse is to know there is no return type defined.

		    TODO(Ed): We could fix this by attempting to parse a type, but we would have to have a way to have it soft fail and rollback.
		*/
		TokArray tokens = Context.Tokens;

		s32   idx       = tokens.Idx;
		Token nav       = tokens[idx];
		for ( ; idx < tokens.Arr.num(); idx++, nav = tokens[idx] )
		{
			if ( nav.Text[0] == '<' )
			{
				// Skip templated expressions as they mey have expressions with the () operators
				s32 capture_level  = 0;
				s32 template_level = 0;
				for ( ; idx < tokens.Arr.num(); idx++, nav = tokens[idx] )
				{
					if ( nav.Text[0] == '<' )
						++template_level;

					if ( nav.Text[0] == '>' )
						--template_level;
					if ( nav.Type == TokType::Operator && nav.Text[1] == '>' )
						--template_level;

					if ( nav.Type == ETokType::Capture_Start )
					{
						if ( template_level != 0 )
							++capture_level;
						else
							break;
					}

					if ( template_level != 0 && nav.Type == ETokType::Capture_End )
						--capture_level;
				}
			}

			if ( nav.Type == TokType::Capture_Start )
				break;
		}

		--idx;
		Token tok_right = tokens[idx];
		Token tok_left  = NullToken;

		if ( tok_right.Type != TokType::Identifier )
		{
			// We're not dealing with a constructor if there is no identifier right before the opening of a parameter's scope.
			return result;
		}

		--idx;
		tok_left = tokens[idx];
		// <Attributes> <Specifiers> ... <Identifier>

		bool possible_destructor = false;
		if ( tok_left.Type == TokType::Operator && tok_left.Text[0] == '~' )
		{
			possible_destructor = true;
			--idx;
			tok_left = tokens[idx];
		}

		if ( tok_left.Type != TokType::Access_StaticSymbol )
			return result;

		--idx;
		tok_left = tokens[idx];
		// <Attributes> <Specifiers> ... :: <Identifier>

		// We search toward the left until we find the next valid identifier
		s32 capture_level  = 0;
		s32 template_level = 0;
		while ( idx != tokens.Idx )
		{
			if ( tok_left.Text[0] == '<' )
				++template_level;

			if ( tok_left.Text[0] == '>' )
				--template_level;
			if ( tok_left.Type == TokType::Operator && tok_left.Text[1] == '>' )
				--template_level;

			if ( template_level != 0 && tok_left.Type == ETokType::Capture_Start )
				++capture_level;

			if ( template_level != 0 && tok_left.Type == ETokType::Capture_End )
				--capture_level;

			if ( capture_level == 0 && template_level == 0 && tok_left.Type == TokType::Identifier )
				break;

			--idx;
			tok_left = tokens[idx];
		}

		bool is_same = str_compare( tok_right.Text, tok_left.Text, tok_right.Length ) == 0;
		if ( tok_left.Type == TokType::Identifier && is_same )
		{
			// We have found the pattern we desired
			if ( possible_destructor )
			{
				// <Name> :: ~<Name> (
				result = parse_destructor( specifiers );
			}
			else
			{
				// <Name> :: <Name> (
				result = parse_constructor( specifiers );
			}
		}

		return result;
	}

	// TODO(Ed): I want to eventually change the identifier to its own AST type.
	// This would allow distinction of the qualifier for a symbol <qualifier>::<nested symboL>
	// This would also allow
	internal Token parse_identifier( bool* possible_member_function )
	{
		push_scope();

		Token name          = currtok;
		Context.Scope->Name = name;
		eat( TokType::Identifier );
		// <Name>

		parse_template_args( name );
		// <Name><Template Args>

		while ( check( TokType::Access_StaticSymbol ) )
		{
			eat( TokType::Access_StaticSymbol );
			// <Qualifier Name> <Template Args> ::

			if ( left == 0 )
			{
				log_failure( "Error, unexpected end of static symbol identifier\n%s", Context.to_string() );
				Context.pop();
				return { nullptr, 0, TokType::Invalid };
			}

			if ( currtok.Type == TokType::Operator && currtok.Text[0] == '~' )
			{
				bool is_destructor = str_compare( Context.Scope->Prev->ProcName, "parse_destructor" ) == 0;
				if ( is_destructor )
				{
					name.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)name.Text;
					Context.pop();
					return name;
				}

				log_failure( "Error, had a ~ operator after %S but not a destructor\n%s", ETokType::to_str( prevtok.Type ), Context.to_string() );
				Context.pop();
				return { nullptr, 0, TokType::Invalid };
			}

			if ( currtok.Type == TokType::Operator && currtok.Text[0] == '*' && currtok.Length == 1 )
			{
				if ( possible_member_function )
					*possible_member_function = true;

				else
				{
					log_failure( "Found a member function pointer identifier but the parsing context did not expect it\n%s", Context.to_string() );
					Context.pop();
					return { nullptr, 0, TokType::Invalid };
				}
			}

			if ( currtok.Type != TokType::Identifier )
			{
				log_failure( "Error, expected static symbol identifier, not %s\n%s", ETokType::to_str( currtok.Type ), Context.to_string() );
				Context.pop();
				return { nullptr, 0, TokType::Invalid };
			}

			name.Length = ( (sptr)currtok.Text + currtok.Length ) - (sptr)name.Text;
			eat( TokType::Identifier );
			// <Qualifier Name> <Template Args> :: <Name>

			parse_template_args( name );
			// <Qualifier Name> <Template Args> :: <Name> <Template Args>
		}
		// <Qualifier Name> <Template Args> :: <Name> <Template Args> ...

		Context.pop();
		return name;
	}

	internal CodeInclude parse_include()
	{
		push_scope();

		CodeInclude include = (CodeInclude)make_code();
		include->Type       = ECode::Preprocess_Include;
		eat( TokType::Preprocess_Include );
		// #include

		if ( ! check( TokType::String ) )
		{
			log_failure( "Error, expected include string after #include\n%s", Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}

		Context.Scope->Name = currtok;
		include->Content    = get_cached_string( currtok );
		eat( TokType::String );
		// #include <Path> or "Path"

		Context.pop();
		return include;
	}

	internal CodeOperator parse_operator_after_ret_type( ModuleFlag mflags, CodeAttributes attributes, CodeSpecifiers specifiers, CodeType ret_type )
	{
		using namespace EOperator;
		push_scope();

		Token nspace = NullToken;
		if ( check( TokType::Identifier ) )
		{
			nspace = currtok;
			while ( left && currtok.Type == TokType::Identifier )
			{
				eat( TokType::Identifier );

				if ( currtok.Type == TokType::Access_StaticSymbol )
					eat( TokType::Access_StaticSymbol );
			}

			nspace.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)nspace.Text;
		}
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...>

		eat( TokType::Decl_Operator );
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator

		if ( ! left && currtok.Type != TokType::Operator && currtok.Type != TokType::Star && currtok.Type != TokType::Ampersand
		     && currtok.Type != TokType::Ampersand_DBL )
		{
			log_failure( "Expected operator after 'operator' keyword\n%s", Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}

		Context.Scope->Name    = currtok;

		bool was_new_or_delete = false;

		OperatorT op           = Invalid;
		switch ( currtok.Text[0] )
		{
			case '+' :
			{
				if ( currtok.Text[1] == '=' )
					op = Assign_Add;

				else if ( currtok.Text[1] == '+' )
					op = Increment;

				else
					op = Add;
			}
			break;
			case '-' :
			{
				if ( currtok.Text[1] == '>' )
				{
					if ( currtok.Text[2] == '*' )
						op = MemberOfPointer;

					else
						op = MemberOfPointer;

					break;
				}

				else if ( currtok.Text[1] == '=' )
					op = Assign_Subtract;

				else
					op = Subtract;
			}
			break;
			case '*' :
			{
				if ( currtok.Text[1] == '=' )
					op = Assign_Multiply;

				else
				{
					Token& finder = prevtok;
					while ( finder.Type != TokType::Decl_Operator )
					{
						if ( finder.Type == TokType::Identifier )
						{
							op = Indirection;
							break;
						}
					}

					if ( op == Invalid )
						op = Multiply;
				}
			}
			break;
			case '/' :
			{
				if ( currtok.Text[1] == '=' )
					op = Assign_Divide;

				else
					op = Divide;
			}
			break;
			case '%' :
			{
				if ( currtok.Text[1] == '=' )
					op = Assign_Modulo;

				else
					op = Modulo;
			}
			break;
			case '&' :
			{
				if ( currtok.Text[1] == '=' )
					op = Assign_BAnd;

				else if ( currtok.Text[1] == '&' )
					op = LAnd;

				else
				{


					if ( op == Invalid )
						op = BAnd;
				}
			}
			break;
			case '|' :
			{
				if ( currtok.Text[1] == '=' )
					op = Assign_BOr;

				else if ( currtok.Text[1] == '|' )
					op = LOr;

				else
					op = BOr;
			}
			break;
			case '^' :
			{
				if ( currtok.Text[1] == '=' )
					op = Assign_BXOr;

				else
					op = BXOr;
			}
			break;
			case '~' :
			{
				op = BNot;
			}
			break;
			case '!' :
			{
				if ( currtok.Text[1] == '=' )
					op = LNot;

				else
					op = UnaryNot;
			}
			break;
			case '=' :
			{
				if ( currtok.Text[1] == '=' )
					op = LEqual;

				else
					op = Assign;
			}
			break;
			case '<' :
			{
				if ( currtok.Text[1] == '=' )
					op = LEqual;

				else if ( currtok.Text[1] == '<' )
				{
					if ( currtok.Text[2] == '=' )
						op = Assign_LShift;

					else
						op = LShift;
				}
				else
					op = Lesser;
			}
			break;
			case '>' :
			{
				if ( currtok.Text[1] == '=' )
					op = GreaterEqual;

				else if ( currtok.Text[1] == '>' )
				{
					if ( currtok.Text[2] == '=' )
						op = Assign_RShift;

					else
						op = RShift;
				}
				else
					op = Greater;
			}
			break;
			case '(' :
			{
				if ( currtok.Text[1] == ')' )
					op = FunctionCall;

				else
					op = Invalid;
			}
			break;
			case '[' :
			{
				if ( currtok.Text[1] == ']' )
					op = Subscript;

				else
					op = Invalid;
			}
			break;
			default :
			{
				StrC str_new    = to_str( OperatorT::New );
				StrC str_delete = to_str( OperatorT::Delete );
				if ( str_compare( currtok.Text, str_new.Ptr, max( str_new.Len - 1, currtok.Length ) ) == 0 )
				{
					op = OperatorT::New;
					eat( ETokType::Identifier );
					was_new_or_delete = true;

					s32 idx           = Context.Tokens.Idx + 1;
					{
						while ( Context.Tokens[idx].Type == TokType::NewLine )
							idx++;
					}
					Token next = Context.Tokens[idx];
					if ( currtok.Type == TokType::Operator && str_compare( currtok.Text, "[]", 2 ) == 0 )
					{
						eat( ETokType::Operator );
						op = OperatorT::NewArray;
					}
					else if ( currtok.Type == TokType::BraceSquare_Open && next.Type == TokType::BraceSquare_Close )
					{
						eat( ETokType::BraceSquare_Open );
						eat( ETokType::BraceSquare_Close );
						op = OperatorT::NewArray;
					}
				}
				else if ( str_compare( currtok.Text, str_delete.Ptr, max( str_delete.Len - 1, currtok.Length ) ) == 0 )
				{
					op = OperatorT::Delete;
					eat( ETokType::Identifier );
					was_new_or_delete = true;

					s32 idx           = Context.Tokens.Idx + 1;
					{
						while ( Context.Tokens[idx].Type == TokType::NewLine )
							idx++;
					}
					Token next = Context.Tokens[idx];
					if ( currtok.Type == TokType::Operator && str_compare( currtok.Text, "[]", 2 ) == 0 )
					{
						eat( ETokType::Operator );
						op = OperatorT::DeleteArray;
					}
					else if ( currtok.Type == TokType::BraceSquare_Open && next.Type == TokType::BraceSquare_Close )
					{
						eat( ETokType::BraceSquare_Open );
						eat( ETokType::BraceSquare_Close );
						op = OperatorT::DeleteArray;
					}
				}
				else
				{
					if ( op == Invalid )
					{
						log_failure( "Invalid operator '%s'\n%s", prevtok.Text, Context.to_string() );
						Context.pop();
						return CodeInvalid;
					}
				}
			}
		}

		if ( op == Invalid )
		{
			log_failure( "Invalid operator '%s'\n%s", currtok.Text, Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}

		if ( ! was_new_or_delete )
			eat( currtok.Type );
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op>

		// Parse Params
		CodeParam params = parse_params();
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> )

		if ( params.ast == nullptr && op == EOperator::Multiply )
			op = MemberOfPointer;

		while ( left && currtok.is_specifier() )
		{
			if ( specifiers.ast == nullptr )
			{
				specifiers = def_specifier( ESpecifier::to_type( currtok ) );
				eat( currtok.Type );
				continue;
			}

			specifiers.append( ESpecifier::to_type( currtok ) );
			eat( currtok.Type );
		}
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers>

		// Parse Body
		CodeBody    body       = { nullptr };
		CodeComment inline_cmt = NoCode;
		if ( check( TokType::BraceCurly_Open ) )
		{
			body = parse_function_body();
			if ( body == Code::Invalid )
			{
				Context.pop();
				return CodeInvalid;
			}
			// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers> { ... }
		}
		else
		{
			Token stmt_end = currtok;
			eat( TokType::Statement_End );
			// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers>;

			if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
				inline_cmt = parse_comment();
			// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers>; <InlineCmt>
		}

		// OpValidateResult check_result = operator__validate( op, params, ret_type, specifiers );
		CodeOperator result = def_operator( op, nspace, params, ret_type, body, specifiers, attributes, mflags );

		if ( inline_cmt )
			result->InlineCmt = inline_cmt;

		Context.pop();
		return result;
	}

	internal Code parse_operator_function_or_variable( bool expects_function, CodeAttributes attributes, CodeSpecifiers specifiers )
	{
		push_scope();

		Code result = CodeInvalid;

#ifndef GEN_PARSER_DISABLE_MACRO_FUNCTION_SIGNATURES
		if ( currtok.Type == TokType::Preprocess_Macro )
		{
			// Were dealing with a macro after attributes/specifiers.
			result = parse_simple_preprocess( TokType::Preprocess_Macro );
			Context.pop();
			return result;
			// <Attributes> <Specifiers> <Macro>
		}
#endif

		CodeType type = parse_type();
		// <Attributes> <Specifiers> <ReturnType/ValueType>

		if ( type == CodeInvalid )
		{
			Context.pop();
			return CodeInvalid;
		}

		bool found_operator = false;
		s32  idx            = Context.Tokens.Idx;

		for ( ; idx < Context.Tokens.Arr.num(); idx++ )
		{
			Token tok = Context.Tokens[idx];

			if ( tok.Type == TokType::Identifier )
			{
				idx++;
				tok = Context.Tokens[idx];
				if ( tok.Type == TokType::Access_StaticSymbol )
					continue;

				break;
			}

			if ( tok.Type == TokType::Decl_Operator )
				found_operator = true;

			break;
		}

		if ( found_operator )
		{
			// Dealing with an operator overload
			result = parse_operator_after_ret_type( ModuleFlag::None, attributes, specifiers, type );
			// <Attributes> <Specifiers> <ReturnType> operator ...
		}
		else
		{
			Token name            = parse_identifier();
			Context.Scope->Name   = name;

			bool detected_capture = check( TokType::Capture_Start );

			// Check three tokens ahead to make sure that were not dealing with a constructor initialization...
			//                  (         350.0f    ,         <---  Could be the scenario
			// Example : <Capture_Start> <Value> <Comma>
			//                 idx         +1      +2
			bool detected_comma = Context.Tokens.Arr[Context.Tokens.Idx + 2].Type == TokType::Comma;
			if ( detected_capture && ! detected_comma )
			{
				// Dealing with a function
				result = parse_function_after_name( ModuleFlag::None, attributes, specifiers, type, name );
				// <Attributes> <Specifiers> <ReturnType> <Name> ( ...
			}
			else
			{
				if ( expects_function )
				{
					log_failure( "Expected function declaration (consteval was used)\n%s", Context.to_string() );
					Context.pop();
					return CodeInvalid;
				}

				// Dealing with a variable
				result = parse_variable_after_name( ModuleFlag::None, attributes, specifiers, type, name );
				// <Attributes> <Specifiers> <ValueType> <Name> ...
			}
		}

		Context.pop();
		return result;
	}

	internal CodePragma parse_pragma()
	{
		push_scope();

		CodePragma pragma = (CodePragma)make_code();
		pragma->Type      = ECode::Preprocess_Pragma;
		eat( TokType::Preprocess_Pragma );
		// #pragma

		if ( ! check( TokType::Preprocess_Content ) )
		{
			log_failure( "Error, expected content after #pragma\n%s", Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}

		Context.Scope->Name = currtok;

		pragma->Content     = get_cached_string( currtok );
		eat( TokType::Preprocess_Content );
		// #pragma <Content>

		Context.pop();
		return pragma;
	}

	internal inline CodeParam parse_params( bool use_template_capture )
	{
		using namespace ECode;
		push_scope();

		if ( ! use_template_capture )
			eat( TokType::Capture_Start );
		// (

		else
		{
			if ( check( TokType::Operator ) && currtok.Text[0] == '<' )
				eat( TokType::Operator );
			// <
		}

		if ( ! use_template_capture && check( TokType::Capture_End ) )
		{
			eat( TokType::Capture_End );
			// )
			Context.pop();
			return { nullptr };
		}
		else if ( check( TokType::Operator ) && currtok.Text[0] == '>' )
		{
			eat( TokType::Operator );
			// >
			Context.pop();
			return { nullptr };
		}

		Code     macro           = { nullptr };
		CodeType type            = { nullptr };
		Code     value           = { nullptr };
		Token    name            = NullToken;
		Code     post_name_macro = { nullptr };

		if ( check( TokType::Varadic_Argument ) )
		{
			eat( TokType::Varadic_Argument );
			// ( or <  ...

			Context.pop();
			return param_varadic;
			// ( ... )
			// or < ... >
		}

#define CheckEndParams() ( use_template_capture ? ( currtok.Text[0] != '>' ) : ( currtok.Type != TokType::Capture_End ) )

		// Ex: Unreal has this type of macro:                 vvvvvvvvv
		// COREUOBJECT_API void CallFunction( FFrame& Stack, RESULT_DECL, UFunction* Function );
		// and:                 vvvv
		// AddComponentByClass(UPARAM(meta = (AllowAbstract = "false")) TSubclassOf<UActorComponent> Class, bool bManualAttachment, ...
		if ( check( TokType::Preprocess_Macro ) )
		{
			macro = parse_simple_preprocess( ETokType::Preprocess_Macro );
			// ( <Macro>
		}
		if ( currtok.Type != TokType::Comma )
		{
			type = parse_type( use_template_capture );
			if ( type == Code::Invalid )
			{
				Context.pop();
				return CodeInvalid;
			}
			// ( <Macro> <ValueType>

			if ( check( TokType::Identifier ) )
			{
				name = currtok;
				eat( TokType::Identifier );
				// ( <Macro> <ValueType> <Name>
			}

			// Unreal has yet another type of macro:
			// template<class T UE_REQUIRES(TPointerIsConvertibleFromTo<T, UInterface>::Value)>
			// class T ... and then ^this^ UE_REQUIRES shows up
			// So we need to consume that.
			if ( check( TokType::Preprocess_Macro ) )
			{
				post_name_macro = parse_simple_preprocess( ETokType::Preprocess_Macro );
			}

			// In template captures you can have a typename have direct assignment without a name
			// typename = typename ...
			// Which would result in a static value type from a struct expansion (traditionally)
			if ( ( name.Text || use_template_capture ) && bitfield_is_equal( u32, currtok.Flags, TF_Assign ) )
			{
				eat( TokType::Operator );
				// ( <Macro> <ValueType> <Name> =

				Token value_tok = currtok;

				if ( currtok.Type == TokType::Comma )
				{
					log_failure( "Expected value after assignment operator\n%s.", Context.to_string() );
					Context.pop();
					return CodeInvalid;
				}

				s32 capture_level  = 0;
				s32 template_level = 0;
				while ( ( left && ( currtok.Type != TokType::Comma ) && template_level >= 0 && CheckEndParams() ) || ( capture_level > 0 || template_level > 0 )
				)
				{
					if ( currtok.Text[0] == '<' )
						++template_level;

					if ( currtok.Text[0] == '>' )
						--template_level;
					if ( currtok.Type == TokType::Operator && currtok.Text[1] == '>' )
						--template_level;

					if ( currtok.Type == ETokType::Capture_Start )
						++capture_level;

					if ( currtok.Type == ETokType::Capture_End )
						--capture_level;

					value_tok.Length = ( (sptr)currtok.Text + currtok.Length ) - (sptr)value_tok.Text;
					eat( currtok.Type );
				}

				value = untyped_str( strip_formatting( value_tok, strip_formatting_dont_preserve_newlines ) );
				// ( <Macro> <ValueType> <Name> = <Expression>
			}
		}

		CodeParam result = (CodeParam)make_code();
		result->Type     = Parameters;

		result->Macro    = macro;

		if ( name.Length > 0 )
			result->Name = get_cached_string( name );

		result->ValueType = type;

		if ( value )
			result->Value = value;

		result->NumEntries++;

		while ( check( TokType::Comma ) )
		{
			eat( TokType::Comma );
			// ( <Macro> <ValueType> <Name> = <Expression>,

			Code type  = { nullptr };
			Code value = { nullptr };

			if ( check( TokType::Varadic_Argument ) )
			{
				eat( TokType::Varadic_Argument );
				result.append( param_varadic );
				continue;
				// ( <Macro> <ValueType> <Name> = <Expression>, ...
			}

			// Ex: Unreal has this type of macro:                 vvvvvvvvv
			// COREUOBJECT_API void CallFunction( FFrame& Stack, RESULT_DECL, UFunction* Function );
			// and:                 vvvv
			// AddComponentByClass(UPARAM(meta = (AllowAbstract = "false")) TSubclassOf<UActorComponent> Class, bool bManualAttachment, ...
			if ( check( TokType::Preprocess_Macro ) )
			{
				macro = parse_simple_preprocess( ETokType::Preprocess_Macro );
				// ( <Macro>
			}
			if ( currtok.Type != TokType::Comma )
			{
				type = parse_type( use_template_capture );
				if ( type == Code::Invalid )
				{
					Context.pop();
					return CodeInvalid;
				}
				// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType>

				name = { nullptr, 0, TokType::Invalid, false };

				if ( check( TokType::Identifier ) )
				{
					name = currtok;
					eat( TokType::Identifier );
					// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <Name>
				}

				// Unreal has yet another type of macro:
				// template<class T UE_REQUIRES(TPointerIsConvertibleFromTo<T, UInterface>::Value)>
				// class T ... and then ^this^ UE_REQUIRES shows up
				// So we need to consume that.
				if ( check( TokType::Preprocess_Macro ) )
				{
					post_name_macro = parse_simple_preprocess( ETokType::Preprocess_Macro );
				}

				// In template captures you can have a typename have direct assignment without a name
				// typename = typename ...
				// Which would result in a static value type from a struct expansion (traditionally)
				if ( ( name.Text || use_template_capture ) && bitfield_is_equal( u32, currtok.Flags, TF_Assign ) )
				{
					eat( TokType::Operator );
					// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <Name> =

					Token value_tok = currtok;

					if ( currtok.Type == TokType::Comma )
					{
						log_failure( "Expected value after assignment operator\n%s", Context.to_string() );
						Context.pop();
						return CodeInvalid;
					}

					s32 capture_level  = 0;
					s32 template_level = 0;
					while ( ( left && currtok.Type != TokType::Comma && template_level >= 0 && CheckEndParams() ) || ( capture_level > 0 || template_level > 0 )
					)
					{
						if ( currtok.Text[0] == '<' )
							++template_level;

						if ( currtok.Text[0] == '>' )
							--template_level;
						if ( currtok.Type == TokType::Operator && currtok.Text[1] == '>' )
							--template_level;

						if ( currtok.Type == ETokType::Capture_Start )
							++capture_level;

						if ( currtok.Type == ETokType::Capture_End )
							--capture_level;

						value_tok.Length = ( (sptr)currtok.Text + currtok.Length ) - (sptr)value_tok.Text;
						eat( currtok.Type );
					}

					value = untyped_str( strip_formatting( value_tok, strip_formatting_dont_preserve_newlines ) );
					// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <Name> = <Expression>
				}
				// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <Name> = <Expression>, ..
			}

			CodeParam param = (CodeParam)make_code();
			param->Type     = Parameters;

			param->Macro    = macro;

			if ( name.Length > 0 )
				param->Name = get_cached_string( name );

			param->PostNameMacro = post_name_macro;
			param->ValueType     = type;

			if ( value )
				param->Value = value;

			result.append( param );
		}

		if ( ! use_template_capture )
			eat( TokType::Capture_End );
		// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <Name> = <Expression>, .. )

		else
		{
			if ( ! check( TokType::Operator ) || currtok.Text[0] != '>' )
			{
				log_failure( "Expected '<' after 'template' keyword\n%s", Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}
			eat( TokType::Operator );
			// < <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <Name> = <Expression>, .. >
		}

		Context.pop();
		return result;
#undef context
	}

	internal CodePreprocessCond parse_preprocess_cond()
	{
		push_scope();

		if ( ! currtok.is_preprocess_cond() )
		{
			log_failure( "Error, expected preprocess conditional\n%s", Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}

		CodePreprocessCond cond = (CodePreprocessCond)make_code();
		cond->Type              = scast( CodeT, currtok.Type - ( TokType::Preprocess_If - ECode::Preprocess_If ) );
		eat( currtok.Type );
		// #<Conditional>

		if ( ! check( TokType::Preprocess_Content ) )
		{
			log_failure( "Error, expected content after #define\n%s", Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}

		Context.Scope->Name = currtok;
		cond->Content       = get_cached_string( currtok );
		eat( TokType::Preprocess_Content );
		// #<Conditiona> <Content>

		Context.pop();
		return cond;
	}

	internal inline Code parse_simple_preprocess( TokType which )
	{
		// TODO(Ed): We can handle a macro a bit better than this. It's AST can be made more robust..
		// Make an AST_Macro, it should have an Name be the macro itself, with the function body being an optional function body node.
		// If we want it to terminate or have an inline comment we can possbily use its parent typedef for that info...
		push_scope();

		Token tok = currtok;
		eat( which );
		// <Macro>

		if ( currtok.Type == TokType::BraceCurly_Open )
		{
			// Eat the block scope right after the macro. Were assuming the macro defines a function definition's signature
			eat( TokType::BraceCurly_Open );
			// <Macro> {

			// TODO(Ed) : Parse this properly later (expression and statement support)
			s32 level = 0;
			while ( left && ( currtok.Type != TokType::BraceCurly_Close || level > 0 ) )
			{
				if ( currtok.Type == TokType::BraceCurly_Open )
					level++;

				else if ( currtok.Type == TokType::BraceCurly_Close && level > 0 )
					level--;

				eat( currtok.Type );
			}
			eat( TokType::BraceCurly_Close );
			// <Macro> { <Body> }

			StrC prev_proc = Context.Scope->Prev->ProcName;
			if ( str_compare( prev_proc.Ptr, "parse_typedef", prev_proc.Len ) != 0 )
			{
				if ( check( TokType::Statement_End ) )
				{
					Token stmt_end = currtok;
					eat( TokType::Statement_End );
					// <Macro> { <Content> };

					if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
						eat( TokType::Comment );
					// <Macro> { <Content> }; <InlineCmt>
				}
			}

			tok.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)tok.Text;
		}
		else
		{
			if ( str_compare( Context.Scope->Prev->ProcName.Ptr, "parse_typedef", Context.Scope->Prev->ProcName.Len ) != 0 )
			{
				if ( check( TokType::Statement_End ) )
				{
					Token stmt_end = currtok;
					eat( TokType::Statement_End );
					// <Macro>;

					if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
						eat( TokType::Comment );
					// <Macro>; <InlineCmt>
				}
			}

			tok.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)tok.Text;
		}

		char const* content = str_fmt_buf( "%.*s ", tok.Length, tok.Text );

		Code result         = untyped_str( to_str( content ) );
		Context.Scope->Name = tok;

		Context.pop();
		return result;
	}

	internal Code parse_static_assert()
	{
		push_scope();

		Code assert         = make_code();
		assert->Type        = ECode::Untyped;

		Token content       = currtok;

		Context.Scope->Name = content;

		eat( TokType::StaticAssert );
		eat( TokType::Capture_Start );
		// static_assert(

		// TODO(Ed) : Parse this properly.
		s32 level = 0;
		while ( left && ( currtok.Type != TokType::Capture_End || level > 0 ) )
		{
			if ( currtok.Type == TokType::Capture_Start )
				level++;
			else if ( currtok.Type == TokType::Capture_End )
				level--;

			eat( currtok.Type );
		}
		eat( TokType::Capture_End );
		eat( TokType::Statement_End );
		// static_assert( <Content> );

		content.Length  = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)content.Text;

		char const* str = str_fmt_buf( "%.*s\n", content.Length, content.Text );
		assert->Content = get_cached_string( { content.Length + 1, str } );
		assert->Name    = assert->Content;

		Context.pop();
		return assert;
	}

	/*
	    This a brute-froce make all the arguments part of the token provided.
	    Can have in-place function signatures, regular identifiers, in-place typenames, compile-time expressions, parameter-pack expansion, etc.
	    This means that validation can only go so far, and so if there is any different in formatting
	    passed the basic stripping supported it report a soft failure.
	*/
	internal inline void parse_template_args( Token& token )
	{
		if ( currtok.Type == TokType::Operator && currtok.Text[0] == '<' && currtok.Length == 1 )
		{
			eat( TokType::Operator );
			// <

			s32 level = 0;
			while ( left && level >= 0 && ( currtok.Text[0] != '>' || level > 0 ) )
			{
				if ( currtok.Text[0] == '<' )
					level++;

				if ( currtok.Text[0] == '>' )
					level--;
				if ( currtok.Type == TokType::Operator && currtok.Text[1] == '>' )
					level--;

				eat( currtok.Type );
			}
			// < <Content>

			// Due to the >> token, this could have been eaten early...
			if ( level == 0 )
				eat( TokType::Operator );
			// < <Content> >

			// Extend length of name to last token
			token.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)token.Text;
		}
	}

	// Variable parsing is handled in multiple places because its initial signature is shared with function parsing
	internal CodeVar parse_variable_after_name( ModuleFlag mflags, CodeAttributes attributes, CodeSpecifiers specifiers, CodeType type, StrC name )
	{
		push_scope();

		Code array_expr                   = parse_array_decl();
		Code expr                         = { nullptr };
		Code bitfield_expr                = { nullptr };

		b32 using_constructor_initializer = false;

		if ( bitfield_is_equal( u32, currtok.Flags, TF_Assign ) )
		{
			// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>
			expr = parse_assignment_expression();
		}

		if ( currtok.Type == TokType::BraceCurly_Open )
		{
			Token expr_tok = currtok;

			eat( TokType::BraceCurly_Open );
			// <Attributes> <Specifiers> <ValueType> <Name> {

			s32 level = 0;
			while ( left && ( currtok.Type != TokType::BraceCurly_Close || level > 0 ) )
			{
				if ( currtok.Type == TokType::BraceCurly_Open )
					level++;

				else if ( currtok.Type == TokType::BraceCurly_Close && level > 0 )
					level--;

				eat( currtok.Type );
			}
			eat( TokType::BraceCurly_Close );

			expr_tok.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)expr_tok.Text;
			expr            = untyped_str( expr_tok );
			// <Attributes> <Specifiers> <ValueType> <Name> = { <Expression> }
		}

		if ( currtok.Type == TokType::Capture_Start )
		{
			eat( TokType::Capture_Start );
			// <Attributes> <Specifiers> <ValueType> <Name> (

			Token expr_token              = currtok;

			using_constructor_initializer = true;

			s32 level                     = 0;
			while ( left && ( currtok.Type != TokType::Capture_End || level > 0 ) )
			{
				if ( currtok.Type == TokType::Capture_Start )
					level++;

				else if ( currtok.Type == TokType::Capture_End && level > 0 )
					level--;

				eat( currtok.Type );
			}

			expr_token.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)expr_token.Text;
			expr              = untyped_str( expr_token );
			eat( TokType::Capture_End );
			// <Attributes> <Specifiers> <ValueType> <Name> ( <Expression> )
		}

		if ( currtok.Type == TokType::Assign_Classifer )
		{
			eat( TokType::Assign_Classifer );
			// <Attributes> <Specifiers> <ValueType> <Name> :

			Token expr_tok = currtok;

			if ( currtok.Type == TokType::Statement_End )
			{
				log_failure( "Expected expression after bitfield \n%s", Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			while ( left && currtok.Type != TokType::Statement_End )
			{
				eat( currtok.Type );
			}

			expr_tok.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)expr_tok.Text;
			bitfield_expr   = untyped_str( expr_tok );
			// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>
		}

		CodeVar     next_var   = NoCode;
		Token       stmt_end   = NullToken;
		CodeComment inline_cmt = NoCode;
		if ( type )
		{
			if ( currtok.Type == TokType::Comma )
			{
				// Were dealing with a statement with more than one declaration
				// This is only handled this way if its the first declaration
				// Otherwise its looped through in parse_variable_declaration_list
				next_var = parse_variable_declaration_list();
				// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>, ...
				// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>, ...
				// <Attributes> <Specifiers> <ValueType> <Name> { <Expression> }, ...
			}

			// If we're dealing with a "comma-procedding then we cannot expect a statement end or inline comment
			// Any comma procedding variable will not have a type provided so it can act as a indicator to skip this
			Token stmt_end = currtok;
			eat( TokType::Statement_End );
			// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>, ...;
			// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>, ...;
			// <Attributes> <Specifiers> <ValueType> <Name> { <Expression> }, ...;

			// Check for inline comment : <type> <identifier> = <expression>; // <inline comment>
			if ( left && ( currtok_noskip.Type == TokType::Comment ) && currtok_noskip.Line == stmt_end.Line )
			{
				inline_cmt = parse_comment();
				// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>, ...; <InlineCmt>
				// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>, ...; <InlineCmt>
				// <Attributes> <Specifiers> <ValueType> <Name> { <Expression> }, ...; <InlineCmt>
			}
		}

		using namespace ECode;

		CodeVar result      = (CodeVar)make_code();
		result->Type        = Variable;
		result->Name        = get_cached_string( name );
		result->ModuleFlags = mflags;

		// Type can be null if we're dealing with a declaration from a variable declaration-list
		if ( type )
			result->ValueType = type;

		if ( array_expr )
			type->ArrExpr = array_expr;

		if ( bitfield_expr )
			result->BitfieldSize = bitfield_expr;

		if ( attributes )
			result->Attributes = attributes;

		if ( specifiers )
			result->Specs = specifiers;

		if ( expr )
			result->Value = expr;

		if ( inline_cmt )
			result->InlineCmt = inline_cmt;

		if ( next_var )
		{
			result->NextVar         = next_var;
			result->NextVar->Parent = result;
		}

		result->VarConstructorInit = using_constructor_initializer;

		Context.pop();
		return result;
	}

	/*
	    Note(Ed): This does not support the following:
	    * Function Pointers
	*/
	internal CodeVar parse_variable_declaration_list()
	{
		push_scope();

		CodeVar result   = NoCode;
		CodeVar last_var = NoCode;
		while ( check( TokType::Comma ) )
		{
			eat( TokType::Comma );
			// ,

			CodeSpecifiers specifiers = NoCode;

			while ( left && currtok.is_specifier() )
			{
				SpecifierT spec = ESpecifier::to_type( currtok );

				switch ( spec )
				{
					case ESpecifier::Const :
						if ( specifiers->NumEntries && specifiers->ArrSpecs[specifiers->NumEntries - 1] != ESpecifier::Ptr )
						{
							log_failure(
							    "Error, const specifier must come after pointer specifier for variable declaration proceeding comma\n"
							    "(Parser will add and continue to specifiers, but will most likely fail to compile)\n%s",
							    Context.to_string()
							);

							specifiers.append( spec );
						}
						break;

					case ESpecifier::Ptr :
					case ESpecifier::Ref :
					case ESpecifier::RValue :
						break;

					default :
					{
						log_failure(
						    "Error, invalid specifier '%s' proceeding comma\n"
						    "(Parser will add and continue to specifiers, but will most likely fail to compile)\n%s",
						    currtok.Text,
						    Context.to_string()
						);
						continue;
					}
					break;
				}

				// eat(currtok.Type);

				if ( specifiers )
					specifiers.append( spec );
				else
					specifiers = def_specifier( spec );
			}
			// , <Specifiers>

			StrC name = currtok;
			eat( TokType::Identifier );
			// , <Specifiers> <Name>

			CodeVar var = parse_variable_after_name( ModuleFlag::None, NoCode, specifiers, NoCode, name );
			// , <Specifiers> <Name> ...

			if ( ! result )
			{
				result.ast   = var.ast;
				last_var.ast = var.ast;
			}
			else
			{
				last_var->NextVar.ast         = var.ast;
				last_var->NextVar->Parent.ast = rcast( AST*, var.ast );
				last_var.ast                  = var.ast;
			}
		}

		Context.pop();
		return result;
	}

	internal CodeClass parse_class( bool inplace_def )
	{
		push_scope();
		CodeClass result = (CodeClass)parse_class_struct( TokType::Decl_Class, inplace_def );
		Context.pop();
		return result;
	}

	internal CodeConstructor parse_constructor( CodeSpecifiers specifiers )
	{
		push_scope();

		Token     identifier = parse_identifier();
		CodeParam params     = parse_params();
		// <Name> ( <Parameters> )

		Code        initializer_list = NoCode;
		CodeBody    body             = NoCode;
		CodeComment inline_cmt       = NoCode;

		// TODO(Ed) : Need to support postfix specifiers

		if ( check( TokType::Assign_Classifer ) )
		{
			eat( TokType::Assign_Classifer );
			// <Name> ( <Parameters> ) :

			Token initializer_list_tok = currtok;

			s32 level                  = 0;
			while ( left && ( currtok.Type != TokType::BraceCurly_Open || level > 0 ) )
			{
				if ( currtok.Type == TokType::Capture_Start )
					level++;
				else if ( currtok.Type == TokType::Capture_End )
					level--;

				eat( currtok.Type );
			}

			initializer_list_tok.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)initializer_list_tok.Text;
			// <Name> ( <Parameters> ) : <InitializerList>

			initializer_list = untyped_str( initializer_list_tok );

			// TODO(Ed): Constructors can have post-fix specifiers

			body = parse_function_body();
			// <Name> ( <Parameters> ) : <InitializerList> { <Body> }
		}
		else if ( check( TokType::BraceCurly_Open ) )
		{
			body = parse_function_body();
			// <Name> ( <Parameters> ) { <Body> }
		}
		else if ( check( TokType::Operator ) && currtok.Text[0] == '=' )
		{
			body = parse_assignment_expression();
		}
		else
		{
			Token stmt_end = currtok;
			eat( TokType::Statement_End );
			// <Name> ( <Parameters> );

			if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
				inline_cmt = parse_comment();
			// <Name> ( <Parameters> ); <InlineCmt>
		}

		CodeConstructor result = (CodeConstructor)make_code();

		result->Name           = get_cached_string( identifier );

		result->Specs          = specifiers;

		if ( params )
			result->Params = params;

		if ( initializer_list )
			result->InitializerList = initializer_list;

		if ( body && body->Type == ECode::Function_Body )
		{
			result->Body = body;
			result->Type = ECode::Constructor;
		}
		else
			result->Type = ECode::Constructor_Fwd;

		if ( inline_cmt )
			result->InlineCmt = inline_cmt;

		Context.pop();
		return result;
	}

	internal CodeDestructor parse_destructor( CodeSpecifiers specifiers )
	{
		push_scope();

		bool has_context         = Context.Scope && Context.Scope->Prev;
		bool is_in_global_nspace = has_context && str_compare( Context.Scope->Prev->ProcName, "parse_global_nspace" ) == 0;

		if ( check( TokType::Spec_Virtual ) )
		{
			if ( specifiers )
				specifiers.append( ESpecifier::Virtual );
			else
				specifiers = def_specifier( ESpecifier::Virtual );
			eat( TokType::Spec_Virtual );
		}
		// <Virtual Specifier>

		Token prefix_identifier = NullToken;
		if ( is_in_global_nspace )
			prefix_identifier = parse_identifier();

		if ( left && currtok.Text[0] == '~' )
			eat( TokType::Operator );
		else
		{
			log_failure( "Expected destructor '~' token\n%s", Context.to_string() );
			return CodeInvalid;
		}
		// <Virtual Specifier> ~

		Token       identifier = parse_identifier();
		CodeBody    body       = { nullptr };
		CodeComment inline_cmt = NoCode;
		// <Virtual Specifier> ~<Name>

		eat( TokType::Capture_Start );
		eat( TokType::Capture_End );
		// <Virtual Specifier> ~<Name>()

		bool pure_virtual = false;

		if ( check( TokType::Operator ) && currtok.Text[0] == '=' )
		{
			// <Virtual Specifier> ~<Name>() =

			bool  skip_formatting = true;
			Token next            = Context.Tokens.next( skip_formatting );
			if ( left && next.Text[0] == '0' )
			{
				eat( TokType::Operator );
				eat( TokType::Number );
				// <Virtual Specifier> ~<Name>() = 0

				specifiers.append( ESpecifier::Pure );
			}
			else if ( left && str_compare( next.Text, "default", sizeof( "default" ) - 1 ) == 0 )
			{
				body = parse_assignment_expression();
				// <Virtual Specifier> ~<
			}
			else
			{
				log_failure( "Pure or default specifier expected due to '=' token\n%s", Context.to_string() );
				return CodeInvalid;
			}

			pure_virtual = true;
		}

		if ( ! pure_virtual && check( TokType::BraceCurly_Open ) )
			body = parse_function_body();
		// <Virtual Specifier> ~<Name>() { ... }
		else
		{
			Token stmt_end = currtok;
			eat( TokType::Statement_End );
			// <Virtual Specifier> ~<Name>() <Pure Specifier>;

			if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
				inline_cmt = parse_comment();
			// <Virtual Specifier> ~<Name>() <Pure Specifier>; <InlineCmt>
		}

		CodeDestructor result = (CodeDestructor)make_code();

		if ( prefix_identifier )
		{
			prefix_identifier.Length += 1 + identifier.Length;
			result->Name              = get_cached_string( prefix_identifier );
		}

		if ( specifiers )
			result->Specs = specifiers;

		if ( body && body->Type == ECode::Function_Body )
		{
			result->Body = body;
			result->Type = ECode::Destructor;
		}
		else
			result->Type = ECode::Destructor_Fwd;

		if ( inline_cmt )
			result->InlineCmt = inline_cmt;

		Context.pop();
		return result;
	}

	internal CodeEnum parse_enum( bool inplace_def )
	{
		using namespace ECode;
		push_scope();

		SpecifierT specs_found[16] { ESpecifier::NumSpecifiers };
		s32        NumSpecifiers  = 0;

		CodeAttributes attributes = { nullptr };

		Token    name             = { nullptr, 0, TokType::Invalid };
		Code     array_expr       = { nullptr };
		CodeType type             = { nullptr };

		char entries_code[kilobytes( 128 )] { 0 };
		s32  entries_length = 0;

		bool is_enum_class  = false;

		eat( TokType::Decl_Enum );
		// enum

		if ( currtok.Type == TokType::Decl_Class )
		{
			eat( TokType::Decl_Class );
			is_enum_class = true;
			// enum class
		}

		attributes = parse_attributes();
		// enum <class> <Attributes>

		if ( check( TokType::Identifier ) )
		{
			name                = currtok;
			Context.Scope->Name = currtok;
			eat( TokType::Identifier );
		}
		// enum <class> <Attributes> <Name>

		if ( currtok.Type == TokType::Assign_Classifer )
		{
			eat( TokType::Assign_Classifer );
			// enum <class> <Attributes> <Name> :

			type = parse_type();
			if ( type == Code::Invalid )
			{
				log_failure( "Failed to parse enum classifier\n%s", Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}
			// enum <class> <Attributes> <Name> : <UnderlyingType>
		}

		CodeBody body = { nullptr };

		if ( currtok.Type == TokType::BraceCurly_Open )
		{
			body       = (CodeBody)make_code();
			body->Type = ECode::Enum_Body;

			eat( TokType::BraceCurly_Open );
			// enum <class> <Attributes> <Name> : <UnderlyingType> {

			Code member        = CodeInvalid;

			bool expects_entry = true;
			while ( left && currtok_noskip.Type != TokType::BraceCurly_Close )
			{
				if ( ! expects_entry )
				{
					log_failure( "Did not expect an entry after last member of enum body.\n%s", Context.to_string() );
					Context.pop();
					break;
				}

				if ( currtok_noskip.Type == TokType::Preprocess_Hash )
					eat( TokType::Preprocess_Hash );

				switch ( currtok_noskip.Type )
				{
					case TokType::NewLine :
						member = untyped_str( currtok_noskip );
						eat( TokType::NewLine );
						break;

					case TokType::Comment :
						member = parse_comment();
						break;

					case TokType::Preprocess_Define :
						member = parse_define();
						// #define
						break;

					case TokType::Preprocess_If :
					case TokType::Preprocess_IfDef :
					case TokType::Preprocess_IfNotDef :
					case TokType::Preprocess_ElIf :
						member = parse_preprocess_cond();
						// #<if, ifdef, ifndef, elif> ...
						break;

					case TokType::Preprocess_Else :
						member = preprocess_else;
						eat( TokType::Preprocess_Else );
						break;

					case TokType::Preprocess_EndIf :
						member = preprocess_endif;
						eat( TokType::Preprocess_EndIf );
						break;

					case TokType::Preprocess_Macro :
						member = parse_simple_preprocess( TokType::Preprocess_Macro );
						// <Macro>
						break;

					case TokType::Preprocess_Pragma :
						member = parse_pragma();
						// #pragma
						break;

					case TokType::Preprocess_Unsupported :
						member = parse_simple_preprocess( TokType::Preprocess_Unsupported );
						// #<UNSUPPORTED>
						break;

					default :
						Token entry = currtok;

						eat( TokType::Identifier );
						// <Name>

						if ( currtok.Type == TokType::Operator && currtok.Text[0] == '=' )
						{
							eat( TokType::Operator );
							// <Name> =

							while ( currtok_noskip.Type != TokType::Comma && currtok_noskip.Type != TokType::BraceCurly_Close )
							{
								eat( currtok_noskip.Type );
							}
						}
						// <Name> = <Expression>

						// Unreal UMETA macro support
						if ( currtok.Type == TokType::Preprocess_Macro )
						{
							eat( TokType::Preprocess_Macro );
							// <Name> = <Expression> <Macro>
						}

						if ( currtok.Type == TokType::Comma )
						{
							eat( TokType::Comma );
							// <Name> = <Expression> <Macro>,
						}

						// Consume inline comments
						// if ( currtok.Type == TokType::Comment && prevtok.Line == currtok.Line )
						// {
						// eat( TokType::Comment );
						// <Name> = <Expression> <Macro>, // <Inline Comment>
						// }

						entry.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)entry.Text;

						member       = untyped_str( entry );
						break;
				}

				if ( member == Code::Invalid )
				{
					log_failure( "Failed to parse member\n%s", Context.to_string() );
					Context.pop();
					return CodeInvalid;
				}

				body.append( member );
			}

			eat( TokType::BraceCurly_Close );
			// enum <class> <Attributes> <Name> : <UnderlyingType> { <Body> }
		}

		CodeComment inline_cmt = NoCode;

		if ( ! inplace_def )
		{
			Token stmt_end = currtok;
			eat( TokType::Statement_End );
			// enum <class> <Attributes> <Name> : <UnderlyingType> { <Body> };

			if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
				inline_cmt = parse_comment();
			// enum <class> <Attributes> <Name> : <UnderlyingType> { <Body> }; <InlineCmt>
		}

		using namespace ECode;

		CodeEnum result = (CodeEnum)make_code();

		if ( body.ast )
		{
			result->Type = is_enum_class ? Enum_Class : Enum;
			result->Body = body;
		}
		else
		{
			result->Type = is_enum_class ? Enum_Class_Fwd : Enum_Fwd;
		}

		result->Name = get_cached_string( name );

		if ( attributes )
			result->Attributes = attributes;

		if ( type )
			result->UnderlyingType = type;

		if ( inline_cmt )
			result->InlineCmt = inline_cmt;

		Context.pop();
		return result;
	}

	internal inline CodeBody parse_export_body()
	{
		push_scope();
		CodeBody result = parse_global_nspace( ECode::Export_Body );
		Context.pop();
		return result;
	}

	internal inline CodeBody parse_extern_link_body()
	{
		push_scope();
		CodeBody result = parse_global_nspace( ECode::Extern_Linkage_Body );
		Context.pop();
		return result;
	}

	internal CodeExtern parse_extern_link()
	{
		push_scope();

		eat( TokType::Decl_Extern_Linkage );
		// extern

		Token name = currtok;
		eat( TokType::String );
		// extern "<Name>"

		name.Text         += 1;
		name.Length       -= 1;

		CodeExtern result  = (CodeExtern)make_code();
		result->Type       = ECode::Extern_Linkage;
		result->Name       = get_cached_string( name );

		Code entry         = parse_extern_link_body();
		if ( entry == Code::Invalid )
		{
			log_failure( "Failed to parse body\n%s", Context.to_string() );
			Context.pop();
			return result;
		}
		// extern "<Name>" { <Body> }

		result->Body = entry;

		Context.pop();
		return result;
	}

	internal CodeFriend parse_friend()
	{
		using namespace ECode;
		push_scope();

		eat( TokType::Decl_Friend );
		// friend

		CodeFn function = { nullptr };

		// Type declaration or return type
		CodeType type = parse_type();
		if ( type == Code::Invalid )
		{
			Context.pop();
			return CodeInvalid;
		}
		// friend <Type>

		// Funciton declaration
		if ( currtok.Type == TokType::Identifier )
		{
			// Name
			Token name          = parse_identifier();
			Context.Scope->Name = name;
			// friend <ReturnType> <Name>

			function = parse_function_after_name( ModuleFlag::None, NoCode, NoCode, type, name );

			// Parameter list
			// CodeParam params = parse_params();
			// friend <ReturnType> <Name> ( <Parameters> )

			// function             = make_code();
			// function->Type       = Function_Fwd;
			// function->Name       = get_cached_string( name );
			// function->ReturnType = type;

			// if ( params )
			// function->Params = params;
		}

		CodeComment inline_cmt = NoCode;
		if ( function && function->Type == ECode::Function_Fwd )
		{
			Token stmt_end = currtok;
			eat( TokType::Statement_End );
			// friend <Type>;
			// friend <ReturnType> <Name> ( <Parameters> );

			if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
				inline_cmt = parse_comment();
			// friend <Type>; <InlineCmt>
			// friend <ReturnType> <Name> ( <Parameters> ); <InlineCmt>
		}

		CodeFriend result = (CodeFriend)make_code();
		result->Type      = Friend;

		if ( function )
			result->Declaration = function;
		else
			result->Declaration = type;

		if ( inline_cmt )
			result->InlineCmt = inline_cmt;

		Context.pop();
		return result;
	}

	internal CodeFn parse_function()
	{
		push_scope();

		SpecifierT specs_found[16] { ESpecifier::NumSpecifiers };
		s32        NumSpecifiers  = 0;

		CodeAttributes attributes = { nullptr };
		CodeSpecifiers specifiers = { nullptr };
		ModuleFlag     mflags     = ModuleFlag::None;

		if ( check( TokType::Module_Export ) )
		{
			mflags = ModuleFlag::Export;
			eat( TokType::Module_Export );
		}
		// <export>

		attributes = parse_attributes();
		// <export> <Attributes>

		while ( left && currtok.is_specifier() )
		{
			SpecifierT spec = ESpecifier::to_type( currtok );

			switch ( spec )
			{
				case ESpecifier::Const :
				case ESpecifier::Consteval :
				case ESpecifier::Constexpr :
				case ESpecifier::External_Linkage :
				case ESpecifier::ForceInline :
				case ESpecifier::Inline :
				case ESpecifier::NeverInline :
				case ESpecifier::Static :
					break;

				default :
					log_failure( "Invalid specifier %s for functon\n%s", ESpecifier::to_str( spec ), Context.to_string() );
					Context.pop();
					return CodeInvalid;
			}

			if ( spec == ESpecifier::Const )
				continue;

			specs_found[NumSpecifiers] = spec;
			NumSpecifiers++;
			eat( currtok.Type );
		}

		if ( NumSpecifiers )
		{
			specifiers = def_specifiers( NumSpecifiers, specs_found );
		}
		// <export> <Attributes> <Specifiers>

		CodeType ret_type = parse_type();
		if ( ret_type == Code::Invalid )
		{
			Context.pop();
			return CodeInvalid;
		}
		// <export> <Attributes> <Specifiers> <ReturnType>

		Token name          = parse_identifier();
		Context.Scope->Name = name;
		if ( ! name )
		{
			Context.pop();
			return CodeInvalid;
		}
		// <export> <Attributes> <Specifiers> <ReturnType> <Name>

		CodeFn result = parse_function_after_name( mflags, attributes, specifiers, ret_type, name );
		// <export> <Attributes> <Specifiers> <ReturnType> <Name> ...

		Context.pop();
		return result;
	}

	internal CodeNS parse_namespace()
	{
		push_scope();

		eat( TokType::Decl_Namespace );
		// namespace

		Token name          = parse_identifier();
		Context.Scope->Name = name;
		// namespace <Name>

		CodeBody body = parse_global_nspace( ECode::Namespace_Body );
		if ( body == Code::Invalid )
		{
			Context.pop();
			return CodeInvalid;
		}
		// namespace <Name> { <Body> }

		CodeNS result = (CodeNS)make_code();
		result->Type  = ECode::Namespace;
		result->Name  = get_cached_string( name );

		result->Body  = body;

		Context.pop();
		return result;
	}

	internal CodeOperator parse_operator()
	{
		push_scope();

		CodeAttributes attributes = { nullptr };
		CodeSpecifiers specifiers = { nullptr };
		ModuleFlag     mflags     = ModuleFlag::None;

		SpecifierT specs_found[16] { ESpecifier::NumSpecifiers };
		s32        NumSpecifiers = 0;

		if ( check( TokType::Module_Export ) )
		{
			mflags = ModuleFlag::Export;
			eat( TokType::Module_Export );
		}
		// <export>

		attributes = parse_attributes();
		// <export> <Attributes>

		while ( left && currtok.is_specifier() )
		{
			SpecifierT spec = ESpecifier::to_type( currtok );

			switch ( spec )
			{
				case ESpecifier::Const :
				case ESpecifier::Constexpr :
				case ESpecifier::ForceInline :
				case ESpecifier::Inline :
				case ESpecifier::NeverInline :
				case ESpecifier::Static :
					break;

				default :
					log_failure(
					    "Invalid specifier "
					    "%s"
					    " for operator\n%s",
					    ESpecifier::to_str( spec ),
					    Context.to_string()
					);
					Context.pop();
					return CodeInvalid;
			}

			if ( spec == ESpecifier::Const )
				continue;

			specs_found[NumSpecifiers] = spec;
			NumSpecifiers++;
			eat( currtok.Type );
		}

		if ( NumSpecifiers )
		{
			specifiers = def_specifiers( NumSpecifiers, specs_found );
		}
		// <export> <Attributes> <Specifiers>

		// Parse Return Type
		CodeType ret_type = parse_type();
		// <export> <Attributes> <Specifiers> <ReturnType>

		CodeOperator result = parse_operator_after_ret_type( mflags, attributes, specifiers, ret_type );
		// <export> <Attributes> <Specifiers> <ReturnType> ...

		Context.pop();
		return result;
	}

	internal CodeOpCast parse_operator_cast( CodeSpecifiers specifiers )
	{
		push_scope();

		// Operator's namespace if not within same class.
		Token name = NullToken;
		if ( check( TokType::Identifier ) )
		{
			name = currtok;
			while ( left && currtok.Type == TokType::Identifier )
			{
				eat( TokType::Identifier );
				// <Specifiers> <Qualifier>

				if ( currtok.Type == TokType::Access_StaticSymbol )
					eat( TokType::Access_StaticSymbol );
				// <Specifiers> <Qualifier> ::
			}
			// <Specifiers> <Qualifier> :: ...

			name.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)name.Text;
		}

		eat( TokType::Decl_Operator );
		// <Specifiers> <Qualifier> :: ... operator

		Code type = parse_type();
		// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>

		Context.Scope->Name = { type->Name.Data, type->Name.length() };

		eat( TokType::Capture_Start );
		eat( TokType::Capture_End );
		// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>()

		// TODO(Ed) : operator cast can have const, volatile, l-value, r-value noexecept qualifying specifiers.
		if ( check( TokType::Spec_Const ) )
		{
			if ( specifiers.ast == nullptr )
				specifiers = def_specifier( ESpecifier::Const );

			else
				specifiers.append( ESpecifier::Const );

			eat( TokType::Spec_Const );
		}
		// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const>

		Code        body       = NoCode;
		CodeComment inline_cmt = NoCode;

		if ( check( TokType::BraceCurly_Open ) )
		{
			eat( TokType::BraceCurly_Open );
			// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const> {

			Token body_str = currtok;

			s32 level      = 0;
			while ( left && ( currtok.Type != TokType::BraceCurly_Close || level > 0 ) )
			{
				if ( currtok.Type == TokType::BraceCurly_Open )
					level++;

				else if ( currtok.Type == TokType::BraceCurly_Close )
					level--;

				eat( currtok.Type );
			}
			body_str.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)body_str.Text;

			eat( TokType::BraceCurly_Close );
			// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const> { <Body> }

			body = untyped_str( body_str );
		}
		else
		{
			Token stmt_end = currtok;
			eat( TokType::Statement_End );
			// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const>;

			if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
				inline_cmt = parse_comment();
			// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const>; <InlineCmt>
		}

		CodeOpCast result = (CodeOpCast)make_code();

		if ( name )
			result->Name = get_cached_string( name );

		if ( body )
		{
			result->Type = ECode::Operator_Cast;
			result->Body = body;
		}
		else
		{
			result->Type = ECode::Operator_Cast_Fwd;
		}

		if ( specifiers )
			result->Specs = specifiers;

		result->ValueType = type;

		Context.pop();
		return result;
	}

	internal inline CodeStruct parse_struct( bool inplace_def )
	{
		push_scope();
		CodeStruct result = (CodeStruct)parse_class_struct( TokType::Decl_Struct, inplace_def );
		Context.pop();
		return result;
	}

	internal CodeTemplate parse_template()
	{
#define UseTemplateCapture true

		push_scope();

		ModuleFlag mflags = ModuleFlag::None;

		if ( check( TokType::Module_Export ) )
		{
			mflags = ModuleFlag::Export;
			eat( TokType::Module_Export );
		}
		// <export> template

		eat( TokType::Decl_Template );
		// <export> template

		Code params = parse_params( UseTemplateCapture );
		if ( params == Code::Invalid )
		{
			Context.pop();
			return CodeInvalid;
		}
		// <export> template< <Parameters> >

		Code definition = { nullptr };

		while ( left )
		{
			if ( check( TokType::Decl_Class ) )
			{
				definition = parse_class();
				// <export> template< <Parameters> > class ...
				break;
			}

			if ( check( TokType::Decl_Struct ) )
			{
				definition = parse_struct();
				// <export> template< <Parameters> > struct ...
				break;
			}

			if ( check( TokType::Decl_Union ) )
			{
				definition = parse_union();
				// <export> template< <Parameters> > union ...
				break;
			}

			if ( check( TokType::Decl_Using ) )
			{
				definition = parse_using();
				// <export> template< <Parameters> > using ...
				break;
			}

			// Its either a function or a variable
			Token name                = { nullptr, 0, TokType::Invalid };

			CodeAttributes attributes = { nullptr };
			CodeSpecifiers specifiers = { nullptr };

			bool expects_function     = false;

			SpecifierT specs_found[16] { ESpecifier::NumSpecifiers };
			s32        NumSpecifiers = 0;

			attributes               = parse_attributes();
			// <export> template< <Parameters> > <Attributes>

			// Specifiers Parsing
			{
				while ( left && currtok.is_specifier() )
				{
					SpecifierT spec = ESpecifier::to_type( currtok );

					switch ( spec )
					{
						case ESpecifier::Const :
						case ESpecifier::Constexpr :
						case ESpecifier::Constinit :
						case ESpecifier::External_Linkage :
						case ESpecifier::Global :
						case ESpecifier::Inline :
						case ESpecifier::ForceInline :
						case ESpecifier::Local_Persist :
						case ESpecifier::Mutable :
						case ESpecifier::Static :
						case ESpecifier::Thread_Local :
						case ESpecifier::Volatile :
							break;

						case ESpecifier::Consteval :
							expects_function = true;
							break;

						default :
							log_failure( "Invalid specifier %s for variable or function\n%s", ESpecifier::to_str( spec ), Context.to_string() );
							Context.pop();
							return CodeInvalid;
					}

					// Ignore const it will be handled by the type
					if ( spec == ESpecifier::Const )
						break;

					specs_found[NumSpecifiers] = spec;
					NumSpecifiers++;
					eat( currtok.Type );
				}

				if ( NumSpecifiers )
				{
					specifiers = def_specifiers( NumSpecifiers, specs_found );
				}
				// <export> template< <Parameters> > <Attributes> <Specifiers>
			}


			bool has_context         = Context.Scope && Context.Scope->Prev;
			bool is_in_global_nspace = has_context && str_compare( Context.Scope->Prev->ProcName, "parse_global_nspace" ) == 0;

			// Possible constructor implemented at global file scope.
			if ( is_in_global_nspace )
			{
				Code constructor_destructor = parse_global_nspace_constructor_destructor( specifiers );
				if ( constructor_destructor )
				{
					definition = constructor_destructor;
					// <Attributes> <Specifiers> <Name> :: <Name> <Type> () { ... }
					break;
				}
			}

			// Possible user Defined operator casts
			if ( is_in_global_nspace )
			{
				bool found_operator_cast_outside_class_implmentation = false;
				s32  idx                                             = Context.Tokens.Idx;

				for ( ; idx < Context.Tokens.Arr.num(); idx++ )
				{
					Token tok = Context.Tokens[idx];

					if ( tok.Type == TokType::Identifier )
					{
						idx++;
						tok = Context.Tokens[idx];
						if ( tok.Type == TokType::Access_StaticSymbol )
							continue;

						break;
					}

					if ( tok.Type == TokType::Decl_Operator )
						found_operator_cast_outside_class_implmentation = true;

					break;
				}

				if ( found_operator_cast_outside_class_implmentation )
				{
					definition = parse_operator_cast( specifiers );
					// <Attributes> <Specifiers> <Name> :: operator <Type> () { ... }
					break;
				}
			}

			definition = parse_operator_function_or_variable( expects_function, attributes, specifiers );
			// <export> template< <Parameters> > <Attributes> <Specifiers> ...
			break;
		}

		CodeTemplate result = (CodeTemplate)make_code();
		result->Type        = ECode::Template;
		result->Params      = params;
		result->Declaration = definition;
		result->ModuleFlags = mflags;

		Context.pop();
		return result;
#undef UseTemplateCapture
	}

	/*
	    This is a mess, but it works
	    Parsing typename is arguably one of the worst aspects of C/C++.
	    This is an effort to parse it without a full blown or half-blown compliant parser.

	    Recursive function typenames are not supported, if they are used expect it to serailize just fine, but validation with AST::is_equal
	    will not be possible if two ASTs share the same definiton but the formatting is slightly different:
	    AST_1->Name: (* A    ( int   (*)    (short a,unsigned b,long c) ) )
	    AST_2->Name: (* A       ( int(*)(short a, unsigned b, long c) ) )

	    The excess whitespace cannot be stripped however, because there is no semantic awareness within the first capture group.
	*/
	internal CodeType parse_type( bool from_template, bool* typedef_is_function )
	{
		push_scope();

		Token context_tok = prevtok;

		SpecifierT specs_found[16] { ESpecifier::NumSpecifiers };
		s32        NumSpecifiers = 0;

		Token name               = { nullptr, 0, TokType::Invalid };

		// Attributes are assumed to be before the type signature
		CodeAttributes attributes = parse_attributes();
		// <Attributes>

		// Prefix specifiers
		while ( left && currtok.is_specifier() )
		{
			SpecifierT spec = ESpecifier::to_type( currtok );

			if ( spec != ESpecifier::Const )
			{
				log_failure( "Error, invalid specifier used in type definition: %s\n%s", currtok.Text, Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			specs_found[NumSpecifiers] = spec;
			NumSpecifiers++;
			eat( currtok.Type );
		}
		// <Attributes> <Specifiers>

		if ( left == 0 )
		{
			log_failure( "Error, unexpected end of type definition\n%s", Context.to_string() );
			Context.pop();
			return CodeInvalid;
		}

		if ( from_template && currtok.Type == TokType::Decl_Class )
		{
			// If a value's type is being parsed from a template, class can be used instead of typename.
			name = currtok;
			eat( TokType::Decl_Class );
			// <class>
		}

		// All kinds of nonsense can makeup a type signature, first we check for a in-place definition of a class, enum, struct, or union
		else if ( currtok.Type == TokType::Decl_Class || currtok.Type == TokType::Decl_Enum || currtok.Type == TokType::Decl_Struct
		          || currtok.Type == TokType::Decl_Union )
		{
			eat( currtok.Type );
			// <Attributes> <Specifiers> <class, enum, struct, union>

			name = parse_identifier();

			// name.Length = ( ( sptr )currtok.Text + currtok.Length ) - ( sptr )name.Text;
			// eat( TokType::Identifier );
			Context.Scope->Name = name;
			// <Attributes> <Specifiers> <class, enum, struct, union> <Name>
		}

// Decltype draft implementaiton
#if 0
else if ( currtok.Type == TokType::DeclType )
{
	// Will have a capture and its own parsing rules, were going to just shove everything in a string (for now).
	name = currtok;
	eat( TokType::DeclType );
	// <Attributes> <Specifiers> decltype

	eat( TokType::Capture_Start );
	while ( left && currtok.Type != TokType::Capture_End )
	{
		if ( currtok.Type == TokType::Capture_Start )
			level++;

		if ( currtok.Type == TokType::Capture_End )
			level--;

		eat( currtok.Type );
	}
	eat( TokType::Capture_End );

	name.Length = ( (sptr)currtok.Text + currtok.Length ) - (sptr)name.Text;
	Context.Scope->Name = name;
	// <Attributes> <Specifiers> decltype( <Expression > )
}
#endif

		// Check if native type keywords are used, eat them for the signature.
		// <attributes> <specifiers> <native types ...> ...
		else if ( currtok.Type >= TokType::Type_Unsigned && currtok.Type <= TokType::Type_MS_W64 )
		{
			// TODO(Ed) : Review this... Its necessary for parsing however the algo's path to this is lost...
			name = currtok;
			eat( currtok.Type );

			while ( left && currtok.Type >= TokType::Type_Unsigned && currtok.Type <= TokType::Type_MS_W64 )
			{
				eat( currtok.Type );
			}

			name.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)name.Text;
			// <Attributes> <Specifiers> <Compound type expression>
		}
		else if ( currtok.Type == TokType::Type_Typename )
		{
			name = currtok;
			eat( TokType::Type_Typename );
			// <typename>

			if ( ! from_template )
			{
				name                = parse_identifier();
				Context.Scope->Name = name;
				if ( ! name )
				{
					log_failure( "Error, failed to type signature\n%s", Context.to_string() );
					Context.pop();
					return CodeInvalid;
				}
			}
		}

		// The usual Identifier type signature that may have namespace qualifiers
		else
		{
			name                = parse_identifier();
			Context.Scope->Name = name;
			if ( ! name )
			{
				log_failure( "Error, failed to type signature\n%s", Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}
			// <Attributes> <Specifiers> <Qualifier ::> <Identifier>
			// <Attributes> <Specifiers> <Identifier>
		}

		// Suffix specifiers for typename.
		while ( left && currtok.is_specifier() )
		{
			SpecifierT spec = ESpecifier::to_type( currtok );

			if ( spec != ESpecifier::Const && spec != ESpecifier::Ptr && spec != ESpecifier::Ref && spec != ESpecifier::RValue )
			{
				log_failure( "Error, invalid specifier used in type definition: %s\n%s", currtok.Text, Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			specs_found[NumSpecifiers] = spec;
			NumSpecifiers++;
			eat( currtok.Type );
		}

#ifdef GEN_USE_NEW_TYPENAME_PARSING
		if ( NumSpecifiers )
		{
			specifiers    = def_specifiers( NumSpecifiers, specs_found );
			NumSpecifiers = 0;
		}
#endif
		// <Attributes> <Specifiers> <Identifier> <Specifiers>

		// For function type signatures
		CodeType  return_type = NoCode;
		CodeParam params      = NoCode;

#ifdef GEN_USE_NEW_TYPENAME_PARSING
		CodeParam params_nested = NoCode;
#endif

		bool   is_function_typename = false;
		Token* last_capture         = nullptr;
		{
			Token* scanner = Context.Tokens.Arr + Context.Tokens.Idx;

			// An identifier being within a typename's signature only occurs if were parsing a typename for a typedef.
			if ( typedef_is_function && scanner->Type == TokType::Identifier )
			{
				is_function_typename = true;
				++scanner;
			}
			is_function_typename = scanner->Type == TokType::Capture_Start;

			Token* first_capture = scanner;
			if ( is_function_typename )
			{
				// Go to the end of the signature
				while ( scanner->Type != TokType::Statement_End && scanner->Type != TokType::BraceCurly_Open )
					++scanner;

				// Go back to the first capture start found
				while ( scanner->Type != TokType::Capture_Start )
					--scanner;

				last_capture = scanner;
			}

			bool has_context   = Context.Scope && Context.Scope->Prev;
			bool is_for_opcast = has_context && str_compare( Context.Scope->Prev->ProcName, "parse_operator_cast" ) == 0;
			if ( is_for_opcast && is_function_typename && last_capture )
			{
				// If we're parsing for an operator cast, having one capture start is not enough
				// we need to make sure that the capture is not for the cast definition.
				is_function_typename = false;

				if ( last_capture == first_capture )
				{
					// The capture start in question is the first capture start, this is not a function typename.
					is_function_typename = false;
				}
			}
		}

		if ( is_function_typename )
		{
			// We're dealing with a function typename.
			// By this point, decltype should have been taken care of for return type, along with any all its specifiers

			// The previous information with exception to attributes will be considered the return type.
			return_type       = (CodeType)make_code();
			return_type->Type = ECode::Typename;

			// String
			// name_stripped = String::make( GlobalAllocator, name );
			// name_stripped.strip_space();
			return_type->Name = get_cached_string( name );

#ifdef GEN_USE_NEW_TYPENAME_PARSING
			if ( specifiers )
			{
				return_type->Specs = specifiers;
				specifiers         = nullptr;
			}

#else
			if ( NumSpecifiers )
				return_type->Specs = def_specifiers( NumSpecifiers, (SpecifierT*)specs_found );

			// Reset specifiers, the function itself will have its own suffix specifiers possibly.
			NumSpecifiers = 0;
#endif
			// <Attributes> <ReturnType>

			name = { nullptr, 0, TokType::Invalid };

			// The next token can either be a capture for the identifier or it could be the identifier exposed.
			if ( ! check( TokType::Capture_Start ) )
			{
				// Started with an identifier immeidately, which means its of the format: <ReturnType> <identifier> <capture>;
				name = parse_identifier();
			}
			// <Attributes> <ReturnType> <Identifier>

			// If the next token is a capture start and is not the last capture, then we're dealing with function typename whoose identifier is within the
			// capture.
			else if ( ( Context.Tokens.Arr + Context.Tokens.Idx ) != last_capture )
			{
				// WIP : Possible alternative without much pain...
				// If this were to be parsed properly...
				// Eat Capture Start
				// Deal with possible binding specifiers (*, &, &&) and modifiers on those bindings (const, volatile)
				// Parse specifiers for the typename with an optional identifier,
				// we can shove these specific specifiers into a specs, and then leave the suffix ones for a separate member of the AST.
				// Parse immeidate capture which would be with parse_params()
				// Eat Capture End
#ifdef GEN_USE_NEW_TYPENAME_PARSING
				eat( TokType::Capture_Start );
				// <Attributes> <ReturnType> (

				// Binding specifiers
				while ( left && currtok.is_specifier() )
				{
					SpecifierT spec = ESpecifier::to_type( currtok );

					if ( spec != ESpecifier::Ptr && spec != ESpecifier::Ref && spec != ESpecifier::RValue )
					{
						log_failure( "Error, invalid specifier used in type definition: %s\n%s", currtok.Text, Context.to_string() );
						Context.pop();
						return CodeInvalid;
					}

					specs_found[NumSpecifiers] = spec;
					NumSpecifiers++;
					eat( currtok.Type );
				}

				if ( NumSpecifiers )
				{
					specifiers = def_specifiers( NumSpecifiers, specs_found );
				}
				NumSpecifiers = 0;
				// <Attributes> <ReturnType> ( <Specifiers>

				if ( check( TokType::Identifier ) )
					name = parse_identifier();
				// <Attributes> <ReturnType> ( <Specifiers> <Identifier>

				// Immeidate parameters

				if ( check( TokType::Capture_Start ) )
					params_nested = parse_params();
				// <Attributes> <ReturnType> ( <Specifiers> <Identifier> ( <Parameters> )

				eat( TokType::Capture_End );
				// <Attributes> <ReturnType> ( <Specifiers> <Identifier> ( <Parameters> ) )

#else
				// Starting immediatley with a capture, most likely declaring a typename for a member function pointer.
				// Everything within this capture will just be shoved into the name field including the capture tokens themselves.
				name = currtok;

				eat( TokType::Capture_Start );
				// <Attributes> <ReturnType> (

				s32 level = 0;
				while ( left && ( currtok.Type != TokType::Capture_End || level > 0 ) )
				{
					if ( currtok.Type == TokType::Capture_Start )
						level++;

					if ( currtok.Type == TokType::Capture_End )
						level--;

					eat( currtok.Type );
				}
				eat( TokType::Capture_End );
				// <Attributes> <ReturnType> ( <Expression> )

				name.Length = ( (sptr)prevtok.Text + prevtok.Length ) - (sptr)name.Text;
#endif
			}

			// Were now dealing with the parameters of the function
			params = parse_params();
			// <Attributes> <ReturnType> <All Kinds of nonsense> ( <Parameters> )

			// Look for suffix specifiers for the function
			while ( left && currtok.is_specifier() )
			{
				SpecifierT spec = ESpecifier::to_type( currtok );

				if ( spec != ESpecifier::Const
				     // TODO : Add support for NoExcept, l-value, volatile, l-value, etc
				     // && spec != ESpecifier::NoExcept
				     && spec != ESpecifier::RValue )
				{
					log_failure( "Error, invalid specifier used in type definition: %s\n%s", currtok.Text, Context.to_string() );
					Context.pop();
					return CodeInvalid;
				}

				specs_found[NumSpecifiers] = spec;
				NumSpecifiers++;
				eat( currtok.Type );
			}

#ifdef GEN_USE_NEW_TYPENAME_PARSING
			if ( NumSpecifiers )
			{
				func_suffix_specs = def_specifiers( NumSpecifiers, specs_found );
				NumSpecifiers     = 0;
			}
#endif
			// <Attributes> <ReturnType> <All Kinds of nonsense> ( <Parameters> ) <Specifiers>
		}
		// <Attributes> <All Kinds of nonsense>

		bool is_param_pack = false;
		if ( check( TokType::Varadic_Argument ) )
		{
			is_param_pack = true;
			eat( TokType::Varadic_Argument );
			// <Attributes> <All kinds of nonsense> ...
		}

		using namespace ECode;

		CodeType result = (CodeType)make_code();
		result->Type    = Typename;
		// result->Token = Context.Scope->Start;

		// Need to wait until were using the new parsing method to do this.
		String name_stripped = strip_formatting( name, strip_formatting_dont_preserve_newlines );

		// name_stripped.strip_space();

#ifdef GEN_USE_NEW_TYPENAME_PARSING
		if ( params_nested )
		{
			name_stripped.append( params_nested->to_string() );
		}
#endif

		result->Name = get_cached_string( name_stripped );

		if ( attributes )
			result->Attributes = attributes;

#ifdef GEN_USE_NEW_TYPENAME_PARSING
		if ( specifiers )
		{
			result->Specs = specifiers;
		}

		if ( func_suffix_specs )
		{
			result->FuncSuffixSpecs = func_suffix_specs;
		}
#else
		if ( NumSpecifiers )
		{
			Code specifiers = def_specifiers( NumSpecifiers, (SpecifierT*)specs_found );
			result->Specs   = specifiers;
		}
#endif

		if ( is_param_pack )
			result->IsParamPack = true;

		// These following are only populated if its a function typename
		if ( return_type )
		{
			result->ReturnType = return_type;

			if ( typedef_is_function )
				*typedef_is_function = true;
		}

		if ( params )
			result->Params = params;

		Context.pop();
		return result;
	}

	internal CodeTypedef parse_typedef()
	{
		push_scope();

		bool  is_function = false;
		Token name        = { nullptr, 0, TokType::Invalid };
		Code  array_expr  = { nullptr };
		Code  type        = { nullptr };

		ModuleFlag mflags = ModuleFlag::None;

		if ( check( TokType::Module_Export ) )
		{
			mflags = ModuleFlag::Export;
			eat( TokType::Module_Export );
		}
		// <ModuleFlags>

		eat( TokType::Decl_Typedef );
		// <ModuleFlags> typedef

		constexpr bool from_typedef = true;

#if GEN_PARSER_DISABLE_MACRO_TYPEDEF
		if ( false )
#else
		if ( check( TokType::Preprocess_Macro ) )
#endif
		{
			type                = t_empty;
			name                = currtok;
			Context.Scope->Name = name;
			eat( TokType::Preprocess_Macro );
			// <ModuleFalgs> typedef <Preprocessed_Macro>
		}
		else
		{
			bool is_complicated = currtok.Type == TokType::Decl_Enum || currtok.Type == TokType::Decl_Class || currtok.Type == TokType::Decl_Struct
			    || currtok.Type == TokType::Decl_Union;

			// This code is highly correlated with parse_complicated_definition
			if ( is_complicated )
			{
				TokArray tokens = Context.Tokens;

				s32 idx         = tokens.Idx;
				s32 level       = 0;
				for ( ; idx < tokens.Arr.num(); idx++ )
				{
					if ( tokens[idx].Type == TokType::BraceCurly_Open )
						level++;

					if ( tokens[idx].Type == TokType::BraceCurly_Close )
						level--;

					if ( level == 0 && tokens[idx].Type == TokType::Statement_End )
						break;
				}

				if ( ( idx - 2 ) == tokens.Idx )
				{
					// Its a forward declaration only
					type = parse_forward_or_definition( currtok.Type, from_typedef );
					// <ModuleFalgs> typedef <UnderlyingType: Forward Decl>
				}

				Token tok = tokens[idx - 1];
				if ( tok.Type == TokType::Identifier )
				{
					tok                 = tokens[idx - 2];

					bool is_indirection = tok.Type == TokType::Ampersand || tok.Type == TokType::Star;

					bool ok_to_parse    = false;

					if ( tok.Type == TokType::BraceCurly_Close )
					{
						// Its an inplace definition
						// typdef <which> <type_identifier> { ... } <identifier>;
						ok_to_parse = true;
					}
					else if ( tok.Type == TokType::Identifier && tokens[idx - 3].Type == TokType::Decl_Struct )
					{
						// Its a variable with type ID using struct namespace.
						// <which> <type_identifier> <identifier>;
						ok_to_parse = true;
					}
					else if ( is_indirection )
					{
						// Its a indirection type with type ID using struct namespace.
						// <which> <type_identifier>* <identifier>;
						ok_to_parse = true;
					}

					if ( ! ok_to_parse )
					{
						log_failure( "Unsupported or bad member definition after struct declaration\n%s", Context.to_string() );
						Context.pop();
						return CodeInvalid;
					}

					// TODO(Ed) : I'm not sure if I have to use parse_type here, I'd rather not as that would complicate parse_type.
					// type = parse_type();
					type = parse_forward_or_definition( currtok.Type, from_typedef );
					// <ModuleFalgs> typedef <UnderlyingType>
				}
				else if ( tok.Type == TokType::BraceCurly_Close )
				{
					// Its a definition
					// <which> { ... };
					type = parse_forward_or_definition( currtok.Type, from_typedef );
					// <ModuleFalgs> typedef <UnderlyingType>
				}
				else if ( tok.Type == TokType::BraceSquare_Close )
				{
					// Its an array definition
					// <which> <type_identifier> <identifier> [ ... ];
					type = parse_type();
					// <ModuleFalgs> typedef <UnderlyingType>
				}
				else
				{
					log_failure( "Unsupported or bad member definition after struct declaration\n%s", Context.to_string() );
					Context.pop();
					return CodeInvalid;
				}
			}
			else
			{
				bool from_template = false;
				type               = parse_type( from_template, &is_function );
				// <ModuleFalgs> typedef <UnderlyingType>
			}

			if ( check( TokType::Identifier ) )
			{
				name = currtok;
				eat( TokType::Identifier );
				// <ModuleFalgs> typedef <UnderlyingType> <Name>
			}
			else if ( ! is_function )
			{
				log_failure( "Error, expected identifier for typedef\n%s", Context.to_string() );
				Context.pop();
				return CodeInvalid;
			}

			array_expr = parse_array_decl();
			// <UnderlyingType> + <ArrayExpr>
		}

		Token stmt_end = currtok;
		eat( TokType::Statement_End );
		// <ModuleFalgs> typedef <UnderlyingType> <Name>;

		CodeComment inline_cmt = NoCode;
		if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
			inline_cmt = parse_comment();
		// <ModuleFalgs> typedef <UnderlyingType> <Name> <ArrayExpr>; <InlineCmt>

		using namespace ECode;

		CodeTypedef result  = (CodeTypedef)make_code();
		result->Type        = Typedef;
		result->ModuleFlags = mflags;

		if ( is_function )
		{
			result->Name       = type->Name;
			result->IsFunction = true;
		}
		else
		{
			result->Name       = get_cached_string( name );
			result->IsFunction = false;
		}

		if ( type )
		{
			result->UnderlyingType         = type;
			result->UnderlyingType->Parent = rcast( AST*, result.ast );
		}
		// Type needs to be aware of its parent so that it can be serialized properly.

		if ( type->Type == Typename && array_expr && array_expr->Type != Invalid )
			type.cast<CodeType>()->ArrExpr = array_expr;

		if ( inline_cmt )
			result->InlineCmt = inline_cmt;

		Context.pop();
		return result;
	}

	internal neverinline CodeUnion parse_union( bool inplace_def )
	{
		push_scope();

		ModuleFlag mflags = ModuleFlag::None;

		if ( check( TokType::Module_Export ) )
		{
			mflags = ModuleFlag::Export;
			eat( TokType::Module_Export );
		}
		// <ModuleFlags>

		eat( TokType::Decl_Union );
		// <ModuleFlags> union

		CodeAttributes attributes = parse_attributes();
		// <ModuleFlags> union <Attributes>

		StrC name = { 0, nullptr };
		if ( check( TokType::Identifier ) )
		{
			name                = currtok;
			Context.Scope->Name = currtok;
			eat( TokType::Identifier );
		}
		// <ModuleFlags> union <Attributes> <Name>

		CodeBody body = { nullptr };

		eat( TokType::BraceCurly_Open );
		// <ModuleFlags> union <Attributes> <Name> {

		body       = make_code();
		body->Type = ECode::Union_Body;

		while ( ! check_noskip( TokType::BraceCurly_Close ) )
		{
			if ( currtok_noskip.Type == TokType::Preprocess_Hash )
				eat( TokType::Preprocess_Hash );

			Code member = { nullptr };
			switch ( currtok_noskip.Type )
			{
				case TokType::NewLine :
					member = fmt_newline;
					eat( TokType::NewLine );
					break;

				case TokType::Comment :
					member = parse_comment();
					break;

					// TODO(Ed) : Unions can have constructors and destructors

				case TokType::Decl_Class :
					member = parse_complicated_definition( TokType::Decl_Class );
					break;

				case TokType::Decl_Enum :
					member = parse_complicated_definition( TokType::Decl_Enum );
					break;

				case TokType::Decl_Struct :
					member = parse_complicated_definition( TokType::Decl_Struct );
					break;

				case TokType::Decl_Union :
					member = parse_complicated_definition( TokType::Decl_Union );
					break;

				case TokType::Preprocess_Define :
					member = parse_define();
					break;

				case TokType::Preprocess_If :
				case TokType::Preprocess_IfDef :
				case TokType::Preprocess_IfNotDef :
				case TokType::Preprocess_ElIf :
					member = parse_preprocess_cond();
					break;

				case TokType::Preprocess_Else :
					member = preprocess_else;
					eat( TokType::Preprocess_Else );
					break;

				case TokType::Preprocess_EndIf :
					member = preprocess_endif;
					eat( TokType::Preprocess_EndIf );
					break;

				case TokType::Preprocess_Macro :
					member = parse_simple_preprocess( TokType::Preprocess_Macro );
					break;

				case TokType::Preprocess_Pragma :
					member = parse_pragma();
					break;

				case TokType::Preprocess_Unsupported :
					member = parse_simple_preprocess( TokType::Preprocess_Unsupported );
					break;

				default :
					member = parse_variable();
					break;
			}

			if ( member )
				body.append( member );
		}
		// <ModuleFlags> union <Attributes> <Name> { <Body>

		eat( TokType::BraceCurly_Close );
		// <ModuleFlags> union <Attributes> <Name> { <Body> }

		if ( ! inplace_def )
			eat( TokType::Statement_End );
		// <ModuleFlags> union <Attributes> <Name> { <Body> };

		CodeUnion result    = (CodeUnion)make_code();
		result->Type        = ECode::Union;
		result->ModuleFlags = mflags;

		if ( name )
			result->Name = get_cached_string( name );

		if ( body )
			result->Body = body;

		if ( attributes )
			result->Attributes = attributes;

		Context.pop();
		return result;
	}

	internal CodeUsing parse_using()
	{
		push_scope();

		SpecifierT specs_found[16] { ESpecifier::Invalid };
		s32        NumSpecifiers  = 0;

		Token    name             = { nullptr, 0, TokType::Invalid };
		Code     array_expr       = { nullptr };
		CodeType type             = { nullptr };

		bool is_namespace         = false;

		ModuleFlag     mflags     = ModuleFlag::None;
		CodeAttributes attributes = { nullptr };

		if ( check( TokType::Module_Export ) )
		{
			mflags = ModuleFlag::Export;
			eat( TokType::Module_Export );
		}
		// <ModuleFlags>

		eat( TokType::Decl_Using );
		// <ModuleFlags> using

		if ( currtok.Type == TokType::Decl_Namespace )
		{
			is_namespace = true;
			eat( TokType::Decl_Namespace );
			// <ModuleFlags> using namespace
		}

		name                = currtok;
		Context.Scope->Name = name;
		eat( TokType::Identifier );
		// <ModuleFlags> using <namespace> <Name>

		if ( ! is_namespace )
		{
			if ( bitfield_is_equal( u32, currtok.Flags, TF_Assign ) )
			{
				attributes = parse_attributes();
				// <ModuleFlags> using <Name> <Attributes>

				eat( TokType::Operator );
				// <ModuleFlags> using <Name> <Attributes> =

				type = parse_type();
				// <ModuleFlags> using <Name> <Attributes> = <UnderlyingType>

				array_expr = parse_array_decl();
				// <UnderlyingType> + <ArrExpr>
			}
		}

		Token stmt_end = currtok;
		eat( TokType::Statement_End );
		// <ModuleFlags> using <namespace> <Attributes> <Name> = <UnderlyingType>;

		CodeComment inline_cmt = NoCode;
		if ( currtok_noskip.Type == TokType::Comment && currtok_noskip.Line == stmt_end.Line )
		{
			inline_cmt = parse_comment();
		}
		// <ModuleFlags> using <namespace> <Attributes> <Name> = <UnderlyingType>; <InlineCmt>

		using namespace ECode;

		CodeUsing result    = (CodeUsing)make_code();
		result->Name        = get_cached_string( name );
		result->ModuleFlags = mflags;

		if ( is_namespace )
		{
			result->Type = Using_Namespace;
		}
		else
		{
			result->Type = Using;

			if ( type )
				result->UnderlyingType = type;

			if ( array_expr )
				type->ArrExpr = array_expr;

			if ( attributes )
				result->Attributes = attributes;

			if ( inline_cmt )
				result->InlineCmt = inline_cmt;
		}

		Context.pop();
		return result;
	}

	internal CodeVar parse_variable()
	{
		push_scope();

		SpecifierT specs_found[16] { ESpecifier::NumSpecifiers };
		s32        NumSpecifiers  = 0;

		ModuleFlag     mflags     = ModuleFlag::None;
		CodeAttributes attributes = { nullptr };
		CodeSpecifiers specifiers = { nullptr };

		if ( check( TokType::Module_Export ) )
		{
			mflags = ModuleFlag::Export;
			eat( TokType::Module_Export );
		}
		// <ModuleFlags>

		attributes = parse_attributes();
		// <ModuleFlags> <Attributes>

		while ( left && currtok.is_specifier() )
		{
			SpecifierT spec = ESpecifier::to_type( currtok );

			switch ( spec )
			{
				case ESpecifier::Const :
				case ESpecifier::Constexpr :
				case ESpecifier::Constinit :
				case ESpecifier::External_Linkage :
				case ESpecifier::Global :
				case ESpecifier::Inline :
				case ESpecifier::Local_Persist :
				case ESpecifier::Mutable :
				case ESpecifier::Static :
				case ESpecifier::Thread_Local :
				case ESpecifier::Volatile :
					break;

				default :
					log_failure( "Invalid specifier %s for variable\n%s", ESpecifier::to_str( spec ), Context.to_string() );
					Context.pop();
					return CodeInvalid;
			}

			// Ignore const specifiers, they're handled by the type
			if ( spec == ESpecifier::Const )
				break;

			specs_found[NumSpecifiers] = spec;
			NumSpecifiers++;
			eat( currtok.Type );
		}

		if ( NumSpecifiers )
		{
			specifiers = def_specifiers( NumSpecifiers, specs_found );
		}
		// <ModuleFlags> <Attributes> <Specifiers>

		CodeType type = parse_type();
		// <ModuleFlags> <Attributes> <Specifiers> <ValueType>

		if ( type == Code::Invalid )
			return CodeInvalid;

		Context.Scope->Name = parse_identifier();
		// <ModuleFlags> <Attributes> <Specifiers> <ValueType> <Name>

		CodeVar result = parse_variable_after_name( mflags, attributes, specifiers, type, Context.Scope->Name );
		// Regular  : <ModuleFlags> <Attributes> <Specifiers> <ValueType> <Name>                  = <Value>; <InlineCmt>
		// Bitfield : <ModuleFlags> <Attributes> <Specifiers> <ValueType> <Name> : <BitfieldSize> = <Value>; <InlineCmt>

		Context.pop();
		return result;
	}

	// namespace parser
}    // namespace parser

// Publically Exposed Interface

CodeClass parse_class( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	push_scope();
	CodeClass result = (CodeClass)parse_class_struct( TokType::Decl_Class );
	Context.pop();
	return result;
}

CodeConstructor parse_constructor( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	// TODO(Ed): Constructors can have prefix attributes

	CodeSpecifiers specifiers;
	SpecifierT     specs_found[16] { ESpecifier::NumSpecifiers };
	s32            NumSpecifiers = 0;

	while ( left && currtok.is_specifier() )
	{
		SpecifierT spec = ESpecifier::to_type( currtok );

		b32 ignore_spec = false;

		switch ( spec )
		{
			case ESpecifier::Constexpr :
			case ESpecifier::Explicit :
			case ESpecifier::Inline :
			case ESpecifier::ForceInline :
			case ESpecifier::NeverInline :
				break;

			case ESpecifier::Const :
				ignore_spec = true;
				break;

			default :
				log_failure( "Invalid specifier %s for variable\n%s", ESpecifier::to_str( spec ), Context.to_string() );
				Context.pop();
				return CodeInvalid;
		}

		// Every specifier after would be considered part of the type type signature
		if ( ignore_spec )
			break;

		specs_found[NumSpecifiers] = spec;
		NumSpecifiers++;
		eat( currtok.Type );
	}

	if ( NumSpecifiers )
	{
		specifiers = def_specifiers( NumSpecifiers, specs_found );
		// <specifiers> ...
	}

	Context.Tokens         = toks;
	CodeConstructor result = parse_constructor( specifiers );
	return result;
}

CodeDestructor parse_destructor( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	// TODO(Ed): Destructors can have prefix attributes
	// TODO(Ed): Destructors can have virtual

	Context.Tokens        = toks;
	CodeDestructor result = parse_destructor();
	return result;
}

CodeEnum parse_enum( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
	{
		Context.pop();
		return CodeInvalid;
	}

	Context.Tokens = toks;
	return parse_enum();
}

CodeBody parse_export_body( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_export_body();
}

CodeExtern parse_extern_link( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_extern_link();
}

CodeFriend parse_friend( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_friend();
}

CodeFn parse_function( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return (CodeFn)parse_function();
}

CodeBody parse_global_body( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	push_scope();
	CodeBody result = parse_global_nspace( ECode::Global_Body );
	Context.pop();
	return result;
}

CodeNS parse_namespace( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_namespace();
}

CodeOperator parse_operator( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return (CodeOperator)parse_operator();
}

CodeOpCast parse_operator_cast( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_operator_cast();
}

CodeStruct parse_struct( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	push_scope();
	CodeStruct result = (CodeStruct)parse_class_struct( TokType::Decl_Struct );
	Context.pop();
	return result;
}

CodeTemplate parse_template( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_template();
}

CodeType parse_type( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_type();
}

CodeTypedef parse_typedef( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_typedef();
}

CodeUnion parse_union( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_union();
}

CodeUsing parse_using( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_using();
}

CodeVar parse_variable( StrC def )
{
	check_parse_args( def );
	using namespace parser;

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return CodeInvalid;

	Context.Tokens = toks;
	return parse_variable();
}

// Undef helper macros
#undef check_parse_args
#undef currtok
#undef prevtok
#undef nexttok
#undef eat
#undef left
#undef check
#undef push_scope

sw token_fmt_va( char* buf, uw buf_size, s32 num_tokens, va_list va )
{
	char const* buf_begin = buf;
	sw          remaining = buf_size;

	local_persist Arena tok_map_arena;

	HashTable<StrC> tok_map;
	{
		local_persist char tok_map_mem[TokenFmt_TokenMap_MemSize];

		tok_map_arena = Arena::init_from_memory( tok_map_mem, sizeof( tok_map_mem ) );
		tok_map       = HashTable<StrC>::init( tok_map_arena );

		s32 left      = num_tokens - 1;

		while ( left-- )
		{
			char const* token = va_arg( va, char const* );
			StrC        value = va_arg( va, StrC );

			u32 key           = crc32( token, str_len( token ) );

			tok_map.set( key, value );
		}
	}

	char const* fmt     = va_arg( va, char const* );
	char        current = *fmt;

	while ( current )
	{
		sw len = 0;

		while ( current && current != '<' && remaining )
		{
			*buf = *fmt;
			buf++;
			fmt++;
			remaining--;

			current = *fmt;
		}

		if ( current == '<' )
		{
			char const* scanner = fmt + 1;

			s32 tok_len         = 0;

			while ( *scanner != '>' )
			{
				tok_len++;
				scanner++;
			}

			char const* token = fmt + 1;

			u32   key         = crc32( token, tok_len );
			StrC* value       = tok_map.get( key );

			if ( value )
			{
				sw          left = value->Len;
				char const* str  = value->Ptr;

				while ( left-- )
				{
					*buf = *str;
					buf++;
					str++;
					remaining--;
				}

				scanner++;
				fmt     = scanner;
				current = *fmt;
				continue;
			}

			*buf = *fmt;
			buf++;
			fmt++;
			remaining--;

			current = *fmt;
		}
	}

	tok_map.clear();
	tok_map_arena.free();

	sw result = buf_size - remaining;

	return result;
}

Code untyped_str( StrC content )
{
	if ( content.Len == 0 )
	{
		log_failure( "untyped_str: empty string" );
		return CodeInvalid;
	}

	Code result     = make_code();
	result->Name    = get_cached_string( content );
	result->Type    = ECode::Untyped;
	result->Content = result->Name;

	if ( result->Name == nullptr )
	{
		log_failure( "untyped_str: could not cache string" );
		return CodeInvalid;
	}

	return result;
}

Code untyped_fmt( char const* fmt, ... )
{
	if ( fmt == nullptr )
	{
		log_failure( "untyped_fmt: null format string" );
		return CodeInvalid;
	}

	local_persist thread_local char buf[GEN_PRINTF_MAXLEN] = { 0 };

	va_list va;
	va_start( va, fmt );
	sw length = str_fmt_va( buf, GEN_PRINTF_MAXLEN, fmt, va );
	va_end( va );

	Code result     = make_code();
	result->Name    = get_cached_string( { str_len( fmt, MaxNameLength ), fmt } );
	result->Type    = ECode::Untyped;
	result->Content = get_cached_string( { length, buf } );

	if ( result->Name == nullptr )
	{
		log_failure( "untyped_fmt: could not cache string" );
		return CodeInvalid;
	}

	return result;
}

Code untyped_token_fmt( s32 num_tokens, ... )
{
	if ( num_tokens == 0 )
	{
		log_failure( "untyped_token_fmt: zero tokens" );
		return CodeInvalid;
	}

	local_persist thread_local char buf[GEN_PRINTF_MAXLEN] = { 0 };

	va_list va;
	va_start( va, num_tokens );
	sw length = token_fmt_va( buf, GEN_PRINTF_MAXLEN, num_tokens, va );
	va_end( va );

	Code result     = make_code();
	result->Name    = get_cached_string( { length, buf } );
	result->Type    = ECode::Untyped;
	result->Content = result->Name;

	if ( result->Name == nullptr )
	{
		log_failure( "untyped_fmt: could not cache string" );
		return CodeInvalid;
	}

	return result;
}

#pragma endregion Parsing

#pragma endregion Interface

GEN_NS_END

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
