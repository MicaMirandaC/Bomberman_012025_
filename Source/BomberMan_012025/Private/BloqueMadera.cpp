// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABloqueMadera::ABloqueMadera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshBloqueMadera = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBloqueMadera"));
	MeshBloqueMadera->SetupAttachment(RootComponent);

	//static  solo pude existir una sola vez en una clase, se define un objeto estatico
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshBloqueMadera(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ObjetoMeshBloqueMadera.Succeeded())
	{
		MeshBloqueMadera->SetStaticMesh(ObjetoMeshBloqueMadera.Object);
		MeshBloqueMadera->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura al bloque
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoBloqueMaderaMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
	if (ObjetoBloqueMaderaMaterial.Succeeded())
	{
		MeshBloqueMadera->SetMaterial(0, ObjetoBloqueMaderaMaterial.Object);
	}

	// Inicializar variables
	bAbriendo = false;
	VelocidadMovimiento = 100.0f; // Velocidad de movimiento
	DistanciaApertura = 200.0f;   // Distancia máxima de apertura
	PosicionInicial = FVector::ZeroVector; // Se inicializará en BeginPlay

	AjustarTamanoMadera(FVector(2.7f, 2.7f, 2.7f));
}

// Called when the game starts or when spawned
void ABloqueMadera::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation(); // Guardar la posición inicial
}

// Called every frame
void ABloqueMadera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Obtener la posición actual del bloque
	FVector NuevaPosicion = GetActorLocation();

	// Mover hacia la derecha (abrir) o hacia la izquierda (cerrar) según el estado
	if (bAbriendo)
	{
		// Mover hacia la derecha (abrir)
		NuevaPosicion.X += VelocidadMovimiento * DeltaTime;
		if (NuevaPosicion.X >= PosicionInicial.X + DistanciaApertura)
		{
			bAbriendo = false; // Cambiar dirección a cerrar
		}
	}
	else
	{
		// Mover hacia la izquierda (cerrar)
		NuevaPosicion.X -= VelocidadMovimiento * DeltaTime;
		if (NuevaPosicion.X <= PosicionInicial.X)
		{
			bAbriendo = true; // Cambiar dirección a abrir
		}
	}

	// Aplicar la nueva posición
	SetActorLocation(NuevaPosicion);
}

void ABloqueMadera::AjustarTamanoMadera(FVector NuevoTamano)
{
	MeshBloqueMadera->SetWorldScale3D(NuevoTamano);
}