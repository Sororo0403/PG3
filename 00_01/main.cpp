#include <cstdio>
#include <windows.h>

int main() {
  // コンソールの出力コードページをUTF-8に変更
  SetConsoleOutputCP(65001);

  // UTF-8の文字列を出力
  printf(u8"HelloWorld!\n");
  printf(u8"こんにちは、世界!\n");

  return 0;
}
