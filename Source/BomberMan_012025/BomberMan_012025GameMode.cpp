// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Character.h"
#include "Engine/Engine.h"
#include "Muro.h"
#include "Bloque.h"
#include "Bloque_Ladrillo.h"



ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}

void ABomberMan_012025GameMode::BeginPlay()
{
    Super::BeginPlay();


    //PARA BLOQUE Y MURO INTERCALADOS
    GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Generando bloques y muros intercalados"));

    const int totalBloques = 5; // Número total de bloques
    const int totalMuros = 5;   // Número total de muros
    const float espacio = 500.0f; // Espacio entre elementos

    TArray<ABloque*> BloquesArray;
    TArray<AMuro*> MurosArray;


    int bloqueCount = 0;
    int muroCount = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            FVector posicion(570.0f + j * espacio, 3000.0f - i * espacio, 5.0f);
            if ((i + j) % 2 == 0 && bloqueCount < totalBloques)
            {
                ABloque* Bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
                if (Bloque)
                {
                    BloquesArray.Add(Bloque);
                }
                bloqueCount++;

            }
            else if (muroCount < totalMuros)
            {
                AMuro* Muro = GetWorld()->SpawnActor<AMuro>(AMuro::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
                if (Muro)
                {
                    MurosArray.Add(Muro);
                }
                muroCount++;
            }
        }
    }

    // Asignar dos bloques para moverse
    if (BloquesArray.Num() >= 2)
    {
        BloquesArray[0]->bPuedeMoverse = true;
        BloquesArray[1]->bPuedeMoverse = true;
    }

    // Asignar dos muros para girar
    if (MurosArray.Num() >= 2)
    {
        MurosArray[0]->bPuedeGirar = true;
        MurosArray[1]->bPuedeGirar = true;
    }

    /*
    int numeroBloqueConMovimiento = 0;
    const int filas = 5; // Número de filas
    const int columnas = 5; // Número de columnas
    const float espacio = 500.0f; // Espacio entre bloques

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            // Calcular la posición de cada bloque
            FVector posicion(570.0f + j * espacio, 3000.0f - i * espacio, 5.0f);
            ABloque* Bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));

            if (Bloque->bPuedeMoverse)
            {
                numeroBloqueConMovimiento++;
            }

            // Limitar el número de bloques que pueden moverse
            if (numeroBloqueConMovimiento >= 5)
            {
                Bloque->bPuedeMoverse = false;
            }
        }
    }

    //PARA MURO
    const int filasM = 3; // Número de filas
    const int columnasM = 3; // Número de columnas
    const float espacioM = 550.0f; // Espacio entre bloques

    for (int i = 0; i < filasM; i++)
    {
        for (int j = 0; j < columnasM; j++)
        {
            // Calcular la posición de cada Muro
            FVector posicion(400.0f + j * espacioM, 1500.0f - i * espacioM, 5.0f);
            AMuro* Muro = GetWorld()->SpawnActor<AMuro>(AMuro::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
        }
    }


    */


    //Para generar bloques y muros intercalados
    /*
     for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            // Calcular la posición de cada bloque o muro
            FVector posicion(570.0f + j * espacio, 3000.0f - i * espacio, 5.0f);

            // Alternar entre bloque y muro
            if ((i + j) % 2 == 0) // Si la suma de i y j es par, crea un bloque
            {
                ABloque* Bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));

                if (Bloque->bPuedeMoverse)
                {
                    // Aquí puedes agregar lógica adicional si es necesario
                }
            }
            else // Si la suma de i y j es impar, crea un muro
            {
                AMuro* Muro = GetWorld()->SpawnActor<AMuro>(AMuro::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
            }
        }
    }

    */

    //PARA BLOQUE DE Ladrillo

    float espacioBA = 500.0f;

    for (int i = 0; i < 5; i++)
    {
        FVector posicionAcero(500.0f + i * espacioBA, 1500.0f, 3.0f);
        ABloque_Ladrillo* Bloque_Ladrillo1 = GetWorld()->SpawnActor<ABloque_Ladrillo>(ABloque_Ladrillo::StaticClass(), posicionAcero, FRotator::ZeroRotator);
    }
}