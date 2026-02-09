#pragma once
#include "Scene.h"

class SceneManager;

class GameScene : public IScene {
  public:
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameScene() override = default;

    /// <summary>
    /// 描画処理
    /// </summary>
    /// <param name="manager">シーンマネージャ</param>
    void Update(SceneManager *manager) override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw() override;

  private:
    int enemyHP_ = 100;
};
