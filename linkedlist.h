/* Hariz Zubayr bin Fuad (P2)  AI01086661
   I only left the names so my menu compiles.
   Fill the bodies. Don't rename the functions or main breaks.

   Doubly linked list. Chapter 3 part 2 and Lab 4. No STL list.
   Node is prev, data, next. Keep a tail so add-at-end is O(1).
   Slides say free(). We used new, so use delete.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "house.h"

class HouseNode {
public:
    House data;
    HouseNode *next;
    HouseNode *prev;
};

class HouseList {
public:
    HouseList();
    ~HouseList();

    bool addHouse(House h);                              // O(1) with tail. Reject duplicate id.
    bool updateHouse(House edited, bool &becameAvailable); // O(n). Set becameAvailable if status flips to Available.
    bool removeHouse(int id);                            // O(n). Beginning, middle, end, and the one-node case.
    void displayAll();                                   // O(n)
    void displayAvailable();                             // O(n)
    void traverse();                                     // forward and backward
    bool isEmpty();                                      // O(1)
    int getCount();                                      // O(1)
    HouseNode *findById(int id);                         // O(n). Return NULL if missing.
    HouseNode *getHead();                                // O(1). Mukred walks this for linear search.
    int copyToArray(House arr[], int max);               // O(n). Do not change the list.
    bool setStatus(int id, string status);               // O(n). Main calls this after an offer.

private:
    HouseNode *head;
    HouseNode *tail;
    int count;
};

HouseList::HouseList() {
    head = NULL;
    tail = NULL;
    count = 0;
}

HouseList::~HouseList() {
    // Hariz: delete every node.
}

bool HouseList::isEmpty() {
    return head == NULL;
}

int HouseList::getCount() {
    return count;
}

bool HouseList::addHouse(House) {
    // Hariz: validate, reject duplicate id, insert at end.
    cout << "addHouse is not written yet (Hariz).\n";
    return false;
}

HouseNode *HouseList::findById(int) {
    return NULL;
}

HouseNode *HouseList::getHead() {
    return head;
}

bool HouseList::updateHouse(House, bool &becameAvailable) {
    becameAvailable = false;
    cout << "updateHouse is not written yet (Hariz).\n";
    return false;
}

bool HouseList::setStatus(int, string) {
    return false;
}

bool HouseList::removeHouse(int) {
    cout << "removeHouse is not written yet (Hariz).\n";
    return false;
}

void HouseList::displayAll() {
    cout << "displayAll is not written yet (Hariz).\n";
}

void HouseList::displayAvailable() {
    cout << "displayAvailable is not written yet (Hariz).\n";
}

void HouseList::traverse() {
    cout << "traverse is not written yet (Hariz).\n";
}

int HouseList::copyToArray(House[], int) {
    return 0;
}

#endif
