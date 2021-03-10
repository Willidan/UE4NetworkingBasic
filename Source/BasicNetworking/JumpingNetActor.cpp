// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpingNetActor.h"
#include "DebugMessageMacro.h"

// Sets default values
AJumpingNetActor::AJumpingNetActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorMesh"));
	RootComponent = ActorMesh;
	ActorMesh->SetSimulatePhysics(true);

	Interactable = CreateDefaultSubobject<UInteractableComponent>(TEXT("Interactable"));

	SetReplicates(true);
}

// Called when the game starts or when spawned
void AJumpingNetActor::BeginPlay()
{
	Super::BeginPlay();

	Interactable->OnInteract.AddDynamic(this, &AJumpingNetActor::OnInteract);
}

// Called every frame
void AJumpingNetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AJumpingNetActor::Jump()
{
	DM_B("%s jumped!", *GetName())
	ActorMesh->AddImpulse(FVector(0.f,0.f,100000.f));
}

void AJumpingNetActor::OnInteract()
{
	Jump();
}


