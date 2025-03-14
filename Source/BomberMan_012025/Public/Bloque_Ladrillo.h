#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque_Ladrillo.generated.h"

// Declaración de clases necesarias
class UStaticMeshComponent;
class UMaterialInterface;

UCLASS()
class BOMBERMAN_012025_API ABloque_Ladrillo : public AActor
{
    GENERATED_BODY()

public:
    // Constructor predeterminado
    ABloque_Ladrillo();

protected:
    // Llamado al inicio del juego
    virtual void BeginPlay() override;

public:
    // Llamado cada cuadro
    virtual void Tick(float DeltaTime) override;

    // Ajustar tamaño del bloque
    UFUNCTION(BlueprintCallable, Category = "Bloque")
    void AjustarTamanoAcero(FVector NuevoTamano);

    // Componente de malla del bloque
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bloque")
    UStaticMeshComponent* MeshBloque_Ladrillo;

    // Material del bloque
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
    UMaterialInterface* BloqueMaterial;

    // Velocidad del movimiento vertical
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    float velocidad;

    // Amplitud del movimiento (distancia máxima de desplazamiento)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    float amplitud;

private:
    // Posición inicial del objeto en el eje Z
    float PosicionInicial;
};
