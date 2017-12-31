// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEROOM_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BaseWidget)
		FString DialogText;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BaseWidget)
		ESlateVisibility ShowExamine = ESlateVisibility::Hidden;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BaseWidget)
		ESlateVisibility ShowUse = ESlateVisibility::Hidden;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BaseWidget)
		ESlateVisibility ShowTarget = ESlateVisibility::Visible;

};
