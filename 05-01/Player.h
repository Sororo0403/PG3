#pragma once
#include <iostream>

class Player {
  public:
    Player();

    void MoveLeft();
    void MoveRight();
    void Draw() const;

  private:
    int x_;
};
