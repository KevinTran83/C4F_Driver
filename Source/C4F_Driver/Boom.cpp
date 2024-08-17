// Fill out your copyright notice in the Description page of Project Settings.


#include "Boom.h"

// Sets default values for this component's properties
UBoom::UBoom()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	ZoomStrength = -25;
	MinArmLength = 0;
	MaxArmLength = 700;
	// ...
}


// Called when the game starts
void UBoom::BeginPlay()
{
	Super::BeginPlay();

	SpringArm = GetOwner()->FindComponentByClass<USpringArmComponent>();

	// ...
	
}


// Called every frame
void UBoom::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBoom::Orbit(float AxisX, float AxisY)
{
	if (SpringArm == nullptr) return;
	FRotator amount = FRotator(-AxisY, -AxisX, 0);
	SpringArm->AddRelativeRotation(amount);
}

void UBoom::Zoom(float Strength)
{
	if (SpringArm == nullptr) return;
	float zoomAmount = ZoomStrength * Strength;
	float prevLength = SpringArm->TargetArmLength;
	SpringArm->TargetArmLength = FMath::Clamp ( prevLength + zoomAmount,
		                                        MinArmLength,
		                                        MaxArmLength
		                                      );
}