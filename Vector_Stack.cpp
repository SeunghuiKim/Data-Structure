#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &stack)
{
	for (vector<int>::size_type i = 0; i < stack.size(); i++)
	{
		cout << "������ " << i + 1 << "�� ���: " << stack[i] << endl;
	}
}

int main()
{
	vector<int> stack;

	stack.push_back(12);		// ��� ����
	stack.push_back(56);
	stack.push_back(90);

	cout << "\n";

	display(stack);
	cout << "������ ���: " << stack.back() << endl;

	stack.pop_back();			// ������ ��� ����
	cout << "������ ���: " << stack.back() << endl;
}