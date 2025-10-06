#include <cstdio>
#include <windows.h>

int main() {
	// コンソールの出力コードページをUTF-8に変更
	SetConsoleOutputCP(65001);

	// UTF-8の文字列を出力
	printf("HelloWorld!\n");
	printf("こんにちは、世界!\n");

	return 0;
}
