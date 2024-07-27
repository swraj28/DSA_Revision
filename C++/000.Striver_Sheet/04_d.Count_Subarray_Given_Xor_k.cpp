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

int subarraysXor(vector<int> &nums, int x) {

    int n = nums.size();

    unordered_map<int, int> m;

    int val = 0;

    int total = 0;

    for (int i = 0; i < n; i++) {
        val ^= nums[i];

        if (val == x) {
            total++;

            total += m[0];

            m[val]++;
        } else if (m.count((val ^ x))) {
            total += m[(val ^ x)];

            m[val]++;
        } else {
            m[val]++;
        }
    }

    return total;
}