// // NLDevs All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/GodOfWarHeroWeapon.h"

AGodOfWarHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AGodOfWarHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
