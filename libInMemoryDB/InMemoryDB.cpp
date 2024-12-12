#include "InMemoryDB.h"

int InMemoryDB::get(std::string key){
    if(this->commited.find(key) == this->commited.end()){
        return -1;
    }
    return this->commited[key];
}

void InMemoryDB::put(std::string key, int val){
    if(!open){
        std::cerr << "There is no in progress Transaction!" << std::endl;
        return;
    }

    this->inProg[key] = val;
}

void InMemoryDB::begin_transaction(){
    this->open = true;
}

void InMemoryDB::commit(){
    if(!open){
        std::cerr << "There is no in progress Transaction!" << std::endl;
        return;
    }

    for(const auto& [key, value] : this->inProg){
        this->commited[key] = value;
    }
    this->open = false;
    this->inProg.clear();
}

void InMemoryDB::rollback(){
    this->open = false;
    this->inProg.clear();
}