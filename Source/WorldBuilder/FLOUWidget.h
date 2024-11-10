// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FLOUWidget.generated.h"

/**
 * 
 */
UCLASS()
class WORLDBUILDER_API UFLOUWidget : public UUserWidget
{
	GENERATED_BODY()

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;

#endif
	
};
