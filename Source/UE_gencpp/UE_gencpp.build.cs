using ModuleRules         = UnrealBuildTool.ModuleRules;
using ReadOnlyTargetRules = UnrealBuildTool.ReadOnlyTargetRules;

public class UE_gencpp : ModuleRules
{
	public UE_gencpp(ReadOnlyTargetRules Target) : base(Target)
	{
	#region Engine
        PrivateIncludePathModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
        });
        PrivateDependencyModuleNames.AddRange(new string[] {
            "Core",
            "Engine",
            "CoreUObject",
			"EditorStyle",
            "PropertyEditor",
            "SlateCore",
            "Slate",
            "UMG",
            "UnrealEd",
        });
    #endregion Engine

		bWarningsAsErrors = false;
		ShadowVariableWarningLevel = UnrealBuildTool.WarningLevel.Off;
		UndefinedIdentifierWarningLevel = UnrealBuildTool.WarningLevel.Off;

		PublicDefinitions.Add("Build_Debug=1");
		PublicDefinitions.Add("GEN_TIME=1");
		PublicDefinitions.Add("GEN_EXECUTION_EXPRESSION_SUPPORT=0");
		PublicDefinitions.Add("GEN_PARSER_DISABLE_MACRO_TYPEDEF=0");
		PublicDefinitions.Add("GEN_EXPOSE_BACKEND=1");
		PublicDefinitions.Add("GEN_DEFINE_LIBRARY_CODE_CONSTANTS=1")
		PublicDefinitions.Add("GEN_ENFORCE_STRONG_CODE_TYPES=1")
	}
}
