#include "Cinema.h"

Cinema::Cinema(const std::string& name) : name(name) {}

void Cinema::addScreen(const Screen& screen) {
    screens.push_back(screen);
}

std::string Cinema::getName() const { return name; }

std::vector<Screen>& Cinema::getScreens() { return screens; }

Screen* Cinema::getScreen(int screenNo) {
    for (auto& screen : screens) {
        if (screen.getScreenNumber() == screenNo) return &screen;
    }
    return nullptr;
}
