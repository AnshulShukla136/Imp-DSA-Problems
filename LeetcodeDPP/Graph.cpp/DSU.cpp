vector<int> parent, rank;

DSU(int n)
{
    parent.resize(n);
    rank.resize(n, 1);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

int find(int x)
{
    if (x == parent[x])
        return x;

    return parent[x] = find(parent[x]);
}

bool Union(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent)
        return false;

    if (rank[x_parent] > rank[y_parent])
    {
        parent[y_parent] = x_parent;
    }
    else if (rank[x_parent] < rank[y_parent])
    {
        parent[x_parent] = y_parent;
    }
    else
    {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }

    return true;
}
