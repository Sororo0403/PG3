#include <cstdio>

// 一般的な賃金体系（時給1226円）
int NormalSalary(int hours) {
    return hours * 1226;
}

int main() {
    int hours = 10;

    // 通常の賃金合計
    int normalTotal = NormalSalary(hours);

    // 再帰的な賃金体系（逐次計算）
    int recursiveTotal = 0;
    int wage = 100; // 1時間目の時給

    for (int i = 1; i <= hours; ++i) {
        recursiveTotal += wage;
        wage = wage * 2 - 50; // 次の時給
    }

    printf("--- 結果 ---\n");
    printf("一般的な賃金体系: %d円\n", normalTotal);
    printf("再帰的な賃金体系: %d円\n", recursiveTotal);

    if (normalTotal > recursiveTotal) {
        printf("→ 一般的な賃金体系の方が高いです。\n");
    } else if (normalTotal < recursiveTotal) {
        printf("→ 再帰的な賃金体系の方が高いです。\n");
    } else {
        printf("→ 同じ金額です。\n");
    }

    return 0;
}
