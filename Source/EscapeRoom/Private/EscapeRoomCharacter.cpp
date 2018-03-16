// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.h"

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

	_hud = Cast<AEscapeRoomHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
}
// Called every frame
void AEscapeRoomCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Controller != nullptr)
	{
		FVector viewLoc;
		FRotator viewRot;
		Controller->GetPlayerViewPoint(viewLoc, viewRot);

		const FVector startTrace = viewLoc;
		const FVector direction = viewRot.Vector();
		const FVector endTrace = startTrace + direction * UseDistance;

		FCollisionQueryParams traceParams(FName(TEXT("Use Trace")), true, Controller->GetPawn());
		traceParams.bTraceAsyncScene = true;
		traceParams.bReturnPhysicalMaterial = true;

		FHitResult hit(ForceInit);
		Controller->GetWorld()->LineTraceSingleByChannel(hit, startTrace, endTrace, ECC_Pawn, traceParams);
		AActor* hitActor = hit.GetActor();

		//Handle examine/use target	
		//Do examining/Using
		//TODO Roll usable and examinable into one base component that highlights, and make them inherit from it.
		if (!bPressedJump && _hud->GetGameState() != EEscapeRoomState::Examining)
		{
			if (hitActor)
			{
				UExaminableComponent* examinableNew = hitActor->FindComponentByClass<UExaminableComponent>();				
				if (_examinable != nullptr && _examinable != examinableNew)
				{
					_examinable->OnMouseOut();
				}
				if (examinableNew != nullptr)
				{
					_examinable = examinableNew;
					_examinable->OnMouseIn();
				}

				//Same thing for usable. If this goes beyond three repititions, refactor
				UUsableComponent* usableNew = hitActor->FindComponentByClass<UUsableComponent>();
				if (_usable != nullptr && _usable != usableNew)
				{
					_usable->OnMouseOut();
				}
				if (usableNew != nullptr)
				{
					_usable = usableNew;
					_usable->OnMouseIn();
				}
			}
			else
			{
				if (_examinable != nullptr)
				{
					_examinable->OnMouseOut();
					_examinable = nullptr;
				}

				if (_usable != nullptr)
				{
					_usable->OnMouseOut();
					_usable = nullptr;
				}
			}
		}

	}
}

// Called to bind functionality to input
void AEscapeRoomCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (PlayerInputComponent != nullptr) 
	{
		Super::SetupPlayerInputComponent(PlayerInputComponent);

		PlayerInputComponent->BindAxis("MoveForward", this, &AEscapeRoomCharacter::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &AEscapeRoomCharacter::MoveRight);
		PlayerInputComponent->BindAxis("Turn", this, &AEscapeRoomCharacter::YMouse);
		PlayerInputComponent->BindAxis("LookUp", this, &AEscapeRoomCharacter::XMouse);

		PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AEscapeRoomCharacter::EJump);
		PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &ACharacter::StopJumping);

		PlayerInputComponent->BindAction("Use", EInputEvent::IE_Pressed, this, &AEscapeRoomCharacter::Use);
		PlayerInputComponent->BindAction("Examine", EInputEvent::IE_Pressed, this, &AEscapeRoomCharacter::Examine);
	}
}

void AEscapeRoomCharacter::YMouse(float val)
{
	if (_hud->GetGameState() == EEscapeRoomState::Default)
	{
		AddControllerYawInput(val);
	}
}

void AEscapeRoomCharacter::XMouse(float val)
{
	if (_hud->GetGameState() == EEscapeRoomState::Default)
	{
		AddControllerPitchInput(val);
	}
}

void AEscapeRoomCharacter::MoveForward(float val)
{
	if (Controller != nullptr && val != 0.0f && _hud->GetGameState() == EEscapeRoomState::Default)
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
	if (Controller != nullptr && val != 0.0f && _hud->GetGameState() == EEscapeRoomState::Default)
	{
		const FRotator rotation = Controller->GetControlRotation();
		const FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(direction, val);
	}
}

void AEscapeRoomCharacter::Examine()
{		
	if (!TryStopExamining() && _examinable)
	{
		_examinable->Examine();
		_hud->SetGameState(EEscapeRoomState::Examining);
	}
}


void AEscapeRoomCharacter::Use()
{
	if (!TryStopExamining() && _usable)
	{
		_usable->Use();
	}
}

void AEscapeRoomCharacter::EJump()
{
	if (!TryStopExamining())
	{
		Jump();
	}
}

bool AEscapeRoomCharacter::TryStopExamining()
{
	//Checks if input is free to fulfill it's primary purpose, or if it's doing something else
	if (_examinable && _hud->GetGameState() == EEscapeRoomState::Examining)
	{
		_examinable->StopExamining();
		_hud->SetGameState(EEscapeRoomState::Default);
		return true;
	}
	return false;
}
