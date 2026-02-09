#pragma once
#include "ICommand.h"

class MoveRightCommand : public ICommand {
  public:
    /// <summary>
    /// コマンドを実行
    /// </summary>
    /// <param name="player">プレイヤーの参照</param>
    void Exec(Player &player) override;
};
