#include<fstream>
#include<string>
#include<iomanip>

class book 
{
    char bno[6];
    char bname[50];
    char aname[20];
 public:
    void create_book()
    {
    cout<<"\nNew book entry: \n";
    cout<<"\nEnter the number of the book.";
    cin>>bno;
    cout<<"\nEnter the name of the book.";
    gets(bname);
    cout<<"\nEnter the name of the author.";
    gets(aname);
    cout<<"\n\n\nBook entry successfully created";
    }
    
    void show_book()
    {
    cout<<"\nBook number: "<<bno;
    cout<<"\nBook name: ";
    puts(bname);
    cout<<"author: ";
    puts(aname);
    }

    void modify_book()
    {
    cout<<"\nBook number: "<<bno;
    cout<<"\nBook name: ";
    gets(bname);
    cout<<"\nModify author: ";
    gets(aname);
    }

    char* retbn()
    {
      return bno;
    }

    void report()
    {cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}
    
};




