#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){
    tar.clear();
}

void TargetGenerator::learnTargetType(ATarget* target){
    tar.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(std::string const & name){
    for(std::vector<ATarget*>::iterator it = tar.begin(); it < tar.end(); it++){
        if ((*it)->getType() == name){
            delete *it;
            tar.erase(it);
        }
    }
}

ATarget* TargetGenerator::createTarget(std::string const & name){
    for(std::vector<ATarget*>::iterator it = tar.begin(); it < tar.end(); it++){
        if ((*it)->getType() == name){
            return (*it);
        }
    }
    return NULL;
}