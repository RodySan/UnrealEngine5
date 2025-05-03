#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyDoorInterface.generated.h"


class AActor;


UINTERFACE(Blueprintable)
class MYUNREALEXERCISE_API UMyDoorInterface : public UInterface
{
	GENERATED_BODY()
};


class MYUNREALEXERCISE_API IMyDoorInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Interact(AActor* Interactor);
};