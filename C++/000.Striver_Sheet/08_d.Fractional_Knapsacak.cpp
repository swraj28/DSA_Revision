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


// The Key idea here is to sort the items in descending order in ratio of their (value / Weight)

struct Item {
	int value;
	int weight;
};


class Solution {
public:
	//Function to get the maximum total value in the knapsack.
	double fractionalKnapsack(int W, Item arr[], int n) {

		sort(arr, arr + n, [](Item & a, Item & b) {

			double v1 = (double)(a.value / (double)a.weight);
			double v2 = (double)(b.value / (double)b.weight);

			return v1 > v2;
		});

		int curWeight = 0;
		double finalvalue = 0.0;

		for (int i = 0; i < n; i++) {

			if (curWeight + arr[i].weight <= W) {
				curWeight += arr[i].weight;
				finalvalue += arr[i].value;
			} else {
				int remain = W - curWeight;
				finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
				break;
			}
		}

		return finalvalue;
	}
};
