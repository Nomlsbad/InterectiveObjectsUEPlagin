// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/TTBaseWidget.h"
#include "TTMainMenuWidget.generated.h"

class UButton;

UCLASS()
class TESTTASK_API UTTMainMenuWidget : public UTTBaseWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta = (BindWidget))
	UButton* StartGameButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SettingsButton;

	UPROPERTY(meta = (BindWidget))
	UButton* CreatorsButton;

	UPROPERTY(meta = (BindWidget))
	UButton* QuitGameButton;

	virtual void NativeOnInitialized() override;

private:

	UFUNCTION()
	void OnStartGame();

	UFUNCTION()
	void OnSettings();

	UFUNCTION()
	void OnCreators();

	UFUNCTION()
	void OnQuitGame();
};
