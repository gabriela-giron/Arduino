#include<iostream>
#include<string>
#include<stdlib.h>
#include"SerialPort.h"

using namespace std;

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

// change the name of the port with the port name of your computer
// must remember that the backslashes are essential so do not remove them
char commport[] = "\\\\.\\COM3";
char* port = commport;

int main() {
	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "Connection made" << endl << endl;
	}
	else {
		cout << "Error in port name" << endl << endl;
	}
	while (arduino.isConnected()) {
		cout << "Enter your command: " << endl;
		string data;
		cin >> data;

		char* charArray = new char[data.size() + 1];
		copy(data.begin(), data.end(), charArray);
		charArray[data.size()] = '\n';

		arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		cout << ">> " << output << endl;

		delete[] charArray;
	}
	return 0;
}