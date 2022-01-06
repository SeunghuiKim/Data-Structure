#include <iostream>
#include <algorithm>
using namespace std;

// Ctrl + K + C = 일괄 주석 처리, Ctrl + K + U = 일괄 주석 해제

// 정수형
int main(int argc, char const *argv[])
{
	int key, data[10] = { 1, 3, 5, 7 , 9, 11, 13 };

	cin >> key;
	if (binary_search(data, data + 7, key) == true)
		cout << key << "가 데이터에 있음" << endl;
	else
		cout << key << "가 데이터에 없음" << endl;
	return 0;
}

// 실수형
//int main(float argc, float const* argv[])
//{
//	float key, data[10] = { 0.5, 1.3, 2.5, 3.7, 4.1, 5.2, 6.8 };
//
//	cin >> key;
//	if (binary_search(data, data + 7, key) == true)
//		cout << key << "가 데이터에 있음" << endl;
//	else
//		cout << key << "가 데이터에 없음" << endl;
//	return 0;
//}

// 문자형
//int main(char argc, char const* argv[])
//{
//	char key, data[10] = { 'A', 'B', 'C' ,'D', 'E', 'F' };
//
//	cin >> key;
//	if (binary_search(data, data + 7, key) == true)
//		cout << key << "가 데이터에 있음" << endl;
//	else
//		cout << key << "가 데이터에 없음" << endl;
//	return 0;
//}