#pragma once
#include "Istorage.h"

class FileStorage : public IStorage
{
public:
    void saveHistory(const std::vector<HistoryEntry>& history) override;
    std::vector<HistoryEntry> loadHistory() override;
};