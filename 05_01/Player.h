#pragma once

class Player {
  public:
    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

    /// <summary>
    /// 左に移動
    /// </summary>
    void MoveLeft();

    /// <summary>
    /// 右に移動
    /// </summary>
    void MoveRight();

  private:
    int x_ = 640;
    int y_ = 360;
    int speed_ = 5;
};
