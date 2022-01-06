#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> iPair;

struct Graph
{
    int V, E;   //����, ����

    vector<pair<int, iPair>> edge;

    Graph(int V, int E) //������
    {
        this->V = V;
        this->E = E;
    }

    void Add_Edge(int u, int v, int w)   //���� �߰�
    {
        edge.push_back({ w, {u, v} });
    }
    int Kruskal_MST();
};

struct Disjoint_Set
{
    int* parent;  
    int* rank;
    int n;

    Disjoint_Set(int n) //������
    {
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];

        for (int i = 0; i <= n; i++)    
        {
            rank[i] = 0;
            parent[i] = i;  //�ڽ��� �ڽ��� �θ��
        }
    }

    int Find(int p) //��� p�� �θ� ã�� ��ο��� ����� �θ� ����(p--> parent[p]�� parent[p])
    {
        if (p != parent[p])
        {
            parent[p] = Find(parent[p]);
        }
        return parent[p];
    }

    void Merge(int x, int y)    //��ũ�� ���� �����ϰ� ���̰� ���� Ʈ���� �ٸ� Ʈ���� ����Ʈ����
    {
        x = Find(x), y = Find(y);

        if (rank[x] > rank[y])
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
        }

        if (rank[x] == rank[y])
        {
            rank[y]++;
        }
    }
};

int Graph::Kruskal_MST()    //ũ�罺Į�� �ּҽ�����Ʈ��(kruskal's Minimum Spanning Tree)
{
    int mst_wt = 0; //��� �ʱ�ȭ

    sort(edge.begin(), edge.end()); //��뿡 ���� ���� ����

    Disjoint_Set ds(V);

    vector< pair<int, iPair> >::iterator iter;

    for (iter = edge.begin(); iter != edge.end(); iter++)
    {
        int p = iter->second.first;
        int v = iter->second.second;
        int set_p = ds.Find(p);
        int set_v = ds.Find(v);

        if (set_p != set_v) //p�� v�� ���� set�� ���� ����Ŭ�� ����� ���õ� ������ ����Ŭ�� �����ϴ��� ���ϴ��� Ȯ��
        {
            cout << p << " - " << v << endl;    //���� ������ ǥ��
            mst_wt += iter->first;
            ds.Merge(set_p, set_v);
        }
    }
    return mst_wt;
}

int main()
{
    int V = 7, E = 12;  //������, ������
    Graph udwg(V, E);  //������ ����ġ �׷���(Undirected weighted graph

    //���� �߰�.. �ڵ����� ���ֳ�?
    udwg.Add_Edge(0, 1, 9);
    udwg.Add_Edge(0, 2, 7);
    udwg.Add_Edge(0, 5, 5);
    udwg.Add_Edge(0, 6, 6);
    udwg.Add_Edge(1, 0, 9);
    udwg.Add_Edge(1, 2, 9);
    udwg.Add_Edge(2, 0, 7);
    udwg.Add_Edge(2, 1, 9);
    udwg.Add_Edge(2, 3, 8);
    udwg.Add_Edge(2, 4, 2);
    udwg.Add_Edge(3, 2, 8);
    udwg.Add_Edge(3, 4, 5);
    udwg.Add_Edge(4, 2, 2);
    udwg.Add_Edge(4, 3, 5);
    udwg.Add_Edge(4, 5, 4);
    udwg.Add_Edge(5, 0, 5);
    udwg.Add_Edge(5, 4, 4);
    udwg.Add_Edge(5, 6, 1);
    udwg.Add_Edge(6, 0, 6);
    udwg.Add_Edge(6, 5, 1);

    cout << "�ּҽ���Ʈ���� �������� �Ʒ��� �����ϴ�.\n";
    int mst_wt = udwg.Kruskal_MST();
    cout << "\n�ּҽ���Ʈ���� ����ġ ���� " << mst_wt << "�Դϴ�.\n";

    return 0;
}