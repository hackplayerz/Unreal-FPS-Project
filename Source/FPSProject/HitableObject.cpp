// Copyright 2022, Infima Games. All Rights Reserved.


#include "HitableObject.h"

// Sets default values
AHitableObject::AHitableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	health = 100;
}

// Called when the game starts or when spawned
void AHitableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHitableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHitableObject::GetDamage(int damage)
{
	health -= damage;
	if(health <= 0)
	{
		health = 0;
		Die();
	}
}

void AHitableObject::Die()
{
	if(!isDead)
	{
		isDead = true;
		UE_LOG(LogTemp,Warning,TEXT("Dead"));
	}
}

int AHitableObject::GetHealth()
{
	return health;
}
