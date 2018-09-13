//Write a function in C++ that finds the k largest unique integers from a given huge array.
// 4*n complexity solution
#include<iostream>
#include<algorithm>

using namespace std;


void printarr(int* arr, int size)//prints out an array with a given size
{
	for (int i = 0; i <size; i++)
	{
		cout << arr[i] << ' ';

	}
	cout << '\n';
}

int PositionOfMin(int*a, int size)//returns the position of the smallest element in an array with a given size
{
	int min = INT_MAX;
	int posofmin;
	for (int i = 0; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			posofmin = i;
		}
	}

	return posofmin;
}
bool Contains(int*a, int size, int e)//checks if an array contains a given integer
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == e) return true;
	}
	return false;
}

int* klargest(int* a, int size, int k)//a - given array,k - size of final array
{
	int* fin = new int[k];//final array

	//fills the final array with the first k elements of the given array
	for (int i = 0; i < k; i++)
	{
		if (!Contains(fin, k, a[i]))//if the final array already contains the same element INT_MIN is put there
		{
			fin[i] = a[i];
		}
		else fin[i] = INT_MIN;
	}

	//cycles through the given array 
	for (int i = k; i < size; i++)
	{
		//if the current element is larger than the smallest element in the final array
		//and if it is not already contained in the final array, the current element is inserted in the final array
		if (a[i] >= fin[PositionOfMin(fin, k)] && !Contains(fin, k, a[i]))
		{
			fin[PositionOfMin(fin, k)] = a[i];
		}
	}

	return fin;
}

int main()
{
	int arr[] = { 3,243,54,-123,65,6,5,-1,2,3,-4,5,3,56,3,4,53,1,6,-545,6654,6544,65,4 };
	int size = sizeof(arr) / sizeof(int);
	int k;
	cin >> k;

	int* res = klargest(arr, size, k);
	printarr(res, k);
	delete res;

	return 0;
}