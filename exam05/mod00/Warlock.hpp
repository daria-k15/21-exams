#pragma once

#include <iostream>

class Warlock{
    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(Warlock const &other);
        Warlock&operator=(Warlock const &other);
    public:
        Warlock(const std::string &name, const std::string &title);
        ~Warlock();

        std::string getName() const;
        std::string getTitle() const;

        void setTitle(const std::string &title);
        void introduce() const;
};