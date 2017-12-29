// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Blueprint/UserWidget.h"

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

	if (TextWidget != nullptr)
	{
		_textWidget = CreateWidget<UUserWidget>(GetWorld(), TextWidget);
		if (_textWidget)
		{
			_textWidget->AddToViewport();						
		}
	}
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

		if (hitActor)
		{
			UExaminable* examinableNew = hitActor->FindComponentByClass<UExaminable>();

			if (_examinable != nullptr && _examinable != examinableNew)
			{
				_examinable->IsHighlight(false);
			}
			if (examinableNew != nullptr)
			{
				_examinable = examinableNew;
				_examinable->IsHighlight(true);
				WidgetText = _examinable->ExamineText;
			}
			else
			{
				WidgetText = "";
			}
		}
		else
		{
			if (_examinable != nullptr)
			{
				_examinable->IsHighlight(false);
				_examinable = nullptr;
				WidgetText = "";
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
		PlayerInputComponent->BindAxis("Turn", this, &AEscapeRoomCharacter::AddControllerYawInput);
		PlayerInputComponent->BindAxis("LookUp", this, &AEscapeRoomCharacter::AddControllerPitchInput);

		PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACharacter::Jump);
		PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &ACharacter::StopJumping);

		PlayerInputComponent->BindAction("Use", EInputEvent::IE_Released, this, &AEscapeRoomCharacter::Use);
	}
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

void AEscapeRoomCharacter::Use()
{
	
}

