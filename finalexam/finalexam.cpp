/*
File Name: finalexap.cpp
programmer: Perrin Dalgleish
requrements:
read the contents of the file into an array then display the following data:
• The lowest number in the array
• The highest number in the array
• The total of the numbers in the array
• The average of the numbers in the array
*/

#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> sortednums(string file) // outputs a sorted list from the input file
{
    ifstream infile(file);
	if (!infile)
	{
		cout << "error reading file. exiting" << endl;
	}
	vector<double> nums;
	double number;
	while (infile >> number)
	{
		nums.push_back(number);
	}
	infile.close();

	sort(nums.begin(), nums.end()); // sorts the whole file numerricly
	return nums;

}

string getfilename() // gets the name of the file to open
{
	string fileName;
	cout << "Enter the name of the file you want to open: ";
	cin >> fileName;
	return fileName;
}
void lownum(vector<double> nums) // reads the first item in the vector. bc it is sorted allready it works
{
	cout << "The lowest number in the file is " << nums.front() << endl; // wanted to make it more efficent https://www.geeksforgeeks.org/how-to-access-first-element-of-vector-in-cpp/
	
}
void highnum(vector<double> nums) // reads the last item in the vector. bc it is sorted allready it works
{
	cout << "The highest number in the file is " << nums.back() << endl;
}
void totalnums(vector<double> nums) // calculates how many items are in the vector by counting the items in the vector
{
	int i = 0;
	int c = 0;
	for (auto i : nums)
	{
		c++;
	}
	cout << "There are " << c << " numbers in the file." << endl;

}
void average(vector<double> nums) // calulates the average
{
	double total, average,non;
	total = 0;
	non = 0;
	for (auto i : nums)
	{
		total = i + total;
		non++;
	}
	average = total / non;
	cout << "There average of all the numbers is " << average << endl;
}
int quits() // prompts if the user wants to quit
{
	int quit;
	cout << "Type 1 to exit; 0 to cont. " << endl;
	cin >> quit;
	switch (quit)
	{
	case 1:
		return 1;
		break;
	case 0:
		cout << "continueing... " << endl;
		return 0;
		break;
	default:
		cout << "invalid selection, exiting";
		return 1;
		break;
	}
} 

int main()
{
	int quit = 0;
	do {
		const string filelocation = "C:/Users/perri/Downloads/"; //only need to change this to get it to run
		string filename = filelocation + getfilename();
		vector<double> nums = sortednums(filename);
		cout << "charistaristics of file " << filename << endl;
		lownum(nums);
		highnum(nums);
		totalnums(nums);
		average(nums);
		quit = quits();
	} while (quit == 0);
	

}

