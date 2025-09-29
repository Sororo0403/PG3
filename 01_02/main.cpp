#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

/// <summary>
/// 学籍メールから、学籍番号の数字部分を抽出して整数として返します。
/// </summary>
/// <param name="mail">学籍メールアドレス文字列。</param>
/// <returns>抽出した学籍番号の整数。見つからない場合は INT_MAX。</returns>
int ExtractStudentNumber(const string &mail) {
  static const regex re(R"(k024g(\d+)\@g\.neec\.ac\.jp)", regex::icase);
  smatch m;
  if (regex_search(mail, m, re) && m.size() >= 2) {
    return stoi(m[1].str());
  }
  return INT_MAX;
}

/// <summary>
/// 1行のCSV形式文字列(カンマ区切り)からメールアドレスを分割し、前後の空白を除去して出力ベクターへ追加します。
/// </summary>
/// <param name="line">カンマ区切りの文字列。</param>
/// <param name="out">分割・整形後のメールを追加していく出力先ベクター。</param>
void AppendEmailsFromCsvLine(const string &line, vector<string> &out) {
  size_t start = 0;
  while (start < line.size()) {
    size_t comma = line.find(',', start);
    string token = (comma == string::npos) ? line.substr(start)
                                           : line.substr(start, comma - start);
    // 前後の空白を軽く落とす
    size_t l = 0, r = token.size();
    while (l < r && isspace(static_cast<unsigned char>(token[l])))
      ++l;
    while (r > l && isspace(static_cast<unsigned char>(token[r - 1])))
      --r;
    token = token.substr(l, r - l);
    if (!token.empty())
      out.push_back(token);
    if (comma == string::npos)
      break;
    start = comma + 1;
  }
}

/// <summary>
/// テキストファイルを開いて1行ずつ読み込み、各行を
/// CSVとして解釈してメールアドレスを収集します。
/// </summary>
/// <param name="path">読み込むテキストファイルのパス。</param>
/// <param
/// name="out">読み込んだメールアドレスを追加していく出力先ベクター。</param>
/// <returns>読み込みに成功した場合は true、失敗した場合は false。</returns>
bool LoadEmailsFromFile(const string &path, vector<string> &out) {
  ifstream ifs(path);
  if (!ifs)
    return false;
  string line;
  while (getline(ifs, line)) {
    AppendEmailsFromCsvLine(line, out);
  }
  return true;
}

/// <summary>
/// メールアドレスの一覧を、件数とともに標準出力へ整形して表示します。
/// </summary>
/// <param name="emails">表示対象のメールアドレス一覧。</param>
/// <param name="title">見出しとして表示するタイトル文字列。</param>
void PrintEmails(const vector<string> &emails, const char *title) {
  cout << "=== " << title << " (" << emails.size() << ") ===\n";
  for (const auto &e : emails)
    cout << e << '\n';
  cout << endl;
}

int main(int argc, char **argv) {
#ifdef _WIN32
  // WindowsのコンソールをUTF-8に
  SetConsoleOutputCP(65001);
#endif

  // コマンドライン引数 or 既定ファイル名
  string filepath = (argc >= 2) ? argv[1] : "PG3_2025_01_02.txt";

  // メールをvector<string>で保持
  vector<string> emails;

  // ファイルから読み込み（失敗時は手動初期化のフォールバック）
  if (!LoadEmailsFromFile(filepath, emails)) {
    emails = {
        "k024g1017@g.neec.ac.jp", "k024g0033@g.neec.ac.jp",
        "k024g0057@g.neec.ac.jp", "k024g0020@g.neec.ac.jp",
        "k024g0109@g.neec.ac.jp", "k024g1031@g.neec.ac.jp",
        "k024g0004@g.neec.ac.jp", "k024g0027@g.neec.ac.jp",
        "k024g0058@g.neec.ac.jp", "k024g0007@g.neec.ac.jp",
    };
  }

  // 学籍番号でソート（同番号は文字列の辞書順で決定、安定ソート）
  stable_sort(emails.begin(), emails.end(),
              [](const string &a, const string &b) {
                int na = ExtractStudentNumber(a);
                int nb = ExtractStudentNumber(b);
                if (na != nb)
                  return na < nb;
                return a < b;
              });

  // 出力
  PrintEmails(emails, "Sorted by student number");

  return 0;
}
