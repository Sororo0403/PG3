#pragma once
#include <iostream>

class Player {
  public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Player();

    /// <summary>
    /// プレイヤーを左に移動させる
    /// </summary>
    void MoveLeft();

    /// <summary>
    /// プレイヤーを右に移動させる
    /// </summary>
    void MoveRight();

    /// <summary>
    /// プレイヤーを描画する
    /// </summary>
    void Draw() const;

  private:
    int x_;
};
