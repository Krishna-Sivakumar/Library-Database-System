//Library DBMS System
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

const float r = 0.1; // Rate to rent books is 10% of the book's price

class book
{
 char name[50];
 int id;
 float price;
 char authour[50];

 public:

 book()
 {
  strcpy(name,"NULL");
  id=1;
  price=-1;
  strcpy(authour,"NULL");
 }

 int returnid()
 {
  return id;
 }
 float returnprice()
 {
  return price;
 }

 void newbook()
 {
  cout<<"\nEnter Name: ";gets(name);
  cout<<"Enter Id: ";cin>>id;
  cout<<"Enter Price: ";cin>>price;
  cout<<"Enter Authour: ";gets(authour);
 }
 void shbook()
 {
   cout<<"\nName: "<<name;
  cout<<" ::Id: "<<id;
  cout<<" ::Price: "<<price;
  cout<<" ::Authour: "<<authour;
 }

};


class user
{
  char username[50];  //User Name
  book rbooks[5];  //Rented Books
  int userid;
  int top;

  public:
  user()
  {
   strcpy(username,"NULL");
   userid=1;
   top=-1;
  }

  int returnuserid()
  {
   return userid;
  }

  void newuser()
  {
  cout<<"\nEnter Name: ";gets(username);
  cout<<"\nEnter Id: ";cin>>userid;
  }
  void shuser()
 {
   cout<<"\nName: "<<username;
  cout<<" ::Id: "<<userid;
  cout<<"\nBooks:\n";
  if(top==-1)
   ;
  else
  {
   for(int i=0;i<=top;i++)
    {
    rbooks[i].shbook();
    cout<<endl;
    }
  }
 }

  void addbook(book b)
 {
 top+=1;
 rbooks[top]=b;
 }
  void clearbooks()
 {
  long float total;
  for(int i=0;i<=top;i++)
   total+=(rbooks[i].returnprice())*r;
  cout<<"\nTotal rent payable is: "<<total<<" Rs.";
  top=-1;
 }


};

void main()
{
   clrscr();

do{
 clrscr();
   rename("TEMP.DAT","BOOKS.DAT");
   int choice,achoice,uchoice;

   cout<<" \t\tLibrary Databa+se Management System ";
   cout<<"\n\n1.Admin\n2.User\n3.Exit";
   cout<<"\n\nEnter Login Mode: ";
   cin>>choice;
   switch(choice)
   {
     case 1: //Admin Mode

     clrscr();
     cout<<"\n\n1.Add a Book\n2.Delete a Book\n3.Modify a Book\n4.Add a user\n5.Delete a user\n6.Modify a User\n7.View Book Database\n8.View User Database\n9.Return \n\n";
     cout<<"\nEnter Your Choice: ";
     cin>>achoice;  int id, pos; char c;
     book b,bmodifier; user u,umodifier;char found='n';
       switch(achoice)
       {
	case 1: //Add a book

	  clrscr();
	  cout<<"\nEnter details of the new book: ";
	  b.newbook();
	  book f;
	  ifstream fi("BOOKS.DAT", ios::in|ios::binary);
	  ofstream fo("TEMP.DAT", ios::out|ios::binary);
	  char last='y';int found=0;

	   while(!fi.eof())
	   {
	     fi.read((char*)&f,sizeof(f));

	     if((b.returnid() <= f.returnid())&&(found==0))
	     {
	      fo.write((char*)&b,sizeof(b));
	      if(!(f.returnprice()==-1))
	       fo.write((char*)&f,sizeof(f));
	      last='n';
	      cout<<"\nRecord Appended.";
	      found=1;
	      getch();
	     }
	     else
	       {
	       fo.write((char*)&f,sizeof(f));
	       }
	   }
	   if(last=='y')
	   {
	    fo.write((char*)&b,sizeof(b));
	    cout<<"\nRecord Appended.";
	    getch();
	   }

	fi.close(); fo.close();

	remove("BOOKS.DAT");
	rename("TEMP.DAT","BOOKS.DAT");


	break;

	case 2: //Delete a book

	  clrscr();
	  cout<<"\nEnter Id of the book to be deleted: ";
	  cin>>id;

	  fi.open("BOOKS.DAT", ios::in|ios::binary);
	  fo.open("TEMP.DAT", ios::out|ios::binary);

	   while(!fi.eof())
	   {
	     fi.read((char*)&f,sizeof(f));

	     if((id==f.returnid())&&(found==0))
	     {
	      ;
	      last='n';
	      cout<<"\nRecord Deleted.";
	      found=1;
	      getch();
	     }
	     else
	       {
	       fo.write((char*)&f,sizeof(f));
	       }
	   }
	   if(last=='y')
	   {
	    cout<<"\nRecord not found.";
	    getch();
	   }


	fi.close();
	fo.close();

	   remove("BOOKS.DAT");
	   rename("TEMP.DAT","BOOKS.DAT");

	break;

	case 3: //Modify a Book Record

	  clrscr();
	  found=0;
	  cout<<"\nEnter details of the book to be modified: ";
	  cin>>id;
	  fi.open("BOOKS.DAT", ios::in|ios::binary);
	  fo.open("TEMP.DAT", ios::out|ios::binary);

	   while(!fi.eof())
	   {
	     fi.read((char*)&f,sizeof(f));
	     if(f.returnid()==-1)
	      fi.read((char*)&f,sizeof(f));

	      pos=fi.tellg();


	     if((id== f.returnid())&&(found==0))
	     {
	      fo.seekp(pos);
	      cout<<"\nThe Record has been found. Enter new details: ";
	      b.newbook();
	      fo.write((char*)&b,sizeof(b));
	      last='n';
	      cout<<"\nRecord Appended.";
	      found=1;
	      getch();
	     }
	     else
	       {
	       fo.write((char*)&f,sizeof(f));
	       }
	   }
	   if(last=='y')
	   {
	    cout<<"\nRecord not found.";
	    getch();
	   }


	fi.close();
	fo.close();

	   remove("BOOKS.DAT");
	   rename("TEMP.DAT","BOOKS.DAT");

	break;

	case 4: //Create a user

		  clrscr();
	  cout<<"\nEnter details of the new user: ";
	  u.newuser();
	  user f1;
	  fi.open("USERS.DAT", ios::in|ios::binary);
	  fo.open("TEMP.DAT", ios::out|ios::binary);

	   while(!fi.eof())
	   {
	     fi.read((char*)&f1,sizeof(f1));

	     if((u.returnuserid() <= f1.returnuserid())&&(found==0))
	     {
	      fo.write((char*)&u,sizeof(u));
	      last='n';
	      cout<<"\nRecord Appended.";
	      fo.write((char*)&f1,sizeof(f1));
	      found=1;
	      getch();
	     }
	     else
	       {
	       fo.write((char*)&f1,sizeof(f1));
	       }
	   }
	   if(last=='y')
	   {
	    fo.write((char*)&u,sizeof(u));
	    cout<<"\nRecord Appended.";
	    getch();
	   }


	fi.close();
	fo.close();

	   remove("USERS.DAT");
	   rename("TEMP.DAT","USERS.DAT");

	break;

	case 5: //Delete a user


	break;

	case 6: //Modify a user



	break;

	case 7: //View Book DataBase

	  clrscr();
	  cout<<"\nLIBRARY DATABASE: "<<endl;
	  ifstream ibook("BOOKS.DAT",ios::in|ios::binary);
	  while(!ibook.eof())
	  {
	   ibook.read((char*)&b,sizeof(b));
	   b.shbook();
	  }
	  getch();
	  ibook.close();


	break;

	case 8: //View User Database

	clrscr();

	  cout<<"\nUSERS DATABASE: "<<endl;
	  ifstream iuser("USERS.DAT",ios::in|ios::binary);
	  while(!iuser.eof())
	  {
	   iuser.read((char*)&u,sizeof(u));
	   u.shuser();
	  }
	  getch();
	  iuser.close();


	break;

      default: //Invalid Option
      cout<<"\nInvalid Option.";
      break;

       }

     break;
 //---------------
     case 2: //User Mode
     clrscr();
     cout<<"\t\tUSER MODE: ";
     cout<<"\n\n1.Rent a book\n2.Return books rented\n3.Return\n";
     cout<<"Enter your choice: ";cin>>uchoice;

     switch(uchoice)
     {
      case 1: //Rent a Book


      break;
	//------------
      case 2: //Return Books


      break;

      case 3: //Return

      break;

      default: //Invalid Option
      cout<<"\nInvalid Option.";
      break;
     }

     break;
 //----------------
     case 3: //Exit
     exit(0);
 //----------------
     default: //Invalid Choice
     cout<<"\nInvalid Choice.";
   }

 }while(1);
}

