using System;
using EpicGames.Core;
using UnrealBuildTool;
using ModuleRules               = UnrealBuildTool.ModuleRules;
using ReadOnlyTargetRules       = UnrealBuildTool.ReadOnlyTargetRules;
using TargetRules               = UnrealBuildTool.TargetRules;
using UnrealTargetConfiguration = UnrealBuildTool.UnrealTargetConfiguration;

public class UnrealGencpp : ModuleRules
{
	public UnrealGencpp(ReadOnlyTargetRules Target) : base(Target)
	{
	#region Engine
        PrivateIncludePathModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
        });
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "Engine",
            "CoreUObject",
			"EditorStyle",
			"Projects",
            "PropertyEditor",
            "SlateCore",
            "Slate",
            "UMG",
            "UnrealEd",
        });
    #endregion Engine
    
		PublicIncludePaths.AddRange(new string[]
		{
			"UnrealGencpp",
		});
		PublicIncludePathModuleNames.AddRange(new string[]
		{
			"UnrealGencpp",
		});
		
		Type = ModuleType.CPlusPlus;

		bUseUnity           = false;
		bMergeUnityFiles    = false;
		IWYUSupport         = IWYUSupport.None;
		PCHUsage            = PCHUsageMode.NoPCHs;
		OptimizeCode        = CodeOptimization.Never;
		// MinCpuArchX64       = MinimumCpuArchitectureX64.AVX512;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		bCodeCoverage                   = false;
		bDisableStaticAnalysis          = true;
		bValidateCircularDependencies   = true;
		bValidateFormatStrings          = false;
		bValidateInternalApi            = false;
		bEnableExceptions               = false;
		bEnableBufferSecurityChecks     = false;
		bEnableNonInlinedGenCppWarnings = false;
		bIgnoreUnresolvedSymbols        = false;

		bWarningsAsErrors               = false;
		ShadowVariableWarningLevel      = UnrealBuildTool.WarningLevel.Off;
		UndefinedIdentifierWarningLevel = UnrealBuildTool.WarningLevel.Off;
		
		bEnableObjCAutomaticReferenceCounting = false;
		bEnableObjCExceptions                 = false;

		bEnableUndefinedIdentifierWarnings = false;
		UndefinedIdentifierWarningLevel = WarningLevel.Off;

		var Kilobyte = 1024;
		NumIncludedBytesPerUnityCPPOverride    = Kilobyte * 32;
		MinFilesUsingPrecompiledHeaderOverride = 1;

		PublicDefinitions.Add("GEN_BUILD_DEBUG=1");
		PublicDefinitions.Add("GEN_TIME=1");
		PublicDefinitions.Add("GEN_EXECUTION_EXPRESSION_SUPPORT=0");
		PublicDefinitions.Add("GEN_PARSER_DISABLE_MACRO_TYPEDEF=0");
		PublicDefinitions.Add("GEN_EXPOSE_BACKEND=1");
		PublicDefinitions.Add("GEN_DEFINE_LIBRARY_CODE_CONSTANTS=1");
		PublicDefinitions.Add("GEN_ENFORCE_STRONG_CODE_TYPES=1");
		PublicDefinitions.Add("GEN_DYN_LINK=1");
		PrivateDefinitions.Add("GEN_DYN_EXPORT=1");
	}
}
