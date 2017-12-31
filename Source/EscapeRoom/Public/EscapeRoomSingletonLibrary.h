// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "EscapeRoomSingleton.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EscapeRoomSingletonLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEROOM_API UEscapeRoomSingletonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category = "Escape Room Singleton")
		static UEscapeRoomSingleton* GetSingleton();
	
	
};
