#include <iostream>
#include <math.h>
using namespace std;

void merge(int list[], int first, int mid, int end)
{
	int size = end - first + 1;
	int* tmp = (int*)malloc(sizeof(int) * size);


	int i = first;
	int j = mid + 1;
	int k = 0;

	while(i <= mid && j <= end)
	{
		if (list[i] <= list[j])
		{
			tmp[k] = list[i];
			k++;
			i++;
		}
		else
		{
			tmp[k] = list[j];
			k++;
			j++;
		}
	}

	if (i > mid)
	{
		for (int l = j; l <= end; l++)
		{
			tmp[k] = list[l];
			k++;
		}
	}

	else
	{
		for (int l = i; l <= mid; l++)
		{
			tmp[k] = list[l];
			k++;
		}
	}

	k = 0;
	for (int l = first; l <= end; l++)
	{
		list[l] = tmp[k++];
	}

	free(tmp);
}


void merge_sort(int list[], int first, int end)
{
	int mid = (first + end) / 2;
	if (first < end)
	{
		merge_sort(list, first, mid);
		merge_sort(list, mid + 1, end);
		merge(list, first, mid, end);
	}
}

int main()
{
	int size;
	cin >> size;
	int* num = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> num[i];
	}

	merge_sort(num, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		printf("%d\n", num[i]);
	}
}