// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTPlayerInputInteractiveActor.h"
#include "Components/SphereComponent.h"

#define ECC_Interactive ECC_GameTraceChannel1;

ATTPlayerInputInteractiveActor::ATTPlayerInputInteractiveActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bNeedToHighlight = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);

	HighlighterMesh = CreateDefaultSubobject<UStaticMeshComponent>("HighlighterMeshComponent");
	HighlighterMesh->SetupAttachment(GetRootComponent());
	HighlighterMesh->SetVisibility(false);
	
	if (CollisionComponent)
	{
		CollisionComponent->SetupAttachment(GetRootComponent());
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ATTPlayerInputInteractiveActor::OnOverlapBegin);
		CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ATTPlayerInputInteractiveActor::OnOverlapEnd);
		CollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
		CollisionComponent->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);
	}
}

void ATTPlayerInputInteractiveActor::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	bReadyToInteract = true;
	if (bNeedToHighlight)
	{
		HighlighterMesh->SetVisibility(true);
	}
}

void ATTPlayerInputInteractiveActor::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bReadyToInteract = false;
	if (bNeedToHighlight)
	{
		HighlighterMesh->SetVisibility(false);
	}
}

void ATTPlayerInputInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
	bReadyToInteract = false;
}
