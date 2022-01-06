#include <iostream>
using namespace std;

bool binarySearch(int data[], int low, int high, int key);

int main()
{
	int low = 0;
	int high, key;

	cout << "몇 개의 데이터를 저장하시겠습니까? ";
	cin >> high;
	int* data = new int[high];

	for (int i = 0; i < high; i++)
	{
		cout << "저장할 데이터 입력 : ";
		cin >> data[i];
	}

	cout << "\n탐색할 데이터 : ";
	cin >> key;

	binarySearch(data, low, high, key);

	delete[] data;
	return 0;
}

bool binarySearch(int data[], int low, int high, int key)
{
	if (low > high)
	{
		cout << "키 값을 찾지 못했습니다.";
		return false;
	}
	int mid = (low + high) / 2;
	if (data[mid] == key)
	{
		cout << "키 값을 찾았습니다.";
		return true;
	}
	else if (data[mid] > key)
		return binarySearch(data, low, mid - 1, key);
	else
		return binarySearch(data, mid + 1, high, key);
}