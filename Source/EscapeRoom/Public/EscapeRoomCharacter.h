// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Engine.h"
#include "CoreMinimal.h"
#include "Casts.h"
#include "ExaminableComponent.h"
#include "GameFramework/Character.h"
#include "Widget.h"
#include "EscapeRoomSingletonLibrary.h"
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
	UFUNCTION()
		void Examine();

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = EscapeRoomCharacter)
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = EscapeRoomCharacter)
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = EscapeRoomCharacter)
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EscapeRoomProperties)
		int UseDistance = 100;

private:
	UExaminableComponent* _examinable;
	UEscapeRoomSingleton* _singleton;
};
