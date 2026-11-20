/* CSEB3213 Data Structures and Algorithms
   Section 01C
   Group 13
   Amirul Hakimi bin Mohd Azren (P1)  AI01086660
   Menu, input checks, and joining the files.

   g++ -std=c++17 main.cpp -o rental
   ./rental

   Hariz, Zaim, Adam and Mukred still write their own files.
   main joins them. linkedlist.h does not include queue.h,
   so Hariz can compile without waiting for Zaim.
   If status flips to Available, update sets a flag and main calls the queue.
*/

#include "linkedlist.h"
#include "queue.h"
#include "sorting.h"
#include "searching.h"

int readInt(string prompt) {
    int x;
    while (true) {
        cout << prompt;
        cin >> x;
        if (cin.fail()) {
            if (cin.eof()) {
                cout << "\nEnd of program\n";
                return -1;
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number.\n";
        } else {
            cin.ignore(1000, '\n');
            return x;
        }
    }
}

double readDouble(string prompt) {
    double x;
    while (true) {
        cout << prompt;
        cin >> x;
        if (cin.fail()) {
            if (cin.eof()) {
                cout << "\nEnd of program\n";
                return -1;
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number.\n";
        } else {
            cin.ignore(1000, '\n');
            return x;
        }
    }
}

string readLine(string prompt) {
    string s;
    while (true) {
        cout << prompt;
        if (!getline(cin, s)) {
            cout << "\nEnd of program\n";
            return "";
        }
        if (s == "") {
            cout << "Input cannot be empty.\n";
        } else {
            return s;
        }
    }
}

string readStatus() {
    while (true) {
        int c = readInt("Status (1 = Available, 2 = Rented): ");
        if (c == 1) {
            return "Available";
        }
        if (c == 2) {
            return "Rented";
        }
        cout << "Invalid status. Enter 1 or 2.\n";
    }
}

void showMenu() {
    cout << "\n==== Student Apartment Rental ====\n";
    cout << "1  Add house\n";
    cout << "2  Update house\n";
    cout << "3  Remove house\n";
    cout << "4  Display all houses\n";
    cout << "5  Display available houses\n";
    cout << "6  Traverse list (forward and backward)\n";
    cout << "7  Sort houses (copy only)\n";
    cout << "8  Search by address or landlord\n";
    cout << "9  Search by house ID (binary search)\n";
    cout << "10 Add student to waiting list\n";
    cout << "11 Display waiting list\n";
    cout << "12 Exit\n";
}

// First student waiting for this house gets it. House goes back to Rented.
void giveHouse(HouseList &list, WaitingList &wait, int houseId) {
    Student got = wait.offerHouse(houseId);
    if (got.id == -1) {
        cout << "No student is waiting for house " << houseId << ".\n";
        return;
    }
    list.setStatus(houseId, "Rented");
    cout << "House " << houseId << " given to " << got.name
         << " (student ID " << got.id << "). Status is Rented.\n";
}

void loadSample(HouseList &list, WaitingList &wait) {
    House h;

    h.id = 101;
    h.address = "Jalan Kajang 3";
    h.rent = 450;
    h.rooms = 1;
    h.distanceKm = 1.2;
    h.status = "Available";
    h.landlordName = "Ahmad";
    list.addHouse(h);

    h.id = 102;
    h.address = "Taman Kajang Utama";
    h.rent = 700;
    h.rooms = 2;
    h.distanceKm = 2.5;
    h.status = "Rented";
    h.landlordName = "Siew May";
    list.addHouse(h);

    h.id = 103;
    h.address = "Bandar Baru Bangi";
    h.rent = 550;
    h.rooms = 1;
    h.distanceKm = 4.0;
    h.status = "Available";
    h.landlordName = "Ravi";
    list.addHouse(h);

    h.id = 104;
    h.address = "Kajang Avenue";
    h.rent = 900;
    h.rooms = 3;
    h.distanceKm = 1.8;
    h.status = "Rented";
    h.landlordName = "John";
    list.addHouse(h);

    h.id = 105;
    h.address = "Seksyen 7 Bangi";
    h.rent = 650;
    h.rooms = 2;
    h.distanceKm = 5.5;
    h.status = "Available";
    h.landlordName = "Mohammad";
    list.addHouse(h);

    h.id = 106;
    h.address = "Taman Jasmin";
    h.rent = 500;
    h.rooms = 1;
    h.distanceKm = 3.2;
    h.status = "Rented";
    h.landlordName = "Jennifer";
    list.addHouse(h);

    Student s;
    s.id = 201;
    s.name = "Ali";
    s.phone = "012-3451111";
    s.preferredHouseId = 104;
    wait.enqueue(s);

    s.id = 202;
    s.name = "Siti";
    s.phone = "013-3452222";
    s.preferredHouseId = 102;
    wait.enqueue(s);

    s.id = 203;
    s.name = "Kumar";
    s.phone = "014-3453333";
    s.preferredHouseId = 104;
    wait.enqueue(s);

    cout << "Sample calls are ready. Houses show up after Hariz's addHouse works.\n";
    cout << "Ali and Kumar both wait for house 104. Ali is first.\n";
}

void doAdd(HouseList &list) {
    House h;
    h.id = readInt("House ID: ");
    h.address = readLine("Address: ");
    h.rent = readDouble("Rent (RM): ");
    h.rooms = readInt("Rooms: ");
    h.distanceKm = readDouble("Distance from UNITEN (km): ");
    h.status = readStatus();
    h.landlordName = readLine("Landlord name: ");
    if (list.addHouse(h)) {
        cout << "House added.\n";
    }
}

void doUpdate(HouseList &list, WaitingList &wait) {
    if (list.isEmpty()) {
        cout << "List is empty. Nothing to update.\n";
        return;
    }
    int id = readInt("House ID to update: ");
    HouseNode *n = list.findById(id);
    if (n == NULL) {
        cout << "House ID not found.\n";
        return;
    }
    cout << "Current record:\n";
    printHouse(n->data);

    cout << "1 Address\n";
    cout << "2 Rent\n";
    cout << "3 Rooms\n";
    cout << "4 Distance\n";
    cout << "5 Status\n";
    cout << "6 Landlord name\n";
    int field = readInt("Field: ");

    House edited = n->data;
    if (field == 1) {
        edited.address = readLine("New address: ");
    } else if (field == 2) {
        edited.rent = readDouble("New rent (RM): ");
    } else if (field == 3) {
        edited.rooms = readInt("New rooms: ");
    } else if (field == 4) {
        edited.distanceKm = readDouble("New distance (km): ");
    } else if (field == 5) {
        edited.status = readStatus();
    } else if (field == 6) {
        edited.landlordName = readLine("New landlord name: ");
    } else {
        cout << "Invalid field.\n";
        return;
    }

    bool becameAvailable = false;
    if (!list.updateHouse(edited, becameAvailable)) {
        return;
    }
    cout << "House updated.\n";
    if (becameAvailable) {
        giveHouse(list, wait, id);
    }
}

void doRemove(HouseList &list, WaitingList &wait) {
    if (list.isEmpty()) {
        cout << "List is empty. Nothing to remove.\n";
        return;
    }
    int id = readInt("House ID to remove: ");
    if (list.findById(id) == NULL) {
        cout << "House ID not found.\n";
        return;
    }
    int dropped = wait.purgeHouse(id);
    if (dropped > 0) {
        cout << dropped << " waiting student(s) removed for this house.\n";
    }
    if (list.removeHouse(id)) {
        cout << "House removed.\n";
    }
}

void printArray(House arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printHouse(arr[i]);
    }
}

void doSort(HouseList &list) {
    if (list.isEmpty()) {
        cout << "List is empty. Nothing to sort.\n";
        return;
    }
    cout << "1 Insertion sort by rent\n";
    cout << "2 Insertion sort by distance\n";
    cout << "3 Quick sort by rent\n";
    cout << "4 Quick sort by distance\n";
    cout << "5 Quick sort by house ID\n";
    int pick = readInt("Sort: ");
    if (pick < 1 || pick > 5) {
        cout << "Invalid sort choice.\n";
        return;
    }
    int order = readInt("Order (1 = ascending, 2 = descending): ");
    if (order != 1 && order != 2) {
        cout << "Invalid order.\n";
        return;
    }

    int method = 1;
    int keyType = 1;
    if (pick == 1) {
        method = 1;
        keyType = 1;
    } else if (pick == 2) {
        method = 1;
        keyType = 2;
    } else if (pick == 3) {
        method = 2;
        keyType = 1;
    } else if (pick == 4) {
        method = 2;
        keyType = 2;
    } else {
        method = 2;
        keyType = 3;
    }

    House arr[MAX_HOUSE];
    int n = list.copyToArray(arr, MAX_HOUSE);
    sortHouses(arr, n, method, keyType, order);

    cout << "Sorted copy. Original list is not changed.\n";
    printArray(arr, n);
}

void doLinear(HouseList &list) {
    int field = readInt("Search by (1 = address, 2 = landlord): ");
    if (field != 1 && field != 2) {
        cout << "Invalid field.\n";
        return;
    }
    string key = readLine("Keyword: ");
    linearSearch(list, key, field);
}

void doBinary(HouseList &list) {
    int id = readInt("House ID: ");
    searchById(list, id);
}

void doEnqueue(HouseList &list, WaitingList &wait) {
    if (list.isEmpty()) {
        cout << "No houses yet. Add a house first.\n";
        return;
    }
    Student s;
    s.id = readInt("Student ID: ");
    s.name = readLine("Student name: ");
    s.phone = readLine("Phone: ");
    s.preferredHouseId = readInt("Preferred house ID: ");

    HouseNode *n = list.findById(s.preferredHouseId);
    if (n == NULL) {
        cout << "That house ID does not exist.\n";
        return;
    }
    if (!wait.enqueue(s)) {
        return;
    }
    cout << "Student added to the waiting list.\n";

    // House already free? Give it out now, same rule as an update.
    if (n->data.status == "Available") {
        giveHouse(list, wait, s.preferredHouseId);
    }
}

int main() {
    HouseList list;
    WaitingList wait;
    loadSample(list, wait);

    int choice = 0;
    do {
        showMenu();
        choice = readInt("Choice: ");
        if (choice == -1) {
            break;
        } else if (choice == 1) {
            doAdd(list);
        } else if (choice == 2) {
            doUpdate(list, wait);
        } else if (choice == 3) {
            doRemove(list, wait);
        } else if (choice == 4) {
            list.displayAll();
        } else if (choice == 5) {
            list.displayAvailable();
        } else if (choice == 6) {
            list.traverse();
        } else if (choice == 7) {
            doSort(list);
        } else if (choice == 8) {
            doLinear(list);
        } else if (choice == 9) {
            doBinary(list);
        } else if (choice == 10) {
            doEnqueue(list, wait);
        } else if (choice == 11) {
            wait.display();
            if (!wait.isEmpty()) {
                cout << "Front (peek): ";
                printStudent(wait.peek());
            }
        } else if (choice == 12) {
            cout << "End of program\n";
        } else {
            cout << "Invalid menu choice.\n";
        }
    } while (choice != 12);

    return 0;
}
