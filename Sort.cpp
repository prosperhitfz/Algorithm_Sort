#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void MergeSort(int *a, int p, int q, int r)
{
	//const int len = 8;
	//int b[len] = { 0 };
	int* b;
	b = (int *)malloc(sizeof(int)*r);
	memset(b, -1, sizeof(b));
	int s = p;
	int t = q + 1;
	int k = p;
	int res = 0;
	while (s <= q && t <= r)
	{
		if (a[s] <= a[t])
		{
			b[k] = a[s];
			s++;
		}
		else
		{
			b[k] = a[t];
			t++;
		}
		k++;
	}
	if (s == q + 1)
	{
		while (k != r+1)
		{
			b[k] = a[t];
			k++;
			t++;
		}
	}
	else
	{
		while (k != r+1)
		{
			b[k] = a[s];
			k++;
			s++;
		}
	}
	printf("MergeSort:");
	while (res != r + 1)
	{
		printf("%d ", b[res]);
		res++;
	}
}

void SelectSort(int* a, int length)
{
	int i, j, tmp, index;
	int k = 0;
	for (i = 0; i < length - 1; i++)
	{
		tmp = a[i];
		index = i;
		for (j = i + 1; j < length; j++)
		{
			if (a[j] < tmp)
			{
				tmp = a[j];
				index = j;
			}
		}
		if (index != i)
		{
			a[index] = a[i];
			a[i] = tmp;
		}
	}
	printf("SelectSort:");
	while (k != length)
	{
		printf("%d ", a[k]);
		k++;
	}
}

void InsertSort(int* a, int length)
{
	int i, j, tmp;
	int k = 0;
	for (i = 1; i < length; i++)
	{
		tmp = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (tmp < a[j])
			{
				a[j + 1] = a[j];
			}
			else break;
		}
		a[j + 1] = tmp;
	}
	printf("InsertSort:");
	while (k != length)
	{
		printf("%d ", a[k]);
		k++;
	}
}

void MergeSort1(int* a, int p, int q, int r)
{
	//const int len = 8;
	//int b[len] = { 0 };
	int* b;
	b = (int*)malloc(sizeof(int) * r);
	memset(b, -1, sizeof(b));
	int s = p;
	int t = q + 1;
	int k = p;
	int res = 0;
	while (s <= q && t <= r)
	{
		if (a[s] <= a[t])
		{
			b[k] = a[s];
			s++;
		}
		else
		{
			b[k] = a[t];
			t++;
		}
		k++;
	}
	if (s == q + 1)
	{
		while (k != r + 1)
		{
			b[k] = a[t];
			k++;
			t++;
		}
	}
	else
	{
		while (k != r + 1)
		{
			b[k] = a[s];
			k++;
			s++;
		}
	}
}

void BottomUpMerge(int* a, int length)
{
	int size = 1;
	int count = 0;
	while (size < length)
	{
		int size_last = size;
		size = 2 * size;
		int index = 0;
		while (index + size <= length)
		{
			MergeSort1(a, index, index + size_last - 1, index + size - 1);
			index = index + size;
		}
		if (index + size_last < length)
		{
			MergeSort1(a, index, index + size_last - 1, length - 1);
		}
	}
	printf("BottomUpMergeSort:");
	while (count != length)
	{
		printf("%d ", a[count]);
		count++;
	}
}

void main()
{
	/*int* Array;
	Array = (int*)malloc(sizeof(int) * 65536);
	int num = 0;
	printf("Please input your array (input 'q' to end):\n");
	while (scanf_s("%d", Array[num]))
	{
		if (Array[num] != 'q')
			num++;
		else
			break;
	}
	*/
	int Array[] = {2,35,44,52,66,13,45,57};
	int length = sizeof(Array)/sizeof(Array[0]);
	//printf("%d", length);

	//Linear Search element comaparisons 为 n, Binary Search element comparisons 为 1~logn取整+1
	MergeSort(Array, 0, 4, length-1); //element comparisons n1~n-1, assignments 2n
	printf("\n");
	SelectSort(Array, length); //element comparisons n(n-1)/2, assignments 0~3(n-1)
	printf("\n");
	InsertSort(Array, length); //element comparisons n-1~n(n-1)/2, assignments 2(n-1)~(n+2)(n-1)/2 (其中while语句的比较次数为1~n/2)
	printf("\n");
	BottomUpMerge(Array, length);//element comparisons nlogn/2~nlogn-n+1, assignments 2nlogn（共经过logn次merge）
	printf("\n");
}
