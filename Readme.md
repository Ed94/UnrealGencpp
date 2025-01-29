# Unreal gencpp

Allows for using the [gencpp](https://github.com/Ed94/gencpp) library within the editor's runtime.

## Setup

Run [scripts/update_dependencies.ps1](./scripts/update_dependencies.ps1).  
It will grab gencpp from its [github](https://github.com/Ed94/gencpp/tree/main) repository and set it up in [Source/Thirdparty](./Source/Thirdparty/).

In order to parse "MODULE"_API macros an [scripts/AttributeTokens.csv](./scripts/AttributeTokens.csv) could be updated with entries for the modules or plugins wished to be parsed.  
Running the [scripts/update_dependencies.ps1](./scripts/update_dependencies.ps1). Will regenerate the attribute tokens.

The other way is to use the Macro registration method:

```cpp
register_macros( args(
	(Macro { txt("ENGINE_API"), MT_Expression, MF_Allow_As_Attribute }),	
));
```

Where the macro will be allowed as an attribute token during parsing.

For documentation on usage of gencpp in general see the [repo's docs](https://github.com/Ed94/gencpp/tree/main/docs).
