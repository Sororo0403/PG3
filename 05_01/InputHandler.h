#pragma once
#include "ICommand.h"

class InputHandler {
  public:
    /// <summary>
    /// 入力処理を行う
    /// </summary>
    /// <returns>コマンド</returns>
    ICommand *HandleInput();

    /// <summary>
    /// 左に移動するコマンドを割り当てる
    /// </summary>
    void AssignMoveLeftCommand();

    /// <summary>
    /// 右に移動するコマンドを割り当てる
    /// </summary>
    void AssignMoveRightCommand();

  private:
    ICommand *pressA_ = nullptr;
    ICommand *pressD_ = nullptr;
};
