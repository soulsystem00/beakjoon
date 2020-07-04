#include <iostream>

using namespace std;

//int main()
//{
//	int size;
//	cin >> size;
//
//	int* num = new int[size];
//
//	for (int i = 0; i < size; i++)
//	{
//		cin >> num[i];
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (num[i] < num[j])
//			{
//				swap(num[i], num[j]);
//			}
//		}
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		cout << num[i] << endl;
//	}
//
//}

int main()
{
	int size;
	cin >> size;

	int* num = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (num[i] > num[j])
			{
				swap(num[i], num[j]);
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << num[i] << endl;
	}

}