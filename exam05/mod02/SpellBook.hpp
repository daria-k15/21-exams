#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook{
    private:
        SpellBook(SpellBook const &other);
        SpellBook&operator=(SpellBook const &other);
        std::map<std::string, ASpell *> book;

    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(const std::string &name);
        ASpell *createSpell(const std::string &name);
};