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


// If we are allowed to modify the array :- We will use negative indexing

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

// You must solve the problem without modifying the array nums and uses only constant extra space.

class Solution {
public:

	// 1. Sorting:-

	int find_Duplicate(vector < int > & arr) {
		int n = arr.size();
		sort(arr.begin(), arr.end());
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] == arr[i + 1]) {
				return arr[i];
			}
		}

		return 0;
	}

	// 2. Using Frequncey Array:-

	int find_Duplicate(vector < int > & arr) {
		int n = arr.size();
		int freq[n + 1] = {0};

		for (int i = 0; i < n; i++) {
			if (freq[arr[i]] == 0) {
				freq[arr[i]] += 1;
			} else {
				return arr[i];
			}
		}

		return 0;
	}

	// 3. Using Floyd Cycle Detection Algorithm :- Finding the Strarting Point

	// Constant Space

	int find_Duplicate(vector < int > & nums) {

		int slow = nums[0];
		int fast = nums[0];

		do {
			slow = nums[slow]; // it will move one step at a time .
			fast = nums[nums[fast]]; // it will move two step at a time  .
		} while (slow != fast);

		fast = nums[0];

		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}

		return slow;
	}

	int findDuplicate(vector<int>& nums) {

	}
};