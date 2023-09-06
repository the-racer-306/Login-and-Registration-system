#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void login();

void registration();

void forgot();

int main()
{
  int c;
  cout << "\t\t\t______________________________________________________________\n\n\n";
  cout << "\t\t\t                   Welcome to the Login Page                  \n\n\n";
  cout << "\t\t\t_______________________       MENU      _______________________\n\n\n";
  cout << "\t\t\t                                                                \n\n\n";
  cout << "\t | Press 1 to LOGIN                         | " << endl;
  cout << "\t | Press 2 to Register                      | " << endl;
  cout << "\t | Press 3 to If you forgot your password   | " << endl;
  cout << "\t | Press 4 to EXIT                          | " << endl;
  cout << "\n\t\t Please enter your choice               | " << endl;
  cin >> c;
  cout << endl;

  switch (c)
  {
  case 1:
    login();
    break;

  case 2:
    registration();
    break;
  case 3:
    forgot();
    break;
  case 4:
    cout << "\t\t\t THANK YOU! \n\n";
    break;
  default:
    system("cls");
    cout << "please select from the option given above \n"
         << endl;
    main();
  }
}

void login()
{
  int count;
  string userId, password, id, pass;
  system("cls");
  cout << "\t\t\t please enter the username and password : " << endl;
  cout << "\t\t\t USERNAME : ";
  cin >> userId;
  cout << "\t\t\t PASSWORD : ";
  cin >> password;

  ifstream input("records.txt");

  while (input >> id >> pass)
  {
    if (id == userId && pass == password)
    {
      count = 1;
      system("cls");
    }
  }
  input.close();
  if (count == 1)
  {
    cout << userId << "\n Your LOGIN is succecssful \n Thanks for Logging in! \n";
    main();
  }
  else
  {
    cout << "\n LOGIN ERROR \n please check your username and password \n";
    main();
  }
}

void registration()
{
  string ruserId, rpassword, rid, rpass;
  system("cls");
  cout << "\t\t\t Enter the username : ";
  cin >> ruserId;
  cout << "t\t\t Enter the password : ";
  cin >> rpassword;

  ofstream f1("records.txt", ios::app);
  f1 << ruserId << " " << rpassword << endl;
  system("cls");
  cout << "\n\t\t\t Registration is successful! \n";
  main();
}

void forgot()
{
  int option;
  system("cls");
  cout << "\t\t\t Your forgot the password? no worries \n";
  cout << "press 1 to search to your id by username " << endl;
  cout << "press 2 to go back to the main menu" << endl;
  cout << "\t\t\t Enter Your choice ! : ";
  cin >> option;
  switch (option)
  {
  case 1:
  {
    int count = 0;
    string suserId, sId, spass;
    cout << "\n\t\t\t Enter the username which you remembered : ";
    cin >> suserId;
    ifstream f2("records.txt");
    while (f2 >> sId >> spass)
    {
      if (sId == suserId)
      {
        count = 1;
      }
    }
    f2.close();
    if (count == 1)
    {
      cout << "\n\n Your account is found! \n";
      cout << "\n\n Your password is : " << spass;
      main();
    }
    else
    {
      cout << "\n\t Sorry your account is not found! \n";
      main();
    }
    break;
  }
  case 2:
  {
    main();
  }

  default:
    cout << "\t\t\t Wrong choice Please Try Again! " << endl;
    forgot();
  }
}