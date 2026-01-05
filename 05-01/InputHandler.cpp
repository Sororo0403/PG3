#include "InputHandler.h"
#include <conio.h>

InputHandler::InputHandler() {
    pressA_ = new MoveLeftCommand();
    pressD_ = new MoveRightCommand();
}

ICommand *InputHandler::HandleInput() {
    if (!_kbhit()) {
        return nullptr;
    }

    char key = _getch();
    if (key == 'a')
        return pressA_;
    if (key == 'd')
        return pressD_;

    return nullptr;
}
