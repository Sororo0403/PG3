#include <Novice.h>
#include "SceneManager.h"
#include "TitleScene.h"

const char kWindowTitle[] = "PG3 StatePattern";

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    Novice::Initialize(kWindowTitle, 1280, 720);

    char keys[256] = {0};
    char preKeys[256] = {0};

    SceneManager sceneManager;
    sceneManager.ChangeScene(new TitleScene());

    while (Novice::ProcessMessage() == 0) {

        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        Novice::BeginFrame();

        // 更新
        sceneManager.Update();

        // 描画
        sceneManager.Draw();

        Novice::EndFrame();
    }

    Novice::Finalize();
    return 0;
}
