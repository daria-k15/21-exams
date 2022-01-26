#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){
    book.clear();
}

void SpellBook::learnSpell(ASpell *spell){
    book.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string const &name){
    for (std::vector<ASpell*>::iterator it = book.begin(); it < book.end(); it++){
        if ((*it)->getName() == name){
            delete *it;
            book.erase(it);
        }
    }
}

ASpell *SpellBook::createSpell(std::string const &name){
    for (std::vector<ASpell*>::iterator it = book.begin(); it < book.end(); it++){
        if ((*it)->getName() == name){
            return (*it);
        }
    }
    return NULL;
}