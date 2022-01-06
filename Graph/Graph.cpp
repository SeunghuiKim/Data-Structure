#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void Create_Array(int);
void Create_List(int);

void Add_Edge_To_Matrix(int* [], int, int);
void Add_Edge_To_List(list<int> [], int, int);
void Add_Weight_To_Matrix(int* [], int, int, int);

void Display_Matrix(int* [], int);
void Display_List(list<int> [], int);

void Get_Adjacent_Vertex(int* [], int);
void Get_Total_Weight(int* [], int);

void Undirected_Graph_Matrix(int* [], int);
void Directed_Graph_Matrix(int* [], int);
void Weighted_Graph_Matrix(int* [], int);

void Undirected_Graph_List(list<int> [], int);
void Directed_Graph_List(list<int>[], int);
void Weighted_Undirected_Graph_List(list<int>[], int);

int main()
{
	for (int n = 5; n < 8; n++)
	{
		Create_Array(n);
		Create_List(n);
	}

	return 0;
}

void Create_Array(int n)
{
	//무방향 그래프를 위한 2차원 배열 할당
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
		memset(array[i], 0, sizeof(int) * n);	//배열을 0으로 초기화
	}

	if (n == 5)
	{
		cout << "\n무방향 그래프로 넘어가려면 Enter를 누르시오.";
		getchar();
		Undirected_Graph_Matrix(array, n);
	}
	else if (n == 6)
	{
		cout << "\n방향 그래프로 넘어가려면 Enter를 누르시오.";
		getchar();
		Directed_Graph_Matrix(array, n);
	}
	else if (n == 7)
	{
		cout << "\n가중치 무방향 그래프로 넘어가려면 Enter를 누르시오.";
		getchar();
		Weighted_Graph_Matrix(array, n);
	}

	for (int i = 0; i < n; i++)
	{	//2차원 배열 메모리 해제{
		delete[] array[i];
	}
	delete[] array;
}

void Create_List(int n)
{
	list<int>* intList = new list<int>[n];
	if (n == 5)
	{
		Undirected_Graph_List(intList, n);
	}
	else if (n == 6)
	{
		Directed_Graph_List(intList, n);
	}
	else if (n == 7)
	{
		Weighted_Undirected_Graph_List(intList, n);
	}
	delete[] intList;
}

void Add_Edge_To_Matrix(int* array[], int x, int y)	//array X num, array Y num
{
	array[x][y] = 1;
}

void Add_Edge_To_List(list<int> intList[], int fln, int sln)	//first list num, secone list num
{
	intList[fln].push_back(sln);
}

void Add_Weight_To_Matrix(int* array[], int x, int y, int w)
{
	array[x][y] = w;
}

void Display_Matrix(int* array[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (n == 6)	//방향 그래프가 반대로 찍히기 때문에
		{
			for (j = 0; j < n; j++)
			{
				cout << array[j][i] << " ";	//반대로 출력
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

void Display_List(list<int> list[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << "--->";
		std::list<int> ::iterator iter;
		for (iter = list[i].begin(); iter != list[i].end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << endl;
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
		cout << i << "번 정점이 인접한 정점의 개수: " << sum << endl;
		sum = 0;	//개수 초기화
	}
}

void Get_Total_Weight(int* array[], int n)
{
	int i, j;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (array[i][j] > 0)
			{
				sum += array[i][j];
			}
		}
		cout << "\n" << i << "번 정점과 인접한 정점의 가중치 합계: " << sum << endl;
		sum = 0;	//개수 초기화
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
}

void Weighted_Graph_Matrix(int* array[], int n)
{
	Add_Weight_To_Matrix(array, 0, 1, 9);
	Add_Weight_To_Matrix(array, 0, 2, 7);
	Add_Weight_To_Matrix(array, 0, 5, 5);
	Add_Weight_To_Matrix(array, 0, 6, 6);
	Add_Weight_To_Matrix(array, 1, 0, 9);
	Add_Weight_To_Matrix(array, 1, 2, 9);
	Add_Weight_To_Matrix(array, 2, 0, 7);
	Add_Weight_To_Matrix(array, 2, 1, 9);
	Add_Weight_To_Matrix(array, 2, 3, 8);
	Add_Weight_To_Matrix(array, 2, 4, 2);
	Add_Weight_To_Matrix(array, 3, 2, 8);
	Add_Weight_To_Matrix(array, 3, 4, 5);
	Add_Weight_To_Matrix(array, 4, 2, 2);
	Add_Weight_To_Matrix(array, 4, 3, 5);
	Add_Weight_To_Matrix(array, 4, 5, 4);
	Add_Weight_To_Matrix(array, 5, 0, 5);
	Add_Weight_To_Matrix(array, 5, 4, 4);
	Add_Weight_To_Matrix(array, 5, 6, 1);
	Add_Weight_To_Matrix(array, 6, 0, 6);
	Add_Weight_To_Matrix(array, 6, 5, 1);

	Display_Matrix(array, n);
	Get_Adjacent_Vertex(array, n);
	Get_Total_Weight(array, n);
}

void Undirected_Graph_List(list<int> intList[], int n)
{
	Add_Edge_To_List(intList, 0, 1);
	Add_Edge_To_List(intList, 0, 2);
	Add_Edge_To_List(intList, 0, 3);
	Add_Edge_To_List(intList, 1, 0);
	Add_Edge_To_List(intList, 1, 2);
	Add_Edge_To_List(intList, 1, 4);
	Add_Edge_To_List(intList, 2, 0);
	Add_Edge_To_List(intList, 2, 1);
	Add_Edge_To_List(intList, 2, 3);
	Add_Edge_To_List(intList, 3, 0);
	Add_Edge_To_List(intList, 3, 2);
	Add_Edge_To_List(intList, 4, 1);

	Display_List(intList, n);
}

void Directed_Graph_List(list<int> intList[], int n)
{
	Add_Edge_To_List(intList, 0, 1);
	Add_Edge_To_List(intList, 1, 0);
	Add_Edge_To_List(intList, 1, 2);
	Add_Edge_To_List(intList, 2, 3);
	Add_Edge_To_List(intList, 3, 4);
	Add_Edge_To_List(intList, 4, 5);
	Add_Edge_To_List(intList, 5, 4);

	Display_List(intList, n);
}

void Weighted_Undirected_Graph_List(list<int> intList[], int n)
{
	Add_Edge_To_List(intList, 0, 1);
	Add_Edge_To_List(intList, 0, 2);
	Add_Edge_To_List(intList, 0, 5);
	Add_Edge_To_List(intList, 0, 6);
	Add_Edge_To_List(intList, 1, 0);
	Add_Edge_To_List(intList, 1, 2);
	Add_Edge_To_List(intList, 2, 0);
	Add_Edge_To_List(intList, 2, 1);
	Add_Edge_To_List(intList, 2, 3);
	Add_Edge_To_List(intList, 2, 4);
	Add_Edge_To_List(intList, 3, 2);
	Add_Edge_To_List(intList, 3, 4);
	Add_Edge_To_List(intList, 4, 2);
	Add_Edge_To_List(intList, 4, 3);
	Add_Edge_To_List(intList, 4, 5);
	Add_Edge_To_List(intList, 5, 0);
	Add_Edge_To_List(intList, 5, 4);
	Add_Edge_To_List(intList, 5, 6);
	Add_Edge_To_List(intList, 6, 0);
	Add_Edge_To_List(intList, 6, 5);

	Display_List(intList, n);
}