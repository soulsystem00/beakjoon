#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

bool check(int i);
int getlength(int num);

int main()
{
	int num;
	int cnt = 0;
	cin >> num;

	for (int i = 0; i < 2147483642; i++)
	{
		if (check(i))
			cnt++;

		if (cnt == num)
		{
			cout << i;
			return 0;
		}

	}
}

bool check(int num)
{
	int length = getlength(num);
	char *str = (char*)malloc(length);
	sprintf(str, "%d", num);

	for (int i = 0; i < sizeof(str) - 2; i++)
	{
		if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6')
		{
			free(str);
			return true;
		}
			
	}
	free(str);
	return false;
}

int getlength(int num)
{
	int temp = 10;
	int length = 1;

	while (num / temp != 0)
	{
		length++;
		temp = temp * 10;
	}

	return length;
}