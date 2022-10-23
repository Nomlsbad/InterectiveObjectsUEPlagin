// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/UI/TTMainMenuHUD.h"
#include "UI/TTBaseWidget.h"


void ATTMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	Widgets.Add(EWidgetName::MainMenu, CreateWidget<UTTBaseWidget>(GetWorld(), MainMenuWidgetClass));
	Widgets.Add(EWidgetName::Settings, CreateWidget<UTTBaseWidget>(GetWorld(), SettingsWidgetClass));
	Widgets.Add(EWidgetName::Creators, CreateWidget<UTTBaseWidget>(GetWorld(), CreatorsWidgetClass));

	for (const auto WidgetPair: Widgets)
	{
		const auto Widget = WidgetPair.Value;
		if (!Widget) continue;

		Widget->AddToViewport();
		Widget->SetVisibility(ESlateVisibility::Hidden);
	}

	CurrentWidgetName = EWidgetName::MainMenu;
	const auto CurrentWidget = Widgets[EWidgetName::MainMenu];
	CurrentWidget->SetVisibility(ESlateVisibility::Visible);
}
