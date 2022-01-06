#include <iostream>
using namespace std;

bool binarySearch(int data[], int low, int high, int key);

int main()
{
	int low = 0;
	int high, key;

	cout << "�� ���� �����͸� �����Ͻðڽ��ϱ�? ";
	cin >> high;
	int* data = new int[high];

	for (int i = 0; i < high; i++)
	{
		cout << "������ ������ �Է� : ";
		cin >> data[i];
	}

	cout << "\nŽ���� ������ : ";
	cin >> key;

	binarySearch(data, low, high, key);

	delete[] data;
	return 0;
}

bool binarySearch(int data[], int low, int high, int key)
{
	if (low > high)
	{
		cout << "Ű ���� ã�� ���߽��ϴ�.";
		return false;
	}
	int mid = (low + high) / 2;
	if (data[mid] == key)
	{
		cout << "Ű ���� ã�ҽ��ϴ�.";
		return true;
	}
	else if (data[mid] > key)
		return binarySearch(data, low, mid - 1, key);
	else
		return binarySearch(data, mid + 1, high, key);
}