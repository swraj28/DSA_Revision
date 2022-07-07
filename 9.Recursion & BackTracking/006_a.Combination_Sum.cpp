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
   Time and Space Complexity Analysis:-

   Since for each and every element we have infinite amount of supply therefore let (n') be the new length of the array.
   For example, given int[] arr = {2, 3, 4, 5, 6} and target is 10 and each element can be used for MORE than once.
   Actually, it is same with the problem: given int[] arr = {2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6}, and target 10

   Now the time complexity is similar to the time complexity of (Combination Sum 2).

   Considering that the combinations may have different length, which range from 0 ~ n' having an average length of k. So, there are at most
    C(n',0) + C(n',1) + C(n',2) + ... C(n',n') solutions. We know that C(n',0) + C(n',1) + C(n',2) + ... C(n',n') = 2^n'.

Then we got the time complexity of Combination Sum II which is O(k * 2 ^ n').

Solution space: (k*x) x--> total number of combinations.
*/

class Solution {
public:

	vector<vector<int>> ans;

	void recur(vector<int>& candidates, int n, int si, int target, vector<int> &v) {
		if (si >= n) {
			if (target == 0) {
				ans.pb(v);
			}
			return;
		}

		if (target >= candidates[si]) {

			v.pb(candidates[si]);

			recur(candidates, n, si, target - candidates[si], v);

			v.pop_back(); // Backtracking
		}

		recur(candidates, n, si + 1, target, v);
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		int n = candidates.size();

		vector<int> v;

		recur(candidates, n, 0, target, v);

		return ans;
	}
};