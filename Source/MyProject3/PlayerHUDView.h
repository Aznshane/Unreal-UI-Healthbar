// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "PlayerHUDView.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MYPROJECT3_API UPlayerHUDView : public UMVVMViewModelBase
{
    GENERATED_BODY()

private:
    UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter, Category = "Status", meta = (AllowPrivateAccess = "true"))
    float CurrentHealth = 100.0f;

public:
    // Getter
    UFUNCTION(BlueprintPure, FieldNotify)
    float GetCurrentHealth() const { return CurrentHealth; }

    // Setter that automatically broadcasts updates to any bound UI
    UFUNCTION(BlueprintCallable, Category = "Status")
    void SetCurrentHealth(float NewHealth)
    {
        UE_MVVM_SET_PROPERTY_VALUE(CurrentHealth, NewHealth);
    }
};