// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "TTInteractiveObjectsSettings.generated.h"

UCLASS(Config = Engine, defaultconfig, meta = (DisplayName = "InteractiveObjectsSettings"))
class INTERACTIVEOBJECTS_API UTTInteractiveObjectsSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(Config, EditAnywhere, Category = "InteractionComponentSettings", meta = (ClampMin = 0.0))
	float UpdateTargetRate;

	UPROPERTY(Config, NoClear, EditAnywhere, Category = "InteractionComponentSettings", meta = (MetaClass="TTBaseInteractiveActor"))
	FSoftClassPath InteractiveShape;
};
	