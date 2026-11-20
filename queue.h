/* Fahrul Zaim bin Mazlan (P3)  AI01086640
   I only left the names so my menu compiles.
   Fill the bodies. Don't rename the functions.

   Your own linked-list queue. Chapter 5 option 1. No STL queue.
   Enqueue at the rear, dequeue at the front. Keep front and rear so both are O(1).
   offerHouse is not a normal pop. Walk from the front and unlink the first
   student waiting for that house. Other students keep their place.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "house.h"

class WaitNode {
public:
    Student data;
    WaitNode *next;
};

class WaitingList {
public:
    WaitingList();
    ~WaitingList();

    bool enqueue(Student s);             // O(1) insert, reject duplicate student id
    Student dequeue();                   // O(1) remove front
    Student peek();                      // O(1)
    bool isEmpty();                      // O(1)
    void display();                      // O(n), front first
    bool hasStudent(int id);             // O(n)
    Student offerHouse(int houseId);     // O(n). Return the student, or id = -1 if none.
    int purgeHouse(int houseId);         // O(n). Drop every waiter for that house. Return how many.
    Student cancelStudent(int id);       // O(n)

private:
    WaitNode *front;
    WaitNode *rear;
    int count;
};

WaitingList::WaitingList() {
    front = NULL;
    rear = NULL;
    count = 0;
}

WaitingList::~WaitingList() {
    // Zaim: delete every node.
}

Student emptyWaiter() {
    Student s;
    s.id = -1;
    s.name = "";
    s.phone = "";
    s.preferredHouseId = -1;
    return s;
}

bool WaitingList::isEmpty() {
    return front == NULL;
}

bool WaitingList::hasStudent(int) {
    return false;
}

bool WaitingList::enqueue(Student) {
    cout << "enqueue is not written yet (Zaim).\n";
    return false;
}

Student WaitingList::dequeue() {
    cout << "dequeue is not written yet (Zaim).\n";
    return emptyWaiter();
}

Student WaitingList::peek() {
    return emptyWaiter();
}

void WaitingList::display() {
    cout << "display queue is not written yet (Zaim).\n";
}

Student WaitingList::offerHouse(int) {
    return emptyWaiter();
}

int WaitingList::purgeHouse(int) {
    return 0;
}

Student WaitingList::cancelStudent(int) {
    return emptyWaiter();
}

#endif
