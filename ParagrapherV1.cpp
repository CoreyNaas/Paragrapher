#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* creates new project file based on user's input */
string newProject();

/* allows user to give project filename to load from
program directory */
string continueProject();

/* allows a user to open a project file to be viewed and/or added to */
void viewProject();

/* takes user input from newProject or continueProject
and load project for user to modify */
void projectWorkspace(string projName);

int main(){
	
	cout << "Welcome to Paragrapher!" << endl;
	cout << "Type \"new\" to start a new project" << endl;
	cout << "Type \"continue\" to continue a project" << endl;
	cout << "Type \"view\" to view a project" << endl;
	cout << "Type \"quit\" to quit Paragrapher" << endl;
	
	string menuSelect; //variable holds user input for menu selection
	string projectName = ""; // variable holds project filename from user for workspace
	
	/* loop holds main menu for program */
	for(int i = 0; ; i++){
		cin >> menuSelect;
		if(menuSelect == "new"){ //create new project
			projectName = newProject();
			break;
		}else if(menuSelect == "continue"){ //continue new project
			projectName = continueProject();
			break;
		}else if(menuSelect == "view"){ //view an existing project
			viewProject();
			cout << "Welcome to Paragrapher!" << endl;
			cout << "Type \"new\" to start a new project" << endl;
			cout << "Type \"continue\" to continue a project" << endl;
			cout << "Type \"view\" to view a project" << endl;
			cout << "Type \"quit\" to quit Paragrapher" << endl;
			continue;
		}else if(menuSelect == "quit"){ //quits program
			return 0;
		}else{ // incorrect input
			cout << "Incorrect input. Please try again: ";
		}
	}
	
	/* passes project filename from user into workspace */
	projectWorkspace(projectName);
	
	// informs user program is ending, give visual notice that program has reached the end
	cout << "Goodbye!";
	return 0;
}

string newProject(){ /*gets data from user about project contents*/
	string newProjName = "", newProjTitle = "", newAuthName = "";
	fstream write;
	
	for(int i = 0; ; i++){
		cout << "Project file name (no spaces): ";
		cin >> newProjName;
		cin.ignore(1, '\n'); /*fixes problem with getline below*/
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
	
	/*pass newProjName to projectWorkspace to load newly
	create file and allow user to begin working*/
	return newProjName;
}


string continueProject(){ /* gets filename from user*/
	string projName = "";
	
	/* gets filename from user to load */
	cout << "Enter the name of project to continue: ";
	cin >> projName;
	
	/* Give the user something to read */
	cout << "Loading.." << endl;

	return projName;
}

void viewProject(){
	/* IO stream created for user input for filename */
	fstream read;
	
	string projName = ""; //variable holds filename from user
	
	/* gets filename from user to load and view */
	cout << "Enter the name of project to view: ";
	cin >> projName;
	
	cout << "Press enter for next paragraph, type \"exit\" to quit" << endl;
	
	read.open(projName.c_str(), ios::in);
	
	string exit = ""; /*variable waits for user to
	input "exit" to quit loop */
	while(exit != "exit"){
	string para = "";
	
	read >> para;
	cout << para << endl;
	
	cin >> exit;
	}
	
	cout << "returning to main menu..." << endl;
	return;
}

void projectWorkspace(string projName){
	// IO stream created for user input to go into file
	ofstream write;
	
	/* Open output stream for project filename gotten
	from user, allows input to append to existing file */
	write.open(projName.c_str(), ios::app);
	
	//project title from file goes here
	
	cout << "Loaded! Type \"save\" to save and exit" << endl;
	
	// variable holds paragraph to be written to file
	string par;
	
	/* loop waits for user to enter "save" to break and
	go to end of function, otherwise writes contents of par to file
	and repeats */
	for(int i = 0; ; i++){
		getline(cin, par);
		if(par == "save"){
			break;
		}
		write << par << endl;
	}
	
	/* closes output stream to project file */
	write.close();
	cout << "Saved!" << endl;
}