#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(float width, float height)
    : width_(width), height_(height) {
}

float Rectangle::Size() {
    return width_ * height_;
}

void Rectangle::Draw() {
    std::cout << "長方形の面積: " << Size() << std::endl;
}
