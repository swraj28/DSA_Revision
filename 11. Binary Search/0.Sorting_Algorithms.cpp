#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))


/*
Stable Sorting Algotrithm:- https://www.geeksforgeeks.org/stable-selection-sort/

A sorting algorithm is said to be stable if two objects with equal or same keys appear in the same order in sorted output as
they appear in the input array to be sorted.
*/

//********************************************************************

// 1. Bubble Sort:-

/*
Complexity in Detail

Bubble Sort compares the adjacent elements. We try to make the right part sorted like we made the left part sorted in Selection Sort.

Cycle	Number of Comparisons
1st		(n-1)
2nd		(n-2)
3rd		(n-3)
.......	......
last	   1

Hence, the number of comparisons is

(n-1) + (n-2) + (n-3) +.....+ 1 = n(n-1)/2
nearly equals to n^2

Hence, Complexity: O(n^2)

Also, if we observe the code, bubble sort requires two loops. Hence, the complexity is n*n = n^2

1. Time Complexities:-

Worst Case Complexity: O(n^2)
If we want to sort in ascending order and the array is in descending order then the worst case occurs.

Best Case Complexity: O(n)
If the array is already sorted, then there is no need for sorting.

Average Case Complexity: O(n^2)
It occurs when the elements of the array are in jumbled order (neither ascending nor descending).


2. Space Complexity:-

Space complexity is O(1) because an extra variable is used for swapping.

In the optimized bubble sort algorithm, two extra variables are used. Hence, the space complexity will be O(2).

*/

void BubbleSort(vector<int> &arr) {

	int n = arr.size();

	for (int i = 0; i < n - 1; i++) {

		bool is_sorted = false;

		for (int j = 0; j < n - i - 1; j++) {

			if (arr[j] > arr[j + 1]) { // we always check adjacent elements
				swap(arr[j], arr[j + 1]);
				is_sorted = true;
			}
		}

		// Optimization:-

		if (is_sorted == false) {
			break;
		}
	}
}

//*******************************************************************//

// 2. Selection Sort:-  (Not Stable) (Inplace)

/*

The time complexity of the selection sort is the same in all cases.
At every step, you have to find the minimum element and put it in the right place to the left.
The minimum element is not known until the end of the array is not reached.

Number of comparisons: (n - 1) + (n - 2) + (n - 3) + ..... + 1 = n(n - 1) / 2 nearly equals to n^2.

Number of Swaps :- At most n swaps.

Time Complexities:

Worst Case Complexity: O(n^2)
If we want to sort in ascending order and the array is in descending order then, the worst case occurs.

Best Case Complexity: O(n^2)
It occurs when the array is already sorted

Average Case Complexity: O(n^2)
It occurs when the elements of the array are in jumbled order (neither ascending nor descending).

Space Complexity:
Space complexity is O(1) because an extra variable min_idx is used.

*/

int findMinIdx(vector<int> &arr, int i) {

	int min_idx = i;

	while (i < arr.size()) {

		if (arr[i] < arr[min_idx]) {
			min_idx = i;
		}

		i++;
	}

	return min_idx;
}

void selectionSort(vector<int> &arr) {

	for (int i = 0; i < arr.size(); i++) {

		int min_idx = findMinIdx(arr, i);

		if (i != min_idx) swap(arr[i], arr[min_idx]);
	}
}

//******************************************************************************************

// 3. Insertion Sort :- (Stable) (Inplace)

/*

Insertion sort works similarly as we sort cards in our hand in a card game.

We assume that the first card in our left hand is already sorted then, we select an unsorted card from the right hand.
And the chosen card from the unsorted part is placed at its correct position in the sorted part (i.e., Left hand).

Time Complexities:-

Worst Case Complexity: O(n^2)

Suppose, an array is in ascending order, and you want to sort it in descending order. In this case, worst case complexity occurs.
Each element has to be compared with each of the other elements so, for every nth element, (n-1) number of comparisons are made.

Thus, the total number of comparisons and swaps in worst case  = n*(n-1) ~ n^2


Best Case Complexity: O(n)
When the array is already sorted, the outer loop runs for n number of times whereas the inner loop does not run at all. So, there are only n number of comparisons.
Thus, complexity is linear.

Average Case Complexity: O(n^2)
It occurs when the elements of an array are in jumbled order (neither ascending nor descending).

Space Complexity:-

Space complexity is O(1) because an extra variable key is used.
*/

void insertionSort(vector<int> &arr) {

	for (int i = 1; i < arr.size(); i++) {

		// find the best place for the ith element
		int key = arr[i];

		// the best place will be somewhere from 0..i-1
		int j = i - 1;

		while (j >= 0 and arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

//***********************************************************************