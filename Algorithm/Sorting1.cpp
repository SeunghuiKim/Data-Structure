#include <iostream>
using namespace std;

void display(int [], int);
void swap(int &, int &);
void selectionSort(int [], int);
void insertionSort(int [], int);
void bubbleSort(int [], int);
void merge(int [], int, int, int);
void mergeSort(int [], int, int);

int tempSorted[8];	// 정렬된 배열.

int main()
{
	int x, y;
	int n;	// 정렬할 데이터의 수(배열 내 데이터의 수).

	cout << "몇 개의 데이터를 입력하시겠습니까? ";
	cin >> n;
	int* arr = new int[n];		// 배열 동적 할당.

	cout << "총 " << n << "개의 데이터를 입력하세요." << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "\n입력한 배열의 순서" << endl;
	display(arr, n);				// 현재 배열에 저장된 데이터들을 보여줌.
	//selectionSort(arr, n);		// 테스트할 함수만 주석해제후 실행.
	//insertionSort(arr, n);
	//bubbleSort(arr, n);
	//mergeSort(arr, 0, n-1);
	cout << "\n정렬된 배열의 순서" << endl;
	display(arr, n);

	delete[] arr;		// 동적 할당한 배열의 메모리 해제.
	return 0;
}

// 배열 표시 함수
void display(int arr[], int n)	// 배열의 시작주소, 배열 내 데이터의 수.
{
	for (int i = 0; i < n; i++)
		cout << "[" << arr[i] << "]  ";
	cout << endl;
}

// 교환 함수
void swap(int &x, int &y)	// 인자로 x, y를 가져올경우 이 함수가 끝나면 x와 y는 원래 값인 4와 5로 돌아감.
{
	int t = x;
	x = y;
	y = t;
}

// 선택 정렬 함수(오름차순)
void selectionSort(int arr[], int n)	// 배열의 시작주소, 정렬할 데이터의 수(배열 내 데이터의 수).
{
	int idx;	// 정렬 대상인 데이터 중, 최솟값을 저장하고 있는 배열의 인덱스 값을 저장.
	for (int i = 0; i < n - 1; i++)	// i는 첫 원소에서 마지막 전 원소까지 증가하면서 선택된(selection) 데이터 값이 위치해야할 위치를 가리킴.
	{
		idx = i;
		for (int j = i + 1; j < n; j++)	// j는 정렬된 영역을 제외한 나머지 영역에서부터 마지막 원소까지 반복 검색후 최솟값을 갖는 배열 인덱스를 찾기위해서 사용됨.
			if (arr[j] < arr[idx])
				idx = j;
		swap(arr[i], arr[idx]);
	}
}

// 삽입 정렬 함수(오름차순)
void insertionSort(int arr[], int n)
{
	int j, newData;	// j: 정렬한 데이터 중 최대값의 위치, newData: 정렬할 새로운 데이터.
	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		newData = arr[i];
		while (j >= 0 && arr[j] > newData)
		{
			arr[j + 1] = arr[j];
			arr[j] = newData;
			j--;
		}
		// 위 81번 줄의 arr[j] = newData; 코드를 이곳으로 이동시 에러가 발생합니다.
	}
}

// 버블 정렬 함수(오름차순)
void bubbleSort(int arr[], int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}


// 합병 함수
void merge(int arr[], int start, int mid, int end)	// 합병할 리스트(arr)의 시작주소, 합병할 전체 데이터의 첫 인덱스, 합병할 전체 데이터의 마지막 인덱스, 합병할 데이터의 첫 번째 리스트의 마지막 인덱스.
{
	int i = start, j = mid + 1, k = 0;	// 0대신 start로 해도 무관.
	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
			tempSorted[k++] = arr[i++];
		else
			tempSorted[k++] = arr[j++];
	}
	if (i > mid)
		for (i = j; i <= end; i++)
			tempSorted[k++] = arr[i];
	else
		for (j = i; j <= mid; j++)
			tempSorted[k++] = arr[j];

	for (i = start, k = 0; i <= end; i++)
		arr[i] = tempSorted[k++];
}


// 합병 정렬 함수(오름차순)
void mergeSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);		// 좌측 정렬.
		mergeSort(arr, mid + 1, end);	// 우측 정렬.
		merge(arr, start, mid, end);
	}
}

// 선택 정렬, 삽입 정렬, 버블 정렬은 단순하지만 효율이 떨어짐.
// 합병 정렬은 구현이 복잡하지만 효율이 좋음.
