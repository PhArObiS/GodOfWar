// // NLDevs All Rights Reserved

#include "AbilitySystem/Abilities/GodOfWarHeroGameplayAbility.h"
#include "GodOfWarGameplayTags.h"
#include "AbilitySystem/GodOfWarAbilitySystemComponent.h"
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

UHeroUIComponent* UGodOfWarHeroGameplayAbility::GetHeroUIComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroUIComponent();
}

FGameplayEffectSpecHandle UGodOfWarHeroGameplayAbility::MakeHeroDamageEffectSpecHandle( TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount)
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
		InWeaponBaseDamage
	);

	if (InCurrentAttackTypeTag.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag, InUsedComboCount);
	}
	return EffectSpecHandle;
}

bool UGodOfWarHeroGameplayAbility::GetAbilityRemainingCooldownByTag(FGameplayTag InCooldownTag, float& TotalCooldownTime, float& RemainingCooldownTime)
{
	check(InCooldownTag.IsValid());
	FGameplayEffectQuery CooldownQuery = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(InCooldownTag.GetSingleTagContainer());
	TArray<TPair<float,float>> TimeRemainingAndDuration = GetAbilitySystemComponentFromActorInfo()->GetActiveEffectsTimeRemainingAndDuration(CooldownQuery);

	if (!TimeRemainingAndDuration.IsEmpty())
	{
		RemainingCooldownTime = TimeRemainingAndDuration[0].Key;
		TotalCooldownTime = TimeRemainingAndDuration[0].Value;
	}
	
	return RemainingCooldownTime > 0.f;
}
