/////////////// IN GOD'S NAME I START, BISMILLAH. ///////////////


///////////////     BANKING MANAGEMENT SYSTEM     ///////////////

// CREATED 23/5/2022 BY YOUSSEF HOSSAM

#include <iostream>
#include <cstring>
#include <fstream>



using namespace std;

int id_count = 1;



class Account
{
private:
    string first_name;
    string last_name;
    int balance;
    string total_enquiry;
    int id;


public:
    Account(string name1 = "first name", string name2 = "last name", int amount = 0)
    {
        this->first_name = name1;
        this->last_name = name2;
        this->balance = amount;
        this->id = id_count;

    }


    string FirstName()
    {
        return first_name;
    }
    string LastName()
    {
        return last_name;
    }
    int Balance()
    {
        return balance;
    }
    int Id()
    {
        return id;
    }

    void setId(string text)
    {
        int num = stoi(text);
        this->id = num;
    }
    void setFirstName(string text)
    {
        this->first_name = text;
    }
    void setLastName(string text)
    {
        this->last_name = text;
    }
    void setBalance(string text)
    {
        int num = stoi(text);
        this->balance = num;
    }


    void view_enquiry(); //done
    void deposit(int amount); //done
    void withdrawal(int amount); //done
    void display_account_info(); // done
    void erase_data(); //done

};


void Account::erase_data()
{
    first_name = " ";
    last_name = " ";
    id = 0;
    balance = 0;
    total_enquiry = " ";
}


void Account::display_account_info()
{
    cout << "Id: "<<id<<endl;
    cout << "first name: "<<first_name<<endl;
    cout << "last name: "<< last_name<<endl;
    cout << "current balance: "<<balance<<endl;
}

void Account::view_enquiry()
{
    cout << total_enquiry<<endl;
}



// put money into the account
void Account::deposit(int amount)
{
    balance += amount;

    string str = to_string(amount);


    string action = "";
    string tail2 = str + "\n";

    action += "Amount Deposited: " + tail2;
    total_enquiry += action;

}

// Remove money from the account
void Account::withdrawal(int amount)
{
    balance -= amount;

    string str = to_string(amount);

    string action = "";
    string tail2 = str + "\n";

    action += "Amount withdrawed: " + tail2;
    total_enquiry += action;

}


//                                                                  END OF CLASS                                                                                          //
// ------------------------------------------------------------------------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------------------------------------------------------------------------ //
//                                                                  START OF MAIN


void show_all_accounts();



Account *accounts = new Account[20];
int total_accounts = 0;



// to control the recursive behavior
bool scanned = false;

// to control the logo text :D
bool flagged = false;

int main()
{
    if (!scanned)
    {
        // open a file as an input to get account info from
        ifstream data("accounts_data.txt");
        string text;

        // making a temporary object to store the attributes in
        Account tmp;
        // this is very important as it is the logic behind the data extraction
        int counter = 0; // to keep track of the lines read
        while (getline(data, text)) // while there are lines in the txt file i.e. loops 4x the number of accounts in it
        {
            counter++;
            if (counter % 4 == 1)
            {   // store first line as id
                tmp.setId(text);
            }
            else if (counter % 4 == 2)
            {   // stores second line as first name
                tmp.setFirstName(text);
            }
            else if (counter % 4 == 3)
            {   // stores third line as last name
                tmp.setLastName(text);
            }
            else if (counter % 4 == 0)
            {   // stores fourth line as balance
                tmp.setBalance(text);
                // keep track of the accounts ids an number and order in array
                id_count++;
                accounts[total_accounts] = tmp; // store the temporary object in my array
                total_accounts++;
                // cout << "added"<<endl;
                // cout << id_count<<endl;
                // cout << total_accounts<<endl;
            }

        }
        scanned = true; // no need to scan it the next loop after the recursive main() function

        data.close(); // finally close the file :)
    }



    if (!flagged)
    {
        cout << "-------Banking system-------"<<endl;
        flagged = true;
    }


    cout << endl;
    cout << "1.Open an account"<<endl;
    cout << "2.Balance enquiry"<<endl;
    cout << "3.Account info"<<endl;
    cout << "4.Deposit"<<endl;
    cout << "5.Withdraw"<<endl;
    cout << "6.Close an account"<<endl;
    cout << "7.Show all accounts"<<endl;
    cout << "8.Quit"<<endl;

    int choice;
    cin >> choice;
    if (choice == 1)
    {

        string name1;
        cout << "First name: ";
        cin >> name1;

        string name2;
        cout << "Last name: ";
        cin >> name2;

        int amount;
        cout << "Initial amount: ";
        cin >> amount;

        Account tmp(name1, name2, amount);
        cout << "Account created successfully!"<<endl<<"Account id: "<< tmp.Id()<<endl;
        id_count++;
        accounts[total_accounts] = tmp;
        total_accounts++;

    }

    else if (choice == 2)
    {
        int id;
        cout << "Enter account's id: ";
        cin >> id;
        for(int i=0;i<id_count-1;i++)
        {
            if (id == accounts[i].Id())
            {
                accounts[i].view_enquiry();
                break;
            }
        }
    }

    else if (choice == 3)
    {
        int id;
        cout << "Enter account's id: ";
        cin >> id;
        for(int i=0;i<id_count-1;i++)
        {
            if (id == accounts[i].Id())
            {
                accounts[i].display_account_info();
                break;
            }
        }
    }

    else if (choice == 4)
    {
        int id;
        int amount;
        cout << "Enter account's id: ";
        cin >> id;
        cout << "Enter Amount to deposit: ";
        cin >> amount;
        for(int i=0;i<id_count-1;i++)
        {
            if (id == accounts[i].Id())
            {
                accounts[i].deposit(amount);
                break;
            }
        }
    }

    else if (choice == 5)
    {
        int id;
        int amount;
        cout << "Enter account's id: ";
        cin >> id;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        for(int i=0;i<id_count-1;i++)
        {
            if (id == accounts[i].Id())
            {
                if (amount <= accounts[i].Balance())
                {
                    accounts[i].withdrawal(amount);
                    break;
                }
                else
                {
                    cout << "Amount to withdraw is more than the balance"<<endl;
                    break;
                }

            }
        }

    }

    else if (choice == 6)
    {
        int id;
        cout << "Enter account's id: ";
        cin >> id;
        for(int i=0;i<id_count-1;i++)
        {
            if (id == accounts[i].Id())
            {
                accounts[i].erase_data();
                break;
            }
        }
    }

    else if (choice == 7)
    {

    }

    else if (choice == 8)
    {
        ofstream data0("accounts_data.txt", ios::trunc);
        for (int i=0;i<total_accounts;i++)
        {
            data0 << accounts[i].Id()<<endl;
            data0 << accounts[i].FirstName()<<endl;
            data0 << accounts[i].LastName()<<endl;
            data0 << accounts[i].Balance()<<endl;
        }

        return 0;
    }





    if (scanned)
    {
        main();
    }


}
