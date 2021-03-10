// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableComponent.h"
#include "DebugMessageMacro.h"
#include "PlayerInteractionComponent.h"

// Sets default values for this component's properties
UInteractableComponent::UInteractableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	DetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));

	if(GetOwner())
	{
		DetectionSphere->SetupAttachment(GetOwner()->GetRootComponent());
	}
	
	DetectionSphere->SetSphereRadius(500.f);
	DetectionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	DetectionSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	DetectionSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	SetCanInteract(true);
}


// Called when the game starts
void UInteractableComponent::BeginPlay()
{
	Super::BeginPlay();

	DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &UInteractableComponent::OnDetectionOverlapStart);
	DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &UInteractableComponent::OnDetectionOverlapEnd);
}

void UInteractableComponent::OnDetectionOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                     UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UPlayerInteractionComponent* PlayerInteraction = OtherActor->FindComponentByClass<UPlayerInteractionComponent>();

	if(PlayerInteraction)
	{
		DM_Y("%s detected Players %s!", *GetOwner()->GetName(), *OtherActor->GetName());

		PlayerInteraction->AddInteractableInRange(this);
	}
}

void UInteractableComponent::OnDetectionOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UPlayerInteractionComponent* PlayerInteraction = OtherActor->FindComponentByClass<UPlayerInteractionComponent>();

	if(PlayerInteraction)
	{
		DM_Y("%s lost Players %s!", *GetOwner()->GetName(), *OtherActor->GetName());

		PlayerInteraction->RemoveInteractableInRange(this);
	}
}


// Called every frame
void UInteractableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UInteractableComponent::CanInteract() const
{
	return bCanInteract;
}

void UInteractableComponent::SetCanInteract(const bool CanInteract)
{
	bCanInteract = CanInteract;
}

void UInteractableComponent::Interact()
{
	OnInteract.Broadcast();
}

