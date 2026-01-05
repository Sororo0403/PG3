#pragma once

class Player;

class ICommand {
  public:
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~ICommand() = default;

    /// <summary>
    /// コマンドを実行する
    /// </summary>
    /// <param name="player">操作対象となるPlayer</param>
    virtual void Exec(Player &player) = 0;
};

class MoveLeftCommand : public ICommand {
  public:
    /// <summary>
    /// 左移動コマンドを実行する
    /// </summary>
    /// <param name="player">操作対象となるPlayer</param>
    void Exec(Player &player) override;
};

class MoveRightCommand : public ICommand {
  public:
    /// <summary>
    /// 右移動コマンドを実行する
    /// </summary>
    /// <param name="player">操作対象となるPlayer</param>
    void Exec(Player &player) override;
};
