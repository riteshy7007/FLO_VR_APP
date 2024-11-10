// Fill out your copyright notice in the Description page of Project Settings.


#include "FLOFunctionLibrary.h"

TArray<FVector> UFLOFunctionLibrary::GetBeizerPath(FVector Start, FVector End, FVector StartTangent, FVector EndTangent)
{
	FVector controlpoints[4];
	TArray<FVector> Outpoints;
	controlpoints[0] = Start;
	controlpoints[1] =  StartTangent;
	controlpoints[2] = End;
	controlpoints[3] = EndTangent;
	FVector::EvaluateBezier(controlpoints, 2,Outpoints );
	return Outpoints;

}

FString UFLOFunctionLibrary::GetRandomString(int32 Length)
{
	const int MAX = 26;
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
		'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
		'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
		'y', 'z' };
	FString result= "";
	for (int i = 0; i < Length; i++)
	{
		result += alphabet[rand()%MAX];
	}


	return result;
}

UWidget* UFLOFunctionLibrary::GetChildWidget(UUserWidget* ParentWidget, FName ChildName)
{
	// Check if ParentWidget is valid
	if (!ParentWidget || !ParentWidget->WidgetTree) return nullptr;

	// Get all widgets in the widget tree
	TArray<UWidget*> Children;
	ParentWidget->WidgetTree->GetAllWidgets(Children);

	// Loop through each child widget and check its name
	for (UWidget* Child : Children)
	{
		if (Child && Child->GetFName() == ChildName)
		{
			return Child; // Return the child if name matches
		}
	}
	return nullptr; // Return nullptr if no matching child was found
}

void UFLOFunctionLibrary::ShiftChildWidget(UPanelWidget* ParentWidget, int32 Index, UWidget* ChildWidget)
{
	if (ParentWidget == nullptr || ChildWidget == nullptr || Index <0)
	{
		return;
	}
#if WITH_EDITOR
	ParentWidget->ShiftChild(Index, ChildWidget);
	TArray<UWidget*> tempchildArray;
	for (int i = 0; i < ParentWidget->GetChildrenCount(); i++)
	{
		tempchildArray.Add(ParentWidget->GetChildAt(i));
	}
	ParentWidget->ClearChildren();
	for (int i = 0; i < tempchildArray.Num(); i++)
	{
		ParentWidget->AddChild(tempchildArray[i]);
	}

#endif
}

UWidgetAnimation* UFLOFunctionLibrary::GetAnimationByName(UUserWidget* ParentWidget, FName AnimationName)
{
	if (!ParentWidget) return nullptr;

	// Cast the widget's class to UWidgetBlueprintGeneratedClass
	UWidgetBlueprintGeneratedClass* WidgetClass = Cast<UWidgetBlueprintGeneratedClass>(ParentWidget->GetClass());
	if (WidgetClass)
	{
		// Iterate through animations and check for the name match
		for (UWidgetAnimation* Animation : WidgetClass->Animations)
		{
			if (Animation && Animation->GetFName() == AnimationName)
			{
				return Animation; // Return the animation if the name matches
			}
		}
	}
	return nullptr; // Return nullptr if no matching animation was found
}


