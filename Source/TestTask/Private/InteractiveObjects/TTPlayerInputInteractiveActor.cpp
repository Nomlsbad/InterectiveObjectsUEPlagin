// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTPlayerInputInteractiveActor.h"


ATTPlayerInputInteractiveActor::ATTPlayerInputInteractiveActor()
{
	bNeedToHighlight = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);

	HighlighterMesh = CreateDefaultSubobject<UStaticMeshComponent>("HighlighterMeshComponent");
	HighlighterMesh->SetupAttachment(GetRootComponent());
	HighlighterMesh->SetVisibility(false);
}

void ATTPlayerInputInteractiveActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (!IsValid(BP_CollisionComponent))
	{
		UE_LOG(LogTTInteractiveObjects, Warning, TEXT("%s : CollisonComponent isn't valid"), *this->GetName());
		return;
	}
	BP_CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ATTPlayerInputInteractiveActor::OnOverlapBegin);
	BP_CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ATTPlayerInputInteractiveActor::OnOverlapEnd);
}

void ATTPlayerInputInteractiveActor::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	bIsSeen = true;
	if (bNeedToHighlight)
	{
		HighlighterMesh->SetVisibility(true);
	}
}

void ATTPlayerInputInteractiveActor::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bIsSeen = false;
	if (bNeedToHighlight)
	{
		HighlighterMesh->SetVisibility(false);
	}
}
