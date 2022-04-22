#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl			"\n"
#define ll 				long long int
#define vi 				vector<int>
#define vll				vector<ll>
#define vvi 			vector < vi >
#define vb 				vector<bool>
#define vs 				vector<string>
#define pii 			pair<int,int>
#define pll 			pair<long long, long long>
#define vpi				vector <pii>
#define vpp 			vector<pair<ll,ll>>
#define mii				map <int, int>
#define mpi 			map <pii, int>
#define spi 			set <pii>
#define que_max			priority_queue <int>
#define que_min			priority_queue <int, vi, greater<int>>
#define repi(i, m, n) 	for (auto i = m; i != n; i++)
#define repd(i, m, n) 	for(auto i = m; i != n; i--)
#define FOR(i, a, b) 	for (ll i = a; i <= b; i++)
#define RFOR(i, a, b) 	for (ll i = a; i >= b; i--)
#define FOREACH(a, b) 	for (auto&(a) : (b))
#define um(x, y) 		unordered_map<x, y>
#define us(x) 			unordered_set<x>
#define om(x, y)		map<x, y>
#define os(x)			set<x>
#define mod 			1000000007
#define inf 			1000000000000000001;
#define all(c) 			c.begin(),c.end()
#define rall(v) 		v.rbegin(), v.rend()
#define mp(x,y) 		make_pair(x,y)
#define mem(a,val) 		memset(a,val,sizeof(a))
#define sz(x) 			x.size()
#define eb 				emplace_back
#define f 				first
#define s 				second
#define pb 				push_back
#define pf 				pop_back
#define prec(n) 		fixed<<setprecision(n)
#define bit(n, i) 		(n & (1 << i))
#define bug(...)		__f (#__VA_ARGS__, __VA_ARGS__)
#define debug(i, j) 	cout << "{" << i << "," << j << "} "
#define min3(a, b, c) 	min(a, min(b, c))
#define max3(a, b, c) 	max(a, max(b, c))
#define maxArr(a,n) 	*max_element(a,a+n)
#define minArr(a,n) 	*min_element(a,a+n)
#define maxVec(a) 		*max_element(a.begin(), a.end())
#define minVec(a) 		*min_element(a.begin(), a.end())
#define present(c, x)	((c).find(x) != (c).end())
#define cpresent(c, x)	(find(all((c)), (x)) != (c).end())
#define print1(a)		for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)	for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

using namespace std;
using namespace std::chrono;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
template<typename T> T logAToBaseB(T a, T b) {
	return a > b - 1 ? 1 + logAToBaseB(a / b, b) : 0;
}
template<typename T> T logAToBaseBDec(T a, T b) {
	return log(a) / log(b);
}
template<typename T> T numberOfDigits(T a) {
	return (int)floor(1 + logAToBaseBDec(a, 10));
}
template<typename T> double nthRoot(T a, T b) {
	double xPre = rand() % 10;
	double eps = 1e-3;
	double delX = INT_MAX;
	double xK;
	while (delX > eps) {
		xK = ((b - 1.0) * xPre + (double)a / pow(xPre, b - 1)) / (double)b;
		delX = abs(xK - xPre);
		xPre = xK;
	}
	return xK;
}
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
/**********************************************/

inline ll lcm(ll a, ll b) {return (a * b) / __gcd(a, b);}
inline int intlcm(int a, int b) {return (a * b) / __gcd(a, b);}
inline int intpow(int a, int b) {return (int)(pow(a, b) + 0.5);}
inline ll llpow(ll a, ll b) {return (ll)(pow(a, b) + 0.5);}


template<typename T>class Node {
private:
	T data;
	Node<T>* next;
	template<typename U>friend class LinkedList;
public:
	Node() {
		this->next = NULL;
	}
};

template<typename T>class LinkedList {
private:
	Node<T>* head;
public:
	void mnreversal(int m, int n) {
		Node<T>* temp = head;
		m--;
		while(temp != NULL and --m) {
			temp = temp->next;
		}
		Node<T>* temp2 = temp->next;
		int n1 = n;
		while(temp2 != NULL and --n1) {
			temp2 = temp2->next;
		}
		Node<T>* head2 = temp2;
		temp2 = temp->next;
		while(temp2 != NULL and --n) {
			Node<T>* newHead = new Node<T>[1];
			newHead->data = temp2->data;
			newHead->next = head2;
			head2 = newHead;
			temp2 = temp2->next;
		}
		Node<T>* temp3 = head2;
		while(temp3 != NULL) {
			bug(temp3->data);
			temp3 = temp3->next;
		}
		bug(temp->data);
		temp->next = head2;

	}
	void reverse() {
		Node<T>* head2 = NULL;
		Node<T>* temp = head;
		while(temp != NULL) {
			Node<T>* newHead = new Node<T>[1];
			newHead->data = temp->data;
			
			newHead->next = head2;
			head2 = newHead;
			
			temp = temp->next;
		}
		head = head2;
		cout << "Reversed" << endl;
	}
	LinkedList() {
		this->head = NULL;
	}

	void add(T item) {
		Node<T>* node = new Node<T>[1];
		node->data = item;
		if (head == NULL) {
			head = node;
			cout << "new node added(firstnode) !" << endl;
			return;
		}
		Node<T>* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = node;
		cout << "new node added at back!" << endl;
	}

	void addFront(T item) {
		Node<T>* node = new Node<T>[1];
		node->data = item;
		if (head == NULL) {
			head = node;
			cout << "new node added(firstnode) !" << endl;
			return;
		}
		node->next = head;
		head = node;
		cout << "new node added at front !" << endl;
	}

	void add(int index, T item) {
		if (index > length() || index < 0) {
			cout << "index out of bound !" << endl;
			return;
		}
		Node<T>* node = new Node<T>[1];
		node->data = item;
		int count = 0;
		Node<T>* temp = head;
		while (temp != NULL && count < index) {
			if (count == index - 1) {
				if (temp->next != NULL) {
					node->next = temp->next;
				}
				temp->next = node;
				cout << "new node added at index " << index << " !" << endl;
				break;
			}
			count++;
			temp = temp->next;
		}

	}

	int length() {
		int len = 0;
		Node<int>* temp = head;
		while (temp != NULL) {
			len++;
			temp = temp->next;
		}
		return len;
	}

	void displayAll() {
		if (head == NULL) {
			cout << "linked list is empty" << endl;
			return;
		}
		cout << endl << "----link list items------" << endl;
		Node<T>* temp = head;
		while (temp != NULL) {
			cout << temp->data << " | ";
			temp = temp->next;
		}
		cout << endl << "--------------------------" << endl;
	}

	void remove() {
		if (head == NULL) {
			cout << "linked list is empty !" << endl;
			return;
		}
		if (head->next == NULL) {
			head = NULL;
			cout << "last item removed" << endl;
			return;
		}

		Node<T>* temp = head;
		while (temp != NULL) {
			if (temp->next->next == NULL) {
				temp->next = NULL;
				cout << "last item removed" << endl;
				break;
			}
			temp = temp->next;
		}

	}

	void remove(int index) {
		if (head == NULL) {
			cout << "linked list is empty !" << endl;
			return;
		}
		if (index >= length() || index < 0) {
			cout << "index out of bound !" << endl;
			return;
		}
		if (index == 0) {
			removeFront();
			cout << "item removed at index " << index << endl;
			return;
		}

		int count = 0;
		Node<T>* temp = head;
		while (temp != NULL) {
			if (count == index - 1) {
				temp->next = temp->next->next;
				cout << "item removed at index " << index << endl;
				break;
			}
			count++;
			temp = temp->next;
		}
	}

	void removeFront() {
		if (head == NULL) {
			cout << "linked list is empty !" << endl;
			return;
		}
		head = head->next;
		cout << "front item removed" << endl;
	}

	T get(int index) {
		if (head == NULL) {
			cout << "linked list is empty !" << endl;
			return -9999;
		}
		if (index >= length() || index < 0) {
			cout << "index out of bound !" << endl;
			return -9999;
		}
		if (index == 0) {
			return head->data;
		}
		int count = 0;
		T res;
		Node<T>* temp = head;
		while (temp != NULL) {
			if (count++ == index) {
				res = temp->data;
				break;
			}
			temp = temp->next;
		}
		return res;
	}

};


void solve() {
	LinkedList<int> a;
	for(int i = 1; i < 6; i++)
		a.add(i);
	a.displayAll();
	a.mnreversal(1, 5);
	a.displayAll();
}

int main() {
	//#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	//freopen("input.txt", "r", stdin);
	//For writing output to output.txt
	//freopen("output.txt", "w", stdout);
	//#endif //ONLINE_JUDGE
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	auto start = high_resolution_clock::now();
	int T = 1;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	// Flashy Wally, never forget the gifted improvisor
	// HiToMizu, flow and power. 12th sign can be all of the elements
	// Backed by the largest and the farthest planets, and sun is in your name
	// Remember, you are loved and your obsession is to be better, not perfect. Go get it.
	while (T--) solve();

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cerr << "Run Time : " << duration.count() << "ms";

	return 0;
}

