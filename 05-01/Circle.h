#pragma once
#include "IShape.h"

class Circle : public IShape {
  public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Circle(float radius) : radius_(radius) {
    }

    /// <summary>
    /// 円の面積を求める
    /// </summary>
    float Size() override {
        return 3.14f * radius_ * radius_;
    }

    /// <summary>
    /// 円の面積を表示
    /// </summary>
    void Draw() override {
        std::cout << "円の面積: " << Size() << std::endl;
    }

  private:
    float radius_;
};
