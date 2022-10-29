// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveActors/TTBaseInteractiveActor.h"
#include "TTIntersectingInteractiveActor.generated.h"


UCLASS()
class TESTTASK_API ATTIntersectingInteractiveActor : public ATTBaseInteractiveActor
{
	GENERATED_BODY()

public:

	virtual bool IsReadyToStartInteraction() override;

	virtual bool IsReadyToStopInteraction() override;
	
protected:
	
	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	virtual void PostInitializeComponents() override;
};