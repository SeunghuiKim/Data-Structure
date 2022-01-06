#include <iostream>
using namespace std;

bool binarySearch(int data[], int n, int key);

int main()
{
	int n;
	int key;

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
		if (data[mid] == key)		// 키 값을 찾았을 때
		{
			cout << "키 값을 찾았습니다.";
			return true;
		}
		else if (data[mid] > key)	// 키 값이 mid 값보다 작을 때
			end -= 1;				// 왼쪽을 검색하도록 end 값 변경
		else						// 키 값이 mid 값 보다 클 때
			start += 1;				// 오른쪽을 검색하도록 start 값 변경
	}

	cout << "키 값을 찾지 못하였습니다.";
	return false;
}