#pragma once
#include <vector>
#include <string>

struct HistoryEntry
{
    std::string url;
};

class HistoryManager
{
public:
    void add(const std::string& url);
    const std::vector<HistoryEntry>& get() const;
private:
    std::vector<HistoryEntry> entries;
};