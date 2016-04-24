#include <iostream>
using namespace std;

void out(int* arr, int n);
void outTwo(int arr[], int n);
void outThree(int arr[], int n);
void outFour(int arr[], int n);
int main()
{
	int arr[6] = {55,3,54,9,1,77};

	out(arr,6);

	outTwo(arr, 6);
	
	outThree(arr, 6);
	
	outFour(arr, 6);

	system("pause");
	
	return 0;
}

void out(int* arr, int n)
{
	cout << "Out 1" << endl;
	int i;
	for(i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << "\n\n";
	return;
}

void outTwo(int arr[], int n){
	cout << "Out 2" << endl;
	for(int i = 0; i < n; i++){
		cout << *(arr + i) << endl;
	}
}
void outThree(int arr[], int n){
	cout << "\n\nIncrementing a pointer " << endl;
	int* ptrA = arr;
	for(int i = 0; i < n; i++){
		cout << *ptrA << endl;
		ptrA++;
	}
	cout << "\n";
}
void outFour(int arr[], int n){
	int* ptrFirst = arr;
	int* ptLast = arr + n;
	
	cout << "Pointer to first and last elements" << endl;
	
	while(ptrFirst < ptLast){
		cout << *ptrFirst << " ";
		ptrFirst++;
	}
	cout << endl;
}