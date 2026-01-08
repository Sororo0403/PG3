#pragma once
#include "Notifier.h"

class AlarmNotifier : public Notifier {
  public:
    /// <summary>
    /// アラームで通知する
    /// </summary>
    void Notify() override {
        std::cout << "アラームが鳴りました" << std::endl;
    }
};
