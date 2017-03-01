
/**
* @Homework: Homework-3
* @Author: Cory Press
* @Description:
*     This program containd a class that creates a circular array based queue, where items can 
*     either be Pushed in or Popped off. It can also Print the queue and check whether the queue
*	  is full and if it is empty.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 01 03 2017
*/

#include <iostream>
#include <random>

using namespace std;

class ArrQueue{
private:
	int ArraySize;
	int *Q;
	int Front;
	int Rear;
	int NumItems;
public:
	ArrQueue(int size = 10){
		ArraySize = size;
		Q = new int[ArraySize];
		Front = Rear = NumItems = 0;
	}

	bool Push(int value){
		if (Full()){
			cout << "Queue Full!" << endl;
			return false;
		}
		Q[Rear] = value;
		Rear = (Rear + 1) % ArraySize;
		NumItems++;
		return true;
	}

	int Pop(){
		if (Empty()){
			cout << "Queue Empty!" << endl;
			return false;
		}
		int Temp = Q[Front];
		Front = (Front + 1) % ArraySize;
		NumItems--;
		return Temp;
	}

	bool Empty(){
		return (NumItems == 0);
	}

	bool Full(){
		return (NumItems == ArraySize);
	}

	void PrintFR(){
		cout << "Front: " << Front << "Rear: " << Rear << endl;
	}


	/**
	* @FunctionName: Print
	* @Description:
	*     Instead of a while loop that looped until index equaled the rear, I used a
	*	  simple for loop that loops for ever item in the que, while index is seperately indexed
	* @Params:
	*    NONE
	* @Returns:
	*    NONE
	*/
	void Print(){
		int Index = Front;

		for(int i = 0;i < NumItems;i++) {
			cout << Q[Index] << " ";
			Index = ((Index + 1) % (ArraySize));
		}
		cout << endl;
	}


};

int main() {
	srand(983475);
	ArrQueue Q;
	int r = 0;
	bool result;

	for (int i = 0; i<12; i++){
		r = rand() % 100;
		result = Q.Push(r);
		if (result)
			cout << r << endl;
	}
	Q.PrintFR();
	Q.Print();
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;

	Q.Print();
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	for (int i = 0; i<3; i++){
		r = rand() % 100;
		result = Q.Push(r);
		if (result)
			cout << r << endl;
	}
	system("pause");
	return 0;
}
