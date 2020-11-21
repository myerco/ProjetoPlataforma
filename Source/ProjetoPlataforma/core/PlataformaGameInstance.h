// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlataformaGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJETOPLATAFORMA_API UPlataformaGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPlataformaGameInstance(const FObjectInitializer& ObjectInitializer);
	
	virtual void Init();
};
