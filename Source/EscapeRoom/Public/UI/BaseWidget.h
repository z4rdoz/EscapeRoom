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

	UFUNCTION(BlueprintCallable, Category = "Messaging")
		void SendMessage(const FString& msg);

	UFUNCTION(BlueprintImplementableEvent, Category = "Messaging")
		void OnMessageReceived(const FString& msg);
};
