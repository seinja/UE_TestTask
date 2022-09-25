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

void ATestTaskCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ThisClass::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ThisClass::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ThisClass::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ThisClass::LookUp);
}

void ATestTaskCharacter::MoveForward(const float Value)
{
	if(Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, Value);
	}
}

void ATestTaskCharacter::MoveRight(const float Value)
{
	if(Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction, Value);
	}
}

void ATestTaskCharacter::Turn(const float Value)
{
	AddControllerYawInput(Value);
}

void ATestTaskCharacter::LookUp(const float Value)
{
	AddControllerPitchInput(Value);
}

void ATestTaskCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}