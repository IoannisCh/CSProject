#pragma once
#include <vector>
#include <string>
#include "..storage/Istorage.h"

struct HistoryEntry
{
    std::string url;
};

class HistoryManager
{
public:
    HistoryManager(IStorage& storage);

    void add(const std::string& url);
    const std::vector<HistoryEntry>& getAll() const;

    void save();
    void load();
private:
    std::vector<HistoryEntry> history;
    IStorage& storage;
};