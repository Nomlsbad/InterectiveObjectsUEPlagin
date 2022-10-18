// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TTInteractionComponent.generated.h"

class ATTBaseInteractiveActor;
class ATTPlayerInteractiveSphere;
class ATTPlayerInputInteractiveActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTTASK_API UTTInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UTTInteractionComponent();

	void InitializeUpdaterTargetTimer();

	UFUNCTION(BlueprintCallable)
	void TryToInteract();

	UFUNCTION(BlueprintCallable, Category = "UI")
	bool GetInteractionText(FString& Text) const;
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction Options", meta = (ClampMin = "0.0"))
	float MaxDistanceToTarget = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction Options", meta = (ClampMin = "0.0"))
	float UpdateTargetRate = 0.2f;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction Options")
	TSubclassOf<ATTBaseInteractiveActor> InteractiveSphereClass;
	
	virtual void BeginPlay() override;

private:

	UPROPERTY()
	ATTPlayerInputInteractiveActor* PotentialForInteract = nullptr;

	UPROPERTY()
	ATTBaseInteractiveActor* InteractiveSphere;

	FTimerHandle UpdaterTargetTimerHandle;
	
	void UpdatePotentialForInteract();

	void GenerateOverlapEvent(const FVector& Location) const;
	
	bool GetHitResultOnDistance(
		FVector& EndTrace,
		FHitResult& HitResult,
		ECollisionChannel TraceChannel,
		const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam,
		const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam) const;
};
