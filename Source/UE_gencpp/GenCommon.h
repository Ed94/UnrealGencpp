#pragma once

// TODO(Ed): Make custom core minimal
#include "CoreMinimal.h"
#include "Gasa/GasaCommon.h"

#pragma region Engine Forwards
#pragma endregion Engine Forwards

#pragma region Engine Plugin Forwards
#pragma endregion Engine Plugin Forwards

// Gasa Editor

#pragma region Forwards
#pragma endregion Forwards

#pragma region Logging
DECLARE_LOG_CATEGORY_EXTERN(LogGencpp, Log, All);

namespace gen
{
	using ELogV = EGasaVerbosity;

	//◞ ‸ ◟//
	// Works for Unreal 5.4, Win64 MSVC (untested in other scenarios, for now)
	inline
	void LogEditor( FString Message, EGasaVerbosity Verbosity = EGasaVerbosity::Log
		, FLogCategoryBase& Category  = LogGasaEditor
		, bool              DumpStack = false
		, int32             Line      = __builtin_LINE()
		, const ANSICHAR*   File      = __builtin_FILE()
		, const ANSICHAR*   Func      = __builtin_FUNCTION() )
	{
	#if !UE_BUILD_SHIPPING && !NO_LOGGING
		ELogVerbosity::Type EngineVerbosity = (ELogVerbosity::Type) Verbosity;

		static UE::Logging::Private::FStaticBasicLogDynamicData LOG_Dynamic;
		static UE::Logging::Private::FStaticBasicLogRecord
		LOG_Static(TEXT("%80s -- %hs %hs(%d)"), File, Line, EngineVerbosity, LOG_Dynamic);

		if ((EngineVerbosity & ELogVerbosity::VerbosityMask) <= ELogVerbosity::COMPILED_IN_MINIMUM_VERBOSITY)
		{
			if ((EngineVerbosity & ELogVerbosity::VerbosityMask) <= Category.GetVerbosity())
			{
				if ( ! Category.IsSuppressed(EngineVerbosity))
				{
					if (DumpStack)
						FDebug::DumpStackTraceToLog(EngineVerbosity);
					BasicLog(Category, &LOG_Static, *Message, File, Func, Line);
				}
			}
		}
	#endif
	}
}

#define GencppEd_Fatal(Message)       UE_LOG( LogGencpp, Fatal,       TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_FILE(), __func__, __builtin_LINE()  );
#define GencppEd_Error(Message)       UE_LOG( LogGencpp, Error,       TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#define GencppEd_Warning(Message)     UE_LOG( LogGencpp, Warning,     TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#define GencppEd_Display(Message)     UE_LOG( LogGencpp, Display,     TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#define GencppEd_Log(Message)         UE_LOG( LogGencpp, Log,         TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#define GencppEd_Verbose(Message)     UE_LOG( LogGencpp, Verbose,     TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#define GencppEd_VeryVerbose(Message) UE_LOG( LogGencpp, VeryVerbose, TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#pragma endregion Logging

#pragma region Timing
#pragma endregion Timing

UE_DISABLE_OPTIMIZATION
#include "gencpp/gen.hpp"
#include "gencpp/gen.builder.hpp"
UE_ENABLE_OPTIMIZATION
using namespace gen;

constexpr StrC str_DECLARE_CLASS                                         = txt("DECLARE_CLASS(");
constexpr StrC str_DECLARE_DELEGATE_RetVal_OneParam                      = txt("DECLARE_DELEGATE_RetVal_OneParam(");
constexpr StrC str_DECLARE_DELEGATE_RetVal_ThreeParams                   = txt("DECLARE_DELEGATE_RetVal_ThreeParams(");
constexpr StrC str_DECLARE_DELEGATE_SixParams                            = txt("DECLARE_DELEGATE_SixParams(");
constexpr StrC str_DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam           = txt("DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(");
constexpr StrC str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FiveParams  = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FiveParams(");
constexpr StrC str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams  = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(");
constexpr StrC str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_NineParams  = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_NineParams(");
constexpr StrC str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam    = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(");
constexpr StrC str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_SevenParams = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_SevenParams(");
constexpr StrC str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams   = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(");
constexpr StrC str_DECLARE_EVENT_ThreeParams                             = txt("DECLARE_EVENT_ThreeParams(");
constexpr StrC str_DECLARE_EVENT_TwoParams                               = txt("DECLARE_EVENT_TwoParams(");
constexpr StrC str_DECLARE_FUNCTION                                      = txt("DECLARE_FUNCTION(");
constexpr StrC str_DECLARE_LOG_CATEGORY_EXTERN                           = txt("DECLARE_LOG_CATEGORY_EXTERN(");
constexpr StrC str_DECLARE_MULTICAST_DELEGATE_OneParam                   = txt("DECLARE_MULTICAST_DELEGATE_OneParam(");
constexpr StrC str_DECLARE_MULTICAST_DELEGATE_ThreeParams                = txt("DECLARE_MULTICAST_DELEGATE_ThreeParams(");
constexpr StrC str_DECLARE_MULTICAST_DELEGATE_TwoParams                  = txt("DECLARE_MULTICAST_DELEGATE_TwoParams(");
constexpr StrC str_DECLARE_TS_MULTICAST_DELEGATE_OneParam                = txt("DECLARE_TS_MULTICAST_DELEGATE_OneParam(");
constexpr StrC str_DECLARE_TS_MULTICAST_DELEGATE_TwoParams               = txt("DECLARE_TS_MULTICAST_DELEGATE_TwoParams(");
constexpr StrC str_DECLARE_TS_MULTICAST_DELEGATE_ThreeParams             = txt("DECLARE_TS_MULTICAST_DELEGATE_ThreeParams(");
constexpr StrC str_DEFINE_ACTORDESC_TYPE                                 = txt("DEFINE_ACTORDESC_TYPE(");
constexpr StrC str_DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL    = txt("DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(");
constexpr StrC str_ENUM_CLASS_FLAGS                                      = txt("ENUM_CLASS_FLAGS(");
// constexpr StrC str_FORCEINLINE                                           = txt("FORCEINLINE");
constexpr StrC str_FORCEINLINE_DEBUGGABLE                                = txt("FORCEINLINE_DEBUGGABLE");
constexpr StrC str_GENERATED_BODY                                        = txt("GENERATED_BODY(");
constexpr StrC str_GENERATED_UCLASS_BODY                                 = txt("GENERATED_UCLASS_BODY(");
constexpr StrC str_GENERATED_USTRUCT_BODY                                = txt("GENERATED_USTRUCT_BODY(");
constexpr StrC str_PRAGMA_DISABLE_DEPRECATION_WARNINGS                   = txt("PRAGMA_DISABLE_DEPRECATION_WARNINGS");
constexpr StrC str_PRAGMA_ENABLE_DEPRECATION_WARNINGS                    = txt("PRAGMA_ENABLE_DEPRECATION_WARNINGS");
constexpr StrC str_PROPERTY_BINDING_IMPLEMENTATION                       = txt("PROPERTY_BINDING_IMPLEMENTATION(");
constexpr StrC str_RESULT_DECL                                           = txt("RESULT_DECL");
constexpr StrC str_SLATE_BEGIN_ARGS                                      = txt("SLATE_BEGIN_ARGS(");
constexpr StrC str_SLATE_END_ARGS                                        = txt("SLATE_END_ARGS(");
constexpr StrC str_TEXT                                                  = txt("TEXT(");
constexpr StrC str_UCLASS                                                = txt("UCLASS(");
constexpr StrC str_UENUM                                                 = txt("UENUM(");
constexpr StrC str_UFUNCTION                                             = txt("UFUNCTION(");
constexpr StrC str_UMETA                                                 = txt("UMETA(");
constexpr StrC str_UPARAM                                                = txt("UPARAM(");
constexpr StrC str_UPROPERTY                                             = txt("UPROPERTY(");
constexpr StrC str_USTRUCT                                               = txt("USTRUCT(");
constexpr StrC str_UE_REQUIRES                                           = txt("UE_REQUIRES(");

#pragma region Globals
extern String Project_Path;
extern String Root_Path;

// These Code objects are created before anything else after gencpp does its initializatioon
extern Code UHT_GENERATED_BODY;
extern Code UHT_UCLASS;
extern Code UHT_UPROPERTY;
extern Code UHT_USTRUCT;
extern Code UModule_GENCPP_API;
#pragma endregion Globals

inline
CodeBody parse_file( char const* path ) {
	String
	resolved_path = String::make(GlobalAllocator, StrC(Project_Path));
	resolved_path.append(path);

	FileContents content = file_read_contents( GlobalAllocator, true, resolved_path );
	CodeBody     code    = parse_global_body( StrC { content.size, (char const*)content.data });
	return code;
}

// Automatically handles resolving project path
inline
Builder builder_open(char const* path) {
	String
	resolved_path = String::make(GlobalAllocator, StrC(Project_Path));
	resolved_path.append(path);
	return Builder::open( resolved_path );
}

inline
void format_file( char const* path, bool relative_path = true )
{
	String
	resolved_path = String::make_reserve(GlobalAllocator, Project_Path.length());
	if (relative_path)
		resolved_path.append(StrC(Project_Path));
	resolved_path.append(path);

	String style_arg = String::make(GlobalAllocator, txt("-style=file:"));
	style_arg.append(Root_Path);
	style_arg.append("/scripts/.clang-format ");

	// Need to execute clang format on the generated file to get it to match the original.
	#define clang_format      "clang-format "
	#define cf_format_inplace "-i "
	#define cf_verbose        "-verbose "
	String command = String::make( GlobalAllocator, clang_format );
	command.append( cf_format_inplace );
	command.append( cf_verbose );
	command.append( style_arg );
	command.append( resolved_path );
		log_fmt("\tRunning clang-format on file:\n");
		system( command );
		log_fmt("\tclang-format finished reformatting.\n");
	#undef cf_cmd
	#undef cf_format_inplace
	#undef cf_style
	#undef cf_verbse
}

FORCEINLINE
String to_string( FString ue_string ) { 
	char const* ansi_str = TCHAR_TO_ANSI(*ue_string);
	return String::make_length(GlobalAllocator, ansi_str, ue_string.Len());
}

FORCEINLINE
String to_string( FName ue_fname ) { 
	char const* ansi_str = TCHAR_TO_ANSI(*ue_fname.ToString());
	return String::make_length(GlobalAllocator, ansi_str, ue_fname.GetStringLength());
}

FORCEINLINE
FString to_fstring( String string )
{
	return FString::ConstructFromPtrSize( string.Data, string.length() );
}
