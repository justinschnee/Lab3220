//============================================================================
// Group: Justin Schnee, Shawn Egan
// Date : 02/25/2018
// Lab: 3
// TA:
//============================================================================

#include <iostream>
#include<cstdlib>
#include<time.h>
#include <cmath>
using namespace std;

void printArray(int *x, int length);
int* CreArray(int* length, int* high, int* low);
//int *randStackArray(int length);
void printArrayAddresses(int *x, int length);
void printDoubleArrayAddresses(double *x, int length);
int **twoDimensionalArray(int *intOne, int *intTwo);
int HanWindow(int arr[]);
int* FilArray(int arr[], int length);
void GrphArray(int arr[], int length, int high, int low);
void printArray1(int arr[], int length);


int main()
{
	cout << "Problem 1:" << endl;

	cout << "Test 1: " << endl;
	int y[9] = {1,2,3,4,5,6,7,8,9};
	printArray(y, 9);

	cout << "Test 2: " << endl;
	int j[5] = {1,2,3,4,5};
	printArray(y, 5);

	cout << "Test 3: " << endl;
	int s[3] = {1,2,3};
	printArray(y, 3);
	cout << "******************************" << endl;

	cout << "Problem 2:" << endl;

	cout << "Test 1: " << endl;
	int length1, high1, low1, *arr1;
	int length2, high2, low2, *arr2;
	int length3, high3, low3, *arr3;
	arr1 = CreArray(&length1,&high1,&low1);   //Array 1
	arr2 = CreArray(&length2,&high2,&low2);   //Array 2
	arr3 = CreArray(&length3,&high3,&low3);   //Array 3
	cout << "length of #1 is  " << length1 << endl;
	cout << "high of #1 is  " << high1 << endl;
	cout << "low of #1 is " << low1 << endl;
	printArray(arr1, length1);

	cout << "Test 2" << endl;
	cout << "length of #2 is " << length2 << endl;
	cout << "high of #2 is " << high2 << endl;
	cout << "low of #2 is " << low2 << endl;
	printArray(arr2, length2);

	cout << "Test 3" << endl;
	cout << "length of #3 is " << length3 << endl;
	cout << "high of #3 is " << high3 << endl;
	cout << "low of #3 is " << low3 << endl;
	printArray(arr3, length3);
	cout << "******************************" << endl;

	cout << "Problem 3:" << endl;

	cout << " Test 1: " << endl;
	//int *stackArrayTest = randStackArray(36);
	//printArray(stackArrayTest, 36);
	//TODO : Explain why cannot return array from the stack


	cout << " Test 2: " << endl;

	cout << " Test 3: " << endl;

	cout << "******************************" << endl;\

	cout << "Problem 4:" << endl;
	cout << " Test 1: " << endl;
	printArrayAddresses(y,9);

	cout << " Test 2: " << endl;
	printArrayAddresses(j,5);

	cout << " Test 3:  " << endl;
	printArrayAddresses(s,3);
	cout << "******************************" << endl;

	cout << "Problem 5:" << endl;
	cout << " Test 1: " << endl;
	double z[5] = {1.1,2.2,3.3,4.4,5.5};
	printDoubleArrayAddresses(z,5);

	cout << " Test 2: " << endl;
	double q[4] = {1.1,2.2,3.3,4.4};
	printDoubleArrayAddresses(q,4);

	cout << " Test 3: " << endl;
	double t[3] = {1.1,2.2,3.3};
	printDoubleArrayAddresses(t,3);
	cout << "******************************" << endl;

	cout << "Problem 6" << endl;
	int han1[] = {1, 2, 3, 4, 5};
	cout << "Test 1: " << HanWindow(han1) << endl;
	int han2[] = {3, 8, 2, 5, 1};
	cout << "Test 2: " << HanWindow(han2) << endl;
	int han3[] = {2, 5, 1, 4, 6};
	cout << "Test 3: " << HanWindow(han3) << endl;



	cout << "****************" << endl;
	cout << "Problem 7" << endl;
	cout << "Test 1:" << endl;

	int arr10[5] = {3, 8, 2, 5, 1};
	int* newarr = FilArray(arr10,5);
	printArray(newarr,5); // Expected: 0,0,4,0,0

	cout << "Test 2:" << endl;
	int arr11[9] = {3,8,2,5,1,4,6,0,2};
	int* newarr2 = FilArray(arr11,9);
	printArray(newarr2,9); // Expected: 0,0,4,3,3,3,3,0,0

	cout << "Test 3:" << endl;
	int arr12[4] = {1, 2, 3, 4};
	int* newarr3 = FilArray(arr12,4);
	printArray1(newarr3,4); // Expected: 0,0,0,0
	cout << "****************" << endl;

	cout << "Problem 8" << endl;
	int rda1[] = {6, -2, -4, 5, -3, -4, -3, -1, 5, 2, -2, 0, -7, 2, -3, -4, -3, -1, -5, -3, 1, 7, 3, -7, -7, 3, -8, 1, -5, -4, -2, -5, -8, 0, -4};
	GrphArray(rda1, 35, 7, -8);  //^^NUmbers in PDF, 35 Numbers, high of 7, low of -8
	cout << "Filtered Array" << endl;
	int* rda2 = FilArray(rda1, 35);   //Filters the array
	GrphArray(rda2, 35, 2, -4);   //35 Numbers, high of 2, low of -4


	cout << "****************" << endl;

	cout << "Problem 9:" << endl;
	cout << "Test 1:" << endl;
	int x = 0;
	int y2 = 0;
	int **array2D = twoDimensionalArray(&x, &y2);
	for(int i = 0; i < x; i++)
	{
		printArray(array2D[i], y2);
	}
}

//Problem 1
void printArray(int *x, int length){
	for(int i = 0; i < length; i++){
		cout << x[i] << ", ";
	}
	cout << endl;
}

//Problem 2

int *CreArray(int *length, int *high, int *low)
{
	*length = rand() % 25 + 25;  //generates random number
	int *arr = new int[*length];  //creates an array on the memory heap of that length

	*high = rand() % 5 + 5;   //generates a random high number
	*low = (-1)*(rand() % 5 + 5);   //generates a random low number

	for (int i=0; i<*length; i++)     //fills in the array iteratively
	{
		arr[i] = rand()%(*high-*low) + *low;
	}
		return arr;
		delete[] arr;
}


//Problem 3

/*int *randStackArray(int length){
	int array[length];
	int high = rand()%5 + 5;
	int low = rand()%5 - 9;
	for(int i = 0; i < length; i++){
		int random = rand()%(high - low) + low;
		array[i] = random;
	}
	return array;
}*/

//Problem 4
void printArrayAddresses(int *x, int length){
	for(int i = 0; i < length; i++){
		cout << &x[i] << ", ";
	}
	cout << endl;
}

//Problem 5

void printDoubleArrayAddresses(double *x, int length){
	for(int i = 0; i < length; i++){
		cout << &x[i] << ", ";
	}
	cout << endl;
}




//Print Array Helpr Func

void printArray1(int arr[], int length){
	for(int i=0;i<length;i++){
		if(i==length-1){
			cout << arr[i] << endl;
		}
		else{
			cout << arr[i] << ",";
		}
	}
}

//Problem 7

int HanWindow(int arr[])
{

	int sum =0;
	for (int i=0; i<5; i++) {
			if (i==0 || i==4) {
				sum = sum + arr[i]*1;
			}
			else if (i==1 || i==3) {
				sum = sum + arr[i]*2;
			}
			else {
				sum = sum + arr[i]*3;
			}
		}

		sum=sum/9;  //dividing the sum by 9 to get the weighted average

		return sum;  //return the sum


}


//Problem 8

int* FilArray(int arr[], int length) {
	int* newarr = new int[length];
	if (length<5) {
		for (int i=0; i<length; i++) {
			newarr[i] = 0;
		}
	}
	else {
		for (int i=0; i<length; i++) {
			if (i<2 || i>length-3) {
							newarr[i] = 0;
						}
						else {
							newarr[i] = HanWindow(&arr[i-2]);
						}
		}
	}
	return newarr;  //Returns a new array
	delete[] newarr;
}


//Problem 9


void GrphArray(int arr[], int length, int high, int low) {
	for (int i=high; i>=low; i--) {
		if (i>=0) {
			cout << " " << i << ":";
		}
		else {
			cout << i << ":";
		}
		for (int j=0; j<length; j++) {
			if (arr[j]==i) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

//Problem 10
int **twoDimensionalArray(int *intOne, int *intTwo){
	int x = rand()%5 + 5;
	int y = rand()%4 + 4;
	*intOne = x;
	*intTwo = y;
	int **array2D = new int*[x];
	for(int i = 0; i < x; i++){
		array2D[i] = new int[y];
	}
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			array2D[i][j] = 0;
		}
	}
	for(int i = 0; i < 5; i++){
		int randX = rand()%x;
		int randY = rand()%y;
		if(array2D[randX][randY] == 1){
			while(array2D[randX][randY] == 1){
				randX = rand()%x;
				randY = rand()%y;
			}
		}
		array2D[randX][randY] = 1;
	}
	return array2D;
}

