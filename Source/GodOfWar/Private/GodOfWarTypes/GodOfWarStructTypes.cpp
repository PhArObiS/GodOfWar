// // NLDevs All Rights Reserved

#include "AbilitySystem/Abilities/GodOfWarGameplayAbility.h"
#include "GodOfWarTypes/GodOfWarStructTypes.h"

bool FGodOfWarHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
