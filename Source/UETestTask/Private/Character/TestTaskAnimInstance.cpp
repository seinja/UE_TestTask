// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/TestTaskAnimInstance.h"
#include "Character/TestTaskCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UTestTaskAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	Character = Cast<ATestTaskCharacter>(TryGetPawnOwner());
}

void UTestTaskAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(Character == nullptr)
	{
		Character = Cast<ATestTaskCharacter>(TryGetPawnOwner());
	}
	if(Character == nullptr) return;

	FVector Velocity = Character->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = Character->GetCharacterMovement()->IsFalling();
	bIsAccelerating = Character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0 ? true : false;
	bWeaponEquipped = Character->IsWeaponEquipped();
	bIsCrouched = Character->bIsCrouched;
	bAiming = Character->IsAiming();
}
