#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell{
    public:
        Fwoosh();
        Fwoosh(Fwoosh const &other);
        Fwoosh & operator=(Fwoosh const  &other);
        virtual ~Fwoosh();

        ASpell *clone() const;
};

#endif