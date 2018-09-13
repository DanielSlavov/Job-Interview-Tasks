//Write a function that will reverse the order of the content of a huge file in - place.
#include<fstream>
#include<iostream>
using namespace std;

void reverse(char* filename)
{
	fstream fin;
	fin.open(filename, ios::in | ios::binary | ios::out);

	char a, b;
	char* temp;
	//obtaining the length of the file
	fin.seekp(0, ios::end);
	int length = fin.tellg();


	for (int i = 0; i < length / 2; i++)
	{
		fin.seekp(i);//sets the iterator at the i position
		fin.get(a);//current letter = 'a'
		fin.seekp(length - i - 1);//sets the iterator at length-i position - at the opposite side of the file
		fin.get(b);// opposite char of 'a' - =' b'


		//swapping the chars at the i and the length-i positions
		fin.seekp(i);//iterator at i position
		temp = &b;
		fin.write(temp, 1);//the 'b' char at the 'a' position

		fin.seekp(length - i - 1);//iterator at opposite side of the file
		temp = &a;
		fin.write(temp, 1);//the 'a' char at the 'b' position
	}
	fin.close();
}

int main()
{
	reverse("file.txt");
	return 0;
}