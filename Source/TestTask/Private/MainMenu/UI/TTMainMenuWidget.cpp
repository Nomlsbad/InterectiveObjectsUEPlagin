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
	
	StartGameButton->OnClicked.AddDynamic(this, &UTTMainMenuWidget::OnStartGame);
	SettingsButton->OnClicked.AddDynamic(this, &UTTMainMenuWidget::OnSettings);
	CreatorsButton->OnClicked.AddDynamic(this, &UTTMainMenuWidget::OnCreators);
	QuitGameButton->OnClicked.AddDynamic(this, &UTTMainMenuWidget::OnQuitGame);
}

void UTTMainMenuWidget::OnStartGame()
{
	if (!GetWorld()) return;
	
	const auto GameInstance = GetWorld()->GetGameInstance<UTTGameInstance>();
	if (!GameInstance) return;

	if (GameInstance->GetGameLevelName() == NAME_None) return;
	UGameplayStatics::OpenLevel(this, GameInstance->GetGameLevelName());
}

void UTTMainMenuWidget::OnSettings()
{
	ChangeCurrentWidgetTo(EWidgetName::Settings);
}

void UTTMainMenuWidget::OnCreators()
{
	ChangeCurrentWidgetTo(EWidgetName::Creators);
}

void UTTMainMenuWidget::OnQuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

