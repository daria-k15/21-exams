#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title){
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(){
    std::cout << this->name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName() const{
    return (this->name);
}

std::string const &Warlock::getTitle() const{
    return (this->title);
}

void Warlock::setTitle(std::string const &title){
    this->title = title;
}

void Warlock::introduce() const{
    std::cout << this->name << ": I am " << this-> name << ", " << this->title << std::endl;
}

void Warlock::learnSpell(ASpell *spell){
    this->spells.push_back(spell->clone());
}

void Warlock::forgetSpell(std::string name){
    for (std::vector<ASpell*>::iterator it = spells.begin(); it < spells.end(); it++){
        if ((*it)->getName() == name){
            delete *it;
            spells.erase(it);
        }
    }
}

void Warlock::launchSpell(std::string name, ATarget &target){
    for (std::vector<ASpell*>::iterator it = spells.begin(); it < spells.end(); it++){
        if ((*it)->getName() == name){
            (*it)->launch(target);
        }
    }
}