#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget{
    public:
        Dummy();
        Dummy(Dummy const &other);
        Dummy &operator=(Dummy const &other);
        virtual ~Dummy();

        ATarget* clone() const;
};

#endif