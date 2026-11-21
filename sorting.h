/* Muhammad Adam Aqil bin Mohmad Fauzi (P4)  CS01086759
   Write sortHouses. Don't change the name or the arguments.
   Chapter 8 has no merge sort, so don't use it. The role PDF is wrong there.
   Insertion sort, and quick sort with the last element as pivot. No std::sort.
   Sort the array copy. Leave Hariz's list alone.

   method:  1 insertion, 2 quick
   keyType: 1 rent, 2 distance, 3 id
   order:   1 ascending, 2 descending
   Mukred's binary search needs id, ascending (3 and 1).
*/

#ifndef SORTING_H
#define SORTING_H

#include "house.h"
#include <vector>

inline bool shouldComeBefore(const House& a, const House& b, int sortBy, bool ascending) {
    if (sortBy == 1) { // Sort by rent (duplicate rents are allowed)
        return ascending ? (a.rent < b.rent) : (a.rent > b.rent);
    } else if (sortBy == 2) { // Sort by distanceKm
        return ascending ? (a.distanceKm < b.distanceKm) : (a.distanceKm > b.distanceKm);
    } else { // Sort by id (unique ID)
        return ascending ? (a.id < b.id) : (a.id > b.id);
    }
}

inline void insertionSort(std::vector<House>& houses, int sortBy, bool ascending) {
    int n = static_cast<int>(houses.size());
    for (int i = 1; i < n; i++) {
        House key = houses[i];
        int j = i - 1;

        while (j >= 0 && shouldComeBefore(key, houses[j], sortBy, ascending)) {
            houses[j + 1] = houses[j];
            j--;
        }
        houses[j + 1] = key;
    }
}

inline void merge(std::vector<House>& houses, int left, int mid, int right, int sortBy, bool ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<House> leftArr(n1);
    std::vector<House> rightArr(n2);

    for (int i = 0; i < n1; i++) leftArr[i] = houses[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = houses[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (shouldComeBefore(leftArr[i], rightArr[j], sortBy, ascending) ||
            (!shouldComeBefore(rightArr[j], leftArr[i], sortBy, ascending))) {
            houses[k++] = leftArr[i++];
        } else {
            houses[k++] = rightArr[j++];
        }
    }

    while (i < n1) houses[k++] = leftArr[i++];
    while (j < n2) houses[k++] = rightArr[j++];
}

inline void mergeSort(std::vector<House>& houses, int left, int right, int sortBy, bool ascending) {
    if (left >= right) return; 

    int mid = left + (right - left) / 2;
    mergeSort(houses, left, mid, sortBy, ascending);
    mergeSort(houses, mid + 1, right, sortBy, ascending);
    merge(houses, left, mid, right, sortBy, ascending);
}

inline void displaySortedHouses(const std::vector<House>& houses) {
    for (const auto& h : houses) {
        printHouse(h);
    }
}

#endif 
