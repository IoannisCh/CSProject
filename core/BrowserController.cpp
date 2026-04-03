#include "BrowserController.h"
#include "../platform/WebKitWrapper.h"

BrowserController::BrowserController(WebKitWrapper* web)
    : web(web),
      storage(),
      history(storage)
    {
        history.load();
    }

void BrowserController::navigate(const std::string& url){
    web->navigate(url);

    history.add(url);
    history.save();
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