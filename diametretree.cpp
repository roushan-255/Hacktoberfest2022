#include<bits/stdc++.h>
using namespace std;
const int N =100000;
vector<int>g[N];
vector<int> depth(N);
void dfs(int vertex,int par=-1)
{
    for(auto child:g[vertex])
    {
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    int max_depth=-1;
    int max_node;
    for (int i = 1; i <=n; i++)
    {
        if(max_depth<depth[i])
        {
            max_depth=depth[i];
            max_node=i;
            depth[i]=0;
        }
    }
    dfs(max_node);
    max_depth=-1;
    for (int i = 1; i <=n; i++)
    {
        if(max_depth<depth[i])
        max_depth=depth[i];
    }
    cout<<max_depth<<endl;
    return  0;
}
