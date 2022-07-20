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
Since we have a pool of 9 number to choose from, let's say the pool size is P (in this case P = 9)
and each node can have at most P branches (in actual cases, it is in most time less than P).

This backtracking can at most have (K + 1) levels.

So, time complexity is less than O(K * P^K) (copying K-size list takes O(K)).
*/

class Solution {
public:
    vector<vector<int>> ans;

    void recur(int si, int k, int &n, vector<int> &v) {

        if (n == 0 and v.size() == k) {
            ans.push_back(v);
            return;
        }

        if (n < 0 || v.size() >= k) {
            return;
        }

        for (int i = si; i <= 9; i++) {

            n -= i;
            v.push_back(i);

            recur(i + 1, k, n, v);

            n += i;
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> v;

        recur(1, k, n, v);

        return ans;
    }
};