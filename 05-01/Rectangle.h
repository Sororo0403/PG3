#pragma once
#include "IShape.h"

class Rectangle : public IShape {
  public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Rectangle(float width, float height) : width_(width), height_(height) {
    }

    /// <summary>
    /// 長方形の面積を求める
    /// </summary>
    float Size() override {
        return width_ * height_;
    }

    /// <summary>
    /// 長方形の面積を表示
    /// </summary>
    void Draw() override {
        std::cout << "長方形の面積: " << Size() << std::endl;
    }

  private:
    float width_;
    float height_;
};
