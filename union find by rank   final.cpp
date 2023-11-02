#include <bits/stdc++.h>
using namespace std;

// make_node , find_root,  union_sets

void make_node(int v)
{

    parent[v]=v;
}

int find_root(int v) {
    if (parent[v] == v)
        return v;

    int root = find_root(parent[v]);
    parent[v] = root;
    return root;
}


void union_sets(int a,int b)
{
      a=find_root(a);
      b=find_root(b);

      if(a!=b)
      {
          if(rank[a]<rank[b])
          {
              parent[a]=b;
          }

          else if(rank[b]<rank[a])
          {
              parent[b]=a;
          }

          else
          {
              parent[b]=a;
              rank[b]++;
          }
      }

}
