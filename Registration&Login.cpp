#include<bits/stdc++.h>
using namespace std;

class User
{
    string username, password;

public :
        User(string username, string password)
        {
            this -> username = username;
            this -> password = password;
        }

        string getUsername()
        {
            return username;
        }

        string getPassword()
        {
            return password;
        }
};

vector<User> users;

class UserManager
{
    bool check(string username)
    {
        for(auto u : users)
        {
            if(u.getUsername() == username)
                return true;
        }
        return false;
    }
public :
    void RegisterUser()
    {
        string username, password, password2;
        while(true)
        {
            jump :
            cout << "Enter User Name : ";
            cin >> username;
            if(check(username))
            {
                cout << "Username is already present" << endl;
                goto jump;
            }
            cout << "Enter Password : ";
            cin >> password;
            cout << "Confirm Password : ";
            cin >> password2;

            if(password == password2)
                break;
            else
                cout << "Confirm Password is not matching!" << endl;
        }
        cout << "User Register Successfully!" << endl;
        User newUser(username, password);
        users.push_back(newUser);
    }

    bool LoginUser(string name, string pass)
    {
        for(int i = 0; i < (int)users.size(); i++)
        {
            if(users[i].getUsername() == name && users[i].getPassword() == pass)
            {
                cout << "Login Successfully ..." << endl;
                return true;
            }
        }
        cout << "Invalid Credentials" << endl;
        return false;
    }

    void ShowUserList()
    {
        if(users.size() == 0)
        {
            cout << "No User is Present" << endl;
            return;
        }
        for(int i = 0; i < (int)users.size(); i++)
            cout << i + 1 << ". " << users[i].getUsername() << endl;
    }

    void SearchUser(string username)
    {
        for(auto u : users)
        {
            if(u.getUsername() == username)
            {
                cout << "User Found" << endl;
                return;
            }
        }
        cout << "User Not Found" << endl;
    }

    void DeleteUser(string username)
    {
        for(int i = 0; i < (int)users.size(); i++)
        {
            if(users[i].getUsername() == username)
            {
                users.erase(users.begin() + i);
                cout << "User Deleted Successfully" << endl;
                return;
            }
        }
        cout << "User Not Found" << endl;
    }
};

int main()
{
    char choice = 'y';

    while(choice == 'y' || choice == 'Y')
    {
        system("cls");
        cout << "\t Welcome to Login and Registration system by Gourav." << endl;
        cout << endl;
        cout << "Press 1. for Register User" << endl;
        cout << "Press 2. for Login" << endl;
        cout << "Press 3. for Show User List" << endl;
        cout << "Press 4. for Search User" << endl;
        cout << "Press 5. for Delete User" << endl;
        cout << "Press 6. for Exit" << endl;

        cout << "Enter Your Choice : ";

        UserManager usermanager;
        int option;
        cin >> option;

        switch(option)
        {
            case 1 :
            {
                usermanager.RegisterUser();
                break;
            }
            case 2 :
            {
                string username, password;

                cout << "Enter User Name : ";
                cin >> username;
                cout << "Enter Password : ";
                cin >> password;

                usermanager.LoginUser(username, password);
                break;
            }
            case 3 :
            {
                usermanager.ShowUserList();
                break;
            }
            case 4 :
            {
                string username;
                cout << "Enter the username which you want to find : ";
                cin >> username;

                usermanager.SearchUser(username);
                break;
            }

            case 5 :
            {
                string username;
                cout << "Enter the username which you want to delete : ";
                cin >> username;

                usermanager.DeleteUser(username);
                break;
            }
            case 6 :
            {
                cout << "Thank You!" << endl;
                return 0;
            }
            default :
            {
                cout << "Option is invalid" << endl;
                break;
            }
        }

        cout << "Do you want to continue ? [y/n]" << endl;
        cin >> choice;
    }
}
