#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include "ATarget.hpp"
#include <vector>


class TargetGenerator{
    private:
        std::vector<ATarget*> tar;

        TargetGenerator(TargetGenerator const &other);
        TargetGenerator &operator=(TargetGenerator const &other);
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget *tar);
        void forgetTargetType(std::string const &name);
        ATarget *createTarget(std::string const &name);

};

#endif