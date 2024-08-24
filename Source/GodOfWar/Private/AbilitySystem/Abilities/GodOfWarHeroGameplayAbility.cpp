// // NLDevs All Rights Reserved


#include "AbilitySystem/Abilities/GodOfWarHeroGameplayAbility.h"

#include "Characters/GodOfWarHeroCharacter.h"
#include "Controllers/GodOfWarHeroController.h"

AGodOfWarHeroCharacter* UGodOfWarHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedGodOfWarHeroCharacter.IsValid())
	{
		CachedGodOfWarHeroCharacter = Cast<AGodOfWarHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedGodOfWarHeroCharacter.IsValid() ? CachedGodOfWarHeroCharacter.Get() : nullptr;
}

AGodOfWarHeroController* UGodOfWarHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedGodOfWarHeroController.IsValid())
	{
		CachedGodOfWarHeroController = Cast<AGodOfWarHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedGodOfWarHeroController.IsValid() ? CachedGodOfWarHeroController.Get() : nullptr;
}

UHeroCombatComponent* UGodOfWarHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
