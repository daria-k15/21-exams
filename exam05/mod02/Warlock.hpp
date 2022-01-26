#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock{
    private:
        std::string name;
        std::string title;
        SpellBook book;

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle(std::string const &title);
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string name);
        void launchSpell(std::string name, ATarget &target);
};

#endif