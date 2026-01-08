#pragma once
#include <iostream>

class IShape {
  public:
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~IShape() = default;

    /// <summary>
    /// 面積を求める
    /// </summary>
    /// <returns>面積</returns>
    virtual float Size() = 0;

    /// <summary>
    /// 図形を描画
    /// </summary>
    virtual void Draw() = 0;
};
