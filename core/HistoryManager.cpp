#include "HistoryManager.h"

void HistoryManager::add(const std::string& url)
{
    history.push_back({ url });
}

const std::vector<HistoryEntry>& HistoryManager::getAll() const
{
    return history;
}