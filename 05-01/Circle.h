#pragma once
#include "IShape.h"

class Circle : public IShape {
  public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Circle(float radius);

    /// <summary>
    /// 円の面積を求める
    /// </summary>
    /// <returns>円の面積</returns>
    float Size() override;

    /// <summary>
    /// 円の面積を表示
    /// </summary>
    void Draw() override;

  private:
    float radius_;
};
