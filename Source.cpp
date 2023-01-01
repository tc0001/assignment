#include<iostream>
#include<string>
#include<cctype>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;

struct info
{
	string name;
	string mykad;
	string student_id;
	string program;
	char gender;
	int year;

	void nominee_data()
	{
		info nominee;
		bool dup = false;
		cout << "\n\n\n\n";
		cout << "\n\t\t\t\t\tEnter candidate name	: ";
		cin.ignore();
		getline(cin, name);
		cout << "\n\t\t\t\t\tEnter MyKad Number	: ";
		getline(cin, mykad);
		cout << "\n\t\t\t\t\tEnter Student ID	: ";
		cin.ignore();
		getline(cin, student_id);
		cout << "\n\t\t\t\t\tProgram			: ";
		cin.ignore();
		getline(cin, program);
		cout << "\n\t\t\t\t\tGender			: ";
		cin.ignore();
		cin.get(gender);
		cout << "\n\t\t\t\t\tEnter Year of Study	: ";
		cin >> year;

		ifstream infile;
		infile.open("nominee.dat", ios::in);

		while(!(infile.eof()))
		{
			infile >> nominee.name;
		}

		if (name == nominee.name)
		{
			dup = true;
			cout << nominee.name;
			cout << " is nominated already.";
			infile.close();
			cin.ignore();
			cin.get();
		}
		else
		{
			dup = false;
			cout << "\n\n\t\t\t\t\tSuccessful Nomination!";
			cin.get();
		}
	}

	void showdetail()
	{
		cout << "\nName		: " << name;
		cout << "\nMykad Number	: " << mykad;
		cout << "\nStudent ID	: " << student_id;
		cout << "\nProgram		: " << program;
		cout << "\nGender		: " << gender;
		cout << "\nYear of Study	: " << year << endl;
		cout << "\n===============================================\n";
	}
};

void displayMenu();
void user(info& nominee, int(&vote)[5]);
void login(info& nominee, int(&vote)[5]);
void nominate(info& nominee, int(&vote)[5]);
void voteMenu(info& nominee, int(&vote)[5]);
void displayDetail(info& nominee);
void castvote(info& nominee, int(&vote)[5]);
void registration(info& student);
void administrator(info& nominee, info& student, int(&vote)[5]);
void result(info& nominee, int(&vote)[5]);
void stat(info& nominee, info& student, int(&vote)[5]);

int main()
{
	system("Color 70");
	char choice;
	info nominee, student;
	int vote[5] = { 0 };
	ofstream outfile;
	outfile.open("votecount.dat");
	do {
		system("cls");
		displayMenu();
		cin >> choice;
		switch (choice)
		{
		case '1':
			system("cls");
			cout << "\n\n\n\n\n";
			cout << "\n\t\t\t\t\t=##############################=";
			cout << "\n\t\t\t\t\t=                              =";
			cout << "\n\t\t\t\t\t=            WELCOME!          =";
			cout << "\n\t\t\t\t\t=                              =";
			cout << "\n\t\t\t\t\t=##############################=";
			cout << "\n\n\t\t\t\t\t\tPress Enter";
			cin.ignore();
			cin.get();
			user(nominee, vote);
			break;
		case '2':
			administrator(nominee, student, vote);
			break;
		case '3':
			break;
		default:
			cout << "\n\t\t\t\t\tInvalid! Please enter again.\a\n\n";
			cin.ignore();
			cin.get();
		}
		outfile << vote;
	} while (choice != '3');
	outfile.close();
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

void user(info& nominee, int(&vote)[5])
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
			login(nominee, vote);
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

void login(info& nominee, int(&vote)[5])
{
	char mykad[50];
	char choice;
	int count = 0;
	char stud_id[11];
	bool eligible = false;
	do {
		system("cls");
		cout << "\n\n\n\n";
		cout << "\n\t\t\t\t\tMyKad Number(w/o '-') : ";
		cin.ignore();
		cin >> mykad;

		cout << "\n\t\t\t\t\tStudent ID		: ";
		cin.ignore();
		cin >> stud_id;

		info student;
		ifstream infile;
		infile.open("studentrecord.dat");
		while ((infile >> student.mykad >> student.student_id));
		{

		}

		if (mykad == student.mykad && stud_id == student.student_id)
		{
			eligible = true;
			cout << "\n\t\t\t\t\tSuccessful Login";
			cin.ignore();
			cin.get();
		}
		else
		{
			eligible = false;
			cout << "\n\t\t\t\t\tInvalid Mykad number or Student ID. Please try again.";
			cin.ignore();
			cin.get();
		}


	} while (eligible == false);


	do {
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
				nominate(nominee, vote);
				count++;
			}
			else
			{
				cout << "\n\t\t\t\t\tYou have already nominated.\n";
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


void nominate(info& nominee, int(&vote)[5])
{
	ifstream infile;
	infile.open("nominee.dat", ios::binary);
	int i = 0;
	while (infile.read(reinterpret_cast<char*>(&nominee), sizeof(info)) && i < 5)
	{
		i++;
	}
	infile.close();
	if (i != 5)
	{
		ofstream outfile;
		outfile.open("nominee.dat", ios::binary | ios::app);
		nominee.nominee_data();
		outfile.write(reinterpret_cast<char*> (&nominee), sizeof(info));
		cin.get();
		outfile.close();
	}
	else
	{
		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tThe nomination is closed.";
		cin.ignore();
		cin.get();
		voteMenu(nominee, vote);
	}


	infile.close();
}

void castvote(info& nominee, int(&vote)[5])
{
	char choice;

	system("cls");
	cout << "\n\n\n\n";
	cout << "\n\t\t\t\t\t###########################";//first part
	cout << "\n\t\t\t\t\t#                         #";
	cout << "\n\t\t\t\t\t# !!!!!!!!WARNING!!!!!!!! #";
	cout << "\n\t\t\t\t\t#                         #";
	cout << "\n\t\t\t\t\t###########################";
	cout << "\nYou only have ONE CHANCE to vote, \nOnce a vote is cast, no amendment or changing of vote is allowed.";//warning message 
	cout << "You must cast your vote by entering a correct number(e.g '1','2','3','4','5')" << endl;
	cout << "\nYou may choose to abstain by entering any number OUT OF THE VALID RANGE of candidate numbers(>5 or <1). ";
	cout << "\n(Click the Enter key to continue vote)" << endl;
	cin.ignore();
	cin.get();

	system("cls");

	ifstream infile;
	infile.open("nominee.dat", ios::binary);

	cout << "Vote For: \n\n";
	int i = 1;
	while (infile.read(reinterpret_cast<char*>(&nominee), sizeof(info)) && i <= 5)
	{
		cout << "\n\nNominee " << i << " " << nominee.name;
		i++;
	}
	cout << "\n\n\nEnter: ";

	cin >> choice;
	system("cls");
	ofstream outvote;
	outvote.open("votecount.dat");
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
	outvote << vote;
	outvote.close();
	system("cls");

	cout << "\n\n\n\n";
	cout << "\n\t\t\t\t\t###########################";//last part
	cout << "\n\t\t\t\t\t#                         #";
	cout << "\n\t\t\t\t\t#  Thank you for voting   #";
	cout << "\n\t\t\t\t\t#                         #";
	cout << "\n\t\t\t\t\t###########################";
	cin.ignore();
	cin.get();
	system("cls");
}



void registration(info& student)
{
	system("cls");
	cout << "\t\t\t Enter the Mykad Number : ";
	cin.ignore();
	getline(cin, student.mykad);
	cout << "\t\t\t Enter the Student ID : ";
	getline(cin, student.student_id);

	ofstream f1("studentrecord.dat", ios::app);
	f1 << student.mykad << ' ' << student.student_id << endl;
	cout << "\n\t\t\t Registration is successful! \n";
	f1.close();
	cin.ignore();
	cin.get();
	system("cls");
}



void displayDetail(info& nominee)
{
	ifstream infile;
	int label = 1;
	infile.open("nominee.dat", ios::binary);
	if (!infile)
	{
		cout << "\nFile could not be opened!\n";
		return;
	}
	int i = 0;
	while (infile.read(reinterpret_cast<char*> (&nominee), sizeof(nominee)) && i != 5)
	{
		cout << "\nLabel: " << label;
		nominee.showdetail();
		i++;
		label++;
	}
	infile.close();
	cin.ignore();
	cin.get();
	system("cls");
}

void registrationMenu()
{
	system("cls");
	cout << "\t\t\t\t\t1.Register\n\n";
	cout << "\t\t\t\t\t2.Result\n\n";
	cout << "\t\t\t\t\t3.Statistic\n\n";
	cout << "\t\t\t\t\t4.Back\n\n";
}
void administrator(info& nominee, info& student, int(&vote)[5])
{
	const string adminUser[3] = { "Pangzanlam", "Lawsonshow","Karryweng" };
	const int password[3] = { 1397, 8519, 0462 };
	char username[50];
	int pw;
	char choice;

	system("cls");
	cout << "WELCOME\n";
	cout << "---------\n";
	cout << "\nEnter your username:";
	cin.ignore();
	cin >> username;
	cout << "\nEnter your password:";
	cin >> pw;

	for (int i = 0; i < 3; i++)
	{
		if (username == adminUser[i] && pw == password[i])
			cout << "\n\nWelcome";
		cin.ignore();
		cin.get();
	}
	do {
		registrationMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			registration(student);
			break;
		case '2':
			result(nominee, vote);
			break;
		case '3':
			stat(nominee, student, vote);
			break;
		case '4':
			break;
		default:
			cout << "invalid";
		}
	} while (choice != '4');
}

void voteMenu(info& nominee, int(&vote)[5])
{
	char choice;
	int checkvote = 0;
	system("cls");
	do {
		cout << "\n\n\t\t\t\t\t1. Check Nominees'Detail";
		cout << "\n\t\t\t\t\t2. Vote";
		cout << "\n\t\t\t\t\t3. Exit";
		cout << "\n\n\n\t\t\t\t\tEnter :  ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case '1':
			displayDetail(nominee);
			break;
		case '2':
			if (checkvote == 0)
			{
				castvote(nominee, vote);
				checkvote++;
			}
			else
			{
				cout << "\n\n\n\n\t\t\t\t\tYou have voted.";
				cin.ignore();
				cin.get();
				system("cls");
			}
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

void result(info& nominee, int(&vote)[5])
{
	system("cls");
	char name[50] = { 0 };
	string names[5], winner;
	int largest = 0, tie = 0;
	ifstream infile;
	infile.open("nominee.dat");
	cout << "Voting Results\n";
	cout << "\n====================================\n";
	for (int i = 0; (infile.read(reinterpret_cast<char*>(&nominee), sizeof(info))) && i < 5; i++)
	{
		cout << "\nNominee " << i + 1 << " : " << nominee.name << "\nvote : " << vote[i] << endl;
		names[i] = nominee.name;
	}
	infile.close();

	infile.open("votecount.dat");
	for (int i = 1; i < 5; i++)
	{
		infile >> vote[i];
		if (vote[0] < vote[i])
		{
			vote[0] = vote[i];
			names[0] = names[i];
		}
		if (i == 4)
		{
			cout << "\nThe Winner Is " << names[0] << "! ";
			break;
		}
	}
	cin.ignore();
	cin.get();
}

void stat(info& nominee, info& student, int(&vote)[5])
{
	int total_voter = 0, voted = 0, no_vote, male_vote = 0, fmale_vote = 0;
	float percentage;
	char gender;

	system("cls");
	ifstream infile;
	infile.open("studentrecord.dat");
	while (infile >> student.mykad >> student.student_id)
	{
		total_voter++;
	}
	infile.close();
	cout << "\nTotal number of voter: " << total_voter;

	for (int i = 0; i < 5; i++)
	{
		voted += vote[i];
	}
	no_vote = total_voter - voted;

	cout << "\nTotal number who did not vote: " << no_vote;

	percentage = (static_cast<float>(total_voter) - no_vote) / total_voter;
	cout << "\nPercentage of student who voted: " << fixed << setprecision(2) << percentage;

	cout << "\nTotal votes obtained by nominee1: " << vote[0];
	cout << "\nTotal votes obtained by nominee2: " << vote[1];
	cout << "\nTotal votes obtained by nominee3: " << vote[2];
	cout << "\nTotal votes obtained by nominee4: " << vote[3];
	cout << "\nTotal votes obtained by nominee5: " << vote[4];

	while (infile >> student.mykad)
	{
		if (student.mykad[11] != '0' || student.mykad[11] != '2' || student.mykad[11] != '4' || student.mykad[11] != '6' || student.mykad[11] != '8')
		{
			male_vote++;
		}
		if (student.mykad[11] != '1' || student.mykad[11] != '3' || student.mykad[11] != '5' || student.mykad[11] != '7' || student.mykad[11] != '9')
		{
			fmale_vote++;
		}
	}

	cout << "\nTotal votes by male: " << male_vote;

	cout << "\nTotal votes by female: " << fmale_vote;
	cin.ignore();
	cin.get();
}
