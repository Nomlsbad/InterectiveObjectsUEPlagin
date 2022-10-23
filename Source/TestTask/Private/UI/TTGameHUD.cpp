// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TTGameHUD.h"
#include "UI/TTBaseWidget.h"


void ATTGameHUD::BeginPlay()
{
	Super::BeginPlay();	

	Widgets.Add(EHUDState::PlayerHUD, CreateWidget<UTTBaseWidget>(GetWorld(), PlayerHUDWidgetClass));
	Widgets[EHUDState::PlayerHUD]->AddToViewport();
	CurrentWidgetName = EHUDState::PlayerHUD;
}
