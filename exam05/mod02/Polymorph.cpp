#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter"){}

Polymorph::Polymorph(Polymorph const &other){
    *this = other;
}

Polymorph &Polymorph::operator=(Polymorph const &other){
    this->name = other.name;
    this->effects = other.effects;
    return (*this);
}

Polymorph::~Polymorph(){}

ASpell* Polymorph::clone() const{
    ASpell *newSpell = new Polymorph(*this);
    return (newSpell);
}