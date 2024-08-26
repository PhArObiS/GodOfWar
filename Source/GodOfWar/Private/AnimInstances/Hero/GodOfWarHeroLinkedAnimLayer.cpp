// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/GodOfWarHeroLinkedAnimLayer.h"
#include "AnimInstances/Hero/GodOfWarHeroAnimInstance.h"

UGodOfWarHeroAnimInstance* UGodOfWarHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UGodOfWarHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
