// Copyright 2022, Infima Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitableObject.generated.h"

UCLASS()
class FPSPROJECT_API AHitableObject : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Health", meta=(ClampMin="0",ClampMax="1000"))
	int health;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Health")
	bool isDead;
	
public:	
	// Sets default values for this actor's properties
	AHitableObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure,Category="Character | Health")
	int GetHealth();	
	UFUNCTION(BlueprintCallable,Category="Character | Health")
	void GetDamage(int damage);
	UFUNCTION(BlueprintCallable, Category="Character | Health")
	void Die();
	UFUNCTION(BlueprintImplementableEvent, Category="Character | Health")
	void OnHealthChanged();
	UFUNCTION(BlueprintImplementableEvent, Category="Character | Health")
	void OnDie();
};
