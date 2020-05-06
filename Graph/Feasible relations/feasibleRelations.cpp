#include <bits/stdc++.h>
#define max 10000000 + 5
#define mod 10000000 + 5
#define pb push_back
#define pairs pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pairs>
#define lb lower_bound
#define ub upper_bound
#define lli long long int
#define endl '\n'
using namespace std;

vi graph[max];
bool visited[max];
int cc[max];
int cur_cc;

void dfs(int node) {
    visited[node] = true;
    cc[node] = cur_cc;
    for(int child : graph[node]) {
        dfs(child);
    }
}

int main() {
#ifndef Niloy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, n, k, a, b;
    cin >> t;
    string op;
    while(t--) {
        cin >> n >> k;
        cur_cc = 0;

        vii edgeList;
        for(int i = 1; i <= n; i++) {
            graph[i].clear();
            visited[i] = false;
        }

        for(int i = 1; i <= k; i++) {
            cin >> a >> op >> b;
            if(op == "=") {
                graph[a].pb(b);
                graph[b].pb(a);
            } else {
                edgeList.pb({a, b});
            }
        }

        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                cur_cc++;
                dfs(i);
            }
        }

        bool flag = true;

        for(int i = 0; i < edgeList.size(); i++) {
            a = edgeList[i].first;
            b = edgeList[i].second;

            if(cc[a] == cc[b]) {
                flag = false;
                break;
            }
        }

        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
