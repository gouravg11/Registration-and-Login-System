#include <bits/stdc++.h>
#include <sstream>
#include <windows.h>

using namespace std;


class Login
{
    string id, password;

public :

    Login() : id(""), password(""){}

    void setId(string id)
    {
        this -> id = id;
    }

    void setPassword(string password)
    {
        this -> password = password;
    }

    string getId()
    {
        return id;
    }

    string getPassword()
    {
        return password;
    }
};

void registration(Login user)
{
    system("cls");
    string id, pw;

    cout << "Enter User ID : ";
    cin >> id;

    cout << "Enter Password : ";
    cin >> pw;

    user.setId(id);
    user.setPassword(pw);

    ofstream outfile("C:/Users/ggupt/OneDrive/Documents/MyCodes/Data.txt", ios :: app); // if we use ios :: app then we can save as many
                                                                                        // user as we can else only one user will be there

    if(!outfile)
    {
        cout << "Error : File Can't Open" << endl;
    }
    else
    {
        outfile << user.getId() << " : " << user.getPassword() << endl;
        cout << "User Registered Successfully" << endl;
    }
    outfile.close();
    Sleep(2000);
}

void login()
{
    system("cls");

    string id, pw;

    cout << "Enter your User ID : ";
    cin >> id;

    cout << "Enter your Password : ";
    cin >> pw;

    ifstream infile("C:/Users/ggupt/OneDrive/Documents/MyCodes/Data.txt");

    if(!infile)
    {
        cout << "Error : File Can't Open" << endl;
    }
    else
    {
        string line;
        bool found = false;

        while(getline(infile, line))
        {
            stringstream ss;
            ss << line;

            string userid, userpw;

            char delimiter;

            ss >> userid >> delimiter >> userpw;

            if(id == userid && pw == userpw)
            {
                found = true;
                cout << "Welcome to the Page" << endl;
            }
        }

        if(found == false)
        {
            cout << "Invalid Credentials" << endl;
        }

        infile.close();
    }
    Sleep(2000);
}

void print_users()
{
    system("cls");

    ifstream infile("C:/Users/ggupt/OneDrive/Documents/MyCodes/Data.txt");

    string line;
    int i = 1;

    while(getline(infile, line))
    {
        stringstream ss;
        ss << line;

        string userId, userPw;

        char delimeter;

        ss >> userId >> delimeter >> userPw;

        if(userId == "")
            continue;

        cout << i++ << "." << userId << " " << userPw << endl;
    }
    Sleep(2000);
}

int main()
{
    Login user;

    while(true)
    {
        system("cls");

        cout << "Welcome To Registration & Login System" << endl;
        cout << "Press 1. for Register" << endl;
        cout << "Press 2. for Login" << endl;
        cout << "Press 3. for User List" << endl;
        cout << "Press 4. for Exit" << endl;

        cout << "Enter Choice : ";
        int val;
        cin >> val;

        if(val == 1)
            registration(user);
        else if(val == 2)
            login();
        else if(val == 3)
        {
            print_users();
        }
        else if(val == 4)
        {
            cout << "Thank You!" << endl;
            break;
        }
    }
    Sleep(1000);
}
