#pragma once
#include <string>
#include "HistoryManager.h"
#include "../storage/Istorage.h"

class WebKitWrapper;

class BrowserController
{
public:
    BrowserController(WebKitWrapper* web);

    void navigate(const std::string& url);
    void back();
    void forward();
    void reload();

private:
    WebKitWrapper* web;
    FileStorage storage;
    HistoryManager history;
};

class BowserController
{public:
    BrowserController(WebKitWrapper* web) : web{}

    void navigate(const std::string& url);
    void back();
    void forward();
    void reload();

private:
    WebKitWrapper* web;
    HistoryManager history;
};