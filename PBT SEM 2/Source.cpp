#include<iostream>//PreProcessor
#include<ctime>//Library for time
using namespace std;
//Line 5-7 is function prototype
float z(float, int);
float w(float, int);
float q(float, int);
//data struct for maklumat
struct maklumat
{
	char first[15];
	char last[15];
	char nama_id[10];
};
maklumat pekerja;
void main()//main function
{
	//declare variable
	int password = 1996;
	char choice;
	int hours;
	int minit;
	float hourly_wage = 30;

	int *jam;//pointer
	jam = &hours;
	//User must key in password first
	cout << "Enter your Password:";
	cin >> password;

	if (password == 1996)
	{
		goto LogInSuccess;
	LogInSuccess:
		cout << "password accepted !!\n" << endl;;
	}
	else
	{
		for (int pass = 1; pass < 3; ++pass)
		{
			cout << "wrong password ,please key in password again :";
			cin >> password;
			if (password == 1996)
				goto LogInSuccess;//if success ,user can continue use this program
			else
				continue;
		}
		goto LogInFailed;//If password is wrong,it will terminated


	}
	time_t now = time(0);//calculate time
	char*dt = ctime(&now);
	cout << "Log in on ->  " << dt << endl;

	cout << "\t\t============================================\t\t\n";
	cout << "\t\tWELCOME TO VERTEX SALARY CALCULATION PROGRAM\t\t\n";
	cout << "\t\t============================================\t\t\n";

	//using looping do while
	{
		do
		{
			cout << "\t\t----Input Data Item----\t\t\n" << endl;//this is input data item
			cout << "Enter the Programmer's first and last name (ie. NAZRUL HAKIM): ";//input first and last name
			cin >> pekerja.first >> pekerja.last;//input from data struct

			cout << "Programmer's ID		: ";
			cin >> pekerja.nama_id;//input from data struct
			cout << "Enter Hours worked	: ";
			cin >> *jam;//input from pointer



			if (hours >= 40)//using if else
			{
				cout << "----Output Data Item----\n" << endl;

				cout << "Programmer	-> " << pekerja.first << "" << pekerja.last << endl;//from input data struct
				cout << "Programmer's ID	->" << pekerja.nama_id << endl;
				minit = *jam * 60;//input from pointer
				cout << "Time worked	->" << *jam << " hours " << ", " << minit << " minutes" << endl;//input from pointer
				cout << "Hourly wage	->" << hourly_wage << endl;
				cout << "============================================\n";
				cout << "The computed pay is = RM" << z(hourly_wage, hours) << endl;//input from function prototype
				cout << "Thank You !" << endl;
				cout << "============================================" << endl;

			}
			else if (hours < 40 && hours >= 30)
			{
				cout << "----Output Data Item----\n" << endl;

				cout << "Programmer	-> " << pekerja.first << "" << pekerja.last << endl;//from input data struct
				cout << "Programmer's ID	->" << pekerja.nama_id << endl;
				minit = *jam * 60;
				cout << "Time worked	->" << *jam << " hours " << ", " << minit << " minutes" << endl;
				cout << "Hourly wage	->" << hourly_wage << endl;
				cout << "============================================\n";
				cout << "The computed pay is:           = RM" << q(hourly_wage, hours) << endl;
				cout << "Thank You !" << endl;
				cout << "============================================" << endl;

			}
			else
			{
				cout << "----Output Data Item----\n" << endl;

				cout << "Programmer	-> " << pekerja.first << "" << pekerja.last << endl;//from input data struct
				cout << "Programmer's ID	->" << pekerja.nama_id << endl;
				minit = *jam * 60;
				cout << "Time worked	->" << *jam << " hours " << ", " << minit << " minutes" << endl;
				cout << "Hourly wage	->" << hourly_wage << endl;
				cout << "============================================\n";
				cout << "The computed pay is:           = RM" << w(hourly_wage, hours) << endl;
				cout << "Thank You !" << endl;
				cout << "============================================" << endl;
			}

			cout << "Do you want continue ? y/n \n" << endl;
			cin >> choice;
			cout << endl;

		} while (choice != 'n' && choice != 'N');
		
	}
	
LogInFailed:
	cout << "\t\tTHANK YOU FOR USING THIS PROGRAM !!\t\t\n" << endl;;

	system("pause");
}
float z(float hourly_wage, int hours)
{
	float computed_pay;
	computed_pay = hourly_wage * hours*(1.3);
	return (computed_pay);
}
float q(float hourly_wage, int hours)
{
	float computed_pay;
	computed_pay = hourly_wage * hours *(1.1);
	return (computed_pay);
}
float w(float hourly_wage, int hours)
{
	float computed_pay;
	computed_pay = hourly_wage * hours;
	return (computed_pay);
}