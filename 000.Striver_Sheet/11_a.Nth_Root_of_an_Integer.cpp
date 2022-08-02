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

double findNthRootOfM(int n, long long m) {

    double st = 1.0, end = m;

    while (st + (1e-8) < end) {

        double mid = (st + (end - st) / (2 * (1.0)));

        double val = mid;

        for (int i = 1; i < n; i++) {
            val *= (double)mid;
        }

        if (val > m) {
            end = mid;
        } else {
            st = mid;
        }
    }

    return st;
}