#pragma once

#include <iostream>
#include "ASpell.hpp"
class ASpell;

class ATarget{
    private:
        std::string type;

    public:
        ATarget(const std::string &type);
        ATarget(ATarget const &other);
        ATarget&operator=(ATarget const &other);
        virtual ~ATarget();

        std::string getType() const;

        virtual ATarget* clone() const = 0;
        void getHitBySpell(ASpell const &spell) const;
};