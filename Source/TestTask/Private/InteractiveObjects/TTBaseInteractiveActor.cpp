// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTBaseInteractiveActor.h"


ATTBaseInteractiveActor::ATTBaseInteractiveActor()
{
 	PrimaryActorTick.bCanEverTick = true;
}

void ATTBaseInteractiveActor::StartInteraction_Implementation(AActor* InstigatedBy)
{
	OnStartInteraction.Broadcast(InstigatedBy);
}

void ATTBaseInteractiveActor::StopInteraction_Implementation()
{
	OnStopInteraction.Broadcast();
}

void ATTBaseInteractiveActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CollisionComponentReference.ComponentProperty = CollisionComponentName;
	BP_CollisionComponent = Cast<UPrimitiveComponent>(CollisionComponentReference.GetComponent(this));

	if (!IsValid(BP_CollisionComponent))
	{
		UE_LOG(LogTTInteractiveObjects, Warning, TEXT("%s : CollisonComponent isn't valid"), *this->GetName());
	}
}

void ATTBaseInteractiveActor::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ObjectsTryingToInteract.Add(OtherActor);
}

void ATTBaseInteractiveActor::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ObjectsTryingToInteract.Remove(OtherActor);
}