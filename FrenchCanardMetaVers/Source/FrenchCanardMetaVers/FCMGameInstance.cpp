// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "FCMGameInstance.h"

void UFCMGameInstance::Init()
{
	Super::Init();
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if (OnlineSubsystem != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found subsystem = %s"), *OnlineSubsystem->GetSubsystemName().ToString());
		SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Session interface found"))
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UFCMGameInstance::OnCreateSessionComplete);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found no subsystem"));
	}
	
}

void UFCMGameInstance::OnCreateSessionComplete(FName SessionName, bool Success)
{
	if (!Success)
	{
		UE_LOG(LogTemp, Error, TEXT("Create session failed !"));
		return;
	}
	FOnlineSessionSettings SessionSettings;
	SessionInterface->CreateSession(0, TEXT("French Canard Metavers"), SessionSettings);
}
