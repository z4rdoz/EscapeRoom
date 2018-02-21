// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Widget.h"
#include "EscapeRoomSingleton.generated.h"
/**
 * 
 */

UENUM(BlueprintType)
enum class EEscapeRoomState : uint8
{
	Default,
	Examining
	//An example of the DiaplyName property. Credit to Rama's (MANY) wiki entries for help exposing to blueprints
	//https://wiki.unrealengine.com/Enums_For_Both_C%2B%2B_and_BP
	//VE_Song	UMETA(DisplayName = "Song")
};


UCLASS(Blueprintable, BlueprintType)
class UEscapeRoomSingleton : public UObject
{
	GENERATED_BODY()

public:
	UEscapeRoomSingleton();

	void Init(UWorld* world);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EscapeRoomSingleton)
		TSubclassOf<class UBaseWidget> TargetWidgetRef;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EscapeRoomSingleton)
		TSubclassOf<class UBaseWidget> ExamineWidgetRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EscapeRoomSingleton)
		EEscapeRoomState EscapeRoomState;

	class UBaseWidget* TargetWidget;
	class UBaseWidget* ExamineWidget;

};
