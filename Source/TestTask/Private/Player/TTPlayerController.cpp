// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TTPlayerController.h"

void ATTPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}
