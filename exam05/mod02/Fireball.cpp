#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp"){}

Fireball::Fireball(Fireball const &other){
    *this = other;
}

Fireball &Fireball::operator=(Fireball const &other){
    this->name = other.name;
    this->effects = other.effects;
    return (*this);
}

Fireball::~Fireball(){}

ASpell *Fireball::clone() const{
    ASpell *newSpell = new Fireball(*this);
    return (newSpell);
}
