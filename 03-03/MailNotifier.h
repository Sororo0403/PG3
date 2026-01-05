#pragma once
#include "Notifier.h"

class MailNotifier : public Notifier {
  public:
    /// <summary>
    /// メールで通知する
    /// </summary>
    void Notify() override {
        std::cout << "メールが届きました" << std::endl;
    }
};
