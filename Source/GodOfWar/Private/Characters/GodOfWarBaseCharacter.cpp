// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GodOfWarBaseCharacter.h"

AGodOfWarBaseCharacter::AGodOfWarBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
}

