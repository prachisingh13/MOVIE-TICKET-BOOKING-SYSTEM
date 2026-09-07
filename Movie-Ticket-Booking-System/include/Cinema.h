#ifndef CINEMA_H
#define CINEMA_H

#include "Screen.h"
#include <string>
#include <vector>

class Cinema {
private:
    std::string name;
    std::vector<Screen> screens;

public:
    explicit Cinema(const std::string& name);

    void addScreen(const Screen& screen);
    std::string getName() const;
    std::vector<Screen>& getScreens();
    Screen* getScreen(int screenNo);
};

#endif
