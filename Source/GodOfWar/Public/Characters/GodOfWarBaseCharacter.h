// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "Interfaces/PawnUIInterface.h"
#include "GodOfWarBaseCharacter.generated.h"

class UDataAsset_StartUpDataBase;
class UGodOfWarAttributeSet;
class UGodOfWarAbilitySystemComponent;

UCLASS()
class GODOFWAR_API AGodOfWarBaseCharacter : public ACharacter, public IAbilitySystemInterface, public IPawnCombatInterface, public IPawnUIInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGodOfWarBaseCharacter();

	//~ Begin IAbilitySystemComponent Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemComponent Interface

	//~ BeginI PawnCombatInterface Interface
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface

	//~ Begin IPawnUIInterface Interface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	//~ End IPawnUIInterface Interface
	
protected:
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UGodOfWarAbilitySystemComponent* GodOfWarAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UGodOfWarAttributeSet* GodOfWarAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;
	
public:
	FORCEINLINE UGodOfWarAbilitySystemComponent* GetGodOfWarAbilitySystemComponent() const { return GodOfWarAbilitySystemComponent; }
	FORCEINLINE UGodOfWarAttributeSet* GetGodOfWarAttributeSet() const { return GodOfWarAttributeSet; }
};
