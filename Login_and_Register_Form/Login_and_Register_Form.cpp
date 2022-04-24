//*********************** LOGIN AND REGISTRATION FORM ***********************
#include <iostream>
#include <fstream>//for file handling
#include <cstdlib>//for system()
#include <string>
#include <Windows.h>//for sleep()



using namespace std;
//creating form
class Form {
public:
	void login();
	void registeration();
	void administrator();
	void menu();
};
void Form::administrator() {
	string password,uID, UPass;
	cout << "\t\t\t\tPassWord: ";
	cin >> password;

	if (password == "U123") {
		fstream Afile;
		Afile.open("records.txt", ios::in);
		if (Afile.is_open()) {
			while (Afile >> uID >> UPass) {
				cout << "\n" << "Username: " << uID << ";" << " " << "Password: " << UPass << endl;
				Sleep(500);
			}
			Afile.close();
		}
	}
}

void Form::menu() {
	cout << "\t\t\t|--------------------------------------------------------|\n";
	cout << "\t\t\t|               LOGIN AND REGISTRATION FORM              |\n";
	cout << "\t\t\t|--------------------------------------------------------|\n";
	cout << "\t\t\t|--------------------------------------------------------|\n";
	cout << "\t\t\t| 1) LOGIN                                               |\n";
	cout << "\t\t\t| 2) REGISTER                                            |\n";
	cout << "\t\t\t| 3) ADMINISTRATOR                                       |\n";
	cout << "\t\t\t| 4) EXIT                                                |\n";
	cout << "\t\t\t|--------------------------------------------------------|\n";
	

	int choice;
	cout << "\n\t\t\tPlease choose a option: ";
	cin >> choice;

	switch (choice) {
	case 1:
		system("CLS");
		login();
		break;
	case 2:
		system("CLS");
		registeration();
		break;
	case 3:
		system("CLS");
		administrator();
		break;
	case 4:
		exit(0);
	default:
		cout << "\n\t\t\tPlease choose from the options above\n";
		system("CLS");
		menu();
	}
}
void Form::registeration() {
	string userName, password, userId, pass;
	cout << "\t\t\tUser Name: ";
	cin >> userName;
	cout << "\t\t\tPassword: ";
	cin >> password;
	//creating and writing to records.txt file
	ofstream f1;
	f1.open("records.txt", ios::app);//open records.txt
	f1 << userName << " " << password << endl;
	f1.close();//close records.txt

	cout << "\n\t\t\t\t\t****REGISTRATION SUCCESSFUL****" << endl;
	cout << " " << endl;
	Sleep(2000);// wait for 2s before clearing console
	system("CLS");//clear console
	menu();
}
void Form::login() {
	int count=0;
	string userName, password, userId, pass;

	cout << "\t\t\tUser Name: ";
	cin >> userName;
	cout << "\t\t\tPassword: ";
	cin >> password;

	ifstream f2; //open records.txt
	f2.open("records.txt", ios::in);
	
		while (f2 >> userId >> pass) {//checking if there is username and password
			//checking if username and password is in the records.txt
			if (userName == userId && password == pass) {
				count = 1;// if found increase count by one
			}
		}
		f2.close();//close records.txt
	if (count == 1) {//if found ....
		cout << "\n\t\t\t\t\t****LOGIN SUCCESS****" << endl;
		menu();
	}
	else {
		cout << "\n\t\t\t\t\tFAILED TO LOGIN" << endl;
		cout << "\n\t\t\t\t\tTRY AGAIN" << endl;
		Sleep(2000);
		system("CLS");
		menu();
	}
}

int main() {
	Form myForm;//creating object myForm.
	myForm.menu();

	system("pause");

}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$ MOHAMED ABDIKAFI HUSSEIN $$$$$$$$$$$$$$$$$$$$$$$$$$$$