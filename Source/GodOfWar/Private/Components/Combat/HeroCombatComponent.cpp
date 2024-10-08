// // NLDevs All Rights Reserved

#include "Components/Combat/HeroCombatComponent.h"
#include "GodOfWarGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Items/Weapons/GodOfWarHeroWeapon.h"

#include "GodOfWarDebugHelper.h"

AGodOfWarHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AGodOfWarHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

AGodOfWarHeroWeapon* UHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
	return Cast<AGodOfWarHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UHeroCombatComponent::GetHeroCurrentEquipWeaponDamageAtLevel(float InLevel) const
{
	return GetHeroCurrentEquippedWeapon()->HeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}
	
	OverlappedActors.AddUnique(HitActor);

	FGameplayEventData Data;
	Data.Instigator = GetOwningPawn();
	Data.Target = HitActor;
	
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		GodOfWarGameplayTags::Shared_Event_MeleeHit,
		Data
	);

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		GodOfWarGameplayTags::Player_Event_HitPause,
		FGameplayEventData()
	);
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		GodOfWarGameplayTags::Player_Event_HitPause,
		FGameplayEventData()
	);
}
