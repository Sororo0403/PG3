#pragma once
#include "IShape.h"

class Rectangle : public IShape {
  public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Rectangle(float width, float height);

    /// <summary>
    /// 長方形の面積を求める
    /// </summary>
    /// <returns>長方形の面積</returns>
    float Size() override;

    /// <summary>
    /// 長方形の面積を表示
    /// </summary>
    void Draw() override;

  private:
    float width_;
    float height_;
};
