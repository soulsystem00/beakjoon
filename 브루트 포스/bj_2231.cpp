#include <iostream>
#include <math.h>
using namespace std;

//int main()
//{
//	string a;
//	cin >> a;
//
//	int sum = atoi(a.c_str());
//
//	for (int i = 0; i < a.length(); i++)
//	{
//		sum += a[i] - '0';
//	}
//
//	cout << sum;
//}
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
int main()
{
	int input;
	int sum;
	cin >> input;
	for (int k = 1; k < input; k++)
	{
		int num = k;
		sum = num;
		int length = getlength(num);

		int* arr = (int*)malloc(sizeof(int) * length);
		arr[0] = num / pow(10, length - 1);
		for (int i = 1; i < length; i++)
		{
			arr[i] = num / pow(10, length - i - 1);
		}

		for (int i = length - 1; i > 0; i--)
		{
			arr[i] = arr[i] - arr[i - 1] * 10;
		}

		for (int i = 0; i < length; i++)
		{
			sum += arr[i];
		}
		if (sum == input)
		{
			cout << k;
			return 0;
		}
	}
	cout << 0;
}