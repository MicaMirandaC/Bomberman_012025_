// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"

// Sets default values
AMuro::AMuro()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshMuro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshMuro"));
	MeshMuro->SetupAttachment(RootComponent);

	//static  solo pude existir una sola vez en una clase, se define un objeto estatico
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMeshMuro(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (ObjetoMeshMuro.Succeeded())
	{
		MeshMuro->SetStaticMesh(ObjetoMeshMuro.Object);

		MeshMuro->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	//para asignar textura al bloque
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ObjetoMuroMaterial(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
	if (ObjetoMuroMaterial.Succeeded())
	{
		MeshMuro->SetMaterial(0, ObjetoMuroMaterial.Object);

	}

	bPuedeGirar = false; // Se asignará desde el GameMode
	RotationSpeed = 50.0f; // Velocidad de rotación por defecto
	// Establecer el tamaño inicial del Muro
	AjustarTamanoMuro(FVector(2.5f, 2.5f, 2.5f)); // Tamaño por defecto
}

// Called when the game starts or when spawned
void AMuro::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bPuedeGirar)
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += RotationSpeed * DeltaTime;
		SetActorRotation(NewRotation);
	}
}

void AMuro::AjustarTamanoMuro(FVector NuevoTamano)
{
	MeshMuro->SetWorldScale3D(NuevoTamano);
}