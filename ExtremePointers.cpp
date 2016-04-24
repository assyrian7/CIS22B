#include <iostream>
#include <string>
#include <cstring>

using namespace std;
void getData(double** arr, int num);
double** setPointers(double* arr, int num);
void sortSelect(double** arr, int num);
int main()
{
//Declare variables
    double* arr = NULL;
    int i;
    int num;
    double** ptrA;

    cout << "Enter the number of students that took the midterm ";
    cin >> num;


    getData(&arr, num);

    if(arr != NULL){
        for(int i = 0; i < num; i++)
        cout << *(arr + i);
    }
    cout << endl;

    ptrA = setPointers(arr, num);
	sortSelect(ptrA, num);
	cout << "Sorted" << endl;
    for(int i = 0; i < num; i++)
        cout << **(ptrA + i);
	cout << endl;
	system("pause");
return 0;
}

void getData(double** arr, int num){

    *arr = new double[num];
    cout << "In function" << endl;
    for(int i = 0; i < num; i++)
        cin >> *(*arr + i);
    for(int i = 0; i < num; i++)
        cout << *(*arr + i);
    cout << endl;
    cout << "Ending function" << endl;
}
double** setPointers(double* arr, int num){

    double** ptrArr;
    ptrArr = new double*[num];

    for(int i = 0; i < num; i++){
        *(ptrArr + i) = arr + i;
    }

    return ptrArr;
}
void sortSelect(double** arr, int num)
{
    int current; int walker;
    int smallestIndex;
    double* temp;
    
    for (current = 0; current < num - 1; current++)
    {
        smallestIndex = current;
        for (walker = current; walker < num; walker++)
          {
                if (**(arr + walker) < **(arr + smallestIndex))
                  smallestIndex = walker;
          }//for walker
        
        //Swap to position smallest at what is the current position
        temp = *(arr + current);
        *(arr + current) = *(arr + smallestIndex); 
        *(arr + smallestIndex) = temp;  
    }//for current 
  return;
}
