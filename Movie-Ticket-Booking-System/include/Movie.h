#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    std::string title;
    std::string language;
    int duration;

public:
    Movie(const std::string& title, const std::string& language, int duration);

    std::string getTitle() const;
    std::string getLanguage() const;
    int getDuration() const;
};

#endif
