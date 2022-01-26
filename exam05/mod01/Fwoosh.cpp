#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed"){}

Fwoosh::Fwoosh(Fwoosh const &other){
    *this = other;
}

Fwoosh &Fwoosh::operator=(Fwoosh const &other){
    this->name = other.name;
    this->effects = other.effects;
    return (*this);
}

Fwoosh::~Fwoosh(){}

ASpell *Fwoosh::clone() const{
    ASpell *newSpell = new Fwoosh(*this);
    return (newSpell);
}