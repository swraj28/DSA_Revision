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
	int minSubArrayLen(int s, vector<int>& nums) {//o(n)

		if (nums.size() == 0)return 0;
		if (nums.size() == 1 and nums[0] >= s)return 1;

		int left = 0;
		int size = INT_MAX;

		int sum = 0;

		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];

			while (sum >= s) { //window
				size = min(size, i + 1 - left);

				sum -= nums[left];
				left++;
			}
		}

		return (size == INT_MAX) ? 0 : size;

	}
};