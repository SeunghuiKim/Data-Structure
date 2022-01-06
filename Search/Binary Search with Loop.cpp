#include <iostream>
using namespace std;

bool binarySearch(int data[], int n, int key);

int main()
{
	int n;
	int key;

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

	binarySearch(data, n, key);

	delete[] data;
	return 0;
}

bool binarySearch(int data[], int n, int key)
{
	int mid, start = 0, end = n;

	while (end - start >= 0)
	{
		mid = (start + end) / 2;
		if (data[mid] == key)		// Ű ���� ã���� ��
		{
			cout << "Ű ���� ã�ҽ��ϴ�.";
			return true;
		}
		else if (data[mid] > key)	// Ű ���� mid ������ ���� ��
			end -= 1;				// ������ �˻��ϵ��� end �� ����
		else						// Ű ���� mid �� ���� Ŭ ��
			start += 1;				// �������� �˻��ϵ��� start �� ����
	}

	cout << "Ű ���� ã�� ���Ͽ����ϴ�.";
	return false;
}