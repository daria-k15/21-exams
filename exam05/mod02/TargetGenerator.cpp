#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){
    std::map<std::string, ATarget *>::iterator it = tar.begin();
    while (it != tar.end()){
        delete it->second;
        ++it;
    }
    tar.clear();
}

void TargetGenerator::learnTargetType(ATarget *target){
    if (target)
        tar.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(const std::string &type){
    std::map<std::string, ATarget *>::iterator it = tar.find(type);
    if (it != tar.end())
        delete it->second;
    tar.erase(type);
}

ATarget *TargetGenerator::createTarget(const std::string &type){
    std::map<std::string, ATarget *>::iterator it = tar.find(type);
    if (it != tar.end())
        return tar[type];
    return NULL;

}