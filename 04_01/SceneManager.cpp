#include "SceneManager.h"

void SceneManager::ChangeScene(IScene *newScene) {
    if (currentScene_) {
        delete currentScene_;
    }
    currentScene_ = newScene;
}

void SceneManager::Update() {
    if (currentScene_)
        currentScene_->Update(this);
}

void SceneManager::Draw() {
    if (currentScene_)
        currentScene_->Draw();
}
