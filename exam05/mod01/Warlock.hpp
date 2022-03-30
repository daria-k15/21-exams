#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock{
    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(Warlock const &other);
        Warlock&operator=(Warlock const &other);

        std::map<std::string, ASpell *> spells;
    public:
        Warlock(const std::string &name, const std::string &title);
        ~Warlock();

        std::string getName() const;
        std::string getTitle() const;

        void setTitle(const std::string &title);
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(const std::string name);
        void launchSpell(const std::string name, ATarget const &tar);
};