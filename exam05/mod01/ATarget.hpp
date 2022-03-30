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
<<<<<<< HEAD

        virtual ATarget* clone() const = 0;
=======

        virtual ATarget *clone() const = 0;

>>>>>>> 00575148a412eecf07b07bc0058d667d1dffd72d
        void getHitBySpell(ASpell const &spell) const;
};