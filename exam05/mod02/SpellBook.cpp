#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){
    std::map<std::string, ASpell *>::iterator it = book.begin();
    while (it != book.end()){
        delete it->second;
        ++it;
    }
    book.clear();
}

void SpellBook::learnSpell(ASpell *spell){
    if (spell)
        book.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(const std::string &name){
    std::map<std::string, ASpell *>::iterator it = book.find(name);
    if (it != book.end())
        delete it->second;
    book.erase(name);
}

ASpell *SpellBook::createSpell(const std::string &name){
    std::map<std::string, ASpell *>::iterator it = book.find(name);
    if (it != book.end())
        return book[name];
    return NULL;
}