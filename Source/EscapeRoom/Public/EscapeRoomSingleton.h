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
