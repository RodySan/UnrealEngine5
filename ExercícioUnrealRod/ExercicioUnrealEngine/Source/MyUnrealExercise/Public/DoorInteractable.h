#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyDoorInterface.h"
#include "DoorInteractable.generated.h"

UCLASS()
class MYUNREALEXERCISE_API ADoorInteractable : public AActor, public IMyDoorInterface
{
	GENERATED_BODY()

public:
	ADoorInteractable();

	virtual void Interact_Implementation(AActor* Interactor) override;
};