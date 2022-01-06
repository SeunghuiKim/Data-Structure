#include <iostream>
using namespace std;

// �Լ� ������
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
	int n;		// ����Ʈ �� �������� ����.

	cout << "�� ���� �����͸� �Է��Ͻðڽ��ϱ�? ";
	cin >> n;
	int* list = new int[n];		// �迭 ���� �Ҵ�.

	cout << "�� " << n << "���� �����͸� �Է��ϼ���." << endl;
	for (int i = 0; i < n; i++)
		cin >> list[i];

	cout << "\n�Էµ� ������: ";
	display(list, n);

	//quickSort(list, 0, n-1);		// �� ���� �Լ�.
	radixSort(list, n);		// ��� ���� �Լ�.
	cout << "\n���ĵ� ������: ";
	display(list, n);

	delete [] list;		// ���� �Ҵ�� �迭�� �޸� ����.
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

// �ǹ�(��, ������) Ž�� �Լ�
int pivotFind(int list[], int start, int end)	// �迭�� ���� �ּ�, ������ �������� ù �ε���, ������ �������� ������ �ε���
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

// ���� ���� ���(divide and conquer)�� �ٰ��� �� ���� �Լ�
void quickSort(int list[], int start, int end)	// �迭�� ���� �ּ�, ������ �������� ù �ε���, ������ �������� ������ �ε���
{
	if (start < end)
	{
		int pivotPosition = pivotFind(list, start, end);
		quickSort(list, start, pivotPosition - 1);
		quickSort(list, pivotPosition + 1, end);
	}
}
*/

// ����Ʈ���� ���� ū ���� ���ϴ� �Լ�.
int getMax(int list[], int n)		// �迭�� ���� �ּ�, �迭�� ������ ����.
{
	int max = list[0];				// �ִ��� ������ ����.
	for (int i = 1; i < n; i++)		// ����Ʈ �� �����͵��� max�� ��.
	{
		if (list[i] > max)			// ����Ʈ�� i��° �����Ͱ� max���� ũ��,
			max = list[i];			// i��° ����Ʈ�� ���� max�� ����.
	}
	return max;						// radixSort �Լ����� ��������, ������ �ִ��� ��ȯ.
}

// ���� �Լ�
void countSort(int list[], int n, int exp)		// �迭�� ���� �ּ�, �迭�� ������ ����, 
{
	int* output = new int[n];		// ���ĵ� �����͸� ������ output �迭 ���� �Ҵ�.
	int i, count[10] = { 0 };		// �ڸ����� ���� ���� �����͸� �����ϱ� ���� ����� �迭 ���� �� �ʱ�ȭ.
	//------------------------------------------------------------------------------------------------------------------------------------
	for (i = 0; i < n; i++)
		count[(list[i] / exp) % 10]++;		// list[i]�� ���� exp(�ڸ���)�� ������ ������ ���� �ؼ� ���� ���ڸ� count[]�� ����.

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];		// ���� count[i]�� output[i]�� �ִ� �� ���� ���� ��ġ�� ����.
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(list[i] / exp) % 10] - 1] = list[i];		// output �迭�� ����.
		count[(list[i] / exp) % 10]--;
	}
	//------------------------------------------------------------------------------------------------------------------------------------
	for (i = 0; i < n; i++)
		list[i] = output[i];		// ������ �Ϸ�� output �迭�� ����Ǿ� �ִ� �����͸� ����Ʈ�� ����.
	delete [] output;		// ���� �Ҵ�� �迭�� �޸� ����.
}

// ��� ���� �Լ�
void radixSort(int list[], int n)		// �迭�� ���� �ּ�, �迭�� ������ ����.
{
	int m = getMax(list, n);			// ���� m�� getMax �Լ����� ������ �迭 �� �������� �ִ�.
	for (int exp = 1; m / exp > 0; exp *= 10)		// ���� exp�� �ڸ����� ��Ÿ���� �ݺ����� �� �� ����ɶ����� �ڸ����� �����ϰ� ��. ex) 1/10/100/...
		countSort(list, n, exp);
}