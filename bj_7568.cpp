#include <iostream>

using namespace std;

typedef struct _Person
{
	int weight;
	int height;
}Person;
int main()
{
	int size;

	cin >> size;

	Person* arr = new Person[size];
	int* rank = new int[size];
	for (int i = 0; i < size; i++)
	{
		rank[i] = 1;
		cin >> arr[i].height >> arr[i].weight;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i].height < arr[j].height && arr[i].weight < arr[j].weight)
				rank[i]++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << rank[i] << " ";
	}
}