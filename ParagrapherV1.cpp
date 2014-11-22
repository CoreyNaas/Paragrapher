#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	
	cout << "Welcome to Paragrapher!" << endl;
	cout << "Type \"new\" to start a new project" << endl;
	cout << "Type \"continue\" to continue a project" << endl;
	cout << "Type \"quit\" to quit Paragrapher" << endl;
	
	string menuSelect;
	do{
	cin >> menuSelect;
	if(menuSelect == "new"){ //create new project
		string newProgName, newProgTitle, newAuthName;
		
		cout << "Project file name (no spaces): ";
			getline(cin, newProgName);
		cout << "Title of project: ";
			getline(cin, newProgTitle);
		cout << "Name of Author: ";
			getline(cin, newAuthName);
		
		//newProject(newProgName, newProgTitle, newAuthName);
		
	}else if(menuSelect == "continue"){ //continue new project
	
	}else if(menuSelect == "quit"){ //quits program
		return 0;
	}else{ // incorrect input
		cout << "Incorrect input. Please try again: ";
	}
	}while(menuSelect != "new" | menuSelect != "continue");

	return 0;
}