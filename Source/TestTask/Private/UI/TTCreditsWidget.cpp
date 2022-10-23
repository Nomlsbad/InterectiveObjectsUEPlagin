// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TTCreditsWidget.h"
#include "Components/Button.h"


void UTTCreditsWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	GoBackButton->OnClicked.AddDynamic(this, &UTTCreditsWidget::OnGoBack);
}

void UTTCreditsWidget::OnGoBack()
{
	GoBack();
}
