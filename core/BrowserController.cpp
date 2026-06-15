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
    web->loadURL(url);

    history.add(url);
    history.save();
}

void BrowserController::back(){
    web->goBack();
}

void BrowserController::forward(){
    web->goForward();
}

void BrowserController::reload(){
    web->reload();
}