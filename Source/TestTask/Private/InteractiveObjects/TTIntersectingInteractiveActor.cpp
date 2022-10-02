// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTIntersectingInteractiveActor.h"


void ATTIntersectingInteractiveActor::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CountOfIntersectingObjects += 1;
	if (!IsReadyToStartInteraction()) return;
	
	StartInteraction();
}

void ATTIntersectingInteractiveActor::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	CountOfIntersectingObjects -= 1;
	if (!IsReadyToStopInteraction()) return;
	
	StopInteraction();
}

bool ATTIntersectingInteractiveActor::IsReadyToStartInteraction_Implementation()
{
	return CountOfIntersectingObjects == 1;
}

bool ATTIntersectingInteractiveActor::IsReadyToStopInteraction_Implementation()
{
	return CountOfIntersectingObjects == 0;
}

void ATTIntersectingInteractiveActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (!IsValid(BP_CollisionComponent))
	{
		UE_LOG(LogTTInteractiveObjects, Warning, TEXT("%s : CollisonComponent isn't valid"), *this->GetName());
		return;
	}
	BP_CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ATTIntersectingInteractiveActor::OnOverlapBegin);
	BP_CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ATTIntersectingInteractiveActor::OnOverlapEnd);
}