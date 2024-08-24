// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BoardCar.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class C4F_DRIVER_API UBoardCar : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBoardCar();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY ( EditAnywhere, BlueprintReadWrite, Category="Driver",
		        meta=(AllowPrivateAccess="true")
		      ) TSubclassOf<class AActor> CarClass;

	APawn *TargetCar;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable) void ScanVehicle(AActor *NewVehicle);
	UFUNCTION(BlueprintCallable) void IgnoreVehicle(AActor *Vehicle);
	UFUNCTION(BlueprintCallable) void BoardVehicle();
};
