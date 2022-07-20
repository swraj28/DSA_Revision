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

// This Question is a spl case of Partition to k equal sum subset (Leetcode -698) Here k=4.

/*

    Total number of stick is n. Out of the n stick it can be among the four sides of the square. Therefore at every stick we have 4
    possiblities .

    T.c:- O(4^n).

    Space :- For recursive solutions, the space complexity is the stack space occupied by all the recursive calls. O(n)

*/

class Solution {
public:

	bool recur(vector<int>& nums, int n, int si, int req, int c_sm, int k, vector<int> &visited) {
		if (k == 1) {
			return true;
		}

		if (c_sm == req) {
			return recur(nums, n, 0, req, 0, k - 1, visited);
		}

		for (int i = si; i < n; i++) {
			if (!visited[i]) {

				if ((c_sm + nums[i]) <= req) {

					visited[i] = 1;

					bool rec_res = recur(nums, n, i + 1, req, c_sm + nums[i], k, visited);

					if (rec_res == true) {
						return true;
					}

					visited[i] = 0;
				}
			}
		}

		return false;
	}

	bool makesquare(vector<int>& matchsticks) {

		int sm = accumulate(all(matchsticks), 0);

		int n = matchsticks.size();

		if (sm % 4 || n < 4) {
			return false;
		}

		int req = (sm / 4);

		vector<int> visited(n, 0);

		return recur(matchsticks, n, 0, req, 0, 4, visited);
	}
};