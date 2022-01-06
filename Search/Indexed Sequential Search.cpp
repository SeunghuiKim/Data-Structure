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

	cout << "�� ���� �����͸� �����Ͻðڽ��ϱ�? ";
	cin >> n;
	int* data = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "������ ������ �Է� : ";
		cin >> data[i];
	}

	cout << "\nŽ���� ������ : ";
	cin >> indexTable->key;

	indexedSequentialSearch(indexTable, data, n, indexTable->key);

	delete[] data;
	return 0;
}

bool indexedSequentialSearch(struct idxTable indexTable[], int data[], int n, int key)
{
	int idx = 0, end;

	// indexTable Ž��
	while (idx < INDEX_SIZE && indexTable[idx].key < key) idx++;
	if (idx == INDEX_SIZE) return false;
	else if (indexTable[idx].key == key) return true;
	else end = indexTable[idx].idx;

	// data �迭�� Ž�� ������ ���� Ž��
	idx = indexTable[idx - 1].idx;
	while (idx < end && data[idx] < key) idx++;
	if (data[idx] == key)
	{
		cout << "Ž���� �����Ͱ� �����մϴ�.";
		return true;
	}
	else
	{
		cout << "Ž���� �����Ͱ� �������� �ʽ��ϴ�.";
		return false;
	}
}