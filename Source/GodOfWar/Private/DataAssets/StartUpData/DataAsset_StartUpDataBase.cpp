// // NLDevs All Rights Reserved


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/GodOfWarAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/GodOfWarGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UGodOfWarAbilitySystemComponent* InASCToGive,
	int32 ApplyLevel)
{
	check(InASCToGive);
	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UGodOfWarGameplayAbility>>& InAbilitiesToGive,
	UGodOfWarAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UGodOfWarGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
