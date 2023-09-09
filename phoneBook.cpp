#include<iostream>
#include<map>
#include <cstring>
#include <algorithm>
using namespace std;

map<string, string> mp;//mp[name] = Mob;
map<int, int> mp2;
map<float, int> mp3;

// Create a contact class having data member as Name and number
class Contact
{
    string Name;
    string Mob;

public:
    friend class StudentDTU;
    // Initialize the Contact by a default value
    Contact()
    {
        Name = "";
        Mob = "";
    }
    ~Contact()
    {
    }
    string getName()
    {
        return Name;
    }
    string getMob()
    {
        return Mob;
    }
    void getData()
    {
        cout << "Name : " << Name << "\t\t\t"
             << "Mobile no : " << Mob << endl;
    }

    // The Contact object is initialized by valid values
    bool add(string New_Name, string New_Num)
    {
        if (Name == "") // If contact is not initialized by any value other than default value then add new contact
        {
            Name = New_Name;
            Mob = New_Num;
            return 1; // Success
        }
        else
            return 0; // Failure
    }
    // Shows Contacts
    bool show()
    {
        if (Name != "")
        {
            cout << "Name : " << Name << "\t\t\t"
                 << "Mob No: " << Mob << endl;
            return 1; // Indicates success
        }
        return 0; // Indicates failure
    }

    // Search
    bool show(string search_term)
    {
        if (search_term == Name)
        {
            cout << "Name : " << Name << endl
                 << "Mobile Number: " << Mob << endl;
            return 1;
        }
        else
            return 0;
    }
    bool show2(string search_term)
    {
        transform(search_term.begin(), search_term.end(), search_term.begin(), ::tolower);
        string s2 = Name;
        int k = 0;
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        if (Name == "")
        {
            return 0;
        }
        for (int i = 0; i < Name.size() - search_term.size(); i++)
        {
            if (s2.substr(i, search_term.size()) == search_term)
            {
                k = 1;
                // cout<<"Name : "<<Name<<endl;
                return 1; // success
            }
        }
        return 0; // failure
    }

    // Checks whether the Name exists or not
    bool Name_exists(string Cont_Name)
    {
        if (Cont_Name == Name)
            return 1;
        else
            return 0;
    }

    // Edits the Contact details
    bool edit(string);

    // Sets the Contact details to default values
    // That is, the Contact details are thus erased
    bool erase(string New_Name)
    {
        if (New_Name == Name)
        {
            mp.erase(Name);
            Name = "";
            Mob = "";
            return 1;
        }
        else
            return 0;
    }
};

// Edits the Contact
bool Contact ::edit(string New_Name)
{
    string New_Num;
    if (New_Name == Name)
    {
        mp.erase(New_Name);
        cout << "Enter new Name: ";
        cin >> New_Name;

        cout << "Enter new Mobile no: ";
        cin >> New_Num;
        mp[New_Name] = New_Num;

        Name = New_Name;
        Mob = New_Num;
        return 1;
    }
    else
        return 0;
}

// Function to prints a line
void Print_Line(char ch, int size)
{
    for (int i = 0; i < size; i++)
        cout << ch;
    cout << "\n";
}

// check if Contact Name is valid or not
bool Check_Name_Valid(string Cont_Name)
{

    if (Cont_Name.size() > 20)
    {
        cout << "Invalid Name!\nEnter a Name within 20 characters!" << endl;
        return 0;
    }
    else if (Cont_Name == "")
    {
        cout << "Invalid Name!\nName cannot be blank!" << endl;
        return 0;
    }
    else
        return 1;
}

// Mobile number validation
bool Check_Mob_No_Valid(string tMob)
{
    if (tMob.size() > 12 || tMob.size() < 10)
    {
        cout << "Invalid Mobile no.\nEnter a no."
                "between 10 and 12 digits"
             << endl;
        return 0;
    }
    else if (tMob == "")
    {
        cout << "Invalid Mobile no.\nMobile"
                "no cannot be blank"
             << endl;
        return 0;
    }
    else
        return 1;
}

void Show_Alph_Order(map<string, string> mp)
{
    if (mp.size() == 0)
    {
        cout << "No contact found " << endl;
    }
    for (auto m : mp)
    {
        cout << "Name : " << m.first << "\t\t\t"
             << "Mobile number : " << m.second << endl;
    }
}

class StudentDTU : virtual private Contact
{
    int roll_No;
    int rank;
    float cgpa;

public:
    friend int getTotal();
    int scholarshipAmount;
    friend class Topper;
    float getCgpa()
    {
        return cgpa;
    }
    StudentDTU()
    {
        roll_No = 0;
        rank = 0;
        cgpa = 0;
        Name = "";
        Mob = "";
        scholarshipAmount = 0;
    }

    void editDataName(int rn)
    {
        string ng;
        cout << "Enter name to edit" << endl;
        cin >> ng;
        Name = ng;
        cout << "previous mobile number  : " << Mob << endl;
        string ing;
        cout << "Enter mobile no to edit" << endl;
        cin >> ing;
        Mob = ing;
    }
    void setData(int i)
    {
        string st, mobNo;
        cout << "Enter the name " << endl;
        cin >> st;
        if (mp.find(st) != mp.end())//mp[Name] = Mob
        {
            cout << "suggested contact number is :" << mp[st] << endl;
        }
        cout << "Enter the roll_No" << endl;
        cin >> roll_No;
        while (roll_No == 0)
        {
            cout << "roll number can not be zero, enter again" << endl;
            int a;
            cin >> a;
            roll_No = a;
        }
        while (mp2.find(roll_No) != mp2.end())
        {
            cout << "Roll number already exist, enter again" << endl;
            int a;
            cin >> a;
            roll_No = a;
        }
        cout << "Enter the rank" << endl;
        cin >> rank;
        cout << "Enter the average CGPA" << endl;
        cin >> cgpa;
        cout << "Enter the mobile number " << endl;
        cin >> mobNo;
        mp2[roll_No] = i;
        mp3[cgpa] = i;
        add(st, mobNo);
    }
    void editData(int i)
    {
        int rn, rnk;
        float cgp;
        string str;
        mp2.erase(roll_No);
        mp3.erase(cgpa);
        cout << "Enter the new roll_No" << endl;
    ROLL_NO:
        cin >> rn;
        if (rn == 0)
        {
            cout << "Roll number can not be zero, enter roll number again" << endl;
            goto ROLL_NO;
        }
        roll_No = rn;
        cout << "Enter the new rank" << endl;
        cin >> rnk;
        rank = rnk;
        cout << "Enter the new average CGPA" << endl;
        cin >> cgp;
        cgpa = cgp;
        cout << "Enter the new name of student" << endl;
        cin >> str;
        Name = str;
        mp2[roll_No] = i;
        mp3[cgpa] = i;
        string a;
    MOB_NO:
        cout << "Enter the new mobile number of the student " << endl;
        cin >> a;
        if (a.size() < 10 && a.size() > 12)
        {
            cout << "Invalid number, enter again" << endl;
            goto MOB_NO;
        }
        Mob = a;
    }
    int getRoll_No()
    {
        return roll_No;
    }
    void getData()
    {
        cout << "Roll number : " << roll_No << endl;
        cout << "rank : " << rank << endl;
        cout << "cgpa : " << cgpa << endl;
        cout << "Name : " << Name << endl;
        cout << "Mobile No : " << Mob << endl;
        if (scholarshipAmount!=0)
        {
            cout << "Brilliat student , He got scholarship of : " << scholarshipAmount << endl;
        }
        if (scholarshipAmount==0)
        {
            cout << "average student , He got scholarship of : " << scholarshipAmount << endl;
        }
    }
    StudentDTU operator+(StudentDTU sd)
    {
        StudentDTU s;
        s.scholarshipAmount = scholarshipAmount + sd.scholarshipAmount;
        return s;
    }
    void setSCA(int sca)
    {
        scholarshipAmount = sca;
    }
};


StudentDTU sDTU[100];
int getTotal()
{
    StudentDTU s1;
    s1.scholarshipAmount = 0;
    for (int i = 0; i < mp3.size() ; i++)
    {
        s1.scholarshipAmount = sDTU[i].scholarshipAmount + s1.scholarshipAmount;
    }
    return s1.scholarshipAmount;
}
class Topper :virtual private Contact, public StudentDTU
{
    int amountOfScholarship;
    int n;

public:
    Topper()
    {
        n = 0;
        amountOfScholarship = 0;
    }
    void getStudent()
    {
        cout << "Enter the number of student to select for scholarship" << endl;
        int d;
        cin >> d;
        n = d;
        if (mp3.size() < n)
        {
            cout << "The number of students in college are less than the number you entered" << endl;
            n = mp3.size();
        }
        int i = 0;
        d = n;
        map<float, int>::iterator it = mp3.end();//cgpa , integer -> index
        while (d--)
        {
            it--;
            i++;
            cout << i << ".)" << sDTU[it->second].getName() << ",\t\t\t"
                 << "cgpa : " << sDTU[it->second].getCgpa() << endl;
        }
        cout << "Enter 1 if you want to set scholarship amount else 0" << endl;
        int scA;
        cin >> scA;
        if (scA == 1)
        {
            cout << setScholarship() << endl;
        }
    }
    int setScholarship()
    {
        if (!n)
        {
            cout << "Enter number of students you want for scholarship" << endl;
            int w;
            cin >> w;
            n = w;
        }
        map<float, int>::iterator it2 = mp3.end();
        int j = 0;
        int x = n;
        try
        {
            if(x>mp3.size()){
                x = mp3.size();
                throw x;
            }
        }
        catch(int x)
        {
            cout<<"The number you entered is mpre than number of students"<<endl;
            x = mp3.size();
        }
        
        while (x--)
        {
            it2--;
            cout << j << ".)" << sDTU[it2->second].getName() << ",\t\t\t"
                 << "cgpa : " << sDTU[it2->second].getCgpa() << endl;
            cout << "Enter scholarship amount for this student : " << endl;
            int sar;
            cin >> sar;
            sDTU[it2->second].setSCA(sar);
            amountOfScholarship += sar;
        }
        cout << "Your total scholarship amount is ";
        // amountOfScholarship = amountScholarship;
        return amountOfScholarship;
    }
};

int main()
{
    Topper tmp;
    Contact Person[100];

    string Temp_Name, Temp_Mob;
    int choice, i, counter;
    bool flag;
    bool cancel_flag;

    cout << "**** PHONEBOOK ****" << endl;

    do
    {
    Phonebook:
        cout << "\n\n\n";
        Print_Line('-', 20);
        cout << "0. Show Contacts" << endl
             << "1. Show Contacts in Albhabetical order" << endl
             << "2. Add Contact" << endl
             << "3. Edit Contact" << endl
             << "4. Delete Contact" << endl
             << "5. Search" << endl
             << "6. search by less term" << endl
             << "7. move in college directory" << endl
             << "8. Quit" << endl
             << endl
             << "Your choice...";
        cin >> choice;
        while (!cin)
        {
            system("clear");
            cout << "Error,,...Please Enter a valid number.. " << endl;
            cin.clear();
            cin.ignore();
            goto Phonebook;
        }

        system("clear");
        Print_Line('-', 20);
        cancel_flag = 0;
        flag = 0;
        int x = 0;
        counter = 0;

        switch (choice)
        {
        case 0:
            cout << "Showing lists of Contacts" << endl;
            Print_Line('-', 20);

            for (i = 0; i < 100; i++)
                if (Person[i].show())
                    x = 1;

            if (x == 0)
                cout << "No Contacts found!" << endl;
            break;
        case 1:
            cout << "Showing contacts in albhabetical order " << endl;
            Show_Alph_Order(mp);
            break;

        case 2:
            cout << "Add New Contact\t\t\t\tpress # to cancel" << endl;
            Print_Line('-', 20);
            counter = 0;

            // Loop until correct Name and Mobile number are entered
            do
            {
                flag = 0;
                if (counter)
                    cout << "Try again\t\t\t\tpress # to cancel"
                         << endl;

                // counts how many times the do-while loop executes
                counter++;

                cout << "Name: ";
                cin >> Temp_Name;

                // Cancel operation
                if (Temp_Name == "#")
                {
                    cancel_flag = 1;
                    break;
                }
                cout << "Mobile No.: ";
                cin >> Temp_Mob;

                // Cancel operation
                if (Temp_Mob == "#")
                {
                    cancel_flag = 1;
                    break;
                }

                // Check whether Name exists
                for (i = 0; i < 100; i++)
                    if (Person[i].Name_exists(Temp_Name))
                    {
                        cout << "The Name you entered is already there"
                                "in the phonebook, enter a different Name."
                             << endl;
                        flag = 1;
                        break;
                    }

            } while (!Check_Name_Valid(Temp_Name) || flag || !Check_Mob_No_Valid(Temp_Mob));

            if (cancel_flag)
            {
                system("clear");
                break;
            }

            // This code adds the Contact to phonebook
            for (i = 0; i < 100; i++)
                if (Person[i].add(Temp_Name, Temp_Mob))
                {
                    mp[Temp_Name] = Temp_Mob;
                    cout << "Contact added successfully!" << endl;
                    flag = 1;
                    break;
                }

            if (!flag)
                cout << "Memory full! Delete some Contacts first."
                     << endl;
            break;

        case 3:
            cout << "Enter a Contact Name to edit:"
                    "\t\t\t\tpress # to cancel\n";
            cin >> Temp_Name;

            // Cancel the Edit Operation
            if (Temp_Name == "#")
            {
                system("clear");
                break;
            }

            for (i = 0; i < 100; i++)
                if (Person[i].edit(Temp_Name))
                {
                    cout << "Edited Successfully!" << endl;
                    flag = 1;
                    break;
                }

            if (!flag)
                cout << "Contact Name not found!" << endl;
            break;

        case 4:
            do
            {
                if (counter)
                    cout << "Try again" << endl;
                counter++;
                cout << "Enter a Contact Name to delete:"
                        "\t\t\tpress # to cancel\n";
                cin >> Temp_Name;

                // Cancel Operation
                if (Temp_Name == "#")
                {
                    system("clear");
                    break;
                }

                // Final Confirmation
                for (i = 0; i < 100; i++)
                    if (Person[i].Name_exists(Temp_Name))
                    {
                        flag = 1;
                        cout << "Are you sure you want to delete? (1/0)"
                             << endl;
                        int yes;
                        cin >> yes;
                        if (!yes)
                        {
                            system("clear");
                            cancel_flag = 1;
                        }
                        break;
                    }

                if (!flag)
                    cout << "Contact Name not found!" << endl;

                if (cancel_flag)
                    break;

                // This code deletes the Contact
                if (flag)
                {
                    for (i = 0; i < 100; i++)
                        if (Person[i].erase(Temp_Name))
                        {
                            cout << "Deleted successfully!" << endl;
                            break;
                        }
                }

            } while (!flag);
            break;

        case 5:
            do
            {
                if (counter)
                    cout << "Try again" << endl;
                counter++;
                cout << "Search a Name: \t\t\t\tpress # to cancel\n";
                cin >> Temp_Name;

                // Cancel Operation
                if (Temp_Name == "#")
                {
                    system("clear");
                    break;
                }

                for (i = 0; i < 100; i++)
                    if (Person[i].show(Temp_Name))
                    {
                        flag = 1;
                        break;
                    }

                if (!flag)
                    cout << "Contact Name not found" << endl;
            } while (!flag);

            break;
        case 6:
            // string temp;
            {
                cout << "Enter name to search " << endl;
                cin >> Temp_Name;
                int k = 0;
                for (int i = 0; i < 100; i++)
                {
                    if (Person[i].show2(Temp_Name))
                    {
                        if (k == 0)
                        {
                            cout << "Your suggestted contacts are :\n";
                        }
                        k = 1;
                        Person[i].getData();
                        x = 1;
                    }
                }
                if (!x)
                {
                    cout << "No contacts is suggested " << endl;
                }
                break;
            }

        case 7:
            goto DTU;
            break;
        case 8:
            return 0;
            break;
        default:
            cout << "Enter proper number " << endl;
            break;
        }
    } while (1);

// getch();
DTU:
    // StudentDTU sDTU[100];
    int input;

    do
    {
    STUDENT:
        cout << "0. For setData" << endl;
        cout << "1. For editData" << endl;
        cout << "2. For print Data" << endl;
        cout << "3. print the Data of all students" << endl;
        cout << "4. For edit name" << endl;
        cout << "5. goto phonebook directory" << endl;
        cout << "6. Find topper students" << endl;
        cout << "7. Set scholarship amount" << endl;
        cout << "8. get scholarship amount" << endl;
        cout << "9. Quit" << endl;
        cout << "Your choice..." << endl;
        cin >> input;
        while (!cin)
        {
            system("clear");
            cout << "Error,,...Please Enter a valid number.. " << endl;
            cin.clear();
            cin.ignore();
            goto STUDENT;
        }
        system("clear");
        Print_Line('-', 20);
        flag = 0;
        int x = 0;
        switch (input)
        {
        case 0:
            Print_Line('-', 20);
            counter = 0;

            for (i = 0; i < 100; i++)
                if (!sDTU[i].getRoll_No())
                {
                    sDTU[i].setData(i);
                    flag = 1;
                    break;
                }

            if (!flag)
                cout << "Memory full! Delete some Contacts first." << endl;
            break;
        case 1:
            cout << "Enter the roll number to edit for " << endl;
            int a;
            cin >> a;
            for (i = 0; i < 100; i++)
                if (sDTU[i].getRoll_No() == a)
                {
                    sDTU[i].editData(i);
                    flag = 1;
                    break;
                }
            if (!flag)
            {
                cout << "No such roll number exist " << endl;
            }
            break;
        case 2:
            cout << "Enter roll number to print " << endl;
            int e;
            cin >> e;
            for (i = 0; i < 100; i++)
                if (sDTU[i].getRoll_No() == e)
                {
                    sDTU[i].getData();
                    flag = 1;
                    break;
                }
            if (!flag)
            {
                cout << "No such roll number exist " << endl;
            }
            break;
        case 3:
            cout << "All the name and roll number of the students :" << endl;
            for (auto it : mp2)
            {
                // cout<<"Name : "<<it.second<<"\t\t\t"<<it.first<<endl;
                sDTU[it.second].getData();
                cout << "\n";
                flag = 1;
            }
            if (!flag)
            {
                cout << "No data for any students " << endl;
            }
            break;
        case 4:
            cout << "Enter roll number to edit name" << endl;
            int b;
            cin >> b;
            for (int i = 0; i < 100; i++)
            {
                if (sDTU[i].getRoll_No() == b)
                {
                    sDTU[i].editDataName(b);
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                cout << "This roll number does not exist" << endl;
            }
            break;
        case 5:
            goto Phonebook;
            break;
        case 6:
            tmp.getStudent();
            break;
        case 7:
        {
            cout << tmp.setScholarship() << endl;
            break;
        }
        case 8:
            cout<<"Total scholarship amount is : "<<getTotal()<<endl;
            break;
        case 9:
            return 0;
            break;

        default:
            cout << "Enter proper number" << endl;
            break;
        }

    } while (1);
    return 0;
}