#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title){
    this->name = name;
    this->title = title;
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(){
    std::cout << name << ": My job here is done!" << std::endl;
}

std::string Warlock::getName() const{
    return name;
}

std::string Warlock::getTitle() const{
    return title;
}

void Warlock::setTitle(const std::string &title){
    this->title = title;
}

void Warlock::introduce() const{
    std::cout << name << ": I am " << name << ", " << title << "!\n";
}

void Warlock::learnSpell(ASpell *spell){
    book.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string name){
    book.forgetSpell(name);
}

void Warlock::launchSpell(const std::string name, ATarget const &tar){
    ATarget const *tmp = 0;
    if (tmp == &tar)
        return ;
    ASpell *spell = book.createSpell(name);
    if (spell)
        spell->launch(tar);
}