#include <iostream>
using namespace std;
#include "User.h"
#include "Vault.h"

void showMenu() // CLI Interface
{
    cout << "=== Lock Base ====\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Choose an Option\n";
}


int main()
{
    int Choice;
    string username, password;
    while (1)
    {
        showMenu();
        cin >> Choice;
        if (Choice == 1)
        {

            cout << "Username \n";
            cin >> username;
            cout << " Password \n";
            cin >> password;
            User user(username);
            if (user.registerUser(password))
            {
                cout << "User registered successfully \n";
            }
            else
            {
                cout << " Registration failed ";
            }
        }else if (Choice == 2){
            cout << "Username\n";
            cin >> username;
            cout << " Password\n";
            cin >> password;
            User user(username);
             if (user.loginUser(password))
            {
                cout << "User login successfully. \n";
                Vault vault(username, password); // master password used as encryption key
                vault.load(); // load existing credentials from file

                int vaultChoice;
                do {
                    std::cout << "\n==== Vault Menu ====\n";
                    std::cout << "1. Add Credential\n";
                    std::cout << "2. List Credentials\n";
                    std::cout << "3. Delete Credential\n";
                    std::cout << "4. Logout\n";
                    std::cout << "Choose: ";
                    std::cin >> vaultChoice;

                    if (vaultChoice == 1) {
                            Credential cred;
                            std::cout << "Service: ";
                            std::cin >> cred.service;
                            std::cout << "Username: ";
                            std::cin >> cred.username;
                            std::cout << "Password: ";
                            std::cin >> cred.password;
                            vault.addCreds(cred);
                    } else if (vaultChoice == 2) {
                            vault.listCreds();
                    } else if (vaultChoice == 3) {
                            int idx;
                            std::cout << "Index to delete: ";
                            std::cin >> idx;
                            vault.deleteCreds(idx);
                    }

} while (vaultChoice != 4);


            }
            else
            {
                cout << " Login failed. \n";
            }


        }else if(Choice == 3) {
            cout<< " Exiting LockBase.\n";
            break;
        }else{
            cout<<" Invalid Choice. \n";
        }
        
        
    }

    system("pause");
    return 0;
}