#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cstring>

#define Size 15
int arr[Size][Size];				//�ڵ����� 0���� �ʱ�ȭ ��. �Ǵ� memset�� ����� ���ϴ� ������ �ʱ�ȭ.
int check_row[4] = { 0, 1, 0, -1 };	//���� Ȯ�ο� �� ��ǥ. �����ʺ��� �����ؼ� �Ʒ���,
int check_col[4] = { 1, 0, -1, 0 };	//���� Ȯ�ο� �� ��ǥ. ����, ���ʼ����� �� ���� üũ
bool visited[Size][Size];			//�湮�� ��ġ �����
std::stack<int> s_row;				//�� ��ǥ
std::stack<int> s_col;				//�� ��

void Create_Maze()	//.txt ������ �ҷ��� �����͸� �迭�� ����
{
	std::string str ("maze");
	std::string temp_str;
	std::string text(".txt");

	std::cout << "1 ~ 3 ������ ���� ���ڸ� �Է��ϼ���. \n";

	std::cin >> temp_str;
	str += temp_str + text;
	std::cout << str;

	std::ifstream file(str);	//���� ����

	if (file.is_open())
	{
		std::cout << "������ �������ϴ�.\n";
		while (!file.eof())
		{
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					std::getline(file, str, ' ');
					arr[i][j] = stoi(str);
				}
				std::getline(file, temp_str, '\n');
			}
		}
		file.close();
	}
	else
	{
		std::cout << "������ �� �� �����ϴ�.\n";
	}
}

void Draw_Maze()		//�̷� �׸���
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			if (arr[i][j] == 0)
			{
				std::cout << "��";	//��
			}
			else if (arr[i][j] == 1)
			{
				std::cout << "��";	//��
			}
			else if (arr[i][j] == 2)
			{
				std::cout << "��";	//������ ��
			}
		}
		std::cout << std::endl;
	}
	std::cout << "�Ա�(1, 0), �ⱸ(13, 14)\n\n";
}

void Search_Exit()	//�ⱸ ã��
{
	visited[1][0] = true;	//���� ������ �湮�� ������ ó��
	s_row.push(1);		//���ÿ� �Ա� �� �� ����
	s_col.push(0);		//���ÿ� �Ա� �� �� ����

	while (!(s_row.empty()))	//������ ��������
	{
		for (int i = 0; i < s_row.size(); i++)		//���� ũ�⸸ŭ �ݺ�
		{
			if (s_row.top() == 13 && s_col.top() == 14)		//�ⱸ�� �����ϸ� ����
			{
				Draw_Maze();
				std::cout << "�̷θ� Ż�� �߽��ϴ�!\n";

				return;
			}

			for (int j = 0; j < 4; j++)
			{
				//���ÿ� ����� ���� ��ġ�� �������� ����� üũ
				int x = check_row[j] + s_row.top();
				int y = check_col[j] + s_col.top();

				//���� �ְ� �湮���� �ʾ�����, �� �迭�� ����� �ʸӼ� �˻������� �ʵ��� 
				if (arr[x][y] == 1 && !visited[x][y] && x >= 0 && x < 15 && y >= 0 && y < 15)
				{
					visited[x][y] = true;	//�湮�� ������ ����.
					s_row.push(x);			//���ÿ� �� ��ǥ ����
					s_col.push(y);			//���ÿ� �� ��ǥ ����
					arr[x][y] = 2;
				}
			}
		}
		s_row.pop();
		s_col.pop();
	}
}

int main()
{
	Create_Maze();
	Draw_Maze();
	Search_Exit();

	return 0;
}