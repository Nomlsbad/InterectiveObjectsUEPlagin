// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTPressurePlate.h"	

ATTPressurePlate::ATTPressurePlate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UStaticMeshComponent>(ATTBaseInteractiveActor::CollisionComponentName))
{
	Base =CreateDefaultSubobject<UStaticMeshComponent>("Base");
	SetRootComponent(Base);
	
	Plate = CreateDefaultSubobject<UStaticMeshComponent>("Plate");
	Plate->SetupAttachment(GetRootComponent());

	CollisionComponent->SetupAttachment(Plate);
	CollisionComponent->SetVisibility(false);
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ATTPressurePlate::OnOverlapBegin);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ATTPressurePlate::OnOverlapEnd);
}

void ATTPressurePlate::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CountOfOverlappingObjects += 1;
	if (!bReadyToInteract) return;

	bReadyToInteract = false;
	
	StartInteraction();
}

void ATTPressurePlate::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	CountOfOverlappingObjects -= 1;
	bReadyToInteract = CountOfOverlappingObjects == 0;
	if (!bReadyToInteract) return;
	
	FinishInteraction();
}

void ATTPressurePlate::BeginPlay()
{
	Super::BeginPlay();

	CountOfOverlappingObjects = 0;
	bReadyToInteract = true;
}
