// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Engine.h"
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "UObject/NoExportTypes.h"
#include "MiscStatics.generated.h"

/**
 * A static library of helper functions and structs
 */
UCLASS()
class ESCAPEROOM_API UMiscStatics : public UObject
{
	GENERATED_BODY()


	// Credit to user Rama for guidelines on static library class and the following function
	// See https://wiki.unrealengine.com/Trace_Functions
	static FORCEINLINE bool Trace(
		UWorld* World,
		AActor* ActorToIgnore,
		const FVector& Start,
		const FVector& End,
		FHitResult& HitOut,
		ECollisionChannel CollisionChannel = ECC_Pawn,
		bool ReturnPhysMat = false
	) 
	{
		if (!World)
		{
			return false;
		}

		FCollisionQueryParams TraceParams(FName(TEXT("Misc Trace")), true, ActorToIgnore);
		TraceParams.bTraceComplex = true;
		//TraceParams.bTraceAsyncScene = true;
		TraceParams.bReturnPhysicalMaterial = ReturnPhysMat;

		//Ignore Actors
		TraceParams.AddIgnoredActor(ActorToIgnore);

		//Re-initialize hit info
		HitOut = FHitResult(ForceInit);

		//Trace!
		World->LineTraceSingleByChannel(
			HitOut,		//result
			Start,	//start
			End, //end
			CollisionChannel, //collision channel
			TraceParams
		);

		//Hit any Actor?
		return (HitOut.GetActor() != NULL);
	}
	//Component-level trace, do a trace against just 1 component
	static FORCEINLINE bool TraceComponent(
		UPrimitiveComponent* TheComp,
		const FVector& Start,
		const FVector& End,
		FHitResult& HitOut
	) {
		if (!TheComp) return false;
		if (!TheComp->IsValidLowLevel()) return false;
		//~~~~~~~~~~~~~~~~~~~~~

		FCollisionQueryParams TraceParams(FName(TEXT("Misc Comp Trace")), true, NULL);
		TraceParams.bTraceComplex = true;
		//TraceParams.bTraceAsyncScene = true;
		TraceParams.bReturnPhysicalMaterial = false;

		//Ignore Actors
		//TraceParams.AddIgnoredActors(ActorsToIgnore);

		//Re-initialize hit info
		HitOut = FHitResult(ForceInit);

		return TheComp->LineTraceComponent(
			HitOut,
			Start,
			End,
			TraceParams
		);
	}
};
