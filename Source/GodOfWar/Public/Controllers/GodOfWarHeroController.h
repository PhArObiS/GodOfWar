// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/PlayerController.h"
#include "GodOfWarHeroController.generated.h"

/**
 * 
 */
UCLASS()
class GODOFWAR_API AGodOfWarHeroController : public APlayerController, public IGenericTeamAgentInterface 
{
	GENERATED_BODY()

public:
	AGodOfWarHeroController();

	//~ Begin IGenericTeamAgentInterface Interface
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~ End IGenericTeamAgentInterface
 
private:
	FGenericTeamId HeroTeamId;
};
