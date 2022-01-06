#include <iostream>
using namespace std;

bool sequentialSearch(int data[], int n, int key, bool sorted);

int main()
{
	int n;
	int key;
	bool sorted;

	cout << "�� ���� �����͸� �����Ͻðڽ��ϱ�? ";
	cin >> n;
	int* data = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "������ ������ �Է� : ";
		cin >> data[i];
	}

	cout << "\nŽ���� ������ : ";
	cin >> key;

	cout << "\n������ ���� ����(true = 1 / false = 0) : ";
	cin >> sorted;

	if (sequentialSearch(data, n, key, sorted) == true)
		cout << "Ž���� ���� �����մϴ�.";
	else cout << "Ž���� ���� �������� �ʽ��ϴ�.";

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