// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "FCMGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class FRENCHCANARDMETAVERS_API UFCMGameInstance : public UGameInstance
{
	GENERATED_BODY()

public://Functions
	virtual void Init() override;


private://Propertys
	IOnlineSessionPtr SessionInterface;
	
private://Functions
	void OnCreateSessionComplete(FName SessionName, bool Success);
	
};
