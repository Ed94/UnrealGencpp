#pragma once

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class UNREALGENCPP_API FUnrealGencppModule : public IModuleInterface
{
public:
	static bool IsAvailable() {
		return FModuleManager::Get().IsModuleLoaded("UnrealGencpp");
	}

	static FUnrealGencppModule& Get() {
		return FModuleManager::LoadModuleChecked<FUnrealGencppModule>("UnrealGencpp");
	}

protected:
	void StartupModule() override;
	void ShutdownModule() override;
};
