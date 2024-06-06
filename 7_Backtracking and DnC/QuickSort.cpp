#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivotIndex = s;
    int pivot = arr[s];
    //count smaller elements
    int cnt = 0;

    for (int i = s+1; i <=e; i++)
    {
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    //place pivote at right position
    pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right part sambhal lete h
    int i = s, j = e;
    while(i<pivotIndex && j>pivotIndex){
        //already smaller element in the left side
        while (arr[i]<=pivot)
        {
            i++;
        }
        //already greater element in the right side
        while (arr[j]>pivot)
        {
            j--;
        }
        //2 case ho sakta h --> you found the element to swap OR-->No need to swap 
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        
    }

    return pivotIndex;
    
}

void quickSort(int arr[], int s, int e) {
    //base case
    if (s >= e) {
        return;
    }

    // Partitioning
    int p = partition(arr, s, e); // Pivot index

    // Sort the left part
    quickSort(arr, s, p - 1);

    // Sort the right part
    quickSort(arr, p + 1, e);
}


int main() {

	int arr[] = {2,1,6,9,4,5};
	int size = 6;
	int s = 0;
	int e = size - 1;

	cout << "Before quick sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	quickSort(arr,s,e);

	cout << "After quick sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}