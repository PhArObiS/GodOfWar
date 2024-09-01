// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GodOfWarBaseCharacter.h"
#include "AbilitySystem/GodOfWarAbilitySystemComponent.h"
#include "AbilitySystem/GodOfWarAttributeSet.h"

class UPawnCombatComponent;

AGodOfWarBaseCharacter::AGodOfWarBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	GodOfWarAbilitySystemComponent = CreateDefaultSubobject<UGodOfWarAbilitySystemComponent>(TEXT("GodOfWarAbilitySystemComponent"));
	GodOfWarAttributeSet = CreateDefaultSubobject<UGodOfWarAttributeSet>(TEXT("GodOfWarAttributeSet"));
}

UAbilitySystemComponent* AGodOfWarBaseCharacter::GetAbilitySystemComponent() const
{
	return GetGodOfWarAbilitySystemComponent();
}

UPawnCombatComponent* AGodOfWarBaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

UPawnUIComponent* AGodOfWarBaseCharacter::GetPawnUIComponent() const
{
	return nullptr;
}


void AGodOfWarBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (GodOfWarAbilitySystemComponent)
	{
		GodOfWarAbilitySystemComponent->InitAbilityActorInfo(this, this);
		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}

