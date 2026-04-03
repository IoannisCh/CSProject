#include "BrowserController.h"
#include "../platform/WebKitWrapper.h"

BrowserController::BrowserController(WebKitWrapper* web)
    : web(web){}

void BrowserController::navigate(const std::string& url){
    web->navigate(url);

    history.add(url);
}

void BrowserController::back(){
    web->back();
}

void BrowserController::forward(){
    web->forward();
}

void BrowserController::reload(){
    web->reload();
}