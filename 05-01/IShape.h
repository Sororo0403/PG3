#pragma once
#include <iostream>

class IShape {
  public:
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~IShape() {
    }

    /// <summary>
    /// 面積を求める
    /// </summary>
    virtual float Size() = 0;

    /// <summary>
    /// 図形を描画
    /// </summary>
    virtual void Draw() = 0;
};
