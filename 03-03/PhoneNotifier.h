#pragma once
#include "Notifier.h"

class PhoneNotifier : public Notifier {
  public:
    /// <summary>
    /// スマホで通知する
    /// </summary>
    void Notify() override {
        std::cout << "スマホに通知が届きました" << std::endl;
    }
};
