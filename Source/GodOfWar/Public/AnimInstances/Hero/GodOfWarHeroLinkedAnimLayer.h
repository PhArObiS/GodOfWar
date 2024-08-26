// // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/GodOfWarBaseAnimInstance.h"
#include "GodOfWarHeroLinkedAnimLayer.generated.h"

class UGodOfWarHeroAnimInstance;
/**
 * 
 */
UCLASS()
class GODOFWAR_API UGodOfWarHeroLinkedAnimLayer : public UGodOfWarBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UGodOfWarHeroAnimInstance* GetHeroAnimInstance() const;
	
};
