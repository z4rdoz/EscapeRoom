// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AEscapeRoomCharacter::AEscapeRoomCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscapeRoomCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("HELLO I'M A CHARACTER"));
	}
}

// Called every frame
void AEscapeRoomCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEscapeRoomCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AEscapeRoomCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AEscapeRoomCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AEscapeRoomCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AEscapeRoomCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &Super::Jump);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &Super::StopJumping);
}

void AEscapeRoomCharacter::MoveForward(float val)
{
	if (Controller != nullptr && val != 0.0f)
	{
		FRotator rotation = Controller->GetControlRotation();
		
		UCharacterMovementComponent* characterMovement = GetCharacterMovement();

		if (characterMovement->IsMovingOnGround() || characterMovement->IsFalling())
		{
			rotation.Pitch = 0.0f;
		}

		const FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(direction, val);
	}
}

void AEscapeRoomCharacter::MoveRight(float val)
{
	if (Controller != nullptr && val != 0.0f)
	{
		const FRotator rotation = Controller->GetControlRotation();
		const FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(direction, val);
	}
}

