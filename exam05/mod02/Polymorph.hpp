#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "ASpell.hpp"

class ASpell;

class Polymorph : public ASpell{
    public:
        Polymorph();
        Polymorph(Polymorph const &other);
        Polymorph & operator=(Polymorph const &other);
        virtual ~Polymorph();

        ASpell* clone() const;
};

#endif