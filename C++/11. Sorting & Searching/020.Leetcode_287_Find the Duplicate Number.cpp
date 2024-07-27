

// 1. Sorting:-
// 2. Frequency Array / map

// 3. Binay Search :-

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

class Solution {
public:
	int findDuplicate(vector<int>& nums) {

		int n = nums.size();

		int dup = -1;
		int idx = 0;

		while (nums[idx] != -1) {

			int prev_idx = idx;

			idx = nums[idx];

			dup = nums[prev_idx];

			nums[prev_idx] = -1;
		}

		return dup;
	}
};


// 4. Using Floyd Cycle Detection Algorithm:- (Finding the starting point of a cycle)

class Solution {
public:
	int findDuplicate(vector<int>& nums) {

		// Find the intersection point of the two runners.
		int tortoise = nums[0];
		int hare = nums[0];

		do {
			tortoise = nums[tortoise];
			hare = nums[nums[hare]];
		} while (tortoise != hare);

		// Find the "entrance" to the cycle.
		tortoise = nums[0];
		while (tortoise != hare) {
			tortoise = nums[tortoise];
			hare = nums[hare];
		}

		return hare;
	}
};

