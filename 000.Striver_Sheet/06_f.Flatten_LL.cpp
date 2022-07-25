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

struct Node {
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x) {
		data = x;
		next = NULL;
		bottom = NULL;
	}
};

Node* mergeTwoLists(Node* l1, Node* l2) {

	if (l2 == nullptr) {
		Node* head = nullptr, *prev = nullptr;

		while (l1 != nullptr) {
			Node* temp = l1->bottom;
			if (head == nullptr) {
				head = l1;
				prev = head;
				head->bottom = nullptr;
			} else {
				prev->bottom = l1;
				l1->bottom = nullptr;
				prev = prev->bottom;
			}
			l1 = temp;
		}

		return head;
	}

	Node* head = nullptr, *prev = nullptr;

	while (l1 != nullptr && l2 != nullptr) {

		if (l1->data <= l2->data) {

			Node* temp = l1->bottom;

			if (head == nullptr) {
				head = l1;
				prev = head;
				head->bottom = nullptr;
			} else {
				prev->bottom = l1;
				l1->bottom = nullptr;
				prev = prev->bottom;
			}
			l1 = temp;
		} else {
			Node* temp = l2->bottom;

			if (head == nullptr) {
				head = l2;
				prev = head;
				head->bottom = nullptr;
			} else {
				prev->bottom = l2;
				l2->bottom = nullptr;
				prev = prev->bottom;
			}

			l2 = temp;
		}
	}

	while (l1 != nullptr) {

		Node* temp = l1->bottom;

		prev->bottom = l1;
		l1->bottom = nullptr;
		prev = prev->bottom;

		l1 = temp;
	}

	while (l2 != nullptr) {

		Node* temp = l2->bottom;

		prev->bottom = l2;
		l2->bottom = nullptr;
		prev = prev->bottom;


		l2 = temp;
	}

	return head;
}


Node *flatten(Node *root) {

	if (root == nullptr) {
		return root;
	}

	if (root->next == nullptr) {
		return mergeTwoLists(root, nullptr);
	}

	Node* r1 = root, *r2 = root->next;

	Node* temp = root->next->next;

	r1->next = nullptr, r2->next = nullptr;

	Node* head = mergeTwoLists(r1, r2);

	while (temp != nullptr) {
		Node* temp_1 = temp->next;
		temp->next = nullptr;

		head = mergeTwoLists(head, temp);

		temp = temp_1;
	}

	return head;
}