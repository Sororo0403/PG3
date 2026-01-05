#include "Player.h"
#include "InputHandler.h"
#include <thread>
#include <chrono>

int main() {
    Player player;
    InputHandler input;

    while (true) {
        ICommand *command = input.HandleInput();

        if (command) {
            command->Exec(player);
            player.Draw();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
