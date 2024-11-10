// Fill out your copyright notice in the Description page of Project Settings.


#include "PanelInfoData.h"

void UPanelInfoData::AddPanelToList(FPanelInfoStruct newPanel)
{
	PanelIsSequenceList.Add(newPanel);
}

void UPanelInfoData::ClearPanelList()
{
	PanelIsSequenceList.Empty();
	totalCompltetionIndex = -1;
	currentPanelIndex = -1;

}

void UPanelInfoData::ReplaceInfoAtIndex(FPanelInfoStruct InfoToReplaceWith, int index)
{
	PanelIsSequenceList[index] = InfoToReplaceWith;
}

void UPanelInfoData::updatePointInfo(FPointInfo InfoItemToUpdate)
{
	for (FPanelInfoStruct panelInfo : PanelIsSequenceList)
	{
		for (FPointListInfo pointListInfo : panelInfo.PanelPointlist)
		{
			for (int i = 0; i < pointListInfo.PanelPointlist.Num(); i++)
			{
				if (pointListInfo.PanelPointlist[i].IdentfierString == InfoItemToUpdate.IdentfierString)
				{
					pointListInfo.PanelPointlist[i] = InfoItemToUpdate;
				}
			}
		}
		
	}

}

FPanelInfoStruct UPanelInfoData::MoveToNextPanelData()
{
	currentPanelIndex++;
	if (currentPanelIndex > totalCompltetionIndex)
		totalCompltetionIndex = currentPanelIndex;
	if (PanelIsSequenceList.IsValidIndex(currentPanelIndex))
	{
		return PanelIsSequenceList[currentPanelIndex];
	}
	

	return FPanelInfoStruct();
}

FPanelInfoStruct UPanelInfoData::MoveToPanelData(int index)
{
	if (PanelIsSequenceList.IsValidIndex(index))
	{
		currentPanelIndex = index;
		return PanelIsSequenceList[currentPanelIndex];
	}

	return FPanelInfoStruct();
}

FPanelInfoStruct UPanelInfoData::GetPanelInfoByName(FString panelName)
{
	for (FPanelInfoStruct panelInfo : PanelIsSequenceList)
	{
		if (panelInfo.PanelName == panelName)
		{
			return panelInfo;
		}
	}

	return FPanelInfoStruct();
}

int UPanelInfoData::GetPanelIndexByName(FString PanelName)
{
	for (int i = 0; i < PanelIsSequenceList.Num(); i++)
	{
		if (PanelIsSequenceList[i].PanelName == PanelName)
		{
			return i;
		}
	}
	return -1;

}
