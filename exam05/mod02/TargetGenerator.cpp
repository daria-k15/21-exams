#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){
    std::map<std::string, ATarget *>::iterator it = tars.begin();
    while (it != tars.end()){
        delete it->second;
        ++it;
    }
    tars.clear();
}

void TargetGenerator::learnTargetType(ATarget *tar){
    if (tar)
        tars.insert(std::pair<std::string, ATarget *>(tar->getType(), tar->clone()));
}

void TargetGenerator::forgetTargetType(const std::string name){
    std::map<std::string, ATarget *>::iterator it = tars.find(name);
    if (it != tars.end())
        delete it->second;
    tars.erase(name);
}

ATarget* TargetGenerator::createTarget(const std::string &spell){
    std::map<std::string, ATarget *>::iterator it = tars.find(spell);
    if (it != tars.end())
        return tars[spell];
    return NULL;
}