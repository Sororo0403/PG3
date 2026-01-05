#pragma once
#include "Command.h"

class InputHandler {
  public:
    InputHandler();

    ICommand *HandleInput();

  private:
    ICommand *pressA_;
    ICommand *pressD_;
};
