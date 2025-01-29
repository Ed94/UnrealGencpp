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

#if ! defined(GEN_DONT_ENFORCE_GEN_TIME_GUARD) && ! defined(GEN_TIME)
#	error Gen.hpp : GEN_TIME not defined
#endif

#include "gen.hpp"

GEN_NS_BEGIN

#pragma region StaticData
GEN_API global Context* _ctx;
GEN_API global u32      context_counter;

#pragma region Constants
GEN_API global Macro enum_underlying_macro;

GEN_API global Code Code_Global;
GEN_API global Code Code_Invalid;

GEN_API global Code access_public;
GEN_API global Code access_protected;
GEN_API global Code access_private;

GEN_API global CodeAttributes attrib_api_export;
GEN_API global CodeAttributes attrib_api_import;

GEN_API global Code module_global_fragment;
GEN_API global Code module_private_fragment;

GEN_API global Code fmt_newline;

GEN_API global CodeParams param_varadic;

GEN_API global CodePragma pragma_once;

GEN_API global CodePreprocessCond preprocess_else;
GEN_API global CodePreprocessCond preprocess_endif;

GEN_API global CodeSpecifiers spec_const;
GEN_API global CodeSpecifiers spec_consteval;
GEN_API global CodeSpecifiers spec_constexpr;
GEN_API global CodeSpecifiers spec_constinit;
GEN_API global CodeSpecifiers spec_extern_linkage;
GEN_API global CodeSpecifiers spec_final;
GEN_API global CodeSpecifiers spec_FORCEINLINE;
GEN_API global CodeSpecifiers spec_global;
GEN_API global CodeSpecifiers spec_inline;
GEN_API global CodeSpecifiers spec_internal_linkage;
GEN_API global CodeSpecifiers spec_local_persist;
GEN_API global CodeSpecifiers spec_mutable;
GEN_API global CodeSpecifiers spec_noexcept;
GEN_API global CodeSpecifiers spec_neverinline;
GEN_API global CodeSpecifiers spec_override;
GEN_API global CodeSpecifiers spec_ptr;
GEN_API global CodeSpecifiers spec_pure;
GEN_API global CodeSpecifiers spec_ref;
GEN_API global CodeSpecifiers spec_register;
GEN_API global CodeSpecifiers spec_rvalue;
GEN_API global CodeSpecifiers spec_static_member;
GEN_API global CodeSpecifiers spec_thread_local;
GEN_API global CodeSpecifiers spec_virtual;
GEN_API global CodeSpecifiers spec_volatile;

GEN_API global CodeTypename t_empty;
GEN_API global CodeTypename t_auto;
GEN_API global CodeTypename t_void;
GEN_API global CodeTypename t_int;
GEN_API global CodeTypename t_bool;
GEN_API global CodeTypename t_char;
GEN_API global CodeTypename t_wchar_t;
GEN_API global CodeTypename t_class;
GEN_API global CodeTypename t_typename;

#ifdef GEN_DEFINE_LIBRARY_CODE_CONSTANTS
GEN_API global CodeTypename t_b32;

GEN_API global CodeTypename t_s8;
GEN_API global CodeTypename t_s16;
GEN_API global CodeTypename t_s32;
GEN_API global CodeTypename t_s64;

GEN_API global CodeTypename t_u8;
GEN_API global CodeTypename t_u16;
GEN_API global CodeTypename t_u32;
GEN_API global CodeTypename t_u64;

GEN_API global CodeTypename t_ssize;
GEN_API global CodeTypename t_usize;

GEN_API global CodeTypename t_f32;
GEN_API global CodeTypename t_f64;
#endif

#pragma endregion Constants

#pragma endregion StaticData

#pragma region AST

// These macros are used in the swtich cases within ast.cpp, inteface.upfront.cpp, parser.cpp

#	define GEN_AST_BODY_CLASS_UNALLOWED_TYPES_CASES    \
	case CT_PlatformAttributes:                  \
	case CT_Class_Body:                          \
	case CT_Enum_Body:                           \
	case CT_Extern_Linkage:                      \
	case CT_Function_Body:                       \
	case CT_Function_Fwd:                        \
	case CT_Global_Body:                         \
	case CT_Namespace:                           \
	case CT_Namespace_Body:                      \
	case CT_Operator:                            \
	case CT_Operator_Fwd:                        \
	case CT_Parameters:                          \
	case CT_Specifiers:                          \
	case CT_Struct_Body:                         \
	case CT_Typename
#	define GEN_AST_BODY_STRUCT_UNALLOWED_TYPES_CASES GEN_AST_BODY_CLASS_UNALLOWED_TYPES_CASES

#	define GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES_CASES \
	case CT_Access_Public:                          \
	case CT_Access_Protected:                       \
	case CT_Access_Private:                         \
	case CT_PlatformAttributes:                     \
	case CT_Class_Body:                             \
	case CT_Enum_Body:                              \
	case CT_Extern_Linkage:                         \
	case CT_Friend:                                 \
	case CT_Function_Body:                          \
	case CT_Function_Fwd:                           \
	case CT_Global_Body:                            \
	case CT_Namespace:                              \
	case CT_Namespace_Body:                         \
	case CT_Operator:                               \
	case CT_Operator_Fwd:                           \
	case CT_Operator_Member:                        \
	case CT_Operator_Member_Fwd:                    \
	case CT_Parameters:                             \
	case CT_Specifiers:                             \
	case CT_Struct_Body:                            \
	case CT_Typename

#	define GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES     \
	case CT_Access_Public:                         \
	case CT_Access_Protected:                      \
	case CT_Access_Private:                        \
	case CT_PlatformAttributes:                    \
	case CT_Class_Body:                            \
	case CT_Enum_Body:                             \
	case CT_Execution:                             \
	case CT_Friend:                                \
	case CT_Function_Body:                         \
	case CT_Namespace_Body:                        \
	case CT_Operator_Member:                       \
	case CT_Operator_Member_Fwd:                   \
	case CT_Parameters:                            \
	case CT_Specifiers:                            \
	case CT_Struct_Body:                           \
	case CT_Typename
#	define GEN_AST_BODY_EXPORT_UNALLOWED_TYPES_CASES         GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES
#	define GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES_CASES GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES

#	define GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES_CASES \
	case CT_Access_Public:                        \
	case CT_Access_Protected:                     \
	case CT_Access_Private:                       \
	case CT_PlatformAttributes:                   \
	case CT_Class_Body:                           \
	case CT_Enum_Body:                            \
	case CT_Execution:                            \
	case CT_Friend:                               \
	case CT_Function_Body:                        \
	case CT_Namespace_Body:                       \
	case CT_Operator_Member:                      \
	case CT_Operator_Member_Fwd:                  \
	case CT_Parameters:                           \
	case CT_Specifiers:                           \
	case CT_Struct_Body:                          \
	case CT_Typename

// This serializes all the data-members in a "debug" format, where each member is printed with its associated value.
Str code_debug_str(Code self)
{
	GEN_ASSERT(self != nullptr);
	StrBuilder  result_stack = strbuilder_make_reserve( _ctx->Allocator_Temp, kilobytes(1) );
	StrBuilder* result       = & result_stack;

	if ( self->Parent )
		strbuilder_append_fmt( result, "\n\tParent       : %S %S", code_type_str(self->Parent), self->Name.Len ? self->Name : txt("Null") );
	else
		strbuilder_append_fmt( result, "\n\tParent       : %S", txt("Null") );

	strbuilder_append_fmt( result, "\n\tName         : %S", self->Name.Len ? self->Name : txt("Null") );
	strbuilder_append_fmt( result, "\n\tType         : %S", code_type_str(self) );
	strbuilder_append_fmt( result, "\n\tModule Flags : %S", module_flag_to_str( self->ModuleFlags ) );

	switch ( self->Type )
	{
		case CT_Invalid:
		case CT_NewLine:
		case CT_Access_Private:
		case CT_Access_Protected:
		case CT_Access_Public:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
		break;

		case CT_Untyped:
		case CT_Execution:
		case CT_Comment:
		case CT_PlatformAttributes:
		case CT_Preprocess_Include:
		case CT_Preprocess_Pragma:
		case CT_Preprocess_If:
		case CT_Preprocess_ElIf:
		case CT_Preprocess_Else:
		case CT_Preprocess_IfDef:
		case CT_Preprocess_IfNotDef:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tContent: %S", self->Content );
		break;

		case CT_Preprocess_Define:
			// TODO(ED): Needs implementaton
			log_failure("code_debug_str: NOT IMPLEMENTED for CT_Preprocess_Define");
		break;

		case CT_Class:
		case CT_Struct:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt   : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tAttributes  : %S", self->Attributes ? strbuilder_to_str( code_to_strbuilder(self->Attributes) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tParentAccess: %S", self->ParentType ? access_spec_to_str( self->ParentAccess )                  : txt("No Parent") );
			strbuilder_append_fmt( result, "\n\tParentType  : %S", self->ParentType ? code_type_str(self->ParentType)                           : txt("Null") );
			strbuilder_append_fmt( result, "\n\tBody        : %S", self->Body       ? code_debug_str(self->Body)                                : txt("Null") );
		break;

		case CT_Class_Fwd:
		case CT_Struct_Fwd:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt   : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tAttributes  : %S", self->Attributes ? strbuilder_to_str( code_to_strbuilder(self->Attributes) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tParentAccess: %S", self->ParentType ? access_spec_to_str( self->ParentAccess )                  : txt("No Parent") );
			strbuilder_append_fmt( result, "\n\tParentType  : %S", self->ParentType ? code_type_str(self->ParentType)                           : txt("Null") );
		break;

		case CT_Constructor:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt      : %S", self->InlineCmt       ? self->InlineCmt->Content                                       : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs          : %S", self->Specs           ? strbuilder_to_str( code_to_strbuilder(self->Specs) )           : txt("Null") );
			strbuilder_append_fmt( result, "\n\tInitializerList: %S", self->InitializerList ? strbuilder_to_str( code_to_strbuilder(self->InitializerList) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tParams         : %S", self->Params          ? strbuilder_to_str( code_to_strbuilder(self->Params) )          : txt("Null") );
			strbuilder_append_fmt( result, "\n\tBody           : %S", self->Body            ? code_debug_str(self->Body)                                     : txt("Null") );
		break;

		case CT_Constructor_Fwd:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt      : %S", self->InlineCmt       ? self->InlineCmt->Content                                       : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs          : %S", self->Specs           ? strbuilder_to_str( code_to_strbuilder(self->Specs) )           : txt("Null") );
			strbuilder_append_fmt( result, "\n\tInitializerList: %S", self->InitializerList ? strbuilder_to_str( code_to_strbuilder(self->InitializerList) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tParams         : %S", self->Params          ? strbuilder_to_str( code_to_strbuilder(self->Params) )          : txt("Null") );
		break;

		case CT_Destructor:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt      : %S", self->InlineCmt       ? self->InlineCmt->Content                             : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs          : %S", self->Specs           ? strbuilder_to_str( code_to_strbuilder(self->Specs) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tBody           : %S", self->Body            ? code_debug_str(self->Body)                           : txt("Null") );
		break;

		case CT_Destructor_Fwd:
		break;

		case CT_Enum:
		case CT_Enum_Class:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt       : %S", self->InlineCmt      ? self->InlineCmt->Content                                     : txt("Null") );
			strbuilder_append_fmt( result, "\n\tAttributes      : %S", self->Attributes     ? strbuilder_to_str( code_to_strbuilder(self->Attributes) )    : txt("Null") );
			strbuilder_append_fmt( result, "\n\tUnderlying Type : %S", self->UnderlyingType ? strbuilder_to_str( code_to_strbuilder(self->UnderlyingType)) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tBody            : %S", self->Body           ? code_debug_str(self->Body)                                   : txt("Null") );
		break;

		case CT_Enum_Fwd:
		case CT_Enum_Class_Fwd:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt       : %S", self->InlineCmt      ? self->InlineCmt->Content                                     : txt("Null") );
			strbuilder_append_fmt( result, "\n\tAttributes      : %S", self->Attributes     ? strbuilder_to_str( code_to_strbuilder(self->Attributes) )    : txt("Null") );
			strbuilder_append_fmt( result, "\n\tUnderlying Type : %S", self->UnderlyingType ? strbuilder_to_str( code_to_strbuilder(self->UnderlyingType)) : txt("Null") );
		break;

		case CT_Extern_Linkage:
		case CT_Namespace:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tBody: %S", self->Body ? code_debug_str(self->Body) : txt("Null") );
		break;

		case CT_Friend:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt  : %S", self->InlineCmt   ? self->InlineCmt->Content                                  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tDeclaration: %S", self->Declaration ? strbuilder_to_str( code_to_strbuilder(self->Declaration)) : txt("Null") );
		break;

		case CT_Function:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tAttributes: %S", self->Attributes ? strbuilder_to_str( code_to_strbuilder(self->Attributes) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? strbuilder_to_str( code_to_strbuilder(self->Specs))       : txt("Null") );
			strbuilder_append_fmt( result, "\n\tReturnType: %S", self->ReturnType ? strbuilder_to_str( code_to_strbuilder(self->ReturnType))  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tParams    : %S", self->Params     ? strbuilder_to_str( code_to_strbuilder(self->Params))      : txt("Null") );
			strbuilder_append_fmt( result, "\n\tBody      : %S", self->Body       ? code_debug_str(self->Body)                                : txt("Null") );
		break;

		case CT_Function_Fwd:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tAttributes: %S", self->Attributes ? strbuilder_to_str( code_to_strbuilder(self->Attributes) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? strbuilder_to_str( code_to_strbuilder(self->Specs))       : txt("Null") );
			strbuilder_append_fmt( result, "\n\tReturnType: %S", self->ReturnType ? strbuilder_to_str( code_to_strbuilder(self->ReturnType))  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tParams    : %S", self->Params     ? strbuilder_to_str( code_to_strbuilder(self->Params))      : txt("Null") );
		break;

		case CT_Module:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
		break;

		case CT_Operator:
		case CT_Operator_Member:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tAttributes: %S", self->Attributes ? strbuilder_to_str( code_to_strbuilder(self->Attributes) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? strbuilder_to_str( code_to_strbuilder(self->Specs))       : txt("Null") );
			strbuilder_append_fmt( result, "\n\tReturnType: %S", self->ReturnType ? strbuilder_to_str( code_to_strbuilder(self->ReturnType))  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tParams    : %S", self->Params     ? strbuilder_to_str( code_to_strbuilder(self->Params))      : txt("Null") );
			strbuilder_append_fmt( result, "\n\tBody      : %S", self->Body       ? code_debug_str(self->Body)                                : txt("Null") );
			strbuilder_append_fmt( result, "\n\tOp        : %S", operator_to_str( self->Op ) );
		break;

		case CT_Operator_Fwd:
		case CT_Operator_Member_Fwd:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tAttributes: %S", self->Attributes ? strbuilder_to_str( code_to_strbuilder(self->Attributes) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? strbuilder_to_str( code_to_strbuilder(self->Specs) )      : txt("Null") );
			strbuilder_append_fmt( result, "\n\tReturnType: %S", self->ReturnType ? strbuilder_to_str( code_to_strbuilder(self->ReturnType) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tParams    : %S", self->Params     ? strbuilder_to_str( code_to_strbuilder(self->Params) )     : txt("Null") );
			strbuilder_append_fmt( result, "\n\tOp        : %S", operator_to_str( self->Op ) );
		break;

		case CT_Operator_Cast:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? strbuilder_to_str( code_to_strbuilder(self->Specs))     : txt("Null") );
			strbuilder_append_fmt( result, "\n\tValueType : %S", self->ValueType  ? strbuilder_to_str( code_to_strbuilder(self->ValueType)) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tBody      : %S", self->Body       ? code_debug_str(self->Body)                              : txt("Null") );
		break;

		case CT_Operator_Cast_Fwd:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt : %S", self->InlineCmt  ? self->InlineCmt->Content                                : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs     : %S", self->Specs      ? strbuilder_to_str( code_to_strbuilder(self->Specs))     : txt("Null") );
			strbuilder_append_fmt( result, "\n\tValueType : %S", self->ValueType  ? strbuilder_to_str( code_to_strbuilder(self->ValueType)) : txt("Null") );
		break;

		case CT_Parameters:
			strbuilder_append_fmt( result, "\n\tNumEntries: %d", self->NumEntries );
			strbuilder_append_fmt( result, "\n\tLast      : %S", self->Last->Name );
			strbuilder_append_fmt( result, "\n\tNext      : %S", self->Next->Name );
			strbuilder_append_fmt( result, "\n\tValueType : %S", self->ValueType ? strbuilder_to_str( code_to_strbuilder(self->ValueType)) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tValue     : %S", self->Value     ? strbuilder_to_str( code_to_strbuilder(self->Value))     : txt("Null") );
		break;

		case CT_Parameters_Define:
			// TODO(ED): Needs implementaton
			log_failure("code_debug_str: NOT IMPLEMENTED for CT_Parameters_Define");
		break;

		case CT_Specifiers:
		{
			strbuilder_append_fmt( result, "\n\tNumEntries: %d", self->NumEntries );
			strbuilder_append_str( result, txt("\n\tArrSpecs: ") );

			s32 idx  = 0;
			s32 left = self->NumEntries;
			while ( left-- )
			{
				Str spec = spec_to_str( self->ArrSpecs[idx] );
				strbuilder_append_fmt( result, "%.*s, ", spec.Len, spec.Ptr );
				idx++;
			}
			strbuilder_append_fmt( result, "\n\tNextSpecs: %S", self->NextSpecs ? code_debug_str(self->NextSpecs) : txt("Null") );
		}
		break;

		case CT_Template:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tParams     : %S", self->Params      ? strbuilder_to_str( code_to_strbuilder(self->Params))      : txt("Null") );
			strbuilder_append_fmt( result, "\n\tDeclaration: %S", self->Declaration ? strbuilder_to_str( code_to_strbuilder(self->Declaration)) : txt("Null") );
		break;

		case CT_Typedef:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt     : %S", self->InlineCmt      ? self->InlineCmt->Content                                     : txt("Null") );
			strbuilder_append_fmt( result, "\n\tUnderlyingType: %S", self->UnderlyingType ? strbuilder_to_str( code_to_strbuilder(self->UnderlyingType)) : txt("Null") );
		break;

		case CT_Typename:
			strbuilder_append_fmt( result, "\n\tAttributes     : %S", self->Attributes ? strbuilder_to_str( code_to_strbuilder(self->Attributes) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs          : %S", self->Specs      ? strbuilder_to_str( code_to_strbuilder(self->Specs))       : txt("Null") );
			strbuilder_append_fmt( result, "\n\tReturnType     : %S", self->ReturnType ? strbuilder_to_str( code_to_strbuilder(self->ReturnType))  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tParams         : %S", self->Params     ? strbuilder_to_str( code_to_strbuilder(self->Params))      : txt("Null") );
			strbuilder_append_fmt( result, "\n\tArrExpr        : %S", self->ArrExpr    ? strbuilder_to_str( code_to_strbuilder(self->ArrExpr))     : txt("Null") );
		break;

		case CT_Union:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tAttributes: %S", self->Attributes ? strbuilder_to_str( code_to_strbuilder(self->Attributes) ) : txt("Null") );
			strbuilder_append_fmt( result, "\n\tBody      : %S", self->Body       ? code_debug_str(self->Body)                                : txt("Null") );
		break;

		case CT_Using:
			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt     : %S", self->InlineCmt      ? self->InlineCmt->Content                                      : txt("Null") );
			strbuilder_append_fmt( result, "\n\tAttributes    : %S", self->Attributes     ? strbuilder_to_str( code_to_strbuilder(self->Attributes) )     : txt("Null") );
			strbuilder_append_fmt( result, "\n\tUnderlyingType: %S", self->UnderlyingType ? strbuilder_to_str( code_to_strbuilder(self->UnderlyingType))  : txt("Null") );
		break;

		case CT_Variable:

			if ( self->Parent && self->Parent->Type == CT_Variable )
			{
				// Its a NextVar
				strbuilder_append_fmt( result, "\n\tSpecs       : %S", self->Specs        ? strbuilder_to_str( code_to_strbuilder(self->Specs))        : txt("Null") );
				strbuilder_append_fmt( result, "\n\tValue       : %S", self->Value        ? strbuilder_to_str( code_to_strbuilder(self->Value))        : txt("Null") );
				strbuilder_append_fmt( result, "\n\tBitfieldSize: %S", self->BitfieldSize ? strbuilder_to_str( code_to_strbuilder(self->BitfieldSize)) : txt("Null") );
				strbuilder_append_fmt( result, "\n\tNextVar     : %S", self->NextVar      ? code_debug_str(self->NextVar)                              : txt("Null") );
				break;
			}

			if ( self->Prev )
				strbuilder_append_fmt( result, "\n\tPrev: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );
			if ( self->Next )
				strbuilder_append_fmt( result, "\n\tNext: %S %S", code_type_str(self->Prev), self->Prev->Name.Len ? self->Prev->Name : txt("Null") );

			strbuilder_append_fmt( result, "\n\tInlineCmt   : %S", self->InlineCmt    ? self->InlineCmt->Content                                    : txt("Null") );
			strbuilder_append_fmt( result, "\n\tAttributes  : %S", self->Attributes   ? strbuilder_to_str( code_to_strbuilder(self->Attributes) )   : txt("Null") );
			strbuilder_append_fmt( result, "\n\tSpecs       : %S", self->Specs        ? strbuilder_to_str( code_to_strbuilder(self->Specs))         : txt("Null") );
			strbuilder_append_fmt( result, "\n\tValueType   : %S", self->ValueType    ? strbuilder_to_str( code_to_strbuilder(self->ValueType))     : txt("Null") );
			strbuilder_append_fmt( result, "\n\tBitfieldSize: %S", self->BitfieldSize ? strbuilder_to_str( code_to_strbuilder(self->BitfieldSize))  : txt("Null") );
			strbuilder_append_fmt( result, "\n\tValue       : %S", self->Value        ? strbuilder_to_str( code_to_strbuilder(self->Value))         : txt("Null") );
			strbuilder_append_fmt( result, "\n\tNextVar     : %S", self->NextVar      ? code_debug_str(self->NextVar)                               : txt("Null") );
		break;
	}

	return strbuilder_to_str( * result );
}

Code code_duplicate(Code self)
{
	Code result = make_code();

	void* mem_result = rcast(void*, cast(AST*, result));
	void* mem_self   = rcast(void*, cast(AST*, self));
	mem_copy( mem_result, mem_self, sizeof( AST ) );

	result->Parent = NullCode;
	return result;
}

StrBuilder code_to_strbuilder(Code self)
{
	StrBuilder result = strbuilder_make_str( _ctx->Allocator_Temp, txt("") );
	code_to_strbuilder_ptr( self, & result );
	return result;
}

void code_to_strbuilder_ptr( Code self, StrBuilder* result )
{
	GEN_ASSERT(self != nullptr);
	local_persist thread_local
	char SerializationLevel = 0;

	switch ( self->Type )
	{
		case CT_Invalid:
		#ifdef GEN_DONT_ALLOW_INVALID_CODE
			log_failure("Attempted to serialize invalid code! - %S", Parent ? Parent->code_debug_str() : Name );
		#else
			strbuilder_append_fmt( result, "Invalid Code!" );
		#endif
		break;

		case CT_NewLine:
			strbuilder_append_str( result, txt("\n"));
		break;

		case CT_Untyped:
		case CT_Execution:
		case CT_Comment:
		case CT_PlatformAttributes:
			strbuilder_append_str( result, self->Content );
		break;

		case CT_Access_Private:
		case CT_Access_Protected:
		case CT_Access_Public:
			strbuilder_append_str( result, self->Name );
		break;

		case CT_Class:
			class_to_strbuilder_def(cast(CodeClass, self), result );
		break;

		case CT_Class_Fwd:
			class_to_strbuilder_fwd(cast(CodeClass, self), result );
		break;

		case CT_Constructor:
			constructor_to_strbuilder_def(cast(CodeConstructor, self), result );
		break;

		case CT_Constructor_Fwd:
			constructor_to_strbuilder_fwd(cast(CodeConstructor, self), result );
		break;

		case CT_Destructor:
			destructor_to_strbuilder_def(cast(CodeDestructor, self), result );
		break;

		case CT_Destructor_Fwd:
			destructor_to_strbuilder_fwd(cast(CodeDestructor, self), result );
		break;

		case CT_Enum:
			enum_to_strbuilder_def(cast(CodeEnum, self), result );
		break;

		case CT_Enum_Fwd:
			enum_to_strbuilder_fwd(cast(CodeEnum, self), result );
		break;

		case CT_Enum_Class:
			enum_to_strbuilder_class_def(cast(CodeEnum, self), result );
		break;

		case CT_Enum_Class_Fwd:
			enum_to_strbuilder_class_fwd(cast(CodeEnum, self), result );
		break;

		case CT_Export_Body:
			body_to_strbuilder_export(cast(CodeBody, self), result );
		break;

		case CT_Extern_Linkage:
			extern_to_strbuilder(cast(CodeExtern, self), result );
		break;

		case CT_Friend:
			friend_to_strbuilder_ref(cast(CodeFriend, self), result );
		break;

		case CT_Function:
			fn_to_strbuilder_def(cast(CodeFn, self), result );
		break;

		case CT_Function_Fwd:
			fn_to_strbuilder_fwd(cast(CodeFn, self), result );
		break;

		case CT_Module:
			module_to_strbuilder_ref(cast(CodeModule, self), result );
		break;

		case CT_Namespace:
			namespace_to_strbuilder_ref(cast(CodeNS, self), result );
		break;

		case CT_Operator:
		case CT_Operator_Member:
			code_op_to_strbuilder_def(cast(CodeOperator, self), result );
		break;

		case CT_Operator_Fwd:
		case CT_Operator_Member_Fwd:
			code_op_to_strbuilder_fwd(cast(CodeOperator, self), result );
		break;

		case CT_Operator_Cast:
			opcast_to_strbuilder_def(cast(CodeOpCast, self), result );
		break;

		case CT_Operator_Cast_Fwd:
			opcast_to_strbuilder_fwd(cast(CodeOpCast, self), result );
		break;

		case CT_Parameters:
			params_to_strbuilder_ref(cast(CodeParams, self), result );
		break;

		case CT_Parameters_Define:
			define_params_to_strbuilder_ref(cast(CodeDefineParams, self), result);
		break;

		case CT_Preprocess_Define:
			define_to_strbuilder_ref(cast(CodeDefine, self), result );
		break;

		case CT_Preprocess_If:
			preprocess_to_strbuilder_if(cast(CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_IfDef:
			preprocess_to_strbuilder_ifdef(cast(CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_IfNotDef:
			preprocess_to_strbuilder_ifndef(cast(CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_Include:
			include_to_strbuilder_ref(cast(CodeInclude, self), result );
		break;

		case CT_Preprocess_ElIf:
			preprocess_to_strbuilder_elif(cast(CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_Else:
			preprocess_to_strbuilder_else(cast(CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_EndIf:
			preprocess_to_strbuilder_endif(cast(CodePreprocessCond, self), result );
		break;

		case CT_Preprocess_Pragma:
			pragma_to_strbuilder_ref(cast(CodePragma, self), result );
		break;

		case CT_Specifiers:
			specifiers_to_strbuilder_ref(cast(CodeSpecifiers, self), result );
		break;

		case CT_Struct:
			struct_to_strbuilder_def(cast(CodeStruct, self), result );
		break;

		case CT_Struct_Fwd:
			struct_to_strbuilder_fwd(cast(CodeStruct, self), result );
		break;

		case CT_Template:
			template_to_strbuilder_ref(cast(CodeTemplate, self), result );
		break;

		case CT_Typedef:
			typedef_to_strbuilder_ref(cast(CodeTypedef, self), result );
		break;

		case CT_Typename:
			typename_to_strbuilder_ref(cast(CodeTypename, self), result );
		break;

		case CT_Union:
			union_to_strbuilder_def( cast(CodeUnion, self), result );
		break;

		case CT_Union_Fwd:
			union_to_strbuilder_fwd( cast(CodeUnion, self), result );
		break;

		case CT_Using:
			using_to_strbuilder_ref(cast(CodeUsing, self), result );
		break;

		case CT_Using_Namespace:
			using_to_strbuilder_ns(cast(CodeUsing, self), result );
		break;

		case CT_Variable:
			var_to_strbuilder_ref(cast(CodeVar, self), result );
		break;

		case CT_Enum_Body:
		case CT_Class_Body:
		case CT_Extern_Linkage_Body:
		case CT_Function_Body:
		case CT_Global_Body:
		case CT_Namespace_Body:
		case CT_Struct_Body:
		case CT_Union_Body:
			body_to_strbuilder_ref( cast(CodeBody, self), result );
		break;
	}
}

bool code_is_equal( Code self, Code other )
{
/*
	AST values are either some u32 value, a cached string, or a pointer to another AST.

	u32 values are compared by value.
	Cached strings are compared by pointer.
	AST nodes are compared with AST::is_equal.
*/
	if ( other == nullptr )
	{
		log_fmt( "AST::is_equal: other is null\nAST: %S", code_debug_str(self) );
		return false;
	}

	if ( self->Type != other->Type )
	{
		log_fmt("AST::is_equal: Type check failure with other\nAST: %S\nOther: %S"
			, code_debug_str(self)
			, code_debug_str(other)
		);

		return false;
	}

	switch ( self->Type )
	{
	#define check_member_val( val )                           \
	if ( self->val != other->val )                            \
	{                                                         \
		log_fmt("\nAST::is_equal: Member - " #val " failed\n" \
		        "AST  : %S\n"                                 \
		        "Other: %S\n"                                 \
		    , code_debug_str(self)                            \
		    ,code_debug_str(other)                            \
		);                                                    \
                                                              \
		return false;                                         \
	}

	#define check_member_str( str )                                 \
	if ( ! str_are_equal( self->str, other->str ) )                 \
	{                                                               \
		log_fmt("\nAST::is_equal: Member string - "#str " failed\n" \
				"AST  : %S\n"                                       \
				"Other: %S\n"                                       \
			, code_debug_str(self)                                  \
			,code_debug_str(other)                                  \
		);                                                          \
	                                                                \
		return false;                                               \
	}

	#define check_member_content( content )                                  \
	if ( ! str_are_equal( self->content, other->content ))                   \
	{                                                                        \
		log_fmt("\nAST::is_equal: Member content - "#content " failed\n"     \
				"AST  : %S\n"                                                \
				"Other: %S\n"                                                \
			, code_debug_str(self)                                           \
			, code_debug_str(other)                                          \
		);                                                                   \
                                                                             \
		log_fmt("Content cannot be trusted to be unique with this check "    \
			"so it must be verified by eye for now\n"                        \
			"AST   Content:\n%S\n"                                           \
			"Other Content:\n%S\n"                                           \
			, str_visualize_whitespace(self->content, _ctx->Allocator_Temp)  \
			, str_visualize_whitespace(other->content, _ctx->Allocator_Temp) \
		);                                                                   \
	}

	#define check_member_ast( ast )                                                                \
	if ( self->ast )                                                                               \
	{                                                                                              \
		if ( other->ast == nullptr )                                                               \
		{                                                                                          \
			log_fmt("\nAST::is_equal: Failed for member " #ast " other equivalent param is null\n" \
					"AST  : %S\n"                                                                  \
					"Other: %S\n"                                                                  \
					"For ast member: %S\n"                                                         \
				, code_debug_str(self)                                                             \
				, code_debug_str(other)                                                            \
				, code_debug_str(self->ast)                                                        \
			);                                                                                     \
                                                                                                   \
			return false;                                                                          \
		}                                                                                          \
                                                                                                   \
		if ( ! code_is_equal(self->ast, other->ast ) )                                             \
		{                                                                                          \
			log_fmt( "\nAST::is_equal: Failed for " #ast"\n"                                       \
					"AST  : %S\n"                                                                  \
					"Other: %S\n"                                                                  \
					"For     ast member: %S\n"                                                     \
					"other's ast member: %S\n"                                                     \
				, code_debug_str(self)                                                             \
				, code_debug_str(other)                                                            \
				, code_debug_str(self->ast)                                                        \
				, code_debug_str(other->ast)                                                       \
			);                                                                                     \
		                                                                                           \
			return false;                                                                          \
		}                                                                                          \
	}

		case CT_NewLine:
		case CT_Access_Public:
		case CT_Access_Protected:
		case CT_Access_Private:
		case CT_Preprocess_Else:
		case CT_Preprocess_EndIf:
			return true;


		// Comments are not validated.
		case CT_Comment:
			return true;

		case CT_Execution:
		case CT_PlatformAttributes:
		case CT_Untyped:
		{
			check_member_content( Content );
			return true;
		}

		case CT_Class_Fwd:
		case CT_Struct_Fwd:
		{
			check_member_str( Name );
			check_member_ast( ParentType );
			check_member_val( ParentAccess );
			check_member_ast( Attributes );

			return true;
		}

		case CT_Class:
		case CT_Struct:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ParentType );
			check_member_val( ParentAccess );
			check_member_ast( Attributes );
			check_member_ast( Body );

			return true;
		}

		case CT_Constructor:
		{
			check_member_ast( InitializerList );
			check_member_ast( Params );
			check_member_ast( Body );

			return true;
		}

		case CT_Constructor_Fwd:
		{
			check_member_ast( InitializerList );
			check_member_ast( Params );

			return true;
		}

		case CT_Destructor:
		{
			check_member_ast( Specs );
			check_member_ast( Body );

			return true;
		}

		case CT_Destructor_Fwd:
		{
			check_member_ast( Specs );

			return true;
		}

		case CT_Enum:
		case CT_Enum_Class:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
			check_member_ast( UnderlyingType );
			check_member_ast( Body );
			check_member_ast( UnderlyingTypeMacro );

			return true;
		}

		case CT_Enum_Fwd:
		case CT_Enum_Class_Fwd:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
			check_member_ast( UnderlyingType );
			check_member_ast( UnderlyingTypeMacro );

			return true;
		}

		case CT_Extern_Linkage:
		{
			check_member_str( Name );
			check_member_ast( Body );

			return true;
		}

		case CT_Friend:
		{
			check_member_str( Name );
			check_member_ast( Declaration );

			return true;
		}

		case CT_Function:
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

		case CT_Function_Fwd:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ReturnType );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( Params );

			return true;
		}

		case CT_Module:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );

			return true;
		}

		case CT_Namespace:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Body );

			return true;
		}

		case CT_Operator:
		case CT_Operator_Member:
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

		case CT_Operator_Fwd:
		case CT_Operator_Member_Fwd:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( ReturnType );
			check_member_ast( Attributes );
			check_member_ast( Specs );
			check_member_ast( Params );

			return true;
		}

		case CT_Operator_Cast:
		{
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( ValueType );
			check_member_ast( Body );

			return true;
		}

		case CT_Operator_Cast_Fwd:
		{
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( ValueType );

			return true;
		}

		case CT_Parameters:
		{
			if ( self->NumEntries > 1 )
			{
				Code curr       = self;
				Code curr_other = other;
				while ( curr != nullptr  )
				{
					if ( curr )
					{
						if ( curr_other == nullptr )
						{
							log_fmt("\nAST::is_equal: Failed for parameter, other equivalent param is null\n"
									"AST  : %S\n"
									"Other: %S\n"
									"For ast member: %S\n"
								, code_debug_str(curr)
							);

							return false;
						}

						if ( str_are_equal(curr->Name, curr_other->Name) )
						{
							log_fmt( "\nAST::is_equal: Failed for parameter name check\n"
									"AST  : %S\n"
									"Other: %S\n"
									"For     ast member: %S\n"
									"other's ast member: %S\n"
								, code_debug_str(self)
								, code_debug_str(other)
								, code_debug_str(curr)
								, code_debug_str(curr_other)
							);
							return false;
						}

						if ( curr->ValueType && ! code_is_equal(curr->ValueType, curr_other->ValueType) )
						{
							log_fmt( "\nAST::is_equal: Failed for parameter value type check\n"
									"AST  : %S\n"
									"Other: %S\n"
									"For     ast member: %S\n"
									"other's ast member: %S\n"
								, code_debug_str(self)
								, code_debug_str(other)
								, code_debug_str(curr)
								, code_debug_str(curr_other)
							);
							return false;
						}

						if ( curr->Value && ! code_is_equal(curr->Value, curr_other->Value) )
						{
							log_fmt( "\nAST::is_equal: Failed for parameter value check\n"
									"AST  : %S\n"
									"Other: %S\n"
									"For     ast member: %S\n"
									"other's ast member: %S\n"
								, code_debug_str(self)
								, code_debug_str(other)
								, code_debug_str(curr)
								, code_debug_str(curr_other)
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

		case CT_Parameters_Define:
		{
			// TODO(ED): Needs implementaton
			log_failure("code_is_equal: NOT IMPLEMENTED for CT_Parameters_Define");
			return false;
		}

		case CT_Preprocess_Define:
		{
			check_member_str( Name );
			check_member_content( Body->Content );
			return true;
		}

		case CT_Preprocess_If:
		case CT_Preprocess_IfDef:
		case CT_Preprocess_IfNotDef:
		case CT_Preprocess_ElIf:
		{
			check_member_content( Content );

			return true;
		}

		case CT_Preprocess_Include:
		case CT_Preprocess_Pragma:
		{
			check_member_content( Content );

			return true;
		}

		case CT_Specifiers:
		{
			check_member_val( NumEntries );
			check_member_str( Name );
			for ( s32 idx = 0; idx < self->NumEntries; ++idx )
			{
				check_member_val( ArrSpecs[ idx ] );
			}
			return true;
		}

		case CT_Template:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Params );
			check_member_ast( Declaration );

			return true;
		}

		case CT_Typedef:
		{
			check_member_val( IsFunction );
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( UnderlyingType );

			return true;
		}
		case CT_Typename:
		{
			check_member_val( IsParamPack );
			check_member_str( Name );
			check_member_ast( Specs );
			check_member_ast( ArrExpr );

			return true;
		}

		case CT_Union:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
			check_member_ast( Body );

			return true;
		}

		case CT_Union_Fwd:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( Attributes );
		}

		case CT_Using:
		case CT_Using_Namespace:
		{
			check_member_val( ModuleFlags );
			check_member_str( Name );
			check_member_ast( UnderlyingType );
			check_member_ast( Attributes );

			return true;
		}

		case CT_Variable:
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

		case CT_Class_Body:
		case CT_Enum_Body:
		case CT_Export_Body:
		case CT_Global_Body:
		case CT_Namespace_Body:
		case CT_Struct_Body:
		case CT_Union_Body:
		{
			check_member_ast( Front );
			check_member_ast( Back );

			Code curr       = self->Front;
			Code curr_other = other->Front;
			while ( curr != nullptr )
			{
				if ( curr_other == nullptr )
				{
					log_fmt("\nAST::is_equal: Failed for body, other equivalent param is null\n"
							"AST  : %S\n"
							"Other: %S\n"
						, code_debug_str(curr)
						, code_debug_str(other)
					);

					return false;
				}

				if ( ! code_is_equal( curr, curr_other ) )
				{
					log_fmt( "\nAST::is_equal: Failed for body\n"
							"AST  : %S\n"
							"Other: %S\n"
							"For     ast member: %S\n"
							"other's ast member: %S\n"
						, code_debug_str(self)
						, code_debug_str(other)
						, code_debug_str(curr)
						, code_debug_str(curr_other)
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

bool code_validate_body(Code self)
{
	switch ( self->Type )
	{
		case CT_Class_Body:
		{
			CodeBody body = cast(CodeBody, self);
			for (Code code_entry = begin_CodeBody(body); code_entry != end_CodeBody(body); next_CodeBody(body, code_entry)) switch (code_entry->Type)
			{
				GEN_AST_BODY_CLASS_UNALLOWED_TYPES_CASES:
					log_failure("AST::validate_body: Invalid entry in body %S", code_debug_str(code_entry));
				return false;

				default:
				continue;
			}
		}
		break;
		case CT_Enum_Body:
		{
			CodeBody body = cast(CodeBody, self);
			for ( Code entry = begin_CodeBody(body); entry != end_CodeBody(body); next_CodeBody(body, entry) )
			{
				if ( entry->Type != CT_Untyped )
				{
					log_failure( "AST::validate_body: Invalid entry in enum body (needs to be untyped or comment) %S", code_debug_str(entry) );
					return false;
				}
			}
		}
		break;
		case CT_Export_Body:
		{
			CodeBody body = cast(CodeBody, self);
			for (Code code_entry = begin_CodeBody(body); code_entry != end_CodeBody(body); next_CodeBody(body, code_entry)) switch (code_entry->Type)
			{
				GEN_AST_BODY_EXPORT_UNALLOWED_TYPES_CASES:
					log_failure("AST::validate_body: Invalid entry in body %S", code_debug_str(code_entry));
				return false;

				default:
				continue;
			}
		}
		break;
		case CT_Extern_Linkage:
		{
			CodeBody body = cast(CodeBody, self);
			for (Code code_entry = begin_CodeBody(body); code_entry != end_CodeBody(body); next_CodeBody(body, code_entry)) switch (code_entry->Type)
			{
				GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES_CASES:
					log_failure("AST::validate_body: Invalid entry in body %S", code_debug_str(code_entry));
				return false;

				default:
				continue;
			}
		}
		break;
		case CT_Function_Body:
		{
			CodeBody body = cast(CodeBody, self);
			for (Code code_entry = begin_CodeBody(body); code_entry != end_CodeBody(body); next_CodeBody(body, code_entry)) switch (code_entry->Type)
			{
				GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES_CASES:
					log_failure("AST::validate_body: Invalid entry in body %S", code_debug_str(code_entry));
				return false;

				default:
				continue;
			}
		}
		break;
		case CT_Global_Body:
		{
			CodeBody body = cast(CodeBody, self);
			for ( Code entry = begin_CodeBody(body); entry != end_CodeBody(body); next_CodeBody(body, entry) )switch (entry->Type)
			{
				GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES:
					log_failure("AST::validate_body: Invalid entry in body %S", code_debug_str(entry));
				return false;
			}
		}
		break;
		case CT_Namespace_Body:
		{
			CodeBody body = cast(CodeBody, self);
			for ( Code entry = begin_CodeBody(body); entry != end_CodeBody(body); next_CodeBody(body, entry) ) switch (entry->Type)
			{
				GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES_CASES:
					log_failure("AST::validate_body: Invalid entry in body %S", code_debug_str(entry));
				return false;
			}
		}
		break;
		case CT_Struct_Body:
		{
			CodeBody body = cast(CodeBody, self);
			for ( Code entry = begin_CodeBody(body); entry != end_CodeBody(body); next_CodeBody(body, entry) ) switch (entry->Type)
			{
				GEN_AST_BODY_STRUCT_UNALLOWED_TYPES_CASES:
					log_failure("AST::validate_body: Invalid entry in body %S", code_debug_str(entry));
				return false;
			}
		}
		break;
		case CT_Union_Body:
		{
			CodeBody body = cast(CodeBody, self);
			for ( Code entry = begin_CodeBody(body); entry != end_CodeBody(body); next_CodeBody(body, entry) )
			{
				if ( entry->Type != CT_Untyped )
				{
					log_failure( "AST::validate_body: Invalid entry in union body (needs to be untyped or comment) %S", code_debug_str(entry) );
					return false;
				}
			}
		}
		break;

		default:
			log_failure( "AST::validate_body: Invalid this AST does not have a body %S", code_debug_str(self) );
			return false;
	}
	return false;
}

inline
StrBuilder attributes_to_strbuilder(CodeAttributes attributes) {
	GEN_ASSERT(attributes);
	char* raw = ccast(char*, str_duplicate( attributes->Content, _ctx->Allocator_Temp ).Ptr);
	StrBuilder result = { raw };
	return result;
}

inline
void attributes_to_strbuilder_ref(CodeAttributes attributes, StrBuilder* result) {
	GEN_ASSERT(attributes);
	GEN_ASSERT(result);
	strbuilder_append_str(result, attributes->Content);
}

StrBuilder body_to_strbuilder(CodeBody body)
{
	GEN_ASSERT(body);
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 128 );
	switch ( body->Type )
	{
		case CT_Untyped:
		case CT_Execution:
			strbuilder_append_str( & result, cast(Code, body)->Content );
		break;

		case CT_Enum_Body:
		case CT_Class_Body:
		case CT_Extern_Linkage_Body:
		case CT_Function_Body:
		case CT_Global_Body:
		case CT_Namespace_Body:
		case CT_Struct_Body:
		case CT_Union_Body:
			body_to_strbuilder_ref( body, & result );
		break;

		case CT_Export_Body:
			body_to_strbuilder_export( body, & result );
		break;
	}
	return result;
}

void body_to_strbuilder_ref( CodeBody body, StrBuilder* result )
{
	GEN_ASSERT(body   != nullptr);
	GEN_ASSERT(result != nullptr);
	Code curr = body->Front;
	s32  left = body->NumEntries;
	while ( left -- )
	{
		code_to_strbuilder_ptr(curr, result);
		// strbuilder_append_fmt( result, "%SB", code_to_strbuilder(curr) );
		++curr;
	}
}

void body_to_strbuilder_export( CodeBody body, StrBuilder* result )
{
	GEN_ASSERT(body   != nullptr);
	GEN_ASSERT(result != nullptr);
	strbuilder_append_fmt( result, "export\n{\n" );

	Code curr = cast(Code, body);
	s32  left = body->NumEntries;
	while ( left-- )
	{
		code_to_strbuilder_ptr(curr, result);
		// strbuilder_append_fmt( result, "%SB", code_to_strbuilder(curr) );
		++curr;
	}

	strbuilder_append_fmt( result, "};\n" );
}

inline
StrBuilder comment_to_strbuilder(CodeComment comment) {
	GEN_ASSERT(comment);
	char* raw = ccast(char*, str_duplicate( comment->Content, _ctx->Allocator_Temp ).Ptr);
	StrBuilder result = { raw };
	return result;
}

inline
void comment_to_strbuilder_ref(CodeComment comment, StrBuilder* result) {
	GEN_ASSERT(comment);
	GEN_ASSERT(result);
	strbuilder_append_str(result, comment->Content);
}

StrBuilder constructor_to_strbuilder(CodeConstructor self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 128 );
	switch (self->Type)
	{
		case CT_Constructor:
			constructor_to_strbuilder_def( self, & result );
		break;
		case CT_Constructor_Fwd:
			constructor_to_strbuilder_fwd( self, & result );
		break;
	}
	return result;
}

void constructor_to_strbuilder_def(CodeConstructor self, StrBuilder* result )
{
	Code ClassStructParent = self->Parent->Parent;
	if (ClassStructParent) {
		strbuilder_append_str( result, ClassStructParent->Name );
	}
	else {
		strbuilder_append_str( result, self->Name );
	}

	if ( self->Params )
		strbuilder_append_fmt( result, "( %SB )", params_to_strbuilder(self->Params) );
	else
		strbuilder_append_str( result, txt("()") );

	if ( self->InitializerList )
		strbuilder_append_fmt( result, " : %SB", code_to_strbuilder(self->InitializerList) );

	if ( self->InlineCmt )
		strbuilder_append_fmt( result, " // %S", self->InlineCmt->Content );

	strbuilder_append_fmt( result, "\n{\n%SB\n}\n", code_to_strbuilder(self->Body) );
}

void constructor_to_strbuilder_fwd(CodeConstructor self, StrBuilder* result )
{
	Code ClassStructParent = self->Parent->Parent;
	if (ClassStructParent) {
		strbuilder_append_str( result, ClassStructParent->Name );
	}
	else {
		strbuilder_append_str( result, self->Name );
	}

	if ( self->Params )
		strbuilder_append_fmt( result, "( %SB )", params_to_strbuilder(self->Params) );
	else
		strbuilder_append_fmt( result, "()");

	if (self->Body)
		strbuilder_append_fmt( result, " = %SB", code_to_strbuilder(self->Body) );

	if ( self->InlineCmt )
		strbuilder_append_fmt( result, "; // %S\n", self->InlineCmt->Content );
	else
		strbuilder_append_str( result, txt(";\n") );
}

StrBuilder class_to_strbuilder( CodeClass self )
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Class:
			class_to_strbuilder_def(self, & result );
		break;
		case CT_Class_Fwd:
			class_to_strbuilder_fwd(self, & result );
		break;
	}
	return result;
}

void class_to_strbuilder_def( CodeClass self, StrBuilder* result )
{
	GEN_ASSERT(self);

	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	strbuilder_append_str( result, txt("class ") );

	if ( self->Attributes )
	{
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );
	}

	if (self->Name)
		strbuilder_append_str( result, self->Name );
	
	if (self->Specs && self->Specs.has(Spec_Final))
		strbuilder_append_str( result, txt(" final"));

	if ( self->ParentType )
	{
		Str access_level = access_spec_to_str( self->ParentAccess );
		strbuilder_append_fmt( result, " : %S %SB", self->Name, access_level, typename_to_strbuilder(self->ParentType) );

		CodeTypename interface = cast(CodeTypename, self->ParentType->Next);
		if ( interface )
			strbuilder_append_str( result, txt("\n") );

		while ( interface )
		{
			strbuilder_append_fmt( result, ", public %SB", typename_to_strbuilder(interface) );
			interface = interface->Next ? cast(CodeTypename, interface->Next) : NullCode;
		}
	}

	if ( self->InlineCmt )
	{
		strbuilder_append_fmt( result, " // %S", self->InlineCmt->Content );
	}

	strbuilder_append_fmt( result, "\n{\n%SB\n}", body_to_strbuilder(self->Body) );

	if ( self->Parent == nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		strbuilder_append_str( result, txt(";\n") );
}

void class_to_strbuilder_fwd( CodeClass self, StrBuilder* result )
{
	GEN_ASSERT(self);

	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "class %SB %S", attributes_to_strbuilder(self->Attributes), self->Name );

	else strbuilder_append_fmt( result, "class %S", self->Name );

	// Check if it can have an end-statement
	if ( self->Parent == nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
	{
		if ( self->InlineCmt )
			strbuilder_append_fmt( result, "; // %S\n", self->InlineCmt->Content );
		else
			strbuilder_append_str( result, txt(";\n") );
	}
}

StrBuilder define_to_strbuilder(CodeDefine define)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 512 );
	define_to_strbuilder_ref(define, & result);
	return result;
}

void define_to_strbuilder_ref(CodeDefine define, StrBuilder* result )
{
	GEN_ASSERT(define);
	GEN_ASSERT(define->Body);
	GEN_ASSERT(define->Body->Content.Ptr && define->Body->Content.Len > 0);
	if (define->Params) {
		StrBuilder params_builder = define_params_to_strbuilder(define->Params);
		strbuilder_append_fmt( result, "#define %S(%S) %S", define->Name, strbuilder_to_str(params_builder), define->Body->Content );
	}
	else {
		strbuilder_append_fmt( result, "#define %S %S", define->Name, define->Body->Content );
	}
}

StrBuilder define_params_to_strbuilder(CodeDefineParams params)
{
	GEN_ASSERT(params);
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 128 );
	define_params_to_strbuilder_ref( params, & result );
	return result;
}

void define_params_to_strbuilder_ref(CodeDefineParams self, StrBuilder* result)
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->Name.Ptr && self->Name.Len )
	{
		strbuilder_append_fmt( result, " %S", self->Name );
	}
	if ( self->NumEntries - 1 > 0 )
	{
		for ( CodeDefineParams param = begin_CodeDefineParams(self->Next); param != end_CodeDefineParams(self->Next); param = next_CodeDefineParams(self->Next, param) )
		{
			strbuilder_append_fmt( result, ", %SB", define_params_to_strbuilder(param) );
		}
	}
}

StrBuilder destructor_to_strbuilder(CodeDestructor self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 128 );
	switch ( self->Type )
	{
		case CT_Destructor:
			destructor_to_strbuilder_def( self, & result );
		break;
		case CT_Destructor_Fwd:
			destructor_to_strbuilder_fwd( self, & result );
		break;
	}
	return result;
}

void destructor_to_strbuilder_def(CodeDestructor self, StrBuilder* result )
{
	if ( self->Name.Len )
	{
		strbuilder_append_fmt( result, "%S()", self->Name );
	}
	else if ( self->Specs )
	{
		if ( specifiers_has(self->Specs, Spec_Virtual ) )
			strbuilder_append_fmt( result, "virtual ~%S()", self->Parent->Name );
		else
			strbuilder_append_fmt( result, "~%S()", self->Parent->Name );
	}
	else
		strbuilder_append_fmt( result, "~%S()", self->Parent->Name );

	strbuilder_append_fmt( result, "\n{\n%SB\n}\n", code_to_strbuilder(self->Body) );
}

void destructor_to_strbuilder_fwd(CodeDestructor self, StrBuilder* result )
{
	if ( self->Specs )
	{
		if ( specifiers_has(self->Specs, Spec_Virtual ) )
			strbuilder_append_fmt( result, "virtual ~%S();\n", self->Parent->Name );
		else
			strbuilder_append_fmt( result, "~%S()", self->Parent->Name );

		if ( specifiers_has(self->Specs, Spec_Pure ) )
			strbuilder_append_str( result, txt(" = 0;") );
		else if (self->Body)
			strbuilder_append_fmt( result, " = %SB;", code_to_strbuilder(self->Body) );
	}
	else
		strbuilder_append_fmt( result, "~%S();", self->Parent->Name );

	if ( self->InlineCmt )
		strbuilder_append_fmt( result, "  %S", self->InlineCmt->Content );
	else
		strbuilder_append_str( result, txt("\n"));
}

StrBuilder enum_to_strbuilder(CodeEnum self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Enum:
			enum_to_strbuilder_def(self, & result );
		break;
		case CT_Enum_Fwd:
			enum_to_strbuilder_fwd(self, & result );
		break;
		case CT_Enum_Class:
			enum_to_strbuilder_class_def(self, & result );
		break;
		case CT_Enum_Class_Fwd:
			enum_to_strbuilder_class_fwd(self, & result );
		break;
	}
	return result;
}

void enum_to_strbuilder_def(CodeEnum self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes || self->UnderlyingType || self->UnderlyingTypeMacro )
	{
		strbuilder_append_str( result, txt("enum ") );

		if ( self->Attributes )
			strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

		if ( self->UnderlyingType )
			strbuilder_append_fmt( result, "%S : %SB\n{\n%SB\n}"
				, self->Name
				, typename_to_strbuilder(self->UnderlyingType)
				, body_to_strbuilder(self->Body)
			);
		else if ( self->UnderlyingTypeMacro )
			strbuilder_append_fmt( result, "%S %SB\n{\n%SB\n}"
				, self->Name
				, code_to_strbuilder(self->UnderlyingTypeMacro)
				, body_to_strbuilder(self->Body)
			);

		else strbuilder_append_fmt( result, "%S\n{\n%SB\n}", self->Name, body_to_strbuilder(self->Body) );
	}
	else strbuilder_append_fmt( result, "enum %S\n{\n%SB\n}", self->Name, body_to_strbuilder(self->Body) );

	if ( self->Parent == nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		strbuilder_append_str( result, txt(";\n"));
}

void enum_to_strbuilder_fwd(CodeEnum self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

	if ( self->UnderlyingType )
		strbuilder_append_fmt( result, "enum %S : %SB", self->Name, typename_to_strbuilder(self->UnderlyingType) );
	else if (self->UnderlyingTypeMacro)
	{
		log_fmt("IDENTIFIED A UNDERLYING ENUM MACRO");
		strbuilder_append_fmt( result, "enum %S %SB", self->Name, code_to_strbuilder(self->UnderlyingTypeMacro) );
	}
	else
		strbuilder_append_fmt( result, "enum %S", self->Name );

	if ( self->Parent == nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
	{
		if ( self->InlineCmt )
			strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
		else
			strbuilder_append_str( result, txt(";\n"));
	}
}

void enum_to_strbuilder_class_def(CodeEnum self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes || self->UnderlyingType )
	{
		strbuilder_append_str( result, txt("enum class ") );

		if ( self->Attributes )
		{
			strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );
		}

		if ( self->UnderlyingType )
		{
			strbuilder_append_fmt( result, "%S : %SB\n{\n%SB\n}", self->Name, typename_to_strbuilder(self->UnderlyingType), body_to_strbuilder(self->Body) );
		}
		else
		{
			strbuilder_append_fmt( result, "%S\n{\n%SB\n}", self->Name, body_to_strbuilder(self->Body) );
		}
	}
	else
	{
		strbuilder_append_fmt( result, "enum %S\n{\n%SB\n}", self->Name, body_to_strbuilder(self->Body) );
	}

	if ( self->Parent == nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		strbuilder_append_str( result, txt(";\n"));
}

void enum_to_strbuilder_class_fwd(CodeEnum self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	strbuilder_append_str( result, txt("enum class ") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

	strbuilder_append_fmt( result, "%S : %SB", self->Name, typename_to_strbuilder(self->UnderlyingType) );

	if ( self->Parent == nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
	{
		if ( self->InlineCmt )
			strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
		else
			strbuilder_append_str( result, txt(";\n"));
	}
}

StrBuilder exec_to_strbuilder(CodeExec exec)
{
	GEN_ASSERT(exec);
	char* raw = ccast(char*, str_duplicate( exec->Content, _ctx->Allocator_Temp ).Ptr);
	StrBuilder result = { raw };
	return result;
}

void extern_to_strbuilder(CodeExtern self, StrBuilder* result )
{
	if ( self->Body )
		strbuilder_append_fmt( result, "extern \"%S\"\n{\n%SB\n}\n", self->Name, body_to_strbuilder(self->Body) );
	else
		strbuilder_append_fmt( result, "extern \"%S\"\n{}\n", self->Name );
}

StrBuilder include_to_strbuilder(CodeInclude include)
{
	return strbuilder_fmt_buf( _ctx->Allocator_Temp, "#include %S\n", include->Content );
}

void include_to_strbuilder_ref( CodeInclude include, StrBuilder* result )
{
	strbuilder_append_fmt( result, "#include %S\n", include->Content );
}

StrBuilder friend_to_strbuilder(CodeFriend self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 256 );
	friend_to_strbuilder_ref( self, & result );
	return result;
}

void friend_to_strbuilder_ref(CodeFriend self, StrBuilder* result )
{
	strbuilder_append_fmt( result, "friend %SB", code_to_strbuilder(self->Declaration) );

	if ( self->Declaration->Type != CT_Function && self->Declaration->Type != CT_Operator && (* result)[ strbuilder_length(* result) - 1 ] != ';' )
	{
		strbuilder_append_str( result, txt(";") );
	}

	if ( self->InlineCmt )
		strbuilder_append_fmt( result, "  %S", self->InlineCmt->Content );
	else
		strbuilder_append_str( result, txt("\n"));
}

StrBuilder fn_to_strbuilder(CodeFn self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Function:
			fn_to_strbuilder_def(self, & result );
		break;
		case CT_Function_Fwd:
			fn_to_strbuilder_fwd(self, & result );
		break;
	}
	return result;
}

void fn_to_strbuilder_def(CodeFn self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, " %SB ", attributes_to_strbuilder(self->Attributes) );

	bool prefix_specs = false;
	if ( self->Specs )
	{
		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, " %.*s", spec_str.Len, spec_str.Ptr );

				prefix_specs = true;
			}
		}
	}

	if ( self->Attributes || prefix_specs )
		strbuilder_append_str( result, txt("\n") );

	if ( self->ReturnType )
		strbuilder_append_fmt( result, "%SB %S(", typename_to_strbuilder(self->ReturnType), self->Name );

	else
		strbuilder_append_fmt( result, "%S(", self->Name );

	if ( self->Params )
		strbuilder_append_fmt( result, "%SB)", params_to_strbuilder(self->Params) );

	else
		strbuilder_append_str( result, txt(")") );

	if ( self->Specs )
	{
		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	// This is bodged in for now SOLEY for Unreal's PURE_VIRTUAL functional macro
	if ( self->SuffixSpecs )
		strbuilder_append_fmt( result, " %SB", code_to_strbuilder(self->SuffixSpecs) );

	strbuilder_append_fmt( result, "\n{\n%SB\n}\n", body_to_strbuilder(self->Body) );
}

void fn_to_strbuilder_fwd(CodeFn self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

	b32 prefix_specs = false;
	if ( self->Specs )
	{
		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! spec_is_trailing( * spec ) || ! ( * spec != Spec_Pure) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, " %.*s", spec_str.Len, spec_str.Ptr );

				prefix_specs = true;
			}
		}
	}

	if ( self->Attributes || prefix_specs )
	{
		strbuilder_append_str( result, txt("\n") );
	}

	if ( self->ReturnType )
		strbuilder_append_fmt( result, "%SB %S(", typename_to_strbuilder(self->ReturnType), self->Name );

	else
		strbuilder_append_fmt( result, "%S(", self->Name );

	if ( self->Params )
		strbuilder_append_fmt( result, "%SB)", params_to_strbuilder(self->Params) );

	else
		strbuilder_append_str( result, txt(")") );

	if ( self->Specs )
	{
		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	if (self->Specs)
	{
		if ( specifiers_has(self->Specs, Spec_Pure ) >= 0 )
			strbuilder_append_str( result, txt(" = 0") );
		
		if ( specifiers_has(self->Specs, Spec_Delete ) >= 0 )
			strbuilder_append_str( result, txt(" = delete") );
	}

	// This is bodged in for now SOLEY for Unreal's PURE_VIRTUAL functional macro (I kept it open ended for other jank)
	if ( self->SuffixSpecs )
		strbuilder_append_fmt( result, " %SB", code_to_strbuilder(self->SuffixSpecs) );

	if (self->Body)
		strbuilder_append_fmt( result, " = %SB;", body_to_strbuilder(self->Body) );

	if ( self->InlineCmt )
		strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
	else
		strbuilder_append_str( result, txt(";\n") );
}

StrBuilder module_to_strbuilder(CodeModule self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 64 );
	module_to_strbuilder_ref( self, & result );
	return result;
}

void module_to_strbuilder_ref(CodeModule self, StrBuilder* result )
{
	if (((scast(u32, ModuleFlag_Export) & scast(u32, self->ModuleFlags)) == scast(u32, ModuleFlag_Export)))
		strbuilder_append_str( result, txt("export "));

	if (((scast(u32, ModuleFlag_Import) & scast(u32, self->ModuleFlags)) == scast(u32, ModuleFlag_Import)))
		strbuilder_append_str( result, txt("import "));

	strbuilder_append_fmt( result, "%S;\n", self->Name );
}

StrBuilder namespace_to_strbuilder(CodeNS self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 512 );
	namespace_to_strbuilder_ref( self, & result );
	return result;
}

void namespace_to_strbuilder_ref(CodeNS self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	strbuilder_append_fmt( result, "namespace %S\n{\n%SB\n}\n", self->Name, body_to_strbuilder(self->Body) );
}

StrBuilder code_op_to_strbuilder(CodeOperator self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Operator:
		case CT_Operator_Member:
			code_op_to_strbuilder_def( self, & result );
		break;
		case CT_Operator_Fwd:
		case CT_Operator_Member_Fwd:
			code_op_to_strbuilder_fwd( self, & result );
		break;
	}
	return result;
}

void code_op_to_strbuilder_def(CodeOperator self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

	if ( self->Specs )
	{
		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	if ( self->Attributes || self->Specs )
	{
		strbuilder_append_str( result, txt("\n") );
	}

	if ( self->ReturnType )
		strbuilder_append_fmt( result, "%SB %S (", typename_to_strbuilder(self->ReturnType), self->Name );

	if ( self->Params )
		strbuilder_append_fmt( result, "%SB)", params_to_strbuilder(self->Params) );

	else
		strbuilder_append_str( result, txt(")") );

	if ( self->Specs )
	{
		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	strbuilder_append_fmt( result, "\n{\n%SB\n}\n"
		, body_to_strbuilder(self->Body)
	);
}

void code_op_to_strbuilder_fwd(CodeOperator self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "%SB\n", attributes_to_strbuilder(self->Attributes) );

	if ( self->Specs )
	{
		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	if ( self->Attributes || self->Specs )
	{
		strbuilder_append_str( result, txt("\n") );
	}

	strbuilder_append_fmt( result, "%SB %S (", typename_to_strbuilder(self->ReturnType), self->Name );

	if ( self->Params )
		strbuilder_append_fmt( result, "%SB)", params_to_strbuilder(self->Params) );

	else
		strbuilder_append_fmt( result, ")" );

	if ( self->Specs )
	{
		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}
	}

	if ( self->InlineCmt )
		strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
	else
		strbuilder_append_str( result, txt(";\n") );
}

StrBuilder opcast_to_strbuilder(CodeOpCast self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 128 );
	switch ( self->Type )
	{
		case CT_Operator_Cast:
			opcast_to_strbuilder_def(self, & result );
		break;
		case CT_Operator_Cast_Fwd:
			opcast_to_strbuilder_fwd(self, & result );
		break;
	}
	return result;
}

void opcast_to_strbuilder_def(CodeOpCast self, StrBuilder* result )
{
	if ( self->Specs )
	{
		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, "%*s ", spec_str.Len, spec_str.Ptr );
			}
		}

		if ( self->Name.Ptr && self->Name.Len )
			strbuilder_append_fmt( result, "%S operator %SB()", self->Name, typename_to_strbuilder(self->ValueType) );
		else
			strbuilder_append_fmt( result, "operator %SB()", typename_to_strbuilder(self->ValueType) );

		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, " %.*s", spec_str.Len, spec_str.Ptr );
			}
		}

		strbuilder_append_fmt( result, "\n{\n%SB\n}\n", body_to_strbuilder(self->Body) );
		return;
	}

	if ( self->Name.Ptr && self->Name.Len )
		strbuilder_append_fmt( result, "%S operator %SB()\n{\n%SB\n}\n", self->Name, typename_to_strbuilder(self->ValueType), body_to_strbuilder(self->Body) );
	else
		strbuilder_append_fmt( result, "operator %SB()\n{\n%SB\n}\n", typename_to_strbuilder(self->ValueType), body_to_strbuilder(self->Body) );
}

void opcast_to_strbuilder_fwd(CodeOpCast self, StrBuilder* result )
{
	if ( self->Specs )
	{
		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( ! spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, "%*s ", spec_str.Len, spec_str.Ptr );
			}
		}

		strbuilder_append_fmt( result, "operator %SB()", typename_to_strbuilder(self->ValueType) );

		for ( Specifier* spec = begin_CodeSpecifiers(self->Specs); spec != end_CodeSpecifiers(self->Specs); spec = next_CodeSpecifiers(self->Specs, spec) )
		{
			if ( spec_is_trailing( * spec ) )
			{
				Str spec_str = spec_to_str( * spec );
				strbuilder_append_fmt( result, " %*s", spec_str.Len, spec_str.Ptr );
			}
		}

		if ( self->InlineCmt )
			strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
		else
			strbuilder_append_str( result, txt(";\n") );
		return;
	}

	if ( self->InlineCmt )
		strbuilder_append_fmt( result, "operator %SB();  %SB", typename_to_strbuilder(self->ValueType) );
	else
		strbuilder_append_fmt( result, "operator %SB();\n", typename_to_strbuilder(self->ValueType) );
}

StrBuilder params_to_strbuilder(CodeParams self)
{
	GEN_ASSERT(self);
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 128 );
	params_to_strbuilder_ref( self, & result );
	return result;
}

void params_to_strbuilder_ref( CodeParams self, StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->Macro )
	{
		// Related to parsing: ( <macro>, ... )
		strbuilder_append_str( result, self->Macro->Content );
		// Could also be: ( <macro> <type <name>, ... )
	}

	if ( self->Name.Ptr && self->Name.Len )
	{
		if ( self->ValueType == nullptr )
			strbuilder_append_fmt( result, " %S", self->Name );
		else
			strbuilder_append_fmt( result, " %SB %S", typename_to_strbuilder(self->ValueType), self->Name );

	}
	else if ( self->ValueType )
		strbuilder_append_fmt( result, " %SB", typename_to_strbuilder(self->ValueType) );

	if ( self->PostNameMacro )
	{
		strbuilder_append_fmt( result, " %SB", code_to_strbuilder(self->PostNameMacro) );
	}

	if ( self->Value )
		strbuilder_append_fmt( result, " = %SB", code_to_strbuilder(self->Value) );

	if ( self->NumEntries - 1 > 0 )
	{
		for ( CodeParams param = begin_CodeParams(self->Next); param != end_CodeParams(self->Next); param = next_CodeParams(self->Next, param) )
		{
			strbuilder_append_fmt( result, ", %SB", params_to_strbuilder(param) );
		}
	}
}

StrBuilder preprocess_to_strbuilder(CodePreprocessCond self)
{
	GEN_ASSERT(self);
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 256 );
	switch ( self->Type )
	{
		case CT_Preprocess_If:
			preprocess_to_strbuilder_if( self, & result );
		break;
		case CT_Preprocess_IfDef:
			preprocess_to_strbuilder_ifdef( self, & result );
		break;
		case CT_Preprocess_IfNotDef:
			preprocess_to_strbuilder_ifndef( self, & result );
		break;
		case CT_Preprocess_ElIf:
			preprocess_to_strbuilder_elif( self, & result );
		break;
		case CT_Preprocess_Else:
			preprocess_to_strbuilder_else( self, & result );
		break;
		case CT_Preprocess_EndIf:
			preprocess_to_strbuilder_endif( self, & result );
		break;
	}
	return result;
}

void preprocess_to_strbuilder_if(CodePreprocessCond cond, StrBuilder* result )
{
	GEN_ASSERT(cond);
	strbuilder_append_fmt( result, "#if %S", cond->Content );
}

void preprocess_to_strbuilder_ifdef(CodePreprocessCond cond, StrBuilder* result )
{
	GEN_ASSERT(cond);
	strbuilder_append_fmt( result, "#ifdef %S\n", cond->Content );
}

void preprocess_to_strbuilder_ifndef(CodePreprocessCond cond, StrBuilder* result )
{
	GEN_ASSERT(cond);
	strbuilder_append_fmt( result, "#ifndef %S", cond->Content );
}

void preprocess_to_strbuilder_elif(CodePreprocessCond cond, StrBuilder* result )
{
	GEN_ASSERT(cond);
	strbuilder_append_fmt( result, "#elif %S\n", cond->Content );
}

void preprocess_to_strbuilder_else(CodePreprocessCond cond, StrBuilder* result )
{
	GEN_ASSERT(cond);
	strbuilder_append_str( result, txt("#else\n") );
}

void preprocess_to_strbuilder_endif(CodePreprocessCond cond, StrBuilder* result )
{
	GEN_ASSERT(cond);
	strbuilder_append_str( result, txt("#endif\n") );
}

StrBuilder pragma_to_strbuilder(CodePragma self)
{
	GEN_ASSERT(self);
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 256 );
	pragma_to_strbuilder_ref( self, & result );
	return result;
}

void pragma_to_strbuilder_ref(CodePragma self, StrBuilder* result )
{
	strbuilder_append_fmt( result, "#pragma %S\n", self->Content );
}

StrBuilder specifiers_to_strbuilder(CodeSpecifiers self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 64 );
	specifiers_to_strbuilder_ref( self, & result );
	return result;
}

void specifiers_to_strbuilder_ref( CodeSpecifiers self, StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	s32 idx  = 0;
	s32 left = self->NumEntries;
	while ( left -- )
	{
		Specifier spec     = self->ArrSpecs[idx];
		Str       spec_str = spec_to_str( spec );
		if ( idx > 0 ) switch (spec) {
			case Spec_Ptr:
			case Spec_Ref:
			case Spec_RValue:
			break;

			default:
				strbuilder_append_str(result, txt(" "));
			break;
		}
		strbuilder_append_fmt( result, "%S", spec_str );
		idx++;
	}
	strbuilder_append_str(result, txt(" "));
}

StrBuilder struct_to_strbuilder(CodeStruct self)
{
	GEN_ASSERT(self);
	GEN_ASSERT(self);
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Struct:
			struct_to_strbuilder_def( self, & result );
		break;
		case CT_Struct_Fwd:
			struct_to_strbuilder_fwd( self, & result );
		break;
	}
	return result;
}

void struct_to_strbuilder_def( CodeStruct self, StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	strbuilder_append_str( result, txt("struct ") );

	if ( self->Attributes )
	{
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );
	}
	
	if ( self->Name.Len )
		strbuilder_append_str( result, self->Name );

	if (self->Specs && self->Specs.has(Spec_Final))
		strbuilder_append_str( result, txt(" final"));

	if ( self->ParentType )
	{
		Str access_level = access_spec_to_str( self->ParentAccess );

		strbuilder_append_fmt( result, " : %S %SB", self->Name, access_level, typename_to_strbuilder(self->ParentType) );

		CodeTypename interface = cast(CodeTypename, self->ParentType->Next);
		if ( interface )
			strbuilder_append_str( result, txt("\n") );

		while ( interface )
		{
			strbuilder_append_fmt( result, ", %SB", typename_to_strbuilder(interface) );
			interface = interface->Next ? cast( CodeTypename, interface->Next) : NullCode;
		}
	}

	if ( self->InlineCmt )
	{
		strbuilder_append_fmt( result, " // %S", self->InlineCmt->Content );
	}

	strbuilder_append_fmt( result, "\n{\n%SB\n}", body_to_strbuilder(self->Body) );

	if ( self->Parent == nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		strbuilder_append_str( result, txt(";\n"));
}

void struct_to_strbuilder_fwd( CodeStruct self, StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "struct %SB %S", attributes_to_strbuilder(self->Attributes), self->Name );

	else strbuilder_append_fmt( result, "struct %S", self->Name );

	if ( self->Parent == nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
	{
		if ( self->InlineCmt )
			strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content );
		else
			strbuilder_append_str( result, txt( ";\n") );
	}
}

StrBuilder template_to_strbuilder(CodeTemplate self)
{
	GEN_ASSERT(self);
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 1024 );
	template_to_strbuilder_ref( self, & result );
	return result;
}

void template_to_strbuilder_ref(CodeTemplate self, StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Params )
		strbuilder_append_fmt( result, "template< %SB >\n%SB", params_to_strbuilder(self->Params), code_to_strbuilder(self->Declaration) );
	else
		strbuilder_append_fmt( result, "template<>\n%SB", code_to_strbuilder(self->Declaration) );
}

StrBuilder typedef_to_strbuilder(CodeTypedef self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 128 );
	typedef_to_strbuilder_ref( self, & result );
	return result;
}

void typedef_to_strbuilder_ref(CodeTypedef self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	strbuilder_append_str( result, txt("typedef "));

	// Determines if the typedef is a function typename
	if ( self->UnderlyingType->ReturnType )
		strbuilder_append_string( result, code_to_strbuilder(self->UnderlyingType) );
	else
		strbuilder_append_fmt( result, "%SB %S", code_to_strbuilder(self->UnderlyingType), self->Name );

	if ( self->UnderlyingType->Type == CT_Typename && self->UnderlyingType->ArrExpr )
	{
		strbuilder_append_fmt( result, "[ %SB ];", code_to_strbuilder(self->UnderlyingType->ArrExpr) );

		Code next_arr_expr = self->UnderlyingType->ArrExpr->Next;
		while ( next_arr_expr )
		{
			strbuilder_append_fmt( result, "[ %SB ];", code_to_strbuilder(next_arr_expr) );
			next_arr_expr = next_arr_expr->Next;
		}
	}
	else
	{
		strbuilder_append_str( result, txt(";") );
	}

	if ( self->InlineCmt )
		strbuilder_append_fmt( result, "  %S", self->InlineCmt->Content);
	else
		strbuilder_append_str( result, txt("\n"));
}

StrBuilder typename_to_strbuilder(CodeTypename self)
{
	StrBuilder result = strbuilder_make_str( _ctx->Allocator_Temp, txt("") );
	typename_to_strbuilder_ref( self, & result );
	return result;
}

void typename_to_strbuilder_ref(CodeTypename self, StrBuilder* result )
{
	#if defined(GEN_USE_NEW_TYPENAME_PARSING)
		if ( self->ReturnType && self->Params )
		{
			if ( self->Attributes )
				strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );
			else
			{
				if ( self->Specs )
					strbuilder_append_fmt( result, "%SB ( %S ) ( %SB ) %SB", typename_to_strbuilder(self->ReturnType), self->Name, params_to_strbuilder(self->Params), specifiers_to_strbuilder(self->Specs) );
				else
					strbuilder_append_fmt( result, "%SB ( %S ) ( %SB )", typename_to_strbuilder(self->ReturnType), self->Name, params_to_strbuilder(self->Params) );
			}

			break;
		}
	#else
		if ( self->ReturnType && self->Params )
		{
			if ( self->Attributes )
				strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );
			else
			{
				if ( self->Specs )
					strbuilder_append_fmt( result, "%SB %S ( %SB ) %SB", typename_to_strbuilder(self->ReturnType), self->Name, params_to_strbuilder(self->Params), specifiers_to_strbuilder(self->Specs) );
				else
					strbuilder_append_fmt( result, "%SB %S ( %SB )", typename_to_strbuilder(self->ReturnType), self->Name, params_to_strbuilder(self->Params) );
			}

			return;
		}
	#endif

	if ( self->Attributes )
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

	switch ( self->TypeTag )
	{
		case Tag_Class  : strbuilder_append_str( result, txt("class "));  break;
		case Tag_Enum   : strbuilder_append_str( result, txt("enum "));   break;
		case Tag_Struct : strbuilder_append_str( result, txt("struct ")); break;
		case Tag_Union  : strbuilder_append_str( result, txt("union "));  break;
		default:
			break;
	}

	if ( self->Specs )
		strbuilder_append_fmt( result, "%S %SB", self->Name, specifiers_to_strbuilder(self->Specs) );
	else
		strbuilder_append_fmt( result, "%S", self->Name );

	if ( self->IsParamPack )
		strbuilder_append_str( result, txt("..."));
}

StrBuilder union_to_strbuilder(CodeUnion self)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 512 );
	switch ( self->Type )
	{
		case CT_Union:
			union_to_strbuilder_def( self, & result );
		break;
		case CT_Union_Fwd:
			union_to_strbuilder_fwd( self, & result );
		break;
	}
	return result;
}

void union_to_strbuilder_def(CodeUnion self, StrBuilder* result )
{
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	strbuilder_append_str( result, txt("union ") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

	if ( self->Name.Len )
	{
		strbuilder_append_fmt( result, "%S\n{\n%SB\n}"
			, self->Name
			, body_to_strbuilder(self->Body)
		);
	}
	else
	{
		// Anonymous union
		strbuilder_append_fmt( result, "\n{\n%SB\n}"
			, body_to_strbuilder(self->Body)
		);
	}

	if ( self->Parent == nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		strbuilder_append_str( result, txt(";\n"));
}

void union_to_strbuilder_fwd(CodeUnion self, StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	strbuilder_append_str( result, txt("union ") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

	if ( self->Name.Len )
	{
		strbuilder_append_fmt( result, "%S", self->Name);
	}

	if ( self->Parent == nullptr || ( self->Parent->Type != CT_Typedef && self->Parent->Type != CT_Variable ) )
		strbuilder_append_str( result, txt(";\n"));
}

StrBuilder using_to_strbuilder(CodeUsing self)
{
	GEN_ASSERT(self);
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 128 );
	switch ( self->Type )
	{
		case CT_Using:
			using_to_strbuilder_ref( self, & result );
		break;
		case CT_Using_Namespace:
			using_to_strbuilder_ns( self, & result );
		break;
	}
	return result;
}

void using_to_strbuilder_ref(CodeUsing self, StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes )
		strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

	if ( self->UnderlyingType )
	{
		strbuilder_append_fmt( result, "using %S = %SB", self->Name, typename_to_strbuilder(self->UnderlyingType) );

		if ( self->UnderlyingType->ArrExpr )
		{
			strbuilder_append_fmt( result, "[ %SB ]", code_to_strbuilder(self->UnderlyingType->ArrExpr) );

			Code next_arr_expr = self->UnderlyingType->ArrExpr->Next;
			while ( next_arr_expr )
			{
				strbuilder_append_fmt( result, "[ %SB ]", code_to_strbuilder(next_arr_expr) );
				next_arr_expr = next_arr_expr->Next;
			}
		}

		strbuilder_append_str( result, txt(";") );
	}
	else
		strbuilder_append_fmt( result, "using %S;", self->Name );

	if ( self->InlineCmt )
		strbuilder_append_fmt( result, "  %S\n", self->InlineCmt->Content );
	else
		strbuilder_append_str( result, txt("\n"));
}

inline
void using_to_strbuilder_ns(CodeUsing self, StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->InlineCmt )
		strbuilder_append_fmt( result, "using namespace $SC;  %S", self->Name, self->InlineCmt->Content );
	else
		strbuilder_append_fmt( result, "using namespace %S;\n", self->Name );
}

inline
StrBuilder var_to_strbuilder(CodeVar self)
{
	GEN_ASSERT(self);
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, 256 );
	var_to_strbuilder_ref( self, & result );
	return result;
}

neverinline
void var_to_strbuilder_ref(CodeVar self, StrBuilder* result )
{
	GEN_ASSERT(self);
	GEN_ASSERT(result);
	if ( self->Parent && self->Parent->Type == CT_Variable )
	{
		// Its a comma-separated variable ( a NextVar )

		if ( self->Specs )
			strbuilder_append_fmt( result, "%SB ", specifiers_to_strbuilder(self->Specs) );

		strbuilder_append_str( result, self->Name );

		if ( self->ValueType && self->ValueType->ArrExpr )
		{
			strbuilder_append_fmt( result, "[ %SB ]", code_to_strbuilder(self->ValueType->ArrExpr) );

			Code next_arr_expr = self->ValueType->ArrExpr->Next;
			while ( next_arr_expr )
			{
				strbuilder_append_fmt( result, "[ %SB ]", code_to_strbuilder(next_arr_expr) );
				next_arr_expr = next_arr_expr->Next;
			}
		}

		if ( self->Value )
		{
			if ( self->VarParenthesizedInit )
				strbuilder_append_fmt( result, "( %SB ", code_to_strbuilder(self->Value) );
			else
				strbuilder_append_fmt( result, " = %SB", code_to_strbuilder(self->Value) );
		}

		// Keep the chain going...
		if ( self->NextVar )
			strbuilder_append_fmt( result, ", %SB", var_to_strbuilder(self->NextVar) );

		if ( self->VarParenthesizedInit )
			strbuilder_append_str( result, txt(" )"));

		return;
	}

	if ( bitfield_is_set( u32, self->ModuleFlags, ModuleFlag_Export ))
		strbuilder_append_str( result, txt("export ") );

	if ( self->Attributes || self->Specs )
	{
		if ( self->Attributes )
			strbuilder_append_fmt( result, "%SB ", attributes_to_strbuilder(self->Attributes) );

		if ( self->Specs )
			strbuilder_append_fmt( result, "%SB", specifiers_to_strbuilder(self->Specs) );

		strbuilder_append_fmt( result, "%SB %S", typename_to_strbuilder(self->ValueType), self->Name );

		if ( self->ValueType && self->ValueType->ArrExpr )
		{
			strbuilder_append_fmt( result, "[ %SB ]", code_to_strbuilder(self->ValueType->ArrExpr) );

			Code next_arr_expr = self->ValueType->ArrExpr->Next;
			while ( next_arr_expr )
			{
				strbuilder_append_fmt( result, "[ %SB ]", code_to_strbuilder(next_arr_expr) );
				next_arr_expr = next_arr_expr->Next;
			}
		}

		if ( self->BitfieldSize )
			strbuilder_append_fmt( result, " : %SB", code_to_strbuilder(self->BitfieldSize) );

		if ( self->Value )
		{
			if ( self->VarParenthesizedInit )
				strbuilder_append_fmt( result, "( %SB ", code_to_strbuilder(self->Value) );
			else
				strbuilder_append_fmt( result, " = %SB", code_to_strbuilder(self->Value) );
		}

		if ( self->NextVar )
			strbuilder_append_fmt( result, ", %SB", var_to_strbuilder(self->NextVar) );

		if ( self->VarParenthesizedInit )
			strbuilder_append_str( result, txt(" )"));

		if ( self->InlineCmt )
			strbuilder_append_fmt( result, ";  %S", self->InlineCmt->Content);
		else
			strbuilder_append_str( result, txt(";\n") );

		return;
	}

	if ( self->BitfieldSize )
		strbuilder_append_fmt( result, "%SB %S : %SB", typename_to_strbuilder(self->ValueType), self->Name, code_to_strbuilder(self->BitfieldSize) );

	else if ( self->ValueType && self->ValueType->ArrExpr )
	{
		strbuilder_append_fmt( result, "%SB %S[ %SB ]", typename_to_strbuilder(self->ValueType), self->Name, code_to_strbuilder(self->ValueType->ArrExpr) );

		Code next_arr_expr = self->ValueType->ArrExpr->Next;
		while ( next_arr_expr )
		{
			strbuilder_append_fmt( result, "[ %SB ]", code_to_strbuilder(next_arr_expr) );
			next_arr_expr = next_arr_expr->Next;
		}
	}

	else
		strbuilder_append_fmt( result, "%SB %S", typename_to_strbuilder(self->ValueType), self->Name );

	if ( self->Value )
	{
		if ( self->VarParenthesizedInit )
			strbuilder_append_fmt( result, "( %SB ", code_to_strbuilder(self->Value) );
		else
			strbuilder_append_fmt( result, " = %SB", code_to_strbuilder(self->Value) );
	}

	if ( self->NextVar )
		strbuilder_append_fmt( result, ", %SB", var_to_strbuilder( self->NextVar) );

	if ( self->VarParenthesizedInit )
		strbuilder_append_str( result, txt(" )"));

	strbuilder_append_str( result, txt(";") );

	if ( self->InlineCmt )
		strbuilder_append_fmt( result, "  %S", self->InlineCmt->Content);
	else
		strbuilder_append_str( result, txt("\n"));
}

#pragma endregion AST

#pragma region Interface

internal void parser_init();
internal void parser_deinit();

internal
void* fallback_allocator_proc( void* allocator_data, AllocType type, ssize size, ssize alignment, void* old_memory, ssize old_size, u64 flags )
{
	GEN_ASSERT(_ctx);
	GEN_ASSERT(_ctx->Fallback_AllocatorBuckets);
	Arena* last = array_back(_ctx->Fallback_AllocatorBuckets);

	switch ( type )
	{
		case EAllocation_ALLOC:
		{
			if ( ( last->TotalUsed + size ) > last->TotalSize )
			{
				Arena bucket = arena_init_from_allocator( heap(), _ctx->InitSize_Fallback_Allocator_Bucket_Size );

				if ( bucket.PhysicalStart == nullptr )
					GEN_FATAL( "Failed to create bucket for Fallback_AllocatorBuckets");

				if ( ! array_append( _ctx->Fallback_AllocatorBuckets, bucket ) )
					GEN_FATAL( "Failed to append bucket to Fallback_AllocatorBuckets");

				last = array_back(_ctx->Fallback_AllocatorBuckets);
			}

			return alloc_align( arena_allocator_info(last), size, alignment );
		}
		case EAllocation_FREE:
		{
			// Doesn't recycle.
		}
		break;
		case EAllocation_FREE_ALL:
		{
			// Memory::cleanup instead.
		}
		break;
		case EAllocation_RESIZE:
		{
			if ( last->TotalUsed + size > last->TotalSize )
			{
				Arena bucket = arena_init_from_allocator( heap(), _ctx->InitSize_Fallback_Allocator_Bucket_Size );

				if ( bucket.PhysicalStart == nullptr )
					GEN_FATAL( "Failed to create bucket for Fallback_AllocatorBuckets");

				if ( ! array_append( _ctx->Fallback_AllocatorBuckets, bucket ) )
					GEN_FATAL( "Failed to append bucket to Fallback_AllocatorBuckets");

				last = array_back( _ctx->Fallback_AllocatorBuckets);
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

internal
void define_constants()
{
	// We only initalize these if there is no base context.
	if ( context_counter > 0 )
		return;

	Code_Global          = make_code();
	Code_Global->Name    = cache_str( txt("Global Code") );
	Code_Global->Content = Code_Global->Name;

	Code_Invalid = make_code();
	code_set_global(Code_Invalid);

	t_empty       = (CodeTypename) make_code();
	t_empty->Type = CT_Typename;
	t_empty->Name = cache_str( txt("") );
	code_set_global(cast(Code, t_empty));

	access_private       = make_code();
	access_private->Type = CT_Access_Private;
	access_private->Name = cache_str( txt("private:\n") );
	code_set_global(cast(Code, access_private));

	access_protected       = make_code();
	access_protected->Type = CT_Access_Protected;
	access_protected->Name = cache_str( txt("protected:\n") );
	code_set_global(access_protected);

	access_public       = make_code();
	access_public->Type = CT_Access_Public;
	access_public->Name = cache_str( txt("public:\n") );
	code_set_global(access_public);

	Str api_export_str = code(GEN_API_Export_Code);
	attrib_api_export = def_attributes( api_export_str );
	code_set_global(cast(Code, attrib_api_export));

	Str api_import_str = code(GEN_API_Import_Code);
	attrib_api_import = def_attributes( api_import_str );
	code_set_global(cast(Code, attrib_api_import));

	module_global_fragment          = make_code();
	module_global_fragment->Type    = CT_Untyped;
	module_global_fragment->Name    = cache_str( txt("module;") );
	module_global_fragment->Content = module_global_fragment->Name;
	code_set_global(cast(Code, module_global_fragment));

	module_private_fragment          = make_code();
	module_private_fragment->Type    = CT_Untyped;
	module_private_fragment->Name    = cache_str( txt("module : private;") );
	module_private_fragment->Content = module_private_fragment->Name;
	code_set_global(cast(Code, module_private_fragment));

	fmt_newline = make_code();
	fmt_newline->Type = CT_NewLine;
	code_set_global((Code)fmt_newline);

	pragma_once          = (CodePragma) make_code();
	pragma_once->Type    = CT_Preprocess_Pragma;
	pragma_once->Name    = cache_str( txt("once") );
	pragma_once->Content = pragma_once->Name;
	code_set_global((Code)pragma_once);

	param_varadic            = (CodeParams) make_code();
	param_varadic->Type      = CT_Parameters;
	param_varadic->Name      = cache_str( txt("...") );
	param_varadic->ValueType = t_empty;
	code_set_global((Code)param_varadic);

	preprocess_else = (CodePreprocessCond) make_code();
	preprocess_else->Type = CT_Preprocess_Else;
	code_set_global((Code)preprocess_else);

	preprocess_endif = (CodePreprocessCond) make_code();
	preprocess_endif->Type = CT_Preprocess_EndIf;
	code_set_global((Code)preprocess_endif);

	Str auto_str     = txt("auto");     t_auto     = def_type( auto_str );     code_set_global( t_auto );
	Str void_str     = txt("void");     t_void     = def_type( void_str );     code_set_global( t_void );
	Str int_str      = txt("int");      t_int      = def_type( int_str );      code_set_global( t_int  );
	Str bool_str     = txt("bool");     t_bool     = def_type( bool_str );     code_set_global( t_bool );
	Str char_str     = txt("char");     t_char     = def_type( char_str );     code_set_global( t_char );
	Str wchar_str    = txt("wchar_t");  t_wchar_t  = def_type( wchar_str );    code_set_global( t_wchar_t );
	Str class_str    = txt("class");    t_class    = def_type( class_str );    code_set_global( t_class );
	Str typename_str = txt("typename"); t_typename = def_type( typename_str ); code_set_global( t_typename );

#ifdef GEN_DEFINE_LIBRARY_CODE_CONSTANTS
	t_b32 = def_type( name(b32) ); code_set_global( t_b32 );

	Str s8_str  = txt("s8");  t_s8  = def_type( s8_str ); code_set_global( t_s8 );
	Str s16_str = txt("s16"); t_s16 = def_type( s16_str ); code_set_global( t_s16 );
	Str s32_str = txt("s32"); t_s32 = def_type( s32_str ); code_set_global( t_s32 );
	Str s64_str = txt("s64"); t_s64 = def_type( s64_str ); code_set_global( t_s64 );

	Str u8_str  = txt("u8");  t_u8  = def_type( u8_str );  code_set_global( t_u8 );
	Str u16_str = txt("u16"); t_u16 = def_type( u16_str ); code_set_global( t_u16 );
	Str u32_str = txt("u32"); t_u32 = def_type( u32_str ); code_set_global( t_u32 );
	Str u64_str = txt("u64"); t_u64 = def_type( u64_str ); code_set_global( t_u64 );

	Str ssize_str = txt("ssize"); t_ssize = def_type( ssize_str ); code_set_global( t_ssize );
	Str usize_str = txt("usize"); t_usize = def_type( usize_str ); code_set_global( t_usize );

	Str f32_str = txt("f32"); t_f32 = def_type( f32_str ); code_set_global( t_f32 );
	Str f64_str = txt("f64"); t_f64 = def_type( f64_str ); code_set_global( t_f64 );
#endif

	spec_const            = def_specifier( Spec_Const);            code_set_global( cast(Code, spec_const ));
	spec_consteval        = def_specifier( Spec_Consteval);        code_set_global( cast(Code, spec_consteval ));
	spec_constexpr        = def_specifier( Spec_Constexpr);        code_set_global( cast(Code, spec_constexpr ));
	spec_constinit        = def_specifier( Spec_Constinit);        code_set_global( cast(Code, spec_constinit ));
	spec_extern_linkage   = def_specifier( Spec_External_Linkage); code_set_global( cast(Code, spec_extern_linkage ));
	spec_final            = def_specifier( Spec_Final);            code_set_global( cast(Code, spec_final ));
	spec_FORCEINLINE      = def_specifier( Spec_ForceInline);      code_set_global( cast(Code, spec_FORCEINLINE ));
	spec_global           = def_specifier( Spec_Global);           code_set_global( cast(Code, spec_global ));
	spec_inline           = def_specifier( Spec_Inline);           code_set_global( cast(Code, spec_inline ));
	spec_internal_linkage = def_specifier( Spec_Internal_Linkage); code_set_global( cast(Code, spec_internal_linkage ));
	spec_local_persist    = def_specifier( Spec_Local_Persist);    code_set_global( cast(Code, spec_local_persist ));
	spec_mutable          = def_specifier( Spec_Mutable);          code_set_global( cast(Code, spec_mutable ));
	spec_neverinline      = def_specifier( Spec_NeverInline);      code_set_global( cast(Code, spec_neverinline ));
	spec_noexcept         = def_specifier( Spec_NoExceptions);     code_set_global( cast(Code, spec_noexcept ));
	spec_override         = def_specifier( Spec_Override);         code_set_global( cast(Code, spec_override ));
	spec_ptr              = def_specifier( Spec_Ptr);              code_set_global( cast(Code, spec_ptr ));
	spec_pure             = def_specifier( Spec_Pure);             code_set_global( cast(Code, spec_pure ));
	spec_ref              = def_specifier( Spec_Ref);              code_set_global( cast(Code, spec_ref ));
	spec_register         = def_specifier( Spec_Register);         code_set_global( cast(Code, spec_register ));
	spec_rvalue           = def_specifier( Spec_RValue);           code_set_global( cast(Code, spec_rvalue ));
	spec_static_member    = def_specifier( Spec_Static);           code_set_global( cast(Code, spec_static_member ));
	spec_thread_local     = def_specifier( Spec_Thread_Local);     code_set_global( cast(Code, spec_thread_local ));
	spec_virtual          = def_specifier( Spec_Virtual);          code_set_global( cast(Code, spec_virtual ));
	spec_volatile         = def_specifier( Spec_Volatile);         code_set_global( cast(Code, spec_volatile ));

	spec_local_persist = def_specifiers( 1, Spec_Local_Persist );
	code_set_global(cast(Code, spec_local_persist));

	if (enum_underlying_macro.Name.Len == 0) {
		enum_underlying_macro.Name  = txt("enum_underlying");
		enum_underlying_macro.Type  = MT_Expression;
		enum_underlying_macro.Flags = MF_Functional;
	}
	register_macro(enum_underlying_macro);
}

void init(Context* ctx)
{
	do_once() {
		context_counter = 0;
	}
	AllocatorInfo fallback_allocator = { & fallback_allocator_proc, nullptr };
	
	b32 using_fallback_allocator = false;
	if (ctx->Allocator_DyanmicContainers.Proc == nullptr) {
		ctx->Allocator_DyanmicContainers = fallback_allocator;
		using_fallback_allocator = true;
	}
	if (ctx->Allocator_Pool.Proc == nullptr ) {
		ctx->Allocator_Pool = fallback_allocator;
		using_fallback_allocator = true;
	}
	if (ctx->Allocator_StrCache.Proc == nullptr) {
		ctx->Allocator_StrCache = fallback_allocator;
		using_fallback_allocator = true;
	}
	if (ctx->Allocator_Temp.Proc == nullptr) {
		ctx->Allocator_Temp = fallback_allocator;
		using_fallback_allocator = true;
	}
	// Setup fallback allocator
	if (using_fallback_allocator)
	{
		ctx->Fallback_AllocatorBuckets = array_init_reserve(Arena, heap(), 128 );
		if ( ctx->Fallback_AllocatorBuckets == nullptr )
			GEN_FATAL( "Failed to reserve memory for Fallback_AllocatorBuckets");

		Arena bucket = arena_init_from_allocator( heap(), ctx->InitSize_Fallback_Allocator_Bucket_Size );
		if ( bucket.PhysicalStart == nullptr )
			GEN_FATAL( "Failed to create first bucket for Fallback_AllocatorBuckets");

		array_append( ctx->Fallback_AllocatorBuckets, bucket );
	}

	if (ctx->Max_CommentLineLength == 0) {
		ctx->Max_CommentLineLength = 1024;
	}
	if (ctx->Max_StrCacheLength == 0) {
		ctx->Max_StrCacheLength = kilobytes(512);
	}

	if (ctx->InitSize_BuilderBuffer == 0) {
		ctx->InitSize_BuilderBuffer = megabytes(2);
	}
	if (ctx->InitSize_CodePoolsArray == 0) { 
		ctx->InitSize_CodePoolsArray = 16; 
	}
	if (ctx->InitSize_StringArenasArray == 0) {
		ctx->InitSize_StringArenasArray = 16; 
	}
	if (ctx->CodePool_NumBlocks == 0) {
		ctx->CodePool_NumBlocks = kilobytes(16);
	}

	if (ctx->InitSize_LexerTokens == 0 ) {
		ctx->InitSize_LexerTokens = kilobytes(64);
	}
	if (ctx->SizePer_StringArena == 0) {
		ctx->SizePer_StringArena = megabytes(1);
	}

	if (ctx->InitSize_Fallback_Allocator_Bucket_Size == 0) { 
		ctx->InitSize_Fallback_Allocator_Bucket_Size = megabytes(8);
	}

	// Override the current context (user has to put it back if unwanted).
	_ctx = ctx;

	// Setup the arrays
	{
		ctx->CodePools = array_init_reserve(Pool, ctx->Allocator_DyanmicContainers, ctx->InitSize_CodePoolsArray );
		if ( ctx->CodePools == nullptr )
			GEN_FATAL( "gen::init: Failed to initialize the CodePools array" );

		ctx->StringArenas = array_init_reserve(Arena, ctx->Allocator_DyanmicContainers, ctx->InitSize_StringArenasArray );
		if ( ctx->StringArenas == nullptr )
			GEN_FATAL( "gen::init: Failed to initialize the StringArenas array" );
	}
	// Setup the code pool and code entries arena.
	{
		Pool code_pool = pool_init( ctx->Allocator_Pool, ctx->CodePool_NumBlocks, sizeof(AST) );
		if ( code_pool.PhysicalStart == nullptr )
			GEN_FATAL( "gen::init: Failed to initialize the code pool" );
		array_append( ctx->CodePools, code_pool );

		// TODO(Ed): Eventually the string arenas needs to be phased out for a dedicated string slab allocator
		Arena strbuilder_arena = arena_init_from_allocator( ctx->Allocator_StrCache, ctx->SizePer_StringArena );
		if ( strbuilder_arena.PhysicalStart == nullptr )
			GEN_FATAL( "gen::init: Failed to initialize the string arena" );
		array_append( ctx->StringArenas, strbuilder_arena );
	}
	// Setup the hash tables
	{
		ctx->StrCache = hashtable_init(StrCached, ctx->Allocator_DyanmicContainers);
		if ( ctx->StrCache.Entries == nullptr )
			GEN_FATAL( "gen::init: Failed to initialize the StringCache");

		ctx->Macros = hashtable_init(Macro, ctx->Allocator_DyanmicContainers);
		if (ctx->Macros.Hashes == nullptr || ctx->Macros.Entries == nullptr) {
			GEN_FATAL( "gen::init: Failed to initialize the PreprocessMacros table" );
		}
	}

	define_constants();
	parser_init();

	++ context_counter;
}

void deinit(Context* ctx)
{
	GEN_ASSERT(context_counter);
	GEN_ASSERT_MSG(context_counter > 0, "Attempted to deinit a context that for some reason wan't accounted for!");
	usize index = 0;
	usize left  = array_num(ctx->CodePools);
	do
	{
		Pool* code_pool = & ctx->CodePools[index];
		pool_free(code_pool);
		index++;
	}
	while ( left--, left );

	index = 0;
	left  = array_num(ctx->StringArenas);
	do
	{
		Arena* strbuilder_arena = & ctx->StringArenas[index];
		arena_free(strbuilder_arena);
		index++;
	}
	while ( left--, left );

	hashtable_destroy(ctx->StrCache);

	array_free( ctx->CodePools);
	array_free( ctx->StringArenas);

	hashtable_destroy(ctx->Macros);

	left  = array_num( ctx->Fallback_AllocatorBuckets);
	if (left)
	{
		index = 0;
		do
		{
			Arena* bucket = & ctx->Fallback_AllocatorBuckets[ index ];
			arena_free(bucket);
			index++;
		}
		while ( left--, left );
		array_free( ctx->Fallback_AllocatorBuckets);
	}
	parser_deinit();

	if (_ctx == ctx) 
		_ctx = nullptr;
	-- context_counter;

	Context wipe = {};
	* ctx = wipe;
}

Context* get_context() { 
	return _ctx;
}

void reset(Context* ctx)
{
	s32 index = 0;
	s32 left  = array_num(ctx->CodePools);
	do
	{
		Pool* code_pool = & ctx->CodePools[index];
		pool_clear(code_pool);
		index++;
	}
	while ( left--, left );

	index = 0;
	left  = array_num(ctx->StringArenas);
	do
	{
		Arena* strbuilder_arena = & ctx->StringArenas[index];
		strbuilder_arena->TotalUsed = 0;;
		index++;
	}
	while ( left--, left );

	hashtable_clear(ctx->StrCache);
	hashtable_clear(ctx->Macros);
	define_constants();
}

void set_context(Context* new_ctx) {
	GEN_ASSERT(new_ctx);
	_ctx = new_ctx;
}

AllocatorInfo get_cached_str_allocator( s32 str_length )
{
	Arena* last     = array_back(_ctx->StringArenas);
	usize  size_req = str_length + sizeof(StrBuilderHeader) + sizeof(char*);
	if ( last->TotalUsed + scast(ssize, size_req) > last->TotalSize )
	{
		Arena new_arena = arena_init_from_allocator( _ctx->Allocator_StrCache, _ctx->SizePer_StringArena );
		if ( ! array_append( _ctx->StringArenas, new_arena ) )
			GEN_FATAL( "gen::get_cached_str_allocator: Failed to allocate a new string arena" );

		last = array_back( _ctx->StringArenas);
	}
	return arena_allocator_info(last);
}

// Will either make or retrive a code string.
StrCached cache_str( Str str )
{
	if (str.Len > _ctx->Max_StrCacheLength) {
		// Do not cache the string, just shove into the arena and and return it.
		Str result = strbuilder_to_str( strbuilder_make_str( get_cached_str_allocator( str.Len ), str ));
		return result;
	}
	u64 key = crc32( str.Ptr, str.Len ); {
		StrCached* result = hashtable_get( _ctx->StrCache, key );
		if ( result )
			return * result;
	}
	Str result = strbuilder_to_str( strbuilder_make_str( get_cached_str_allocator( str.Len ), str ));
	hashtable_set( _ctx->StrCache, key, result );
	return result;
}

// Used internally to retireve a Code object form the CodePool.
Code make_code()
{
	Pool* allocator = array_back( _ctx->CodePools);
	if ( allocator->FreeList == nullptr )
	{
		Pool code_pool = pool_init( _ctx->Allocator_Pool, _ctx->CodePool_NumBlocks, sizeof(AST) );

		if ( code_pool.PhysicalStart == nullptr )
			GEN_FATAL( "gen::make_code: Failed to allocate a new code pool - CodePool allcoator returned nullptr." );

		if ( ! array_append( _ctx->CodePools, code_pool ) )
			GEN_FATAL( "gen::make_code: Failed to allocate a new code pool - CodePools failed to append new pool." );

		allocator = array_back( _ctx->CodePools);
	}
	Code result = { rcast( AST*, alloc( pool_allocator_info(allocator), sizeof(AST) )) };
	mem_set( rcast(void*, cast(AST*, result)), 0, sizeof(AST) );
	return result;
}

Macro* lookup_macro( Str name ) {
	u32 key = crc32( name.Ptr, name.Len );
	return hashtable_get( _ctx->Macros, key );
}

void register_macro( Macro macro ) {
	GEN_ASSERT_NOT_NULL(macro.Name.Ptr);
	GEN_ASSERT(macro.Name.Len > 0);
	u32 key = crc32( macro.Name.Ptr, macro.Name.Len );
	macro.Name = cache_str(macro.Name);
	hashtable_set( _ctx->Macros, key, macro );
}

void register_macros( s32 num, ... )
{
	GEN_ASSERT(num > 0);
	va_list va;
	va_start(va, num);
	do
	{
		Macro macro = va_arg(va, Macro);
		GEN_ASSERT_NOT_NULL(macro.Name.Ptr);
		GEN_ASSERT(macro.Name.Len > 0);
		macro.Name = cache_str(macro.Name);

		u32 key = crc32( macro.Name.Ptr, macro.Name.Len );
		hashtable_set( _ctx->Macros, key, macro );
	}
	while (num--, num > 0);
	va_end(va);
}

void register_macros_arr( s32 num,  Macro* macros )
{
	GEN_ASSERT(num > 0);
	do
	{
		Macro macro = * macros;
		GEN_ASSERT_NOT_NULL(macro.Name.Ptr);
		GEN_ASSERT(macro.Name.Len > 0);
		macro.Name = cache_str(macro.Name);

		u32 key = crc32( macro.Name.Ptr, macro.Name.Len );
		hashtable_set( _ctx->Macros, key, macro );
		++ macros;
	}
	while (num--, num > 0);
}

#pragma region Upfront

enum OpValidateResult : u32
{
	OpValResult_Fail,
	OpValResult_Global,
	OpValResult_Member
};

internal neverinline
OpValidateResult operator__validate( Operator op, CodeParams params_code, CodeTypename ret_type, CodeSpecifiers specifier )
{
	if ( op == Op_Invalid )
	{
		log_failure("gen::def_operator: op cannot be invalid");
		return OpValResult_Fail;
	}

#pragma region Helper Macros
#	define check_params()                                                                                                   \
	if ( ! params_code )                                                                                                    \
	{                                                                                                                       \
		log_failure("gen::def_operator: params is null and operator %S requires it", operator_to_str(op));                  \
		return OpValResult_Fail;                                                                                            \
	}                                                                                                                       \
	if ( params_code->Type != CT_Parameters )                                                                               \
	{                                                                                                                       \
		log_failure("gen::def_operator: params is not of Parameters type - %S", code_debug_str( cast(Code, params_code)));  \
		return OpValResult_Fail;                                                                                            \
	}

#	define check_param_eq_ret()                                                                            \
	if ( ! is_member_symbol && ! code_is_equal(cast(Code, params_code->ValueType), cast(Code, ret_type)) ) \
	{                                                                                                      \
		log_failure("gen::def_operator: operator %S requires first parameter to equal return type\n"       \
			"param types: %S\n"                                                                            \
			"return type: %S",                                                                             \
			operator_to_str(op),                                                                           \
			code_debug_str(cast(Code, params_code)),                                                       \
			code_debug_str(cast(Code, ret_type))                                                           \
		);                                                                                                 \
		return OpValResult_Fail;                                                                           \
	}
#pragma endregion Helper Macros

	if ( ! ret_type )
	{
		log_failure("gen::def_operator: ret_type is null but is required by operator %S", operator_to_str(op));
	}

	if ( ret_type->Type != CT_Typename )
	{
		log_failure("gen::def_operator: operator %S - ret_type is not of typename type - %S",
			operator_to_str(op),
			code_debug_str(cast(Code, ret_type))
		);
		return OpValResult_Fail;
	}

	bool is_member_symbol = false;

	switch ( op )
	{
#	define specs( ... ) num_args( __VA_ARGS__ ), __VA_ARGS__
		case Op_Assign:
			check_params();

			if ( params_code->NumEntries > 1 )
			{
				log_failure("gen::def_operator: "
					"operator %S does not support non-member definition (more than one parameter provided) - %S",
					operator_to_str(op),
					code_debug_str(cast(Code, params_code))
				);
				return OpValResult_Fail;
			}

			is_member_symbol = true;
			break;

		case Op_Assign_Add:
		case Op_Assign_Subtract:
		case Op_Assign_Multiply:
		case Op_Assign_Divide:
		case Op_Assign_Modulo:
		case Op_Assign_BAnd:
		case Op_Assign_BOr:
		case Op_Assign_BXOr:
		case Op_Assign_LShift:
		case Op_Assign_RShift:
			check_params();

			if ( params_code->NumEntries == 1 )
				is_member_symbol = true;

			else
				check_param_eq_ret();

			if (params_code->NumEntries > 2 )
			{
				log_failure("gen::def_operator: operator %S may not be defined with more than two parametes - param count; %d\n%S"
					, operator_to_str(op)
					, params_code->NumEntries
					, code_debug_str(cast(Code, params_code))
				);
				return OpValResult_Fail;
			}
			break;

		case Op_Increment:
		case Op_Decrement:
			// If its not set, it just means its a prefix member op.
			if ( params_code )
			{
				if ( params_code->Type != CT_Parameters )
				{
					log_failure("gen::def_operator: operator %S params code provided is not of Parameters type - %S"
						, operator_to_str(op)
						, code_debug_str(cast(Code, params_code))
					);
					return OpValResult_Fail;
				}

				switch ( params_code->NumEntries )
				{
					case 1:
						if ( code_is_equal((Code)params_code->ValueType, (Code)t_int ) )
							is_member_symbol = true;

						else
							check_param_eq_ret();
						break;

					case 2:
						check_param_eq_ret();

						if ( ! code_is_equal((Code)params_get(params_code, 1), (Code)t_int ) )
						{
							log_failure("gen::def_operator: "
								"operator %S requires second parameter of non-member definition to be int for post-decrement",
								operator_to_str(op)
							);
							return OpValResult_Fail;
						}
						break;

					default:
						log_failure("gen::def_operator: operator %S recieved unexpected number of parameters recived %d instead of 0-2"
							, operator_to_str(op)
							, params_code->NumEntries
						);
						return OpValResult_Fail;
				}
			}
			break;

		case Op_Unary_Plus:
		case Op_Unary_Minus:
			if ( ! params_code )
				is_member_symbol = true;

			else
			{
				if ( params_code->Type != CT_Parameters )
				{
					log_failure("gen::def_operator: params is not of Parameters type - %S", code_debug_str((Code)params_code));
					return OpValResult_Fail;
				}

				if ( code_is_equal((Code)params_code->ValueType, (Code)ret_type ) )
				{
					log_failure("gen::def_operator: "
						"operator %S is non-member symbol yet first paramter does not equal return type\n"
						"param type: %S\n"
						"return type: %S\n"
						, code_debug_str((Code)params_code)
						, code_debug_str((Code)ret_type)
					);
					return OpValResult_Fail;
				}

				if ( params_code->NumEntries > 1 )
				{
					log_failure("gen::def_operator: operator %S may not have more than one parameter - param count: %d"
						, operator_to_str(op)
						, params_code->NumEntries
					);
					return OpValResult_Fail;
				}
			}
			break;

		case Op_BNot:
		{
			// Some compilers let you do this...
		#if 0
			if ( ! ret_type.is_equal( t_bool) )
			{
				log_failure( "gen::def_operator: operator %S return type is not a boolean - %S", operator_to_str(op) code_debug_str(params_code) );
				return OpValidateResult::Fail;
			}
		#endif

			if ( ! params_code )
				is_member_symbol = true;

			else
			{
				if ( params_code->Type != CT_Parameters )
				{
					log_failure( "gen::def_operator: operator %S - params is not of Parameters type - %S", operator_to_str(op), code_debug_str((Code)params_code) );
					return OpValResult_Fail;
				}

				if ( params_code->NumEntries > 1 )
				{
					log_failure(
						"gen::def_operator: operator %S may not have more than one parameter - param count: %d",
						operator_to_str( op ),
						params_code->NumEntries
					);
					return OpValResult_Fail;
				}
			}
			break;
		}

		case Op_Add:
		case Op_Subtract:
		case Op_Multiply:
		case Op_Divide:
		case Op_Modulo:
		case Op_BAnd:
		case Op_BOr:
		case Op_BXOr:
		case Op_LShift:
		case Op_RShift:
			check_params();

			switch ( params_code->NumEntries )
			{
				case 1:
					is_member_symbol = true;
					break;

				case 2:
					// This is allowed for arithemtic operators
					// if ( ! code_is_equal((Code)params_code->ValueType, (Code)ret_type ) )
					// {
					// 	log_failure("gen::def_operator: "
					// 		"operator %S is non-member symbol yet first paramter does not equal return type\n"
					// 		"param type: %S\n"
					// 		"return type: %S\n"
					// 		, code_debug_str((Code)params_code)
					// 		, code_debug_str((Code)ret_type)
					// 	);
					// 	return OpValResult_Fail;
					// }
					break;

				default:
					log_failure("gen::def_operator: operator %S recieved unexpected number of paramters recived %d instead of 0-2"
						, operator_to_str(op)
						, params_code->NumEntries
					);
					return OpValResult_Fail;
			}
			break;

		case Op_UnaryNot:
			if ( ! params_code )
				is_member_symbol = true;

			else
			{
				if ( params_code->Type != CT_Parameters )
				{
					log_failure("gen::def_operator: operator %S - params is not of Parameters type - %S", operator_to_str(op), code_debug_str((Code)params_code));
					return OpValResult_Fail;
				}

				if ( params_code->NumEntries != 1 )
				{
					log_failure("gen::def_operator: operator %S recieved unexpected number of paramters recived %d instead of 0-1"
						, operator_to_str(op)
						, params_code->NumEntries
					);
					return OpValResult_Fail;
				}
			}

			if ( ! code_is_equal((Code)ret_type, (Code)t_bool ))
			{
				log_failure("gen::def_operator: operator %S return type must be of type bool - %S"
					, operator_to_str(op)
					, code_debug_str((Code)ret_type)
				);
				return OpValResult_Fail;
			}
			break;

		case Op_LAnd:
		case Op_LOr:
		case Op_LEqual:
		case Op_LNot:
		case Op_Lesser:
		case Op_Greater:
		case Op_LesserEqual:
		case Op_GreaterEqual:
			check_params();

			switch ( params_code->NumEntries )
			{
				case 1:
					is_member_symbol = true;
					break;

				case 2:
					break;

				default:
					log_failure("gen::def_operator: operator %S recieved unexpected number of paramters recived %d instead of 1-2"
						, operator_to_str(op)
						, params_code->NumEntries
					);
					return OpValResult_Fail;
			}
			break;

		case Op_Indirection:
		case Op_AddressOf:
		case Op_MemberOfPointer:
			if ( params_code && params_code->NumEntries > 1)
			{
				log_failure("gen::def_operator: operator %S recieved unexpected number of paramters recived %d instead of 0-1"
					, operator_to_str(op)
					, params_code->NumEntries
				);
				return OpValResult_Fail;
			}
			else
			{
				is_member_symbol = true;
			}
			break;

		case Op_PtrToMemOfPtr:
			if ( params_code )
			{
				log_failure("gen::def_operator: operator %S expects no paramters - %S", operator_to_str(op), code_debug_str((Code)params_code));
				return OpValResult_Fail;
			}
			break;

		case Op_Subscript:
		case Op_FunctionCall:
		case Op_Comma:
			check_params();
			break;

		case Op_New:
		case Op_Delete:
			// This library doesn't support validating new and delete yet.
			break;
#	undef specs
	}

	return is_member_symbol ? OpValResult_Member : OpValResult_Global;
#	undef check_params
#	undef check_ret_type
#	undef check_param_eq_ret
}

FORCEINLINE
bool name__check( char const* context, Str name )
{
	if ( name.Len <= 0 ) {
		log_failure( "gen::%s: Invalid name length provided - %d",  name.Len );
		return false;
	}
	if ( name.Ptr == nullptr ) {
		log_failure( "gen::%s: name is null" );
		return false;
	}
	return true;
}
#define name_check( context, name ) name__check( #context, name )

FORCEINLINE
bool null__check( char const* context, char const* code_id, Code code ) {
	if ( code == nullptr ) {
		log_failure( "gen::%s: %s provided is null", context, code_id );
		return false;
	}
	return true;
}
#define null_check( context, code ) null__check( #context, #code, cast(Code, code) )

/*
The implementation of the upfront constructors involves doing three things:
* Validate the arguments given to construct the intended type of AST is valid.
* Construct said AST type.
* Lock the AST (set to readonly) and return the valid object.

If any of the validation fails, it triggers a call to log_failure with as much info the give the user so that they can hopefully
identify the issue without having to debug too much (at least they can debug though...)

The largest of the functions is related to operator overload definitions.
The library validates a good protion of their form and thus the argument processing for is quite a bit.
*/
CodeAttributes def_attributes( Str content )
{
	if ( content.Len <= 0 || content.Ptr == nullptr ) {
		log_failure( "gen::def_attributes: Invalid attributes provided" );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	Code
	result          = make_code();
	result->Type    = CT_PlatformAttributes;
	result->Name    = cache_str( content );
	result->Content = result->Name;
	return (CodeAttributes) result;
}

CodeComment def_comment( Str content )
{
	if ( content.Len <= 0 || content.Ptr == nullptr )
	{
		log_failure( "gen::def_comment: Invalid comment provided:" );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	StrBuilder  cmt_formatted = strbuilder_make_reserve( _ctx->Allocator_Temp, kilobytes(1) );
	char const* end           = content.Ptr + content.Len;
	char const* scanner       = content.Ptr;
	s32         curr          = 0;
	do
	{
		char const* next   = scanner;
		s32         length = 0;
		while ( next != end && scanner[ length ] != '\n' )
		{
			next = scanner + length;
			length++;
		}
		length++;

		strbuilder_append_fmt(& cmt_formatted, "//%.*s", length, scanner );
		scanner += length;
	}
	while ( scanner <= end );

	if ( * strbuilder_back(cmt_formatted) != '\n' )
		strbuilder_append_str( & cmt_formatted, txt("\n") );

	Str name = strbuilder_to_str(cmt_formatted);

	Code
	result          = make_code();
	result->Type    = CT_Comment;
	result->Name    = cache_str( name );
	result->Content = result->Name;

	strbuilder_free(& cmt_formatted);

	return (CodeComment) result;
}

CodeConstructor def_constructor( Opts_def_constructor p )
{
	if ( p.params && p.params->Type != CT_Parameters ) {
		log_failure("gen::def_constructor: params must be of Parameters type - %s", code_debug_str((Code)p.params));
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	CodeConstructor result = (CodeConstructor) make_code();
	if ( p.params ) {
		result->Params = p.params;
	}
	if ( p.initializer_list ) {
		result->InitializerList = p.initializer_list;
	}
	if ( p.body )
	{
		switch ( p.body->Type ) {
			case CT_Function_Body:
			case CT_Untyped:
			break;

			default:
				log_failure("gen::def_constructor: body must be either of Function_Body or Untyped type - %s", code_debug_str(p.body));
				return InvalidCode;
		}

		result->Type = CT_Constructor;
		result->Body = p.body;
	}
	else
	{
		result->Type = CT_Constructor_Fwd;
	}
	return result;
}

CodeClass def_class( Str name, Opts_def_struct p )
{
	if ( ! name_check( def_class, name ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.attributes && p.attributes->Type != CT_PlatformAttributes ) {
		log_failure( "gen::def_class: attributes was not a 'PlatformAttributes' type: %s", code_debug_str(p.attributes) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.parent && ( p.parent->Type != CT_Class && p.parent->Type != CT_Struct && p.parent->Type != CT_Typename && p.parent->Type != CT_Untyped ) ) {
		log_failure( "gen::def_class: parent provided is not type 'Class', 'Struct', 'Typeanme', or 'Untyped': %s", code_debug_str(p.parent) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	CodeClass
	result               = (CodeClass) make_code();
	result->Name         = cache_str( name );
	result->ModuleFlags  = p.mflags;
	result->Attributes   = p.attributes;
	result->Specs        = p.specifers;
	result->ParentAccess = p.parent_access;
	result->ParentType   = p.parent;
	if ( p.body )
	{
		switch ( p.body->Type )
		{
			case CT_Class_Body:
			case CT_Untyped:
			break;

			default:
				log_failure("gen::def_class: body must be either of Class_Body or Untyped type - %s", code_debug_str(p.body));
				return InvalidCode;
		}

		result->Type         = CT_Class;
		result->Body         = p.body;
		result->Body->Parent = cast(Code, result);
	}
	else {
		result->Type = CT_Class_Fwd;
	}
	for (s32 idx = 0; idx < p.num_interfaces; idx++ ) {
		class_add_interface(result, p.interfaces[idx] );
	}
	return result;
}

CodeDefine def_define( Str name, MacroType type, Opts_def_define p )
{
	if ( ! name_check( def_define, name ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodeDefine
	result          = (CodeDefine) make_code();
	result->Type    = CT_Preprocess_Define;
	result->Name    = cache_str( name );
	result->Params  = p.params;
	if ( p.content.Len <= 0 || p.content.Ptr == nullptr )
		result->Body = untyped_str( txt("\n") );
	else
		result->Body = untyped_str( strbuilder_to_str(strbuilder_fmt_buf(_ctx->Allocator_Temp, "%S\n", p.content)) );

	b32  register_define = ! p.dont_register_to_preprocess_macros;
	if ( register_define ) {
		Macro macro_entry = { result->Name, type, p.flags };
		register_macro(macro_entry);
	}
	return result;
}

CodeDestructor def_destructor( Opts_def_destructor p )
{
	if ( p.specifiers && p.specifiers->Type != CT_Specifiers ) {
		log_failure( "gen::def_destructor: specifiers was not a 'Specifiers' type: %s", code_debug_str(p.specifiers) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	CodeDestructor
	result        = (CodeDestructor) make_code();
	result->Specs = p.specifiers;
	if ( p.body )
	{
		switch ( p.body->Type )
		{
			case CT_Function_Body:
			case CT_Untyped:
			break;

			default:
				log_failure("gen::def_destructor: body must be either of Function_Body or Untyped type - %s", code_debug_str(p.body));
				return InvalidCode;
		}

		result->Type = CT_Destructor;
		result->Body = p.body;
	}
	else
	{
		result->Type = CT_Destructor_Fwd;
	}
	return result;
}

CodeEnum def_enum( Str name, Opts_def_enum p )
{
	if ( ! name_check( def_enum, name ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.type && p.type->Type != CT_Typename ) {
		log_failure( "gen::def_enum: enum underlying type provided was not of type Typename: %s", code_debug_str(p.type) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.attributes && p.attributes->Type != CT_PlatformAttributes ) {
		log_failure( "gen::def_enum: attributes was not a 'PlatformAttributes' type: %s", code_debug_str(p.attributes) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	CodeEnum
	result              = (CodeEnum) make_code();
	result->Name        = cache_str( name );
	result->ModuleFlags = p.mflags;
	if ( p.body )
	{
		switch ( p.body->Type )
		{
			case CT_Enum_Body:
			case CT_Untyped:
			break;

			default:
				log_failure( "gen::def_enum: body must be of Enum_Body or Untyped type %s", code_debug_str(p.body));
				return InvalidCode;
		}

		result->Type = p.specifier == EnumDecl_Class ?
			CT_Enum_Class : CT_Enum;

		result->Body = p.body;
	}
	else
	{
		result->Type = p.specifier == EnumDecl_Class ?
			CT_Enum_Class_Fwd : CT_Enum_Fwd;
	}
	result->Attributes = p.attributes;

	if ( p.type ) {
		result->UnderlyingType = p.type;
	}
	else if ( p.type_macro ) {
		result->UnderlyingTypeMacro = p.type_macro;
	}
	else if ( result->Type != CT_Enum_Class_Fwd && result->Type != CT_Enum_Fwd )
	{
		log_failure( "gen::def_enum: enum forward declaration must have an underlying type" );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	return result;
}

CodeExec def_execution( Str content )
{
	if ( content.Len <= 0 || content.Ptr == nullptr ) {
		log_failure( "gen::def_execution: Invalid execution provided" );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodeExec
	result          = (CodeExec) make_code();
	result->Type    = CT_Execution;
	result->Content = cache_str( content );
	return result;
}

CodeExtern def_extern_link( Str name, CodeBody body )
{
	if ( ! name_check(def_extern_link, name) || ! null_check(def_extern_link, body) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( body->Type != CT_Extern_Linkage_Body && body->Type != CT_Untyped ) {
		log_failure("gen::def_extern_linkage: body is not of extern_linkage or untyped type %s", code_debug_str(body));
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodeExtern
	result        = (CodeExtern)make_code();
	result->Type  = CT_Extern_Linkage;
	result->Name  = cache_str( name );
	result->Body  = body;
	return result;
}

CodeFriend def_friend( Code declaration )
{
	if ( ! null_check( def_friend, declaration ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	switch ( declaration->Type )
	{
		case CT_Class_Fwd:
		case CT_Function_Fwd:
		case CT_Operator_Fwd:
		case CT_Struct_Fwd:
		case CT_Class:
		case CT_Function:
		case CT_Operator:
		case CT_Struct:
		break;

		default:
			log_failure("gen::def_friend: requires declartion to have class, function, operator, or struct - %s", code_debug_str(declaration));
			return InvalidCode;
	}
	CodeFriend
	result              = (CodeFriend) make_code();
	result->Type        = CT_Friend;
	result->Declaration = declaration;
	return result;
}

CodeFn def_function( Str name, Opts_def_function p )
{
	if ( ! name_check( def_function, name )) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.params && p.params->Type != CT_Parameters ) {
		log_failure( "gen::def_function: params was not a `Parameters` type: %s", code_debug_str(p.params) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.ret_type && p.ret_type->Type != CT_Typename ) {
		log_failure( "gen::def_function: ret_type was not a Typename: %s", code_debug_str(p.ret_type) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.specs && p.specs-> Type != CT_Specifiers ) {
		log_failure( "gen::def_function: specifiers was not a `Specifiers` type: %s", code_debug_str(p.specs) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.attrs && p.attrs->Type != CT_PlatformAttributes ) {
		log_failure( "gen::def_function: attributes was not a `PlatformAttributes` type: %s", code_debug_str(p.attrs) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	CodeFn
	result              = (CodeFn) make_code();
	result->Name        = cache_str( name );
	result->ModuleFlags = p.mflags;
	if ( p.body )
	{
		switch ( p.body->Type )
		{
			case CT_Function_Body:
			case CT_Execution:
			case CT_Untyped:
				break;

			default:
			{
				log_failure("gen::def_function: body must be either of Function_Body, Execution, or Untyped type. %s", code_debug_str(p.body));
				return InvalidCode;
			}
		}
		result->Type = CT_Function;
		result->Body = p.body;
	}
	else
	{
		result->Type = CT_Function_Fwd;
	}
	result->Attributes = p.attrs;
	result->Specs      = p.specs;
	result->Params     = p.params;
	result->ReturnType = p.ret_type ? p.ret_type : t_void;
	return result;
}

CodeInclude def_include( Str path, Opts_def_include p )
{
	if ( path.Len <= 0 || path.Ptr == nullptr ) {
		log_failure( "gen::def_include: Invalid path provided - %d" );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	StrBuilder content = p.foreign ?
			strbuilder_fmt_buf( _ctx->Allocator_Temp, "<%.*s>",   path.Len, path.Ptr )
		:	strbuilder_fmt_buf( _ctx->Allocator_Temp, "\"%.*s\"", path.Len, path.Ptr );

	CodeInclude
	result          = (CodeInclude) make_code();
	result->Type    = CT_Preprocess_Include;
	result->Name    = cache_str( strbuilder_to_str(content) );
	result->Content = result->Name;
	return result;
}

CodeModule def_module( Str name, Opts_def_module p )
{
	if ( ! name_check( def_module, name )) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodeModule
	result              = (CodeModule) make_code();
	result->Type        = CT_Module;
	result->Name        = cache_str( name );
	result->ModuleFlags = p.mflags;
	return result;
}

CodeNS def_namespace( Str name, CodeBody body, Opts_def_namespace p )
{
	if ( ! name_check( def_namespace, name )) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( ! null_check( def_namespace, body)) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( body && body->Type != CT_Namespace_Body && body->Type != CT_Untyped ) {
		log_failure("gen::def_namespace: body is not of namespace or untyped type %s", code_debug_str(body));
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodeNS
	result              = (CodeNS) make_code();
	result->Type        = CT_Namespace;
	result->Name        = cache_str( name );
	result->ModuleFlags = p.mflags;
	result->Body        = body;
	return result;
}

CodeOperator def_operator( Operator op, Str nspace, Opts_def_operator p )
{
	if ( p.attributes && p.attributes->Type != CT_PlatformAttributes ) {
		log_failure( "gen::def_operator: PlatformAttributes was provided but its not of attributes type: %s", code_debug_str(p.attributes) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.specifiers && p.specifiers->Type != CT_Specifiers ) {
		log_failure( "gen::def_operator: Specifiers was provided but its not of specifiers type: %s", code_debug_str(p.specifiers) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	OpValidateResult check_result = operator__validate( op, p.params, p.ret_type, p.specifiers );
	if ( check_result == OpValResult_Fail ) {
		return InvalidCode;
	}

	char const* name = nullptr;

	Str op_str = operator_to_str( op );
	if ( nspace.Len > 0 )
		name = c_str_fmt_buf( "%.*soperator %.*s", nspace.Len, nspace.Ptr, op_str.Len, op_str.Ptr );
	else
		name = c_str_fmt_buf( "operator %.*s", op_str.Len, op_str.Ptr );

	Str name_resolved = { name, c_str_len(name) };

	CodeOperator
	result              = (CodeOperator) make_code();
	result->Name        = cache_str( name_resolved );
	result->ModuleFlags = p.mflags;
	result->Op          = op;
	if ( p.body )
	{
		switch ( p.body->Type )
		{
			case CT_Function_Body:
			case CT_Execution:
			case CT_Untyped:
				break;

			default:
			{
				log_failure("gen::def_operator: body must be either of Function_Body, Execution, or Untyped type. %s", code_debug_str(p.body));
				GEN_DEBUG_TRAP();
				return InvalidCode;
			}
		}

		result->Type = check_result == OpValResult_Global ?
			CT_Operator : CT_Operator_Member;

		result->Body = p.body;
	}
	else
	{
		result->Type = check_result == OpValResult_Global ?
			CT_Operator_Fwd : CT_Operator_Member_Fwd;
	}
	result->Attributes = p.attributes;
	result->Specs      = p.specifiers;
	result->ReturnType = p.ret_type;
	result->Params     = p.params;
	return result;
}

CodeOpCast def_operator_cast( CodeTypename type, Opts_def_operator_cast p )
{
	if ( ! null_check( def_operator_cast, type )) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( type->Type != CT_Typename ) {
		log_failure( "gen::def_operator_cast: type is not a typename - %s", code_debug_str(type) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	CodeOpCast result = (CodeOpCast) make_code();
	if (p.body)
	{
		result->Type = CT_Operator_Cast;

		if ( p.body->Type != CT_Function_Body && p.body->Type != CT_Execution ) {
			log_failure( "gen::def_operator_cast: body is not of function body or execution type - %s", code_debug_str(p.body) );
			GEN_DEBUG_TRAP();
			return InvalidCode;
		}
		result->Body = p.body;
	}
	else
	{
		result->Type = CT_Operator_Cast_Fwd;
	}
	result->Specs     = p.specs;
	result->ValueType = type;
	return result;
}

CodeParams def_param( CodeTypename type, Str name, Opts_def_param p )
{
	if ( ! name_check( def_param, name ) || ! null_check( def_param, type ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( type->Type != CT_Typename ) {
		log_failure( "gen::def_param: type is not a typename - %s", code_debug_str(type) );
		return InvalidCode;
	}
	if ( p.value && p.value->Type != CT_Untyped ) {
		log_failure( "gen::def_param: value is not untyped - %s", code_debug_str(p.value) );
		return InvalidCode;
	}
	CodeParams
	result            = (CodeParams) make_code();
	result->Type      = CT_Parameters;
	result->Name      = cache_str( name );
	result->ValueType = type;
	result->Value     = p.value;
	result->NumEntries++;
	return result;
}

CodePragma def_pragma( Str directive )
{
	if ( directive.Len <= 0 || directive.Ptr == nullptr ) {
		log_failure( "gen::def_comment: Invalid comment provided:" );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodePragma
	result          = (CodePragma) make_code();
	result->Type    = CT_Preprocess_Pragma;
	result->Content = cache_str( directive );
	return result;
}

CodePreprocessCond def_preprocess_cond( EPreprocessCond type, Str expr )
{
	if ( expr.Len <= 0 || expr.Ptr == nullptr ) {
		log_failure( "gen::def_comment: Invalid comment provided:" );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodePreprocessCond
	result          = (CodePreprocessCond) make_code();
	result->Content = cache_str( expr );
	switch (type)
	{
		case PreprocessCond_If:
			result->Type = CT_Preprocess_If;
		break;
		case PreprocessCond_IfDef:
			result->Type = CT_Preprocess_IfDef;
		break;
		case PreprocessCond_IfNotDef:
			result->Type = CT_Preprocess_IfNotDef;
		break;
		case PreprocessCond_ElIf:
			result->Type = CT_Preprocess_ElIf;
		break;
	}
	return result;
}

CodeSpecifiers def_specifier( Specifier spec )
{
	CodeSpecifiers
	result       = (CodeSpecifiers) make_code();
	result->Type = CT_Specifiers;
	specifiers_append(result, spec );
	return result;
}

CodeStruct def_struct( Str name, Opts_def_struct p )
{
	if ( p.attributes && p.attributes->Type != CT_PlatformAttributes ) {
		log_failure( "gen::def_struct: attributes was not a `PlatformAttributes` type - %s", code_debug_str(cast(Code, p.attributes)) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.parent && p.parent->Type != CT_Typename ) {
		log_failure( "gen::def_struct: parent was not a `Struct` type - %s", code_debug_str(p.parent) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.body && p.body->Type != CT_Struct_Body ) {
		log_failure( "gen::def_struct: body was not a Struct_Body type - %s", code_debug_str(p.body) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	CodeStruct
	result              = (CodeStruct) make_code();
	result->ModuleFlags = p.mflags;
	if ( name.Len )
		result->Name = cache_str( name );

	if ( p.body ) {
		result->Type = CT_Struct;
		result->Body = p.body;
	}
	else {
		result->Type = CT_Struct_Fwd;
	}
	result->Attributes   = p.attributes;
	result->ParentAccess = p.parent_access;
	result->ParentType   = p.parent;

	for (s32 idx = 0; idx < p.num_interfaces; idx++ ) {
		struct_add_interface(result, p.interfaces[idx] );
	}

	result->Specs = p.specifers;
	return result;
}

CodeTemplate def_template( CodeParams params, Code declaration, Opts_def_template p )
{
	if ( ! null_check( def_template, declaration ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( params && params->Type != CT_Parameters ){
		log_failure( "gen::def_template: params is not of parameters type - %s", code_debug_str(params) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	switch (declaration->Type )
	{
		case CT_Class:
		case CT_Function:
		case CT_Struct:
		case CT_Variable:
		case CT_Using:
		break;

		default:
			log_failure( "gen::def_template: declaration is not of class, function, struct, variable, or using type - %s", code_debug_str(declaration) );
	}
	CodeTemplate
	result              = (CodeTemplate) make_code();
	result->Type        = CT_Template;
	result->ModuleFlags = p.mflags;
	result->Params      = params;
	result->Declaration = declaration;
	return result;
}

CodeTypename def_type( Str name, Opts_def_type p )
{
	if ( ! name_check( def_type, name )) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	Code           arrayexpr  = p.arrayexpr;
	CodeSpecifiers specifiers = p.specifiers;
	CodeAttributes attributes = p.attributes;
	if ( p.attributes && p.attributes->Type != CT_PlatformAttributes ) {
		log_failure( "gen::def_type: attributes is not of attributes type - %s", code_debug_str((Code)p.attributes) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.specifiers && p.specifiers->Type != CT_Specifiers ) {
		log_failure( "gen::def_type: specifiers is not of specifiers type - %s", code_debug_str((Code)p.specifiers) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.arrayexpr && p.arrayexpr->Type != CT_Untyped ) {
		log_failure( "gen::def_type: arrayexpr is not of untyped type - %s", code_debug_str((Code)p.arrayexpr) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodeTypename
	result             = (CodeTypename) make_code();
	result->Name       = cache_str( name );
	result->Type       = CT_Typename;
	result->Attributes = p.attributes;
	result->Specs      = p.specifiers;
	result->ArrExpr    = p.arrayexpr;
	result->TypeTag    = p.type_tag;
	return result;
}

CodeTypedef def_typedef( Str name, Code type, Opts_def_typedef p )
{
	if ( ! null_check( def_typedef, type ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	switch ( type->Type )
	{
		case CT_Class:
		case CT_Class_Fwd:
		case CT_Enum:
		case CT_Enum_Fwd:
		case CT_Enum_Class:
		case CT_Enum_Class_Fwd:
		case CT_Function_Fwd:
		case CT_Struct:
		case CT_Struct_Fwd:
		case CT_Union:
		case CT_Typename:
			break;
		default:
			log_failure( "gen::def_typedef: type was not a Class, Enum, Function Forward, Struct, Typename, or Union - %s", code_debug_str((Code)type) );
			GEN_DEBUG_TRAP();
			return InvalidCode;
	}
	if ( p.attributes && p.attributes->Type != CT_PlatformAttributes ) {
		log_failure( "gen::def_typedef: attributes was not a PlatformAttributes - %s", code_debug_str((Code)p.attributes) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	// Registering the type.
	CodeTypename registered_type = def_type( name );
	if ( ! registered_type ) {
		log_failure( "gen::def_typedef: failed to register type" );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	CodeTypedef
	result                 = (CodeTypedef) make_code();
	result->Type           = CT_Typedef;
	result->ModuleFlags    = p.mflags;
	result->UnderlyingType = type;

	if ( name.Len <= 0  )
	{
		if (type->Type != CT_Untyped) {
			log_failure( "gen::def_typedef: name was empty and type was not untyped (indicating its a function typedef) - %s", code_debug_str(type) );
			GEN_DEBUG_TRAP();
			return InvalidCode;
		}
		result->Name       = cache_str( type->Name );
		result->IsFunction = true;
	}
	else
	{
		result->Name       = cache_str( name );
		result->IsFunction = false;
	}
	return result;
}

CodeUnion def_union( Str name, CodeBody body, Opts_def_union p )
{
	if ( ! null_check( def_union, body ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( body->Type != CT_Union_Body ) {
		log_failure( "gen::def_union: body was not a Union_Body type - %s", code_debug_str(body) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.attributes && p.attributes->Type != CT_PlatformAttributes ) {
		log_failure( "gen::def_union: attributes was not a PlatformAttributes type - %s", code_debug_str(p.attributes) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodeUnion
	result              = (CodeUnion) make_code();
	result->ModuleFlags = p.mflags;
	result->Type        = CT_Union;
	result->Body        = body;
	result->Attributes  = p.attributes;
	if ( name.Ptr )
		result->Name = cache_str( name );
	return result;
}

CodeUsing def_using( Str name, CodeTypename type, Opts_def_using p )
{
	if ( ! name_check( def_using, name ) || null_check( def_using, type ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}

	CodeTypename register_type = def_type( name );
	if ( ! register_type ) {
		log_failure( "gen::def_using: failed to register type" );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.attributes && p.attributes->Type != CT_PlatformAttributes ) {
		log_failure( "gen::def_using: attributes was not a PlatformAttributes type - %s", code_debug_str(p.attributes) );
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodeUsing
	result                 = (CodeUsing) make_code();
	result->Name           = cache_str( name );
	result->ModuleFlags    = p.mflags;
	result->Type           = CT_Using;
	result->UnderlyingType = type;
	result->Attributes     = p.attributes;
	return result;
}

CodeUsing def_using_namespace( Str name )
{
	if ( ! name_check( def_using_namespace, name ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	CodeUsing
	result          = (CodeUsing) make_code();
	result->Name    = cache_str( name );
	result->Type    = CT_Using_Namespace;
	return result;
}

CodeVar def_variable( CodeTypename type, Str name, Opts_def_variable p )
{
	if ( ! name_check( def_variable, name ) || ! null_check( def_variable, type ) ) {
		GEN_DEBUG_TRAP();
		return InvalidCode;
	}
	if ( p.attributes && p.attributes->Type != CT_PlatformAttributes )
	{
		log_failure( "gen::def_variable: attributes was not a `PlatformAttributes` type - %s", code_debug_str(p.attributes) );
		return InvalidCode;
	}
	if ( p.specifiers && p.specifiers->Type != CT_Specifiers )
	{
		log_failure( "gen::def_variable: specifiers was not a `Specifiers` type - %s", code_debug_str(p.specifiers) );
		return InvalidCode;
	}
	if ( type->Type != CT_Typename )
	{
		log_failure( "gen::def_variable: type was not a Typename - %s", code_debug_str(type) );
		return InvalidCode;
	}
	if ( p.value && p.value->Type != CT_Untyped )
	{
		log_failure( "gen::def_variable: value was not a `Untyped` type - %s", code_debug_str(p.value) );
		return InvalidCode;
	}
	CodeVar
	result              = (CodeVar) make_code();
	result->Name        = cache_str( name );
	result->Type        = CT_Variable;
	result->ModuleFlags = p.mflags;
	result->ValueType   = type;
	result->Attributes  = p.attributes;
	result->Specs       = p.specifiers;
	result->Value       = p.value;
	return result;
}

#pragma region Helper Macros for def_**_body functions
#define def_body_start( Name_ )                                               \
if ( num <= 0 )                                                               \
{                                                                             \
	log_failure("gen::" stringize(Name_) ": num cannot be zero or negative"); \
	return InvalidCode;                                                       \
}

#define def_body_code_array_start( Name_ )                                     \
if ( num <= 0 )                                                                \
{                                                                              \
	log_failure("gen::" stringize(Name_) ": num cannot be zero or negative");  \
	return InvalidCode;                                                        \
}                                                                              \
																			   \
if ( codes == nullptr )                                                        \
{                                                                              \
	log_failure("gen::" stringize(Name_)" : Provided a null array of codes");  \
	return InvalidCode;                                                        \
}

#pragma endregion Helper Macros for def_**_body functions

CodeBody def_class_body( s32 num, ... )
{
	def_body_start( def_class_body );

	CodeBody result = ( CodeBody )make_code();
	result->Type    = CT_Class_Body;

	va_list va;
	va_start( va, num );
	do
	{
		Code_POD pod   = va_arg(va, Code_POD);
		Code     entry = pcast(Code, pod);
		if ( ! entry) {
			log_failure("gen::"
						"def_class_body"
						": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_CLASS_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_class_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);
	va_end(va);

	return result;
}

CodeBody def_class_body_arr( s32 num, Code* codes )
{
	def_body_code_array_start( def_class_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Function_Body;
	do
	{
		Code entry = *codes;
		codes++;
		if ( ! entry) {
			log_failure("gen::" "def_class_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_CLASS_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_class_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);

	return result;
}

CodeDefineParams def_define_params( s32 num, ... )
{
	def_body_start( def_define_params );

	va_list va;
	va_start(va, num);

	Code_POD         pod   = va_arg(va, Code_POD);
	CodeDefineParams param = pcast( CodeDefineParams, pod );

	null_check( def_define_params, param );
	if ( param->Type != CT_Parameters_Define ) {
		log_failure( "gen::def_define_params: param %d is not a parameter for a preprocessor define", num - num + 1 );
		return InvalidCode;
	}

	CodeDefineParams result = (CodeDefineParams) code_duplicate(param);
	while ( -- num )
	{
		pod   = va_arg(va, Code_POD);
		param = pcast( CodeDefineParams, pod );
		if ( param->Type != CT_Parameters_Define ) {
			log_failure( "gen::def_define_params: param %d is not a parameter for a preprocessor define", num - num + 1 );
			return InvalidCode;
		}
		define_params_append(result, param );
	}
	va_end(va);

	return result;
}

CodeDefineParams def_define_params_arr( s32 num, CodeDefineParams* codes )
{
	def_body_code_array_start( def_define_params );

#	define check_current(current)                                                                                                                 \
	if ( current == nullptr ) {                                                                                                                   \
		log_failure("gen::def_define_params: Provide a null code in codes array");                                                                \
		return InvalidCode;                                                                                                                       \
	}                                                                                                                                             \
	if (current->Type != CT_Parameters_Define ) {                                                                                                 \
		log_failure("gen::def_define_params: Code in coes array is not of paramter for preprocessor define type - %s", code_debug_str(current) ); \
		return InvalidCode;                                                                                                                       \
	}
	CodeDefineParams current = (CodeDefineParams)code_duplicate(* codes);
	check_current(current);

	CodeDefineParams
	result            = (CodeDefineParams) make_code();
	result->Name      = current->Name;
	result->Type      = current->Type;
	while( codes++, current = * codes, num--, num > 0 ) {
		check_current(current);
		define_params_append(result, current );
	}
#	undef check_current

	return result;
}

CodeBody def_enum_body( s32 num, ... )
{
	def_body_start( def_enum_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Enum_Body;

	va_list va;
	va_start(va, num);
	do
	{
		Code_POD pod   = va_arg(va, Code_POD);
		Code     entry = pcast(Code, pod);
		if ( ! entry ) {
			log_failure("gen::def_enum_body: Provided a null entry");
			return InvalidCode;
		}
		if ( entry->Type != CT_Untyped && entry->Type != CT_Comment ) {
			log_failure("gen::def_enum_body: Entry type is not allowed - %s. Must be of untyped or comment type.", code_debug_str(entry) );
			return InvalidCode;
		}
		body_append(result, entry );
	}
	while ( num--, num > 0 );
	va_end(va);

	return (CodeBody) result;
}

CodeBody def_enum_body_arr( s32 num, Code* codes )
{
	def_body_code_array_start( def_enum_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Enum_Body;
	do
	{
		Code entry = *codes;
		if ( ! entry ) {
			log_failure("gen::def_enum_body: Provided a null entry");
			return InvalidCode;
		}
		if ( entry->Type != CT_Untyped && entry->Type != CT_Comment ) {
			log_failure("gen::def_enum_body: Entry type is not allowed: %s", code_debug_str(entry) );
			return InvalidCode;
		}
		body_append(result, entry );
	}
	while ( codes++, num--, num > 0 );

	return result;
}

CodeBody def_export_body( s32 num, ... )
{
	def_body_start( def_export_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Export_Body;

	va_list va;
	va_start(va, num);
	do
	{
		Code_POD pod = va_arg(va, Code_POD);
		Code     entry = pcast(Code, pod);
		if ( ! entry)
		{
			log_failure("gen::" "def_export_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_EXPORT_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_export_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);
	va_end(va);

	return result;
}

CodeBody def_export_body_arr( s32 num, Code* codes )
{
	def_body_code_array_start( def_export_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Export_Body;
	do
	{
		Code entry = *codes;
		codes++;
		if ( ! entry) {
			log_failure("gen::" "def_export_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_EXPORT_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_export_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);

	return result;
}

CodeBody def_extern_link_body( s32 num, ... )
{
	def_body_start( def_extern_linkage_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Extern_Linkage_Body;

	va_list va;
	va_start(va, num);
	do
	{
		Code_POD pod   = va_arg(va, Code_POD);
		Code     entry = pcast(Code, pod);
		if ( ! entry) {
			log_failure("gen::" "def_extern_linkage_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_extern_linkage_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);
	va_end(va);

	return result;
}

CodeBody def_extern_link_body_arr( s32 num, Code* codes )
{
	def_body_code_array_start( def_extern_linkage_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Extern_Linkage_Body;
	do
	{
		Code entry = *codes;
		codes++;
		if (!entry)
		{
			log_failure("gen::" "def_extern_linkage_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_EXTERN_LINKAGE_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_extern_linkage_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);

	return result;
}

CodeBody def_function_body( s32 num, ... )
{
	def_body_start( def_function_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Function_Body;

	va_list va;
	va_start(va, num);
	do
	{
		Code_POD pod   = va_arg(va, Code_POD);
		Code     entry = pcast(Code, pod);
		if ( ! entry) {
			log_failure("gen::" stringize(def_function_body) ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES_CASES:
				log_failure("gen::" stringize(def_function_body) ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);
	va_end(va);

	return result;
}

CodeBody def_function_body_arr( s32 num, Code* codes )
{
	def_body_code_array_start( def_function_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Function_Body;
	do
	{
		Code entry = *codes;
		codes++;
		if (!entry) {
			log_failure("gen::" "def_function_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_FUNCTION_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_function_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);

	return result;
}

CodeBody def_global_body( s32 num, ... )
{
	def_body_start( def_global_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Global_Body;

	va_list va;
	va_start(va, num);
	do
	{
		Code_POD pod   = va_arg(va, Code_POD);
		Code     entry = pcast(Code, pod);
		if ( ! entry) {
			log_failure("gen::" "def_global_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			case CT_Global_Body:
				// result.body_append( entry.code_cast<CodeBody>() ) ;
				body_append_body( result, cast(CodeBody, entry) );
				continue;

			GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_global_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);
	va_end(va);

	return result;
}

CodeBody def_global_body_arr( s32 num, Code* codes )
{
	def_body_code_array_start( def_global_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Global_Body;
	do
	{
		Code entry = *codes;
		codes++;
		if ( ! entry) {
			log_failure("gen::" "def_global_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			case CT_Global_Body:
				body_append_body(result, cast(CodeBody, entry) );
				continue;

			GEN_AST_BODY_GLOBAL_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_global_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}

		body_append(result, entry);
	}
	while (num--, num > 0);

	return result;
}

CodeBody def_namespace_body( s32 num, ... )
{
	def_body_start( def_namespace_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Namespace_Body;

	va_list va;
	va_start(va, num);
	do
	{
		Code_POD pod   = va_arg(va, Code_POD);
		Code     entry = pcast(Code, pod);
		if ( ! entry) {
			log_failure("gen::" "def_namespace_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_namespace_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);
	va_end(va);

	return result;
}

CodeBody def_namespace_body_arr( s32 num, Code* codes )
{
	def_body_code_array_start( def_namespace_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Global_Body;
	do
	{
		Code entry = *codes;
		codes++;
		if ( ! entry) {
			log_failure("gen::" "def_namespace_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_NAMESPACE_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_namespace_body" ": Entry type is not allowed: %s", code_debug_str(entry) );
				return InvalidCode;

			default: break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);

	return result;
}

CodeParams def_params( s32 num, ... )
{
	def_body_start( def_params );

	va_list va;
	va_start(va, num);

	Code_POD  pod   = va_arg(va, Code_POD);
	CodeParams param = pcast( CodeParams, pod );

	null_check( def_params, param );
	if ( param->Type != CT_Parameters ) {
		log_failure( "gen::def_params: param %d is not a Parameters", num - num + 1 );
		return InvalidCode;
	}

	CodeParams result = (CodeParams) code_duplicate(param);
	while ( -- num )
	{
		pod   = va_arg(va, Code_POD);
		param = pcast( CodeParams, pod );
		if ( param->Type != CT_Parameters ) {
			log_failure( "gen::def_params: param %d is not a Parameters", num - num + 1 );
			return InvalidCode;
		}
		params_append(result, param );
	}
	va_end(va);

	return result;
}

CodeParams def_params_arr( s32 num, CodeParams* codes )
{
	def_body_code_array_start( def_params );

#	define check_current(current)                                                                                      \
	if ( current == nullptr ) {                                                                                        \
		log_failure("gen::def_params: Provide a null code in codes array");                                            \
		return InvalidCode;                                                                                            \
	}                                                                                                                  \
	if (current->Type != CT_Parameters ) {                                                                             \
		log_failure("gen::def_params: Code in coes array is not of paramter type - %s", code_debug_str(current) );     \
		return InvalidCode;                                                                                            \
	}
	CodeParams current = (CodeParams)code_duplicate(* codes);
	check_current(current);

	CodeParams
	result            = (CodeParams) make_code();
	result->Name      = current->Name;
	result->Type      = current->Type;
	result->ValueType = current->ValueType;
	while( codes++, current = * codes, num--, num > 0 ) {
		check_current(current);
		params_append(result, current );
	}
#	undef check_current

	return result;
}

CodeSpecifiers def_specifiers( s32 num, ... )
{
	if ( num <= 0 ) {
		log_failure("gen::def_specifiers: num cannot be zero or less");
		return InvalidCode;
	}
	if ( num > AST_ArrSpecs_Cap ) {
		log_failure("gen::def_specifiers: num of speciifers to define AST larger than AST specicifier capacity - %d", num);
		return InvalidCode;
	}
	CodeSpecifiers
	result       = (CodeSpecifiers) make_code();
	result->Type = CT_Specifiers;

	va_list va;
	va_start(va, num);
	do {
		Specifier type = (Specifier)va_arg(va, int);
		specifiers_append(result, type );
	}
	while ( --num, num );
	va_end(va);

	return result;
}

CodeSpecifiers def_specifiers_arr( s32 num, Specifier* specs )
{
	if ( num <= 0 ) {
		log_failure("gen::def_specifiers: num cannot be zero or less");
		return InvalidCode;
	}
	if ( num > AST_ArrSpecs_Cap ) {
		log_failure("gen::def_specifiers: num of speciifers to define AST larger than AST specicifier capacity - %d", num);
		return InvalidCode;
	}
	CodeSpecifiers
	result       = (CodeSpecifiers) make_code();
	result->Type = CT_Specifiers;

	s32 idx = 0;
	do {
		specifiers_append(result, specs[idx] );
		idx++;
	}
	while ( --num, num );

	return result;
}

CodeBody def_struct_body( s32 num, ... )
{
	def_body_start( def_struct_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Struct_Body;

	va_list va;
	va_start(va, num);
	do
	{
		Code_POD pod   = va_arg(va, Code_POD);
		Code     entry = pcast(Code, pod);
		if ( ! entry) {
			log_failure("gen::" "def_struct_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_STRUCT_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_struct_body" ": Entry type is not allowed: %s", code_debug_str(entry));
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);
	va_end(va);

	return result;
}

CodeBody def_struct_body_arr( s32 num, Code* codes )
{
	def_body_code_array_start( def_struct_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Struct_Body;
	do
	{
		Code entry = *codes;
		codes++;
		if ( ! entry) {
			log_failure("gen::" "def_struct_body" ": Provided an null entry");
			return InvalidCode;
		}
		switch (entry->Type)
		{
			GEN_AST_BODY_STRUCT_UNALLOWED_TYPES_CASES:
				log_failure("gen::" "def_struct_body" ": Entry type is not allowed: %s", code_debug_str(entry) );
				return InvalidCode;

			default:
			break;
		}
		body_append(result, entry);
	}
	while (num--, num > 0);

	return result;
}

CodeBody def_union_body( s32 num, ... )
{
	def_body_start( def_union_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Union_Body;

	va_list va;
	va_start(va, num);
	do
	{
		Code_POD pod   = va_arg(va, Code_POD);
		Code     entry = pcast( Code, pod );
		if ( ! entry ) {
			log_failure("gen::def_union_body: Provided a null entry");
			return InvalidCode;
		}
		if ( entry->Type != CT_Untyped && entry->Type != CT_Comment ) {
			log_failure("gen::def_union_body: Entry type is not allowed - %s. Must be of untyped or comment type.", code_debug_str(entry) );
			return InvalidCode;
		}
		body_append(result, entry );
	}
	while ( num--, num > 0 );
	va_end(va);

	return result;
}

CodeBody def_union_body_arr( s32 num, Code* codes )
{
	def_body_code_array_start( def_union_body );

	CodeBody
	result       = (CodeBody) make_code();
	result->Type = CT_Union_Body;
	do
	{
		Code entry = *codes;
		if ( ! entry ) {
			log_failure("gen::def_union_body: Provided a null entry");
			return InvalidCode;
		}
		if ( entry->Type != CT_Untyped && entry->Type != CT_Comment ) {
			log_failure("gen::def_union_body: Entry type is not allowed: %s", code_debug_str(entry) );
			return InvalidCode;
		}
		body_append(result, entry );
	}
	while ( codes++, num--, num > 0 );

	return (CodeBody) result;
}

#	undef name_check
#	undef null_check
#	undef def_body_start
#	undef def_body_code_array_start

#pragma endregion Upfront

#pragma region Parsing


StrBuilder tok_to_strbuilder(Token tok)
{
	StrBuilder result   = strbuilder_make_reserve( _ctx->Allocator_Temp, kilobytes(4) );
	Str        type_str = toktype_to_str( tok.Type );

	strbuilder_append_fmt( & result, "Line: %d Column: %d, Type: %.*s Content: %.*s"
		, tok.Line, tok.Column
		, type_str.Len, type_str.Ptr
		, tok.Text.Len, tok.Text.Ptr
	);
	return result;
}

bool lex__eat( TokArray* self, TokType type );

Token* lex_current(TokArray* self, bool skip_formatting )
{
	if ( skip_formatting )
	{
		while ( self->Arr[self->Idx].Type == Tok_NewLine || self->Arr[self->Idx].Type == Tok_Comment  )
			self->Idx++;
	}
	return & self->Arr[self->Idx];
}

Token* lex_peek(TokArray self, bool skip_formatting)
{
	s32 idx = self.Idx;
	if ( skip_formatting )
	{
		while ( self.Arr[idx].Type == Tok_NewLine )
			idx++;

		return & self.Arr[idx];
	}
	return & self.Arr[idx];
}

Token* lex_previous(TokArray self, bool skip_formatting)
{
	s32 idx = self.Idx;
	if ( skip_formatting )
	{
		while ( self.Arr[idx].Type == Tok_NewLine )
			idx --;

		return & self.Arr[idx];
	}
	return & self.Arr[idx - 1];
}

Token* lex_next(TokArray self, bool skip_formatting)
{
	s32 idx = self.Idx;
	if ( skip_formatting )
	{
		while ( self.Arr[idx].Type == Tok_NewLine )
			idx++;

		return & self.Arr[idx + 1];
	}
	return & self.Arr[idx + 1];
}

enum
{
	Lex_Continue,
	Lex_ReturnNull,
};

FORCEINLINE
void lexer_move_forward( LexContext* ctx )
{
	if ( * ctx->scanner == '\n' ) {
		ctx->line   += 1;
		ctx->column  = 1;
	}
	else {
		++ ctx->column;
	}
	-- ctx->left;
	++ ctx->scanner;
}
#define move_forward() lexer_move_forward(ctx)

FORCEINLINE
void lexer_skip_whitespace( LexContext* ctx )
{
	while ( ctx->left && char_is_space( * ctx->scanner ) )
		move_forward();
}
#define skip_whitespace() lexer_skip_whitespace(ctx)

FORCEINLINE
void lexer_end_line( LexContext* ctx )
{
	while ( ctx->left && (* ctx->scanner) == ' ' )
		move_forward();

	if ( ctx->left && (* ctx->scanner) == '\r' ) {
		move_forward();
		move_forward();
	}
	else if ( ctx->left && (* ctx->scanner) == '\n' )
		move_forward();
}
#define end_line() lexer_end_line(ctx)

// TODO(Ed): We need to to attempt to recover from a lex failure?
s32 lex_preprocessor_define( LexContext* ctx )
{
	Token name = { { ctx->scanner, 1 }, Tok_Identifier, ctx->line, ctx->column, TF_Preprocess };
	move_forward();

	while ( ctx->left && ( char_is_alphanumeric((* ctx->scanner)) || (* ctx->scanner) == '_' ) ) {
		move_forward();
		name.Text.Len++;
	}

	Specifier spec    = str_to_specifier( name.Text );
	TokType   attrib  = str_to_toktype( name.Text );
	b32 not_specifier = spec   == Spec_Invalid;
	b32 not_attribute = attrib <= Tok___Attributes_Start;

	Macro  macro            = { name.Text, MT_Expression, (MacroFlags)0 };
	Macro* registered_macro = lookup_macro(name.Text);

	if ( registered_macro == nullptr && not_specifier && not_attribute ) {
		log_fmt("Warning: '%S' was not registered before the lexer processed its #define directive, it will be registered as a expression macro\n"
			, name.Text 
		);
		// GEN_DEBUG_TRAP();
	}
	array_append( _ctx->Lexer_Tokens, name );

	if ( ctx->left && (* ctx->scanner) == '(' )
	{
		if (registered_macro && ! macro_is_functional(* registered_macro)) {
			log_fmt("Warning: %S registered macro is not flagged as functional yet the definition detects opening parenthesis '(' for arguments\n"
				, name.Text
			);
			// GEN_DEBUG_TRAP();
		}
		else {
			macro.Flags |= MF_Functional;
		}

		Token opening_paren = { { ctx->scanner, 1 }, Tok_Paren_Open, ctx->line, ctx->column, TF_Preprocess };
		array_append( _ctx->Lexer_Tokens, opening_paren );
		move_forward();

		Token last_parameter = {};
		// We need to tokenize the define's arguments now:
		while( ctx->left && * ctx->scanner != ')')
		{
			skip_whitespace();
			
			Str possible_varadic = { ctx->scanner, 3 };
			if ( ctx->left > 3 && str_are_equal( txt("..."), possible_varadic ) ) {
				Token parameter = { { ctx->scanner, 3 }, Tok_Preprocess_Define_Param, ctx->line, ctx->column, TF_Preprocess };
				move_forward();
				move_forward();
				move_forward();

				array_append(_ctx->Lexer_Tokens, parameter);
				skip_whitespace();
				last_parameter = parameter;

				while ( (* ctx->scanner) == '\\' ) {
					move_forward();
					skip_whitespace();
				}
				if (* ctx->scanner != ')' )
				{
					log_failure("lex_preprocessor_define(%d, %d): Expected a ')' after '...' (varaidc macro param) %S\n"
						, ctx->line
						, ctx->column
						, name.Text
					);
					return Lex_ReturnNull;
				}
				break;
			}
			else if ( (* ctx->scanner) == '\\' ) {
				move_forward();
				skip_whitespace();
				continue;
			}
			else if ( char_is_alpha( (* ctx->scanner) ) || (* ctx->scanner) == '_' )
			{
				Token parameter = { { ctx->scanner, 1 }, Tok_Preprocess_Define_Param, ctx->line, ctx->column, TF_Preprocess };
				move_forward();

				while ( ctx->left && ( char_is_alphanumeric((* ctx->scanner)) || (* ctx->scanner) == '_' ) )
				{
					move_forward();
					parameter.Text.Len++;
				}
				array_append(_ctx->Lexer_Tokens, parameter);
				skip_whitespace();
				last_parameter = parameter;
			}
			else {
				log_failure("lex_preprocessor_define(%d, %d): Expected a '_' or alpha character for a parameter name for %S\n"
					, ctx->line
					, ctx->column
					, name.Text
				);
				return Lex_ReturnNull;
			}

			if (* ctx->scanner == ')' )
				break;

			// There should be a comma
			if ( * ctx->scanner != ',' ) {
				log_failure("lex_preprocessor_define(%d, %d): Expected a comma after parameter %S for %S\n"
					, ctx->line
					, ctx->column
					, last_parameter.Text
					, name.Text
				);
				return Lex_ReturnNull;
			}
			Token comma = { { ctx->scanner, 1 }, Tok_Comma, ctx->line, ctx->column, TF_Preprocess };
			array_append(_ctx->Lexer_Tokens, comma);
			move_forward();
		}
		
		if ( * ctx->scanner != ')' ) {
			log_failure("lex_preprocessor_define(%d, %d): Expected a ')' after last_parameter %S for %S (ran out of characters...)\n"
				, ctx->line
				, ctx->column
				, last_parameter.Text
				, name.Text
			);
			return Lex_ReturnNull;
		}
		Token closing_paren = { { ctx->scanner, 1 }, Tok_Paren_Close, ctx->line, ctx->column, TF_Preprocess };
		array_append(_ctx->Lexer_Tokens, closing_paren);
		move_forward();
	}
	else if ( registered_macro && macro_is_functional( * registered_macro) ) {
		if (registered_macro && ! macro_is_functional(* registered_macro)) {
			log_fmt("Warning: %S registered macro is flagged as functional yet the definition detects no opening parenthesis '(' for arguments\n"
				, name.Text
			);
			GEN_DEBUG_TRAP();
		}
	}

	if ( registered_macro == nullptr ) {
		register_macro(macro);
	}

	// Define's content handled by lex_preprocessor_directive (the original caller of this)
	return Lex_Continue;
}

// TODO(Ed): We need to to attempt to recover from a lex failure?
FORCEINLINE
s32 lex_preprocessor_directive( LexContext* ctx )
{
	char const* hash = ctx->scanner;
	Token hash_tok = { { hash, 1 }, Tok_Preprocess_Hash, ctx->line, ctx->column, TF_Preprocess };
	array_append( _ctx->Lexer_Tokens, hash_tok  );

	move_forward();
	skip_whitespace();

	ctx->token.Text.Ptr = ctx->scanner;
	while (ctx->left && ! char_is_space((* ctx->scanner)) )
	{
		move_forward();
		ctx->token.Text.Len++;
	}

	ctx->token.Type = str_to_toktype( ctx->token.Text );

	bool   is_preprocessor = ctx->token.Type >= Tok_Preprocess_Define && ctx->token.Type <= Tok_Preprocess_Pragma;
	if ( ! is_preprocessor )
	{
		ctx->token.Type  = Tok_Preprocess_Unsupported;

		// Its an unsupported directive, skip it
		s32 within_string = false;
		s32 within_char   = false;
		while ( ctx->left )
		{
			if ( * ctx->scanner == '"' && ! within_char )
				within_string ^= true;

			if ( * ctx->scanner == '\'' && ! within_string )
				within_char ^= true;

			if ( * ctx->scanner == '\\' && ! within_string && ! within_char )
			{
				move_forward();
				ctx->token.Text.Len++;

				if ( (* ctx->scanner) == '\r' )
				{
					move_forward();
					ctx->token.Text.Len++;
				}

				if ( (* ctx->scanner) == '\n' )
				{
					move_forward();
					ctx->token.Text.Len++;
					continue;
				}
				else
				{
					log_failure( "gen::Parser::lex: Invalid escape sequence '\\%c' (%d, %d)"
								" in preprocessor directive (%d, %d)\n%.100s"
						, (* ctx->scanner), ctx->line, ctx->column
						, ctx->token.Line, ctx->token.Column, ctx->token.Text );
					break;
				}
			}

			if ( (* ctx->scanner) == '\r' )
			{
				move_forward();
				ctx->token.Text.Len++;
			}

			if ( (* ctx->scanner) == '\n' )
			{
				move_forward();
				ctx->token.Text.Len++;
				break;
			}

			move_forward();
			ctx->token.Text.Len++;
		}

		ctx->token.Text.Len = ctx->token.Text.Len + ctx->token.Text.Ptr - hash;
		ctx->token.Text.Ptr = hash;
		array_append( _ctx->Lexer_Tokens, ctx->token );
		return Lex_Continue; // Skip found token, its all handled here.
	}

	if ( ctx->token.Type == Tok_Preprocess_Else || ctx->token.Type == Tok_Preprocess_EndIf )
	{
		ctx->token.Flags |= TF_Preprocess_Cond;
		array_append( _ctx->Lexer_Tokens, ctx->token );
		end_line();
		return Lex_Continue;
	}
	else if ( ctx->token.Type >= Tok_Preprocess_If && ctx->token.Type <= Tok_Preprocess_ElIf  )
	{
		ctx->token.Flags |= TF_Preprocess_Cond;
	}

	array_append( _ctx->Lexer_Tokens, ctx->token );

	skip_whitespace();

	if ( ctx->token.Type == Tok_Preprocess_Define )
	{
		u32 result = lex_preprocessor_define(ctx); // handles: #define <name>( <params> ) - define's content handled later on within this scope.
		if (result != Lex_Continue)
			return Lex_ReturnNull;
	}

	Token preprocess_content = { { ctx->scanner, 0 }, Tok_Preprocess_Content, ctx->line, ctx->column, TF_Preprocess };

	if ( ctx->token.Type == Tok_Preprocess_Include )
	{
		preprocess_content.Type = Tok_String;

		if ( (* ctx->scanner) != '"' && (* ctx->scanner) != '<' )
		{
			StrBuilder directive_str = strbuilder_fmt_buf( _ctx->Allocator_Temp, "%.*s", min( 80, ctx->left + preprocess_content.Text.Len ), ctx->token.Text.Ptr );

			log_failure( "gen::Parser::lex: Expected '\"' or '<' after #include, not '%c' (%d, %d)\n%s"
				, (* ctx->scanner)
				, preprocess_content.Line
				, preprocess_content.Column
				, (char*) directive_str
			);
			return Lex_ReturnNull;
		}
		move_forward();
		preprocess_content.Text.Len++;

		while ( ctx->left && (* ctx->scanner) != '"' && (* ctx->scanner) != '>' )
		{
			move_forward();
			preprocess_content.Text.Len++;
		}

		move_forward();
		preprocess_content.Text.Len++;

		if ( (* ctx->scanner) == '\r' && ctx->scanner[1] == '\n' )
		{
			move_forward();
			move_forward();
		}
		else if ( (* ctx->scanner) == '\n' )
		{
			move_forward();
		}

		array_append( _ctx->Lexer_Tokens, preprocess_content );
		return Lex_Continue; // Skip found token, its all handled here.
	}

	s32 within_string = false;
	s32 within_char   = false;

	// Consume preprocess content
	while ( ctx->left )
	{
		if ( (* ctx->scanner) == '"' && ! within_char )
			within_string ^= true;

		if ( (* ctx->scanner) == '\'' && ! within_string )
			within_char ^= true;

		if ( (* ctx->scanner) == '\\' && ! within_string && ! within_char )
		{
			move_forward();
			preprocess_content.Text.Len++;

			if ( (* ctx->scanner) == '\r' )
			{
				move_forward();
				preprocess_content.Text.Len++;
			}

			if ( (* ctx->scanner) == '\n' )
			{
				move_forward();
				preprocess_content.Text.Len++;
				continue;
			}
			else
			{
				StrBuilder directive_str = strbuilder_make_length( _ctx->Allocator_Temp, ctx->token.Text.Ptr, ctx->token.Text.Len );
				StrBuilder content_str   = strbuilder_fmt_buf( _ctx->Allocator_Temp, "%.*s", min( 400, ctx->left + preprocess_content.Text.Len ), preprocess_content.Text.Ptr );

				log_failure( "gen::Parser::lex: Invalid escape sequence '\\%c' (%d, %d)"
							" in preprocessor directive '%s' (%d, %d)\n%s"
					, (* ctx->scanner), ctx->line, ctx->column
					, directive_str, preprocess_content.Line, preprocess_content.Column
					, content_str );
				return Lex_ReturnNull;
				break;
			}
		}

		if ( (* ctx->scanner) == '\r' )
		{
			break;
			//move_forward();
		}

		if ( (* ctx->scanner) == '\n' )
		{
			//move_forward();
			break;
		}

		move_forward();
		preprocess_content.Text.Len++;
	}

	array_append( _ctx->Lexer_Tokens, preprocess_content );
	return Lex_Continue; // Skip found token, its all handled here.
}

FORCEINLINE
void lex_found_token( LexContext* ctx )
{
	if ( ctx->token.Type != Tok_Invalid ) {
		array_append( _ctx->Lexer_Tokens, ctx->token );
		return;
	}

	TokType type = str_to_toktype( ctx->token.Text );

	if (type <= Tok_Access_Public && type >= Tok_Access_Private ) {
		ctx->token.Flags |= TF_AccessSpecifier;
	}
	if ( type > Tok___Attributes_Start ) {
		ctx->token.Flags |= TF_Attribute;
	}
	if ( type == Tok_Decl_Extern_Linkage )
	{
		skip_whitespace();

		if ( (* ctx->scanner) != '"' ) {
			type         = Tok_Spec_Extern;
			ctx->token.Flags |= TF_Specifier;
		}

		ctx->token.Type = type;
		array_append( _ctx->Lexer_Tokens, ctx->token );
		return;
	}
	if ( ( type <= Tok_Star && type >= Tok_Spec_Alignas)
			|| type == Tok_Ampersand
			|| type == Tok_Ampersand_DBL )
	{
		ctx->token.Type   = type;
		ctx->token.Flags |= TF_Specifier;
		array_append( _ctx->Lexer_Tokens, ctx->token );
		return;
	}
	if ( type != Tok_Invalid )
	{
		ctx->token.Type = type;
		array_append( _ctx->Lexer_Tokens, ctx->token );
		return;
	}

	Macro* macro = lookup_macro( ctx->token.Text );
	b32 has_args          = ctx->left && (* ctx->scanner) == '(';
	b32 resolved_to_macro = false;
	if (macro) {
		ctx->token.Type   = macrotype_to_toktype(macro->Type);
		b32 is_functional = macro_is_functional(* macro);
		resolved_to_macro = has_args ? is_functional : ! is_functional;
		if ( ! resolved_to_macro && GEN_BUILD_DEBUG ) {
			log_fmt("Info(%d, %d): %S identified as a macro but usage here does not resolve to one (interpreting as identifier)\n"
				, ctx->token.Line
				, ctx->token.Line
				, macro->Name
			);
		}
	}
	if ( resolved_to_macro )
	{
		// TODO(Ed): When we introduce a macro AST (and expression support), we'll properly lex this section.
		// Want to ignore any arguments the define may have as they can be execution expressions.
		if ( has_args ) {
			ctx->token.Flags |= TF_Macro_Functional;
		}
		if ( bitfield_is_set(MacroFlags, macro->Flags, MF_Allow_As_Attribute) ) {
			ctx->token.Flags |= TF_Attribute;
		}
		if ( bitfield_is_set(MacroFlags, macro->Flags, MF_Allow_As_Specifier ) ) {
			ctx->token.Flags |= TF_Specifier;
		}
	}
	else
	{
		ctx->token.Type = Tok_Identifier;
	}

	array_append( _ctx->Lexer_Tokens, ctx->token );
}

// TODO(Ed): We need to to attempt to recover from a lex failure?
neverinline
// TokArray lex( Array<Token> tokens, Str content )
TokArray lex( Str content )
{
	LexContext c; LexContext* ctx = & c;
	c.content = content;
	c.left    = content.Len;
	c.scanner = content.Ptr;

	char const* word        = c.scanner;
	s32         word_length = 0;

	c.line   = 1;
	c.column = 1;

	skip_whitespace();
	if ( c.left <= 0 )
	{
		log_failure( "gen::lex: no tokens found (only whitespace provided)" );
		TokArray null_array = {};
		return null_array;
	}

	array_clear(_ctx->Lexer_Tokens);

	b32 preprocess_args = true;

	while (c.left )
	{
		#if 0
		if (Tokens.num())
		{
			log_fmt("\nLastTok: %SB", Tokens.back().to_strbuilder());
		}
		#endif

		{
			Token thanks_c = { { c.scanner, 0 }, Tok_Invalid, c.line, c.column, TF_Null };
			c.token = thanks_c;
		}

		bool is_define = false;

		if ( c.column == 1 )
		{
			if ( (* ctx->scanner) == '\r')
			{
				move_forward();
				c.token.Text.Len = 1;
			}

			if ( (* ctx->scanner) == '\n' )
			{
				move_forward();

				c.token.Type = Tok_NewLine;
				c.token.Text.Len++;

				array_append( _ctx->Lexer_Tokens, c.token );
				continue;
			}
		}

		c.token.Text.Len = 0;

		skip_whitespace();
		if ( c.left <= 0 )
			break;

		switch ( (* ctx->scanner) )
		{
			case '#':
			{
				s32 result = lex_preprocessor_directive( ctx );
				switch ( result )
				{
					case Lex_Continue:
					{
						//TokType last_type = Tokens[array_get_header(Tokens)->Num - 2].Type;
						//if ( last_type == Tok_Preprocess_Pragma )
						{
							{
								Token thanks_c = { { c.scanner, 0 }, Tok_Invalid, c.line, c.column, TF_Null };
								c.token = thanks_c;
							}
							if ( (* ctx->scanner) == '\r')
							{
								move_forward();
								c.token.Text.Len = 1;
							}

							if ( (* ctx->scanner) == '\n' )
							{
								c.token.Type = Tok_NewLine;
								c.token.Text.Len++;
								move_forward();

								array_append( _ctx->Lexer_Tokens, c.token );
							}
						}
						continue;
					}

					case Lex_ReturnNull:
					{
						TokArray tok_array =  {};
						return tok_array;
					}
				}
			}
			case '.':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Access_MemberSymbol;
				c.token.Flags  = TF_AccessOperator;

				if (c.left) {
					move_forward();
				}

				if ( (* ctx->scanner) == '.' )
				{
					move_forward();
					if( (* ctx->scanner) == '.' )
					{
						c.token.Text.Len = 3;
						c.token.Type     = Tok_Varadic_Argument;
						c.token.Flags    = TF_Null;
						move_forward();
					}
					else
					{
						StrBuilder context_str = strbuilder_fmt_buf( _ctx->Allocator_Temp, "%s", c.scanner, min( 100, c.left ) );

						log_failure( "gen::lex: invalid varadic argument, expected '...' got '..%c' (%d, %d)\n%s", (* ctx->scanner), c.line, c.column, context_str );
					}
				}

				goto FoundToken;
			}
			case '&' :
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Ampersand;
				c.token.Flags |= TF_Operator;
				c.token.Flags |= TF_Specifier;

				if (c.left)
					move_forward();

				if ( (* ctx->scanner) == '&' )	// &&
				{
					c.token.Text.Len = 2;
					c.token.Type     = Tok_Ampersand_DBL;

					if (c.left)
						move_forward();
				}

				goto FoundToken;
			}
			case ':':
			{
				Str text = { c.scanner, 1 };
				c.token.Text = text;
				c.token.Type = Tok_Assign_Classifer;
				// Can be either a classifier (ParentType, Bitfield width), or ternary else
				// token.Type   = Tok_Colon;

				if (c.left)
					move_forward();

				if ( (* ctx->scanner) == ':' )
				{
					move_forward();
					c.token.Type = Tok_Access_StaticSymbol;
					c.token.Text.Len++;
				}
				goto FoundToken;
			}
			case '{':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_BraceCurly_Open;

				if (c.left)
					move_forward();
				goto FoundToken;
			}
			case '}':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_BraceCurly_Close;
				c.token.Flags  = TF_EndDefinition;

				if (c.left)
					move_forward();

				end_line();
				goto FoundToken;
			}
			case '[':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_BraceSquare_Open;
				if ( c.left )
				{
					move_forward();

					if ( (* ctx->scanner) == ']' )
					{
						c.token.Text.Len = 2;
						c.token.Type     = Tok_Operator;
						move_forward();
					}
				}
				goto FoundToken;
			}
			case ']':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_BraceSquare_Close;

				if (c.left)
					move_forward();
				goto FoundToken;
			}
			case '(':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Paren_Open;

				if (c.left)
					move_forward();
				goto FoundToken;
			}
			case ')':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Paren_Close;

				if (c.left)
					move_forward();
				goto FoundToken;
			}
			case '\'':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Char;
				c.token.Flags  = TF_Literal;

				move_forward();

				if ( c.left && (* ctx->scanner) == '\\' )
				{
					move_forward();
					c.token.Text.Len++;

					if ( (* ctx->scanner) == '\'' )
					{
						move_forward();
						c.token.Text.Len++;
					}
				}

				while ( c.left && (* ctx->scanner) != '\'' )
				{
					move_forward();
					c.token.Text.Len++;
				}

				if ( c.left )
				{
					move_forward();
					c.token.Text.Len++;
				}
				goto FoundToken;
			}
			case ',':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Comma;
				c.token.Flags  = TF_Operator;

				if (c.left)
					move_forward();
				goto FoundToken;
			}
			case '*':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Star;
				c.token.Flags |= TF_Specifier;
				c.token.Flags |= TF_Operator;

				if (c.left)
					move_forward();

				if ( (* ctx->scanner) == '=' )
				{
					c.token.Text.Len++;
					c.token.Flags |= TF_Assign;
					// c.token.Type = Tok_Assign_Multiply;

					if ( c.left )
						move_forward();
				}

				goto FoundToken;
			}
			case ';':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Statement_End;
				c.token.Flags  = TF_EndDefinition;

				if (c.left)
					move_forward();

				end_line();
				goto FoundToken;
			}
			case '"':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_String;
				c.token.Flags |= TF_Literal;

				move_forward();
				while ( c.left )
				{
					if ( (* ctx->scanner) == '"' )
					{
						move_forward();
						break;
					}

					if ( (* ctx->scanner) == '\\' )
					{
						move_forward();
						c.token.Text.Len++;

						if ( c.left )
						{
							move_forward();
							c.token.Text.Len++;
						}
						continue;
					}

					move_forward();
					c.token.Text.Len++;
				}
				goto FoundToken;
			}
			case '?':
			{
				Str text = { c.scanner, 1 };
				c.token.Text     = text;
				c.token.Type     = Tok_Operator;
				// c.token.Type     = Tok_Ternary;
				c.token.Flags    = TF_Operator;

				if (c.left)
					move_forward();

				goto FoundToken;
			}
			case '=':
			{
				Str text = { c.scanner, 1 };
				c.token.Text     = text;
				c.token.Type     = Tok_Operator;
				// c.token.Type     = Tok_Assign;
				c.token.Flags    = TF_Operator;
				c.token.Flags   |= TF_Assign;

				if (c.left)
					move_forward();

				if ( (* ctx->scanner) == '=' )
				{
					c.token.Text.Len++;
					c.token.Flags = TF_Operator;

					if (c.left)
						move_forward();
				}

				goto FoundToken;
			}
			case '+':
			{
				// c.token.Type = Tok_Add

			}
			case '%':
			{
				// c.token.Type = Tok_Modulo;

			}
			case '^':
			{
				// c.token.Type = Tok_B_XOr;
			}
			case '~':
			{
				// c.token.Type = Tok_Unary_Not;

			}
			case '!':
			{
				// c.token.Type = Tok_L_Not;
			}
			case '<':
			{
				// c.token.Type = Tok_Lesser;

			}
			case '>':
			{
				// c.token.Type = Tok_Greater;

			}
			case '|':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Operator;
				c.token.Flags  = TF_Operator;
				// token.Type   = Tok_L_Or;

				if (c.left)
					move_forward();

				if ( (* ctx->scanner) == '=' )
				{
					c.token.Text.Len++;
					c.token.Flags |= TF_Assign;
					// token.Flags |= TokFlags::Assignment;
					// token.Type = Tok_Assign_L_Or;

					if (c.left)
						move_forward();
				}
				else while ( c.left && (* ctx->scanner) == *(c.scanner - 1) && c.token.Text.Len < 3 )
				{
					c.token.Text.Len++;

					if (c.left)
						move_forward();
				}
				goto FoundToken;
			}

			// Dash is unfortunately a bit more complicated...
			case '-':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Operator;
				// token.Type = Tok_Subtract;
				c.token.Flags  = TF_Operator;
				if ( c.left )
				{
					move_forward();

					if ( (* ctx->scanner) == '>'  )
					{
						c.token.Text.Len++;
//						token.Type = Tok_Access_PointerToMemberSymbol;
						c.token.Flags |= TF_AccessOperator;
						move_forward();

						if ( (* ctx->scanner) == '*' )
						{
//							token.Type = Tok_Access_PointerToMemberOfPointerSymbol;
							c.token.Text.Len++;
							move_forward();
						}
					}
					else if ( (* ctx->scanner) == '=' )
					{
						c.token.Text.Len++;
						// token.Type = Tok_Assign_Subtract;
						c.token.Flags |= TF_Assign;

						if (c.left)
							move_forward();
					}
					else while ( c.left && (* ctx->scanner) == *(c.scanner - 1) && c.token.Text.Len < 3 )
					{
						c.token.Text.Len++;

						if (c.left)
							move_forward();
					}
				}
				goto FoundToken;
			}
			case '/':
			{
				Str text = { c.scanner, 1 };
				c.token.Text   = text;
				c.token.Type   = Tok_Operator;
				// token.Type   = Tok_Divide;
				c.token.Flags  = TF_Operator;
				move_forward();

				if ( c.left )
				{
					if ( (* ctx->scanner) == '=' )
					{
						// token.Type = TokeType::Assign_Divide;
						move_forward();
						c.token.Text.Len++;
						c.token.Flags = TF_Assign;
					}
					else if ( (* ctx->scanner) == '/' )
					{
						c.token.Type     = Tok_Comment;
						c.token.Text.Len = 2;
						c.token.Flags    = TF_Null;
						move_forward();

						while ( c.left && (* ctx->scanner) != '\n' && (* ctx->scanner) != '\r' )
						{
							move_forward();
							c.token.Text.Len++;
						}

						if ( (* ctx->scanner) == '\r' )
						{
							move_forward();
							c.token.Text.Len++;
						}
						if ( (* ctx->scanner) == '\n' )
						{
							move_forward();
							c.token.Text.Len++;
						}
						array_append( _ctx->Lexer_Tokens, c.token );
						continue;
					}
					else if ( (* ctx->scanner) == '*' )
					{
						c.token.Type     = Tok_Comment;
						c.token.Text.Len = 2;
						c.token.Flags    = TF_Null;
						move_forward();

						bool star   = (* ctx->scanner)    == '*';
						bool slash  = c.scanner[1] == '/';
						bool at_end = star && slash;
						while ( c.left && ! at_end  )
						{
							move_forward();
							c.token.Text.Len++;

							star   = (* ctx->scanner)    == '*';
							slash  = c.scanner[1] == '/';
							at_end = star && slash;
						}
						c.token.Text.Len += 2;
						move_forward();
						move_forward();

						if ( (* ctx->scanner) == '\r' )
						{
							move_forward();
							c.token.Text.Len++;
						}
						if ( (* ctx->scanner) == '\n' )
						{
							move_forward();
							c.token.Text.Len++;
						}
						array_append( _ctx->Lexer_Tokens, c.token );
						// end_line();
						continue;
					}
				}
				goto FoundToken;
			}
		}

		if ( char_is_alpha( (* ctx->scanner) ) || (* ctx->scanner) == '_' )
		{
			Str text = { c.scanner, 1 };
			c.token.Text = text;
			move_forward();

			while ( c.left && ( char_is_alphanumeric((* ctx->scanner)) || (* ctx->scanner) == '_' ) ) {
				move_forward();
				c.token.Text.Len++;
			}

			goto FoundToken;
		}
		else if ( char_is_digit((* ctx->scanner)) )
		{
			// This is a very brute force lex, no checks are done for validity of literal.

			Str text = { c.scanner, 1 };
			c.token.Text   = text;
			c.token.Type   = Tok_Number;
			c.token.Flags  = TF_Literal;
			move_forward();

			if (c.left
			&& (	(* ctx->scanner) == 'x' || (* ctx->scanner) == 'X'
				||	(* ctx->scanner) == 'b' || (* ctx->scanner) == 'B'
				||  (* ctx->scanner) == 'o' || (* ctx->scanner) == 'O' )
			)
			{
				move_forward();
				c.token.Text.Len++;

				while ( c.left && char_is_hex_digit((* ctx->scanner)) ) {
					move_forward();
					c.token.Text.Len++;
				}

				goto FoundToken;
			}

			while ( c.left && char_is_digit((* ctx->scanner)) ) {
				move_forward();
				c.token.Text.Len++;
			}

			if ( c.left && (* ctx->scanner) == '.' )
			{
				move_forward();
				c.token.Text.Len++;

				while ( c.left && char_is_digit((* ctx->scanner)) ) {
					move_forward();
					c.token.Text.Len++;
				}

				// Handle number literal suffixes in a botched way
				if (c.left && (
					(* ctx->scanner) == 'l' || (* ctx->scanner) == 'L' ||  // long/long long
					(* ctx->scanner) == 'u' || (* ctx->scanner) == 'U' ||  // unsigned
					(* ctx->scanner) == 'f' || (* ctx->scanner) == 'F' ||  // float
					(* ctx->scanner) == 'i' || (* ctx->scanner) == 'I' ||  // imaginary
					(* ctx->scanner) == 'z' || (* ctx->scanner) == 'Z'))   // complex
				{
					char prev = (* ctx->scanner);
					move_forward();
					c.token.Text.Len++;

					// Handle 'll'/'LL' as a special case when we just processed an 'l'/'L'
					if (c.left && (prev == 'l' || prev == 'L') && ((* ctx->scanner) == 'l' || (* ctx->scanner) == 'L')) {
						move_forward();
						c.token.Text.Len++;
					}
				}
			}

			goto FoundToken;
		}
		else
		{
			s32 start = max( 0, array_num(_ctx->Lexer_Tokens) - 100 );
			log_fmt("\n%d\n", start);
			for ( s32 idx = start; idx < array_num(_ctx->Lexer_Tokens); idx++ )
			{
				log_fmt( "Token %d Type: %s : %.*s\n"
					, idx
					, toktype_to_str( _ctx->Lexer_Tokens[ idx ].Type ).Ptr
					, _ctx->Lexer_Tokens[ idx ].Text.Len, _ctx->Lexer_Tokens[ idx ].Text.Ptr
				);
			}

			StrBuilder context_str = strbuilder_fmt_buf( _ctx->Allocator_Temp, "%.*s", min( 100, c.left ), c.scanner );
			log_failure( "Failed to lex token '%c' (%d, %d)\n%s", (* ctx->scanner), c.line, c.column, context_str );

			// Skip to next whitespace since we can't know if anything else is valid until then.
			while ( c.left && ! char_is_space( (* ctx->scanner) ) ) {
				move_forward();
			}
		}

		FoundToken:
		{
			lex_found_token( ctx );
			TokType last_type = array_back(_ctx->Lexer_Tokens)->Type;
			if ( last_type == Tok_Preprocess_Macro_Stmt || last_type == Tok_Preprocess_Macro_Expr )
			{
				Token thanks_c = { { c.scanner, 0 }, Tok_Invalid, c.line, c.column, TF_Null };
				c.token = thanks_c;
				if ( (* ctx->scanner) == '\r') {
					move_forward();
					c.token.Text.Len = 1;
				}
				if ( (* ctx->scanner) == '\n' ) 
				{
					c.token.Type = Tok_NewLine;
					c.token.Text.Len++;
					move_forward();

					array_append( _ctx->Lexer_Tokens, c.token );
					continue;
				}
			}
		}
	}

	if ( array_num(_ctx->Lexer_Tokens) == 0 ) {
		log_failure( "Failed to lex any tokens" );
		TokArray tok_array =  {};
		return tok_array;
	}

	TokArray result = { _ctx->Lexer_Tokens, 0 };
	return result;
}

#undef move_forward
#undef skip_whitespace
#undef end_line
// These macros are used in the swtich cases within parser.cpp

#define GEN_PARSER_CLASS_STRUCT_BODY_ALLOWED_MEMBER_TOK_SPECIFIER_CASES \
case Tok_Spec_Consteval:              \
case Tok_Spec_Constexpr:              \
case Tok_Spec_Constinit:              \
case Tok_Spec_Explicit:               \
case Tok_Spec_ForceInline:            \
case Tok_Spec_ForceInline_Debuggable: \
case Tok_Spec_Inline:                 \
case Tok_Spec_Mutable:                \
case Tok_Spec_NeverInline:            \
case Tok_Spec_Static:                 \
case Tok_Spec_Volatile:               \
case Tok_Spec_Virtual

#define GEN_PARSER_CLASS_STRUCT_BODY_ALLOWED_MEMBER_SPECIFIER_CASES \
case Spec_Constexpr:              \
case Spec_Constinit:              \
case Spec_Explicit:               \
case Spec_Inline:                 \
case Spec_ForceInline:            \
case Spec_ForceInline_Debuggable: \
case Spec_Mutable:                \
case Spec_NeverInline:            \
case Spec_Static:                 \
case Spec_Volatile:               \
case Spec_Virtual

#define GEN_PARSER_CLASS_GLOBAL_NSPACE_ALLOWED_MEMBER_TOK_SPECIFIER_CASES \
case Tok_Spec_Consteval:              \
case Tok_Spec_Constexpr:              \
case Tok_Spec_Constinit:              \
case Tok_Spec_Extern:                 \
case Tok_Spec_ForceInline:            \
case Tok_Spec_ForceInline_Debuggable: \
case Tok_Spec_Global:                 \
case Tok_Spec_Inline:                 \
case Tok_Spec_Internal_Linkage:       \
case Tok_Spec_NeverInline:            \
case Tok_Spec_Static

#define GEN_PARSER_CLASS_GLOBAL_NSPACE_ALLOWED_MEMBER_SPECIFIER_CASES \
case Spec_Constexpr:              \
case Spec_Constinit:              \
case Spec_ForceInline:            \
case Spec_ForceInline_Debuggable: \
case Spec_Global:                 \
case Spec_External_Linkage:       \
case Spec_Internal_Linkage:       \
case Spec_Inline:                 \
case Spec_Mutable:                \
case Spec_NeverInline:            \
case Spec_Static:                 \
case Spec_Volatile

#define GEN_PARSER_FRIEND_ALLOWED_SPECIFIER_CASES \
case Spec_Const:       \
case Spec_Inline:      \
case Spec_ForceInline

#define GEN_PARSER_FUNCTION_ALLOWED_SPECIFIER_CASES \
case Spec_Const:                  \
case Spec_Consteval:              \
case Spec_Constexpr:              \
case Spec_External_Linkage:       \
case Spec_Internal_Linkage:       \
case Spec_ForceInline:            \
case Spec_ForceInline_Debuggable: \
case Spec_Inline:                 \
case Spec_NeverInline:            \
case Spec_Static

#define GEN_PARSER_OPERATOR_ALLOWED_SPECIFIER_CASES \
case Spec_Const:       \
case Spec_Constexpr:   \
case Spec_ForceInline: \
case Spec_Inline:      \
case Spec_NeverInline: \
case Spec_Static

#define GEN_PARSER_TEMPLATE_ALLOWED_SPECIFIER_CASES \
case Spec_Const:                  \
case Spec_Constexpr:              \
case Spec_Constinit:              \
case Spec_External_Linkage:       \
case Spec_Global:                 \
case Spec_Inline:                 \
case Spec_ForceInline:            \
case Spec_ForceInline_Debuggable: \
case Spec_Local_Persist:          \
case Spec_Mutable:                \
case Spec_Static:                 \
case Spec_Thread_Local:           \
case Spec_Volatile

#define GEN_PARSER_VARIABLE_ALLOWED_SPECIFIER_CASES \
case Spec_Const:            \
case Spec_Constexpr:        \
case Spec_Constinit:        \
case Spec_External_Linkage: \
case Spec_Global:           \
case Spec_Inline:           \
case Spec_Local_Persist:    \
case Spec_Mutable:          \
case Spec_Static:           \
case Spec_Thread_Local:     \
case Spec_Volatile

#define GEN_PARSER_TYPENAME_ALLOWED_SUFFIX_SPECIFIER_CASES \
case Spec_Const:    \
case Spec_Ptr:      \
case Spec_Ref:      \
case Spec_RValue

// TODO(Ed) : Rename ETok_Capture_Start, ETok_Capture_End to Open_Parenthesis adn Close_Parenthesis

constexpr bool lex_dont_skip_formatting = false;
constexpr bool      lex_skip_formatting = true;

void parser_push( ParseContext* ctx, StackNode* node )
{
	node->Prev = ctx->Scope;
	ctx->Scope = node;

#if 0 && GEN_BUILD_DEBUG
	log_fmt("\tEntering _ctx->parser: %.*s\n", Scope->ProcName.Len, Scope->ProcName.Ptr );
#endif
}

void parser_pop(ParseContext* ctx)
{
#if 0 && GEN_BUILD_DEBUG
	log_fmt("\tPopping  _ctx->parser: %.*s\n", Scope->ProcName.Len, Scope->ProcName.Ptr );
#endif
	ctx->Scope = ctx->Scope->Prev;
}

StrBuilder parser_to_strbuilder(ParseContext ctx)
{
	StrBuilder result = strbuilder_make_reserve( _ctx->Allocator_Temp, kilobytes(4) );

	Token scope_start = * ctx.Scope->Start;
	Token last_valid  = ctx.Tokens.Idx >= array_num(ctx.Tokens.Arr) ? ctx.Tokens.Arr[array_num(ctx.Tokens.Arr) -1] : (* lex_current(& ctx.Tokens, true));

	sptr        length  = scope_start.Text.Len;
	char const* current = scope_start.Text.Ptr + length;
	while ( current <= array_back( ctx.Tokens.Arr)->Text.Ptr && (* current) != '\n' && length < 74 )
	{
		current++;
		length++;
	}

	Str scope_str = { scope_start.Text.Ptr, length };
	StrBuilder line = strbuilder_make_str( _ctx->Allocator_Temp, scope_str );
	strbuilder_append_fmt( & result, "\tScope    : %s\n", line );
	strbuilder_free(& line);

	sptr   dist            = (sptr)last_valid.Text.Ptr - (sptr)scope_start.Text.Ptr + 2;
	sptr   length_from_err = dist;

	Str err_str        = { last_valid.Text.Ptr, length_from_err };
	StrBuilder line_from_err = strbuilder_make_str( _ctx->Allocator_Temp, err_str );

	if ( length_from_err < 100 )
		strbuilder_append_fmt(& result, "\t(%d, %d):%*c\n", last_valid.Line, last_valid.Column, length_from_err, '^' );
	else
		strbuilder_append_fmt(& result, "\t(%d, %d)\n", last_valid.Line, last_valid.Column );

	StackNode* curr_scope = ctx.Scope;
	s32 level = 0;
	do
	{
		if ( curr_scope->Name.Ptr ) {
			strbuilder_append_fmt(& result, "\t%d: %s, AST Name: %.*s\n", level, curr_scope->ProcName.Ptr, curr_scope->Name.Len, curr_scope->Name.Ptr );
		}
		else {
			strbuilder_append_fmt(& result, "\t%d: %s\n", level, curr_scope->ProcName.Ptr );
		}

		curr_scope = curr_scope->Prev;
		level++;
	}
	while ( curr_scope );
	return result;
}

bool lex__eat(TokArray* self, TokType type )
{
	if ( array_num(self->Arr) - self->Idx <= 0 ) {
		log_failure( "No tokens left.\n%s", parser_to_strbuilder(_ctx->parser) );
		return false;
	}

	Token at_idx = self->Arr[ self->Idx ];

	if ( ( at_idx.Type == Tok_NewLine && type != Tok_NewLine )
	||   ( at_idx.Type == Tok_Comment && type != Tok_Comment ) )
	{
		self->Idx ++;
	}

	b32 not_accepted  = at_idx.Type != type;
	b32 is_identifier = at_idx.Type == Tok_Identifier;
	if ( not_accepted )
	{
		Macro* macro = lookup_macro(at_idx.Text);
		b32 accept_as_identifier = macro && bitfield_is_set(MacroFlags, macro->Flags, MF_Allow_As_Identifier );
		not_accepted             = type == Tok_Identifier && accept_as_identifier ? false : true;
	}
	if ( not_accepted )
	{
		Token tok = * lex_current( self, lex_skip_formatting );
		log_failure( "Parse Error, TokArray::eat, Expected: ' %s ' not ' %.*s ' (%d, %d)`\n%s"
			, toktype_to_str(type).Ptr
			, at_idx.Text.Len, at_idx.Text.Ptr
			, tok.Line
			, tok.Column
			, parser_to_strbuilder(_ctx->parser)
		);
		GEN_DEBUG_TRAP();
		return false;
	}

#if 0 && GEN_BUILD_DEBUG
	log_fmt("Ate: %SB\n", self->Arr[Idx].to_strbuilder() );
#endif

	self->Idx ++;
	return true;
}

internal
void parser_init()
{
	_ctx->Lexer_Tokens = array_init_reserve(Token, _ctx->Allocator_DyanmicContainers, _ctx->InitSize_LexerTokens );
}

internal
void parser_deinit()
{
	Array(Token) null_array = { nullptr };
	_ctx->Lexer_Tokens = null_array;
}

#pragma region Helper Macros

#define check_parse_args( def ) _check_parse_args(def, stringize(_func_) )
bool _check_parse_args( Str def, char const* func_name )
{
	if ( def.Len <= 0 )
	{
		log_failure( c_str_fmt_buf("gen::%s: length must greater than 0", func_name) );
		parser_pop(& _ctx->parser);
		return false;
	}
	if ( def.Ptr == nullptr )
	{
		log_failure( c_str_fmt_buf("gen::%s: def was null", func_name) );
		parser_pop(& _ctx->parser);
		return false;
	}
	return true;
}

#	define currtok_noskip (* lex_current( &  _ctx->parser.Tokens, lex_dont_skip_formatting ))
#	define currtok        (* lex_current( & _ctx->parser.Tokens, lex_skip_formatting ))
#	define peektok        (* lex_peek(_ctx->parser.Tokens, lex_skip_formatting))
#	define prevtok        (* lex_previous( _ctx->parser.Tokens, lex_dont_skip_formatting))
#	define nexttok		  (* lex_next( _ctx->parser.Tokens, lex_skip_formatting ))
#	define nexttok_noskip (* lex_next( _ctx->parser.Tokens, lex_dont_skip_formatting))
#	define eat( Type_ )   lex__eat( & _ctx->parser.Tokens, Type_ )
#	define left           ( array_num(_ctx->parser.Tokens.Arr) - _ctx->parser.Tokens.Idx )

#if GEN_COMPILER_CPP
#	define def_assign( ... ) { __VA_ARGS__ }
#else
#	define def_assign( ... ) __VA_ARGS__
#endif


#ifdef check
#define CHECK_WAS_DEFINED
#pragma push_macro("check")
#undef check
#endif

#	define check_noskip( Type_ ) ( left && currtok_noskip.Type == Type_ )
#	define check( Type_ )        ( left && currtok.Type        == Type_ )

#	define push_scope()                                                                                                         \
	Str null_name = {};                                                                                                         \
	StackNode scope = { nullptr, lex_current( &  _ctx->parser.Tokens, lex_dont_skip_formatting ), null_name, txt( __func__ ) }; \
	parser_push( & _ctx->parser, & scope )

#pragma endregion Helper Macros

// Procedure Forwards ( Entire parser internal parser interface )

internal Code               parse_array_decl                   ();
internal CodeAttributes     parse_attributes                   ();
internal CodeComment        parse_comment                      ();
internal Code               parse_complicated_definition       ( TokType which );
internal CodeBody           parse_class_struct_body            ( TokType which, Token name );
internal Code               parse_class_struct                 ( TokType which, bool inplace_def );
internal Code               parse_expression                   ();
internal Code               parse_forward_or_definition        ( TokType which, bool is_inplace );
internal CodeFn             parse_function_after_name          ( ModuleFlag mflags, CodeAttributes attributes, CodeSpecifiers specifiers, CodeTypename ret_type, Token name );
internal Code               parse_function_body                ();
internal CodeBody           parse_global_nspace                ( CodeType which );
internal Code               parse_global_nspace_constructor_destructor( CodeSpecifiers specifiers );
internal Token              parse_identifier                   ( bool* possible_member_function );
internal CodeInclude        parse_include                      ();
internal Code               parse_macro_as_definiton           ( CodeAttributes attributes, CodeSpecifiers specifiers );
internal CodeOperator       parse_operator_after_ret_type      ( ModuleFlag mflags, CodeAttributes attributes, CodeSpecifiers specifiers, CodeTypename ret_type );
internal Code               parse_operator_function_or_variable( bool expects_function, CodeAttributes attributes, CodeSpecifiers specifiers );
internal CodePragma         parse_pragma                       ();
internal CodeParams         parse_params                       ( bool use_template_capture );
internal CodePreprocessCond parse_preprocess_cond              ();
internal Code               parse_simple_preprocess            ( TokType which  );
internal Code               parse_static_assert                ();
internal void               parse_template_args                ( Token* token );
internal CodeVar            parse_variable_after_name          ( ModuleFlag mflags, CodeAttributes attributes, CodeSpecifiers specifiers, CodeTypename type, Str name );
internal CodeVar            parse_variable_declaration_list    ();

internal CodeClass       parser_parse_class           ( bool inplace_def );
internal CodeConstructor parser_parse_constructor     ( CodeSpecifiers specifiers );
internal CodeDefine      parser_parse_define          ();
internal CodeDestructor  parser_parse_destructor      ( CodeSpecifiers specifiers );
internal CodeEnum        parser_parse_enum            ( bool inplace_def );
internal CodeBody        parser_parse_export_body     ();
internal CodeBody        parser_parse_extern_link_body();
internal CodeExtern      parser_parse_extern_link     ();
internal CodeFriend      parser_parse_friend          ();
internal CodeFn          parser_parse_function        ();
internal CodeNS          parser_parse_namespace       ();
internal CodeOpCast      parser_parse_operator_cast   ( CodeSpecifiers specifiers );
internal CodeStruct      parser_parse_struct          ( bool inplace_def );
internal CodeVar         parser_parse_variable        ();
internal CodeTemplate    parser_parse_template        ();
internal CodeTypename    parser_parse_type            ( bool from_template, bool* is_function );
internal CodeTypedef     parser_parse_typedef         ();
internal CodeUnion       parser_parse_union           ( bool inplace_def );
internal CodeUsing       parser_parse_using           ();

constexpr bool parser_inplace_def         = true;
constexpr bool parser_not_inplace_def     = false;
constexpr bool parser_dont_consume_braces = true;
constexpr bool parser_consume_braces      = false;
constexpr bool parser_not_from_template   = false;

constexpr bool parser_use_parenthesis = false;

// Internal parsing functions

constexpr bool parser_strip_formatting_dont_preserve_newlines = false;
/*
	This function was an attempt at stripping formatting from any c++ code.
	It has edge case failures that prevent it from being used in function bodies.
*/
internal
StrBuilder parser_strip_formatting( Str raw_text, bool preserve_newlines )
{
	StrBuilder content = strbuilder_make_reserve( _ctx->Allocator_Temp, raw_text.Len );

	if ( raw_text.Len == 0 )
		return content;

#define cut_length ( scanner - raw_text.Ptr - last_cut )
#define cut_ptr    ( raw_text.Ptr   + last_cut )
#define pos        ( rcast( sptr, scanner ) - rcast( sptr, raw_text.Ptr ) )
#define move_fwd() do { scanner++; tokleft--; } while(0)

	s32         tokleft  = raw_text.Len;
	sptr        last_cut = 0;
	char const* scanner  = raw_text.Ptr;

	if ( scanner[0] == ' ' ) {
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

			strbuilder_append_c_str_len( & content, cut_ptr, cut_length );
			last_cut = rcast(sptr, scanner ) - rcast( sptr, raw_text.Ptr );
			continue;
		}

		// Skip over the content of character literals
		if ( scanner[0] == '\'' )
		{
			move_fwd();

			while ( tokleft
			&& ( scanner[0] != '\''
				|| ( *(scanner -1 ) == '\\' )
			) )
			{
				move_fwd();
			}

			// Skip the closing '
			if ( tokleft )
				move_fwd();

			strbuilder_append_c_str_len( & content, cut_ptr, cut_length );
			last_cut = rcast( sptr, scanner ) - rcast( sptr, raw_text.Ptr );
			continue;
		}

		// Block comments
		if ( tokleft > 1 && scanner[0] == '/' && scanner[1] == '*' )
		{
			while ( tokleft > 1 && !(scanner[0] == '*' && scanner[1] == '/') )
				move_fwd();

			scanner += 2;
			tokleft -= 2;

			strbuilder_append_c_str_len( & content,  cut_ptr, cut_length );
			last_cut = rcast( sptr, scanner ) - rcast( sptr, raw_text.Ptr );
			continue;
		}

		// Line comments
		if ( tokleft > 1 && scanner[0] == '/' && scanner[1] == '/' )
		{
			must_keep_newline = true;

			scanner += 2;
			tokleft -= 2;

			while ( tokleft && scanner[ 0 ] != '\n' )
				move_fwd();

			if (tokleft)
				move_fwd();

			strbuilder_append_c_str_len( & content,  cut_ptr, cut_length );
			last_cut = rcast( sptr,  scanner ) - rcast( sptr, raw_text.Ptr );
			continue;
		}

		// Tabs
		if (scanner[0] == '\t')
		{
			if (pos > last_cut)
				strbuilder_append_c_str_len( & content, cut_ptr, cut_length);

			if ( * strbuilder_back( content ) != ' ' )
				strbuilder_append_char( & content, ' ' );

			move_fwd();
			last_cut = rcast( sptr, scanner) - rcast( sptr, raw_text.Ptr);
			continue;
		}

		if ( tokleft > 1 && scanner[0] == '\r' && scanner[1] == '\n' )
		{
			if ( must_keep_newline || preserve_newlines )
			{
				must_keep_newline = false;

				scanner += 2;
				tokleft -= 2;

				strbuilder_append_c_str_len( & content,  cut_ptr, cut_length );
				last_cut = rcast( sptr, scanner ) - rcast( sptr, raw_text.Ptr );
				continue;
			}

			if ( pos > last_cut )
				strbuilder_append_c_str_len( & content,  cut_ptr, cut_length );

			// Replace with a space
			if ( * strbuilder_back( content ) != ' ' )
				strbuilder_append_char( & content,  ' ' );

			scanner += 2;
			tokleft -= 2;

			last_cut = rcast( sptr, scanner ) - rcast( sptr, raw_text.Ptr );
			continue;
		}

		if ( scanner[0] == '\n' )
		{
			if ( must_keep_newline || preserve_newlines )
			{
				must_keep_newline = false;

				move_fwd();

				strbuilder_append_c_str_len( & content,  cut_ptr, cut_length );
				last_cut = rcast( sptr, scanner ) - rcast( sptr, raw_text.Ptr );
				continue;
			}

			if ( pos > last_cut )
				strbuilder_append_c_str_len( & content,  cut_ptr, cut_length );

			// Replace with a space
			if ( * strbuilder_back( content ) != ' ' )
				strbuilder_append_char( & content,  ' ' );

			move_fwd();

			last_cut = rcast( sptr, scanner ) - rcast( sptr, raw_text.Ptr );
			continue;
		}

		// Escaped newlines
		if ( scanner[0] == '\\' )
		{
			strbuilder_append_c_str_len( & content,  cut_ptr, cut_length );

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

			last_cut = rcast( sptr, scanner ) - rcast( sptr, raw_text.Ptr );
			continue;
		}

		// Consectuive spaces
		if ( tokleft > 1 && char_is_space( scanner[0] ) && char_is_space( scanner[ 1 ] ) )
		{
			strbuilder_append_c_str_len( & content,  cut_ptr, cut_length );
			do
			{
				move_fwd();
			}
			while ( tokleft && char_is_space( scanner[0] ) );

			last_cut = rcast( sptr, scanner ) - rcast( sptr, raw_text.Ptr );

			// Preserve only 1 space of formattting
			char* last = strbuilder_back(content);
			if ( last == nullptr || * last != ' ' )
				strbuilder_append_char( & content, ' ' );

			continue;
		}

		move_fwd();
	}

	if ( last_cut < raw_text.Len ) {
		strbuilder_append_c_str_len( & content,  cut_ptr, raw_text.Len - last_cut );
	}

#undef cut_ptr
#undef cut_length
#undef pos
#undef move_fwd

	return content;
}

internal
Code parse_array_decl()
{
	push_scope();

	if ( check( Tok_Operator ) && currtok.Text.Ptr[0] == '[' && currtok.Text.Ptr[1] == ']' )
	{
		Code array_expr = untyped_str( txt(" ") );
		eat( Tok_Operator );
		// []

		parser_pop(& _ctx->parser);
		return array_expr;
	}

	if ( check( Tok_BraceSquare_Open ) )
	{
		eat( Tok_BraceSquare_Open );
		// [

		if ( left == 0 )
		{
			log_failure( "Error, unexpected end of array declaration ( '[]' scope started )\n%s", parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}

		if ( currtok.Type == Tok_BraceSquare_Close )
		{
			log_failure( "Error, empty array expression in definition\n%s", parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}

		Token untyped_tok = currtok;

		while ( left && currtok.Type != Tok_BraceSquare_Close )
		{
			eat( currtok.Type );
		}

		untyped_tok.Text.Len = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)untyped_tok.Text.Ptr;

		Code array_expr = untyped_str( untyped_tok.Text );
		// [ <Content>

		if ( left == 0 )
		{
			log_failure( "Error, unexpected end of array declaration, expected ]\n%s", parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}

		if ( currtok.Type != Tok_BraceSquare_Close )
		{
			log_failure( "%s: Error, expected ] in array declaration, not %s\n%s", toktype_to_str( currtok.Type ), parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}

		eat( Tok_BraceSquare_Close );
		// [ <Content> ]

		// Its a multi-dimensional array
		if ( check( Tok_BraceSquare_Open ))
		{
			Code adjacent_arr_expr = parse_array_decl();
			// [ <Content> ][ <Content> ]...

			array_expr->Next = adjacent_arr_expr;
		}

		parser_pop(& _ctx->parser);
		return array_expr;
	}

	parser_pop(& _ctx->parser);
	return NullCode;
}

internal inline
CodeAttributes parse_attributes()
{
	push_scope();

	Token start = currtok;
	s32   len   = 0;

	// There can be more than one attribute. If there is flatten them to a single string.
	// TODO(Ed): Support chaining attributes (Use parameter linkage pattern)
	while ( left && tok_is_attribute(currtok) )
	{
		if ( check( Tok_Attribute_Open ) )
		{
			eat( Tok_Attribute_Open );
			// [[

			while ( left && currtok.Type != Tok_Attribute_Close )
			{
				eat( currtok.Type );
			}
			// [[ <Content>

			eat( Tok_Attribute_Close );
			// [[ <Content> ]]

			len = ( ( sptr )prevtok.Text.Ptr + prevtok.Text.Len ) - ( sptr )start.Text.Ptr;
		}
		else if ( check( Tok_Decl_GNU_Attribute ) )
		{
			eat( Tok_Decl_GNU_Attribute );
			eat( Tok_Paren_Open );
			eat( Tok_Paren_Open );
			// __attribute__((

			while ( left && currtok.Type != Tok_Paren_Close )
			{
				eat( currtok.Type );
			}
			// __attribute__(( <Content>

			eat( Tok_Paren_Close );
			eat( Tok_Paren_Close );
			// __attribute__(( <Content> ))

			len = ( ( sptr )prevtok.Text.Ptr + prevtok.Text.Len ) - ( sptr )start.Text.Ptr;
		}
		else if ( check( Tok_Decl_MSVC_Attribute ) )
		{
			eat( Tok_Decl_MSVC_Attribute );
			eat( Tok_Paren_Open );
			// __declspec(

			while ( left && currtok.Type != Tok_Paren_Close )
			{
				eat( currtok.Type );
			}
			// __declspec( <Content>

			eat( Tok_Paren_Close );
			// __declspec( <Content> )

			len = ( ( sptr )prevtok.Text.Ptr + prevtok.Text.Len ) - ( sptr )start.Text.Ptr;
		}
		else if ( tok_is_attribute(currtok) )
		{
			eat( currtok.Type );
			// <Attribute>

			// If its a macro based attribute, this could be a functional macro such as Unreal's UE_DEPRECATED(...)
			if ( check( Tok_Paren_Open))
			{
				eat( Tok_Paren_Open );

				s32 level = 0;
				while (left && currtok.Type != Tok_Paren_Close && level == 0)
				{
					if (currtok.Type == Tok_Paren_Open)
						++ level;
					if (currtok.Type == Tok_Paren_Close)
						--level;
					eat(currtok.Type);
				}
				eat(Tok_Paren_Close);
			}

			len = ( ( sptr )prevtok.Text.Ptr + prevtok.Text.Len ) - ( sptr )start.Text.Ptr;
			// <Attribute> ( ... )
		}
	}

	if ( len > 0 )
	{
		Str attribute_txt = { start.Text.Ptr, len };
		parser_pop(& _ctx->parser);

		StrBuilder name_stripped = parser_strip_formatting( attribute_txt, parser_strip_formatting_dont_preserve_newlines );

		Code result     = make_code();
		result->Type    = CT_PlatformAttributes;
		result->Name    = cache_str( strbuilder_to_str(name_stripped) );
		result->Content = result->Name;
		// result->Token   =

		return ( CodeAttributes )result;
	}

	parser_pop(& _ctx->parser);
	return NullCode;
}

internal
Code parse_class_struct( TokType which, bool inplace_def )
{
	if ( which != Tok_Decl_Class && which != Tok_Decl_Struct ) {
		log_failure( "Error, expected class or struct, not %s\n%s", toktype_to_str( which ), parser_to_strbuilder(_ctx->parser) );
		return InvalidCode;
	}

	Token name = NullToken;

	AccessSpec     access     = AccessSpec_Default;
	CodeTypename   parent     = { nullptr };
	CodeBody       body       = { nullptr };
	CodeAttributes attributes = { nullptr };
	ModuleFlag     mflags     = ModuleFlag_None;

	Code result = InvalidCode;

	if ( check(Tok_Module_Export) ) {
		mflags = ModuleFlag_Export;
		eat( Tok_Module_Export );
	}
	// <ModuleFlags>

	eat( which );
	// <ModuleFlags> <class/struct>

	attributes = parse_attributes();
	// <ModuleFlags> <class/struct> <Attributes>

	if ( check( Tok_Identifier ) ) {
		name = parse_identifier(nullptr);
		_ctx->parser.Scope->Name = name.Text;
	}
	// <ModuleFlags> <class/struct> <Attributes> <Name>

	CodeSpecifiers specifiers = NullCode;
	if ( check(Tok_Spec_Final)) {
		specifiers = def_specifier(Spec_Final);
	}

	local_persist
	char interface_arr_mem[ kilobytes(4) ] = {0};
	Array(CodeTypename) interfaces; {
		Arena arena = arena_init_from_memory( interface_arr_mem, kilobytes(4) );
		interfaces  = array_init_reserve(CodeTypename, arena_allocator_info(& arena), 4 );
	}

	// TODO(Ed) : Make an AST_DerivedType, we'll store any arbitary derived type into there as a linear linked list of them.
	if ( check( Tok_Assign_Classifer ) )
	{
		eat( Tok_Assign_Classifer );
		// <ModuleFlags> <class/struct> <Attributes> <Name> :

		if ( tok_is_access_specifier(currtok) ) {
			access = tok_to_access_specifier(currtok);
			// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier>
			eat( currtok.Type );
		}

		Token parent_tok = parse_identifier(nullptr);
		parent = def_type( parent_tok.Text );
		// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Parent/Interface Name>

		while ( check(Tok_Comma) )
		{
			eat( Tok_Comma );
			// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Name>,

			if ( tok_is_access_specifier(currtok) ) {
				eat(currtok.Type);
			}
			Token interface_tok = parse_identifier(nullptr);

			array_append( interfaces, def_type( interface_tok.Text ) );
			// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Name>, ...
		}
	}

	if ( check( Tok_BraceCurly_Open ) ) {
		body = parse_class_struct_body( which, name );
	}
	// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Name>, ... { <Body> }

	CodeComment inline_cmt = NullCode;
	if ( ! inplace_def )
	{
		Token stmt_end = currtok;
		eat( Tok_Statement_End );
		// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Name>, ... { <Body> };

		if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
			inline_cmt = parse_comment();
		// <ModuleFlags> <class/struct> <Attributes> <Name> : <Access Specifier> <Name>, ... { <Body> }; <InlineCmt>
	}

	if ( which == Tok_Decl_Class )
		result = cast(Code, def_class( name.Text, def_assign( body, parent, access, attributes, interfaces, scast(s32, array_num(interfaces)), mflags ) ));

	else
		result = cast(Code, def_struct( name.Text, def_assign( body, (CodeTypename)parent, access, attributes, interfaces, scast(s32, array_num(interfaces)), mflags ) ));

	if ( inline_cmt )
		result->InlineCmt = cast(Code, inline_cmt);

	array_free(interfaces);
	return result;
}

internal neverinline
CodeBody parse_class_struct_body( TokType which, Token name )
{
	push_scope();

	eat( Tok_BraceCurly_Open );
	// {

	CodeBody
	result = (CodeBody) make_code();

	if ( which == Tok_Decl_Class )
		result->Type = CT_Class_Body;

	else
		result->Type = CT_Struct_Body;

	while ( left && currtok_noskip.Type != Tok_BraceCurly_Close )
	{
		Code           member     = Code_Invalid;
		CodeAttributes attributes = { nullptr };
		CodeSpecifiers specifiers = { nullptr };

		bool expects_function = false;

		// _ctx->parser.Scope->Start = currtok_noskip;

		if ( currtok_noskip.Type == Tok_Preprocess_Hash )
			eat( Tok_Preprocess_Hash );

		switch ( currtok_noskip.Type )
		{
			case Tok_Statement_End: {
				// TODO(Ed): Convert this to a general warning procedure
				log_fmt("Dangling end statement found %SB\n", tok_to_strbuilder(currtok_noskip));
				eat( Tok_Statement_End );
				continue;
			}
			case Tok_NewLine: {
				member = fmt_newline;
				eat( Tok_NewLine );
				break;
			}
			case Tok_Comment: {
				member = cast(Code, parse_comment());
				break;
			}
			case Tok_Access_Public: {
				member = access_public;
				eat( Tok_Access_Public );
				eat( Tok_Assign_Classifer );
				// public:
				break;
			}
			case Tok_Access_Protected: {
				member = access_protected;
				eat( Tok_Access_Protected );
				eat( Tok_Assign_Classifer );
				// protected:
				break;
			}
			case Tok_Access_Private: {
				member = access_private;
				eat( Tok_Access_Private );
				eat( Tok_Assign_Classifer );
				// private:
				break;
			}
			case Tok_Decl_Class: {
				member = parse_complicated_definition( Tok_Decl_Class );
				// class
				break;
			}
			case Tok_Decl_Enum: {
				member = parse_complicated_definition( Tok_Decl_Enum );
				// enum
				break;
			}
			case Tok_Decl_Friend: {
				member = cast(Code, parser_parse_friend());
				// friend
				break;
			}
			case Tok_Decl_Operator: {
				member = cast(Code, parser_parse_operator_cast(NullCode));
				// operator <Type>()
				break;
			}
			case Tok_Decl_Struct: {
				member = parse_complicated_definition( Tok_Decl_Struct );
				// struct
				break;
			}
			case Tok_Decl_Template: {
				member = cast(Code, parser_parse_template());
				// template< ... >
				break;
			}
			case Tok_Decl_Typedef: {
				member = cast(Code, parser_parse_typedef());
				// typedef
				break;
			}
			case Tok_Decl_Union: {
				member = parse_complicated_definition( Tok_Decl_Union );
				// union
				break;
			}
			case Tok_Decl_Using: {
				member = cast(Code, parser_parse_using());
				// using
				break;
			}
			case Tok_Operator:
			{
				//if ( currtok.Text[0] != '~' )
				//{
				//	log_failure( "Operator token found in global body but not destructor unary negation\n%s", to_strbuilder(_ctx->parser) );
				//	return InvalidCode;
				//}

				member = cast(Code, parser_parse_destructor(NullCode));
				// ~<Name>()
				break;
			}
			case Tok_Preprocess_Define: {
				member = cast(Code, parser_parse_define());
				// #define
				break;
			}
			case Tok_Preprocess_Include:
			{
				member = cast(Code, parse_include());
				// #include
				break;
			}

			case Tok_Preprocess_If:
			case Tok_Preprocess_IfDef:
			case Tok_Preprocess_IfNotDef:
			case Tok_Preprocess_ElIf:
				member = cast(Code, parse_preprocess_cond());
				// #<Condition>
			break;

			case Tok_Preprocess_Else: {
				member = cast(Code, preprocess_else);
				eat( Tok_Preprocess_Else );
				// #else
				break;
			}
			case Tok_Preprocess_EndIf: {
				member = cast(Code, preprocess_endif);
				eat( Tok_Preprocess_EndIf );
				// #endif
				break;
			}

			case Tok_Preprocess_Macro_Stmt: {
				member = cast(Code, parse_simple_preprocess( Tok_Preprocess_Macro_Stmt ));
				break;
			}
			case Tok_Preprocess_Macro_Expr: {
				log_failure("Unbounded macro expression residing in class/struct body\n%S", parser_to_strbuilder(_ctx->parser));
				return InvalidCode;
			}

			// case Tok_Preprocess_Macro:
			// 	// <Macro>
			// 	macro_found = true;
			// 	goto Preprocess_Macro_Bare_In_Body;
			// break;

			case Tok_Preprocess_Pragma: {
				member = cast(Code, parse_pragma());
				// #pragma
				break;
			}

			case Tok_Preprocess_Unsupported: {
				member = cast(Code, parse_simple_preprocess( Tok_Preprocess_Unsupported ));
				// #<UNKNOWN>
				break;
			}

			case Tok_StaticAssert: {
				member = parse_static_assert();
				// static_assert
				break;
			}

			case Tok_Attribute_Open:
			case Tok_Decl_GNU_Attribute:
			case Tok_Decl_MSVC_Attribute:
		#define Entry( attribute, str ) case attribute:
			GEN_DEFINE_ATTRIBUTE_TOKENS
		#undef Entry
			{
				attributes = parse_attributes();
				// <Attributes>
			}
			//! Fallthrough intended
			GEN_PARSER_CLASS_STRUCT_BODY_ALLOWED_MEMBER_TOK_SPECIFIER_CASES:
			{
				Specifier specs_found[16] = { Spec_NumSpecifiers };
				s32        NumSpecifiers = 0;

				while ( left && tok_is_specifier(currtok) )
				{
					Specifier spec = str_to_specifier( currtok.Text );

					b32 ignore_spec = false;

					switch ( spec )
					{
						GEN_PARSER_CLASS_STRUCT_BODY_ALLOWED_MEMBER_SPECIFIER_CASES:
						break;

						case Spec_Consteval:
							expects_function = true;
						break;

						case Spec_Const :
							ignore_spec = true;
						break;

						default:
							log_failure( "Invalid specifier %S for class/struct member\n%S", spec_to_str(spec), strbuilder_to_str( parser_to_strbuilder(_ctx->parser)) );
							parser_pop(& _ctx->parser);
							return InvalidCode;
					}

					// Every specifier after would be considered part of the type type signature
					if (ignore_spec)
						break;

					specs_found[NumSpecifiers] = spec;
					NumSpecifiers++;
					eat( currtok.Type );
				}

				if ( NumSpecifiers )
				{
					specifiers = def_specifiers_arr( NumSpecifiers, specs_found );
				}
				// <Attributes> <Specifiers>

				if ( tok_is_attribute(currtok) )
				{
					// Unfortuantely Unreal has code where there is attirbutes before specifiers
					CodeAttributes more_attributes = parse_attributes();

					if ( attributes )
					{
						StrBuilder fused = strbuilder_make_reserve( _ctx->Allocator_Temp, attributes->Content.Len + more_attributes->Content.Len );
						strbuilder_append_fmt( & fused, "%SB %SB", attributes->Content, more_attributes->Content );

						Str attrib_name     = strbuilder_to_str(fused);
						attributes->Name    = cache_str( attrib_name );
						attributes->Content = attributes->Name;
						// <Attributes> <Specifiers> <Attributes>
					}

					attributes = more_attributes;
				}

				if ( currtok.Type == Tok_Operator && currtok.Text.Ptr[0] == '~' )
				{
					member = cast(Code, parser_parse_destructor( specifiers ));
					// <Attribute> <Specifiers> ~<Name>()
					break;
				}

				if ( currtok.Type == Tok_Decl_Operator )
				{
					member = cast(Code, parser_parse_operator_cast( specifiers ));
					// <Attributes> <Specifiers> operator <Type>()
					break;
				}
			}
			//! Fallthrough intentional
			case Tok_Identifier:
			case Tok_Preprocess_Macro_Typename:
			case Tok_Spec_Const:
			case Tok_Type_Unsigned:
			case Tok_Type_Signed:
			case Tok_Type_Short:
			case Tok_Type_Long:
			case Tok_Type_bool:
			case Tok_Type_char:
			case Tok_Type_int:
			case Tok_Type_double:
			{
				if ( nexttok.Type == Tok_Paren_Open && name.Text.Len && currtok.Type == Tok_Identifier )
				{
					if ( c_str_compare_len( name.Text.Ptr, currtok.Text.Ptr, name.Text.Len ) == 0 )
					{
						member = cast(Code, parser_parse_constructor( specifiers ));
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

			default:
				Token untyped_tok = currtok;
				while ( left && currtok.Type != Tok_BraceCurly_Close )
				{
					untyped_tok.Text.Len = ( (sptr)currtok.Text.Ptr + currtok.Text.Len ) - (sptr)untyped_tok.Text.Ptr;
					eat( currtok.Type );
				}
				member = untyped_str( untyped_tok.Text );
				// Something unknown
			break;
		}

		if ( member == Code_Invalid )
		{
			log_failure( "Failed to parse member\n%s", parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}
		body_append(result, member );
	}

	eat( Tok_BraceCurly_Close );
	// { <Members> }
	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeComment parse_comment()
{
	push_scope();

	CodeComment
	result          = (CodeComment) make_code();
	result->Type    = CT_Comment;
	result->Content = cache_str( currtok_noskip.Text );
	// result->Token   = currtok_noskip;
	eat( Tok_Comment );

	parser_pop(& _ctx->parser);
	return result;
}

internal
Code parse_complicated_definition( TokType which )
{
	push_scope();

	bool is_inplace = false;

	TokArray tokens = _ctx->parser.Tokens;

	s32 idx         = tokens.Idx;
	s32 level       = 0;
	for ( ; idx < array_num(tokens.Arr); idx++ )
	{
		if ( tokens.Arr[ idx ].Type == Tok_BraceCurly_Open )
			level++;

		if ( tokens.Arr[ idx ].Type == Tok_BraceCurly_Close )
			level--;

		if ( level == 0 && tokens.Arr[ idx ].Type == Tok_Statement_End )
			break;
	}

	if ( ( idx - 2 ) == tokens.Idx )
	{
		// Its a forward declaration only
		Code result = parse_forward_or_definition( which, is_inplace );
		// <class, enum, struct, or union> <Name>;
		parser_pop(& _ctx->parser);
		return result;
	}

	Token tok = tokens.Arr[ idx - 1 ];
	if ( tok_is_specifier(tok) && spec_is_trailing( str_to_specifier( tok.Text)) )
	{
		// <which> <type_identifier>(...) <specifier> ...;

		s32   spec_idx = idx - 1;
		Token spec     = tokens.Arr[spec_idx];
		while ( tok_is_specifier(spec) && spec_is_trailing( str_to_specifier( spec.Text)) )
		{
			-- spec_idx;
			spec = tokens.Arr[spec_idx];
		}

		if ( tokens.Arr[spec_idx].Type == Tok_Paren_Close )
		{
			// Forward declaration with trailing specifiers for a procedure
			tok = tokens.Arr[spec_idx];

			Code result = parse_operator_function_or_variable( false, NullCode, NullCode );
			// <Attributes> <Specifiers> <ReturnType/ValueType> <operator <Op>, or Name> ...
			parser_pop(& _ctx->parser);
			return result;
		}

		log_failure( "Unsupported or bad member definition after %s declaration\n%s", toktype_to_str(which), parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}
	if ( tok.Type == Tok_Identifier )
	{
		tok = tokens.Arr[ idx - 2 ];
		bool is_indirection = tok.Type == Tok_Ampersand || tok.Type == Tok_Star;
		bool ok_to_parse    = false;

		if ( tok.Type == Tok_BraceCurly_Close )
		{
			// Its an inplace definition
			// <which> <type_identifier ?> { ... } <identifier>;
			ok_to_parse = true;
			is_inplace  = true;

			CodeTypename type = cast(CodeTypename, parse_forward_or_definition(which, is_inplace));

			// Should be a name right after the type.
			Token name = parse_identifier(nullptr);
			_ctx->parser.Scope->Name = name.Text;

			CodeVar result = parse_variable_after_name(ModuleFlag_None, NullCode, NullCode, type, name.Text);
			parser_pop(& _ctx->parser);
			return (Code) result;
		}
		else if ( tok.Type == Tok_Identifier && tokens.Arr[ idx - 3 ].Type == which )
		{
			// Its a variable with type ID using <which> namespace.
			// <which> <type_identifier> <identifier>;
			ok_to_parse = true;
		}
		else if ( tok.Type == Tok_Assign_Classifer
		&& (	( tokens.Arr[idx - 5].Type == which && tokens.Arr[idx - 4].Type == Tok_Decl_Class )
			||	( tokens.Arr[idx - 4].Type == which))
		)
		{
			// Its a forward declaration of an enum
			// <enum>         <type_identifier> : <identifier>;
			// <enum> <class> <type_identifier> : <identifier>;
			ok_to_parse = true;
			Code result = cast(Code, parser_parse_enum( ! parser_inplace_def));
			parser_pop(& _ctx->parser);
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
			log_failure( "Unsupported or bad member definition after %s declaration\n%s", toktype_to_str(which), parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}

		Code result = parse_operator_function_or_variable( false, NullCode, NullCode );
		// <Attributes> <Specifiers> <ReturnType/ValueType> <operator <Op>, or Name> ...
		parser_pop(& _ctx->parser);
		return result;
	}
	else if ( tok.Type >= Tok_Type_Unsigned && tok.Type <= Tok_Type_MS_W64 )
	{
		tok = tokens.Arr[ idx - 2 ];

		if ( tok.Type != Tok_Assign_Classifer
		|| (	( tokens.Arr[idx - 5].Type != which && tokens.Arr[idx - 4].Type != Tok_Decl_Class )
			&&	( tokens.Arr[idx - 4].Type != which))
		)
		{
			log_failure( "Unsupported or bad member definition after %s declaration\n%s", toktype_to_str(which), parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}

		// Its a forward declaration of an enum class
		// <enum>         <type_identifier> : <identifier>;
		// <enum> <class> <type_identifier> : <identifier>;
		Code result = cast(Code, parser_parse_enum( ! parser_inplace_def));
		parser_pop(& _ctx->parser);
		return result;
	}
	else if ( tok.Type == Tok_BraceCurly_Close )
	{
		// Its a definition
		Code result = parse_forward_or_definition( which, is_inplace );
		// <which> { ... };
		parser_pop(& _ctx->parser);
		return result;
	}
	else if ( tok.Type == Tok_BraceSquare_Close )
	{
		// Its an array definition
		Code result = parse_operator_function_or_variable( false, NullCode, NullCode );
		// <which> <type_identifier> <identifier> [ ... ];
		parser_pop(& _ctx->parser);
		return result;
	}
	else
	{
		log_failure( "Unsupported or bad member definition after %s declaration\n%SB", toktype_to_str(which).Ptr, parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}
}

internal inline
Code parse_assignment_expression()
{
	Code expr = { nullptr };

	eat( Tok_Operator );
	// <Attributes> <Specifiers> <ValueType> <Name> =

	Token expr_tok = currtok;

	if ( currtok.Type == Tok_Statement_End && currtok.Type != Tok_Comma )
	{
		log_failure( "Expected expression after assignment operator\n%s", parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	s32 level = 0;
	while ( left && currtok.Type != Tok_Statement_End && (currtok.Type != Tok_Comma || level > 0) )
	{
		if (currtok.Type == Tok_BraceCurly_Open )
			level++;
		if (currtok.Type == Tok_BraceCurly_Close )
			level--;
		if (currtok.Type == Tok_Paren_Open)
			level++;
		else if (currtok.Type == Tok_Paren_Close)
			level--;

		eat( currtok.Type );
	}

	expr_tok.Text.Len = ( ( sptr )currtok.Text.Ptr + currtok.Text.Len ) - ( sptr )expr_tok.Text.Ptr - 1;
	expr              = untyped_str( expr_tok.Text );
	// = <Expression>
	return expr;
}

internal inline
Code parse_forward_or_definition( TokType which, bool is_inplace )
{
	Code result = InvalidCode;

	switch ( which )
	{
		case Tok_Decl_Class:
			result = cast(Code, parser_parse_class( is_inplace ));
			return result;

		case Tok_Decl_Enum:
			result = cast(Code, parser_parse_enum( is_inplace ));
			return result;

		case Tok_Decl_Struct:
			result = cast(Code, parser_parse_struct( is_inplace ));
			return result;

		case Tok_Decl_Union:
			result = cast(Code, parser_parse_union( is_inplace ));
			return result;

		default:
			log_failure( "Error, wrong token type given to parse_complicated_definition "
				"(only supports class, enum, struct, union) \n%s"
				, parser_to_strbuilder(_ctx->parser) );

			return InvalidCode;
	}
}

// Function parsing is handled in multiple places because its initial signature is shared with variable parsing
internal inline
CodeFn parse_function_after_name(
	  ModuleFlag     mflags
	, CodeAttributes attributes
	, CodeSpecifiers specifiers
	, CodeTypename   ret_type
	, Token          name
)
{
	push_scope();
	CodeParams params = parse_params(parser_use_parenthesis);
	// <Attributes> <Specifiers> <ReturnType> <Name> ( <Parameters> )

	Code suffix_specs = NullCode;

	// TODO(Ed), Review old comment : These have to be kept separate from the return type's specifiers.
	while ( left && tok_is_specifier(currtok) )
	{
		// For Unreal's PURE_VIRTUAL Support
		Macro* macro = lookup_macro( currtok.Text );
		if (macro && tok_is_specifier(currtok))
		{
			suffix_specs = parse_simple_preprocess(Tok_Preprocess_Macro_Expr);
			continue;
		}
		if ( specifiers == nullptr )
		{
			specifiers = def_specifier( str_to_specifier( currtok.Text) );
			eat( currtok.Type );
			continue;
		}

		specifiers_append(specifiers, str_to_specifier( currtok.Text) );
		eat( currtok.Type );
	}
	// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>

	CodeBody    body       = NullCode;
	CodeComment inline_cmt = NullCode;
	if ( check( Tok_BraceCurly_Open ) )
	{
		body = cast(CodeBody, parse_function_body());
		if ( cast(Code, body) == Code_Invalid )
		{
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}
		// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers> { <Body> }
	}
	else if ( check(Tok_Operator) && currtok.Text.Ptr[0] == '=' )
	{
		eat(Tok_Operator);
		if ( specifiers == nullptr )
		{
			specifiers       = (CodeSpecifiers) make_code();
			specifiers->Type = CT_Specifiers;
		}
		if ( str_are_equal(nexttok.Text, txt("delete")))
		{
			specifiers_append(specifiers, Spec_Delete);
			eat(currtok.Type);	
			// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers> = delete
		}
		else
		{
			specifiers_append(specifiers, Spec_Pure );

			eat( Tok_Number);
			// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers> = 0
		}
		Token stmt_end = currtok;
		eat( Tok_Statement_End );
		
		if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
			inline_cmt = parse_comment();
		// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>; <InlineCmt>
	}
	else
	{
		Token stmt_end = currtok;
		eat( Tok_Statement_End );
		// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>;

		if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
			inline_cmt = parse_comment();
			// <Attributes> <Specifiers> <ReturnType> <Name> ( <Paraemters> ) <Specifiers>; <InlineCmt>
	}

	StrBuilder
	name_stripped = strbuilder_make_str( _ctx->Allocator_Temp, name.Text );
	strbuilder_strip_space(name_stripped);

	CodeFn
	result              = (CodeFn) make_code();
	result->Name        = cache_str( strbuilder_to_str(name_stripped) );
	result->ModuleFlags = mflags;

	if ( body )
	{
		switch ( body->Type )
		{
			case CT_Function_Body:
			case CT_Untyped:
				break;

			default:
			{
				log_failure("Body must be either of Function_Body or Untyped type, %s\n%s", code_debug_str(body), parser_to_strbuilder(_ctx->parser));
				parser_pop(& _ctx->parser);
				return InvalidCode;
			}
		}

		result->Type = CT_Function;
		result->Body = body;
	}
	else
	{
		result->Type = CT_Function_Fwd;
	}

	if ( attributes )
		result->Attributes = attributes;

	if ( specifiers )
		result->Specs = specifiers;

	if ( suffix_specs )
		result->SuffixSpecs = suffix_specs;

	result->ReturnType = ret_type;

	if ( params )
		result->Params = params;

	if ( inline_cmt )
		result->InlineCmt = inline_cmt;

	parser_pop(& _ctx->parser);
	return result;
}

internal
Code parse_function_body()
{
	push_scope();

	eat( Tok_BraceCurly_Open );

	CodeBody
	result = (CodeBody) make_code();
	result->Type = CT_Function_Body;

	// TODO : Support actual parsing of function body
	Token start = currtok_noskip;

	s32 level = 0;
	while ( left && ( currtok_noskip.Type != Tok_BraceCurly_Close || level > 0 ) )
	{
		if ( currtok_noskip.Type == Tok_BraceCurly_Open )
			level++;

		else if ( currtok_noskip.Type == Tok_BraceCurly_Close && level > 0 )
			level--;

		eat( currtok_noskip.Type );
	}

	Token past = prevtok;

	s32 len = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)start.Text.Ptr;

	if ( len > 0 )
	{
		Str str = { start.Text.Ptr, len };
		body_append( result, cast(Code, def_execution( str )) );
	}

	eat( Tok_BraceCurly_Close );

	parser_pop(& _ctx->parser);
	return cast(Code, result);
}

internal neverinline
CodeBody parse_global_nspace( CodeType which )
{
	push_scope();

	if ( which != CT_Namespace_Body && which != CT_Global_Body && which != CT_Export_Body && which != CT_Extern_Linkage_Body )
		return InvalidCode;

	if ( which != CT_Global_Body )
		eat( Tok_BraceCurly_Open );
		// {

	CodeBody
	result = (CodeBody) make_code();
	result->Type = which;

	while ( left && currtok_noskip.Type != Tok_BraceCurly_Close )
	{
		Code           member     = Code_Invalid;
		CodeAttributes attributes = { nullptr };
		CodeSpecifiers specifiers = { nullptr };

		bool expects_function = false;

		// _ctx->parser.Scope->Start = currtok_noskip;

		if ( currtok_noskip.Type == Tok_Preprocess_Hash )
			eat( Tok_Preprocess_Hash );

		b32 macro_found = false;

		switch ( currtok_noskip.Type )
		{
			case Tok_Comma:
			{
				log_failure("Dangling comma found: %SB\nContext:\n%SB", tok_to_strbuilder(currtok), parser_to_strbuilder(_ctx->parser));
				parser_pop( & _ctx->parser);
				return InvalidCode;
			}
			break;
			case Tok_Statement_End:
			{
				// TODO(Ed): Convert this to a general warning procedure
				log_fmt("Dangling end statement found %SB\n", tok_to_strbuilder(currtok_noskip));
				eat( Tok_Statement_End );
				continue;
			}
			case Tok_NewLine:
				// Empty lines are auto skipped by Tokens.current()
				member = fmt_newline;
				eat( Tok_NewLine );
			break;

			case Tok_Comment:
				member = cast(Code, parse_comment());
			break;

			case Tok_Decl_Class:
				member = parse_complicated_definition( Tok_Decl_Class );
				// class
			break;

			case Tok_Decl_Enum:
				member = parse_complicated_definition( Tok_Decl_Enum );
				// enum
			break;

			case Tok_Decl_Extern_Linkage:
				if ( which == CT_Extern_Linkage_Body )
					log_failure( "Nested extern linkage\n%s", parser_to_strbuilder(_ctx->parser) );

				member = cast(Code, parser_parse_extern_link());
				// extern "..." { ... }
			break;

			case Tok_Decl_Namespace:
				member = cast(Code, parser_parse_namespace());
				// namespace <Name> { ... }
			break;

			case Tok_Decl_Struct:
				member = parse_complicated_definition( Tok_Decl_Struct );
				// struct ...
			break;

			case Tok_Decl_Template:
				member = cast(Code, parser_parse_template());
				// template<...> ...
			break;

			case Tok_Decl_Typedef:
				member = cast(Code, parser_parse_typedef());
				// typedef ...
			break;

			case Tok_Decl_Union:
				member = parse_complicated_definition( Tok_Decl_Union );
				// union ...
			break;

			case Tok_Decl_Using:
				member = cast(Code, parser_parse_using());
				// using ...
			break;

			case Tok_Preprocess_Define:
				member = cast(Code, parser_parse_define());
				// #define ...
			break;

			case Tok_Preprocess_Include:
				member = cast(Code, parse_include());
				// #include ...
			break;

			case Tok_Preprocess_If:
			case Tok_Preprocess_IfDef:
			case Tok_Preprocess_IfNotDef:
			case Tok_Preprocess_ElIf:
				member = cast(Code, parse_preprocess_cond());
				// #<Conditional> ...
			break;

			case Tok_Preprocess_Else:
				member = cast(Code, preprocess_else);
				eat( Tok_Preprocess_Else );
				// #else
			break;

			case Tok_Preprocess_EndIf:
				member = cast(Code, preprocess_endif);
				eat( Tok_Preprocess_EndIf );
				// #endif
			break;

			case Tok_Preprocess_Macro_Stmt: {
				member = cast(Code, parse_simple_preprocess( Tok_Preprocess_Macro_Stmt ));
				break;
			}
			case Tok_Preprocess_Macro_Expr: {
				log_failure("Unbounded macro expression residing in class/struct body\n%S", parser_to_strbuilder(_ctx->parser));
				return InvalidCode;
			}

			case Tok_Preprocess_Pragma: {
				member = cast(Code, parse_pragma());
				// #pragma ...
			}
			break;

			case Tok_Preprocess_Unsupported: {
				member = cast(Code, parse_simple_preprocess( Tok_Preprocess_Unsupported ));
				// #<UNSUPPORTED> ...
			}
			break;

			case Tok_StaticAssert: {
				member = cast(Code, parse_static_assert());
				// static_assert( <Conditional Expression>, ... );
			}
			break;

			case Tok_Module_Export: {
				if ( which == CT_Export_Body )
					log_failure( "Nested export declaration\n%s", parser_to_strbuilder(_ctx->parser) );

				member = cast(Code, parser_parse_export_body());
				// export { ... }
			}
			break;

			case Tok_Module_Import: {
				// import ...
				log_failure( "gen::%s: This function is not implemented" );
				return InvalidCode;
			}
			//! Fallthrough intentional
			case Tok_Attribute_Open:
			case Tok_Decl_GNU_Attribute:
			case Tok_Decl_MSVC_Attribute:
		#define Entry( attribute, str ) case attribute:
			GEN_DEFINE_ATTRIBUTE_TOKENS
		#undef Entry
			{
				attributes = parse_attributes();
				// <Attributes>
			}
			//! Fallthrough intentional
			GEN_PARSER_CLASS_GLOBAL_NSPACE_ALLOWED_MEMBER_TOK_SPECIFIER_CASES:
			{
				Specifier specs_found[16] = { Spec_NumSpecifiers };
				s32        NumSpecifiers = 0;

				while ( left && tok_is_specifier(currtok) )
				{
					Specifier spec = str_to_specifier( currtok.Text );

					bool ignore_spec = false;

					switch ( spec )
					{
						GEN_PARSER_CLASS_GLOBAL_NSPACE_ALLOWED_MEMBER_SPECIFIER_CASES:
						break;

						case Spec_Consteval:
							expects_function = true;
						break;

						case Spec_Const:
							ignore_spec = true;
						break;

						default:
							Str spec_str = spec_to_str(spec);

							log_failure( "Invalid specifier %S for variable\n%S", spec_str, strbuilder_to_str( parser_to_strbuilder(_ctx->parser)) );
							parser_pop(& _ctx->parser);
							return InvalidCode;
					}

					if (ignore_spec)
						break;

					specs_found[NumSpecifiers] = spec;
					NumSpecifiers++;
					eat( currtok.Type );
				}

				if ( NumSpecifiers )
				{
					specifiers = def_specifiers_arr( NumSpecifiers, specs_found );
				}
				// <Attributes> <Specifiers>
			}
			//! Fallthrough intentional
			case Tok_Identifier:
			case Tok_Preprocess_Macro_Typename:
			case Tok_Spec_Const:
			case Tok_Type_Long:
			case Tok_Type_Short:
			case Tok_Type_Signed:
			case Tok_Type_Unsigned:
			case Tok_Type_bool:
			case Tok_Type_char:
			case Tok_Type_double:
			case Tok_Type_int:
			{
				// This s only in a scope so that Preprocess_Macro_Bare_In_Body works without microsoft extension warnings
				{
					Code constructor_destructor = parse_global_nspace_constructor_destructor( specifiers );
					// Possible constructor implemented at global file scope.
					if ( constructor_destructor )
					{
						member = constructor_destructor;
						break;
					}

					bool found_operator_cast_outside_class_implmentation = false;
					s32  idx = _ctx->parser.Tokens.Idx;

					for ( ; idx < array_num(_ctx->parser.Tokens.Arr); idx++ )
					{
						Token tok = _ctx->parser.Tokens.Arr[ idx ];

						if ( tok.Type == Tok_Identifier )
						{
							idx++;
							tok = _ctx->parser.Tokens.Arr[ idx ];
							if ( tok.Type == Tok_Access_StaticSymbol )
								continue;

							break;
						}

						if ( tok.Type == Tok_Decl_Operator )
							found_operator_cast_outside_class_implmentation = true;

						break;
					}

					if ( found_operator_cast_outside_class_implmentation )
					{
						member = cast(Code, parser_parse_operator_cast( specifiers ));
						// <Attributes> <Specifiers> <Name>::operator <Type>() { ... }
						break;
					}
				}

				member = parse_operator_function_or_variable( expects_function, attributes, specifiers );
				// <Attributes> <Specifiers> ...
			}
		}

		if ( member == Code_Invalid )
		{
			log_failure( "Failed to parse member\nToken: %SB\nContext:\n%SB", tok_to_strbuilder(currtok_noskip), parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}

		// log_fmt("Global Body Member: %s", member->debug_str());
		body_append(result, member );
	}

	if ( which != CT_Global_Body )
		eat( Tok_BraceCurly_Close );
		// { <Body> }

	parser_pop(& _ctx->parser);
	return result;
}

internal inline
Code parse_global_nspace_constructor_destructor( CodeSpecifiers specifiers )
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
	TokArray tokens = _ctx->parser.Tokens;

	s32   idx = tokens.Idx;
	Token nav = tokens.Arr[ idx ];
	for ( ; idx < array_num(tokens.Arr); idx++, nav = tokens.Arr[ idx ] )
	{
		if ( nav.Text.Ptr[0] == '<' )
		{
			// Skip templated expressions as they mey have expressions with the () operators
			s32 capture_level  = 0;
			s32 template_level = 0;
			for ( ; idx < array_num(tokens.Arr); idx++, nav = tokens.Arr[idx] )
			{
				if (nav.Text.Ptr[ 0 ] == '<')
					++ template_level;

				if (nav.Text.Ptr[ 0 ] == '>')
					-- template_level;
				if (nav.Type == Tok_Operator && nav.Text.Ptr[1] == '>')
					-- template_level;

				if ( nav.Type == Tok_Paren_Open)
				{
					if (template_level != 0 )
						++ capture_level;
					else
						break;
				}

				if ( template_level != 0 && nav.Type == Tok_Paren_Close)
					-- capture_level;
			}
		}

		if ( nav.Type == Tok_Paren_Open )
			break;
	}

	-- idx;
	Token tok_right = tokens.Arr[idx];
	Token tok_left  = NullToken;

	if (tok_right.Type != Tok_Identifier)
	{
		// We're not dealing with a constructor if there is no identifier right before the opening of a parameter's scope.
		return result;
	}

	-- idx;
	tok_left = tokens.Arr[idx];
	// <Attributes> <Specifiers> ... <Identifier>

	bool possible_destructor = false;
	if ( tok_left.Type == Tok_Operator && tok_left.Text.Ptr[0] == '~')
	{
		possible_destructor = true;
		-- idx;
		tok_left = tokens.Arr[idx];
	}

	if ( tok_left.Type != Tok_Access_StaticSymbol )
		return result;

	-- idx;
	tok_left = tokens.Arr[idx];
	// <Attributes> <Specifiers> ... :: <Identifier>

	// We search toward the left until we find the next valid identifier
	s32 capture_level  = 0;
	s32 template_level = 0;
	while ( idx != tokens.Idx )
	{
		if (tok_left.Text.Ptr[ 0 ] == '<')
			++ template_level;

		if (tok_left.Text.Ptr[ 0 ] == '>')
			-- template_level;
		if (tok_left.Type == Tok_Operator && tok_left.Text.Ptr[1] == '>')
			-- template_level;

		if ( template_level != 0 && tok_left.Type == Tok_Paren_Open)
			++ capture_level;

		if ( template_level != 0 && tok_left.Type == Tok_Paren_Close)
			-- capture_level;

		if ( capture_level == 0 && template_level == 0  && tok_left.Type == Tok_Identifier )
			break;

		-- idx;
		tok_left = tokens.Arr[idx];
	}

	bool is_same = c_str_compare_len( tok_right.Text.Ptr, tok_left.Text.Ptr, tok_right.Text.Len ) == 0;
	if (tok_left.Type == Tok_Identifier && is_same)
	{
		// We have found the pattern we desired
		if (possible_destructor)
		{
			// <Name> :: ~<Name> (
			result = cast(Code, parser_parse_destructor( specifiers ));
		}
		else {
			// <Name> :: <Name> (
			result = cast(Code, parser_parse_constructor( specifiers ));
		}
	}

	return result;
}

// TODO(Ed): I want to eventually change the identifier to its own AST type.
// This would allow distinction of the qualifier for a symbol <qualifier>::<nested symboL>
// This would also allow
internal
Token parse_identifier( bool* possible_member_function )
{
	push_scope();

	Token name = currtok;
	_ctx->parser.Scope->Name = name.Text;
	eat( Tok_Identifier );
	// <Name>

	parse_template_args( & name );
	// <Name><Template Args>

	while ( check( Tok_Access_StaticSymbol ) )
	{
		eat( Tok_Access_StaticSymbol );
		// <Qualifier Name> <Template Args> ::

		Token invalid = NullToken;
		if ( left == 0 )
		{
			log_failure( "Error, unexpected end of static symbol identifier\n%s", parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return invalid;
		}

		if ( currtok.Type == Tok_Operator && currtok.Text.Ptr[0] == '~' )
		{
			bool is_destructor = str_are_equal( _ctx->parser.Scope->Prev->ProcName, txt("parser_parse_destructor"));
			if (is_destructor)
			{
				name.Text.Len = ( ( sptr )prevtok.Text.Ptr + prevtok.Text.Len ) - ( sptr )name.Text.Ptr;
				parser_pop(& _ctx->parser);
				return name;
			}

			log_failure( "Error, had a ~ operator after %SB but not a destructor\n%s", toktype_to_str( prevtok.Type ), parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return invalid;
		}

		if ( currtok.Type == Tok_Operator && currtok.Text.Ptr[0] == '*' && currtok.Text.Len == 1 )
		{
			if ( possible_member_function )
				*possible_member_function = true;

			else
			{
				log_failure( "Found a member function pointer identifier but the parsing context did not expect it\n%s", parser_to_strbuilder(_ctx->parser) );
				parser_pop(& _ctx->parser);
				return invalid;
			}
		}

		if ( currtok.Type != Tok_Identifier )
		{
			log_failure( "Error, expected static symbol identifier, not %s\n%s", toktype_to_str( currtok.Type ), parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return invalid;
		}

		name.Text.Len = ( (sptr)currtok.Text.Ptr + currtok.Text.Len ) - (sptr)name.Text.Ptr;
		eat( Tok_Identifier );
		// <Qualifier Name> <Template Args> :: <Name>

		parse_template_args( & name );
		// <Qualifier Name> <Template Args> :: <Name> <Template Args>
	}
	// <Qualifier Name> <Template Args> :: <Name> <Template Args> ...

	parser_pop(& _ctx->parser);
	return name;
}

internal
CodeInclude parse_include()
{
	push_scope();

	CodeInclude
	include       = (CodeInclude) make_code();
	include->Type = CT_Preprocess_Include;
	eat( Tok_Preprocess_Include );
	// #include

	if ( ! check( Tok_String ))
	{
		log_failure( "Error, expected include string after #include\n%s", parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	_ctx->parser.Scope->Name = currtok.Text;
	include->Content = cache_str( currtok.Text );
	eat( Tok_String );
	// #include <Path> or "Path"

	parser_pop(& _ctx->parser);
	return include;
}

internal
CodeOperator parse_operator_after_ret_type(
	  ModuleFlag     mflags
	, CodeAttributes attributes
	, CodeSpecifiers specifiers
	, CodeTypename   ret_type
)
{
	push_scope();

	Token nspace = NullToken;
	if ( check( Tok_Identifier ) )
	{
		nspace = currtok;
		while ( left && currtok.Type == Tok_Identifier )
		{
			eat( Tok_Identifier );

			if ( currtok.Type == Tok_Access_StaticSymbol )
				eat( Tok_Access_StaticSymbol );
		}

		nspace.Text.Len = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)nspace.Text.Ptr;
	}
	// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...>

	eat( Tok_Decl_Operator );
	// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator

	if ( ! left && currtok.Type != Tok_Operator
		&& currtok.Type != Tok_Star
		&& currtok.Type != Tok_Ampersand
		&& currtok.Type != Tok_Ampersand_DBL )
	{
		log_failure( "Expected operator after 'operator' keyword\n%s", parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	_ctx->parser.Scope->Name = currtok.Text;

	bool was_new_or_delete = false;

	Operator op = Op_Invalid;
	switch ( currtok.Text.Ptr[0] )
	{
		case '+':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_Assign_Add;

			else if ( currtok.Text.Ptr[1] == '+' )
				op = Op_Increment;

			else
				op = Op_Add;
		}
		break;
		case '-':
		{
			if ( currtok.Text.Ptr[1] == '>' )
			{
				if ( currtok.Text.Ptr[2] == '*' )
					op = Op_MemberOfPointer;

				else
					op = Op_MemberOfPointer;

				break;
			}

			else if ( currtok.Text.Ptr[1] == '=' )
				op = Op_Assign_Subtract;

			else
				op = Op_Subtract;
		}
		break;
		case '*':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_Assign_Multiply;

			else
			{
				Token finder = prevtok;
				while ( finder.Type != Tok_Decl_Operator )
				{
					if ( finder.Type == Tok_Identifier)
					{
						op = Op_Indirection;
						break;
					}
				}

				if ( op == Op_Invalid)
					op = Op_Multiply;
			}
		}
		break;
		case '/':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_Assign_Divide;

			else
				op = Op_Divide;
		}
		break;
		case '%':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_Assign_Modulo;

			else
				op = Op_Modulo;
		}
		break;
		case '&':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_Assign_BAnd;

			else if ( currtok.Text.Ptr[1] == '&' )
				op = Op_LAnd;

			else
			{


				if ( op == Op_Invalid )
				op = Op_BAnd;
			}
		}
		break;
		case '|':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_Assign_BOr;

			else if ( currtok.Text.Ptr[1] == '|' )
				op = Op_LOr;

			else
				op = Op_BOr;
		}
		break;
		case '^':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_Assign_BXOr;

			else
				op = Op_BXOr;
		}
		break;
		case '~':
		{
			op = Op_BNot;
		}
		break;
		case '!':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_LNot;

			else
				op = Op_UnaryNot;
		}
		break;
		case '=':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_LEqual;

			else
				op = Op_Assign;
		}
		break;
		case '<':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_LesserEqual;

			else if ( currtok.Text.Ptr[1] == '<' )
			{
				if ( currtok.Text.Ptr[2] == '=' )
					op = Op_Assign_LShift;

				else
					op = Op_LShift;
			}
			else
				op = Op_Lesser;
		}
		break;
		case '>':
		{
			if ( currtok.Text.Ptr[1] == '=' )
				op = Op_GreaterEqual;

			else if ( currtok.Text.Ptr[1] == '>' )
			{
				if ( currtok.Text.Ptr[2] == '=' )
					op = Op_Assign_RShift;

				else
					op = Op_RShift;
			}
			else
				op = Op_Greater;
		}
		break;
		case '(':
		{
			if ( currtok.Text.Ptr[1] == ')' )
				op = Op_FunctionCall;

			else
				op = Op_Invalid;
		}
		break;
		case '[':
		{
			if ( currtok.Text.Ptr[1] == ']' )
				op = Op_Subscript;

			else
				op = Op_Invalid;
		}
		break;
		default:
		{
			Str c_str_new    = operator_to_str(Op_New);
			Str c_str_delete = operator_to_str(Op_Delete);
			if ( c_str_compare_len( currtok.Text.Ptr, c_str_new.Ptr, max(c_str_new.Len - 1, currtok.Text.Len)) == 0)
			{
				op = Op_New;
				eat( Tok_Identifier );
				was_new_or_delete = true;

				s32 idx = _ctx->parser.Tokens.Idx + 1;
				{
					while ( _ctx->parser.Tokens.Arr[ idx ].Type == Tok_NewLine )
						idx++;
				}
				Token next = _ctx->parser.Tokens.Arr[idx];
				if ( currtok.Type == Tok_Operator && c_str_compare_len(currtok.Text.Ptr, "[]", 2) == 0)
				{
					eat(Tok_Operator);
					op = Op_NewArray;
				}
				else if ( currtok.Type == Tok_BraceSquare_Open && next.Type == Tok_BraceSquare_Close)
				{
					eat(Tok_BraceSquare_Open);
					eat(Tok_BraceSquare_Close);
					op = Op_NewArray;
				}
			}
			else if ( c_str_compare_len( currtok.Text.Ptr, c_str_delete.Ptr, max(c_str_delete.Len - 1, currtok.Text.Len )) == 0)
			{
				op = Op_Delete;
				eat(Tok_Identifier);
				was_new_or_delete = true;

				s32 idx = _ctx->parser.Tokens.Idx + 1;
				{
					while ( _ctx->parser.Tokens.Arr[ idx ].Type == Tok_NewLine )
						idx++;
				}
				Token next = _ctx->parser.Tokens.Arr[idx];
				if ( currtok.Type == Tok_Operator && c_str_compare_len(currtok.Text.Ptr, "[]", 2) == 0)
				{
					eat(Tok_Operator);
					op = Op_DeleteArray;
				}
				else if ( currtok.Type == Tok_BraceSquare_Open && next.Type == Tok_BraceSquare_Close)
				{
					eat(Tok_BraceSquare_Open);
					eat(Tok_BraceSquare_Close);
					op = Op_DeleteArray;
				}
			}
			else
			{
				if ( op == Op_Invalid )
				{
					log_failure( "Invalid operator '%s'\n%s", prevtok.Text, parser_to_strbuilder(_ctx->parser) );
					parser_pop(& _ctx->parser);
					return InvalidCode;
				}
			}
		}
	}

	if ( op == Op_Invalid )
	{
		log_failure( "Invalid operator '%s'\n%s", currtok.Text, parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	if ( ! was_new_or_delete)
		eat( currtok.Type );
	// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op>

	// Parse Params
	CodeParams params = parse_params(parser_use_parenthesis);
	// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> )

	if ( params == nullptr && op == Op_Multiply )
		op = Op_MemberOfPointer;

	while ( left && tok_is_specifier(currtok) )
	{
		if ( specifiers == nullptr )
		{
			specifiers = def_specifier( str_to_specifier( currtok.Text) );
			eat( currtok.Type );
			continue;
		}

		specifiers_append(specifiers, str_to_specifier( currtok.Text) );
		eat( currtok.Type );
	}
	// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers>
	
	// TODO(Ed): Add proper "delete" and "new" awareness
	// We're dealing with either a "= delete" or operator deletion
	if (check(Tok_Operator) && currtok.Text.Ptr[0] == '=')
	{
		eat(currtok.Type);
		if ( ! str_are_equal(currtok.Text, txt("delete")))
		{
			log_failure("Expected delete after = in operator forward instead found \"%S\"\n%SB", currtok.Text, parser_to_strbuilder(_ctx->parser));
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}
		if (specifiers == nullptr)
			specifiers = def_specifier( Spec_Delete );
		else 
			specifiers_append(specifiers, Spec_Delete);
		eat(currtok.Type);
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers> = delete
	}

	// Parse Body
	CodeBody    body       = { nullptr };
	CodeComment inline_cmt = NullCode;
	if ( check( Tok_BraceCurly_Open ) )
	{
		body = cast(CodeBody, parse_function_body());
		if ( cast(Code, body) == Code_Invalid )
		{
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers> { ... }
	}
	else
	{
		Token stmt_end = currtok;
		eat( Tok_Statement_End );
		// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers>;

		if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
			inline_cmt = parse_comment();
			// <ExportFlag> <Attributes> <Specifiers> <ReturnType> <Qualifier::...> operator <Op> ( <Parameters> ) <Specifiers>; <InlineCmt>
	}

	// OpValidateResult check_result = operator__validate( op, params, ret_type, specifiers );
	CodeOperator result = def_operator( op, nspace.Text, def_assign( params, ret_type, body, specifiers, attributes, mflags ) );

	if ( inline_cmt )
		result->InlineCmt = inline_cmt;

	parser_pop(& _ctx->parser);
	return result;
}

internal
Code parse_operator_function_or_variable( bool expects_function, CodeAttributes attributes, CodeSpecifiers specifiers )
{
	push_scope();

	Code result = InvalidCode;

	Code macro_stmt = parse_macro_as_definiton(attributes, specifiers);
	if (macro_stmt) {
		parser_pop(& _ctx->parser);
		return macro_stmt;
	}

	CodeTypename type = parser_parse_type( parser_not_from_template, nullptr );
	// <Attributes> <Specifiers> <ReturnType/ValueType>

	if ( type == InvalidCode ) {
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	bool found_operator = false;
	s32  idx            = _ctx->parser.Tokens.Idx;

	for ( ; idx < array_num(_ctx->parser.Tokens.Arr); idx++ )
	{
		Token tok = _ctx->parser.Tokens.Arr[ idx ];

		if ( tok.Type == Tok_Identifier )
		{
			idx++;
			tok = _ctx->parser.Tokens.Arr[ idx ];
			if ( tok.Type == Tok_Access_StaticSymbol )
				continue;

			break;
		}

		if ( tok.Type == Tok_Decl_Operator )
			found_operator = true;

		break;
	}

	if ( found_operator )
	{
		// Dealing with an operator overload
		result = cast(Code, parse_operator_after_ret_type( ModuleFlag_None, attributes, specifiers, type ));
		// <Attributes> <Specifiers> <ReturnType> operator ...
	}
	else
	{
		Token name = parse_identifier(nullptr);
		_ctx->parser.Scope->Name = name.Text;

		bool detected_capture = check( Tok_Paren_Open );

		// Check three tokens ahead to make sure that were not dealing with a constructor initialization...
		//                  (         350.0f    ,         <---  Could be the scenario
		// Example : <Capture_Start> <Value> <Comma>
		//                 idx         +1      +2
		bool detected_comma = _ctx->parser.Tokens.Arr[ _ctx->parser.Tokens.Idx + 2 ].Type == Tok_Comma;

		b32   detected_non_varadic_unpaired_param = detected_comma && nexttok.Type != Tok_Varadic_Argument;
		if (! detected_non_varadic_unpaired_param && nexttok.Type ==  Tok_Preprocess_Macro_Expr) for( s32 break_scope = 0; break_scope == 0; ++ break_scope)
		{
			Macro* macro = lookup_macro( nexttok.Text );
			if (macro == nullptr || ! macro_is_functional(* macro))
				break;

			// (   <Macro_Expr> (  
			// Idx      +1     +2
			s32  idx    = _ctx->parser.Tokens.Idx + 1;  
			s32  level = 0;

			// Find end of the token expression
			for ( ; idx < array_num(_ctx->parser.Tokens.Arr); idx++ )
			{
				Token tok = _ctx->parser.Tokens.Arr[ idx ];

				if ( tok.Type == Tok_Paren_Open )
					level++;
				else if ( tok.Type == Tok_Paren_Close && level > 0 )
					level--;
				if (level == 0 && tok.Type == Tok_Paren_Close)
					break;
			}
			++ idx; // Will incremnt to possible comma position

			if ( _ctx->parser.Tokens.Arr[ idx ].Type != Tok_Comma )
				break;

			detected_non_varadic_unpaired_param = true;
		}

		if ( detected_capture && ! detected_non_varadic_unpaired_param ) 
		{
			// Dealing with a function
			result = cast(Code, parse_function_after_name( ModuleFlag_None, attributes, specifiers, type, name ));
			// <Attributes> <Specifiers> <ReturnType> <Name> ( ...
		}
		else
		{
			if ( expects_function ) {
				log_failure( "Expected function declaration (consteval was used)\n%s", parser_to_strbuilder(_ctx->parser) );
				parser_pop(& _ctx->parser);
				return InvalidCode;
			}
			// Dealing with a variable
			result = cast(Code, parse_variable_after_name( ModuleFlag_None, attributes, specifiers, type, name.Text ));
			// <Attributes> <Specifiers> <ValueType> <Name> ...
		}
	}

	parser_pop(& _ctx->parser);	
	return result;
}

internal
Code parse_macro_as_definiton( CodeAttributes attributes, CodeSpecifiers specifiers )
{
	push_scope();

	if (currtok.Type != Tok_Preprocess_Macro_Stmt ) {
		parser_pop(& _ctx->parser);
		return NullCode;
	}
	Macro* macro                     = lookup_macro(currtok.Text);
	b32    can_resolve_to_definition = macro && bitfield_is_set(MacroFlags, macro->Flags, MF_Allow_As_Definition);
	if ( ! can_resolve_to_definition) {
		parser_pop(& _ctx->parser);
		return NullCode;
	}

	// TODO(Ed): When AST_Macro is made, have it support attributs and specifiers for when its behaving as a declaration/definition.
	Code code = parse_simple_preprocess( Tok_Preprocess_Macro_Stmt );

	// Attributes and sepcifiers will be collapsed into the macro's serialization.
	StrBuilder resolved_definition = strbuilder_fmt_buf(_ctx->Allocator_Temp, "%S %S %S"
		, attributes ? strbuilder_to_str( attributes_to_strbuilder(attributes)) : txt("")
		, specifiers ? strbuilder_to_str( specifiers_to_strbuilder(specifiers)) : txt("")
		, code->Content
	);
	Code result = untyped_str( strbuilder_to_str(resolved_definition) );
	parser_pop(& _ctx->parser);
	return result;
}

internal
CodePragma parse_pragma()
{
	push_scope();

	CodePragma
	pragma       = (CodePragma) make_code();
	pragma->Type = CT_Preprocess_Pragma;
	eat( Tok_Preprocess_Pragma );
	// #pragma

	if ( ! check( Tok_Preprocess_Content )) {
		log_failure( "Error, expected content after #pragma\n%s", parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	_ctx->parser.Scope->Name = currtok.Text;

	pragma->Content = cache_str( currtok.Text );
	eat( Tok_Preprocess_Content );
	// #pragma <Content>

	parser_pop(& _ctx->parser);
	return pragma;
}

internal inline
CodeParams parse_params( bool use_template_capture )
{
	push_scope();

	if ( ! use_template_capture ) {
		eat( Tok_Paren_Open );
		// (
	}
	else {
		if ( check( Tok_Operator ) && currtok.Text.Ptr[ 0 ] == '<' )
			eat( Tok_Operator );
			// <
	}

	if ( ! use_template_capture && check( Tok_Paren_Close ) )
	{
		eat( Tok_Paren_Close );
		// )
		parser_pop(& _ctx->parser);
		return NullCode;
	}
	else if ( check( Tok_Operator ) && currtok.Text.Ptr[ 0 ] == '>' ) 
	{
		eat( Tok_Operator );
		// >
		parser_pop(& _ctx->parser);
		return NullCode;
	}

	Code         macro           = { nullptr };
	CodeTypename type            = { nullptr };
	Code         value           = { nullptr };
	Token        name            = NullToken;
	Code         post_name_macro = { nullptr };

	if ( check( Tok_Varadic_Argument ) )
	{
		eat( Tok_Varadic_Argument );
		// ( or <  ...

		parser_pop(& _ctx->parser);
		return param_varadic;
		// ( ... )
		// or < ... >
	}

	#define CheckEndParams() \
		(use_template_capture ? (currtok.Text.Ptr[ 0 ] != '>') : (currtok.Type != Tok_Paren_Close))

	// TODO(Ed): Use expression macros or this? macro as attribute?
	// Ex: Unreal has this type of macro:                 vvvvvvvvv
	// COREUOBJECT_API void CallFunction( FFrame& Stack, RESULT_DECL, UFunction* Function );
	// and:                 vvvv
	// AddComponentByClass(UPARAM(meta = (AllowAbstract = "false")) TSubclassOf<UActorComponent> Class, bool bManualAttachment, ...
	if ( check(Tok_Preprocess_Macro_Expr))
	{
		macro = parse_simple_preprocess(Tok_Preprocess_Macro_Expr);
		// ( <Macro>
	}
	if ( currtok.Type != Tok_Comma )
	{
		type = parser_parse_type( use_template_capture, nullptr );
		if ( cast(Code, type) == Code_Invalid )
		{
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}
		// ( <Macro> <ValueType>

		if ( check( Tok_Identifier ) )
		{
			name = currtok;
			eat( Tok_Identifier );
			// ( <Macro> <ValueType> <Name>
		}

		// TODO(Ed): Use expression macro for this?
		// Unreal has yet another type of macro:
		// template<class T UE_REQUIRES(TPointerIsConvertibleFromTo<T, UInterface>::Value)>
		// class T ... and then ^this^ UE_REQUIRES shows up
		// So we need to consume that.
		if ( check( Tok_Preprocess_Macro_Expr ))
		{
			post_name_macro = parse_simple_preprocess( Tok_Preprocess_Macro_Expr );
			// ( <Macro> <ValueType> <Name> <PostNameMacro>
		}

		// In template captures you can have a typename have direct assignment without a name
		// typename = typename ...
		// Which would result in a static value type from a struct expansion (traditionally)
		if ( ( name.Text.Ptr || use_template_capture ) && bitfield_is_set( u32, currtok.Flags, TF_Assign ) )
		{
			eat( Tok_Operator );
			// ( <Macro> <ValueType> <Name>  =

			Token value_tok = currtok;

			if ( currtok.Type == Tok_Comma ) {
				log_failure( "Expected value after assignment operator\n%s.", parser_to_strbuilder(_ctx->parser) );
				parser_pop(& _ctx->parser);
				return InvalidCode;
			}

			s32 capture_level  = 0;
			s32 template_level = 0;
			while ( (left && ( currtok.Type != Tok_Comma ) && template_level >= 0 && CheckEndParams()) || (capture_level > 0 || template_level > 0) )
			{
				if (currtok.Text.Ptr[ 0 ] == '<')
					++ template_level;

				if (currtok.Text.Ptr[ 0 ] == '>')
					-- template_level;
				if (currtok.Type == Tok_Operator && currtok.Text.Ptr[1] == '>')
					-- template_level;

				if ( currtok.Type == Tok_Paren_Open)
					++ capture_level;

				if ( currtok.Type == Tok_Paren_Close)
					-- capture_level;

				value_tok.Text.Len = ( ( sptr )currtok.Text.Ptr + currtok.Text.Len ) - ( sptr )value_tok.Text.Ptr;
				eat( currtok.Type );
			}

			value = untyped_str( strbuilder_to_str(parser_strip_formatting( value_tok.Text, parser_strip_formatting_dont_preserve_newlines )) );
			// ( <Macro> <ValueType> <Name> = <Expression>
		}
	}

	CodeParams result = ( CodeParams )make_code();
	result->Type     = CT_Parameters;

	result->Macro = macro;

	if ( name.Text.Len > 0 )
		result->Name = cache_str( name.Text );

	result->ValueType = type;

	if ( value )
		result->Value = value;

	result->NumEntries++;

	while ( check(Tok_Comma) )
	{
		eat( Tok_Comma );
		// ( <Macro> <ValueType> <Name> = <Expression>,

		Code type  = { nullptr };
		Code value = { nullptr };

		if ( check( Tok_Varadic_Argument ) )
		{
			eat( Tok_Varadic_Argument );
			params_append(result, param_varadic );
			continue;
			// ( <Macro> <ValueType> <Name> = <Expression>, ...
		}

		// Ex: Unreal has this type of macro:                 vvvvvvvvv
		// COREUOBJECT_API void CallFunction( FFrame& Stack, RESULT_DECL, UFunction* Function );
		// and:                 vvvv
		// AddComponentByClass(UPARAM(meta = (AllowAbstract = "false")) TSubclassOf<UActorComponent> Class, bool bManualAttachment, ...
		if ( check(Tok_Preprocess_Macro_Expr))
		{
			macro = parse_simple_preprocess(Tok_Preprocess_Macro_Expr);
			// ( <Macro> <ValueType> <Name> = <Expression>, <Macro>
		}
		if ( currtok.Type != Tok_Comma )
		{
			type = cast(Code, parser_parse_type( use_template_capture, nullptr ));
			if ( type == Code_Invalid )
			{
				parser_pop(& _ctx->parser);
				return InvalidCode;
			}
			// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType>

			name = NullToken;

			if ( check( Tok_Identifier ) )
			{
				name = currtok;
				eat( Tok_Identifier );
				// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <Name>
			}

			// Unreal has yet another type of macro:
			// template<class T UE_REQUIRES(TPointerIsConvertibleFromTo<T, UInterface>::Value)>
			// class T ... and then ^this^ UE_REQUIRES shows up
			// So we need to consume that.
			if ( check( Tok_Preprocess_Macro_Expr )) {
				post_name_macro = parse_simple_preprocess( Tok_Preprocess_Macro_Expr );
				// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <PostNameMacro>
			}

			// In template captures you can have a typename have direct assignment without a name
			// typename = typename ...
			// Which would result in a static value type from a struct expansion (traditionally)
			if ( ( name.Text.Ptr || use_template_capture ) && bitfield_is_set( u32, currtok.Flags, TF_Assign ) )
			{
				eat( Tok_Operator );
				// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <Name> <PostNameMacro> =

				Token value_tok = currtok;

				if ( currtok.Type == Tok_Comma ) {
					log_failure( "Expected value after assignment operator\n%s", parser_to_strbuilder(_ctx->parser) );
					parser_pop(& _ctx->parser);
					return InvalidCode;
				}

				s32 capture_level  = 0;
				s32 template_level = 0;
				while ( (left
				&& currtok.Type != Tok_Comma
				&& template_level >= 0
				&& CheckEndParams()) || (capture_level > 0 || template_level > 0) )
				{
					if (currtok.Text.Ptr[ 0 ] == '<')
						++ template_level;

					if (currtok.Text.Ptr[ 0 ] == '>')
						-- template_level;
					if (currtok.Type == Tok_Operator && currtok.Text.Ptr[1] == '>')
						-- template_level;

					if ( currtok.Type == Tok_Paren_Open)
						++ capture_level;

					if ( currtok.Type == Tok_Paren_Close)
						-- capture_level;

					value_tok.Text.Len = ( ( sptr )currtok.Text.Ptr + currtok.Text.Len ) - ( sptr )value_tok.Text.Ptr;
					eat( currtok.Type );
				}

				value = untyped_str( strbuilder_to_str(parser_strip_formatting( value_tok.Text, parser_strip_formatting_dont_preserve_newlines )) );
				// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <Name> <PostNameMacro> = <Expression>
			}
			// ( <Macro> <ValueType> <Name> = <Expression>, <Macro> <ValueType> <Name> <PostNameMacro> = <Expression>, ..
		}

		CodeParams param = ( CodeParams )make_code();
		param->Type     = CT_Parameters;

		param->Macro = macro;

		if ( name.Text.Len > 0 )
			param->Name = cache_str( name.Text );

		param->PostNameMacro = post_name_macro;
		param->ValueType     = cast(CodeTypename, type);

		if ( value )
			param->Value = value;

		params_append(result, param );
	}

	if ( ! use_template_capture )
	{
		eat( Tok_Paren_Close );
		// ( <Macro> <ValueType> <Name> <PostNameMacro> = <Expression>, <Macro> <ValueType> <Name> <PostNameMacro> = <Expression>, .. )
	}
	else
	{
		if ( ! check( Tok_Operator ) || currtok.Text.Ptr[ 0 ] != '>' ) {
			log_failure( "Expected '<' after 'template' keyword\n%s", parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}
		eat( Tok_Operator );
		// < <Macro> <ValueType> <Name> <PostNameMacro> = <Expression>, <Macro> <ValueType> <Name> <PostNameMacro> = <Expression>, .. >
	}
	parser_pop(& _ctx->parser);
	return result;
#undef context
}

internal
CodePreprocessCond parse_preprocess_cond()
{
	push_scope();

	if ( ! tok_is_preprocess_cond(currtok) )
	{
		log_failure( "Error, expected preprocess conditional\n%s", parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	CodePreprocessCond
	cond       = (CodePreprocessCond) make_code();
	cond->Type = scast(CodeType, currtok.Type - ( Tok_Preprocess_If - CT_Preprocess_If ) );
	eat( currtok.Type );
	// #<Conditional>

	if ( ! check( Tok_Preprocess_Content ))
	{
		log_failure( "Error, expected content after #define\n%s", parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	_ctx->parser.Scope->Name = currtok.Text;
	cond->Content = cache_str( currtok.Text );
	eat( Tok_Preprocess_Content );
	// #<Conditiona> <Content>

	parser_pop(& _ctx->parser);
	return cond;
}

internal
Code parse_simple_preprocess( TokType which )
{
	// TODO(Ed): We can handle a macro a bit better than this. It's AST can be made more robust..
	// Make an AST_Macro, it should have an Name be the macro itself, with the function body being an optional function body node.
	// If we want it to terminate or have an inline comment we can possbily use its parent typedef for that info...
	push_scope();

	Token full_macro = currtok;
	eat( which );
	// <Macro>

	Macro* macro = lookup_macro( full_macro.Text );
	if ( which != Tok_Preprocess_Unsupported && macro == nullptr ) {
		log_failure("Expected the macro %S to be registered\n%S", full_macro,  parser_to_strbuilder(_ctx->parser));
		return NullCode;
	}

	// TODO(Ed) : Parse this properly later (expression and statement support)
	if ( macro && macro_is_functional(* macro) )
	{
		eat( Tok_Paren_Open );

		s32 level = 0;
		while ( left && ( currtok.Type != Tok_Paren_Close || level > 0 ) )
		{
			if ( currtok.Type == Tok_Paren_Open )
				level++;

			else if ( currtok.Type == Tok_Paren_Close && level > 0 )
				level--;

			eat( currtok.Type );
		}
		eat( Tok_Paren_Close );
		// <Macro> ( <params> )

		full_macro.Text.Len = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)full_macro.Text.Ptr;
	}

	if ( macro && macro_expects_body(* macro) && peektok.Type == Tok_BraceCurly_Open )
	{
		// Eat the block scope right after the macro. Were assuming the macro defines a function definition's signature
		eat( Tok_BraceCurly_Open );
		// <Macro> {

		// TODO(Ed) : Parse this properly later (expression and statement support)
		s32 level = 0;
		while ( left && ( currtok.Type != Tok_BraceCurly_Close || level > 0 ) )
		{
			if ( currtok.Type == Tok_BraceCurly_Open )
				level++;

			else if ( currtok.Type == Tok_BraceCurly_Close && level > 0 )
				level--;

			eat( currtok.Type );
		}
		eat( Tok_BraceCurly_Close );
		// <Macro> { <Body> }

		// TODO(Ed): Review this?
		Str prev_proc = _ctx->parser.Scope->Prev->ProcName;
		if ( macro->Type == MT_Typename && c_str_compare_len( prev_proc.Ptr, "parser_parse_typedef", prev_proc.Len ) != 0 )
		{
			if ( check( Tok_Statement_End ))
			{
				Token stmt_end = currtok;
				eat( Tok_Statement_End );
				// <Macro> { <Content> };

				if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
					eat( Tok_Comment );
					// <Macro> { <Content> }; <InlineCmt>
			}
		}

		full_macro.Text.Len = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)full_macro.Text.Ptr;
	}
	else
	{
		// If the macro is just a macro in the body of an AST it may have a semi-colon for the user to close on purpsoe
		// (especially for functional macros)
		Str calling_proc = _ctx->parser.Scope->Prev->ProcName;

		if (str_contains(_ctx->parser.Scope->Prev->ProcName, txt("parser_parse_enum")))
		{
			// Do nothing
			goto Leave_Scope_Early;
		}
		else if (macro && macro->Type == MT_Typename && str_contains(_ctx->parser.Scope->Prev->ProcName, txt("parser_parse_typedef")))
		{
			if ( peektok.Type == Tok_Statement_End )
			{
				Token stmt_end = currtok;
				eat( Tok_Statement_End );
				// <Macro>;

				full_macro.Text.Len += prevtok.Text.Len;

				// TODO(Ed): Reveiw the context for this? (ESPECIALLY THIS)
				if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
				{
					eat( Tok_Comment );
					// <Macro>; <InlineCmt>

					full_macro.Text.Len += prevtok.Text.Len;
				}
			}
		}
		else if (
				str_contains(calling_proc, txt("parse_global_nspace"))
			||	str_contains(calling_proc, txt("parse_class_struct_body"))
		)
		{
			if (left && peektok.Type == Tok_Statement_End)
			{
				Token stmt_end = currtok;
				eat( Tok_Statement_End );
				// <Macro>;
				full_macro.Text.Len += prevtok.Text.Len;
			}
		}
	}

Leave_Scope_Early:
	Code result = untyped_str( full_macro.Text );
	_ctx->parser.Scope->Name = full_macro.Text;

	parser_pop(& _ctx->parser);
	return result;
}

internal
Code parse_static_assert()
{
	push_scope();

	Code
	assert       = make_code();
	assert->Type = CT_Untyped;

	Token content = currtok;

	_ctx->parser.Scope->Name = content.Text;

	eat( Tok_StaticAssert );
	eat( Tok_Paren_Open );
	// static_assert(

	// TODO(Ed) : Parse this properly.
	s32 level = 0;
	while ( left && ( currtok.Type != Tok_Paren_Close || level > 0 ) )
	{
		if ( currtok.Type == Tok_Paren_Open )
			level++;
		else if ( currtok.Type == Tok_Paren_Close )
			level--;

		eat( currtok.Type );
	}
	eat( Tok_Paren_Close );
	eat( Tok_Statement_End );
	// static_assert( <Content> );

	content.Text.Len  = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)content.Text.Ptr;

	char const* str  = c_str_fmt_buf( "%.*s\n", content.Text.Len, content.Text.Ptr );
	Str content_str = { str, content.Text.Len + 1 };
	assert->Content = cache_str( content_str );
	assert->Name	= assert->Content;

	parser_pop(& _ctx->parser);
	return assert;
}

/*
	This a brute-froce make all the arguments part of the token provided.
	Can have in-place function signatures, regular identifiers, in-place typenames, compile-time expressions, parameter-pack expansion, etc.
	This means that validation can only go so far, and so if there is any different in formatting
	passed the basic stripping supported it report a soft failure.
*/
internal inline
void parse_template_args( Token* token )
{
	if ( currtok.Type == Tok_Operator && currtok.Text.Ptr[ 0 ] == '<' && currtok.Text.Len == 1 )
	{
		eat( Tok_Operator );
		// <

		s32 level = 0;
		while ( left && level >= 0 && ( currtok.Text.Ptr[ 0 ] != '>' || level > 0 ) )
		{
			if ( currtok.Text.Ptr[ 0 ] == '<' )
				level++;

			if ( currtok.Text.Ptr[ 0 ] == '>' )
				level--;
			if ( currtok.Type == Tok_Operator && currtok.Text.Ptr[1] == '>')
				level--;

			eat( currtok.Type );
		}
		// < <Content>

		// Due to the >> token, this could have been eaten early...
		if (level == 0)
			eat( Tok_Operator );
		// < <Content> >

		// Extend length of name to last token
		token->Text.Len = ( ( sptr )prevtok.Text.Ptr + prevtok.Text.Len ) - ( sptr )token->Text.Ptr;
	}
}

// Variable parsing is handled in multiple places because its initial signature is shared with function parsing
internal
CodeVar parse_variable_after_name(
	  ModuleFlag        mflags
	, CodeAttributes    attributes
	, CodeSpecifiers    specifiers
	, CodeTypename      type
	, Str               name
)
{
	push_scope();

	Code array_expr    = parse_array_decl();
	Code expr          = NullCode;
	Code bitfield_expr = NullCode;

	b32 using_constructor_initializer = false;

	if ( bitfield_is_set( u32, currtok.Flags, TF_Assign ) ) {
		// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>
		expr = parse_assignment_expression();
	}

	if ( currtok.Type == Tok_BraceCurly_Open )
	{
		Token expr_tok = currtok;

		eat( Tok_BraceCurly_Open );
		// <Attributes> <Specifiers> <ValueType> <Name> {

		s32 level = 0;
		while ( left && ( currtok.Type != Tok_BraceCurly_Close || level > 0 ) )
		{
			if ( currtok.Type == Tok_BraceCurly_Open )
				level++;

			else if ( currtok.Type == Tok_BraceCurly_Close && level > 0 )
				level--;

			eat( currtok.Type );
		}
		eat( Tok_BraceCurly_Close );

		expr_tok.Text.Len = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)expr_tok.Text.Ptr;
		expr              = untyped_str( expr_tok.Text );
		// <Attributes> <Specifiers> <ValueType> <Name> = { <Expression> }
	}

	if ( currtok.Type == Tok_Paren_Open )
	{
		eat( Tok_Paren_Open);
		// <Attributes> <Specifiers> <ValueType> <Name> (

		Token expr_token = currtok;

		using_constructor_initializer = true;

		s32 level = 0;
		while ( left && ( currtok.Type != Tok_Paren_Close || level > 0 ) )
		{
			if ( currtok.Type == Tok_Paren_Open )
				level++;

			else if ( currtok.Type == Tok_Paren_Close && level > 0 )
				level--;

			eat( currtok.Type );
		}

		expr_token.Text.Len = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)expr_token.Text.Ptr;
		expr                = untyped_str( expr_token.Text );
		eat( Tok_Paren_Close );
		// <Attributes> <Specifiers> <ValueType> <Name> ( <Expression> )
	}

	if ( currtok.Type == Tok_Assign_Classifer )
	{
		eat( Tok_Assign_Classifer );
		// <Attributes> <Specifiers> <ValueType> <Name> :

		Token expr_tok = currtok;

		if ( currtok.Type == Tok_Statement_End ) {
			log_failure( "Expected expression after bitfield \n%SB", parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}

		while ( left && currtok.Type != Tok_Statement_End ) {
			eat( currtok.Type );
		}

		expr_tok.Text.Len = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)expr_tok.Text.Ptr;
		bitfield_expr     = untyped_str( expr_tok.Text );
		// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>
	}

	CodeVar     next_var   = NullCode;
	Token       stmt_end   = NullToken;
	CodeComment inline_cmt = NullCode;
	if ( type )
	{
		if ( currtok.Type == Tok_Comma ) {
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
		eat( Tok_Statement_End );
		// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>, ...;
		// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>, ...;
		// <Attributes> <Specifiers> <ValueType> <Name> { <Expression> }, ...;

		// Check for inline comment : <type> <identifier> = <expression>; // <inline comment>
		if ( left && ( currtok_noskip.Type == Tok_Comment ) && currtok_noskip.Line == stmt_end.Line ) {
			inline_cmt = parse_comment();
			// <Attributes> <Specifiers> <ValueType> <Name> : <Expression>, ...; <InlineCmt>
			// <Attributes> <Specifiers> <ValueType> <Name> = <Expression>, ...; <InlineCmt>
			// <Attributes> <Specifiers> <ValueType> <Name> { <Expression> }, ...; <InlineCmt>
		}
	}

	CodeVar
	result              = (CodeVar) make_code();
	result->Type        = CT_Variable;
	result->Name        = cache_str( name );
	result->ModuleFlags = mflags;
	result->ValueType    = type;
	result->BitfieldSize = bitfield_expr;
	result->Attributes   = attributes;
	result->Specs        = specifiers;
	result->Value        = expr;
	result->InlineCmt    = inline_cmt;

	if (array_expr)
		type->ArrExpr = array_expr;

	if ( next_var ) {
		result->NextVar         = next_var;
		result->NextVar->Parent = cast(Code, result);
	}
	result->VarParenthesizedInit = using_constructor_initializer;

	parser_pop(& _ctx->parser);
	return result;
}

/*
	Note(Ed): This does not support the following:
	* Function Pointers
*/
internal
CodeVar parse_variable_declaration_list()
{
	push_scope();

	CodeVar result   = NullCode;
	CodeVar last_var = NullCode;
	while ( check( Tok_Comma ) )
	{
		eat( Tok_Comma );
		// ,

		CodeSpecifiers specifiers = NullCode;

		while ( left && tok_is_specifier(currtok) )
		{
			Specifier spec = str_to_specifier( currtok.Text );

			switch ( spec )
			{
				case Spec_Const:
					if ( specifiers->NumEntries && specifiers->ArrSpecs[ specifiers->NumEntries - 1 ] != Spec_Ptr )
					{
						log_failure( "Error, const specifier must come after pointer specifier for variable declaration proceeding comma\n"
						"(Parser will add and continue to specifiers, but will most likely fail to compile)\n%SB"
						, parser_to_strbuilder(_ctx->parser) );

						specifiers_append(specifiers, spec );
					}
				break;

				case Spec_Ptr:
				case Spec_Ref:
				case Spec_RValue:
				break;

				default:
				{
					log_failure( "Error, invalid specifier '%S' proceeding comma\n"
					"(Parser will add and continue to specifiers, but will most likely fail to compile)\n%S"
					, currtok.Text, strbuilder_to_str( parser_to_strbuilder(_ctx->parser)) );
					continue;
				}
				break;
			}

			if ( specifiers )
				specifiers_append(specifiers, spec );
			else
				specifiers = def_specifier( spec );

			eat(currtok.Type);
		}
		// , <Specifiers>

		Str name = currtok.Text;
		eat( Tok_Identifier );
		// , <Specifiers> <Name>

		CodeVar var = parse_variable_after_name( ModuleFlag_None, NullCode, specifiers, NullCode, name );
		// , <Specifiers> <Name> ...

		if ( ! result )
		{
			result   = var;
			last_var = var;
		}
		else
		{
			last_var->NextVar         = var;
			last_var->NextVar->Parent = cast(Code, var);
			last_var                  = var;
		}
	}

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeClass parser_parse_class( bool inplace_def )
{
	push_scope();
	CodeClass result = (CodeClass) parse_class_struct( Tok_Decl_Class, inplace_def );
	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeConstructor parser_parse_constructor( CodeSpecifiers specifiers )
{
	push_scope();

	Token     identifier = parse_identifier(nullptr);
	CodeParams params     = parse_params(parser_not_from_template);
	// <Name> ( <Parameters> )

	Code        initializer_list = NullCode;
	CodeBody    body             = NullCode;
	CodeComment inline_cmt       = NullCode;

	// TODO(Ed) : Need to support postfix specifiers

	if ( check( Tok_Assign_Classifer ) )
	{
		eat( Tok_Assign_Classifer );
		// <Name> ( <Parameters> ) :

		Token initializer_list_tok = currtok;

		s32 level                  = 0;
		while ( left && ( currtok.Type != Tok_BraceCurly_Open || level > 0 ) )
		{
			if (currtok.Type == Tok_Paren_Open)
				level++;
			else if ( currtok.Type == Tok_Paren_Close )
				level--;

			eat( currtok.Type );
		}

		initializer_list_tok.Text.Len = ( ( sptr )prevtok.Text.Ptr + prevtok.Text.Len ) - ( sptr )initializer_list_tok.Text.Ptr;
		// <Name> ( <Parameters> ) : <InitializerList>

		initializer_list = untyped_str( initializer_list_tok.Text );

		// TODO(Ed): Constructors can have post-fix specifiers

		body = cast(CodeBody, parse_function_body());
		// <Name> ( <Parameters> ) : <InitializerList> { <Body> }
	}
	else if ( check( Tok_BraceCurly_Open ) )
	{
		body = cast(CodeBody, parse_function_body());
		// <Name> ( <Parameters> ) { <Body> }
	}
	// TODO(Ed): Add support for detecting constructor deletion
	else if ( check( Tok_Operator) && currtok.Text.Ptr[ 0 ] == '=' )
	{
		body = cast(CodeBody, parse_assignment_expression());
	}
	else
	{
		Token stmt_end = currtok;
		eat( Tok_Statement_End );
		// <Name> ( <Parameters> );

		if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
			inline_cmt = parse_comment();
		// <Name> ( <Parameters> ); <InlineCmt>
	}

	CodeConstructor result = ( CodeConstructor )make_code();

	result->Name = cache_str( identifier.Text );

	result->Specs = specifiers;

	if ( params )
		result->Params = params;

	if ( initializer_list )
		result->InitializerList = initializer_list;

	if ( body && body->Type == CT_Function_Body )
	{
		result->Body = cast(Code, body);
		result->Type = CT_Constructor;
	}
	else
		result->Type = CT_Constructor_Fwd;

	if ( inline_cmt )
		result->InlineCmt = inline_cmt;

	parser_pop(& _ctx->parser);
	return result;
}

internal inline
CodeDefine parser_parse_define()
{
	push_scope();
	if ( check(Tok_Preprocess_Hash)) {
		// If parse_define is called by the user the hash reach here.
		eat(Tok_Preprocess_Hash);
	}

	eat( Tok_Preprocess_Define );
	// #define

	CodeDefine
	define = (CodeDefine) make_code();
	define->Type = CT_Preprocess_Define;
	if ( ! check( Tok_Identifier ) ) {
		log_failure( "Error, expected identifier after #define\n%s", parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}
	_ctx->parser.Scope->Name = currtok.Text;
	define->Name = cache_str( currtok.Text );
	eat( Tok_Identifier );
	// #define <Name>

	Macro* macro = lookup_macro(define->Name);
	if (macro_is_functional(* macro)) {
		eat( Tok_Paren_Open );
		// #define <Name> (

		// We provide the define params even if empty to make sure '()' are serialized.
		CodeDefineParams
		params = (CodeDefineParams) make_code();
		params->Type = CT_Parameters_Define;

		if ( left && currtok.Type != Tok_Paren_Close ) {
			params->Name = currtok.Text;
			params->NumEntries ++;

			eat( Tok_Preprocess_Define_Param );
			// #define <Name> ( <param>
		}
		
		while( left && currtok.Type != Tok_Paren_Close ) {
			eat( Tok_Comma );
			// #define <Name> ( <param>, 

			CodeDefineParams next_param = (CodeDefineParams) make_code();
			next_param->Type = CT_Parameters_Define;
			next_param->Name = currtok.Text;
			define_params_append(params, next_param);

			// #define  <Name> (  <param>, <next_param> ...
			eat( Tok_Preprocess_Define_Param );
		}

		eat( Tok_Paren_Close );
		// #define <Name> ( <params> )

		define->Params = params;
	}

	if ( ! check( Tok_Preprocess_Content ))
	{
		log_failure( "Error, expected content after #define %s\n%s", define->Name, parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	if ( currtok.Text.Len == 0 )
	{
		define->Body = untyped_str( txt("\n") );
		eat( Tok_Preprocess_Content );
		// #define <Name> ( <params> ) <Content>

		parser_pop(& _ctx->parser);
		return define;
	}

	define->Body = untyped_str( strbuilder_to_str( parser_strip_formatting( currtok.Text, parser_strip_formatting_dont_preserve_newlines )) );
	eat( Tok_Preprocess_Content );
	// #define <Name> ( <params> ) <Content>

	parser_pop(& _ctx->parser);
	return define;
}

internal
CodeDestructor parser_parse_destructor( CodeSpecifiers specifiers )
{
	push_scope();

	bool has_context         = _ctx->parser.Scope && _ctx->parser.Scope->Prev;
	bool is_in_global_nspace = has_context && str_are_equal( _ctx->parser.Scope->Prev->ProcName, txt("parse_global_nspace") );

	if ( check( Tok_Spec_Virtual ) )
	{
		if ( specifiers )
			specifiers_append(specifiers, Spec_Virtual );
		else
			specifiers = def_specifier( Spec_Virtual );
		eat( Tok_Spec_Virtual );
	}
	// <Virtual Specifier>

	Token prefix_identifier = NullToken;
	if (is_in_global_nspace)
		prefix_identifier = parse_identifier(nullptr);

	if ( left && currtok.Text.Ptr[ 0 ] == '~' )
		eat( Tok_Operator );
	else
	{
		log_failure( "Expected destructor '~' token\n%s", parser_to_strbuilder(_ctx->parser) );
		parser_pop( & _ctx->parser);
		return InvalidCode;
	}
	// <Virtual Specifier> ~

	Token       identifier = parse_identifier(nullptr);
	CodeBody    body       = { nullptr };
	CodeComment inline_cmt = NullCode;
	// <Virtual Specifier> ~<Name>

	eat( Tok_Paren_Open );
	eat( Tok_Paren_Close );
	// <Virtual Specifier> ~<Name>()

	bool pure_virtual = false;

	if ( check( Tok_Operator ) && currtok.Text.Ptr[ 0 ] == '=' )
	{
		// <Virtual Specifier> ~<Name>() =

		bool skip_formatting = true;
		Token upcoming = nexttok;
		if ( left && upcoming.Text.Ptr[ 0 ] == '0' )
		{
			eat( Tok_Operator );
			eat( Tok_Number );
			// <Virtual Specifier> ~<Name>() = 0

			specifiers_append(specifiers, Spec_Pure );
		}
		else if ( left && c_str_compare_len( upcoming.Text.Ptr, "default", sizeof("default") - 1 ) == 0) 
		{
			body = cast(CodeBody, parse_assignment_expression());
			// <Virtual Specifier> ~<
		}
		else
		{
			log_failure( "Pure or default specifier expected due to '=' token\n%s", parser_to_strbuilder(_ctx->parser) );
			parser_pop( & _ctx->parser);
			return InvalidCode;
		}

		pure_virtual = true;
	}

	if ( ! pure_virtual && check( Tok_BraceCurly_Open ) )
	{
		body = cast(CodeBody, parse_function_body());
		// <Virtual Specifier> ~<Name>() { ... }
	}
	else
	{
		Token stmt_end = currtok;
		eat( Tok_Statement_End );
		// <Virtual Specifier> ~<Name>() <Pure Specifier>;

		if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
			inline_cmt = parse_comment();
		// <Virtual Specifier> ~<Name>() <Pure Specifier>; <InlineCmt>
	}

	CodeDestructor result = ( CodeDestructor )make_code();

	if ( tok_is_valid(prefix_identifier) ) {
		prefix_identifier.Text.Len += 1 + identifier.Text.Len;
		result->Name = cache_str( prefix_identifier.Text );
	}

	if ( specifiers )
		result->Specs = specifiers;

	if ( body && body->Type == CT_Function_Body ) {
		result->Body = cast(Code, body);
		result->Type = CT_Destructor;
	}
	else
		result->Type = CT_Destructor_Fwd;

	if ( inline_cmt )
		result->InlineCmt = inline_cmt;

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeEnum parser_parse_enum( bool inplace_def )
{
	push_scope();

	Specifier specs_found[16] = { Spec_NumSpecifiers };
	s32       NumSpecifiers = 0;

	CodeAttributes attributes = { nullptr };

	Token        name       = NullToken;
	Code         array_expr = { nullptr };
	CodeTypename type       = { nullptr };

	bool is_enum_class = false;

	eat( Tok_Decl_Enum );
	// enum

	if ( currtok.Type == Tok_Decl_Class )
	{
		eat( Tok_Decl_Class);
		is_enum_class = true;
		// enum class
	}

	attributes = parse_attributes();
	// enum <class> <Attributes>

	if ( check( Tok_Identifier ) )
	{
		name = currtok;
		_ctx->parser.Scope->Name = currtok.Text;
		eat( Tok_Identifier );
	}
	// enum <class> <Attributes> <Name>

	b32  use_macro_underlying = false;
	Code underlying_macro     = { nullptr };
	if ( currtok.Type == Tok_Assign_Classifer )
	{
		eat( Tok_Assign_Classifer );
		// enum <class> <Attributes> <Name> :

		type = parser_parse_type(parser_not_from_template, nullptr);
		if ( cast(Code, type) == Code_Invalid )
		{
			log_failure( "Failed to parse enum classifier\n%s", parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}
		// enum <class> <Attributes> <Name> : <UnderlyingType>
	}
	else if ( currtok.Type == Tok_Preprocess_Macro_Expr )
	{
		// We'll support the enum_underlying macro
		if ( str_contains( currtok.Text, enum_underlying_macro.Name) )
		{
			use_macro_underlying = true;
			underlying_macro     = parse_simple_preprocess( Tok_Preprocess_Macro_Expr );
		}
	}

	CodeBody body = { nullptr };

	if ( currtok.Type == Tok_BraceCurly_Open )
	{
		body       = (CodeBody) make_code();
		body->Type = CT_Enum_Body;

		eat( Tok_BraceCurly_Open );
		// enum <class> <Attributes> <Name> : <UnderlyingType> {

		Code member = InvalidCode;

		bool expects_entry = true;
		while ( left && currtok_noskip.Type != Tok_BraceCurly_Close )
		{
			if ( ! expects_entry )
			{
				log_failure( "Did not expect an entry after last member of enum body.\n%s", parser_to_strbuilder(_ctx->parser) );
				parser_pop(& _ctx->parser);
				break;
			}

			if ( currtok_noskip.Type == Tok_Preprocess_Hash )
				eat( Tok_Preprocess_Hash );

			switch ( currtok_noskip.Type )
			{
				case Tok_NewLine:
					member = untyped_str( currtok_noskip.Text );
					eat( Tok_NewLine );
				break;

				case Tok_Comment:
					member = cast(Code, parse_comment());
				break;

				case Tok_Preprocess_Define:
					member = cast(Code, parser_parse_define());
					// #define
				break;

				case Tok_Preprocess_If:
				case Tok_Preprocess_IfDef:
				case Tok_Preprocess_IfNotDef:
				case Tok_Preprocess_ElIf:
					member = cast(Code, parse_preprocess_cond());
					// #<if, ifdef, ifndef, elif> ...
				break;

				case Tok_Preprocess_Else:
					member = cast(Code, preprocess_else);
					eat( Tok_Preprocess_Else );
				break;

				case Tok_Preprocess_EndIf:
					member = cast(Code, preprocess_endif);
					eat( Tok_Preprocess_EndIf );
				break;

				case Tok_Preprocess_Macro_Stmt: {
					member = cast(Code, parse_simple_preprocess( Tok_Preprocess_Macro_Stmt ));
					// <Macro>
					break;
				}

				case Tok_Preprocess_Pragma:
					member = cast(Code, parse_pragma());
					// #pragma
				break;

				case Tok_Preprocess_Unsupported:
					member = cast(Code, parse_simple_preprocess( Tok_Preprocess_Unsupported ));
					// #<UNSUPPORTED>
				break;

				default:
				{
					Token entry = currtok;

					eat( Tok_Identifier);
					// <Name>

					if ( currtok.Type == Tok_Operator && currtok.Text.Ptr[0] == '=' )
					{
						eat( Tok_Operator );
						// <Name> =

						while ( currtok.Type != Tok_Comma && currtok.Type != Tok_BraceCurly_Close ) {
							eat( currtok.Type );
						}
					}
					// <Name> = <Expression>

					// Unreal UMETA macro support
					if ( currtok.Type == Tok_Preprocess_Macro_Expr ) {
						Code macro = parse_simple_preprocess( Tok_Preprocess_Macro_Expr );
						// <Name> = <Expression> <Macro>

						// We're intentially ignoring this code as its going to be serialized as an untyped string with the rest of the enum "entry".
						// TODO(Ed): We need a CodeEnumEntry, AST_EnumEntry types
					}

					if ( currtok.Type == Tok_Comma )
					{
						//Token prev = * previous(_ctx->parser.Tokens, dont_skip_formatting);
						//entry.Length = ( (sptr)prev.Text + prev.Length ) - (sptr)entry.Text;

						eat( Tok_Comma );
						// <Name> = <Expression> <Macro>,
					}

					// Consume inline comments
					// if ( currtok.Type == Tok_Comment && prevtok.Line == currtok.Line )
					// {
						// eat( Tok_Comment );
						// <Name> = <Expression> <Macro>, // <Inline Comment>
					// }

					Token prev     = * lex_previous(_ctx->parser.Tokens, lex_dont_skip_formatting);
					entry.Text.Len = ( (sptr)prev.Text.Ptr + prev.Text.Len ) - (sptr)entry.Text.Ptr;

					member = untyped_str( entry.Text );
				}
				break;
			}

			if ( member == Code_Invalid ) {
				log_failure( "Failed to parse member\n%s", parser_to_strbuilder(_ctx->parser) );
				parser_pop(& _ctx->parser);
				return InvalidCode;
			}

			body_append(body, member );
		}

		eat( Tok_BraceCurly_Close );
		// enum <class> <Attributes> <Name> : <UnderlyingType> { <Body> }
	}

	CodeComment inline_cmt = NullCode;

	if ( ! inplace_def )
	{
		Token stmt_end = currtok;
		eat( Tok_Statement_End );
		// enum <class> <Attributes> <Name> : <UnderlyingType> { <Body> };

		if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
			inline_cmt = parse_comment();
			// enum <class> <Attributes> <Name> : <UnderlyingType> { <Body> }; <InlineCmt>
	}

	CodeEnum
	result = (CodeEnum) make_code();

	if ( body )
	{
		result->Type = is_enum_class ? CT_Enum_Class : CT_Enum;
		result->Body = body;
	}
	else
	{
		result->Type = is_enum_class ? CT_Enum_Class_Fwd : CT_Enum_Fwd;
	}

	result->Name = cache_str( name.Text );

	if ( attributes )
		result->Attributes = attributes;

	result->UnderlyingTypeMacro = underlying_macro;
	result->UnderlyingType      = type;

	if ( inline_cmt )
		result->InlineCmt = inline_cmt;


	parser_pop(& _ctx->parser);
	return result;
}

internal inline
CodeBody parser_parse_export_body()
{
	push_scope();
	CodeBody result = parse_global_nspace( CT_Export_Body );
	parser_pop(& _ctx->parser);
	return result;
}

internal inline
CodeBody parser_parse_extern_link_body()
{
	push_scope();
	CodeBody result = parse_global_nspace( CT_Extern_Linkage_Body );
	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeExtern parser_parse_extern_link()
{
	push_scope();

	eat( Tok_Decl_Extern_Linkage );
	// extern

	Token name = currtok;
	eat( Tok_String );
	// extern "<Name>"

	name.Text.Ptr += 1;
	name.Text.Len -= 1;

	CodeExtern
	result       = (CodeExtern) make_code();
	result->Type = CT_Extern_Linkage;
	result->Name = cache_str( name.Text );

	CodeBody entry = parser_parse_extern_link_body();
	if ( cast(Code, entry) == Code_Invalid )
	{
		log_failure( "Failed to parse body\n%s", parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return result;
	}
	// extern "<Name>" { <Body> }

	result->Body = entry;

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeFriend parser_parse_friend()
{
	push_scope();

	eat( Tok_Decl_Friend );
	// friend

	CodeFn         function   = { nullptr };
	CodeOperator   op         = { nullptr };
	CodeSpecifiers specifiers = { nullptr };

	// Specifiers Parsing
	{
		Specifier specs_found[ 16 ] = { Spec_NumSpecifiers };
		s32       NumSpecifiers = 0;

		while ( left && tok_is_specifier(currtok) )
		{
			Specifier spec = str_to_specifier( currtok.Text );

			switch ( spec )
			{
				GEN_PARSER_FRIEND_ALLOWED_SPECIFIER_CASES:
				break;

				default :
					log_failure( "Invalid specifier %S for friend definition\n%S", spec_to_str( spec ), strbuilder_to_str( parser_to_strbuilder(_ctx->parser)) );
					parser_pop(& _ctx->parser);
					return InvalidCode;
			}

			// Ignore const it will be handled by the type
			if ( spec == Spec_Const )
				break;

			specs_found[ NumSpecifiers ] = spec;
			NumSpecifiers++;
			eat( currtok.Type );
		}

		if ( NumSpecifiers ) {
			specifiers = def_specifiers_arr( NumSpecifiers, specs_found );
		}
		// <friend> <specifiers>
	}

	// Type declaration or return type
	CodeTypename type = parser_parse_type(parser_not_from_template, nullptr);
	if ( cast(Code, type) == Code_Invalid ) {
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}
	// friend <Type>

	// Funciton declaration
	if ( currtok.Type == Tok_Identifier )
	{
		// Name
		Token name          = parse_identifier(nullptr);
		_ctx->parser.Scope->Name = name.Text;
		// friend <ReturnType> <Name>

		function = parse_function_after_name( ModuleFlag_None, NullCode, specifiers, type, name );

		// Parameter list
		// CodeParams params = parse_params();
		// friend <ReturnType> <Name> ( <Parameters> )

		// function             = make_code();
		// function->Type       = Function_Fwd;
		// function->Name       = cache_str( name );
		// function->ReturnType = type;

		// if ( params )
			// function->Params = params;
	}

	// Operator declaration or definition
	if ( currtok.Type == Tok_Decl_Operator ) {
		op = parse_operator_after_ret_type( ModuleFlag_None, NullCode, specifiers, type );
	}

	CodeComment inline_cmt = NullCode;
	if ( function && function->Type == CT_Function_Fwd )
	{
		Token stmt_end = currtok;
		eat( Tok_Statement_End );
		// friend <Type>;
		// friend <ReturnType> <Name> ( <Parameters> );

		if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
			inline_cmt = parse_comment();
		// friend <Type>; <InlineCmt>
		// friend <ReturnType> <Name> ( <Parameters> ); <InlineCmt>
	}

	CodeFriend result = ( CodeFriend )make_code();
	result->Type      = CT_Friend;

	if ( function )
		result->Declaration = cast(Code, function);
	else if ( op )
		result->Declaration = cast(Code, op);
	else
		result->Declaration = cast(Code, type);

	if ( inline_cmt )
		result->InlineCmt = inline_cmt;

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeFn parser_parse_function()
{
	push_scope();

	Specifier specs_found[16] = { Spec_NumSpecifiers };
	s32        NumSpecifiers = 0;

	CodeAttributes attributes = { nullptr };
	CodeSpecifiers specifiers = { nullptr };
	ModuleFlag     mflags     = ModuleFlag_None;

	if ( check(Tok_Module_Export) ) {
		mflags = ModuleFlag_Export;
		eat( Tok_Module_Export );
	}
	// <export>

	attributes = parse_attributes();
	// <export> <Attributes>

	while ( left && tok_is_specifier(currtok) )
	{
		Specifier spec = str_to_specifier( currtok.Text );

		switch ( spec )
		{
			GEN_PARSER_FUNCTION_ALLOWED_SPECIFIER_CASES:
			break;

			default:
				log_failure( "Invalid specifier %S for functon\n%SB", spec_to_str(spec), parser_to_strbuilder(_ctx->parser) );
				parser_pop(& _ctx->parser);
				return InvalidCode;
		}

		if ( spec == Spec_Const )
			continue;

		specs_found[NumSpecifiers] = spec;
		NumSpecifiers++;
		eat( currtok.Type );
	}

	if ( NumSpecifiers ) {
		specifiers = def_specifiers_arr( NumSpecifiers, specs_found );
	}
	// <export> <Attributes> <Specifiers>

	CodeTypename ret_type = parser_parse_type(parser_not_from_template, nullptr);
	if ( cast(Code, ret_type) == Code_Invalid ) {
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}
	// <export> <Attributes> <Specifiers> <ReturnType>

	Token name = parse_identifier(nullptr);
	_ctx->parser.Scope->Name = name.Text;
	if ( ! tok_is_valid(name) ) {
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}
	// <export> <Attributes> <Specifiers> <ReturnType> <Name>

	CodeFn result = parse_function_after_name( mflags, attributes, specifiers, ret_type, name );
	// <export> <Attributes> <Specifiers> <ReturnType> <Name> ...

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeNS parser_parse_namespace()
{
	push_scope();

	eat( Tok_Decl_Namespace );
	// namespace

	Token name = parse_identifier(nullptr);
	_ctx->parser.Scope->Name = name.Text;
	// namespace <Name>

	CodeBody body = parse_global_nspace( CT_Namespace_Body );
	if ( cast(Code, body) == Code_Invalid ) {
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}
	// namespace <Name> { <Body> }

	CodeNS
	result       = (CodeNS) make_code();
	result->Type = CT_Namespace;
	result->Name = cache_str( name.Text );

	result->Body = body;

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeOperator parser_parse_operator()
{
	push_scope();

	CodeAttributes attributes = { nullptr };
	CodeSpecifiers specifiers = { nullptr };
	ModuleFlag     mflags     = ModuleFlag_None;

	Specifier specs_found[16] = { Spec_NumSpecifiers };
	s32        NumSpecifiers = 0;

	if ( check(Tok_Module_Export) ) {
		mflags = ModuleFlag_Export;
		eat( Tok_Module_Export );
	}
	// <export>

	attributes = parse_attributes();
	// <export> <Attributes>

	while ( left && tok_is_specifier(currtok) )
	{
		Specifier spec = str_to_specifier( currtok.Text );

		switch ( spec )
		{
			GEN_PARSER_OPERATOR_ALLOWED_SPECIFIER_CASES:
			break;

			default:
				log_failure( "Invalid specifier " "%S" " for operator\n%SB", spec_to_str(spec), parser_to_strbuilder(_ctx->parser) );
				parser_pop(& _ctx->parser);
				return InvalidCode;
		}

		if ( spec == Spec_Const )
			continue;

		specs_found[NumSpecifiers] = spec;
		NumSpecifiers++;
		eat( currtok.Type );
	}

	if ( NumSpecifiers ) {
		specifiers = def_specifiers_arr( NumSpecifiers, specs_found );
	}
	// <export> <Attributes> <Specifiers>

	// Parse Return Type
	CodeTypename ret_type = parser_parse_type(parser_not_from_template, nullptr);
	// <export> <Attributes> <Specifiers> <ReturnType>

	CodeOperator result = parse_operator_after_ret_type( mflags, attributes, specifiers, ret_type );
	// <export> <Attributes> <Specifiers> <ReturnType> ...

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeOpCast parser_parse_operator_cast( CodeSpecifiers specifiers )
{
	push_scope();

	// Operator's namespace if not within same class.
	Token name = NullToken;
	if ( check( Tok_Identifier ) )
	{
		name = currtok;
		while ( left && currtok.Type == Tok_Identifier )
		{
			eat( Tok_Identifier );
			// <Specifiers> <Qualifier>

			if ( currtok.Type == Tok_Access_StaticSymbol )
				eat( Tok_Access_StaticSymbol );
				// <Specifiers> <Qualifier> ::
		}
		// <Specifiers> <Qualifier> :: ...

		name.Text.Len = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)name.Text.Ptr;
	}

	eat( Tok_Decl_Operator );
	// <Specifiers> <Qualifier> :: ... operator

	CodeTypename type = parser_parse_type(parser_not_from_template, nullptr);
	// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>

	Str scope_name         = { type->Name.Ptr, type->Name.Len };
	Token scope_name_tok   = { scope_name, Tok_Identifier, 0, 0, TF_Null };
	_ctx->parser.Scope->Name = scope_name_tok.Text;

	eat( Tok_Paren_Open );
	eat( Tok_Paren_Close );
	// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>()

	// TODO(Ed) : operator cast can have const, volatile, l-value, r-value noexecept qualifying specifiers.
	if ( check(Tok_Spec_Const))
	{
		if ( specifiers == nullptr )
			specifiers = def_specifier( Spec_Const );

		else
			specifiers_append(specifiers, Spec_Const );

		eat( Tok_Spec_Const );
	}
	// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const>

	Code        body       = NullCode;
	CodeComment inline_cmt = NullCode;

	if ( check( Tok_BraceCurly_Open) )
	{
		eat( Tok_BraceCurly_Open );
		// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const> {

		Token body_str = currtok;

		s32 level = 0;
		while ( left && ( currtok.Type != Tok_BraceCurly_Close || level > 0 ) )
		{
			if ( currtok.Type == Tok_BraceCurly_Open )
				level++;

			else if ( currtok.Type == Tok_BraceCurly_Close )
				level--;

			eat( currtok.Type );
		}
		body_str.Text.Len = ( (sptr)prevtok.Text.Ptr + prevtok.Text.Len ) - (sptr)body_str.Text.Ptr;

		eat( Tok_BraceCurly_Close );
		// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const> { <Body> }

		body = untyped_str( body_str.Text );
	}
	else
	{
		Token stmt_end = currtok;
		eat( Tok_Statement_End );
		// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const>;

		if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
			inline_cmt = parse_comment();
			// <Specifiers> <Qualifier> :: ... operator <UnderlyingType>() <const>; <InlineCmt>
	}

	CodeOpCast result = (CodeOpCast) make_code();

	if ( tok_is_valid(name) )
		result->Name = cache_str( name.Text );

	if (body) {
		result->Type = CT_Operator_Cast;
		result->Body = cast(CodeBody, body);
	}
	else {
		result->Type = CT_Operator_Cast_Fwd;
	}

	if ( specifiers )
		result->Specs = specifiers;

	result->ValueType = cast(CodeTypename, type);

	parser_pop(& _ctx->parser);
	return result;
}

internal inline
CodeStruct parser_parse_struct( bool inplace_def )
{
	push_scope();
	CodeStruct result = (CodeStruct) parse_class_struct( Tok_Decl_Struct, inplace_def );
	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeTemplate parser_parse_template()
{
#define UseTemplateCapture true

	push_scope();

	ModuleFlag mflags = ModuleFlag_None;

	if ( check( Tok_Module_Export ) ) {
		mflags = ModuleFlag_Export;
		eat( Tok_Module_Export );
	}
	// <export> template

	eat( Tok_Decl_Template );
	// <export> template

	CodeParams params = parse_params( UseTemplateCapture );
	if ( cast(Code, params) == Code_Invalid ) {
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}
	// <export> template< <Parameters> >

	Code definition = { nullptr };

	while ( left )
	{
		if ( check( Tok_Decl_Class ) )
		{
			definition = cast(Code, parser_parse_class( parser_not_inplace_def));
			// <export> template< <Parameters> > class ...
			break;
		}

		if ( check( Tok_Decl_Struct ) )
		{
			definition = cast(Code, parser_parse_struct( parser_not_inplace_def));
			// <export> template< <Parameters> > struct ...
			break;
		}

		if ( check( Tok_Decl_Union ) )
		{
			definition = cast(Code, parser_parse_union( parser_not_inplace_def));
			// <export> template< <Parameters> > union ...
			break;
		}

		if ( check( Tok_Decl_Using ) )
		{
			definition = cast(Code, parser_parse_using());
			// <export> template< <Parameters> > using ...
			break;
		}

		// Its either a function or a variable
		Token name                = NullToken;

		CodeAttributes attributes = { nullptr };
		CodeSpecifiers specifiers = { nullptr };

		bool expects_function     = false;

		Specifier specs_found[ 16 ] = { Spec_NumSpecifiers };
		s32        NumSpecifiers = 0;

		attributes = parse_attributes();
		// <export> template< <Parameters> > <Attributes>

		// Specifiers Parsing
		{
			while ( left && tok_is_specifier(currtok) )
			{
				Specifier spec = str_to_specifier( currtok.Text );

				switch ( spec )
				{
					GEN_PARSER_TEMPLATE_ALLOWED_SPECIFIER_CASES:
					break;

					case Spec_Consteval :
						expects_function = true;
						break;

					default :
						log_failure( "Invalid specifier %S for variable or function\n%SB", spec_to_str( spec ), parser_to_strbuilder(_ctx->parser) );
						parser_pop(& _ctx->parser);
						return InvalidCode;
				}

				// Ignore const it will be handled by the type
				if ( spec == Spec_Const )
					break;

				specs_found[ NumSpecifiers ] = spec;
				NumSpecifiers++;
				eat( currtok.Type );
			}

			if ( NumSpecifiers ) {
				specifiers = def_specifiers_arr( NumSpecifiers, specs_found );
			}
			// <export> template< <Parameters> > <Attributes> <Specifiers>
		}


		bool has_context         = _ctx->parser.Scope && _ctx->parser.Scope->Prev;
		bool is_in_global_nspace = has_context && str_are_equal( _ctx->parser.Scope->Prev->ProcName, txt("parse_global_nspace") );
		// Possible constructor implemented at global file scope.
		if (is_in_global_nspace)
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
		if (is_in_global_nspace)
		{
			bool found_operator_cast_outside_class_implmentation = false;
			s32  idx = _ctx->parser.Tokens.Idx;

			for ( ; idx < array_num(_ctx->parser.Tokens.Arr); idx++ )
			{
				Token tok = _ctx->parser.Tokens.Arr[ idx ];

				if ( tok.Type == Tok_Identifier )
				{
					idx++;
					tok = _ctx->parser.Tokens.Arr[ idx ];
					if ( tok.Type == Tok_Access_StaticSymbol )
						continue;

					break;
				}

				if ( tok.Type == Tok_Decl_Operator )
					found_operator_cast_outside_class_implmentation = true;

				break;
			}

			if ( found_operator_cast_outside_class_implmentation ) {
				definition = cast(Code, parser_parse_operator_cast( specifiers ));
				// <Attributes> <Specifiers> <Name> :: operator <Type> () { ... }
				break;
			}
		}

		definition = parse_operator_function_or_variable( expects_function, attributes, specifiers );
		// <export> template< <Parameters> > <Attributes> <Specifiers> ...
		break;
	}

	CodeTemplate result = ( CodeTemplate )make_code();
	result->Type        = CT_Template;
	result->Params      = params;
	result->Declaration = definition;
	result->ModuleFlags = mflags;
	// result->Name        = definition->Name;

	parser_pop(& _ctx->parser);
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
internal
CodeTypename parser_parse_type( bool from_template, bool* typedef_is_function )
{
	push_scope();

	Token context_tok = prevtok;

	Specifier specs_found[ 16 ] = { Spec_NumSpecifiers };
	s32       NumSpecifiers = 0;

	Token name= NullToken;

	ETypenameTag tag = Tag_None;

	// Attributes are assumed to be before the type signature
	CodeAttributes attributes = parse_attributes();
	// <Attributes>

	// Prefix specifiers
	while ( left && tok_is_specifier(currtok) )
	{
		Specifier spec = str_to_specifier( currtok.Text );

		if ( spec != Spec_Const ) {
			log_failure( "Error, invalid specifier used in type definition: %S\n%SB", currtok.Text, parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}

		specs_found[ NumSpecifiers ] = spec;
		NumSpecifiers++;
		eat( currtok.Type );
	}
	// <Attributes> <Specifiers>

	if ( left == 0 ) {
		log_failure( "Error, unexpected end of type definition\n%SB", parser_to_strbuilder(_ctx->parser) );
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	if ( from_template && currtok.Type == Tok_Decl_Class )
	{
		// If a value's type is being parsed from a template, class can be used instead of typename.
		name = currtok;
		eat(Tok_Decl_Class);
		// <class>
	}

	// All kinds of nonsense can makeup a type signature, first we check for a in-place definition of a class, enum, struct, or union
	else if ( currtok.Type == Tok_Decl_Class || currtok.Type == Tok_Decl_Enum || currtok.Type == Tok_Decl_Struct
			|| currtok.Type == Tok_Decl_Union )
	{
		switch (currtok.Type) {
			case Tok_Decl_Class  : tag = Tag_Class;  break;
			case Tok_Decl_Enum   : tag = Tag_Enum;   break;
			case Tok_Decl_Struct : tag = Tag_Struct; break;
			case Tok_Decl_Union  : tag = Tag_Union;  break;
			default:
				break;
		}
		eat( currtok.Type );
		// <Attributes> <Specifiers> <class, enum, struct, union>

		name = parse_identifier(nullptr);

		// name.Length = ( ( sptr )currtok.Text + currtok.Length ) - ( sptr )name.Text;
		// eat( Tok_Identifier );
		_ctx->parser.Scope->Name = name.Text;
		// <Attributes> <Specifiers> <class, enum, struct, union> <Name>
	}

// Decltype draft implementation
#if 0
else if ( currtok.Type == Tok_DeclType )
{
	// Will have a capture and its own parsing rules, were going to just shove everything in a string (for now).
	name = currtok;
	eat( Tok_DeclType );
	// <Attributes> <Specifiers> decltype

	eat( Tok_Paren_Open );
	while ( left && currtok.Type != Tok_Paren_Close )
	{
		if ( currtok.Type == Tok_Paren_Open )
			level++;

		if ( currtok.Type == Tok_Paren_Close )
			level--;

		eat( currtok.Type );
	}
	eat( Tok_Paren_Close );

	name.Length = ( (sptr)currtok.Text + currtok.Length ) - (sptr)name.Text;
	_ctx->parser.Scope->Name = name;
	// <Attributes> <Specifiers> decltype( <Expression > )
}
#endif

	// Check if native type keywords are used, eat them for the signature.
	// <attributes> <specifiers> <native types ...> ...
	else if ( currtok.Type >= Tok_Type_Unsigned && currtok.Type <= Tok_Type_MS_W64 )
	{
		// TODO(Ed) : Review this... Its necessary for parsing however the algo's path to this is lost...
		name = currtok;
		eat( currtok.Type );

		while ( left && currtok.Type >= Tok_Type_Unsigned && currtok.Type <= Tok_Type_MS_W64 )
		{
			eat( currtok.Type );
		}

		name.Text.Len = ( ( sptr )prevtok.Text.Ptr + prevtok.Text.Len ) - ( sptr )name.Text.Ptr;
		// <Attributes> <Specifiers> <Compound type expression>
	}
	else if ( currtok.Type == Tok_Type_Typename )
	{
		name = currtok;
		eat(Tok_Type_Typename);
		// <typename>

		if ( ! from_template )
		{
			name                = parse_identifier(nullptr);
			_ctx->parser.Scope->Name = name.Text;
			if ( ! tok_is_valid(name) )
			{
				log_failure( "Error, failed to type signature\n%s", parser_to_strbuilder(_ctx->parser) );
				parser_pop(& _ctx->parser);
				return InvalidCode;
			}
		}
	}
	else if ( currtok.Type == Tok_Preprocess_Macro_Typename ) {
		// Typename is a macro
		// name = currtok;
		// eat(Tok_Preprocess_Macro_Typename);
		Code macro = parse_simple_preprocess(Tok_Preprocess_Macro_Typename);
		name.Text = macro->Content;
	}

	// The usual Identifier type signature that may have namespace qualifiers
	else
	{
		name = parse_identifier(nullptr);
		_ctx->parser.Scope->Name = name.Text;
		if ( ! tok_is_valid(name) )
		{
			log_failure( "Error, failed to type signature\n%s", parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}
		// <Attributes> <Specifiers> <Qualifier ::> <Identifier>
		// <Attributes> <Specifiers> <Identifier>
	}

	// Suffix specifiers for typename.
	while ( left && tok_is_specifier(currtok) )
	{
		Specifier spec = str_to_specifier( currtok.Text );

		switch (spec ) {
			GEN_PARSER_TYPENAME_ALLOWED_SUFFIX_SPECIFIER_CASES:
			break;

			default: {
				log_failure( "Error, invalid specifier used in type definition: %S\n%SB", currtok.Text, parser_to_strbuilder(_ctx->parser) );
				parser_pop(& _ctx->parser);
				return InvalidCode;
			}
		}
		specs_found[ NumSpecifiers ] = spec;
		NumSpecifiers++;
		eat( currtok.Type );
	}

#ifdef GEN_USE_NEW_TYPENAME_PARSING
	if ( NumSpecifiers )
	{
		specifiers    = def_specifiers_arr( NumSpecifiers, specs_found );
		NumSpecifiers = 0;
	}
#endif
	// <Attributes> <Specifiers> <Identifier> <Specifiers>

	// For function type signatures
	CodeTypename return_type = NullCode;
	CodeParams   params      = NullCode;

#ifdef GEN_USE_NEW_TYPENAME_PARSING
	CodeParams params_nested = NullCode;
#endif

	bool   is_function_typename = false;
	Token* last_capture         = nullptr;
	{
		Token* scanner = _ctx->parser.Tokens.Arr + _ctx->parser.Tokens.Idx;

		// An identifier being within a typename's signature only occurs if were parsing a typename for a typedef.
		if ( typedef_is_function && scanner->Type == Tok_Identifier )
		{
			is_function_typename = true;
			++scanner;
		}
		is_function_typename = scanner->Type == Tok_Paren_Open;

		Token* first_capture = scanner;
		if ( is_function_typename )
		{
			// Go to the end of the signature
			while ( scanner->Type != Tok_Statement_End && scanner->Type != Tok_BraceCurly_Open )
				++scanner;

			// Go back to the first capture start found
			while ( scanner->Type != Tok_Paren_Open )
				--scanner;

			last_capture = scanner;
		}

		bool has_context   = _ctx->parser.Scope && _ctx->parser.Scope->Prev;
		bool is_for_opcast = has_context && str_are_equal( _ctx->parser.Scope->Prev->ProcName, txt("parser_parse_operator_cast") );
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
		return_type       = ( CodeTypename )make_code();
		return_type->Type = CT_Typename;

		// StrBuilder
		// name_stripped = StrBuilder::make( FallbackAllocator, name );
		// name_stripped.strip_space();
		return_type->Name = cache_str( name.Text );

#ifdef GEN_USE_NEW_TYPENAME_PARSING
		if ( specifiers )
		{
			return_type->Specs = specifiers;
			specifiers         = nullptr;
		}

#else
		if ( NumSpecifiers )
			return_type->Specs = def_specifiers_arr( NumSpecifiers, ( Specifier* )specs_found );

		// Reset specifiers, the function itself will have its own suffix specifiers possibly.
		NumSpecifiers = 0;
#endif
		// <Attributes> <ReturnType>
		name = NullToken;

		// The next token can either be a capture for the identifier or it could be the identifier exposed.
		if ( ! check( Tok_Paren_Open ) )
		{
			// Started with an identifier immeidately, which means its of the format: <ReturnType> <identifier> <capture>;
			name = parse_identifier(nullptr);
		}
		// <Attributes> <ReturnType> <Identifier>

		// If the next token is a capture start and is not the last capture, then we're dealing with function typename whoose identifier is within the
		// capture.
		else if ( ( _ctx->parser.Tokens.Arr + _ctx->parser.Tokens.Idx ) != last_capture )
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
			eat( Tok_Paren_Open );
			// <Attributes> <ReturnType> (

			// Binding specifiers
			while ( left && currtok.is_specifier() )
			{
				Specifier spec = to_type( currtok );

				if ( spec != Spec_Ptr && spec != Spec_Ref && spec != Spec_RValue )
				{
					log_failure( "Error, invalid specifier used in type definition: %S\n%SB", toktype_to_str(currtok), to_strbuilder(_ctx->parser) );
					pop(& _ctx->parser);
					return InvalidCode;
				}

				specs_found[ NumSpecifiers ] = spec;
				NumSpecifiers++;
				eat( currtok.Type );
			}

			if ( NumSpecifiers )
			{
				specifiers = def_specifiers_arr( NumSpecifiers, specs_found );
			}
			NumSpecifiers = 0;
			// <Attributes> <ReturnType> ( <Specifiers>

			if ( check( Tok_Identifier ) )
				name = parse_identifier();
			// <Attributes> <ReturnType> ( <Specifiers> <Identifier>

			// Immeidate parameters

			if ( check( Tok_Paren_Open ) )
				params_nested = parse_params();
			// <Attributes> <ReturnType> ( <Specifiers> <Identifier> ( <Parameters> )

			eat( Tok_Paren_Close );
			// <Attributes> <ReturnType> ( <Specifiers> <Identifier> ( <Parameters> ) )

#else
			// Starting immediatley with a capture, most likely declaring a typename for a member function pointer.
			// Everything within this capture will just be shoved into the name field including the capture tokens themselves.
			name = currtok;

			eat( Tok_Paren_Open );
			// <Attributes> <ReturnType> (

			s32 level = 0;
			while ( left && ( currtok.Type != Tok_Paren_Close || level > 0 ) )
			{
				if ( currtok.Type == Tok_Paren_Open )
					level++;

				if ( currtok.Type == Tok_Paren_Close )
					level--;

				eat( currtok.Type );
			}
			eat( Tok_Paren_Close );
			// <Attributes> <ReturnType> ( <Expression> )

			name.Text.Len = ( ( sptr )prevtok.Text.Ptr + prevtok.Text.Len ) - ( sptr )name.Text.Ptr;
#endif
		}

		// Were now dealing with the parameters of the function
		params = parse_params(parser_use_parenthesis);
		// <Attributes> <ReturnType> <All Kinds of nonsense> ( <Parameters> )

		// Look for suffix specifiers for the function
		while ( left && tok_is_specifier(currtok) )
		{
			Specifier spec = str_to_specifier( currtok.Text );

			if ( spec != Spec_Const
					// TODO : Add support for NoExcept, l-value, volatile, l-value, etc
					// && spec != Spec_NoExcept
					&& spec != Spec_RValue )
			{
				log_failure( "Error, invalid specifier used in type definition: %S\n%S", currtok.Text, strbuilder_to_str( parser_to_strbuilder(_ctx->parser)) );
				parser_pop(& _ctx->parser);
				return InvalidCode;
			}

			specs_found[ NumSpecifiers ] = spec;
			NumSpecifiers++;
			eat( currtok.Type );
		}

#ifdef GEN_USE_NEW_TYPENAME_PARSING
		if ( NumSpecifiers )
		{
			func_suffix_specs = def_specifiers_arr( NumSpecifiers, specs_found );
			NumSpecifiers     = 0;
		}
#endif
		// <Attributes> <ReturnType> <All Kinds of nonsense> ( <Parameters> ) <Specifiers>
	}
	// <Attributes> <All Kinds of nonsense>

	bool is_param_pack = false;
	if ( check( Tok_Varadic_Argument ) )
	{
		is_param_pack = true;
		eat( Tok_Varadic_Argument );
		// <Attributes> <All kinds of nonsense> ...
	}

	CodeTypename result = ( CodeTypename )make_code();
	result->Type        = CT_Typename;
	// result->Token = _ctx->parser.Scope->Start;

	// Need to wait until were using the new parsing method to do this.
	StrBuilder name_stripped = parser_strip_formatting( name.Text, parser_strip_formatting_dont_preserve_newlines );

	// name_stripped.strip_space();

#ifdef GEN_USE_NEW_TYPENAME_PARSING
	if ( params_nested )
	{
		name_stripped.append( params_nested->to_strbuilder() );
	}
#endif

	result->Name = cache_str( strbuilder_to_str(name_stripped) );

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
		CodeSpecifiers specifiers = def_specifiers_arr( NumSpecifiers, ( Specifier* )specs_found );
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

	result->TypeTag = tag;

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeTypedef parser_parse_typedef()
{
	push_scope();

	bool  is_function = false;
	Token name        = NullToken;
	Code  array_expr  = { nullptr };
	Code  type        = { nullptr };

	ModuleFlag mflags = ModuleFlag_None;

	if ( check(Tok_Module_Export) )
	{
		mflags = ModuleFlag_Export;
		eat( Tok_Module_Export );
	}
	// <ModuleFlags>

	eat( Tok_Decl_Typedef );
	// <ModuleFlags> typedef

	const bool from_typedef = true;

	// TODO(Ed): UPDATE MACRO USAGE HERE
#if GEN_PARSER_DISABLE_MACRO_TYPEDEF
	if ( false )
#else
	b32 valid_macro = false;
	valid_macro |= left && currtok.Type == Tok_Preprocess_Macro_Typename;
	valid_macro |= left && currtok.Type == Tok_Preprocess_Macro_Stmt;
	// if (currtok.Type == Tok_Preprocess_Macro_Stmt)
	// {
		// PreprocessMacro* macro = lookup_macro(currtok.Text);
		// valid_macro |= macro && macro_expects_body(* macro));
	// }

	if ( valid_macro )
#endif
	{
		type          = cast(Code, t_empty);
		name          = currtok;
		Code macro    = parse_simple_preprocess(currtok.Type);
		name.Text.Len = macro->Content.Len;
		_ctx->parser.Scope->Name = name.Text;
		// <ModuleFalgs> typedef <Preprocessed_Macro>

		if ( currtok.Type == Tok_Identifier )
		{
			type = macro;
			name = currtok;
			eat(Tok_Identifier);
			// <ModuleFalgs> typedef <Preprocessed_Macro> <Identifier>
		}
	}
	else
	{
		bool is_complicated =
				currtok.Type == Tok_Decl_Enum
			||	currtok.Type == Tok_Decl_Class
			||	currtok.Type == Tok_Decl_Struct
			||	currtok.Type == Tok_Decl_Union;


		// This code is highly correlated with parse_complicated_definition
		if ( is_complicated )
		{
			TokArray tokens = _ctx->parser.Tokens;
			TokType  which  = currtok.Type;

			s32 idx = tokens.Idx;
			s32 level = 0;
			for ( ; idx < array_num(tokens.Arr); idx ++ )
			{
				if ( tokens.Arr[idx].Type == Tok_BraceCurly_Open )
					level++;

				if ( tokens.Arr[idx].Type == Tok_BraceCurly_Close )
					level--;

				if ( level == 0 && tokens.Arr[idx].Type == Tok_Statement_End )
					break;
			}

			Token pre_foward_tok = currtok;
			if ( (idx - 3 ) == tokens.Idx )
			{
				// Its a forward declaration only
				type = parse_forward_or_definition( which, from_typedef );
				// <ModuleFalgs> typedef <UnderlyingType: Forward Decl>
			}
			else
			{
				Token tok = tokens.Arr[ idx - 1 ];
				if ( tok.Type == Tok_Identifier )
				{
					log_fmt("Found id\n");
					tok = tokens.Arr[ idx - 2 ];

					bool is_indirection = tok.Type == Tok_Ampersand
					||                    tok.Type == Tok_Star;

					bool ok_to_parse = false;

					Token temp_3 = tokens.Arr[ idx - 3 ];

					if ( tok.Type == Tok_BraceCurly_Close )
					{
						// Its an inplace definition
						// typedef <which> <type_identifier> { ... } <identifier>;
						ok_to_parse = true;
					}
					else if ( tok.Type == Tok_Identifier && tokens.Arr[ idx - 3 ].Type == which )
					{
						// Its a variable with type ID using which namespace.
						// typedef <which> <type_identifier> <identifier>;
						ok_to_parse = true;
					}
					else if ( is_indirection )
					{
						// Its a indirection type with type ID using struct namespace.
						// typedef <which> <type_identifier>* <identifier>;
						ok_to_parse = true;
					}

					if ( ! ok_to_parse )
					{
						log_failure( "Unsupported or bad member definition after struct declaration\n%SB", parser_to_strbuilder(_ctx->parser) );
						parser_pop(& _ctx->parser);
						return InvalidCode;
					}

					// TODO(Ed) : I'm not sure if I have to use parser_parse_type here, I'd rather not as that would complicate parser_parse_type.
					// type = parser_parse_type();
					type = parse_forward_or_definition( which, from_typedef );
					// <ModuleFalgs> typedef <UnderlyingType>
				}
				else if ( tok.Type == Tok_BraceCurly_Close )
				{
					// Its a definition
					// <which> { ... };
					type = parse_forward_or_definition( currtok.Type, from_typedef );
					// <ModuleFalgs> typedef <UnderlyingType>
				}
				else if ( tok.Type == Tok_BraceSquare_Close)
				{
					// Its an array definition
					// <which> <type_identifier> <identifier> [ ... ];
					type = cast(Code, parser_parse_type(parser_not_from_template, nullptr));
					// <ModuleFalgs> typedef <UnderlyingType>
				}
				else
				{
					log_failure( "Unsupported or bad member definition after struct declaration\n%SB", parser_to_strbuilder(_ctx->parser) );
					parser_pop(& _ctx->parser);
					return InvalidCode;
				}
			}
		}
		else
		{
			bool from_template = false;
			type = cast(Code, parser_parse_type( from_template, &is_function ));
			// <ModuleFalgs> typedef <UnderlyingType>
		}

		if ( check( Tok_Identifier ) )
		{
			name = currtok;
			eat( Tok_Identifier );
			// <ModuleFalgs> typedef <UnderlyingType> <Name>
		}
		else if ( ! is_function )
		{
			log_failure( "Error, expected identifier for typedef\n%SB", parser_to_strbuilder(_ctx->parser) );
			parser_pop(& _ctx->parser);
			return InvalidCode;
		}

		array_expr = parse_array_decl();
		// <UnderlyingType> + <ArrayExpr>
	}

	Token stmt_end = currtok;
	eat( Tok_Statement_End );
	// <ModuleFalgs> typedef <UnderlyingType> <Name>;

	CodeComment inline_cmt = NullCode;
	if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line )
		inline_cmt = parse_comment();
		// <ModuleFalgs> typedef <UnderlyingType> <Name> <ArrayExpr>; <InlineCmt>

	CodeTypedef
	result              = (CodeTypedef) make_code();
	result->Type        = CT_Typedef;
	result->ModuleFlags = mflags;

	if ( is_function )
	{
		result->Name       = type->Name;
		result->IsFunction = true;
	}
	else
	{
		result->Name       = cache_str( name.Text );
		result->IsFunction = false;
	}

	if ( type )
	{
		result->UnderlyingType         = type;
		result->UnderlyingType->Parent = cast(Code, result);
	}
	// Type needs to be aware of its parent so that it can be serialized properly.

	if ( type->Type == CT_Typename && array_expr && array_expr->Type != CT_Invalid )
		cast(CodeTypename, type)->ArrExpr = array_expr;

	if ( inline_cmt )
		result->InlineCmt = inline_cmt;

	parser_pop(& _ctx->parser);
	return result;
}

internal neverinline
CodeUnion parser_parse_union( bool inplace_def )
{
	push_scope();

	ModuleFlag mflags = ModuleFlag_None;

	if ( check(Tok_Module_Export) )
	{
		mflags = ModuleFlag_Export;
		eat( Tok_Module_Export );
	}
	// <ModuleFlags>

	eat( Tok_Decl_Union );
	// <ModuleFlags> union

	CodeAttributes attributes = parse_attributes();
	// <ModuleFlags> union <Attributes>

	Str name = { nullptr, 0 };
	if ( check( Tok_Identifier ) )
	{
		name = currtok.Text;
		_ctx->parser.Scope->Name = currtok.Text;
		eat( Tok_Identifier );
	}
	// <ModuleFlags> union <Attributes> <Name>

	CodeBody body = { nullptr };

	if ( ! inplace_def || ! check(Tok_Identifier) )
	{
		eat( Tok_BraceCurly_Open );
		// <ModuleFlags> union <Attributes> <Name> {

		body = cast(CodeBody, make_code());
		body->Type = CT_Union_Body;

		while ( ! check_noskip( Tok_BraceCurly_Close ) )
		{
			if ( currtok_noskip.Type == Tok_Preprocess_Hash )
				eat( Tok_Preprocess_Hash );

			Code member = { nullptr };
			switch ( currtok_noskip.Type )
			{
				case Tok_NewLine:
					member = fmt_newline;
					eat( Tok_NewLine );
				break;

				case Tok_Comment:
					member = cast(Code, parse_comment());
				break;

				// TODO(Ed) : Unions can have constructors and destructors

				case Tok_Decl_Class:
					member = parse_complicated_definition( Tok_Decl_Class );
				break;

				case Tok_Decl_Enum:
					member = parse_complicated_definition( Tok_Decl_Enum );
				break;

				case Tok_Decl_Struct:
					member = parse_complicated_definition( Tok_Decl_Struct );
				break;

				case Tok_Decl_Union:
					member = parse_complicated_definition( Tok_Decl_Union );
				break;

				case Tok_Preprocess_Define:
					member = cast(Code, parser_parse_define());
				break;

				case Tok_Preprocess_If:
				case Tok_Preprocess_IfDef:
				case Tok_Preprocess_IfNotDef:
				case Tok_Preprocess_ElIf:
					member = cast(Code, parse_preprocess_cond());
				break;

				case Tok_Preprocess_Else:
					member = cast(Code, preprocess_else);
					eat( Tok_Preprocess_Else );
				break;

				case Tok_Preprocess_EndIf:
					member = cast(Code, preprocess_endif);
					eat( Tok_Preprocess_EndIf );
				break;

				case Tok_Preprocess_Macro_Typename:
					// Its a variable with a macro typename
					member = cast(Code, parser_parse_variable());
				break;

				case Tok_Preprocess_Macro_Stmt:
					member = parse_simple_preprocess( Tok_Preprocess_Macro_Stmt );
				break;

				case Tok_Preprocess_Pragma:
					member = cast(Code, parse_pragma());
				break;

				case Tok_Preprocess_Unsupported:
					member = parse_simple_preprocess( Tok_Preprocess_Unsupported );
				break;

				default:
					member = cast(Code, parser_parse_variable());
				break;
			}

			if ( member )
				body_append(body, member );
		}
		// <ModuleFlags> union <Attributes> <Name> { <Body>

		eat( Tok_BraceCurly_Close );
		// <ModuleFlags> union <Attributes> <Name> { <Body> }
	}

	if ( ! inplace_def )
		eat( Tok_Statement_End );
		// <ModuleFlags> union <Attributes> <Name> { <Body> };

	CodeUnion
	result = (CodeUnion) make_code();
	result->Type        = body ? CT_Union : CT_Union_Fwd;
	result->ModuleFlags = mflags;

	if ( name.Len )
		result->Name = cache_str( name );

	result->Body       = body;
	result->Attributes = attributes;

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeUsing parser_parse_using()
{
	push_scope();

	Specifier specs_found[16] = { Spec_Invalid };
	s32        NumSpecifiers = 0;

	Token        name       = NullToken;
	Code         array_expr = { nullptr };
	CodeTypename type       = { nullptr };

	bool is_namespace = false;

	ModuleFlag     mflags     = ModuleFlag_None;
	CodeAttributes attributes = { nullptr };

	if ( check(Tok_Module_Export) )
	{
		mflags = ModuleFlag_Export;
		eat( Tok_Module_Export );
	}
	// <ModuleFlags>

	eat( Tok_Decl_Using );
	// <ModuleFlags> using

	if ( currtok.Type == Tok_Decl_Namespace ) 
	{
		is_namespace = true;
		eat( Tok_Decl_Namespace );
		// <ModuleFlags> using namespace
	}

	name = currtok;
	_ctx->parser.Scope->Name = name.Text;
	eat( Tok_Identifier );
	// <ModuleFlags> using <namespace> <Name>

	if ( ! is_namespace )
	{
		if ( bitfield_is_set( u32, currtok.Flags, TF_Assign ) )
		{
			attributes = parse_attributes();
			// <ModuleFlags> using <Name> <Attributes>

			eat( Tok_Operator );
			// <ModuleFlags> using <Name> <Attributes> =

			type = parser_parse_type(parser_not_from_template, nullptr);
			// <ModuleFlags> using <Name> <Attributes> = <UnderlyingType>

			array_expr = parse_array_decl();
			// <UnderlyingType> + <ArrExpr>
		}
	}

	Token stmt_end = currtok;
	eat( Tok_Statement_End );
	// <ModuleFlags> using <namespace> <Attributes> <Name> = <UnderlyingType>;

	CodeComment inline_cmt = NullCode;
	if ( currtok_noskip.Type == Tok_Comment && currtok_noskip.Line == stmt_end.Line ) {
		inline_cmt = parse_comment();
	}
	// <ModuleFlags> using <namespace> <Attributes> <Name> = <UnderlyingType>; <InlineCmt>

	CodeUsing
	result              = (CodeUsing) make_code();
	result->Name        = cache_str( name.Text );
	result->ModuleFlags = mflags;

	if ( is_namespace)
	{
		result->Type = CT_Using_Namespace;
	}
	else
	{
		result->Type = CT_Using;

		if ( type )
			result->UnderlyingType = type;

		if ( array_expr )
			type->ArrExpr = array_expr;

		if ( attributes )
			result->Attributes = attributes;

		if ( inline_cmt )
			result->InlineCmt = inline_cmt;
	}

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeVar parser_parse_variable()
{
	push_scope();

	Specifier specs_found[16] = { Spec_NumSpecifiers };
	s32       NumSpecifiers = 0;

	ModuleFlag	   mflags     = ModuleFlag_None;
	CodeAttributes attributes = { nullptr };
	CodeSpecifiers specifiers = { nullptr };

	if ( check(Tok_Module_Export) ) {
		mflags = ModuleFlag_Export;
		eat( Tok_Module_Export );
	}
	// <ModuleFlags>

	attributes = parse_attributes();
	// <ModuleFlags> <Attributes>

	while ( left && tok_is_specifier(currtok) )
	{
		Specifier spec = str_to_specifier( currtok.Text );
		switch  ( spec )
		{
			GEN_PARSER_VARIABLE_ALLOWED_SPECIFIER_CASES:
			break;

			default:
				log_failure( "Invalid specifier %S for variable\n%S", spec_to_str( spec ), strbuilder_to_str( parser_to_strbuilder(_ctx->parser)) );
				parser_pop(& _ctx->parser);
				return InvalidCode;
		}

		// Ignore const specifiers, they're handled by the type
		if ( spec == Spec_Const )
			break;

		specs_found[NumSpecifiers] = spec;
		NumSpecifiers++;
		eat( currtok.Type );
	}

	if ( NumSpecifiers ) {
		specifiers = def_specifiers_arr( NumSpecifiers, specs_found );
	}
	// <ModuleFlags> <Attributes> <Specifiers>

	CodeTypename type = parser_parse_type(parser_not_from_template, nullptr);
	// <ModuleFlags> <Attributes> <Specifiers> <ValueType>

	if ( cast(Code, type) == Code_Invalid )
		return InvalidCode;

	_ctx->parser.Scope->Name = parse_identifier(nullptr).Text;
	// <ModuleFlags> <Attributes> <Specifiers> <ValueType> <Name>

	CodeVar result = parse_variable_after_name( mflags, attributes, specifiers, type, _ctx->parser.Scope->Name );
	// Regular  : <ModuleFlags> <Attributes> <Specifiers> <ValueType> <Name>                  = <Value>; <InlineCmt>
	// Bitfield : <ModuleFlags> <Attributes> <Specifiers> <ValueType> <Name> : <BitfieldSize> = <Value>; <InlineCmt>

	parser_pop(& _ctx->parser);
	return result;
}

internal
CodeTypename parser_parse_type_alt( bool from_template, bool* typedef_is_functon )
{
	return InvalidCode;
}

#ifdef CHECK_WAS_DEFINED
#pragma pop_macro("check")
#endif

// Publically Exposed Interface

CodeClass parse_class( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	push_scope();
	CodeClass result = (CodeClass) parse_class_struct( Tok_Decl_Class, parser_not_inplace_def );
	parser_pop(& _ctx->parser);
	return result;
}

CodeConstructor parse_constructor( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	// TODO(Ed): Constructors can have prefix attributes

	CodeSpecifiers specifiers = NullCode;
	Specifier      specs_found[ 16 ] = { Spec_NumSpecifiers };
	s32            NumSpecifiers = 0;

	while ( left && tok_is_specifier(currtok) )
	{
		Specifier spec = str_to_specifier( currtok.Text );

		b32 ignore_spec = false;

		switch ( spec )
		{
			case Spec_Constexpr :
			case Spec_Explicit:
			case Spec_Inline :
			case Spec_ForceInline :
			case Spec_NeverInline :
				break;

			case Spec_Const :
				ignore_spec = true;
				break;

			default :
				log_failure( "Invalid specifier %s for variable\n%S", spec_to_str( spec ), parser_to_strbuilder(_ctx->parser) );
				parser_pop(& _ctx->parser);
				return InvalidCode;
		}

		// Every specifier after would be considered part of the type type signature
		if (ignore_spec)
			break;

		specs_found[ NumSpecifiers ] = spec;
		NumSpecifiers++;
		eat( currtok.Type );
	}

	if ( NumSpecifiers )
	{
		specifiers = def_specifiers_arr( NumSpecifiers, specs_found );
		// <specifiers> ...
	}

	_ctx->parser.Tokens         = toks;
	CodeConstructor result = parser_parse_constructor( specifiers );
	return result;
}

CodeDefine parse_define( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	push_scope();
	CodeDefine result = parser_parse_define();
	parser_pop(& _ctx->parser);
	return result;
}

CodeDestructor parse_destructor( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	// TODO(Ed): Destructors can have prefix attributes
	// TODO(Ed): Destructors can have virtual

	_ctx->parser.Tokens        = toks;
	CodeDestructor result = parser_parse_destructor(NullCode);
	return result;
}

CodeEnum parse_enum( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
	{
		parser_pop(& _ctx->parser);
		return InvalidCode;
	}

	_ctx->parser.Tokens = toks;
	return parser_parse_enum( parser_not_inplace_def);
}

CodeBody parse_export_body( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_export_body();
}

CodeExtern parse_extern_link( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_extern_link();
}

CodeFriend parse_friend( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_friend();
}

CodeFn parse_function( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return (CodeFn) parser_parse_function();
}

CodeBody parse_global_body( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	push_scope();
	CodeBody result = parse_global_nspace( CT_Global_Body );
	parser_pop(& _ctx->parser);
	return result;
}

CodeNS parse_namespace( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_namespace();
}

CodeOperator parse_operator( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return (CodeOperator) parser_parse_operator();
}

CodeOpCast parse_operator_cast( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_operator_cast(NullCode);
}

CodeStruct parse_struct( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	push_scope();
	CodeStruct result = (CodeStruct) parse_class_struct( Tok_Decl_Struct, parser_not_inplace_def );
	parser_pop(& _ctx->parser);
	return result;
}

CodeTemplate parse_template( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_template();
}

CodeTypename parse_type( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_type( parser_not_from_template, nullptr);
}

CodeTypedef parse_typedef( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_typedef();
}

CodeUnion parse_union( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_union( parser_not_inplace_def);
}

CodeUsing parse_using( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_using();
}

CodeVar parse_variable( Str def )
{
	check_parse_args( def );

	TokArray toks = lex( def );
	if ( toks.Arr == nullptr )
		return InvalidCode;

	_ctx->parser.Tokens = toks;
	return parser_parse_variable();
}

// Undef helper macros
#undef check_parse_args
#undef currtok_noskip
#undef currtok
#undef peektok
#undef prevtok
#undef nexttok
#undef nexttok_noskip
#undef eat
#undef left
#undef check
#undef push_scope
#undef def_assign

// Here for C Variant
#undef lex_dont_skip_formatting
#undef lex_skip_formatting

#undef parser_inplace_def
#undef parser_not_inplace_def
#undef parser_dont_consume_braces
#undef parser_consume_braces
#undef parser_not_from_template
#undef parser_use_parenthesis
#undef parser_strip_formatting_dont_preserve_newlines

#pragma endregion Parsing


#pragma region Untyped


ssize token_fmt_va( char* buf, usize buf_size, s32 num_tokens, va_list va )
{
	char const* buf_begin = buf;
	ssize       remaining = buf_size;

	if (_ctx->token_fmt_map.Hashes == nullptr) {
		_ctx->token_fmt_map = hashtable_init(Str, _ctx->Allocator_DyanmicContainers );
	}
	// Populate token pairs
	{
		s32 left = num_tokens - 1;

		while ( left-- )
		{
			char const* token = va_arg( va, char const* );
			Str         value = va_arg( va, Str );

			u32 key = crc32( token, c_str_len(token) );
			hashtable_set( _ctx->token_fmt_map, key, value );
		}
	}

	char const* fmt     = va_arg( va, char const* );
	char        current = *fmt;

	while ( current )
	{
		ssize len = 0;

		while ( current && current != '<' && remaining )
		{
			* buf = * fmt;
			buf++;
			fmt++;
			remaining--;

			current = * fmt;
		}

		if ( current == '<' )
		{
			char const* scanner = fmt + 1;

			s32 tok_len = 0;

			while ( *scanner != '>' )
			{
				tok_len++;
				scanner++;
			}

			char const* token = fmt + 1;

			u32      key   = crc32( token, tok_len );
			Str*     value = hashtable_get(_ctx->token_fmt_map, key );

			if ( value )
			{
				ssize          left = value->Len;
				char const* str  = value->Ptr;

				while ( left-- )
				{
					* buf = * str;
					buf++;
					str++;
					remaining--;
				}

				scanner++;
				fmt     = scanner;
				current = * fmt;
				continue;
			}

			* buf = * fmt;
			buf++;
			fmt++;
			remaining--;

			current = * fmt;
		}
	}
	hashtable_clear(_ctx->token_fmt_map);
	ssize result = buf_size - remaining;
	return result;
}

Code untyped_str( Str content )
{
	if ( content.Len == 0 )
	{
		log_failure( "untyped_str: empty string" );
		return InvalidCode;
	}

	Code
	result          = make_code();
	result->Name    = cache_str( content );
	result->Type    = CT_Untyped;
	result->Content = result->Name;

	if ( result->Name.Len == 0 )
	{
		log_failure( "untyped_str: could not cache string" );
		return InvalidCode;
	}

	return result;
}

Code untyped_fmt( char const* fmt, ...)
{
	if ( fmt == nullptr )
	{
		log_failure( "untyped_fmt: null format string" );
		return InvalidCode;
	}

	local_persist thread_local
	char buf[GEN_PRINTF_MAXLEN] = { 0 };

	va_list va;
	va_start(va, fmt);
	ssize length = c_str_fmt_va(buf, GEN_PRINTF_MAXLEN, fmt, va);
	va_end(va);
    Str content = { buf, length };

	Code
	result          = make_code();
	result->Type    = CT_Untyped;
	result->Content = cache_str( content );

	if ( result->Name.Len == 0 )
	{
		log_failure( "untyped_fmt: could not cache string" );
		return InvalidCode;
	}

	return result;
}

Code untyped_token_fmt( s32 num_tokens, char const* fmt, ... )
{
	if ( num_tokens == 0 )
	{
		log_failure( "untyped_token_fmt: zero tokens" );
		return InvalidCode;
	}

	local_persist thread_local
	char buf[GEN_PRINTF_MAXLEN] = { 0 };

	va_list va;
	va_start(va, fmt);
	ssize length = token_fmt_va(buf, GEN_PRINTF_MAXLEN, num_tokens, va);
	va_end(va);

	Str buf_str = { buf, length };

	Code
	result          = make_code();
	result->Type    = CT_Untyped;
	result->Content = cache_str( buf_str );

	if ( result->Name.Len == 0 )
	{
		log_failure( "untyped_fmt: could not cache string" );
		return InvalidCode;
	}

	return result;
}
#pragma endregion 

#pragma endregion Interface

GEN_NS_END

#ifdef __clang__
#	pragma clang diagnostic pop
#endif

#ifdef __GNUC__
#	pragma GCC diagnostic pop
#endif
