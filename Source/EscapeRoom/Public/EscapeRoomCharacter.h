// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Engine.h"
#include "CoreMinimal.h"
#include "Casts.h"
#include "Examinable.h"
#include "GameFramework/Character.h"
#include "Widget.h"
#include "EscapeRoomCharacter.generated.h"

UCLASS()
class ESCAPEROOM_API AEscapeRoomCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEscapeRoomCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float val);
	UFUNCTION()
		void MoveRight(float val);
	UFUNCTION()
		void Use();

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = EscapeRoomCharacter)
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = EscapeRoomCharacter)
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = EscapeRoomCharacter)
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EscapeRoomProperties)
		int UseDistance = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EscapeRoomProperties)
		TSubclassOf<UUserWidget> TextWidget;

	UPROPERTY(BlueprintReadOnly)
		FString WidgetText;

private:
	UExaminable* _examinable;
	UUserWidget* _textWidget;
};
