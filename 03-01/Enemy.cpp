#include "Enemy.h"
#include <iostream>

Enemy::FuncPtr Enemy::spFuncTable[(int)Enemy::Phase::SIZE] = {
    &Enemy::ApproachFunc, &Enemy::AttackFunc, &Enemy::LeaveFunc};

Enemy::Enemy() { phase_ = Phase::APPROACH; }

void Enemy::Update() {
  // 現在フェーズの関数を呼び出す
  (this->*spFuncTable[static_cast<int>(phase_)])();

  // フェーズを進める
  int p = static_cast<int>(phase_);
  p++;
  if (p >= static_cast<int>(Phase::SIZE)) {
    p = 0;
  }
  phase_ = static_cast<Phase>(p);
}

void Enemy::ApproachFunc() { std::cout << "Approach\n"; }

void Enemy::AttackFunc() { std::cout << "Attack\n"; }

void Enemy::LeaveFunc() { std::cout << "Leave\n"; }
