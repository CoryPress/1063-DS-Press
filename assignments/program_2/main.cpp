
/**
* @ProgramName: Program-2
* @Author: Cory Press
* @Description:
*	This program creates a class, which was the ability to read in an image as rgb values from
*   a space delimited file format, then has the ability to edit the image by either flipping it
*   horizontally or vertically, or grayscale it and then write the edited image as rgb values into
*   a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 15 02 2017
*/

#include<iostream>
#include<fstream>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb{
	int r;
	int g;
	int b;
};

class ImageManip{
private:
	rgb** image;
	int width;
	int height;
	ifstream infile;
	ofstream ofile;
	string infile_name = "Image.txt";
	string ofile_name = "NewImage.txt";
public:

	/**
	* @FunctionName: readFile
	* @Description:
	*	reads in images stored as rgb values in a space delimited file format
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
	void readFile(){
		infile.open(infile_name);
		infile >> width >> height;
		image = new rgb*[height];
		for (int i = 0; i < height; i++){
			image[i] = new rgb[width];
		}

		for (int i = 0; i<height; i++){
			for (int j = 0; j<width; j++){
				infile >> image[i][j].r >> image[i][j].g >> image[i][j].b;
			}
		}
		infile.close();
	}

	/**
	* @FunctionName: writeFile
	* @Description:
	*	stores the edited image as rgb values in a space delimited file format
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
	void writeFile(){
		ofile.open(ofile_name);
		ofile << width << " " << height << endl;
		for (int i = 0; i<height; i++){
			for (int j = 0; j<width; j++){
				ofile << image[i][j].r << " " << image[i][j].g << " " << image[i][j].b << " ";
			}
			ofile << endl;
		}
		ofile.close();
	}

	/**
	* @FunctionName: flipVert
	* @Description:
	*	Loops through a 2D array and switches each rgb value with the rgb value mirrored across
	*    the middle column of the image.
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
	void flipVert(){
		rgb Temp;
		for (int i = 0; i <= height / 2; i++)
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
	*    none
	* @Returns:
	*    void
	*/
	void flipHorz(){
		rgb Temp;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j <= width / 2; j++)
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
	*    none
	* @Returns:
	*    void
	*/
	void grayScale(){
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
	
};




int main(){

	
	ImageManip MyImage;

	MyImage.readFile();

	MyImage.grayScale();

	MyImage.flipHorz();

	MyImage.flipVert();

	MyImage.writeFile();

}
