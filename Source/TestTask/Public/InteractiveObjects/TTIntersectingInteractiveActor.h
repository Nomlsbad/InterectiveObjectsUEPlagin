// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveObjects/TTBaseInteractiveActor.h"
#include "TTIntersectingInteractiveActor.generated.h"


UCLASS()
class TESTTASK_API ATTIntersectingInteractiveActor : public ATTBaseInteractiveActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly)
	int32 CountOfIntersectingObjects = 0;
	
	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	virtual bool IsReadyToStartInteraction_Implementation() override;

	virtual bool IsReadyToStopInteraction_Implementation() override;

	virtual void PostInitializeComponents() override;
};
