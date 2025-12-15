#pragma once

template <typename T1, typename T2> class Min {
  public:
    /// <summary>
    /// 値を比較し、小さい値を返す
    /// </summary>
    /// <param name="a">比較する値a</param>
    /// <param name="b">比較する値b</param>
    /// <returns>比較結果</returns>
    auto MinValue(T1 a, T2 b) {
        return (a < b) ? a : b;
    }
};
