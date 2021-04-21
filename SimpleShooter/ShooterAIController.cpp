// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"


void AShooterAIController::BeginPlay() 
{
    Super::BeginPlay();
    if(AIBehavior != nullptr)
    {
            RunBehaviorTree(AIBehavior);
            APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

            GetBlackboardComponent() ->  SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
            GetBlackboardComponent() ->  SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    }

    // APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

}

void AShooterAIController::Tick(float DeltaSeconds) 
{
    Super::Tick(DeltaSeconds);
    //     APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    //     if(LineOfSightTo(PlayerPawn)){
    //         GetBlackboardComponent() ->  SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
    //         GetBlackboardComponent() ->  SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
    //         // Set player location
    //         // Set Lastknowplayerlocation
            
    //     } else {
    //         GetBlackboardComponent() -> ClearValue(TEXT("PlayerLocation"));
    //     }
    // If LineOfSight
        // MoveTo
        //SetFocus
    // Else
        //ClearFocus
        //StopMovement
}

bool AShooterAIController::IsDead() const
{
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if(ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();     
    }

    return true;
}
