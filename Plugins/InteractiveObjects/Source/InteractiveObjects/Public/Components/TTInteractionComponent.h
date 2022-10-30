// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TTInteractionComponent.generated.h"

class ATTBaseInteractiveActor;
class ATTPlayerInputInteractiveActor;

DECLARE_LOG_CATEGORY_CLASS(LogTTInteractionComponent, All, All);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIVEOBJECTS_API UTTInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UTTInteractionComponent();

	void InitializeUpdaterTargetTimer();

	UFUNCTION(BlueprintCallable)
	void TryToInteract();
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction Options", meta = (ClampMin = "0.0"))
	float MaxDistanceToTarget = 200.0f;

	UPROPERTY()
	ATTBaseInteractiveActor* InteractiveShape;
	
	virtual void BeginPlay() override;

private:

	UPROPERTY()
	ATTPlayerInputInteractiveActor* PotentialForInteract = nullptr;
	
	FTimerHandle UpdaterTargetTimerHandle;

	float UpdateTargetRate;
	
	void UpdatePotentialForInteract();

	bool GetBoundaryPoints(FVector& Start, FVector& End) const;

	void GenerateOverlapEvent(const FVector& Location) const;
	
	bool GetHitResultOnDistance(
		FVector& EndTrace,
		FHitResult& HitResult,
		ECollisionChannel TraceChannel,
		const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam,
		const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam) const;
};
