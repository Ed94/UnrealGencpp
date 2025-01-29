#include "GenCommon.h"

GEN_NS_BEGIN

GEN_API global Str PathRoot;
GEN_API global Str PathEngine;
GEN_API global Str PathEngineConfig;
GEN_API global Str PathEnginePlugins;
GEN_API global Str PathEngineIntermediate;
GEN_API global Str PathProject;
GEN_API global Str PathProjectConfig;
GEN_API global Str PathProjectIntermediate;
GEN_API global Str PathProjectPlugins;

GEN_API global Str PathUnrealGencpp;

GEN_API global Code UHT_GENERATED_BODY;
GEN_API global Code UHT_UCLASS;
GEN_API global Code UHT_UPROPERTY;
GEN_API global Code UHT_USTRUCT;

void ClangFormatFile( Str Path )
{
	// StrBuilder
	StrBuilder StyleArg = StrBuilder::make(get_context()->Allocator_Temp, txt("-style=file:"));
	StyleArg.append(PathUnrealGencpp);
	StyleArg.append("/scripts/.clang-format ");

	// Need to execute clang format on the generated file to get it to match the original.
#define clang_format      "clang-format "
#define cf_format_inplace "-i "
#define cf_verbose        "-verbose "
	StrBuilder command = StrBuilder::make( get_context()->Allocator_Temp, clang_format );
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
