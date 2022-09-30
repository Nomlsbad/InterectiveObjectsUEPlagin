// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTLamp.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"

ATTLamp::ATTLamp(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<USphereComponent>(ATTBaseInteractiveActor::CollisionComponentName))
{	
	SetRootComponent(CollisionComponent);
	CollisionComponent->SetupAttachment(GetRootComponent());
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ATTLamp::OnOverlapBegin);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ATTLamp::OnOverlapEnd);

	PointLightComponent = CreateDefaultSubobject<UPointLightComponent>("PointLightComponent");
	PointLightComponent->SetupAttachment(GetRootComponent());
	PointLightComponent->SetVisibility(false);
}

void ATTLamp::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CountOfPawnInRadius += 1;
	if (!bReadyToInteract) return;

	bReadyToInteract = false;
	StartInteraction();
}

void ATTLamp::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	CountOfPawnInRadius -= 1;
	bReadyToInteract = CountOfPawnInRadius == 0;
	if (!bReadyToInteract) return;

	FinishInteraction();
}

void ATTLamp::BeginPlay()
{
	Super::BeginPlay();

	CountOfPawnInRadius = 0;
	bReadyToInteract = true;
}
