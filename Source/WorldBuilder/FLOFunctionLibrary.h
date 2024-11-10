// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/WidgetAnimation.h"
#include "components/Widget.h"
#include "Blueprint/WidgetTree.h"
#include "Blueprint/WidgetBlueprintGeneratedClass.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FLOFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class WORLDBUILDER_API UFLOFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	
	static TArray<FVector> GetBeizerPath(FVector Start, FVector End, FVector StartTangent, FVector EndTangent);

	UFUNCTION(BlueprintPure)
	static FString GetRandomString(int32 Length);

	UFUNCTION(BlueprintPure)
	static UWidget* GetChildWidget(UUserWidget* ParentWidget, FName childName);

	UFUNCTION(BlueprintCallable)
	static void ShiftChildWidget(UPanelWidget* ParentWidget, int32 Index, UWidget* ChildWidget);

	UFUNCTION(BlueprintPure)
	static UWidgetAnimation* GetAnimationByName(UUserWidget* ParentWidget, FName AnimationName);

	
};
