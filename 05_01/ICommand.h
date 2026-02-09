#pragma once
class Player;

class ICommand {
  public:
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~ICommand() = default;

    /// <summary>
    /// コマンドを実行
    /// </summary>
    /// <param name="player">プレイヤーの産所</param>
    virtual void Exec(Player &player) = 0;
};
