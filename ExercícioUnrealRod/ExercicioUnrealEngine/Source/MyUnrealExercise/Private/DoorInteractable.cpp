#include "DoorInteractable.h"
#include "Engine/Engine.h"

ADoorInteractable::ADoorInteractable()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADoorInteractable::Interact_Implementation(AActor* Interactor)
{
    IMyDoorInterface::Execute_Interact(this, Interactor);

    UE_LOG(LogTemp, Warning, TEXT("A porta foi interagida por %s"), *GetNameSafe(Interactor));
}