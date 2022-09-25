// Fill out your copyright notice in the Description page of Project Settings.

#include "UETestTask/Public/Character/TestTaskCharacter.h"

// Sets default values
ATestTaskCharacter::ATestTaskCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestTaskCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestTaskCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestTaskCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

