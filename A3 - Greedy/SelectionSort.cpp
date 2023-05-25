#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
	int i, j,temp,minn;

	
	for (i = 0; i < n - 1; i++) {
	    minn = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[minn])
				minn=j;
				
		}
		if (minn != i)
            swap(arr[minn], arr[i]);
	}
	for (i = 0; i < n; i++) {
		cout << arr[i] << " ";
		cout << endl;
	}
}

int main()
{
	int arr[] = {1, 64, 25, 22,0,8};
	int n = 6;
	selectionSort(arr, n);
	
	return 0;
}
