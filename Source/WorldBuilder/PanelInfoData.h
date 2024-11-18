// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/ObjectMacros.h"
#include "UObject/UnrealTypePrivate.h"	

#include "PanelInfoData.generated.h"

class UDataAsset;
class ULevelSequence;
class ALevelSequenceActor;

UENUM(BlueprintType)
enum ECheckTypeENum
{
	Unchecked,
	LatestChecked,
	OldChecked,
	CurrnetlyActive
};

USTRUCT(BlueprintType)
struct FPointInfo
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString IdentfierString;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TEnumAsByte<ECheckTypeENum> CheckType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool isCurrentlyActive;
};

USTRUCT(BlueprintType)
struct FPointListInfo
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FPointInfo> PanelPointlist;
};

USTRUCT(BlueprintType)
struct FPanelInfoStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> UMGPanelWidgetClass;

	UPROPERTY(BlueprintReadWrite)
	FString PanelName;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	TArray<FPointListInfo> PanelPointlist;

};

UCLASS(BlueprintType)
class WORLDBUILDER_API UPanelInfoData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	
	int  currentPanelIndex = -1;

	UPROPERTY(BlueprintReadOnly)
	int totalCompltetionIndex = -1;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	bool isDeveloperMode = false;

	UPROPERTY(BlueprintReadWrite)

	ALevelSequenceActor* currentLevelSequenceActor =false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FPanelInfoStruct> PanelIsSequenceList;

	UFUNCTION(BlueprintCallable)
	void AddPanelToList(FPanelInfoStruct newPanel);

	UFUNCTION(BlueprintCallable)
	void ClearPanelList();

	UFUNCTION(BlueprintCallable)
	void ReplaceInfoAtIndex(FPanelInfoStruct InfoToReplaceWith, int index);

	UFUNCTION(BlueprintCallable)
	void updatePointInfo(FPointInfo InfoItemToUpdate);

	UFUNCTION(BlueprintPure)
	FPanelInfoStruct MoveToNextPanelData();

	UFUNCTION(BlueprintPure)
	FPanelInfoStruct MoveToPanelData(int index);

	UFUNCTION(BlueprintPure)
	FPanelInfoStruct GetPanelInfoByName(FString panelName);

	UFUNCTION(BlueprintPure)
	int GetPanelIndexByName(FString PanelName);



};
