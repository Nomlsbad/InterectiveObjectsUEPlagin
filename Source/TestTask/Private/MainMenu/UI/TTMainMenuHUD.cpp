// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/UI/TTMainMenuHUD.h"
#include "UI/TTBaseWidget.h"


void ATTMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	Widgets.Add(EHUDState::MainMenu, CreateWidget<UTTBaseWidget>(GetWorld(), MainMenuWidgetClass));
	Widgets.Add(EHUDState::Settings, CreateWidget<UTTBaseWidget>(GetWorld(), SettingsWidgetClass));
	Widgets.Add(EHUDState::Credits, CreateWidget<UTTBaseWidget>(GetWorld(), CreditsWidgetClass));

	for (const auto WidgetPair: Widgets)
	{
		const auto Widget = WidgetPair.Value;
		if (!Widget) continue;

		Widget->AddToViewport();
		Widget->SetVisibility(ESlateVisibility::Hidden);
	}

	CurrentWidgetName = EHUDState::MainMenu;
	const auto CurrentWidget = Widgets[EHUDState::MainMenu];
	CurrentWidget->SetVisibility(ESlateVisibility::Visible);
}
