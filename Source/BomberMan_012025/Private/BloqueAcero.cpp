// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueAcero.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"


// Sets default values
ABloqueAcero::ABloqueAcero()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshBloqueAcero = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBloqueAcero"));
	MeshBloqueAcero->SetupAttachment(RootComponent);

	//static  solo pude existir una sola vez en una clase, se define un objeto estatico
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueAcero(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueAcero.Succeeded())
	{
		MeshBloqueAcero->SetStaticMesh(ObjetoMeshBloqueAcero.Object);

		MeshBloqueAcero->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueAceroMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Tech_Panel.M_Tech_Panel'"));
	if (ObjetoBloqueAceroMaterial.Succeeded())
	{
		MeshBloqueAcero->SetMaterial(0, ObjetoBloqueAceroMaterial.Object);

	}

	velocidad = 0.5f;
	AjustarTamanoAcero(FVector(2.7f, 2.7f, 2.7f));
}

// Called when the game starts or when spawned
void ABloqueAcero::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABloqueAcero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float TimeOffset = GetActorLocation().X * 4.0f;  // Desfase para efecto de ola

	// Movimiento en forma circular
	float DeltaHeight = FMath::Sin(GetWorld()->GetTimeSeconds() * velocidad + TimeOffset) * 5.0f; // Oscilación en Z
	float DeltaX = FMath::Sin(GetWorld()->GetTimeSeconds() * velocidad) * 3.0f; // Oscilación en X
	float DeltaY = FMath::Cos(GetWorld()->GetTimeSeconds() * velocidad) * 3.0f; // Oscilación en Y

	NewLocation.Z = 5.0f + DeltaHeight; // Altura de la ola
	NewLocation.X += DeltaX; // Movimiento en X
	NewLocation.Y += DeltaY; // Movimiento en Y

	SetActorLocation(NewLocation);

}

void ABloqueAcero::AjustarTamanoAcero(FVector NuevoTamano)
{
	MeshBloqueAcero->SetWorldScale3D(NuevoTamano);
}