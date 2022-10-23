// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/UI/TTMainMenuWidget.h"
#include "TTGameInstance.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UI/TTBaseHUD.h"

void UTTMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &UTTMainMenuWidget::OnStartGame);
	}
	if (SettingsButton)
	{
		SettingsButton->OnClicked.AddDynamic(this, &UTTMainMenuWidget::OnSettings);
	}
	if (CreditsButton)
	{
		CreditsButton->OnClicked.AddDynamic(this, &UTTMainMenuWidget::OnCredits);
	}
	if (QuitGameButton)
	{
		QuitGameButton->OnClicked.AddDynamic(this, &UTTMainMenuWidget::OnQuitGame);
	}
}

void UTTMainMenuWidget::OnStartGame()
{
	if (!GetWorld()) return;
	
	const auto GameInstance = GetWorld()->GetGameInstance<UTTGameInstance>();
	if (!GameInstance) return;
	
	UGameplayStatics::OpenLevel(this, GameInstance->GetGameLevelName());
}

void UTTMainMenuWidget::OnSettings()
{
	ChangeCurrentWidgetTo(EHUDState::Settings);
}

void UTTMainMenuWidget::OnCredits()
{
	ChangeCurrentWidgetTo(EHUDState::Credits);
}

void UTTMainMenuWidget::OnQuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

