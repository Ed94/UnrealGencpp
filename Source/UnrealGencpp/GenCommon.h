#pragma once
#include "GenEngineMinimal.h"

UE_DISABLE_OPTIMIZATION
#include "gencpp/gen.hpp"
#include "gencpp/gen.builder.hpp"
UE_ENABLE_OPTIMIZATION

namespace Gencpp = gen;
namespace GENCPP = gen;

GEN_NS_BEGIN

constexpr Str str_UDELEGATE                                             = txt("UDELEGATE");
constexpr Str str_DECLARE_CLASS                                         = txt("DECLARE_CLASS");
constexpr Str str_DECLARE_CYCLE_STAT_EXTERN                             = txt("DECLARE_CYCLE_STAT_EXTERN");
constexpr Str str_DECLARE_DELEGATE                                      = txt("DECLARE_DELEGATE");
constexpr Str str_DECLARE_DELEGATE_RetVal_OneParam                      = txt("DECLARE_DELEGATE_RetVal_OneParam");
constexpr Str str_DECLARE_DELEGATE_RetVal_ThreeParams                   = txt("DECLARE_DELEGATE_RetVal_ThreeParams");
constexpr Str str_DECLARE_DELEGATE_RetVal_SevenParams                   = txt("DECLARE_DELEGATE_RetVal_SevenParams");
constexpr Str str_DECLARE_DELEGATE_OneParam                             = txt("DECLARE_DELEGATE_OneParam");
constexpr Str str_DECLARE_DELEGATE_TwoParams                            = txt("DECLARE_DELEGATE_TwoParams");
constexpr Str str_DECLARE_DELEGATE_ThreeParams                          = txt("DECLARE_DELEGATE_ThreeParams");
constexpr Str str_DECLARE_DELEGATE_FourParams                           = txt("DECLARE_DELEGATE_FourParams");
constexpr Str str_DECLARE_DELEGATE_SixParams                            = txt("DECLARE_DELEGATE_SixParams");
constexpr Str str_DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam           = txt("DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam");
constexpr Str str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FiveParams  = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FiveParams");
constexpr Str str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams  = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams");
constexpr Str str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_NineParams  = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_NineParams");
constexpr Str str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam    = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam");
constexpr Str str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_SevenParams = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_SevenParams");
constexpr Str str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams   = txt("DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams");
constexpr Str str_DECLARE_EVENT                                         = txt("DECLARE_EVENT");
constexpr Str str_DECLARE_EVENT_OneParam                                = txt("DECLARE_EVENT_OneParam");
constexpr Str str_DECLARE_EVENT_FourParams                              = txt("DECLARE_EVENT_FourParams");
constexpr Str str_DECLARE_EVENT_ThreeParams                             = txt("DECLARE_EVENT_ThreeParams");
constexpr Str str_DECLARE_EVENT_TwoParams                               = txt("DECLARE_EVENT_TwoParams");
constexpr Str str_DECLARE_FUNCTION                                      = txt("DECLARE_FUNCTION");
constexpr Str str_DECLARE_LOG_CATEGORY_EXTERN                           = txt("DECLARE_LOG_CATEGORY_EXTERN");
constexpr Str str_DECLARE_MULTICAST_DELEGATE                            = txt("DECLARE_MULTICAST_DELEGATE");
constexpr Str str_DECLARE_MULTICAST_DELEGATE_OneParam                   = txt("DECLARE_MULTICAST_DELEGATE_OneParam");
constexpr Str str_DECLARE_MULTICAST_DELEGATE_ThreeParams                = txt("DECLARE_MULTICAST_DELEGATE_ThreeParams");
constexpr Str str_DECLARE_MULTICAST_DELEGATE_TwoParams                  = txt("DECLARE_MULTICAST_DELEGATE_TwoParams");
constexpr Str str_DECLARE_STATS_GROUP                                   = txt("DECLARE_STATS_GROUP");
constexpr Str str_DECLARE_TS_MULTICAST_DELEGATE_OneParam                = txt("DECLARE_TS_MULTICAST_DELEGATE_OneParam");
constexpr Str str_DECLARE_TS_MULTICAST_DELEGATE_TwoParams               = txt("DECLARE_TS_MULTICAST_DELEGATE_TwoParams");
constexpr Str str_DECLARE_TS_MULTICAST_DELEGATE_ThreeParams             = txt("DECLARE_TS_MULTICAST_DELEGATE_ThreeParams");
constexpr Str str_DEFINE_ACTORDESC_TYPE                                 = txt("DEFINE_ACTORDESC_TYPE");
constexpr Str str_DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL    = txt("DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL");
constexpr Str str_ENUM_CLASS_FLAGS                                      = txt("ENUM_CLASS_FLAGS");
constexpr Str str_GENERATED_BODY                                        = txt("GENERATED_BODY");
constexpr Str str_GENERATED_UCLASS_BODY                                 = txt("GENERATED_UCLASS_BODY");
constexpr Str str_GENERATED_USTRUCT_BODY                                = txt("GENERATED_USTRUCT_BODY");
constexpr Str str_PRAGMA_DISABLE_DEPRECATION_WARNINGS                   = txt("PRAGMA_DISABLE_DEPRECATION_WARNINGS");
constexpr Str str_PRAGMA_ENABLE_DEPRECATION_WARNINGS                    = txt("PRAGMA_ENABLE_DEPRECATION_WARNINGS");
constexpr Str str_PROPERTY_BINDING_IMPLEMENTATION                       = txt("PROPERTY_BINDING_IMPLEMENTATION");
constexpr Str str_RESULT_DECL                                           = txt("RESULT_DECL");
constexpr Str str_SLATE_BEGIN_ARGS                                      = txt("SLATE_BEGIN_ARGS");
constexpr Str str_SLATE_END_ARGS                                        = txt("SLATE_END_ARGS");
constexpr Str str_TEXT                                                  = txt("TEXT");
constexpr Str str_UCLASS                                                = txt("UCLASS");
constexpr Str str_UENUM                                                 = txt("UENUM");
constexpr Str str_UFUNCTION                                             = txt("UFUNCTION");
constexpr Str str_UINTERFACE                                            = txt("UINTERFACE");
constexpr Str str_UMETA                                                 = txt("UMETA");
constexpr Str str_UPARAM                                                = txt("UPARAM");
constexpr Str str_UPROPERTY                                             = txt("UPROPERTY");
constexpr Str str_USTRUCT                                               = txt("USTRUCT");
constexpr Str str_UE_REQUIRES                                           = txt("UE_REQUIRES");
constexpr Str str_UE_DEPRECATED                                         = txt("UE_DEPRECATED");
constexpr Str str_UE_DEPRECATED_FORGAME                                 = txt("UE_DEPRECATED_FORGAME");
constexpr Str str_UE_DEPRECATED_FORENGINE                               = txt("str_UE_DEPRECATED_FORENGINE");
constexpr Str str_ACTOR_HAS_LABELS                                      = txt("ACTOR_HAS_LABELS");
constexpr Str str_HIDE_ACTOR_TRANSFORM_FUNCTIONS                        = txt("HIDE_ACTOR_TRANSFORM_FUNCTIONS");
constexpr Str str_SCENECOMPONENT_QUAT_TOLERANCE                         = txt("SCENECOMPONENT_QUAT_TOLERANCE");
constexpr Str str_SCENECOMPONENT_ROTATOR_TOLERANCE                      = txt("SCENECOMPONENT_ROTATOR_TOLERANCE");
constexpr Str str_GAMEPLAYATTRIBUTE_REPNOTIFY                           = txt("GAMEPLAYATTRIBUTE_REPNOTIFY");
constexpr Str str_GAMEPLAYATTRIBUTE_PROPERTY_GETTER                     = txt("GAMEPLAYATTRIBUTE_PROPERTY_GETTER");
constexpr Str str_GAMEPLAYATTRIBUTE_VALUE_GETTER                        = txt("GAMEPLAYATTRIBUTE_VALUE_GETTER");
constexpr Str str_GAMEPLAYATTRIBUTE_VALUE_SETTER                        = txt("GAMEPLAYATTRIBUTE_VALUE_SETTER");
constexpr Str str_GAMEPLAYATTRIBUTE_VALUE_INITTER                       = txt("GAMEPLAYATTRIBUTE_VALUE_INITTER");
constexpr Str str_LOCTEXT_NAMESPACE                                     = txt("LOCTEXT_NAMESPACE");
constexpr Str str_PURE_VIRTUAL                                          = txt("PURE_VIRTUAL");
constexpr Str str_AIMODULE_API                                          = txt("AIMODULE_API");
constexpr Str str_IRISCORE_API                                          = txt("IRISCORE_API");
constexpr Str str_UNREALED_API                                          = txt("UNREALED_API");
constexpr Str str_LYRAGAME_API                                          = txt("LYRAGAME_API");
constexpr Str str_COMMONUI_API                                          = txt("COMMONUI_API");
constexpr Str str_WORLDBROWSER_API                                      = txt("WORLDBROWSER_API");
constexpr Str str_MODULARGAMEPLAY_API                                   = txt("MODULARGAMEPLAY_API");
constexpr Str str_UE_INTERNAL                                           = txt("UE_INTERNAL");
constexpr Str str_OUT                                                   = txt("OUT");
constexpr Str str_IN                                                    = txt("IN");

#pragma region Globals
GEN_API extern Str PathRoot;
GEN_API extern Str PathEngine;
GEN_API extern Str PathEngineConfig;
GEN_API extern Str PathEnginePlugins;
GEN_API extern Str PathEngineIntermediate;
GEN_API extern Str PathProject;
GEN_API extern Str PathProjectConfig;
GEN_API extern Str PathProjectIntermediate;
GEN_API extern Str PathProjectPlugins;

GEN_API extern Str PathUnrealGencpp;

// These Code objects are created before anything else after gencpp does its initializatioon
GEN_API extern Code UHT_GENERATED_BODY;
GEN_API extern Code UHT_UCLASS;
GEN_API extern Code UHT_UPROPERTY;
GEN_API extern Code UHT_USTRUCT;
#pragma region Globals

inline
CodeBody ParseFile( Str Path ) {
	FileContents content = file_read_contents( get_context()->Allocator_Temp, true, Path );
	CodeBody     code    = parse_global_body( Str {  (char const*)content.data, content.size });
	log_fmt("\nParsed: %s\n", Path);
	return code;
}

// inline
// CodeConstructor find_constructor( StrC parent_name, )

GEN_API void ClangFormatFile( Str Path );

FORCEINLINE
Str ToStr( FString String ) { 
	char const* ansi_str = TCHAR_TO_ANSI(*String);
	return StrBuilder::make_length(get_context()->Allocator_Temp, ansi_str, String.Len()).to_str();
}

FORCEINLINE
Str ToStr( FName Name ) { 
	char const* ansi_str = TCHAR_TO_ANSI(* Name.ToString());
	return StrBuilder::make_length(get_context()->Allocator_Temp, ansi_str, Name.GetStringLength()).to_str();
}

FORCEINLINE
FString ToFString( Str String )
{
	return FString::ConstructFromPtrSize( String.Ptr, String.Len );
}

GEN_NS_END

#pragma region Logging
// Straight from the Engine
UENUM(BlueprintType)
enum class EGencppVerbosity : uint8
{
	/** Not used */
	NoLogging		= 0,

	/** Always prints a fatal error to console (and log file) and crashes (even if logging is disabled) */
	// Fatal,
	// Just use GASA_Fatal...

	/** 
	 * Prints an error to console (and log file). 
	 * Commandlets and the editor collect and report errors. Error messages result in commandlet failure.
	 */
	Error = ELogVerbosity::Error,

	/** 
	 * Prints a warning to console (and log file).
	 * Commandlets and the editor collect and report warnings. Warnings can be treated as an error.
	 */
	Warning,

	/** Prints a message to console (and log file) */
	Display,

	/** Prints a message to a log file (does not print to console) */
	Log,

	/** 
	 * Prints a verbose message to a log file (if Verbose logging is enabled for the given category, 
	 * usually used for detailed logging) 
	 */
	Verbose,

	/** 
	 * Prints a verbose message to a log file (if VeryVerbose logging is enabled, 
	 * usually used for detailed logging that would otherwise spam output) 
	 */
	VeryVerbose,
};

DECLARE_LOG_CATEGORY_EXTERN(LogGencpp, Log, All);

namespace gen
{
	using ELogV = EGencppVerbosity;

	// Works for Unreal 5.4, Win64 MSVC (untested in other scenarios, for now)
	inline
	void Log( FString Message
		, ELogV             Verbosity = ELogV::Log
		, FLogCategoryBase& Category  = LogGencpp
		, bool              DumpStack = false
		, int32             Line      = __builtin_LINE()
		, const ANSICHAR*   File      = __builtin_FILE()
		, const ANSICHAR*   Func      = __builtin_FUNCTION() )
	{
	#if !UE_BUILD_SHIPPING && !NO_LOGGING
		ELogVerbosity::Type EngineVerbosity = (ELogVerbosity::Type) Verbosity;

		static UE::Logging::Private::FStaticBasicLogDynamicData LOG_Dynamic;
		static UE::Logging::Private::FStaticBasicLogRecord
		LOG_Static(TEXT("%s -- %hs %hs(%d)"), File, Line, EngineVerbosity, LOG_Dynamic);

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

#define GENCPP_Fatal(Message)       UE_LOG( LogGencpp, Fatal,       TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_FILE(), __func__, __builtin_LINE()  );
#define GENCPP_Error(Message)       UE_LOG( LogGencpp, Error,       TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#define GENCPP_Warning(Message)     UE_LOG( LogGencpp, Warning,     TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#define GENCPP_Display(Message)     UE_LOG( LogGencpp, Display,     TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#define GENCPP_Log(Message)         UE_LOG( LogGencpp, Log,         TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#define GENCPP_Verbose(Message)     UE_LOG( LogGencpp, Verbose,     TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#define GENCPP_VeryVerbose(Message) UE_LOG( LogGencpp, VeryVerbose, TEXT("%s -- %hs %hs(%d)"), *Message, __builtin_File(), __func__, __builtin_LINE()  );
#pragma endregion Logging
