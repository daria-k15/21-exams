#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title){
    this->name = name;
    this->title = title;
    std::cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(){
    std::cout << name << ": My job here is done!\n";
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
    std::cout << name << ": I am " << name << "," << title << "!\n";
}

void Warlock::learnSpell(ASpell *spell){
    if (spell)
        spells.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(const std::string name){
    std::map<std::string, ASpell *>::iterator it = spells.find(name);
    if (it != spells.end())
        delete it->second;
    spells.erase(name);
}

void Warlock::launchSpell(const std::string name, ATarget const &tar){
    ASpell *spell = spells[name];
    if (spell)
        spell->launch(tar);
}