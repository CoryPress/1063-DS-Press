```
/**
* @ProgramName: Program_3
* @Author: Cory Press
* @Description:
*     This program reads equation strings from a file, then processes that into a solvable
*	   postfix and then into solution using Stacks and Queues
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 20 03 2017
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

/**
* @ClassName: Queue
* @Description:
*     Implementation of a char Queue
*/
class Queue{
private:
	int QArySize;
	char *QAry;
	int front;
	int back;
	int NumItems;
public:
	
	/**
	* @FunctionName: Queue
	* @Description:
	*     Class constructor
	* @Params:
	*    int Size - Size of the Queue
	* @Returns:
	*    void
	*/
	Queue(int Size){
		QArySize = Size;
		QAry = new char[QArySize];
		front = back = NumItems = 0;
	}
	
	/**
	* @FunctionName: Push
	* @Description:
	*     Pushs a Character onto the front of the Queue
	* @Params:
	*    char Char - Character that is being pushed onto the queue
	* @Returns:
	*    void
	*/
	void Push(char Char){
		QAry[back++] = Char;
		NumItems++;
	}

	/**
	* @FunctionName: Pop
	* @Description:
	*     Pops Character from the back of the Queue
	* @Params:
	*     None
	* @Returns:
	*     char Temp - Character being pushed off of the Queue
	*/
	char Pop(){
		char Temp = QAry[front++];
		NumItems--;
		return Temp;
	}

	/**
	* @FunctionName: Empty
	* @Description:
	*     Chaecks if the Queue is empty
	* @Params:
	*     None
	* @Returns:
	*     bool - if true Queue is empty
	*/
	bool Empty(){
		if (front == back){
			return true;
		}
		else{
			return false;
		}
	
	}

	/**
	* @FunctionName: PrintQueue
	* @Description:
	*     Prints queue to screen
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	void PrintQueue(){
		for (int i = front, j = 0; j<NumItems; j++, i = (i + 1) % QArySize){
			cout << QAry[i];
		}
	}
};

/**
* @ClassName: Stack
* @Description:
*     Implementation of a char Stack
*/
class Stack{
private:
	int SArySize;
	char *SAry;
	int top;
public:
	
	/**
	* @FunctionName: Stack
	* @Description:
	*     Class constructor
	* @Params:
	*    int Size - Size of the Stack
	* @Returns:
	*    void
	*/
	Stack(int Size){
		SArySize = Size;
		SAry = new char[SArySize];
		top = 0;
	}
	
	/**
	* @FunctionName: Push
	* @Description:
	*     Pushs a Character onto the top of the Stack
	* @Params:
	*    char Char - Character that is being pushed onto the Stack
	* @Returns:
	*    void
	*/
	void Push(char Char){
		SAry[top++] = Char;
	}

	/**
	* @FunctionName: Pop
	* @Description:
	*     Pops Character from the top of the Stack
	* @Params:
	*     None
	* @Returns:
	*     char Temp - Character being pushed of off the Stack
	*/
	char Pop(){
		char Temp = SAry[--top];
		return Temp;
	}

	/**
	* @FunctionName: Empty
	* @Description:
	*     Chaecks if the Stack is empty
	* @Params:
	*     None
	* @Returns:
	*     bool - if true Stack is empty
	*/
	bool Empty(){
		if (top == 0){
			return true;
		}
		else{
			return false;
		}
	}
};

/**
* @ClassName: DecimalStack
* @Description:
*     Implementation of a float Stack
*/
class DecimalStack{
private:
	int SArySize;
	float *SAry;
	int top;
public:

	/**
	* @FunctionName: DecimalStack
	* @Description:
	*     Class constructor
	* @Params:
	*    int Size - Size of the Stack
	* @Returns:
	*    void
	*/
	DecimalStack(int Size){
		SArySize = Size;
		SAry = new float[SArySize];
		top = 0;
	}

	/**
	* @FunctionName: Push
	* @Description:
	*     Pushs a float value onto the top of the Stack
	* @Params:
	*    float val - float value that is being pushed onto the Stack
	* @Returns:
	*    void
	*/
	void Push(float val){
		SAry[top++] = val;
	}

	/**
	* @FunctionName: Pop
	* @Description:
	*     Pops float value from the top of the Stack
	* @Params:
	*     None
	* @Returns:
	*     char Temp - flaot value being pushed off of the Stack
	*/
	float Pop(){
		float Temp = SAry[--top];
		return Temp;
	}
};

/**
* @ClassName: Solve Equation
* @Description:
*     Reads in a equation string and evaluates it
*/
class SolveEquation{
private:
	string Infix;
	string Postfix;
	int NumEquat;
	Stack *S;
	DecimalStack *S2;
	Queue *Q;
	char Char, Temp;
	int InfixNum, PostfixNum, Precedence, StackPrecedence;
	float answer, x, y;

	/**
	* @FunctionName: InfixToPostfix
	* @Description:
	*     Takes the intial equation string and processes it into a solvable Postfix
	* @Params:
	*     None
	* @Returns:
	*     void
	*/
	void InfixToPostfix(){
		S = new Stack(Infix.length()+2);
		Q = new Queue(Infix.length()+2);
		S2 = new DecimalStack(Infix.length() + 2);
		S->Push('(');
		Infix[Infix.length()] = ')';
		while (!S->Empty()){
			Char = Infix[InfixNum];
			if ((int)Char >= 48 && (int)Char <= 57){
				Postfix[PostfixNum] = Char;
				PostfixNum++;
			}
			else if ((int)Char == 40){
				S->Push(Char);
			}
			else if ((int)Char == 37 || (int)Char == 42 || (int)Char == 43 || (int)Char == 45 || (int)Char == 47 || (int)Char == 94){
				switch ((int)Char){
				case 43:
				case 45:
					Precedence = 1;
					break;
				case 37:
				case 42:
				case 47:
					Precedence = 2;
					break;
				case 94:
					Precedence = 3;
					break;
				default:
					break;
				}

				if (StackPrecedence >= Precedence){
					Temp = S->Pop();
					while( Temp != '('){
						Postfix[PostfixNum] = Temp;
						PostfixNum++;
						Temp = S->Pop();
					}
					S->Push('(');
					S->Push(Char);
					
					StackPrecedence = Precedence;
				}
				else{
					S->Push(Char);
					StackPrecedence = Precedence;
				}
			}
			else if ((int)Char == 41) {
				Temp = S->Pop();
				while ((int)Temp != 40){
					Postfix[PostfixNum] = Temp;
					PostfixNum++;
					Temp = S->Pop();
				}
			}
			InfixNum++;
		}
		for (int i = 0; i < Infix.length(); i++){
			Q->Push(Postfix[i]);
		}
		
	}

	/**
	* @FunctionName: SolvePostfix
	* @Description:
	*     Takes the Postfix and processes it into the answer of the original equation
	* @Params:
	*     None
	* @Returns:
	*     double answer - answer to the equation
	*/
	double EvaluatePostfix(){
		while (!Q->Empty()){
			Temp = Q->Pop();
			if ((int)Temp >= 48 && (int)Temp <= 57){
				S2->Push((int)Temp - 48.0);
			}
			else{
				
				x = S2->Pop();
				y = S2->Pop();
				switch ((int)Temp){
					case 43:
						answer = y+x;
						break;
					case 45:
						answer = y-x;
						break;
					case 37:
						answer = fmod(y,x);
						break;
					case 42:
						answer = y*x;
						break;
					case 47:
						answer = y/x;
						break;
					case 94:
						answer = pow(y,x);
						break;
					default:
						break;
				}
				S2->Push(answer);
			}
		}
		return answer;

	}
public:
	
	/**
	* @FunctionName: SolveEquation
	* @Description:
	*     Class constructor
	* @Params:
	*     None
	* @Returns:
	*     void
	*/
	SolveEquation(){
		InfixNum = PostfixNum = StackPrecedence = 0;
		Postfix = "                   ";
	}

	/**
	* @FunctionName: SolveEquation
	* @Description:
	*     reads in the equation then calls on private functions to process it into the solution
	*	  and the print that solution
	* @Params:
	*     ifstream &infile - allows function to read from the file opened in main
	* @Returns:
	*     void
	*/
	void SolveEquations(ifstream &infile){
			infile >> Infix;
			cout << Infix;
			InfixToPostfix();
			answer = EvaluatePostfix();
			cout << " = " << answer << '\n';
			delete Q;
			delete S;
			delete S2;
		
	}

};

int main(){
	
	ifstream infile;
	infile.open("exp.txt");
	int NumEquat;
	infile >> NumEquat;
	for (int i = 0; i < NumEquat; i++){
		SolveEquation Calc;
		Calc.SolveEquations(infile);
	
	}
	system("pause");
	infile.close();
	return 0;
}
```
