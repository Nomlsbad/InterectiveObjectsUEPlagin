// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TTGameInstance.generated.h"


UCLASS()
class TESTTASK_API UTTGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	FName GetMenuLevelName() const { return MenuLevelName; }

	FName GetGameLevelName() const { return GameLevelName; }
	
protected:

	UPROPERTY(EditDefaultsOnly, Category = "Game")
	FName MenuLevelName = NAME_None;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
	FName GameLevelName = NAME_None;
};
