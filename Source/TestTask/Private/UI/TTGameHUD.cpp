// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TTGameHUD.h"
#include "Blueprint/UserWidget.h"


void ATTGameHUD::BeginPlay()
{
	Super::BeginPlay();	

	PlayerHUDWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass);
	PlayerHUDWidget->AddToViewport();
}
