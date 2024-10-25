# Unreal gencpp

## Setup

Run [scripts/update_dependencies.ps1](./scripts/update_dependencies.ps1).  
It will grab gencpp from its [github](https://github.com/Ed94/gencpp/tree/main) repository and set it up in [Source/Thirdparty](./Source/Thirdparty/).

In order to parse "MODULE"_API macros an AttributeTokens.csv needs to be updated with entries for the modules or plugins wished to be parsed.  
Run [scripts/update_attributetokens.ps1](./scripts/update_attributetokens.ps1) to regenerate.
