#include "Player.h"

Player::Player() : x_(10) {
}

void Player::MoveLeft() {
    x_--;
}

void Player::MoveRight() {
    x_++;
}

void Player::Draw() const {
    system("cls"); 

    for (int i = 0; i < x_; ++i) {
        std::cout << " ";
    }
    std::cout << "■" << std::endl;
}
