/* Mohammed Muaadh Shaif Mohammed Mukred (P5)  AI01087011
   Linear search walks the list from getHead. Address or landlord.
   No std::find. The list is not sorted, so this is O(n).

   Binary search is by house ID only. Rent can repeat, so don't search by rent.
   Sort a copy first: sortHouses(arr, n, 2, 3, 1). That's Adam's quick sort, by id, ascending.
   Chapter 9: LOW, HI, MID = (LOW + HI) / 2.
*/

#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
#include <string>

#include "linkedlist.h"
#include "sorting.h"

using namespace std;

// field: 1 = address, 2 = landlord name. O(n)
void linearSearch(HouseList &list, string key, int field) {
    Node *cur = list.getHead();

    if (cur == nullptr) {
        cout << "The house list is empty.\n";
        return;
    }
    if (field != 1 && field != 2) {
        cout << "Invalid search field.\n";
        return;
    }

    bool found = false;
    int count = 0;

    while (cur != nullptr) {
        count++;
        House &h = cur->data;

        bool match = (field == 1) ? (h.address == key) : (h.landlordName == key);

        if (match) {
            found = true;
            cout << "Found at position " << count << ":\n";
            cout << "  ID: " << h.id << "\n";
            cout << "  Address: " << h.address << "\n";
            cout << "  Rent: " << h.rent << "\n";
            cout << "  Rooms: " << h.rooms << "\n";
            cout << "  Distance: " << h.distanceKm << " km\n";
            cout << "  Status: " << h.status << "\n";
            cout << "  Landlord: " << h.landlordName << "\n";
        }
        cur = cur->next;
    }

    if (!found) {
        cout << "No house found for that " << (field == 1 ? "address" : "landlord name") << ".\n";
    }
}

// Binary search by id on a sorted copy. O(n log n) to sort, O(log n) to search
void searchById(HouseList &list, int id) {
    Node *cur = list.getHead();

    if (cur == nullptr) {
        cout << "The house list is empty.\n";
        return;
    }

    // Count the nodes so we can size the array
    int n = 0;
    while (cur != nullptr) {
        n++;
        cur = cur->next;
    }

    // Copy the list into an array so the original list is not changed
    House *arr = new House[n];
    cur = list.getHead();
    for (int i = 0; i < n; i++) {
        arr[i] = cur->data;
        cur = cur->next;
    }

    // Adam's quick sort: by id, ascending
    sortHouses(arr, n, 2, 3, 1);

    int LOW = 0;
    int HI = n - 1;
    bool found = false;

    while (LOW <= HI) {
        int MID = (LOW + HI) / 2;

        if (arr[MID].id == id) {
            found = true;
            cout << "Found at sorted index " << MID << ":\n";
            cout << "  ID: " << arr[MID].id << "\n";
            cout << "  Address: " << arr[MID].address << "\n";
            cout << "  Rent: " << arr[MID].rent << "\n";
            cout << "  Rooms: " << arr[MID].rooms << "\n";
            cout << "  Distance: " << arr[MID].distanceKm << " km\n";
            cout << "  Status: " << arr[MID].status << "\n";
            cout << "  Landlord: " << arr[MID].landlordName << "\n";
            break;
        }
        else if (arr[MID].id < id) {
            LOW = MID + 1;
        }
        else {
            HI = MID - 1;
        }
    }

    if (!found) {
        cout << "No house found with ID " << id << ".\n";
    }

    delete[] arr;
}

#endif
