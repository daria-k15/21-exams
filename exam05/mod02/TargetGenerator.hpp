#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator{
    private:
        TargetGenerator(TargetGenerator const &other);
        TargetGenerator&operator=(TargetGenerator const &other);

        std::map<std::string, ATarget *> tar;
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *target);
        void forgetTargetType(const std::string &type);
        ATarget *createTarget(const std::string &type);
};