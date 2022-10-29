// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TTInteractionActorWidget.h"
#include "Components/TTInteractionComponent.h"


bool UTTInteractionActorWidget::GetInteractionText(FString& Text) const
{
	const auto InteractionComponent = GetOwningPlayerPawn()->FindComponentByClass<UTTInteractionComponent>();
	return InteractionComponent->GetInteractionText(Text);
}
