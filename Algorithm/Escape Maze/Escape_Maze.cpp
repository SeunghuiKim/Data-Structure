#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cstring>

#define Size 15
int arr[Size][Size];				//자동으로 0으로 초기화 됨. 또는 memset을 사용해 원하는 값으로 초기화.
int check_row[4] = { 0, 1, 0, -1 };	//방향 확인용 행 좌표. 오른쪽부터 시작해서 아래쪽,
int check_col[4] = { 1, 0, -1, 0 };	//방향 확인용 열 좌표. 왼쪽, 위쪽순서로 네 방향 체크
bool visited[Size][Size];			//방문한 위치 저장용
std::stack<int> s_row;				//행 좌표
std::stack<int> s_col;				//열 좌

void Create_Maze()	//.txt 파일을 불러와 데이터를 배열에 삽입
{
	std::string str ("maze");
	std::string temp_str;
	std::string text(".txt");

	std::cout << "1 ~ 3 사이의 파일 숫자를 입력하세요. \n";

	std::cin >> temp_str;
	str += temp_str + text;
	std::cout << str;

	std::ifstream file(str);	//파일 열기

	if (file.is_open())
	{
		std::cout << "파일을 열었습니다.\n";
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
		std::cout << "파일을 열 수 없습니다.\n";
	}
}

void Draw_Maze()		//미로 그리기
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			if (arr[i][j] == 0)
			{
				std::cout << "■";	//벽
			}
			else if (arr[i][j] == 1)
			{
				std::cout << "□";	//길
			}
			else if (arr[i][j] == 2)
			{
				std::cout << "⊙";	//지나간 길
			}
		}
		std::cout << std::endl;
	}
	std::cout << "입구(1, 0), 출구(13, 14)\n\n";
}

void Search_Exit()	//출구 찾기
{
	visited[1][0] = true;	//시작 지점은 방문한 것으로 처리
	s_row.push(1);		//스택에 입구 행 값 삽입
	s_col.push(0);		//스택에 입구 열 값 삽입

	while (!(s_row.empty()))	//스택이 빌때까지
	{
		for (int i = 0; i < s_row.size(); i++)		//스택 크기만큼 반복
		{
			if (s_row.top() == 13 && s_col.top() == 14)		//출구에 도착하면 종료
			{
				Draw_Maze();
				std::cout << "미로를 탈출 했습니다!\n";

				return;
			}

			for (int j = 0; j < 4; j++)
			{
				//스택에 저장된 현재 위치를 기준으로 사방을 체크
				int x = check_row[j] + s_row.top();
				int y = check_col[j] + s_col.top();

				//길이 있고 방문하지 않았으며, 각 배열의 행렬을 너머서 검사하지는 않도록 
				if (arr[x][y] == 1 && !visited[x][y] && x >= 0 && x < 15 && y >= 0 && y < 15)
				{
					visited[x][y] = true;	//방문한 것으로 설정.
					s_row.push(x);			//스택에 행 좌표 저장
					s_col.push(y);			//스택에 열 좌표 저장
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
