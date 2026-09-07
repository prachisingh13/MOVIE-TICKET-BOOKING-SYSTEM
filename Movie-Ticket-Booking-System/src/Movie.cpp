#include "Movie.h"

Movie::Movie(const std::string& title, const std::string& language, int duration)
    : title(title), language(language), duration(duration) {}

std::string Movie::getTitle() const { return title; }
std::string Movie::getLanguage() const { return language; }
int Movie::getDuration() const { return duration; }
