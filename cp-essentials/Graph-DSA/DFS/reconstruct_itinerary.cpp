#include <bits/stdc++.h>
using namespace std;

vector<string> findItineraryBFS(vector<vector<string>> tickets) {
	unordered_map<string, vector<string>> adjList;
	vector<string> result;
	unordered_map<string, bool> visited;
	set<string> s;

	for (auto p : tickets) {
		adjList[p[0]].push_back(p[1]);
		s.insert(p[0]);
		s.insert(p[1]);
	}
	for (auto si : s) {
		sort(adjList[si].begin(), adjList[si].end());
	}

	auto bfs = [&] (string source = "JFK") {
		queue<string> q;
		q.push(source);
		visited[source] = true;


		while (!q.empty()) {
			string node = q.front(); q.pop();
			cout << node << " " << adjList[node].size() << endl;
			// if(adjList[node].size() == 0) continue;
			for (auto nbr : adjList[node]) {
				q.push(nbr);
				visited[nbr] = true;
			}
			result.push_back(node);
		}

	};
	bfs();
	return result;
}

// DFS solution
vector<string>ans;
map<string,multiset<string>>m;
void dfs(string str)
{
    while(m[str].size()>0)
    {
        auto it=m[str].begin();
        string str1=*it;
        m[str].erase(it);
        dfs(str1);
    }
    ans.push_back(str);
}
vector<string> findItineraryDFS(vector<vector<string>> tickets) {
    int n=tickets.size();
    ans.clear();
    m.clear();
    for(int i=0;i<n;i++)
    {
        string str1=tickets[i][0],str2=tickets[i][1];
        m[str1].insert(str2);
    }
    dfs("JFK");
    reverse(ans.begin(),ans.end());
    return ans;
}

// Both have O(ElogE), where e = number of edges

int main() {
	vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
	auto a = findItineraryDFS(tickets);
	for (auto i : a) {
		cout << i << " ";
	}

	return 0;
}