// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/TTMainMenuPlayerController.h"

void ATTMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
}
