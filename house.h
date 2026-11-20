/* CSEB3213, section 01C, group 13
   Shared records. Don't change the fields unless you tell the group first.
   id is unique.
   Sort by rent or distance. Binary search uses id, not rent (rent can repeat).
   Status is Available or Rented.
*/

#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <string>
using namespace std;

struct House {
    int id;
    string address;
    double rent;
    int rooms;
    double distanceKm;
    string status;
    string landlordName;
};

struct Student {
    int id;
    string name;
    string phone;
    int preferredHouseId;
};

const int MAX_HOUSE = 100;

// One line per house. List, sort and search all use this.
void printHouse(House h) {
    cout << "ID: " << h.id
         << " | " << h.address
         << " | RM" << h.rent
         << " | Rooms: " << h.rooms
         << " | " << h.distanceKm << " km"
         << " | " << h.status
         << " | Landlord: " << h.landlordName << endl;
}

void printStudent(Student s) {
    cout << "Student ID: " << s.id
         << " | " << s.name
         << " | " << s.phone
         << " | Waiting for house ID: " << s.preferredHouseId << endl;
}

#endif
