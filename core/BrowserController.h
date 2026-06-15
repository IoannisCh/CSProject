#pragma once

#include <string>

#include "HistoryManager.h"
#include "FileStorage.h"

class WebKitWrapper;

class BrowserController
{
public:
    explicit BrowserController(WebKitWrapper* web);

    void navigate(const std::string& url);
    void back();
    void forward();
    void reload();

private:
    WebKitWrapper* web;
    FileStorage storage;
    HistoryManager history;
};