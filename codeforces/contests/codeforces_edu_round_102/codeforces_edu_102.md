# 1-Replacing Elements..
*Question*:
You have an array a1,a2,…,an. All ai are positive integers.

In one step you can choose three distinct indices i, j, and k (i≠j; i≠k; j≠k) and assign the sum of aj and ak to ai, i. e. make ai=aj+ak.

Can you make all ai lower or equal to d using the operation above any number of times (possibly, zero)?

Input
The first line contains a single integer t (1≤t≤2000) — the number of test cases.

The first line of each test case contains two integers n and d (3≤n≤100; 1≤d≤100) — the number of elements in the array a and the value d.

The second line contains n integers a1,a2,…,an (1≤ai≤100) — the array a.

Output
For each test case, print YES, if it's possible to make all elements ai less or equal than d using the operation above. Otherwise, print NO.

You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer).

*Sample Input*

*Output*
NO
YES
YES

Solution:
@1 Mine:
So what I did is take all inputs then do a linear scan of whether every number is less than or equal to d(look in question). Then if all elements are smaller or equal to d I simply
print "YES" otherwise I sorted the array, and calculated sum of first two numbers namely v[0] and v[1]...vector is v.
The logic:
			If there was a sum less than d it has to be the sum of smallest two numbers of the array. Otherwise none of the sum is guarenteed to be smaller.
			Time requirement maybe O(nlogn) but on smaller inputs the higher bound is fast.
Code:
	<code>
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

void solve() {
	int n, d;
	cin >> n >> d;
	std::vector<int> v;
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	bool ok = 1;
	for (int i = 0; i < n; ++i)
	{
		if(v[i] > d)
			ok = 0;
	}
	if(ok) {
		cout << "YES" << endl;
		return ;
	}
	sort(v.begin(), v.end());
	// cout << endl;
	if(v[0] + v[1] <= d)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		solve();
	}
	return 0;
}
</code>

@2 There is another code which does it in O(n) time. For this solution, just check whether the array has elements already below d in O(n) time. If yes print "YES" and return.
If not then again do a linear search again, this time searching if v[i] + v[i + 1].

# 2-String LCM
This is the one I spent rest of the time on..
*Question*:
Let's define a multiplication operation between a string a and a positive integer x: a⋅x is the string that is a result of writing x copies of a one after another. For example, "abc" ⋅ 2 = "abcabc", "a" ⋅ 5 = "aaaaa".

A string a is divisible by another string b if there exists an integer x such that b⋅x=a. For example, "abababab" is divisible by "ab", but is not divisible by "ababab" or "aa".

LCM of two strings s and t (defined as LCM(s,t)) is the shortest non-empty string that is divisible by both s and t.

You are given two strings s and t. Find LCM(s,t) or report that it does not exist. It can be shown that if LCM(s,t) exists, it is unique.

Input
The first line contains one integer q (1≤q≤2000) — the number of test cases.

Each test case consists of two lines, containing strings s and t (1≤|s|,|t|≤20). Each character in each of these strings is either 'a' or 'b'.

Output
For each test case, print LCM(s,t) if it exists; otherwise, print -1. It can be shown that if LCM(s,t) exists, it is unique.
*Sample Input*:
3
baba
ba
aa
aaa
aba
ab
*Output*:
baba
aaaaaa
-1

Solution:
@1 codeExplainer did this and I understood from his yt channel..
Link: https://www.youtube.com/watch?v=OJzWP2RgPeI

So his explanation goes something like this.
* First notice that if strings s and t have a LCM then the len(s) and len(t) must be multiple of each other.
* Elements of smaller string should match every element of longer string till smaller length terminates
* If len(s) == len(t) then 1) And s != t, then they do not have a LCM so print -1 in that bitch.
*						   2) And s == t, then print either of them since the LCM(m, m) is m and both the strings are the same.

Code:
<code>
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
// #define debug()

using namespace std;

void solve() {
	string s, t;
	cin >> s >> t;
	if(s.size() == t.size()) {
		if(s == t)
			cout << s << endl;
		else
			cout << -1 << endl;
		return ;
	}
	if(s.size() > t.size())
		swap(s, t);
	int n = s.size();
	int m = t.size();
	int lcm = (n * m) / __gcd(n, m);
	string ans = "";
	int k = 0;
	for(int i = 0; i < lcm; i++) {
		ans += (char)s[k];
		k++;
		k %= n; /* ! killer move.. It sets the count of k back to 0 if k exceeds n i.e. size of smaller string */
	}
	k = 0;
	for (int i = 0; i < lcm; ++i) {
		if(ans[i] != t[k]) {
			cout << -1 << endl;
			return ;
		}
		k++;
		k %= m; /* Once again killer move/logic */
	}
	cout << ans << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		solve();
	}
	return 0;
}
</code>

# 3-No More Inversion
*Question*:
You have a sequence a with n elements 1,2,3,…,k−1,k,k−1,k−2,…,k−(n−k) (k≤n<2k).

Let's call as inversion in a a pair of indices i<j such that a[i]>a[j].

Suppose, you have some permutation p of size k and you build a sequence b of size n in the following manner: b[i]=p[a[i]].

Your goal is to find such permutation p that the total number of inversions in b doesn't exceed the total number of inversions in a, and b is lexicographically maximum.

Small reminder: the sequence of k integers is called a permutation if it contains all integers from 1 to k exactly once.

Another small reminder: a sequence s is lexicographically smaller than another sequence t, if either s is a prefix of t, or for the first i such that si!=ti, si<ti holds (in the first position that these sequences are different, s has smaller number than t).

*Input*
The first line contains a single integer t (1≤t≤1000) — the number of test cases.

The first and only line of each test case contains two integers n and k (k≤n<2k; 1≤k≤105) — the length of the sequence a and its maximum.

It's guaranteed that the total sum of k over test cases doesn't exceed 105.

Output
For each test case, print k integers — the permutation p which maximizes b lexicographically without increasing the total number of inversions.

It can be proven that p exists and is unique.
*Sample Input*:
4
1 1
2 2
3 2
4 3
*Output*
1 
1 2 
2 1 
1 3 2 

*Note*:
Note
In the first test case, the sequence a=[1], there is only one permutation p=[1].

In the second test case, the sequence a=[1,2]. There is no inversion in a, so there is only one permutation p=[1,2] which doesn't increase the number of inversions.

In the third test case, a=[1,2,1] and has 1 inversion. If we use p=[2,1], then b=[p[a[1]],p[a[2]],p[a[3]]]=[2,1,2] and also has 1 inversion.

In the fourth test case, a=[1,2,3,2], and since p=[1,3,2] then b=[1,3,2,3]. Both a and b have 1 inversion and b is the lexicographically maximum.

Solution:
1@ I again didn't do this.. as I didn't even know where to start in problem statement.
So again this is from codeExplainer
Link: https://www.youtube.com/watch?v=6C7rypcIEN8

Code:
<code>

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

void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n + 1);
	for (int i = 1; i < k + 1; ++i) {
		a[i] = i;
	}
	int x = k - 1;
	for (int i = k + 1; i < n + 1; ++i) {
		a[i] = x--;
	}
	vi b(k + 1);
	vi ans;
	for (int i = n; i >= 1; i--) {
		if(b[a[i]] == 1)
			continue;
		else {
			ans.push_back(a[i]);
			b[a[i]] = 1;
		}
	}
	reverse(all(ans));
	for(int i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		solve();
	}
	return 0;
}

</code>

# 4-Program
*Question*:
You are given a program that consists of n instructions. Initially a single variable x is assigned to 0. Afterwards, the instructions are of two types:

increase x by 1;
decrease x by 1.
You are given m queries of the following format:

query l r — how many distinct values is x assigned to if all the instructions between the l-th one and the r-th one inclusive are ignored and the rest are executed without changing the order?
Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

Then the description of t testcases follows.

The first line of each testcase contains two integers n and m (1≤n,m≤2⋅105) — the number of instructions in the program and the number of queries.

The second line of each testcase contains a program — a string of n characters: each character is either '+' or '-' — increment and decrement instruction, respectively.

Each of the next m lines contains two integers l and r (1≤l≤r≤n) — the description of the query.

The sum of n over all testcases doesn't exceed 2⋅105. The sum of m over all testcases doesn't exceed 2⋅105.

Output
For each testcase print m integers — for each query l, r print the number of distinct values variable x is assigned to if all the instructions between the l-th one and the r-th one inclusive are ignored and the rest are executed without changing the order.
*Sample Input*:
2
8 4
-+--+--+
1 8
2 8
2 5
1 1
4 10
+-++
1 1
1 2
2 2
1 3
2 3
3 3
1 4
2 4
3 4
4 4
*Output*:
1
2
4
4
3
3
4
2
3
2
1
2
2
2
Note
The instructions that remain for each query of the first testcase are:

empty program — x was only equal to 0;
"-" — x had values 0 and −1;
"---+" — x had values 0, −1, −2, −3, −2 — there are 4 distinct values among them;
"+--+--+" — the distinct values are 1, 0, −1, −2.

Solution:
As you can tell by looking at the length of the problem, I have no idea and nobody has a clear solution and logical explanation and part of it is that 
I haven't even read the whole problem.
So I leave it to future me.. if you are better at solving problem than you were back now, fucking provide me the solution already.
I leave it to you..

# 5-Minimum Path
*Question*:
You are given a weighted undirected connected graph consisting of n vertices and m edges. It is guaranteed that there are no self-loops or multiple edges in the given graph.

Let's define the weight of the path consisting of k edges with indices e1,e2,…,ek as ∑i=1kwei−maxi=1kwei+mini=1kwei, where wi — weight of the i-th edge in the graph.

Your task is to find the minimum weight of the path from the 1-st vertex to the i-th vertex for each i (2≤i≤n).

Input
The first line contains two integers n and m (2≤n≤2⋅105; 1≤m≤2⋅105) — the number of vertices and the number of edges in the graph.

Following m lines contains three integers vi,ui,wi (1≤vi,ui≤n; 1≤wi≤109; vi≠ui) — endpoints of the i-th edge and its weight respectively.

Output
Print n−1 integers — the minimum weight of the path from 1-st vertex to the i-th vertex for each i (2≤i≤n).

*Sample Input*:
* 5 4
* 5 3 4
* 2 1 1
* 3 2 2
* 2 4 2

*Output*:
1 2 2 4 

*Sample Input*:
6 8
3 1 1
3 6 2
5 4 2
4 2 2
6 1 1
5 2 1
3 2 3
1 5 4
*Output*:
2 1 4 3 1 

*Sample Input*:
7 10
7 5 5
2 3 3
4 7 1
5 3 6
2 7 6
6 2 6
3 7 6
4 2 1
3 1 4
1 7 4
*Output*:
3 4 2 7 7 3 

Do it..

# 5-Strange Set
*Question*:
Note that the memory limit is unusual.

You are given an integer n and two sequences a1,a2,…,an and b1,b2,…,bn.

Let's call a set of integers S such that S⊆{1,2,3,…,n} strange, if, for every element i of S, the following condition is met: for every j∈[1,i−1], if aj divides ai, then j is also included in S. An empty set is always strange.

The cost of the set S is ∑i∈Sbi. You have to calculate the maximum possible cost of a strange set.

Input
The first line contains one integer n (1≤n≤3000).

The second line contains n integers a1,a2,…,an (1≤ai≤100).

The third line contains n integers b1,b2,…,bn (−105≤bi≤105).

Output
Print one integer — the maximum cost of a strange set.

*Sample Input*:
9
4 7 3 4 5 6 7 8 13
-2 3 -19 5 -6 7 -8 9 1
*Output*:
16

*Sample Input*:
2
42 42
-37 13
*Output*:
0

*Sample Input*:
2
42 42
13 -37
*Output*:
13
* Note
The strange set with the maximum cost in the first example is {1,2,4,8,9}.

The strange set with the maximum cost in the second example is empty.
Solution:
Do it

#If you can't any of the above problems...
Link to secondthread: https://www.youtube.com/watch?v=jlMIIK92zog
Link to contes: https://codeforces.com/contest/1473
Link to codeExplain: https://www.youtube.com/watch?v=z5ii3ZHPQ9U
