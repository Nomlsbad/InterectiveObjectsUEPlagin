// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTPlayerInputInteractiveActor.h"


ATTPlayerInputInteractiveActor::ATTPlayerInputInteractiveActor()
{
	bNeedToHighlight = false;
	bIsSeen = false;
}

void ATTPlayerInputInteractiveActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	BP_CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ATTPlayerInputInteractiveActor::OnOverlapBegin);
	BP_CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ATTPlayerInputInteractiveActor::OnOverlapEnd);
}

void ATTPlayerInputInteractiveActor::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin_Implementation(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (bIsSeen) return;
	bIsSeen = true;

	if (bNeedToHighlight)
	{
		SetHighlight(true);
	}

	OnActorIsSeen.Broadcast(OtherActor);
}

void ATTPlayerInputInteractiveActor::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd_Implementation(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);

	bIsSeen = CountOfOverlappingActors > 0;
	if (bIsSeen) return;

	if (bNeedToHighlight)
	{
		SetHighlight(false);
	}

	OnActorIsUnseen.Broadcast();
}
