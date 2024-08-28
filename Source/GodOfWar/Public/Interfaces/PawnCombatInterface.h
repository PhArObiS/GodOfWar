// // NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnCombatInterface.generated.h"

class UPawnCombatComponent;

UINTERFACE(MinimalAPI)
class UPawnCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GODOFWAR_API IPawnCombatInterface
{
	GENERATED_BODY()

public:
	virtual UPawnCombatComponent* GetPawnCombatComponent() const = 0;
};
