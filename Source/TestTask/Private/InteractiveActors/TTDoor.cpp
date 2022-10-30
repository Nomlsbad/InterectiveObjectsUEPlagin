// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveActors/TTDoor.h"

void ATTDoor::StartInteraction_Implementation(AActor* InstigatedBy)
{
	Super::StartInteraction_Implementation(InstigatedBy);

	IsOpen = !IsOpen;
}
