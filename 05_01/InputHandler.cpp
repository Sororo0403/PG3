#include "InputHandler.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "Novice.h"

void InputHandler::AssignMoveLeftCommand() {
    pressA_ = new MoveLeftCommand();
}

void InputHandler::AssignMoveRightCommand() {
    pressD_ = new MoveRightCommand();
}

ICommand *InputHandler::HandleInput() {
    if (Novice::CheckHitKey(DIK_A)) {
        return pressA_;
    }

    if (Novice::CheckHitKey(DIK_D)) {
        return pressD_;
    }

    return nullptr;
}
