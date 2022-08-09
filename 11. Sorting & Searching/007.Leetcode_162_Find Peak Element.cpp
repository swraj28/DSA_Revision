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
 What we are essentially doing is going in the direction of the rising slope(by choosing the element which is greater than current).
 How does that guarantee the result?
 Think about it, there are 2 possibilities.
 a) rising slope has to keep rising till end of the array.
 b) rising slope will encounter a lesser element and go down.

In both scenarios we will have an answer.
In a) the answer is the end element because we take the boundary as -INFINITY
b) the answer is the largest element before the slope falls.

*/

class Solution {
public:
	int findPeakElement(vector<int>& nums) {

		int n = nums.size();

		int st = 0, end = n - 1;

		while (st + 1 < end) {

			int mid = (st + (end - st) / 2);

			int mid1 = mid + 1;

			if (nums[mid1] > nums[mid]) {
				st = mid;
			} else {
				end = mid;
			}
		}

		if (nums[end] > nums[st]) {
			return end;
		}

		return st;
	}
};