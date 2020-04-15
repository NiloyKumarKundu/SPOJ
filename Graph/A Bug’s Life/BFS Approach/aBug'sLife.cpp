#include<bits/stdc++.h>
#define white 0
#define red 1
#define blue 2
using namespace std;
int color[2010];
bool bicoloring(unordered_map< int , vector< int > > adjacentList, int source)
{
    queue< int > q;
    q.push(source);
    color[source] = red;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v : adjacentList[u])
        {
            if(color[v]==white)
            {
                if(color[u]==red)
                    color[v]=blue;
                else
                    color[v]=red;
                q.push(v);
            }
            if(color[u]==color[v]) return false;
        }
    }
    return true;
}
int main()
{
    int tt; cin >> tt;
    int cases = 0;
    while(tt--)
    {
        int vertices, edges; cin >> vertices >> edges;
        unordered_map< int , vector< int > > adjacentList;
        for(int i=0;i<edges;i++)
        {
            int u, v; cin >> u >> v;
            adjacentList[u].push_back(v);
            adjacentList[v].push_back(u);
        }

        for(int i=1;i<=vertices;i++)
            color[i]=white;

        bool flag = true;

        for(int i=1;i<=vertices;i++)
        {
            if(color[i]==white)
            {
                if(bicoloring(adjacentList,i)) continue;
                else
                {
                    flag = false;
                    break;
                }
            }
        }

        cout << "Scenario #" << ++cases << ":\n";

        if(flag)
            cout << "No suspicious bugs found!\n";
        else
            cout << "Suspicious bugs found!\n";

    }
}
