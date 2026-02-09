#pragma once
#include "Scene.h"

class SceneManager;

class ClearScene : public IScene {
  public:
    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="manager">シーンマネージャ</param>
    void Update(SceneManager *manager) override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw() override;
};
