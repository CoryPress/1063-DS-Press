/**
* @ProgramName: Program-1
* @Author: Cory Press
* @Description:
*	This program reads in images stored as rgb values in a space delimited file format. Then 
*	it will ask the user what they like to do the image, either flip it horizontally or vertically,
*	or grayscale it. It will then aply the chosen effect and store the new rbg valuse in a new
*	space delimited file.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 05 02 2017
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb{
	int r;
	int g;
	int b;
};

/**
* @FunctionName: flipVert
* @Description:
*	Loops through a 2D array and switches each rgb value with the rgb value mirrored across
*    the middle column of the image.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipVert(rgb** image, int width, int height)
{
	rgb Temp;
	for (int i = 0; i <= height/2 ; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			Temp.r = image[i][j].r;
			Temp.g = image[i][j].g;
			Temp.b = image[i][j].b;
			image[i][j].r = image[height - 1 - i][j].r;
			image[i][j].g = image[height - 1 - i][j].g;
			image[i][j].b = image[height - 1 - i][j].b;
			image[height - 1 - i][j].r = Temp.r;
			image[height - 1 - i][j].g = Temp.g;
			image[height - 1 - i][j].b = Temp.b;
		}
	}
}

/**
* @FunctionName: flipHorz
* @Description:
*	Loops through a 2D array and switches each rgb value with the rgb value mirrored across
*    the middle row of the image. 
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipHorz(rgb** image, int width, int height)
{
	rgb Temp;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j <= width/2; j++)
		{
			Temp.r = image[i][j].r;
			Temp.g = image[i][j].g;
			Temp.b = image[i][j].b;
			image[i][j].r = image[i][width - 1 - j].r;
			image[i][j].g = image[i][width - 1 - j].g;
			image[i][j].b = image[i][width - 1 - j].b;
			image[i][width - 1 - j].r = Temp.r;
			image[i][width - 1 - j].g = Temp.g;
			image[i][width - 1 - j].b = Temp.b;
		}
	}
}

/**
* @FunctionName: grayScale
* @Description:
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image, int width, int height)
{
	int Grey;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Grey = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
			image[i][j].r = image[i][j].g = image[i][j].b = Grey;
		}
	}
}

int main()
{
	ifstream ifile;          //Input / output files
	ofstream ofile;
	ifile.open("Image.txt");
	ofile.open("NewImage.txt");

	int width;               //width of image
	int height;              //height of image

	rgb **imgArray;         //Pointer var for our 2D array because we         
	//don't know how big the image will be!

	ifile >> width >> height;   //Read in width and height from top of input file
	//We need this so we can make the array the right 
	//size. After we get these two values, we can
	//now allocate memory for our 2D array.

	imgArray = new rgb*[height];    //This array points to every row

	for (int i = 0; i<height; i++){
		imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
	}

	//Read the color data in from our txt file
	for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}

	int choice, choice2;
	cout << "What would you like to do to your image? (input corresponding number)\n";
	cout << setw(8) << '1' << ". Flip Image\n";
	cout << setw(8) << '2' << ". Greyscale Image\n";
	cin >> choice;

	if (choice == 1)
	{
		cout << "Which way would you like to flip your image? (input corresponding number)\n";
		cout << setw(8) << '1' << ". Vertically\n";
		cout << setw(8) << '2' << ". Horizontally\n";
		cin >> choice2;
		if (choice2 == 1)
		{
			flipVert(imgArray, width, height);
		}
		else if (choice2 == 2)
		{
			flipHorz(imgArray, width, height);
		}
		else
		{
			cout << "ERROR: Invalid Input!";
		}
	}
	else if (choice == 2)
	{
		grayScale(imgArray, width, height);
	}
	else
	{
		cout << "ERROR: Invalid Input!";
	}

	//Write out our color data to a new file
	ofile << width << " " << height << endl;
	for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
		}
		ofile << endl;
	}

	return 0;
}