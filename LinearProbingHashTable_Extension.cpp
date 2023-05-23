/* File: LinearProbingHashTable_Extension.cpp
 *
 *
 * This file implements a linear probing hash table. It is an improved version
 * of the typical linear probing hash table that accounts for number of tombstones.
 */
#include "GUI/SimpleTest.h"
#include "set.h"
#include "LinearProbingHashTable.h"
using namespace std;


/* Constructor
 * -------------------------------------
 * This constructor makes a
 * LinearProbingHashTable with the integer variables
 * of amtOfSpots and insertedAmt, both set to 0.
 * The hashFunction is stored as hashFunc and
 * and internal data structure is filled with
 * empty slots
 */
LinearProbingHashTable::LinearProbingHashTable(HashFunction<std::string> hashFn) {
    hashFunc = hashFn;
    amtOfSpots = hashFunc.numSlots();
    elems = new Slot[amtOfSpots];
    insertedAmt = 0;
    amtOfTombstones = 0;


    for (int i = 0; i < amtOfSpots; i++) {
        elems[i] = {"", SlotType::EMPTY};
    }
}

/* Destructor
 * -------------------------------------
 * This deconstructs the LinearProbingHashTable class
 */
LinearProbingHashTable::~LinearProbingHashTable() {
    delete[] elems;
}

/* function: size()
 * -------------------------------------
 * This returns the insertedAmt, or
 * the amount of filled slots.
 */
int LinearProbingHashTable::size() const {
    return insertedAmt;
}

/* function: isEmpty()
 * -------------------------------------
 * This returns a boolean representing if
 * insertedAmt is 0.
 */
bool LinearProbingHashTable::isEmpty() const {
    return insertedAmt == 0;
}

/* function: insert(elem)
 * -------------------------------------
 * This function takes in a string elem to
 * be added to the internal data structure.
 * A boolean is returned: false if the table
 * is full or the element is already added or true
 * if the string was successfully added.
 */
bool LinearProbingHashTable::insert(const string& elem) {
    if (size() == amtOfSpots || contains(elem)) {
        return false; //no room to add it or already added
    }
    if (amtOfTombstones > TOMBSTONE_AMT )
    {
        elems = new Slot[amtOfSpots];
        Set<string> toAdd;
        for (int i =0; i < amtOfSpots; i++){
            if (elems[i].type == SlotType::FILLED) {
                toAdd.add(elems[i].value);
            }
        }
        for (string value: toAdd) {
            insert(value);
        }
    }
    int initialLocation = hashFunc(elem);
    while (elems[initialLocation].type != SlotType::EMPTY
           && elems[initialLocation].type != SlotType::TOMBSTONE) {
        initialLocation++;
        if (initialLocation == amtOfSpots) {
            initialLocation = 0;
        }
    }
    elems[initialLocation].value = elem;
    if (elems[initialLocation].type == SlotType::TOMBSTONE) {
        amtOfTombstones--;
    }
    elems[initialLocation].type = SlotType::FILLED;
    insertedAmt++;
    return true;
}

/* function: contains(elem)
 * -------------------------------------
 * This function returns a boolean representing
 * if the table contains a string value.
 */
bool LinearProbingHashTable::contains(const string& elem) const {
    int initialLocation = hashFunc(elem);
    int j = 0;
    while (elems[initialLocation].type != SlotType::EMPTY
           && (elems[initialLocation].value != elem || elems[initialLocation].type == SlotType::TOMBSTONE)
           && j < amtOfSpots) {
        initialLocation++;
        j++;
        if (initialLocation == amtOfSpots) {
            initialLocation = 0;
        }
    }
    if (elems[initialLocation].value == elem && elems[initialLocation].type != SlotType::EMPTY) {
        return true;
    }
    return false;

}

/* function: remove(elem)
 * -------------------------------------
 * This function returns a boolean representing
 * if a string was successfully removed. A false
 * is returned if the string is not in the table
 * to be removed and true if it was succesfully
 * removed.
 */
bool LinearProbingHashTable::remove(const string& elem) {
    /* TODO: Delete this comment and the next lines, then implement this function. */
    if (!contains(elem)) {
        return false;
    }
    int initialLocation = hashFunc(elem);
    int j = 0;
    while (elems[initialLocation].type != SlotType::EMPTY
           && (elems[initialLocation].value != elem || elems[initialLocation].type == SlotType::TOMBSTONE)
           && j < amtOfSpots) {
        initialLocation++;
        j++;
        if (initialLocation == amtOfSpots) {
            initialLocation = 0;
        }
    }
    elems[initialLocation].type = SlotType::TOMBSTONE;
    amtOfTombstones++;
    insertedAmt--;
    return true;
}
