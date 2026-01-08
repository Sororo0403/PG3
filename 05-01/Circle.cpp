#include "Circle.h"
#include <iostream>

Circle::Circle(float radius) : radius_(radius) {
}

float Circle::Size() {
    return 3.14f * radius_ * radius_;
}

void Circle::Draw() {
    std::cout << "円の面積: " << Size() << std::endl;
}
