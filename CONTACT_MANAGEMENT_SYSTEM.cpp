#include<iostream>
#include<string.h>

using namespace std;

class contact
{

    public:

    int n;
    int c;

    long long *number=new long long[n];                       // DYNAMIC ARRAY TO STORE PHONE NUMBERS
    string *name=new string[n];                   // DYNAMIC ARRAY TO STORE NAMES

      // CONSTRUCTOR

    contact()
    {
        n=1;
    }

      // DESTRUCTOR

    ~contact()
    {
        delete []number;
        delete []name;
    }

      // INSERTION FUCNTION TO ADD CONTACTS


    void insertion()
    {

        char ch;
        a:
        cout<<"\t \t Enter the following details correctly to add a contact : "<<endl;
        cout<<endl;
        cout<<"\t \t NAME : ";
        fflush(stdin);
        getline(cin,name[n-1]);
        cout<<"\t \t CONTACT NUMBER : ";
        cin>>number[n-1];
        n++;
        cout<<endl<<endl;
        cout<<"\t \t Do you want to add another contact ? (Y/N) ";
        cin>>ch;
        if(ch=='Y' || ch=='y')
        goto a;
        else
        {
            sort();
            menu();
        }


    }


      // SORTING FUCNTION TO KEEP CONTACT LIST SORTED


    void sort()
    {

         int i,j=0;
         long long temp;
         string temp1;
         for(i=0;i<n-1;i++)
         {
             for(j=0;j<n-1-i;j++)
             {
                 if(name[j].compare(name[j+1])>0)
                 {
                     temp1=name[j];
                     name[j]=name[j+1];
                     name[j+1]=temp1;
                     temp=number[j];
                     number[j]=number[j+1];
                     number[j+1]=temp;
                 }
             }
         }

    }

      // SEARCH FUNCTION FOR LOOKING UP A CONTACT


    int search()
    {

        int choice,ans;
        cout<<endl<<endl;

        b:
        cout<<"\t \t Press 1 to search contact by name ."<<endl;
        cout<<"\t \t Press 2 to search contact by number ."<<endl;
        cout<<"\t \t Enter your choice : ";
        cin>>choice;
        if(choice == 1)
        ans=searchname();
        else if (choice ==2)
        ans=searchnumber();
        else
        {
            cout<<"Wrong choice inputted , please input again . "<<endl;
            cout<<endl;
            goto b;
        }
        return ans;

    }

      // FUCNTION TO SEARCH BY NAME

    int searchname()
    {

        string na;
        int i,c,flag=0;
        cout<<"\t \t Enter the name : ";
        fflush(stdin);
        getline(cin,na);
        for(i=0;i<n;i++)
        {
            if(na.compare(name[i])==0)
            {
                c=i;
                flag =1;
                break;
            }
        }

        if(flag==1)
        {
            cout<<"\t \t CONTACT FOUND SUCCESSFULLY !! "<<endl;
            cout<<"\t \t NAME : "<<name[c];
            cout<<"\t \t CONTACT NUMBER : "<<number[c];
            return c;
        }

        else
        {
            cout<<"CONTACT NOT FOUND !! "<<endl;
            return -1;
        }


    }

    // FUNCTION TO SERACH BY NUMBER


    int searchnumber()
    {

        int i,d,flag1=0;
        long long no1;
        cout<<"\t \t Enter the number : ";
        cin>>no1;
        for(i=0;i<n;i++)
        {
            if(no1==number[i])
            {
                d=i;
                flag1 =1;
                break;
            }
        }

        if(flag1==1)
        {
            cout<<"\t \t CONTACT FOUND SUCCESSFULLY !! "<<endl;
            cout<<"\t \t NAME : "<<name[d]<<endl;
            cout<<"\t \t CONTACT NUMBER : "<<number[d];
            return d;
        }

        else
        {
            cout<<"CONTACT NOT FOUND !! "<<endl;
            return -1;
        }

    }

      // FUNCTION TO DELETE CONTACTS


    void deletion()
    {

        int cho,an;

        e:
        cout<<"\t \t Press 1 to search contact by name and delete ."<<endl;
        cout<<"\t \t Press 2 to search contact by number and delete ."<<endl;
        cout<<"\t \t Enter your choice : ";
        cin>>cho;
        if(cho == 1)
        {
            an=searchname();
            if(an!=-1)
            {
               for(int i=an;i<n-1;i++)
               {
                   name[i]=name[i+1];
                   number[i]=number[i+1];
               }
               cout<<endl<<endl<<"CONTACT DELETED SUCCESSFULLY !!"<<endl;
               n--;
            }

            else
            {
                cout<<"Search again !! "<<endl;
                goto e;
            }
        }

        else if (cho ==2)
        {
            an=searchnumber();
            if(an!=-1)
            {
               for(int i=an;i<n-1;i++)
               {
                   name[i]=name[i+1];
                   number[i]=number[i+1];
               }
               n--;
            }

            else
            {
                cout<<"Search again !! "<<endl;
                goto e;
            }
        }


    }

    // FUNCTION TO UPDATE AN EXISTING CONTACT DETAILS


    void update()
    {

        int u,chh;
        u=search();
        cout<<"\t \t To update name press 1 "<<endl;
        cout<<"\t \t To update number press 2 "<<endl;
        cout<<"\t \t Enter your choice : ";
        cin>>chh;
        if(chh==1)
        {
            cout<<"\t \t Enter new name : ";
            fflush(stdin);
            getline(cin,name[u]);
            cout<<"Name updated successfully !! "<<endl;
        }

        else if(chh==2)
        {
            cout<<"\t \t Enter new number : ";
            cin>>number[u];
            cout<<"Number updated successfully !! "<<endl;
        }

    }

     // FUNCTION TO DISPLAY ALL CONTACTS

    void display()
    {

        cout<<"\t \t CONTACT LIST  "<<endl<<endl<<endl;
        cout<<"\t  NAME \t \t \t NUMBER"<<endl;
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"\t  "<<name[i]<<"\t \t \t"<<number[i]<<endl;
        }

    }

     // FUNCTION TO DISPLAY AVAILABLE OPTIONS

    void menu()
    {

        int ab;
        char hh;
        cout<<endl<<endl<<endl;

        f:
        cout<<"\t \t 1. DISPLAY ALL THE CONTACTS ."<<endl;
        cout<<"\t \t 2. ADD CONTACT ."<<endl;
        cout<<"\t \t 3. DELETE CONTACT ."<<endl;
        cout<<"\t \t 4. UPDATE CONTACT ."<<endl;
        cout<<"\t \t 5. SEARCH CONTACT ."<<endl<<endl<<endl;
        cout<<"\t \t Enter your choice : ";
        cin>>ab;

        switch(ab)
        {
            case 1:
            display();
            break;

            case 2:
            insertion();
            break;

            case 3:
            deletion();
            break;

            case 4:
            update();
            break;

            case 5:
            search();
            break;

            default:
            cout<<"\t \t Wrong option selected , choose again "<<endl<<endl;
            goto f;
        }

        cout<<"\t \t To continue press Y and N to exit "<<endl;
        cin>>hh;
        if(hh=='Y' || hh=='y')
        goto f;
        else
        exit(0);

    }




};                  // END OF CLASS CONTACT



 int main()               // MAIN  FUNCTION
 {
     contact ob;
     ob.menu();
     return 0;
 }





