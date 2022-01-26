#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"
class ATarget;

class BrickWall : public ATarget{
    public:
        BrickWall();
        BrickWall(BrickWall const &other);
        BrickWall &operator=(BrickWall const &other);
        virtual ~BrickWall();

        ATarget *clone() const;
};

#endif