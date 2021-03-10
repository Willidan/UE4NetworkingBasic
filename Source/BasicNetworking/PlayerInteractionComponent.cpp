// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractionComponent.h"

#include "DebugMessageMacro.h"

// Sets default values for this component's properties
UPlayerInteractionComponent::UPlayerInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

bool UPlayerInteractionComponent::IsInteractableInRange() const
{
	return InteractablesInRange.Num() > 0;
}

UInteractableComponent* UPlayerInteractionComponent::GetClosestInteractable()
{
	if(!IsInteractableInRange())
	{
		return nullptr;
	}
	
	FVector PlayerLocation = GetOwner()->GetActorLocation();
	InteractablesInRange.Sort([PlayerLocation](const UInteractableComponent& FirstInteractable, const UInteractableComponent& SecondInteractable)
    {
		const float DistanceToFirst = FVector::Dist(PlayerLocation, FirstInteractable.GetOwner()->GetActorLocation());
		const float DistanceToSecond = FVector::Dist(PlayerLocation, SecondInteractable.GetOwner()->GetActorLocation());
		
        return DistanceToFirst < DistanceToSecond;
    });

	return InteractablesInRange[0];
}

// Called every frame
void UPlayerInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPlayerInteractionComponent::AddInteractableInRange(UInteractableComponent* Interactable)
{
	if(IsValid(Interactable))
	{
		InteractablesInRange.AddUnique(Interactable);
	}
}

void UPlayerInteractionComponent::RemoveInteractableInRange(UInteractableComponent* Interactable)
{
	if(IsValid(Interactable))
	{
		InteractablesInRange.Remove(Interactable);
	}
}

void UPlayerInteractionComponent::TryInteract()
{
	UInteractableComponent* Interactable = GetClosestInteractable();
	
	if(!IsValid(Interactable) || !Interactable->CanInteract())
	{
		DM_R("Interactable not valid or doesn't allow interaction")
		return;
	}

	Interactable->Interact();
}

