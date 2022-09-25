// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TestTaskAnimInstance.generated.h"

class ATestTaskCharacter;

UCLASS()
class UETESTTASK_API UTestTaskAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(BlueprintReadOnly, Category="Character", meta =(AllowPrivateAccess = "true"))
	ATestTaskCharacter* Character;

	UPROPERTY(BlueprintReadOnly, Category="Movement", meta =(AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category="Movement", meta =(AllowPrivateAccess = "true"))
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Category="Movement", meta =(AllowPrivateAccess = "true"))
	bool bIsAccelerating;
};
