#include <Novice.h>
#include "Player.h"
#include "InputHandler.h"

const char kWindowTitle[] = "PG3 Command Pattern";

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    Novice::Initialize(kWindowTitle, 1280, 720);

    Player player;
    InputHandler input;

    input.AssignMoveLeftCommand();
    input.AssignMoveRightCommand();

    while (Novice::ProcessMessage() == 0) {

        Novice::BeginFrame();

        ICommand *command = input.HandleInput();

        if (command) {
            command->Exec(player);
        }

        player.Update();
        player.Draw();

        Novice::EndFrame();
    }

    Novice::Finalize();
    return 0;
}
