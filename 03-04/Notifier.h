#pragma once
#include <iostream>

class Notifier {
  public:
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~Notifier() {
    }

    /// <summary>
    /// 通知を行う
    /// </summary>
    virtual void Notify() = 0;
};
