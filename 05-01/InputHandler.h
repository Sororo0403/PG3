#pragma once
#include "Command.h"

/// <summary>
/// 入力とコマンドを結びつけるクラス
/// </summary>
class InputHandler {
  public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    InputHandler();

    /// <summary>
    /// 入力を取得し、対応するコマンドを返す
    /// </summary>
    /// <returns>実行するコマンド 入力が無い場合は nullptr を返す</returns>
    ICommand *HandleInput();

  private:
    ICommand *pressA_;
    ICommand *pressD_;
};
