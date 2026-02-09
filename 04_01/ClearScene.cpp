#include "ClearScene.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "Novice.h"

void ClearScene::Update(SceneManager *manager) {

    if (Novice::CheckHitKey(DIK_SPACE)) {
        manager->ChangeScene(new TitleScene());
    }
}

void ClearScene::Draw() {
    Novice::ScreenPrintf(500, 300, "CLEAR!!");
    Novice::ScreenPrintf(420, 340, "Press SPACE to Title");
}
