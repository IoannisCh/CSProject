#include "FileStorage.h"
#include "..core/HistoryManager.h"
#include <fstream>

void FileStorage::saveHistory(const std::vector<HistoryEntry>& history)
{
    std::ofstream outFile("history.txt");

    for (const auto& entry : history) {
        file << entry.url "\n";
    }
}

std::vector<HistoryEntry> FileStorage::loadHistory()
{
    std::vector<HistoryEntry> history;
    std::ifstream inFile("history.txt");
    std::string url;

    while (std::getline(file, url)) {
        history.push_back({url});
    }

    return history;
}