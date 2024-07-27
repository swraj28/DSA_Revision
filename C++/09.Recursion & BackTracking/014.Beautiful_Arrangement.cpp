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

    // T.c:- O(Number Of Valid Permutations).

    // S.c:- O(n)--> Recursive Call Stack

    void permute(vector<int> &v, int n, int si, int &cnt) {
        if (si >= n) {
            cnt++;
            return;
        }

        for (int i = si; i < n; i++) {

            swap(v[i], v[si]);

            if ((v[si] % (si + 1) == 0) or ((si + 1) % v[si]) == 0) {
                permute(v, n, si + 1, cnt);
            }

            swap(v[i], v[si]);
        }
    }

    int countArrangement(int n) {

        vector<int> v;

        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }

        int cnt = 0;

        permute(v, n, 0, cnt);

        return cnt;
    }
};