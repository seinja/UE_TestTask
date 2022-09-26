// Fill out your copyright notice in the Description page of Project Settings.


#include "Hud/OverheadWidget.h"
#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if(DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(const APawn* InPawn)
{
	const ENetRole LocalRole = InPawn->GetLocalRole();
	FString Role;
	switch(LocalRole)
	{
	case ROLE_Authority:
		Role = FString("Authority");
		break;
	case ROLE_AutonomousProxy:
        Role = FString("Autonomous Proxy");
        break;
    case ROLE_SimulatedProxy:
        Role = FString("Simulated Proxy");
        break;
    case ROLE_None:
        Role = FString("NONE");
        break;
	default:
		break;
	}

	const FString LocalRoleString = FString::Printf(TEXT("Local role : %s"), *Role);
	SetDisplayText(LocalRoleString);
}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}
