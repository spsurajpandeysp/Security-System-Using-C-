#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    int choice,i=0;
    string text, old ,password1,password2, pass,name ,password0, user,word,word1;
    string creds[2], cp[2],age;

    cout<<"       Security System             "<<endl;

    cout<<"___________________________________"<<endl;
    cout<<"               1. Register         "<<endl;
    cout<<"               2. Login            "<<endl;
    cout<<"               3. Change Password  "<<endl;
    cout<<"               4. End Program      "<<endl;
    cout<<"___________________________________"<<endl;

    do
    {
        cout<<endl<<endl;
        cout<<"Enter your choice:- "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"_____________________________"<<endl;
                cout<<"          Register           "<<endl;
                cout<<"_____________________________"<<endl;
                cout<<"Please Enter Username:- "<<endl;
                cin>>name;
                cout<<"Please Enter the Password:- "<<endl;
                cin>>password1;
                cout<<"Please Enter Your Age:- "<<endl;
                cin>>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open())
                {
                    of1<<name<<"\n";
                    of1<<password1;
                    cout<<"Reistration Successfull"<<endl;
                }
                break;
            }
            case 2:
            {
                    i=0;

                    cout<<"___________________________________"<<endl;
                    cout<<"               Login               "<<endl;
                    cout<<"___________________________________"<<endl;

                    ifstream of2;
                    of2.open("file.txt");
                    cout<<"Please enter the username:-"<<endl;
                    cin>>user;
                    cout<<"Please Enter the password:- "<<endl;
                    cin>>pass;

                    if(of2.is_open())
                    {
                        while(!of2.eof())
                        {
                            while(getline(of2, text))
                            {
                                while(getline(of2, text))
                                {
                                    istringstream iss(text);
                                    iss>>text;
                                    creds[i]=word;
                                    i++;
                                }

                                if(user==creds[0] &&pass==creds[1])
                                {
                                    cout<<"     Log in Successfull     "<<endl;
                                    cout<<endl<<endl;

                                    cout<<"      Details:     "<<endl;
                                    cout<<"Username:- "<<name<<endl;
                                    cout<<"Password:- "<<pass<<endl;
                                    cout<<"Age: "<<age<<endl;
                                }
                                else
                                {
                                    cout<<endl<<endl;
                                    cout<<"Incorrect Credentials"<<endl;
                                    cout<<"       1. Press 2 Login                  "<<endl;
                                    cout<<"       2. Press 3 to change the password "<<endl;
                                    break;
                                }
                            }
                        }
                    }
                    break;
            }
            case 3:
            {
                    cout<<"__________________________________________"<<endl;
                    cout<<"           Change Password                "<<endl;
                    cout<<"__________________________________________"<<endl;

                    ifstream of0;
                    of0.open("file.txt");
                    cout<<"Enter the old password:- ";
                    cin>>old;
                    if(of0.is_open())
                    {
                    while(of0.eof())
                    {
                        while(getline(of0, text))
                        {
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }

                        if(old==cp[1])
                        {
                            of0.close();

                            ofstream of1;
                            if(of1.is_open())
                            {
                                cout<<"Enter your new password:-";
                                cin>>password1;
                                cout<<"Enter your password again:-";
                                cin>>password2;

                                if(password1==password2)
                                {
                                    of1<<cp[0]<<"\n";
                                    cout<<"Password change successfully:-"<<endl;
                                }
                                else
                                {
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password do not match"<<endl;
                                }
                            }
                        
                        }
                        else
                        {
                            cout<<"Please enter a valid password"<<endl;
                            break;
                        }
                        }
                    }
                    break;
                }
                case 4:
                {
                    cout<<"____________________________________________"<<endl;
                    cout<<"            Thankyou!                       "<<endl;
                    cout<<"____________________________________________"<<endl;
                    break;
                }
                default:
                {
                    cout<<"____________________________________________"<<endl;
                    cout<<"            Enter valid choice              "<<endl;
                    cout<<"____________________________________________"<<endl;
                    break;
                }          
        }

    } while(choice!=4);
    return 0;
    


}