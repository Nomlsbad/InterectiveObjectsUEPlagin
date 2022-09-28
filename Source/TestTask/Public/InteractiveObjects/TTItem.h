// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveObjects/TTPlayerInputInteractiveActor.h"
#include "TTItem.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASK_API ATTItem : public ATTPlayerInputInteractiveActor
{
	GENERATED_BODY()

public:

	ATTItem(const FObjectInitializer& ObjectInitializer);
	
};
