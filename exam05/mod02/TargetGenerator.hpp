#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"
class ATarget;

class TargetGenerator{
    private:
        std::map<std::string, ATarget *> tars;
        TargetGenerator(TargetGenerator const &other);
        TargetGenerator&operator=(TargetGenerator const &other);

    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *tar);
        void forgetTargetType(const std::string name);
        ATarget* createTarget(const std::string &spell);
};