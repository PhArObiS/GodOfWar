// // Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GodOfWarAttributeSet.h"
#include "GameplayEffectExtension.h"

#include "GodOfWarDebugHelper.h"
#include "GodOfWarFunctionLibrary.h"
#include "GodOfWarGameplayTags.h"
#include "Components/UI/HeroUIComponent.h"
#include "Components/UI/PawnUIComponent.h"
#include "Interfaces/PawnUIInterface.h"

UGodOfWarAttributeSet::UGodOfWarAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentRage(1.f);
	InitMaxRage(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UGodOfWarAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (!CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
	}

	checkf(CachedPawnUIInterface.IsValid(), TEXT("%s didnt implement IPawnUIInterface"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());
	UPawnUIComponent* PawnUIComponent = CachedPawnUIInterface->GetPawnUIComponent();
	checkf(PawnUIComponent, TEXT("Couldn't extract a PawnUIComponent from %s"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());
	
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);

		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());
	}

	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());
		SetCurrentRage(NewCurrentRage);
		if (GetCurrentRage() == GetMaxRage())
		{
			UGodOfWarFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), GodOfWarGameplayTags::Player_Status_Rage_Full);
		}
		else if (GetCurrentRage() == 0.f)
		{
			UGodOfWarFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), GodOfWarGameplayTags::Player_Status_Rage_None);
		}
		else
		{
			UGodOfWarFunctionLibrary::RemoveGameplayTagFromActorIfFound(Data.Target.GetAvatarActor(), GodOfWarGameplayTags::Player_Status_Rage_Full);
			UGodOfWarFunctionLibrary::RemoveGameplayTagFromActorIfFound(Data.Target.GetAvatarActor(), GodOfWarGameplayTags::Player_Status_Rage_None);
		}
		
		if (UHeroUIComponent* HeroUIComponent = CachedPawnUIInterface->GetHeroUIComponent())
		{
			HeroUIComponent->OnCurrentRageChanged.Broadcast(GetCurrentRage() / GetMaxRage());
		}
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		// const FString DebugString = FString::Printf(
		// 	TEXT("Old Health: %f, Damage Done: %f, NewCurrentHealth: %f"),
		// 	OldHealth,
		// 	DamageDone,
		// 	NewCurrentHealth
		// );
		//
		// Debug::Print(DebugString, FColor::Green);

		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());

		if (GetCurrentHealth() == 0.f)
		{
			UGodOfWarFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), GodOfWarGameplayTags::Shared_Status_Dead);
		}
	}
}
