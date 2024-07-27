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

/*

Time Complexity: O(N*N*M) - where N is the no of nodes in main linked list (reachable using right pointer)
and M is the no of node in a single sub linked list (reachable using down pointer).

Explanation: As we are merging 2 lists at a time,

After adding first 2 lists, time taken will be O(M+M) = O(2M).
Then we will merge another list to above merged list -> time = O(2M + M) = O(3M).
Then we will merge another list -> time = O(3M + M).
We will keep merging lists to previously merged lists until all lists are merged.
Total time taken will be O(2M + 3M + 4M + .... N*M) = (2 + 3 + 4 + ... + N)*M
Using arithmetic sum formula: time = O((N*N + N - 2)*M/2)

Above expression is roughly equal to O(N*N*M) for large value of N

Space Complexity :- O(1)

*/

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

// Slightly Optimized

/*

    Time Complexity: O(N*M*log(N)) – where N is the no of nodes in main linked list (reachable using next pointer)
    and M is the no of node in a single sub linked list (reachable using bottom pointer).

Space Complexity: O(N)-where N is the no of nodes in main linked list (reachable using next pointer)

*/

struct mycomp {

	bool operator()(Node* a, Node* b) {
		return a->data > b->data;
	}
};

void flatten(Node* root) {

	priority_queue<Node*, vector<Node*>, mycomp> p;

	//pushing main link nodes into priority_queue.

	while (root != NULL) {
		p.push(root);
		root = root->next;
	}

	while (!p.empty()) {
		//extracting min
		auto k = p.top();
		p.pop();
		//printing  least element
		cout << k->data << " ";

		if (k->bottom) {
			p.push(k->bottom);
		}
	}
}