#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AItem;
class UAnimMontage;
class AWeapon;

UCLASS()
class SLAS_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;
	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void LookUp(float value);
	void EKeyPressed();
	void Attack();

	void PlayAttackMontage();
	UFUNCTION(BlueprintCallable)
	void AttackEnd();
	bool CanAttack();

	void PlayEquippedMontage(FName Section_Name);
	bool CanDisArm();
	bool CanArm();

	UFUNCTION(BlueprintCallable)
	void DisArm();
	UFUNCTION(BlueprintCallable)
	void Arm();
	UFUNCTION(BlueprintCallable)
	void FinishEquipping();
private:

	ECharacterState CharacterState = ECharacterState::ECS_Unequiped;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon* EquipWeapon;

	UPROPERTY(EditDefaultsOnly,Category = Montage)
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = Montage)
	UAnimMontage* EquippedMontage;
	
public:
	FORCEINLINE void SetOverLappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};
