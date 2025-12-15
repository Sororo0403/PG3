#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>

/// <summary>
/// サイコロの出目とユーザーの予想を比較して、結果を表示する。
/// </summary>
/// <param name="roll">サイコロの出目(1〜6の整数)</param>
/// <param name="userGuess">ユーザーの予想(1=奇数, 0=偶数)</param>
/// <returns>なし</returns>
void ShowResult(int roll, int userGuess) {
    // rollが奇数なら1、偶数なら0
    int correct = roll % 2;

    printf("\n=== 結果発表 ===\n");
    printf("サイコロの出目は「%d」でした。\n", roll);

    if (userGuess == correct) {
        printf("→ 正解！あなたの予想が当たりました！\n");
    } else {
        printf("→ 残念！はずれです。\n");
    }
}

/// <summary>
/// 指定時間待機した後に、コールバック関数を実行する。
/// </summary>
/// <param name="fn">遅延後に実行する関数(関数ポインタ)</param>
/// <param name="delayMs">待機時間(ミリ秒)</param>
/// <param name="roll">サイコロの出目</param>
/// <param name="userGuess">ユーザーの予想(1=奇数, 0=偶数)</param>
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll,
                 int userGuess) {
    printf("\nサイコロを振っています...\n");

    // 指定ミリ秒待機
    Sleep(delayMs);

    // コールバック関数を実行
    fn(roll, userGuess);
}

int main() {
    // 乱数初期化
    srand((unsigned int) time(NULL));

    // ユーザーに予想を入力させる
    int userGuess;
    printf("奇数だと思うなら1、偶数だと思うなら0を入力してください: ");
    scanf_s("%d", &userGuess);

    // サイコロを振る
    int roll = rand() % 6 + 1;

    // 3秒後に結果を発表
    DelayReveal(ShowResult, 3000, roll, userGuess);

    return 0;
}
