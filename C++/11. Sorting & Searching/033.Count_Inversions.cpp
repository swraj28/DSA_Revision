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

// The Brute Force Approach is to use two nested loops and count the inversions.

// There is a smart trick that we can use to solve the problem is to use the merge sort

ll merge(vector<ll> &nums, int st, int end) {

    int mid = (st + (end - st) / 2);

    vector<ll> temp((end - st) + 1);

    int i = st, j = mid + 1;

    int k = 0;

    ll cnt = 0;

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i];
            i++;
        } else {
            temp[k++] = nums[j];

            j++;

            cnt += (mid - i) + 1;
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i];
        i++;
    }

    while (j <= end) {
        temp[k++] = nums[j];
        j++;
    }

    int pos = 0;

    for (int x = st; x <= end; x++) {
        nums[x] = temp[pos];
        pos++;
    }

    return cnt;
}

ll get_Inversions(vector<ll> &nums, int st, int end) {

    if (st == end) {
        return 0;
    }

    ll cnt = 0;

    ll mid = (st + (end - st) / 2);

    cnt += get_Inversions(nums, st, mid);
    cnt += get_Inversions(nums, mid + 1, end);

    cnt += merge(nums, st, end);

    return cnt;
}

long long getInversions(long long *arr, int n) {

    vector<ll> nums(n);

    for (int i = 0; i < n; i++) {
        nums[i] = arr[i];
    }

    return get_Inversions(nums, 0, n - 1);
}