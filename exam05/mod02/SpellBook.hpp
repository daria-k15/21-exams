#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
class ASpell;

class SpellBook{
    private:
        std::map<std::string, ASpell *> book;
        SpellBook(SpellBook const &other);
        SpellBook&operator=(SpellBook const &other);

    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(const std::string name);
        ASpell* createSpell(const std::string &spell);
};