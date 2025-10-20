#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <functional>

/// <summary>
/// 指定時間待機した後に、コールバック（std::function）を実行する。
/// </summary>
/// <param name="fn">遅延後に実行する関数</param>
/// <param name="delayMs">待機時間(ミリ秒)</param>
/// <param name="roll">サイコロの出目</param>
/// <param name="userGuess">ユーザーの予想(1=奇数, 0=偶数)</param>
void DelayReveal(const std::function<void(int, int)> &fn,
	unsigned int delayMs, int roll, int userGuess) {
	printf("\nサイコロを振っています...\n");

	// 指定ミリ秒待機
	Sleep(delayMs);

	// コールバック実行
	fn(roll, userGuess);
}

int main() {
	// 乱数初期化
	srand((unsigned int)time(NULL));

	// ユーザーに予想を入力させる
	int userGuess = 0;
	printf("奇数だと思うなら1、偶数だと思うなら0を入力してください: ");
	if (scanf_s("%d", &userGuess) != 1) {
		printf("入力エラーです。\n");
		return 1;
	}

	// サイコロを振る
	int roll = rand() % 6 + 1;

	// 3秒後に結果を発表
	std::function<void(int, int)> showResult =
		[](int roll, int userGuess) {
		int correct = roll % 2;

		printf("\n=== 結果発表 ===\n");
		printf("サイコロの出目は「%d」でした。\n", roll);

		if (userGuess == correct) {
			printf("→ 正解！あなたの予想が当たりました！\n");
		} else {
			printf("→ 残念！はずれです。\n");
		}
		};

	DelayReveal(showResult, 3000, roll, userGuess);
	return 0;
}
