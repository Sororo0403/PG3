#include <cstdio>

/// <summary>
/// 2つの値を比較し、小さい方の値を返す関数テンプレート。
/// </summary>
/// <typeparam name="T">比較する値の型</typeparam>
/// <param name="a">1つ目の値。</param>
/// <param name="b">2つ目の値。</param>
/// <returns>2つの引数のうち、小さい方の値を返す。</returns>
template <typename T> T Min(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    // intで呼ぶ
    int ia = 114;
    int ib = 514;
    int iMin = Min<int>(ia, ib);
    std::printf("Min<int>(%d, %d) = %d\n", ia, ib, iMin);

    // floatで呼ぶ
    float fa = 11.4f;
    float fb = 51.4f;
    float fMin = Min<float>(fa, fb);
    std::printf("Min<float>(%.1f, %.1f) = %.1f\n", fa, fb, fMin);

    // doubleで呼ぶ
    double da = 3.1415926535;
    double db = 2.7182818284;
    double dMin = Min<double>(da, db);
    std::printf("Min<double>(%.10f, %.10f) = %.10f\n", da, db, dMin);
    return 0;
}
