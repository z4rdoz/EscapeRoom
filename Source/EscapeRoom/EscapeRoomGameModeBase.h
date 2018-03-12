// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EscapeRoomGameModeBase.generated.h"

UENUM(BlueprintType)
enum class EEscapeRoomState : uint8
{
	Default,
	Examining
	//An example of the DiaplyName property. Credit to Rama's (MANY) wiki entries for help exposing to blueprints
	//https://wiki.unrealengine.com/Enums_For_Both_C%2B%2B_and_BP
	//VE_Song	UMETA(DisplayName = "Song")
};

/**
 * 
 */
UCLASS()
class ESCAPEROOM_API AEscapeRoomGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AEscapeRoomGameModeBase();

	void StartPlay() override;	
};
