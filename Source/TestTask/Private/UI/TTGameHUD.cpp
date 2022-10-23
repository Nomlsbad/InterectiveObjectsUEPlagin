// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TTGameHUD.h"
#include "UI/TTBaseWidget.h"


void ATTGameHUD::BeginPlay()
{
	Super::BeginPlay();	

	Widgets.Add(EWidgetName::PlayerHUD, CreateWidget<UTTBaseWidget>(GetWorld(), PlayerHUDWidgetClass));
	Widgets[EWidgetName::PlayerHUD]->AddToViewport();
}
