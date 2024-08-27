// // NLDevs All Rights Reserved

#include "GodOfWarTypes/GodOfWarStructTypes.h"
#include "AbilitySystem/Abilities/GodOfWarHeroGameplayAbility.h"

bool FGodOfWarHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
