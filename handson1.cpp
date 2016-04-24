#include <iostream>

using namespace std;

void haveFun(int* x, int* y);

int main(){
	
	int x = 3;
	int y = 4;
	
	cout << "Original Values" << endl;
	cout << "X: " << x << " Y: " << y << endl;
	
	haveFun(&x, &y);
	
	cout << "\nNew Values" << endl;
	cout << "X: " << x << " Y: " << y << endl;
	
	return 0;
}

/*********
Task: switch values of the parameters
*******/

void haveFun(int* x, int* y){

	/*Pre: x: pointer to first value
		   y: pointer to second value
		   Post: nothing */
	
	int temp = *y;
	
	*y = *x;
	
	*x = temp;
	
	return;

}
/* Output
Original Values
X: 3 Y: 4

New Values
X: 4 Y: 3
*/