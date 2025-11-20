#pragma once

template <typename T1, typename T2>
class Min {
public:
    // メンバ関数 Min()
    auto MinValue(T1 a, T2 b) {
        return (a < b) ? a : b;
    }
};
