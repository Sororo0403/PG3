#include <iostream>
#include <list>
#include <windows.h>

using namespace std;

// 山手線の駅名(1970年版、英語表記)
const char *stations1970[] = {
    "Tokyo",        "Kanda",     "Akihabara", "Okachimachi",  "Ueno",
    "Uguisudani",   "Nippori",   "Tabata",    "Komagome",     "Sugamo",
    "Otsuka",       "Ikebukuro", "Mejiro",    "Takadanobaba", "Shin-Okubo",
    "Shinjuku",     "Yoyogi",    "Harajuku",  "Shibuya",      "Ebisu",
    "Meguro",       "Gotanda",   "Osaki",     "Shinagawa",    "Tamachi",
    "Hamamatsucho", "Shimbashi", "Yurakucho"};

/// <summary>
/// 駅のリストを表示
/// </summary>
/// <param name="lst">表示する駅のリスト</param>
/// <param name="title">駅のリストのタイトル名</param>
void PrintStations(const list<const char *> &lst, const char *title) {
    cout << "=== " << title << " ===" << endl;
    for (auto &s : lst) {
        cout << s << " -> ";
    }
    cout << "(back to start)" << endl << endl;
}

int main() {
    // UTF-8 出力
    SetConsoleOutputCP(65001);

    // 1970年版をリストに作成
    list<const char *> line1970(stations1970,
                                stations1970 + sizeof(stations1970) /
                                                   sizeof(stations1970[0]));

    // コピーして2019版作成(西日暮里追加)
    list<const char *> line2019 = line1970;
    auto it = find(line2019.begin(), line2019.end(), "Nippori");
    if (it != line2019.end()) {
        ++it; // Nippori の次
        line2019.insert(it, "Nishi-Nippori");
    }

    // コピーして2022版作成(高輪ゲートウェイ追加)
    list<const char *> line2022 = line2019;
    it = find(line2022.begin(), line2022.end(), "Shinagawa");
    if (it != line2022.end()) {
        ++it; // Shinagawa の次
        line2022.insert(it, "Takanawa Gateway");
    }

    // 出力
    PrintStations(line1970, "Yamanote Line 1970");
    PrintStations(line2019, "Yamanote Line 2019");
    PrintStations(line2022, "Yamanote Line 2022");

    return 0;
}
