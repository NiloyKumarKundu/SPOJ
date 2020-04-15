#include <bits/stdc++.h>
#define max 10000 + 5
#define mod 10000 + 5
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
int visited[max];

void dfs(int n) {
    visited[n] = 1;
    for(int i : graph[n]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {

    int n, m, a, b;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int cc_count = 0;

    for(int i = 1; i <=n; i++) {
        if(visited[i] == 0)  {
            dfs(i);
            cc_count++;
        }
    }

    if(cc_count == 1 && m == n - 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }


    return 0;
}
