#include <iostream>
using namespace std;

// 함수 원형들
void display(int [], int);
/*
void swap(int &, int &);
int pivotFind(int [], int, int);
void quickSort(int [], int, int);
*/
int getMax(int [], int);
void radixSort(int [], int);

int main()
{
	int n;		// 리스트 내 데이터의 갯수.

	cout << "몇 개의 데이터를 입력하시겠습니까? ";
	cin >> n;
	int* list = new int[n];		// 배열 동적 할당.

	cout << "총 " << n << "개의 데이터를 입력하세요." << endl;
	for (int i = 0; i < n; i++)
		cin >> list[i];

	cout << "\n입력된 데이터: ";
	display(list, n);

	//quickSort(list, 0, n-1);		// 퀵 정렬 함수.
	radixSort(list, n);		// 기수 정렬 함수.
	cout << "\n정렬된 데이터: ";
	display(list, n);

	delete [] list;		// 동적 할당된 배열의 메모리 해제.
	return 0;
}

void display(int list[], int n)
{
	for (int i = 0; i < n; i++)
		cout << "[" << list[i] << "]  ";
}

/*
void swap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}

// 피벗(축, 기준점) 탐색 함수
int pivotFind(int list[], int start, int end)	// 배열의 시작 주소, 정렬할 데이터의 첫 인덱스, 정렬할 데이터의 마지막 인덱스
{
	int pivot = list[start], low = start + 1, high = end;
	do
	{
		while (low <= high && list[low] < pivot)
			low++;
		while (low <= high && list[high] > pivot)
			high--;
		if (low < high)
			swap(list[low], list[high]);
	} while (low < high);

	swap(list[start], list[high]);
	return high;
}

// 분할 정복 방법(divide and conquer)에 근거한 퀵 정렬 함수
void quickSort(int list[], int start, int end)	// 배열의 시작 주소, 정렬할 데이터의 첫 인덱스, 정렬할 데이터의 마지막 인덱스
{
	if (start < end)
	{
		int pivotPosition = pivotFind(list, start, end);
		quickSort(list, start, pivotPosition - 1);
		quickSort(list, pivotPosition + 1, end);
	}
}
*/

// 리스트에서 가장 큰 수를 구하는 함수.
int getMax(int list[], int n)		// 배열의 시작 주소, 배열의 데이터 갯수.
{
	int max = list[0];				// 최댓값을 저장할 변수.
	for (int i = 1; i < n; i++)		// 리스트 내 데이터들을 max와 비교.
	{
		if (list[i] > max)			// 리스트의 i번째 데이터가 max보다 크면,
			max = list[i];			// i번째 리스트의 값을 max에 저장.
	}
	return max;						// radixSort 함수에서 쓰기위해, 구해진 최댓값을 반환.
}

// 정렬 함수
void countSort(int list[], int n, int exp)		// 배열의 시작 주소, 배열의 데이터 갯수, 
{
	int* output = new int[n];		// 정렬된 데이터를 저장할 output 배열 동적 할당.
	int i, count[10] = { 0 };		// 자릿수의 수에 따라 데이터를 정렬하기 위해 사용할 배열 선언 및 초기화.
	//------------------------------------------------------------------------------------------------------------------------------------
	for (i = 0; i < n; i++)
		count[(list[i] / exp) % 10]++;		// list[i]의 값을 exp(자릿수)로 나누고 나머지 셈을 해서 나온 숫자를 count[]에 저장.

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];		// 이제 count[i]가 output[i]에 있는 이 값의 실제 위치를 포함.
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(list[i] / exp) % 10] - 1] = list[i];		// output 배열을 제작.
		count[(list[i] / exp) % 10]--;
	}
	//------------------------------------------------------------------------------------------------------------------------------------
	for (i = 0; i < n; i++)
		list[i] = output[i];		// 정렬이 완료된 output 배열에 저장되어 있는 데이터를 리스트에 저장.
	delete [] output;		// 동적 할당된 배열의 메모리 해제.
}

// 기수 정렬 함수
void radixSort(int list[], int n)		// 배열의 시작 주소, 배열의 데이터 갯수.
{
	int m = getMax(list, n);			// 변수 m은 getMax 함수에서 구해진 배열 내 데이터의 최댓값.
	for (int exp = 1; m / exp > 0; exp *= 10)		// 변수 exp는 자릿수를 나타내고 반복문이 한 번 실행될때마다 자릿수가 증가하게 됨. ex) 1/10/100/...
		countSort(list, n, exp);
}