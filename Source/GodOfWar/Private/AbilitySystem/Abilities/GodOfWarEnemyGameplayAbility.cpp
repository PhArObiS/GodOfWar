// // NLDevs All Rights Reserved


#include "AbilitySystem/Abilities/GodOfWarEnemyGameplayAbility.h"
#include "AbilitySystem/GodOfWarAbilitySystemComponent.h"
#include "Characters/GodOfWarEnemyCharacter.h"
#include "GodOfWarGameplayTags.h"

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

FGameplayEffectSpecHandle UGodOfWarEnemyGameplayAbility::MakeEnemyDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& InDamageScalableFloat)
{
	check(EffectClass);

	FGameplayEffectContextHandle ContextHandle = GetGodOfWarAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo()),
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

	FGameplayEffectSpecHandle EffectSpecHandle = GetGodOfWarAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(
		EffectClass,
		GetAbilityLevel(),
		ContextHandle
	);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(
		GodOfWarGameplayTags::Shared_SetByCaller_BaseDamage,
		InDamageScalableFloat.GetValueAtLevel(GetAbilityLevel())
	);
	
	return EffectSpecHandle;
}
