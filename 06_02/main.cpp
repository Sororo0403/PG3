#include <Novice.h>
#include <thread>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <mutex>

const char kWindowTitle[] = "Thread CSV Load";

std::vector<std::vector<int>> mapData;
std::mutex mapMutex;

bool isLoaded = false;

void LoadCSV() {
    std::ifstream file("map.csv");

    if (!file.is_open()) {
        return;
    }

    std::vector<std::vector<int>> tempMap;
    std::string line;

    while (std::getline(file, line)) {

        std::stringstream ss(line);
        std::string cell;

        std::vector<int> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stoi(cell));
        }

        tempMap.push_back(row);
    }

    // スレッド安全コピー
    std::lock_guard<std::mutex> lock(mapMutex);
    mapData = tempMap;
    isLoaded = true;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    Novice::Initialize(kWindowTitle, 1280, 720);

    // CSV読み込みスレッド開始
    std::thread loadThread(LoadCSV);

    char keys[256] = {0};
    char preKeys[256] = {0};

    while (Novice::ProcessMessage() == 0) {

        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        Novice::BeginFrame();

        if (!isLoaded) {
            Novice::ScreenPrintf(500, 300, "Loading CSV...");
        } else {
            std::lock_guard<std::mutex> lock(mapMutex);

            int chipSize = 32;

            for (int y = 0; y < mapData.size(); y++) {
                for (int x = 0; x < mapData[y].size(); x++) {

                    if (mapData[y][x] == 1) {
                        Novice::DrawBox(x * chipSize, y * chipSize, chipSize,
                                        chipSize, 0.0f, WHITE, kFillModeSolid);
                    }
                }
            }
        }

        Novice::EndFrame();

        if (keys[DIK_ESCAPE]) {
            break;
        }
    }

    loadThread.join();

    Novice::Finalize();
    return 0;
}
