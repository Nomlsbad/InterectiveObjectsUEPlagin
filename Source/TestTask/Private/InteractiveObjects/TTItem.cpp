// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObjects/TTItem.h"
#include "Components/SphereComponent.h"

ATTItem::ATTItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<USphereComponent>(ATTBaseInteractiveActor::CollisionComponentName))
{
	
}
