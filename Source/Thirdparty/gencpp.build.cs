using UnrealBuildTool;

public class gencpp : ModuleRules
{
	public gencpp(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		PublicSystemIncludePaths.Add(ModuleDirectory);

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
