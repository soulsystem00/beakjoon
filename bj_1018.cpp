#include <iostream>

using namespace std;
int check(int start_y, int start_x,char **arr)
{
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = start_y; i < start_y + 8; i++)
	{
		for (int j = start_x; j < start_x + 8; j++)
		{
			if ((i + j) % 2 == 0 && arr[i][j] != 'W')
				cnt1++;
			else if ((i + j) % 2 == 1 && arr[i][j] != 'B')
				cnt1++;
		}
	}

	for (int i = start_y; i < start_y + 8; i++)
	{
		for (int j = start_x; j < start_x + 8; j++)
		{
			if ((i + j) % 2 == 0 && arr[i][j] != 'B')
				cnt2++;
			else if ((i + j) % 2 == 1 && arr[i][j] != 'W')
				cnt2++;
		}
	}

	if (cnt1 < cnt2)
		return cnt1;
	else
		return cnt2;
}
int main()
{
	int width, height;
	int MIN = 999999;
	cin >> height >> width;

	char** arr = new char* [height];
	for (int i = 0; i < height; i++)
	{
		arr[i] = new char[width];
	}

	for (int i = 0; i < height; i++)
	{
		cin >> arr[i];
	}
	/*for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			arr[i][j] = i + j;
		}
	}*/
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (!(i + 8 > height || j + 8 > width))
			{
				int tmp = check(i, j, arr);
				if (tmp < MIN)
					MIN = tmp;
			}
		}
	}

	cout << MIN;
}