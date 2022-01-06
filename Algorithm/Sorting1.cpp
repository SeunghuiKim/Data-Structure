#include <iostream>
using namespace std;

void display(int [], int);
void swap(int &, int &);
void selectionSort(int [], int);
void insertionSort(int [], int);
void bubbleSort(int [], int);
void merge(int [], int, int, int);
void mergeSort(int [], int, int);

int tempSorted[8];	// ���ĵ� �迭.

int main()
{
	int x, y;
	int n;	// ������ �������� ��(�迭 �� �������� ��).

	cout << "�� ���� �����͸� �Է��Ͻðڽ��ϱ�? ";
	cin >> n;
	int* arr = new int[n];		// �迭 ���� �Ҵ�.

	cout << "�� " << n << "���� �����͸� �Է��ϼ���." << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "\n�Է��� �迭�� ����" << endl;
	display(arr, n);				// ���� �迭�� ����� �����͵��� ������.
	//selectionSort(arr, n);		// �׽�Ʈ�� �Լ��� �ּ������� ����.
	//insertionSort(arr, n);
	//bubbleSort(arr, n);
	//mergeSort(arr, 0, n-1);
	cout << "\n���ĵ� �迭�� ����" << endl;
	display(arr, n);

	delete[] arr;		// ���� �Ҵ��� �迭�� �޸� ����.
	return 0;
}

// �迭 ǥ�� �Լ�
void display(int arr[], int n)	// �迭�� �����ּ�, �迭 �� �������� ��.
{
	for (int i = 0; i < n; i++)
		cout << "[" << arr[i] << "]  ";
	cout << endl;
}

// ��ȯ �Լ�
void swap(int &x, int &y)	// ���ڷ� x, y�� �����ð�� �� �Լ��� ������ x�� y�� ���� ���� 4�� 5�� ���ư�.
{
	int t = x;
	x = y;
	y = t;
}

// ���� ���� �Լ�(��������)
void selectionSort(int arr[], int n)	// �迭�� �����ּ�, ������ �������� ��(�迭 �� �������� ��).
{
	int idx;	// ���� ����� ������ ��, �ּڰ��� �����ϰ� �ִ� �迭�� �ε��� ���� ����.
	for (int i = 0; i < n - 1; i++)	// i�� ù ���ҿ��� ������ �� ���ұ��� �����ϸ鼭 ���õ�(selection) ������ ���� ��ġ�ؾ��� ��ġ�� ����Ŵ.
	{
		idx = i;
		for (int j = i + 1; j < n; j++)	// j�� ���ĵ� ������ ������ ������ ������������ ������ ���ұ��� �ݺ� �˻��� �ּڰ��� ���� �迭 �ε����� ã�����ؼ� ����.
			if (arr[j] < arr[idx])
				idx = j;
		swap(arr[i], arr[idx]);
	}
}

// ���� ���� �Լ�(��������)
void insertionSort(int arr[], int n)
{
	int j, newData;	// j: ������ ������ �� �ִ밪�� ��ġ, newData: ������ ���ο� ������.
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
		// �� 81�� ���� arr[j] = newData; �ڵ带 �̰����� �̵��� ������ �߻��մϴ�.
	}
}

// ���� ���� �Լ�(��������)
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


// �պ� �Լ�
void merge(int arr[], int start, int mid, int end)	// �պ��� ����Ʈ(arr)�� �����ּ�, �պ��� ��ü �������� ù �ε���, �պ��� ��ü �������� ������ �ε���, �պ��� �������� ù ��° ����Ʈ�� ������ �ε���.
{
	int i = start, j = mid + 1, k = 0;	// 0��� start�� �ص� ����.
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


// �պ� ���� �Լ�(��������)
void mergeSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);		// ���� ����.
		mergeSort(arr, mid + 1, end);	// ���� ����.
		merge(arr, start, mid, end);
	}
}

// ���� ����, ���� ����, ���� ������ �ܼ������� ȿ���� ������.
// �պ� ������ ������ ���������� ȿ���� ����.
