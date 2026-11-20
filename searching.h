/* Mohammed Muaadh Shaif Mohammed Mukred (P5)  AI01087011
   Write the two functions. Don't rename them.
   Linear search walks the list from getHead. Address or landlord.
   No std::find. The list is not sorted, so this is O(n).

   Binary search is by house ID only. Rent can repeat, so don't search by rent.
   Sort a copy first: sortHouses(arr, n, 2, 3, 1). That's Adam's quick sort, by id, ascending.
   Chapter 9: LOW, HI, MID = (LOW + HI) / 2.
*/

#ifndef SEARCHING_H
#define SEARCHING_H

#include "linkedlist.h"
#include "sorting.h"

// field: 1 = address, 2 = landlord name
void linearSearch(HouseList &, string, int) {
    cout << "linearSearch is not written yet (Mukred).\n";
}

void searchById(HouseList &, int) {
    cout << "searchById is not written yet (Mukred).\n";
}

#endif
