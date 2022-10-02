// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveObjects/TTBaseInteractiveActor.h"
#include "TTPlayerInputInteractiveActor.generated.h"


UCLASS()
class TESTTASK_API ATTPlayerInputInteractiveActor : public ATTBaseInteractiveActor
{
	GENERATED_BODY()

public:

	ATTPlayerInputInteractiveActor();

	virtual bool IsReadyToStartInteraction_Implementation() override { return bIsSeen; }

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (EditCondition = "!bNeedToHighlight"))
	UStaticMeshComponent* HighlighterMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bNeedToHighlight;

	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	virtual void PostInitializeComponents() override;

private:

	bool bIsSeen = false;
};
