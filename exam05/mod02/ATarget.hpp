#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"
#include <string>
class ASpell;

class ATarget{
    protected:
        std::string type;
    public:
        ATarget();
        ATarget(const std::string &type);
        ATarget(ATarget const &other);
        ATarget &operator=(ATarget const &other);
        virtual ~ATarget();

        std::string getType() const;
        virtual ATarget *clone() const = 0;

        void getHitBySpell(const ASpell &spell) const;

};

#endif