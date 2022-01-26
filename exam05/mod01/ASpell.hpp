#ifndef ASPELL_HPP
#define ASPELL_HPP

#include "ATarget.hpp"
#include <iostream>
#include <string>

class ATarget;

class ASpell{
    protected:
        std::string name;
        std::string effects;

    public:
        ASpell();
        ASpell(const std::string &name, const std::string &effects);
        ASpell(ASpell const &other);
        ASpell &operator=(ASpell const &other);
        virtual ~ASpell();

        std::string getName() const;
        std::string getEffects() const;
        virtual ASpell *clone() const = 0;

        void launch(const ATarget &target);

};

#endif