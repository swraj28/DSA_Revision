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

// Optimized :- By using Moore Vooting Algorithm:-

/*
 		The key idea behind the method is that, if we pair distinct elements in the array and eliminate them,
 		then the element we will be left with in the end would be the one which is a majority element,
 		provided that there exists a majority in the array.
*/

// T.c:- O(n) and S.c:- O(1)

class Solution {
public:
	int majorityElement(vector<int>& nums) {

		int n = nums.size();

		int maj_element = nums[0], count = 1;

		for (int i = 1; i < n; i++) {
			if (count == 0) {
				count++;
				maj_element = nums[i];
			} else if (nums[i] == maj_element) {
				count++;
			} else {
				count--;
			}
		}

		return maj_element;
	}
};