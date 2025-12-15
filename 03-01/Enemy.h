#pragma once

class Enemy {
  public:
    enum class Phase { APPROACH, ATTACK, LEAVE, SIZE };

  public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Enemy();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

  private:
    // フェーズごとの関数
    void ApproachFunc();
    void AttackFunc();
    void LeaveFunc();

  private:
    Phase phase_;

    using FuncPtr = void (Enemy::*)();
    static FuncPtr spFuncTable[(int) Phase::SIZE];
};
