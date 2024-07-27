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

int getMedian(vector<vector<int>> &matrix) {

    int n = matrix.size(), m = matrix[0].size();

    int st = INT_MAX, end = INT_MIN;

    for (int i = 0; i < n; i++) {
        st = min(st, matrix[i][0]);
        end = max(end, matrix[i][m - 1]);
    }

    int req = (n * m) / 2 + 1;

    while (st + 1 < end) {

        int mid = (st + (end - st) / 2);

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += upper_bound(all(matrix[i]), mid) - matrix[i].begin();
        }

        if (cnt >= req) {
            end = mid;
        } else {
            st = mid;
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += upper_bound(all(matrix[i]), st) - matrix[i].begin();
    }


    if (cnt == req) {
        return st;
    }

    return end;

}