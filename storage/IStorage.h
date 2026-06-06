#pragma once
#include <vector>
#include <string>

struct HistoryEntry;

class IStorage
{
public:
    virtual void saveHistory(const std::vector<HistoryEntry>& history) = 0;
    virtual std::vector<HistoryEntry> loadHistory() = 0;
    virtual ~IStorage() = default;
};