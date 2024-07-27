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
	int removeDuplicates(vector<int>& nums) {

		int n = nums.size();

		if (n == 0) {
			return 0;
		}


		int idx = 1;

		int total = 1;

		for (int i = 1; i < n; i++) {
			if (nums[i] == nums[i - 1]) {

			} else {
				nums[idx] = nums[i];
				idx++;
				total++;
			}
		}

		return total;
	}
};