#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall"){}

BrickWall::BrickWall(BrickWall const &other){
    *this = other;
}

BrickWall &BrickWall::operator=(BrickWall const &other){
    this->type = other.type;
    return *this;
}

BrickWall::~BrickWall(){}

ATarget *BrickWall::clone() const{
    ATarget *newTarget = new BrickWall(*this);
    return (newTarget); 
}