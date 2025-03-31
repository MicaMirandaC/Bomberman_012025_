// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueConcreto.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"


// Sets default values
ABloqueConcreto::ABloqueConcreto()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshBloqueConcreto = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBloqueConcreto"));
	RootComponent = MeshBloqueConcreto;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshBloqueConcretoAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MeshBloqueConcretoAsset.Succeeded())
	{
		MeshBloqueConcreto->SetStaticMesh(MeshBloqueConcretoAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> BloqueConcretoMaterialAsset(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Copper.M_Metal_Copper'"));
	if (BloqueConcretoMaterialAsset.Succeeded())
	{
		MeshBloqueConcreto->SetMaterial(0, BloqueConcretoMaterialAsset.Object);
	}

	AjustarTamanoConcreto(FVector(2.7f, 2.7f, 2.7f));


}

// Called when the game starts or when spawned
void ABloqueConcreto::BeginPlay()
{
	Super::BeginPlay();

}
// Called every frame
void ABloqueConcreto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();

	// Movimiento en el eje X (lado a lado)
	float DeltaX = FMath::Sin(GetWorld()->GetTimeSeconds() * 2.0f) * 5.0f; // Oscilación en X

	// Movimiento en el eje Z (arriba y abajo)
	float DeltaZ = FMath::Sin(GetWorld()->GetTimeSeconds() * 3.0f) * 5.0f; // Oscilación en Z

	// Aplicar el movimiento
	NewLocation.X += DeltaX;
	NewLocation.Z = 50.0f + DeltaZ;  // Base elevada para que no se hunda en el suelo

	SetActorLocation(NewLocation);

}

void ABloqueConcreto::AjustarTamanoConcreto(FVector NuevoTamano)
{
	MeshBloqueConcreto->SetWorldScale3D(NuevoTamano);
}