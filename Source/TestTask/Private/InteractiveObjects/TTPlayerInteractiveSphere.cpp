// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTPlayerInteractiveSphere.h"
#include "Components/SphereComponent.h"

ATTPlayerInteractiveSphere::ATTPlayerInteractiveSphere(const FObjectInitializer ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<USphereComponent>(ATTBaseInteractiveActor::CollisionComponentName))
{
	SetRootComponent(CollisionComponent);
}
