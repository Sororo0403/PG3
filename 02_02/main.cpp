#include <cstdio>

// 一般的な賃金体系（時給1226円）
int NormalSalary(int hours) {
	return hours * 1226;
}

// 再帰的な賃金体系：
// 1時間目は100円、以降は「前の時給 * 2 - 50」
int RecursiveSalary(int hour) {
	if (hour <= 1) {
		return 100;
	}

	return RecursiveSalary(hour - 1) * 2 - 50;
}

int main() {
	int hours;
	printf("何時間働きますか？: ");
	scanf_s("%d", &hours);

	// 通常の賃金合計
	int normalTotal = NormalSalary(hours);

	// 再帰的な賃金合計を求める
	int recursiveTotal = 0;
	for (int i = 1; i <= hours; ++i) {
		recursiveTotal += RecursiveSalary(i);
	}

	printf("\n--- 結果 ---\n");
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
