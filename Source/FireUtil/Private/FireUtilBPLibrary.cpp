// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "FireUtilPrivatePCH.h"
#include "FireUtilBPLibrary.h"

UFireUtilBPLibrary::UFireUtilBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UFireUtilBPLibrary::TraceVectorLengthAxis(USceneComponent* Object, EAxis::Type myAxis, float length, FVector& OutStart, FVector& OutEnd)
{
	// Calculate draw 
	FVector Start = Object->GetComponentLocation();
	FVector EndPoint;

	switch (myAxis)
	{
	case EAxis::Y:
		EndPoint = Object->GetRightVector() * length + Start;
		break;

	case EAxis::Z:
		EndPoint = Object->GetUpVector() * length + Start; 
		break;

	case EAxis::None: // Fall into default
	case EAxis::X: // Fall into default
	default:
		EndPoint = Object->GetForwardVector() * length + Start;
		break;
	}
	// End end vector draw calc

	OutStart = Start;
	OutEnd = EndPoint;
}

void UFireUtilBPLibrary::TraceVectorLengthVector(USceneComponent * Object, FVector Trace, float length, FVector & OutStart, FVector & OutEnd)
{
	FVector Start = Object->GetComponentLocation();
	Trace.Normalize();
	OutEnd = Start + (Trace * length);

	OutStart = Start;
	//OutEnd = EndPoint;
}

