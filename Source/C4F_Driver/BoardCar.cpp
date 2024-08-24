// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardCar.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UBoardCar::UBoardCar()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBoardCar::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBoardCar::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBoardCar::ScanVehicle(AActor *NewVechicle)
{
	if (!NewVechicle->IsA(CarClass)) return;
	APawn *vehicle = Cast<APawn>(NewVechicle);
	TargetCar = vehicle;
}

void UBoardCar::IgnoreVehicle(AActor *Vehicle)
{
	if (TargetCar == Vehicle) TargetCar = nullptr;
}

void UBoardCar::BoardVehicle()
{
	if (TargetCar == nullptr) return;

	GetOwner()->SetActorHiddenInGame(true);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(TargetCar);
}