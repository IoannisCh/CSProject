#include "FileStorage.h"
#include "../core/HistoryManager.h"

#include <fstream>

void FileStorage::saveHistory(const std::vector<HistoryEntry>& history)
{
    std::ofstream outFile("history.txt");

    if (!outFile.is_open())
        return;

    for (const auto& entry : history)
    {
        outFile << entry.url << "\n";
    }
}

std::vector<HistoryEntry> FileStorage::loadHistory()
{
    std::vector<HistoryEntry> history;

    std::ifstream inFile("history.txt");

    if (!inFile.is_open())
        return history;

    std::string url;

    while (std::getline(inFile, url))
    {
        history.push_back({url});
    }

    return history;
}