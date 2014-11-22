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
	string projectName = "";
	for(int i = 0; ; i++){
		cin >> menuSelect;
		if(menuSelect == "new"){ //create new project
			projectName = newProject();
			break;
		}else if(menuSelect == "continue"){ //continue new project
			projectName = continueProject();
			break;
		}else if(menuSelect == "quit"){ //quits program
			return 0;
		}else{ // incorrect input
			cout << "Incorrect input. Please try again: ";
		}
	}
	
	projectWorkspace(projectName); //Where literally ALL of the magic happens
	cout << "Goodbye!";
	return 0;
}

string newProject(){ /*gets data from user about project contents*/
	string newProjName = "", newProjTitle = "", newAuthName = "";
	fstream write;
	
	for(int i = 0; ; i++){
		cout << "Project file name (no spaces): ";
		cin >> newProjName;
		write.open(newProjName.c_str());
		if(write.fail()){
			write.close();
			break;
		}else{
			cout << "Error: File already exists" << endl;
		}
	}
	cout << "Title of project: ";
		getline(cin, newProjTitle, '\n');
	cout << "Name of Author: ";
		getline(cin, newAuthName, '\n');
		
	/*create new file, insert above data into file*/
	write.open(newProjName.c_str(), ios::out);
	
	write << newProjTitle << endl;
	write << newAuthName << endl;
	
	write.close();
	
	/*pass newProjName to projectWorkspace to load newly create file and allow
	user to begin working*/
	return newProjName;
}

string continueProject(){ /* gets filename from user*/
	string projName = "";
	
	cout << "Enter the name of project to continue: ";
	cin >> projName;
	
	cout << "Loading.." << endl;

	return projName;
}

void projectWorkspace(string projName){
	ofstream write;
	write.open(projName.c_str(), ios::app);
	
	//project title from file goes here
	
	cout << "Loaded! Type \"save\" to save and exit" << endl;
	string par;
	for(int i = 0; ; i++){
		getline(cin, par);
		if(par == "save"){
			break;
		}
		write << par << endl;
	}
	
	write.close();
	cout << "Saved!" << endl;
}


