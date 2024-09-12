// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/GodOfWarHeroController.h"

AGodOfWarHeroController::AGodOfWarHeroController()
{
	HeroTeamId = FGenericTeamId(0);
}

FGenericTeamId AGodOfWarHeroController::GetGenericTeamId() const
{
	return HeroTeamId;
}
