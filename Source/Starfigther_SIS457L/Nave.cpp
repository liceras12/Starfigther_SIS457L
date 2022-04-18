// Fill out your copyright notice in the Description page of Project Settings.


#include "Nave.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ANave::ANave()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Starship = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Starship"));
	RootComponent = Starship;

	Starship->SetEnableGravity(false);
	Starship->SetConstraintMode(EDOFMode::XZPlane);
	Starship->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Starship->SetCollisionProfileName(TEXT("PhysicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));


}

// Called when the game starts or when spawned
void ANave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANave::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANave::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), 10.0f, false);
}

void ANave::MoveVertical(float AxisValue)
{
	AddMovementInput(FVector(0.0f, 0.0f, AxisValue), 10.0f, false);
}

