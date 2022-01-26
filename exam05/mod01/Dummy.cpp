#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy"){}

Dummy::Dummy(Dummy const &other){
    *this = other;
}

Dummy &Dummy::operator=(Dummy const &other){
    this->type = other.type;
    return (*this);
}

Dummy::~Dummy(){}

ATarget* Dummy::clone() const{
    ATarget *newTarget = new Dummy(*this);
    return (newTarget);
}