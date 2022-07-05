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

class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};

class Solution {
public:
	Node* flatten(Node* head) {

		if (head == nullptr) {
			return head;
		}

		Node*curr = head;

		while (curr != nullptr) {

			if (curr->child == nullptr) {
				curr = curr->next;
				continue;
			}

			Node* h1 = curr->child;
			curr->child = nullptr;

			Node* temp = h1;

			while (temp->next) {
				temp = temp->next;
			}

			Node* c1 = curr->next;

			curr->next = h1;
			h1->prev = curr;

			temp->next = c1;

			if (c1) {
				c1->prev = temp;
			}

			curr = curr->next;
		}

		return head;
	}
};