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
Let us understand the time complexity of Combination Sum II at the beginning:
O(k * 2 ^ n) is the time complexity of Combination Sum II
:
k is average length of each solution, and we need O(k) time to copy new linkedlist when we get one combination.

Considering that the combinations may have different length, which range from 0 ~ n having an average length of k. So, there are at most
C(n,0) + C(n,1) + C(n,2) + ... C(n,n) solutions. We know that C(n,0) + C(n,1) + C(n,2) + ... C(n,n) = 2^n.

Then we got the time complexity of Combination Sum II which is O(k * 2 ^ n).
Solution space: (k*x) x--> total number of combinations.
*/

class Solution {
public:
    vector<vector<int>> ans;

    void recur(vector<int>& candidates, int n, int si, int &target, vector<int> &v) {

        if (target == 0) {
            ans.push_back(v);
            return;
        }

        if (target < 0) {
            return;
        }

        // We dont need to apply second recusion call as it will be manged by the for loop

        for (int i = si; i < n; i++) {

            if (i > si and candidates[i] == candidates[i - 1]) { // To avoid the use of duplicates (Make a Dry Run for better Understanding).
                continue;
            }

            target -= candidates[i];
            v.push_back(candidates[i]);

            recur(candidates, n, i + 1, target, v);

            target += candidates[i];
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        int n = candidates.size();

        vector<int> v;

        recur(candidates, n, 0, target, v);

        return ans;
    }
};