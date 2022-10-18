// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TTInteractionActorWidget.generated.h"


UCLASS()
class TESTTASK_API UTTInteractionActorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "UI")
	bool GetInteractionText(FString& Text) const;
};
