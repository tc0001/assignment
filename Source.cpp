#include<iostream>
#include<cctype>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;

struct info
{
	char name[50];
	char mykad[13];
	char student_id[11];
	char program[4];
	char gender;
	int year;

	void nominee_data()
	{
		info nominee;
		bool dup = false;
		cout << "\n\n\n\n\n\t\t\t\t\tEnter candidate name	: ";
		cin.ignore();
		cin.getline(name, 50);
		cout << "\n\t\t\t\t\tEnter MyKad Number	: ";
		cin.get(mykad,13);
		cout << "\n\t\t\t\t\tEnter Student ID	: ";
		cin.ignore();
		cin.get(student_id,11);
		cout << "\n\t\t\t\t\tProgram			: ";
		cin >> program;
		cout << "\n\t\t\t\t\tGender			: ";
		cin >> gender;
		cout << "\n\t\t\t\t\tEnter Year of Study	: ";
		cin >> year;

		ifstream infile;
		infile.open("nominee.dat", ios::binary | ios::in);
		for (int i = 0; ((infile.read(reinterpret_cast<char*>(&nominee), sizeof(info)))); i++)
		{
			cout << nominee.name;
		}

		if (strcmp(name,nominee.name)==0)
		{
			cout << " is nominated already.";
			infile.close();
			cin.ignore();
			cin.get();
		}


		if(name != nominee.name)
		{
			ofstream outfile;
			cin.ignore();
			cin.get();
		}


		infile.close();
	}

	void showdetail()
	{
		cout << "\t" << name << "\t\t\t" << mykad << "\t" << student_id << "\t" << program << "\t\t" << gender << "\t\t" << year << endl;

	}
};

void displayMenu();
void user();
void login();
void nominate();
void voteMenu();
void displayDetail();
void vote();
void registration();
void administrator();

int main() 
{
	system("Color 70");
	char choice;
	cout << "\n\n\n\n\n";
	cout << "\n\t\t\t\t\t=##############################=";
	cout << "\n\t\t\t\t\t=                              =";
	cout << "\n\t\t\t\t\t=            WELCOME!          =";
	cout << "\n\t\t\t\t\t=                              =";
	cout << "\n\t\t\t\t\t=##############################=";
	cout << "\n\n\t\t\t\t\t\tPress Enter";
	cin.get();

	do {
		system("cls");
		displayMenu();
		cin >> choice;
		switch (choice)
		{
		case '1':
			user();
			break;
		case '2':
			administrator();
			break;
		case '3':
			break;
		default:
			cout << "\n\t\t\t\t\tInvalid! Please enter again.\a\n\n";
			cin.ignore();
			cin.get();
		}
	} while (choice != '3');

	return 0;
}

void displayMenu() {
	cout << "\n\n\n\n\n\t\t\t\t\tPlease Select: \n";
	cout << "\t\t\t\t\t==================\n\n";
	cout << "\t\t\t\t\t1.USER          \n\n";
	cout << "\t\t\t\t\t2.ADMINISTRATOR \n\n";
	cout << "\t\t\t\t\t3.QUIT PROGRAM  \n\n\n";
	cout << "\t\t\t\t\tEnter your choice : -> ";

}

void user() 
{
	char choice;
	do
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t\tSELECT: \n";
		cout << "\t\t\t\t\t---------\n\n";
		cout << "\t\t\t\t\t1. Login \n\n";
		cout << "\t\t\t\t\t2. Main Menu\n\n";
		cout << "\t\t\t\t\tEnter your choice : ->  ";
	
	
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case '1':
			login();
			break;
		case '2':
			break;
		default:
			cout << "\n\t\t\t\t\tInvalid! Please enter again.\a\n\n";
			cin.ignore();
			cin.get();
			user();
		}
	} while (choice != '2');
}

void login() 
{
	info nominee;
	char mykad[13];
	char choice;
	int count = 0;
	string name, stud_id;
	
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\tMyKad Number		: ";
	cin.ignore();
	cin >> mykad;
	cout << "\n\t\t\t\t\tStudent ID		: ";
	cin.ignore();
	cin >> stud_id;
	

	do{
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t\tSelect:\n\n";
		cout << "\t\t\t\t\t1. Nomination\n\n";
		cout << "\t\t\t\t\t2. Logout\n\n";
		cout << "\t\t\t\t\tEnter :--> ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			if (count == 0)
			{
				system("cls");
				nominate();
				count++;
			}
			else
			{
				cout << "\n\t\t\t\tYou have already nominated.\n";
				cin.ignore();
				cin.get();
			}
			break;
		case '2':
			break;
		default:
			cout << "\n\t\t\t\t\tInvalid! Please enter again.\a\n\n";
			cin.ignore();
			cin.get();
		}
	} while (choice != '2');
}

void nominate()
{
	info nominee;
	ifstream infile;
	infile.open("nominee.dat", ios::binary);
	int i = 0;
	while (infile.read(reinterpret_cast<char*>(&nominee), sizeof(info)) && i < 5)
	{
		nominee.showdetail();
		i++;
	}
	infile.close();
	if (i != 5)
	{
		ofstream outfile;
		outfile.open("nominee.dat", ios::binary | ios::app);
		nominee.nominee_data();
		cout << "\n\n\t\t\t\t\tSuccessful Nomination!";
		outfile.write(reinterpret_cast<char*> (&nominee), sizeof(nominee));
		outfile.close();
	}
	else
	{
		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tThe nomination is closed.";
		cin.ignore();
		cin.get();
		voteMenu();
	}


	infile.close();
}

void vote()
{
	int vote[5] = { 0 }, i = 1;
	char choice;
	info nominee;
	ifstream infile;
	infile.open("nominee.dat", ios::binary);
	
	cout << "Vote For: \n\n";
	while (infile.read(reinterpret_cast<char*>(&nominee), sizeof(info)) && i <= 5)
	{
		cout << "\n\nNominee " << i << " " << nominee.name;
		i++;
	}
		cout << "\n\n\nEnter: ";

	cin >> choice;
	system("cls");

	switch (choice)
	{
	case '1':
		vote[0]++;
		break;
	case '2':
		vote[1]++;
		break;
	case '3':
		vote[2]++;
		break;
	case '4':
		vote[3]++;
		break;
	case '5':
		vote[4]++;
		break;
	default:
		cout << "\n\t\t\t\t\tInvalid! Please enter again.\a\n\n";
		cin.ignore();
		cin.get();
	}
}



void registration()
{

}



void displayDetail()
{
	info nominee;
	ifstream infile;
	int label = 1;
	infile.open("nominee.dat", ios::binary);
	if (!infile)
	{
		cout << "\nFile could not be opened!\n";
		return;
	}
	cout << "\n\nNOMINEES DETAIL\n";
	cout << "=====================================================================================================================\n";
	cout << "LABEL\tName\t\t\t\tMykad Number\tStudent ID\tProgram\t\tGender\t\tYear of Study\n";
	cout << "=====================================================================================================================\n";

	int i = 0;
	while (infile.read(reinterpret_cast<char*> (&nominee), sizeof(nominee)) && i!=5)
	{
		cout<<label;
		nominee.showdetail();
		i++;
		label++;
	}
	infile.close();
	cin.ignore();
	cin.get();
	system("cls");
}

void administrator() 
{
	const string adminUser[3] = { "Pangzanlam", "Lawsonshow","Karryweng" };
	const int password[3] = { 1397, 8519, 0462 };
	string username;
	int pw;

	system("cls");
	cout << "WELCOME\n";
	cout << "---------\n";
	cout << "\nEnter your username:";
	cin.ignore();
	cin >> username;
	cout << "\nEnter your password:";
	cin >> pw;
	cin.clear();
	cin.ignore();

	for (int i = 0; i < 3; i++)
	{
		if (username == adminUser[i] && pw == password[i])
			cout << "\n\nWelcome";
			cin.get();
	}
}

void voteMenu()
{
	char choice;
	system("cls");
	do{
	cout << "\n\n\t\t\t\t\t1. Check Nominees'Detail";
	cout << "\n\t\t\t\t\t2. Vote";
	cout << "\n\t\t\t\t\t3. Exit";
	cout << "\n\n\n\t\t\t\t\tEnter :  ";
	cin >> choice;
	system("cls");
		switch (choice)
		{
		case '1':
			displayDetail();
			break;
		case '2':
			vote();
			break;
		case '3':
			break;
		default:
			cout << "\n\t\t\t\t\tInvalid! Please try again.\a\n\n";
			cin.ignore();
			cin.get();
		}
	} while (choice != '3');
}