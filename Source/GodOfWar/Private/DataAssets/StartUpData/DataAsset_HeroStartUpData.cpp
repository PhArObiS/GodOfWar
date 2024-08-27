// NLDevs All Rights Reserved

#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/GodOfWarAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/GodOfWarGameplayAbility.h"

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UGodOfWarAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FGodOfWarHeroAbilitySet& AbilitySet : HeroStartUpAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;
		
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
