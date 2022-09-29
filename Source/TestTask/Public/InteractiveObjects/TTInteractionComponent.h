// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TTInteractionComponent.generated.h"

class ATTPlayerInteractiveSphere;
class ATTPlayerInputInteractiveActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTTASK_API UTTInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UTTInteractionComponent();

	void InitializeUpdaterTargetTimer();

	virtual void TryToInteract();
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction", meta = (ClampMin = "0.0"))
	float MaxDistanceToTarget = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction", meta = (ClampMin = "0.0"))
	float UpdateTargetRate = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	ATTPlayerInteractiveSphere* InteractiveSphere;

private:

	UPROPERTY()
	ATTPlayerInputInteractiveActor* PotentialForInteract = nullptr;

	FTimerHandle UpdaterTargetTimerHandle;
	
	void UpdatePotentialForInteract();
	
	bool GetHitResultInInteractiveChannel(
		FHitResult& HitResult,
		const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam,
		const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam) const;
};
