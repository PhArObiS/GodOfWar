// // Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/GodOfWarBaseAnimInstance.h"
#include "GodOfWarFunctionLibrary.h"

bool UGodOfWarBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
	if (APawn* OwningPawn = TryGetPawnOwner())
	{
		return UGodOfWarFunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
	}
	return false;
}
