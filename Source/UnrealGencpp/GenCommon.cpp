#include "GenCommon.h"

GEN_NS_BEGIN

global Str PathRoot;
global Str PathEngine;
global Str PathEngineConfig;
global Str PathEnginePlugins;
global Str PathEngineIntermediate;
global Str PathProject;
global Str PathProjectConfig;
global Str PathProjectIntermediate;
global Str PathProjectPlugins;

global Str PathUnrealGencpp;

global Code UHT_GENERATED_BODY;
global Code UHT_UCLASS;
global Code UHT_UPROPERTY;
global Code UHT_USTRUCT;

global Context UeCtx = {};

void ClangFormatFile( Str Path )
{
	// StrBuilder
	StrBuilder StyleArg = StrBuilder::make(UeCtx.Allocator_Temp, txt("-style=file:"));
	StyleArg.append(PathUnrealGencpp);
	StyleArg.append("/scripts/.clang-format ");

	// Need to execute clang format on the generated file to get it to match the original.
#define clang_format      "clang-format "
#define cf_format_inplace "-i "
#define cf_verbose        "-verbose "
	StrBuilder command = StrBuilder::make( UeCtx.Allocator_Temp, clang_format );
	command.append( cf_format_inplace );
	command.append( cf_verbose );
	command.append( StyleArg );
	command.append( Path );
	log_fmt("\tRunning clang-format on file:\n");
	system( command );
	log_fmt("\tclang-format finished reformatting.\n");
#undef cf_cmd
#undef cf_format_inplace
#undef cf_style
#undef cf_verbse
}

GEN_NS_END
