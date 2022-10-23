// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TTSettingsWidget.h"
#include "Components/Button.h"


void UTTSettingsWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (GoBackButton)
	{
		GoBackButton->OnClicked.AddDynamic(this, &UTTSettingsWidget::OnGoBack);
	}
}

void UTTSettingsWidget::OnGoBack()
{
	GoBack();
}	
