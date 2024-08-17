// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "Boom.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class C4F_DRIVER_API UBoom : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBoom();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	USpringArmComponent *SpringArm;

	UPROPERTY ( EditAnywhere, BlueprintReadWrite, Category="Driver",
		        meta=( AllowPrivateAccess="true" )
	          ) float ZoomStrength;
	UPROPERTY ( EditAnywhere, BlueprintReadWrite, Category="Driver",
		        meta=( AllowPrivateAccess="true" )
	          ) float MinArmLength;
	UPROPERTY ( EditAnywhere, BlueprintReadWrite, Category="Driver",
		        meta=( AllowPrivateAccess="true" )
	          ) float MaxArmLength;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable) void Orbit(float AxisX, float AxisY);
	UFUNCTION(BlueprintCallable) void Zoom(float Strength);
};
