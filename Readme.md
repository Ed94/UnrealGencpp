# Unreal gencpp

## Setup

Run [scripts/update_dependencies.ps1](./scripts/update_dependencies.ps1).  
It will grab genccp from its github repository.

In order to parse "MODULE"_API macros an AttributeTokens.csv needs to be updated with entries for the modules or plugins wished to be parsed.  
Run [scripts/update_attributetokens.ps1](./scripts/update_attributetokens.ps1) to regenerate.
