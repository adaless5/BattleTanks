// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank(); 
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Not Possessing a Tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Possesing: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	if (Cast<ATank>(GetPawn()) == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("NoTank"));
	}
	else if (Cast<ATank>(GetPawn()) != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank!"));
	}

	return Cast<ATank>(GetPawn()); 
}

