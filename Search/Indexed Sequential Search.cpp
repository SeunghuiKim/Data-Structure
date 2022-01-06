#include <iostream>
#define INDEX_SIZE 4

bool indexedSequentialSearch(struct idxTable indexTable[], int data[], int n, int key);
using namespace std;

struct idxTable
{
	int idx;
	int key;
};

int main()
{
	struct idxTable indexTable[INDEX_SIZE];
	int n;

	cout << "몇 개의 데이터를 저장하시겠습니까? ";
	cin >> n;
	int* data = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "저장할 데이터 입력 : ";
		cin >> data[i];
	}

	cout << "\n탐색할 데이터 : ";
	cin >> indexTable->key;

	indexedSequentialSearch(indexTable, data, n, indexTable->key);

	delete[] data;
	return 0;
}

bool indexedSequentialSearch(struct idxTable indexTable[], int data[], int n, int key)
{
	int idx = 0, end;

	// indexTable 탐색
	while (idx < INDEX_SIZE && indexTable[idx].key < key) idx++;
	if (idx == INDEX_SIZE) return false;
	else if (indexTable[idx].key == key) return true;
	else end = indexTable[idx].idx;

	// data 배열의 탐색 영역내 순차 탐색
	idx = indexTable[idx - 1].idx;
	while (idx < end && data[idx] < key) idx++;
	if (data[idx] == key)
	{
		cout << "탐색한 데이터가 존재합니다.";
		return true;
	}
	else
	{
		cout << "탐색한 데이터가 존재하지 않습니다.";
		return false;
	}
}