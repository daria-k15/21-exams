#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::ASpell(const std::string &name, const std::string &effects){
    this->name = name;
    this->effects = effects;
}

ASpell::ASpell(ASpell const &other){
    *this = other;
}

ASpell&ASpell::operator=(ASpell const &other){
    this->name = other.name;
    this->effects = other.effects;
    return *this;
}

ASpell::~ASpell(){}

std::string ASpell::getName() const{
    return name;
}

std::string ASpell::getEffects() const{
    return effects;
}

void ASpell::launch(ATarget const &tar) const{
    tar.getHitBySpell(*this);
}