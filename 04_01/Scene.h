#pragma once

class SceneManager;

class IScene {
  public:
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~IScene() = default;

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="manager">シーンマネージャー</param>
    virtual void Update(SceneManager *manager) = 0;

    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void Draw() = 0;
};
