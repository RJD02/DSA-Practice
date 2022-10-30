/*
A taxi service has been running in the city. There are a total of 109 stops numbered from 1 to 109 at which pick up and drop is allowed from the taxi. You are given a schedule of a taxi being run by the taxi service. The schedule is in form a list of stops, S = [s1, s2, …, sN]. The taxi starts from the stop s1, then it goes to each of the stops s2, s3, …, sN one by one (i.e. it goes to each of the stops in the list from left to right) and its journey terminates at the Nth stop sN. Note that S can contain the same stop multiple times, i.e. the taxi can go to one stop multiple times. 

You are given Q queries of the form (si, sj), i.e. one passenger wants to go from the stop si to sj using this taxi and the passenger will use the taxi only if he/she can go from stop si to sj only using this taxi, i.e. the taxi must pick him/her up from stop si and drop him/her at stop sj.

Your task is to find out exactly how many of these Q passengers can use this taxi.

For example, S = [2, 4, 1, 2, 6, 3, 4, 5], Q = 2, the two queries are as follows:

	i) (2, 3): This passenger can take the taxi at stop 2 and can reach reach to stop 3 via the path 2 → 6 → 3.

	ii) (3, 1): This passenger can not use the taxi as it does not go to stop 1 after reaching stop 3.

So, only 1 passenger can use the taxi.

Input Format:
The first line is T (1 ≤ T ≤ 10^4), the number of testcases.
Then each testcase is given as follows:
First line of each testcase contains two space separated integers: N (1 ≤ N ≤ 105) and Q (1 ≤ Q ≤ 10^5).
The next line of each testcase contains N space separated integers: s1, s2, ..., sN. (1 ≤ si ≤ 10^9)
Next Q lines of each testcase contains a query on each line, a query is given as two space separated integers: si sj (si ≠ sj).

Output Format:
For each testcase output the exact number of passengers out of Q who can use the taxi in a single line. So, the output should contain T lines.
*/

#include <bits/stdc++.h>
using namespace std;

# define ll long long int
unordered_map<int, set<int>> memo;
bool canUseTaxi(ll source, ll destination, vector<ll> s) {
	// cout << (memo[source].find(destination) == memo[source].end()) << endl;
	if(memo[source].find(destination) != memo[source].end())
		return true;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == source) {
			if(i + 1 >= s.size())
				continue;
			for(int j = i + 1; j < s.size(); j++) {
				if(s[j] == destination) {
					memo[source].insert(destination);
					return true;
				}
			}
		}
	}
	return false;
}

void solve() {
	memo.clear();
	int n, q;
	cin >> n >> q;
	vector<ll> s(n);
	for(int i = 0; i < n; i++)
		cin >> s[i];
	
	int count = 0;
	for(int i = 0; i < q; i++) {
		ll source, destination;
		cin >> source >> destination;
		count += canUseTaxi(source, destination, s);
	}
	cout << count << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	while(t--) {
		solve();
	}
	return 0;
}