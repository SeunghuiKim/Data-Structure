#include <iostream>
#include <queue>

using namespace std;

void Create_Array(int);

void Add_Edge_To_Matrix(int* [], int, int);

void Display_Matrix(int* [], int);

void Get_Adjacent_Vertex(int* [], int);

void Undirected_Graph_Matrix(int* [], int);
void Directed_Graph_Matrix(int* [], int);

void Search(int* [],int);
void Depth_First_Search(int* [], bool [], int, int);
void Breathed_First_Search(int* [], bool[], int, int);

int main()
{
	for (int n = 5; n < 8; n++)
	{
		Create_Array(n);
	}

	return 0;
}

void Create_Array(int n)
{
	//������ �׷����� ���� 2���� �迭 �Ҵ�
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
		memset(array[i], 0, sizeof(int) * n);	//�迭�� 0���� �ʱ�ȭ
	}

	if (n == 5)
	{
		cout << "\n������ �׷����� �Ѿ���� Enter�� �����ÿ�.";
		getchar();
		Undirected_Graph_Matrix(array, n);
	}
	else if (n == 6)
	{
		cout << "\n���� �׷����� �Ѿ���� Enter�� �����ÿ�.";
		getchar();
		Directed_Graph_Matrix(array, n);
	}

	for (int i = 0; i < n; i++)
	{	//2���� �迭 �޸� ����{
		delete[] array[i];
	}
	delete[] array;
}

void Search(int* array[], int n)
{
	bool* visited = new bool[n];
	memset(visited, false, sizeof(visited));

	int start = 0;	//���� ����
	int now = start;	//���� ����
	Depth_First_Search(array, visited, now, n);
	memset(visited, false, sizeof(visited));	// bool �迭 ������ ���� �ʱ�ȭ
	cout << endl;
	Breathed_First_Search(array, visited, now, n);
}

void Depth_First_Search(int* array[], bool visited[], int now, int n)
{
	int i;
	visited[now] = 1;
	cout << now << " ";

	for (i = 1; i <= n; i++)
	{
		if (array[now][i] == 1 && visited[i] == 0)
		{
			Depth_First_Search(array, visited, i, n);
		}
	}
}

void Breathed_First_Search(int* array[], bool visited[], int now, int n)
{
	queue<int> que;
	int i;

	visited[now] = 1;
	cout << now << " ";
	que.push(now);

	while (1) {
		now = que.front();	//���� ���� ���Ҹ� ���� ��ġ�� �ű�� ť���� ���� 
		que.pop();
		for (i = 1; i <= n; i++)
		{
			if (array[now][i] == 1 && visited[i] == 0)	//������ �ְ� ������ �湮�� ��������
			{
				visited[i] = 1;
				cout << i << " ";
				que.push(i);	//�������� �Ѿ ���� ������ queue�� ����
			}
		}
		if (que.empty())
		{
			break;
		}
	}
}

void Add_Edge_To_Matrix(int* array[], int x, int y)	//array X num, array Y num
{
	array[x][y] = 1;	//���� x��ǥ, y��ǥ
}

void Display_Matrix(int* array[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (n == 6)	//���� �׷����� �ݴ�� ������ ������
		{
			for (j = 0; j < n; j++)
			{
				cout << array[j][i] << " ";	//�ݴ�� ���
			}
			cout << endl;
		}
		else
		{
			for (j = 0; j < n; j++)
			{
				cout << array[i][j] << " ";
			}
			cout << endl;
		}
	}
}

void Get_Adjacent_Vertex(int* array[], int n)
{
	int i, j;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (array[i][j] > 0)
			{
				sum++;
			}
		}
		cout << i << "�� ������ ������ ������ ����: " << sum << endl;
		sum = 0;	//���� �ʱ�ȭ
	}
}

void Undirected_Graph_Matrix(int* array[], int n)
{
	Add_Edge_To_Matrix(array, 0, 1);
	Add_Edge_To_Matrix(array, 0, 2);
	Add_Edge_To_Matrix(array, 0, 3);
	Add_Edge_To_Matrix(array, 1, 0);
	Add_Edge_To_Matrix(array, 1, 2);
	Add_Edge_To_Matrix(array, 1, 4);
	Add_Edge_To_Matrix(array, 2, 0);
	Add_Edge_To_Matrix(array, 2, 1);
	Add_Edge_To_Matrix(array, 2, 3);
	Add_Edge_To_Matrix(array, 3, 0);
	Add_Edge_To_Matrix(array, 3, 2);
	Add_Edge_To_Matrix(array, 4, 1);

	Display_Matrix(array, n);
	Get_Adjacent_Vertex(array, n);
	Search(array, n);
}

void Directed_Graph_Matrix(int* array[], int n)
{
	Add_Edge_To_Matrix(array, 0, 1);
	Add_Edge_To_Matrix(array, 1, 0);
	Add_Edge_To_Matrix(array, 1, 2);
	Add_Edge_To_Matrix(array, 2, 3);
	Add_Edge_To_Matrix(array, 3, 4);
	Add_Edge_To_Matrix(array, 4, 5);
	Add_Edge_To_Matrix(array, 5, 4);

	Display_Matrix(array, n);
	Get_Adjacent_Vertex(array, n);
	Search(array, n);
}