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
 char author[50];

 public:

 book()
 {
  strcpy(name,"NULL");
  id=1;
  price=-1;
  strcpy(author,"NULL");
 }

 void defaultbook()
 {
  strcpy(name,"NULL");
  id=1;
  price=-1;
  strcpy(author,"NULL");
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
  cout<<"Enter Author: ";gets(Author);
 }
 void shbook()
 {
   cout<<"\nName: "<<name;
  cout<<" ::Id: "<<id;
  cout<<" ::Price: "<<price;
  cout<<" ::Author: "<<Author;
 }

};


class user
{
  char username[50];  //User Name
  book rbook;  //Rented Book
  int userid;

  public:
  user()
  {
   strcpy(username,"NULL");
   userid=1;
  }

  int returnuserid()
  {
   return userid;
  }

  float returnbprice()
  {
   return rbook.returnprice();
  }

  void newuser()
  {
  cout<<"\nEnter Name: ";gets(username);
  cout<<"Enter Id: ";cin>>userid;
  }

  void shuser()
 {
   cout<<"\nName: "<<username;
  cout<<" ::Id: "<<userid;
  cout<<" ::Book Rented: ";
  if(rbook.returnprice()==-1)
   {
    cout<<"\nNone";
   }
  else
   {
    rbook.shbook();
   }
 }

 void rentbook(book b)
 {
  rbook=b;
 }

  void clearbook()
 {
  rbook.defaultbook();
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
     cin>>achoice;  int i, pos; char c;
     book b,bmodifier; user u,umodifier;char found='n';
       switch(achoice)
       {
	case 1: //Add a book

	  clrscr();
	  cout<<"\nEnter details of the new book: ";
	  b.newbook();
	  book f;
	  ifstream fi("BOOKS.DAT", ios::in|ios::binary);
	  ofstream fo("TEMP.DAT", ios::out|ios::binary|ios::app);
	  char last='y';int found=0;

	   while( fi.read((char*)&f,sizeof(f)))
	   {


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
	  cin>>i;
	  last='y';
	  ifstream fi1("BOOKS.DAT", ios::in|ios::binary);
	  ofstream fo1("TEMP.DAT", ios::out|ios::binary|ios::app);


	   while( fi1.read((char*)&f,sizeof(f)) )
	   {
	     if(i==f.returnid())
	     {
	       cout<<"\nDo you really want to delete the record? (y/n): ";
	       cin>>c;
	       if(c=='y')
	       {
		    last='n';
		    cout<<"\nRecord Deleted.";
		    getch();
	       }
	       else
	       fo1.write((char*)&f,sizeof(f));
	     }
	     else
	     {
	       fo1.write((char*)&f,sizeof(f));
	     }
	   }
	   if(last=='y')
	   {
	    cout<<"\nRecord not found.";
	    getch();
	   }

	fi1.close(); fo1.close();

	remove("BOOKS.DAT");
	rename("TEMP.DAT","BOOKS.DAT");

	break;

	case 3: //Modify a Book Record

	  clrscr();
	  found=0;
	  cout<<"\nEnter details of the book to be modified: ";
	  cin>>i;
	  fstream fio("BOOKS.DAT", ios::in|ios::out|ios::binary);

	  pos=fio.tellg();
	  cout<<pos;

	   while(fio.read((char*)&f,sizeof(f)))
	   {
	     if((i== f.returnid())&&(found==0))
	     {
	      if(fio.tellg()!=0)
	       fio.seekp(pos);

	      cout<<"\nThe Record has been found. Enter new details: ";
	      b.newbook();
	      fio.write((char*)&b,sizeof(b));
	      last='n';
	      cout<<"\nRecord Appended.";
	      found=1;
	      getch();
	     }

	     pos=fio.tellg();
	   }
	   if(last=='y')
	   {
	    cout<<"\nRecord not found.";
	    getch();
	   }


	fio.close();

	break;

	case 4: //Create a user

	 clrscr();

	 found=1;
	 last='y';

	  cout<<"\nEnter details of the new user: ";
	  u.newuser();
	  user g;
	  ifstream ui("USERS.DAT", ios::in|ios::binary);
	  ofstream uo("TEMP.DAT", ios::out|ios::binary|ios::app);
	   while(ui.read((char*)&g,sizeof(g)))
	   {

	     if((u.returnuserid() <= g.returnuserid())&&(found==0))
	     {

	      getch();
	      uo.write((char*)&u,sizeof(u));
	      last='n';
	      cout<<"\nRecord Appended.";
	      found=1;
	      getch();
	     }
	     else
	       {
	       uo.write((char*)&g,sizeof(g));
	       }
	   }
	   if(last=='y')
	   {
	    uo.write((char*)&u,sizeof(u));
	    cout<<"\nRecord Appended.";
	    getch();
	   }

	ui.close(); uo.close();

	remove("USERS.DAT");
	rename("TEMP.DAT","USERS.DAT");

	break;

	case 5: //Delete a user

	clrscr();
	  last='y';
	  cout<<"\nEnter Id of the book to be deleted: ";
	  cin>>i;
	  ifstream ui1("USERS.DAT", ios::in|ios::binary);
	  ofstream uo1("TEMP.DAT", ios::out|ios::binary|ios::app);


	   while( ui1.read((char*)&g,sizeof(g)) )
	   {
	     if(i==g.returnuserid())
	     {
	       cout<<"\nDo you really want to delete the record? (y/n): ";
	       cin>>c;
	       if(c=='y')
	       {
		    last='n';
		    cout<<"\nRecord Deleted.";
		    getch();
	       }
	       else
	       uo1.write((char*)&g,sizeof(g));
	     }
	     else
	     {
	       uo1.write((char*)&g,sizeof(g));
	     }
	   }
	   if(last=='y')
	   {
	    cout<<"\nRecord not found.";
	    getch();
	   }

	ui1.close(); uo1.close();

	remove("USERS.DAT");
	rename("TEMP.DAT","USERS.DAT");

	break;

	case 6: //Modify a user

       clrscr();
	  found=0;
	  cout<<"\nEnter id of the user to be modified: ";
	  cin>>i;
	  fstream uio("USERS.DAT", ios::in|ios::out|ios::binary);

	  pos=uio.tellg();
	  cout<<pos;

	   while(uio.read((char*)&g,sizeof(g)))
	   {
	     if((i== g.returnuserid())&&(found==0))
	     {
	      if(uio.tellg()!=0)
	       uio.seekp(pos);

	      cout<<"\nThe Record has been found. Enter new details: ";
	      u.newuser();
	      uio.write((char*)&u,sizeof(u));
	      last='n';
	      cout<<"\nRecord Appended.";
	      found=1;
	      getch();
	     }

	     pos=uio.tellg();
	   }
	   if(last=='y')
	   {
	    cout<<"\nRecord not found.";
	    getch();
	   }


	uio.close();

	break;

	case 7: //View Book DataBase

	  clrscr();
	  cout<<"\nLIBRARY DATABASE: "<<endl;
	  ifstream ibook("BOOKS.DAT",ios::in|ios::binary);
	  while(ibook.read((char*)&b,sizeof(b)))
	  {
	   b.shbook();
	  }
	  getch();
	  ibook.close();


	break;

	case 8: //View User Database

	clrscr();
	  cout<<"\nUSER DATABASE: "<<endl;
	  ifstream iuser("USERS.DAT",ios::in|ios::binary);
	  while(iuser.read((char*)&u,sizeof(u)))
	  {
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

      book f; user g,u;
      char last='y';

      clrscr();
      int id1;
      cout<<"\nEnter Id of user: ";
      cin>>id1;
	  ifstream ui("USERS.DAT", ios::in|ios::binary);
	  ifstream bi("BOOKS.DAT",ios:: in|ios::binary);
	  while(ui.read((char*)&g,sizeof(g)))
	   {
	      if(id1 == g.returnuserid())
	      {
	       cout<<"User found.";
	       if(g.returnbprice()==-1)
	       {
		last='n';
		u=g;
	       }
	       else
		{
		 cout<<"\nUser has already rented a book";
		 last='x';
		 break;
		}
	      }
	   }
	   if(last=='y')
	   {
	    cout<<"\nUser not found.";
	    getch();
	    break;
	   }
	   ui.close();


	   last='y';
	   int id2;
      cout<<"\nEnter Id of book to be rented: ";
      cin>>id2;

	   while( bi.read((char*)&f,sizeof(f)) )
	   {
	     if((id2== f.returnid()))
	     {
	      cout<<"\nThe Book has been found.";
	      last='n';
	      u.rentbook(f);
	     }
	   }
	   if(last=='y')
	   {
	    cout<<"\nBook not found.";
	    getch();
	    break;
	   }
	   bi.close();

	   fstream uio("USERS.DAT",ios::in|ios::out|ios::binary);

	   int pos=uio.tellg();

	   while( uio.read((char*)&g,sizeof(g)) )
	   {
	     if((id2== g.returnuserid()))
	     {
	      uio.seekp(pos);
	      uio.write((char*)&u,sizeof(u));
	      cout<<"\nBook Rented.";
	      getch();
	     }

	     pos=uio.tellg();


	   }



	uio.close();

      break;
	//------------
      case 2: //Return Books

      last='y';

      clrscr();
      cout<<"\nEnter Id of user: ";
      cin>>id1;
	  ifstream ui1("USERS.DAT", ios::in|ios::binary);
	  while(ui1.read((char*)&g,sizeof(g)))
	   {
	      if(id1 == g.returnuserid())
	      {
	       cout<<"User found.";
	       if(g.returnbprice()!=-1)
	       {
		u=g;
		last='n';
		cout<<"\nUser has returned the book.";
		getch();
		u.clearbook();
	       }
	       else
		{
		 cout<<"\nUser has not rented a book";
		 last='x';
		 break;
		}
	      }
	   }
	   if(last=='y')
	   {
	    cout<<"\nUser not found.";
	    getch();
	    break;
	   }
	   ui.close();

	   fstream uio1("USERS.DAT",ios::in|ios::out|ios::binary);

	   pos=uio1.tellg();

	   while( uio1.read((char*)&g,sizeof(g)) )
	   {
	     if((u.returnuserid()== g.returnuserid()))
	     {
	      uio1.seekp(pos);
	      uio1.write((char*)&u,sizeof(u));
	      getch();
	     }

	     pos=uio1.tellg();


	   }



	uio1.close();


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

