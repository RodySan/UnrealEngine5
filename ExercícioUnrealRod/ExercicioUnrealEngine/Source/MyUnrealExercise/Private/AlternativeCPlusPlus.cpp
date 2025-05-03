#include "AlternativeCPlusPlus.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DoorInteractable.h"

AAlternativeCPlusPlus::AAlternativeCPlusPlus()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
}

void AAlternativeCPlusPlus::BeginPlay()
{
	Super::BeginPlay();
}

void AAlternativeCPlusPlus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TraceForInteractable();
}

void AAlternativeCPlusPlus::TraceForInteractable()
{
	FVector Start = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	FVector End = Start + (Forward * 200.0f);

	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	float Radius = 50.f;
	bool bHit = GetWorld()->SweepSingleByChannel(
		Hit,
		Start,
		End,
		FQuat::Identity,
		ECC_Visibility,
		FCollisionShape::MakeSphere(Radius),
		Params
	);

	CurrentLookTarget = bHit ? Hit.GetActor() : nullptr;
	DrawDebugSphere(GetWorld(), bHit ? Hit.ImpactPoint : End, Radius, 12, bHit ? FColor::Red : FColor::Green, false, 0.1f);
}

void AAlternativeCPlusPlus::Interact()
{
	if (CurrentLookTarget)
	{

		if (CurrentLookTarget->GetClass()->ImplementsInterface(UMyDoorInterface::StaticClass()))
		{

			IMyDoorInterface* Interface = Cast<IMyDoorInterface>(CurrentLookTarget);
			if (Interface)
			{

				Interface->Execute_Interact(CurrentLookTarget, this);
			}
			else
			{
			}
		}
		else
		{
		}
	}
	else
	{
	}
}