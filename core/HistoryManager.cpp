#include "HistoryManager.h"

HistoryManager::HistoryManager(IStorage& storage) 
: storage(storage) {}

void HistoryManager::add(const std::string& url)
{
    history.push_back({ url });
}

void HistoryManager::save()
{
    storage.saveHistory(history);
}
void HistoryManager::load()
{
    history = storage.loadHistory();
}

const std::vector<HistoryEntry>& HistoryManager::getAll() const
{
    return history;
}