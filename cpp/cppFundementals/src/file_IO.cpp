/*
 * file_IO.cpp
 *
 *  Created on: May 21, 2016
 *      Author: Robert
 *
 *      basic file input output
 */

#include "../h/file_IO.h"

/**
 * You can use the same cpp IO methods associated with console IO for file IO
 */
void fileIO()
{
	cout<<"creating a file"<<endl;

	ofstream outFile;
	outFile.open("files/newFile.txt");
	outFile <<"Save this text to the newFile.txt created above\n";
	outFile.close();

	char *line = new char(sizeof(char)*50);

	ifstream infile;
	infile.open("files/myFile.txt");
	infile.getline(line,49);
	infile.close();

	cout<<"reading from the file: "<<line<<endl;

}



