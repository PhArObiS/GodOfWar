// // NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GodOfWarGameplayAbility.h"
#include "GodOfWarEnemyGameplayAbility.generated.h"

class UEnemyCombatComponent;
class AGodOfWarEnemyCharacter;
/**
 * 
 */
UCLASS()
class GODOFWAR_API UGodOfWarEnemyGameplayAbility : public UGodOfWarGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "GodOfWar|Ability")
	AGodOfWarEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "GodOfWar|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AGodOfWarEnemyCharacter> CachedGodOfWarEnemyCharacter;
};
