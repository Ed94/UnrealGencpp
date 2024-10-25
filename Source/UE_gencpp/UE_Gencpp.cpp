#include "GenCommon.h"

global String Project_Path;
global String Root_Path;

global Code UHT_GENERATED_BODY;
global Code UHT_UCLASS;
global Code UHT_UPROPERTY;
global Code UHT_USTRUCT;
global Code UModule_GASA_API;

#define LOCTEXT_NAMESPACE "UE_Gencpp"

global String Project_Path;
global String Root_Path;

global Code UHT_GENERATED_BODY;
global Code UHT_UCLASS;
global Code UHT_UPROPERTY;
global Code UHT_USTRUCT;
global Code UModule_GENCPP_API;
void Execute_GasaModule_Codegen()
{
	FScopedSlowTask SlowTask(100.0f, LOCTEXT("RunningGasaGen", "Running GasaGen..."));
	SlowTask.MakeDialog(false, true);  // Shows a progress dialog

	AsyncTask(ENamedThreads::AnyBackgroundHiPriTask, [&SlowTask]()
	{
		Gasa::LogEditor("Executing: Gencpp Module code generation example.");

		gen::init();

		FString     ue_project_path = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
		FPaths::NormalizeDirectoryName(ue_project_path);
		char const* ue_ansi_project_path = TCHAR_TO_ANSI(*ue_project_path);

		FString     ue_root_path = FPaths::GetPath(ue_project_path);
		FPaths::NormalizeDirectoryName(ue_root_path);
		char const* ue_ansi_rooot_path = TCHAR_TO_ANSI(*ue_project_path);

		Project_Path = String::make_length(GlobalAllocator, ue_ansi_project_path, ue_project_path.Len());
		Root_Path    = String::make_length(GlobalAllocator, ue_ansi_rooot_path, ue_root_path.Len());

		// Initialize Globals
		{
		#pragma push_macro("UCLASS")
		#pragma push_macro("UPROPERTY")
		#pragma push_macro("USTRUCT")
		#pragma push_macro("GENERATED_BODY")
		#pragma push_macro("GENCPP_API")
		#undef UCLASS
		#undef UPROPERTY
		#undef USTRUCT
		#undef GENERATED_BODY
		#undef GENCPP_API
			UHT_UCLASS         = code_str(UCLASS());
			UHT_UPROPERTY      = code_str(UPROPERTY());
			UHT_USTRUCT        = code_str(USTRUCT());
			UHT_GENERATED_BODY = code_str(GENERATED_BODY()\n);
			UModule_GENCPP_API = code_str(GENCPP_API);
		#pragma pop_macro("UCLASS")
		#pragma pop_macro("UPROPERTY")
		#pragma pop_macro("USTRUCT")
		#pragma pop_macro("GENERATED_BODY")
		#pragma pop_macro("GENCPP_API")
		}

		// Populate Defines
		{
			PreprocessorDefines.append(get_cached_string(str_DECLARE_CLASS));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_DELEGATE_RetVal_OneParam));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_DELEGATE_RetVal_ThreeParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_DELEGATE_SixParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FiveParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_NineParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_SevenParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_EVENT_ThreeParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_EVENT_TwoParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_FUNCTION));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_LOG_CATEGORY_EXTERN));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_MULTICAST_DELEGATE_OneParam));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_MULTICAST_DELEGATE_ThreeParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_MULTICAST_DELEGATE_TwoParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_TS_MULTICAST_DELEGATE_OneParam));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_TS_MULTICAST_DELEGATE_TwoParams));
			PreprocessorDefines.append(get_cached_string(str_DECLARE_TS_MULTICAST_DELEGATE_ThreeParams));
			PreprocessorDefines.append(get_cached_string(str_DEFINE_ACTORDESC_TYPE));
			PreprocessorDefines.append(get_cached_string(str_DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL));
			PreprocessorDefines.append(get_cached_string(str_ENUM_CLASS_FLAGS));
			PreprocessorDefines.append(get_cached_string(str_FORCEINLINE_DEBUGGABLE));
			// PreprocessorDefines.append( get_cached_string(str_FORCEINLINE));
			PreprocessorDefines.append(get_cached_string(str_GENERATED_BODY));
			PreprocessorDefines.append(get_cached_string(str_GENERATED_UCLASS_BODY));
			PreprocessorDefines.append(get_cached_string(str_GENERATED_USTRUCT_BODY));
			PreprocessorDefines.append(get_cached_string(str_PRAGMA_DISABLE_DEPRECATION_WARNINGS));
			PreprocessorDefines.append(get_cached_string(str_PRAGMA_ENABLE_DEPRECATION_WARNINGS));
			PreprocessorDefines.append(get_cached_string(str_PROPERTY_BINDING_IMPLEMENTATION));
			PreprocessorDefines.append(get_cached_string(str_RESULT_DECL));
			PreprocessorDefines.append(get_cached_string(str_SLATE_BEGIN_ARGS));
			PreprocessorDefines.append(get_cached_string(str_SLATE_END_ARGS));
			PreprocessorDefines.append(get_cached_string(str_TEXT));
			PreprocessorDefines.append(get_cached_string(str_UCLASS));
			PreprocessorDefines.append(get_cached_string(str_UENUM));
			PreprocessorDefines.append(get_cached_string(str_UFUNCTION));
			PreprocessorDefines.append(get_cached_string(str_UMETA));
			PreprocessorDefines.append(get_cached_string(str_UPARAM));
			PreprocessorDefines.append(get_cached_string(str_UPROPERTY));
			PreprocessorDefines.append(get_cached_string(str_USTRUCT));
			PreprocessorDefines.append(get_cached_string(str_UE_REQUIRES));
		}

		gen::deinit();
	});
}

#undef LOCTEXT_NAMESPACE
