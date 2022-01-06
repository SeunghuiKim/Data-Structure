#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> iPair;

struct Graph
{
    int V, E;   //정점, 간선

    vector<pair<int, iPair>> edge;

    Graph(int V, int E) //생성자
    {
        this->V = V;
        this->E = E;
    }

    void Add_Edge(int u, int v, int w)   //간선 추가
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

    Disjoint_Set(int n) //생성자
    {
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];

        for (int i = 0; i <= n; i++)    
        {
            rank[i] = 0;
            parent[i] = i;  //자신이 자신의 부모로
        }
    }

    int Find(int p) //노드 p의 부모를 찾고 경로에서 노드의 부모를 변경(p--> parent[p]를 parent[p])
    {
        if (p != parent[p])
        {
            parent[p] = Find(parent[p]);
        }
        return parent[p];
    }

    void Merge(int x, int y)    //랭크에 따라 결합하고 높이가 낮은 트리를 다른 트리의 서브트리로
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

int Graph::Kruskal_MST()    //크루스칼의 최소신장비용트리(kruskal's Minimum Spanning Tree)
{
    int mst_wt = 0; //결과 초기화

    sort(edge.begin(), edge.end()); //비용에 따라 간선 정렬

    Disjoint_Set ds(V);

    vector< pair<int, iPair> >::iterator iter;

    for (iter = edge.begin(); iter != edge.end(); iter++)
    {
        int p = iter->second.first;
        int v = iter->second.second;
        int set_p = ds.Find(p);
        int set_v = ds.Find(v);

        if (set_p != set_v) //p와 v가 같은 set에 들어가면 사이클이 생기니 선택된 간선이 사이클을 생성하는지 않하는지 확인
        {
            cout << p << " - " << v << endl;    //현재 간선을 표시
            mst_wt += iter->first;
            ds.Merge(set_p, set_v);
        }
    }
    return mst_wt;
}

int main()
{
    int V = 7, E = 12;  //정점수, 간선수
    Graph udwg(V, E);  //무방향 가중치 그래프(Undirected weighted graph

    //간선 추가.. 자동으로 못넣나?
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

    cout << "최소신장트리의 간선들은 아래와 같습니다.\n";
    int mst_wt = udwg.Kruskal_MST();
    cout << "\n최소신장트리의 가중치 합은 " << mst_wt << "입니다.\n";

    return 0;
}