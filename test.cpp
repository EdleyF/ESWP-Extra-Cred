#include "libInMemoryDB/InMemoryDB.h"
#include <iostream>
#include <cassert>

void test_get_and_put_without_transaction() {
    InMemoryDB db;

    // Test: get should return -1 for non-existent keys
    assert(db.get("A") == -1);

    // Test: put without a transaction should not modify the database
    db.put("A", 5);
    assert(db.get("A") == -1);

    std::cout << "test_get_and_put_without_transaction passed.\n";
}

void test_transaction_commit() {
    InMemoryDB db;

    // Start a transaction and set a key-value pair
    db.begin_transaction();
    db.put("A", 5);

    // Test: get should return -1 for uncommitted changes
    assert(db.get("A") == -1);

    // Commit the transaction
    db.commit();

    // Test: get should now return the committed value
    assert(db.get("A") == 5);

    std::cout << "test_transaction_commit passed.\n";
}

void test_transaction_rollback() {
    InMemoryDB db;

    // Start a transaction and set a key-value pair
    db.begin_transaction();
    db.put("A", 5);

    // Rollback the transaction
    db.rollback();

    // Test: get should return -1 for rolled-back changes
    assert(db.get("A") == -1);

    std::cout << "test_transaction_rollback passed.\n";
}

void test_nested_transactions() {
    InMemoryDB db;

    // Test: Multiple commits and rollbacks
    db.begin_transaction();
    db.put("A", 10);
    db.commit();
    assert(db.get("A") == 10);

    db.begin_transaction();
    db.put("A", 20);
    db.rollback();
    assert(db.get("A") == 10);

    db.begin_transaction();
    db.put("A", 30);
    db.commit();
    assert(db.get("A") == 30);

    std::cout << "test_nested_transactions passed.\n";
}

int main() {
    test_get_and_put_without_transaction();
    test_transaction_commit();
    test_transaction_rollback();
    test_nested_transactions();

    std::cout << "All tests passed successfully!\n";
    return 0;
}