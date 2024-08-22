// // NLDevs All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UGodOfWarGameplayAbility;
class UGodOfWarAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class GODOFWAR_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UGodOfWarAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UGodOfWarGameplayAbility>>ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UGodOfWarGameplayAbility>>ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UGodOfWarGameplayAbility>>& InAbilitiesToGive, UGodOfWarAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
