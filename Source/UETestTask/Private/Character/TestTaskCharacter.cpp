// Fill out your copyright notice in the Description page of Project Settings.

#include "UETestTask/Public/Character/TestTaskCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ATestTaskCharacter::ATestTaskCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	ArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("ArmComponent"));
	ArmComponent->SetupAttachment(GetMesh());
	ArmComponent->TargetArmLength = 600.f;
	ArmComponent->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	Camera->SetupAttachment(ArmComponent, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
}

void ATestTaskCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATestTaskCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestTaskCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

