// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveObjects/TTBaseInteractiveActor.h"
#include "TTPlayerInputInteractiveActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FOnActorIsSeenSignature, AActor*, Viewer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE( FOnActorIsUnseenSignature);


UCLASS()
class TESTTASK_API ATTPlayerInputInteractiveActor : public ATTBaseInteractiveActor
{
	GENERATED_BODY()

public:

	ATTPlayerInputInteractiveActor();

	UPROPERTY(BlueprintAssignable, Category = "InteractiveObject | Interaction")
	FOnActorIsSeenSignature OnActorIsSeen;

	UPROPERTY(BlueprintAssignable, Category = "InteractiveObject | Interaction")
	FOnActorIsUnseenSignature OnActorIsUnseen;

	virtual bool IsReadyToStartInteraction_Implementation() override { return bIsSeen; }

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveObject | Interacrion Options")
	bool bNeedToHighlight;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractiveObject | Interaction")
	void SetHighlight(bool bHighlightVisibility);
	virtual void SetHighlight_Implementation(bool bHighlightVisibility) {}

	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	virtual void PostInitializeComponents() override;

private:

	bool bIsSeen;
};
