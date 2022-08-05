
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;


struct Node {
	int data;
	struct Node *next;
	bool visited = false;
};
struct Node* head = NULL;

void insert(int newdata) {
	Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	Node *ptr = head;
	newnode->data = newdata;
	newnode->next = head;
	if (head != NULL) {
		while (ptr->next != head)
			ptr = ptr->next;
		ptr->next = newnode;
	} else
		newnode->next = newnode;
	head = newnode;
}
void display() {
	struct Node* ptr;
	ptr = head;
	do {
		cout << ptr->data << " ";
		ptr = ptr->next;
	} while (ptr != head);
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		insert(n - i + 1);
	int index = 1000;
	int curr_time = 0;
	int i;
	Node* temp = head;
	while (index) {
		temp->visited = true;
		curr_time++;
		i = curr_time;
		while (i--) {
			// cout << temp->visited << " ";
			temp = temp->next;
		}
		index--;
	}
	temp = head;
	bool ok = true;
	do {
		// cout << temp->visited << " ";
		if(temp->visited == false) {
			ok = false;
			break;
		}
		temp = temp->next;
	}while(temp != head);
	if (ok)
		cout << "YES";
	else
		cout << "NO";
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T = 1;
	// cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		solve();
	}
	return 0;
}
