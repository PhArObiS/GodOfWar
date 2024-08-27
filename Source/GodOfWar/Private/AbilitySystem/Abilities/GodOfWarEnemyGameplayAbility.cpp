// // NLDevs All Rights Reserved


#include "AbilitySystem/Abilities/GodOfWarEnemyGameplayAbility.h"

#include "Characters/GodOfWarEnemyCharacter.h"

AGodOfWarEnemyCharacter* UGodOfWarEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedGodOfWarEnemyCharacter.IsValid())
	{
		CachedGodOfWarEnemyCharacter = Cast<AGodOfWarEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedGodOfWarEnemyCharacter.IsValid() ? CachedGodOfWarEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UGodOfWarEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}
