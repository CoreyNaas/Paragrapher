#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string newProject();
string continueProject();
void projectWorkspace(string projName);

int main(){
	
	cout << "Welcome to Paragrapher!" << endl;
	cout << "Type \"new\" to start a new project" << endl;
	cout << "Type \"continue\" to continue a project" << endl;
	cout << "Type \"quit\" to quit Paragrapher" << endl;
	
	string menuSelect;
	do{
	cin >> menuSelect;
	if(menuSelect == "new"){ //create new project
		newProject();
		break;
	}else if(menuSelect == "continue"){ //continue new project
		continueProject();
		break;
	}else if(menuSelect == "quit"){ //quits program
		return 0;
	}else{ // incorrect input
		cout << "Incorrect input. Please try again: ";
	}
	}while(menuSelect != "new" | menuSelect != "continue");

	cout << "ending...";
	return 0;
}

string newProject(){ /*gets data from user about project contents*/
	string newProgName, newProgTitle, newAuthName;

	cout << "Project file name (no spaces): ";
		getline(cin, newProgName, '\n'); //Buggy, skips first instance of getline
	cout << "Title of project: ";
		getline(cin, newProgTitle, '\n');
	cout << "Name of Author: ";
		getline(cin, newAuthName, '\n');
		
	/*create new file, insert above data into file*/
	
	/*pass newProgName to projectWorkspace to load newly create file and allow
	user to begin working*/
}

string continueProject(){


}

