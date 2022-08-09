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

// Template 1:-

int binarySearch_1(vector<int>& nums, int target) {
	if (nums.size() == 0)
		return -1;

	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		// Prevent (left + right) overflow
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) { return mid; }
		else if (nums[mid] < target) { left = mid + 1; }
		else { right = mid - 1; }
	}

	// End Condition: left > right
	return -1;
}

// Template 2:-

int binarySearch_2(vector<int>& nums, int target) {
	if (nums.size() == 0)
		return -1;

	int left = 0, right = nums.size();
	while (left < right) {
		// Prevent (left + right) overflow
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) { return mid; }
		else if (nums[mid] < target) { left = mid + 1; }
		else { right = mid; }
	}

	// Post-processing:
	// End Condition: left == right
	if (left != nums.size() && nums[left] == target) return left;

	return -1;
}

// Template 3:-

int binarySearch_3(vector<int>& nums, int target) {
	if (nums.size() == 0) {
		return -1;
	}

	int left = 0, right = nums.size() - 1;

	while (left + 1 < right) {
		// Prevent (left + right) overflow
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] < target) {
			left = mid;
		} else {
			right = mid;
		}
	}

	// Post-processing:

	// End Condition: left + 1 == right

	if (nums[left] == target) return left;
	if (nums[right] == target) return right;

	return -1;
}