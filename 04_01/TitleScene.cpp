#include "TitleScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "Novice.h"

void TitleScene::Update(SceneManager *manager) {

    if (Novice::CheckHitKey(DIK_SPACE)) {
        manager->ChangeScene(new GameScene());
    }
}

void TitleScene::Draw() {
    Novice::ScreenPrintf(500, 300, "TITLE");
    Novice::ScreenPrintf(450, 340, "Press SPACE to Start");
}
