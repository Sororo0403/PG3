#include "Player.h"
#include "Novice.h"

void Player::Update() {
}

void Player::Draw() {
    Novice::DrawBox(x_ - 32, y_ - 32, 64, 64, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveLeft() {
    x_ -= speed_;
}

void Player::MoveRight() {
    x_ += speed_;
}
