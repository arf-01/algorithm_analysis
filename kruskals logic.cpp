#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from;
    int to;
    int weight;
};

void make_node(int v, int parent[], int rnk[]) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_root(int v, int parent[]) {
    if (parent[v] == v)
        return v;

    int root = find_root(parent[v], parent);
    parent[v] = root;
    return root;
}

void union_sets(int a, int b, int parent[], int rnk[]) {
    a = find_root(a, parent);
    b = find_root(b, parent);

    if (a != b) {
        if (rnk[a] < rnk[b]) {
            parent[a] = b;
        } else if (rnk[b] < rnk[a]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rnk[a]++;
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<edge> edges;
    vector<edge> mst;
    int parent[v];
    int rnk[v] = {0};

    edge x;
    for (int i = 0; i < e; i++) {
        cin >> x.from >> x.to >> x.weight;
        edges.push_back(x);
    }

    sort(edges.begin(), edges.end(), [](edge &a, edge &b) {
        return a.weight < b.weight;
    });

    for (int i = 0; i < v; i++) {
        make_node(i, parent, rnk);
    }

    for (int i = 0; i < e; i++) {
        if (find_root(edges[i].from, parent) == find_root(edges[i].to, parent)) {
            continue;
        } else {
            mst.push_back(edges[i]);
            union_sets(edges[i].from, edges[i].to, parent, rnk);
        }
    }

    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].from << " " << mst[i].to << " " << mst[i].weight << endl;
    }

    return 0;
}
