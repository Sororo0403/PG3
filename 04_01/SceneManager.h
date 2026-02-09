#pragma once
#include "Scene.h"

class SceneManager {
  public:
    /// <summary>
    /// シーンを変更
    /// </summary>
    /// <param name="newScene">変更後のシーン</param>
    void ChangeScene(IScene *newScene);

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

  private:
    IScene *currentScene_ = nullptr;
};
