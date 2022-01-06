#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &stack)
{
	for (vector<int>::size_type i = 0; i < stack.size(); i++)
	{
		cout << "스택의 " << i + 1 << "번 요소: " << stack[i] << endl;
	}
}

int main()
{
	vector<int> stack;

	stack.push_back(12);		// 요소 삽입
	stack.push_back(56);
	stack.push_back(90);

	cout << "\n";

	display(stack);
	cout << "마지막 요소: " << stack.back() << endl;

	stack.pop_back();			// 마지막 요소 삭제
	cout << "마지막 요소: " << stack.back() << endl;
}