// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Engine.h"
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Components/ActorComponent.h"
#include "Examinable.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UExaminable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UExaminable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Examinable)
		FString ExamineText = "Don't leave this text naked";

	void IsHighlight(bool isHighlight);

	void Examine();
};
