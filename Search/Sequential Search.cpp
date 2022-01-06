#include <iostream>
using namespace std;

bool sequentialSearch(int data[], int n, int key, bool sorted);

int main()
{
	int n;
	int key;
	bool sorted;

	cout << "몇 개의 데이터를 저장하시겠습니까? ";
	cin >> n;
	int* data = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "저장할 데이터 입력 : ";
		cin >> data[i];
	}

	cout << "\n탐색할 데이터 : ";
	cin >> key;

	cout << "\n데이터 정렬 여부(true = 1 / false = 0) : ";
	cin >> sorted;

	if (sequentialSearch(data, n, key, sorted) == true)
		cout << "탐색한 값이 존재합니다.";
	else cout << "탐색한 값이 존재하지 않습니다.";

	delete[] data;
	return 0;
}

bool sequentialSearch(int data[], int n, int key, bool sorted)
{
	int idx = 0;

	if (sorted == false)
	{
		while (idx < n && data[idx] != key) idx++;
		if (idx != n) return true;
		else return false;
	}
	else
	{
		while (idx < n && data[idx] < key) idx++;
		if (data[idx] == key) return true;
		else return false;
	}
}