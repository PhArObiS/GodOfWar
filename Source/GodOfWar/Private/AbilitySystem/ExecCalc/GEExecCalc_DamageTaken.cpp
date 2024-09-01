// // NLDevs All Rights Reserved


#include "AbilitySystem/ExecCalc/GEExecCalc_DamageTaken.h"
#include "GodOfWarGameplayTags.h"
#include "AbilitySystem/GodOfWarAttributeSet.h"

#include "GodOfWarDebugHelper.h"

struct FGodOfWarDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

	FGodOfWarDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGodOfWarAttributeSet, AttackPower, Source, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGodOfWarAttributeSet, DefensePower, Target, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGodOfWarAttributeSet, DamageTaken, Target, false)
	}
};

static const FGodOfWarDamageCapture& GetGodOfWarDamageCapture()
{
	static FGodOfWarDamageCapture GodOfWarDamageCapture;
	return GodOfWarDamageCapture;
}
UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
	RelevantAttributesToCapture.Add(GetGodOfWarDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetGodOfWarDamageCapture().DefensePowerDef);
	RelevantAttributesToCapture.Add(GetGodOfWarDamageCapture().DamageTakenDef);
}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	// EffectSpec.GetContext().GetSourceObject();
	// EffectSpec.GetContext().GetAbility();
	// EffectSpec.GetContext().GetInstigator();
	// EffectSpec.GetContext().GetEffectCauser();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetGodOfWarDamageCapture().AttackPowerDef, EvaluateParameters, SourceAttackPower);
	// Debug::Print(TEXT("SourceAttackPower"), SourceAttackPower);
	
	float BaseDamage = 0.f;
	int32 UsedLightAttackCombatCount = 0;
	int32 UsedHeavyAttackCombatCount = 0;
	
	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(GodOfWarGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseDamage = TagMagnitude.Value;
			// Debug::Print(TEXT("BaseDamage"), BaseDamage);
		}

		if (TagMagnitude.Key.MatchesTagExact(GodOfWarGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackCombatCount = TagMagnitude.Value;
			// Debug::Print(TEXT("UsedLightAttackCombatCount"), UsedLightAttackCombatCount);
		}

		if (TagMagnitude.Key.MatchesTagExact(GodOfWarGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackCombatCount = TagMagnitude.Value;
			// Debug::Print(TEXT("UsedHeavyAttackCombatCount"), UsedHeavyAttackCombatCount);
		}
	}
	
	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetGodOfWarDamageCapture().DefensePowerDef,  EvaluateParameters, TargetDefensePower);
	// Debug::Print(TEXT("TargetDefensePower"), TargetDefensePower);
	
	if (UsedLightAttackCombatCount != 0)
	{
		const float DamageIncreasePercentLight = (UsedLightAttackCombatCount - 1) * 0.05 + 1.f;

		BaseDamage *= DamageIncreasePercentLight;
		// Debug::Print(TEXT("ScaledBaseDamageLight"), BaseDamage);
	}

	if (UsedHeavyAttackCombatCount != 0)
	{
		const float DamageIncreasePercentHeavy = UsedHeavyAttackCombatCount * 0.15f + 1.f;

		BaseDamage *= DamageIncreasePercentHeavy;
		// Debug::Print(TEXT("ScaledBaseDamageHeavy"), BaseDamage);
	}

	const float FinalDamageDone = BaseDamage * SourceAttackPower / TargetDefensePower;
	// Debug::Print(TEXT("FinalDamageDone"), FinalDamageDone);
	
	if (FinalDamageDone > 0)
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(
				GetGodOfWarDamageCapture().DamageTakenProperty,
				EGameplayModOp::Override,
				FinalDamageDone
			)
		);
	}
}
