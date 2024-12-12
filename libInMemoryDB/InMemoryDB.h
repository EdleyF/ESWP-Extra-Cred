#include <iostream>
#include <map>

struct InMemoryDB{

    bool open = false;

    std::map<std::string, int> commited, inProg;

    int get(std::string key);

    void put(std::string key, int val);

    void begin_transaction();

    void commit();

    void rollback();
};