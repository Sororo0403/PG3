#include "GameScene.h"
#include "SceneManager.h"
#include "ClearScene.h"
#include "Novice.h"

void GameScene::Update(SceneManager *manager) {
    if (Novice::CheckHitKey(DIK_SPACE)) {
        enemyHP_--;
    }

    if (enemyHP_ <= 0) {
        manager->ChangeScene(new ClearScene());
    }
}

void GameScene::Draw() {
    Novice::ScreenPrintf(500, 300, "GAME");
    Novice::ScreenPrintf(480, 340, "Enemy HP : %d", enemyHP_);
    Novice::ScreenPrintf(420, 380, "Press SPACE to Attack");
}
