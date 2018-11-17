//Library DBMS System

#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

const float r = 0.1; // Rate to rent books is 10% of the book's price

class book
{
 char name[20];
 int id;
 float price;
 char authour[20];

 public:

 book()
 {
  strcpy(name,"NULL");
  id=-1;
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
  char username[20];  //User Name
  book rbooks[5];  //Rented Books
  int userid;
  int top;

  public:
  user()
  {
   strcpy(username,"NULL");
   userid=-1;
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

   ifstream ibook,iuser; ofstream obook,ouser,temp; //Input and Output Handlers for Books.dat and Users.dat
   fstream mbook,muser; //Manipulates Books, Users Binary Files
   ibook.open("books.dat",ios::in|ios::binary);
   iuser.open("users.dat",ios::in|ios::binary);
   obook.open("books.dat",ios::out|ios::binary);
   ouser.open("users.dat",ios::out|ios::binary);
   mbook.open("books.dat",ios::in|ios::out||ios::binary);
   muser.open("users.dat",ios::in|ios::out||ios::binary);

do{
 clrscr();

   int choice,achoice,uchoice;

   cout<<" \t\tLibrary Database Management System ";
   cout<<"\n\n1.Admin\n2.User\n3.Exit";
   cout<<"\n\nEnter Login Mode: ";
   cin>>choice;
   switch(choice)
   {
     case 1: //Admin Mode

     clrscr();
     cout<<"\n\n1.Add a Book\n2.Delete a Book\n3.Modify a Book\n4.Add a user\n5.Delete a user\n6.Modify a User\7.View Book Database\n8.View User Database\n9.Return \n\n";
     cout<<"\nEnter Your Choice: ";
     cin>>achoice;
     book b,bmodifier; user u,umodifier;char found='n';
       switch(achoice)
       {
	case 1: //Add a book

	break;

	case 2: //Delete a book

	break;

	case 3: //Modify a Book Record


	break;

	case 4: //Create a user

	cout<<"Enter User Details: \n";
	u.newuser();
	obook.write((char*)&u,sizeof(u));
	cout<<"Record Appended.";getch();

	break;

	case 5: //Delete a user
	temp.open("temp.dat",ios::out||ios::binary);
	cout<<"Enter Id of the user to be deleted: "; cin>>id;
	while(!iuser.eof())
	{
	 iuser.read((char*)&u,sizeof(u));
	 if(u.returnuserid()==id)
	  {found='y';
	   cout<<"Do you want to certainly delete this record? (y/n): "; cin>>c;
	   if(c=='y')
	   {
	   ;
	   cout<<"Record Deleted.";getch();
	   }
	   else
	   temp.write((char*)&u,sizeof(u));
	  }
	 else
	  temp.write((char*)&u,sizeof(u));
	}


	if(found=='n')
	{
	 cout<<"\nThe record was not found. ";
	}

	found='n';

	remove("users.dat");
	 rename("temp.dat","users.dat");
	 temp.close();

	break;

	case 6: //Modify a user

	cout<<"\nEnter the Id of user to be modified: ";
	cin>>id;
	while(!muser.eof())
	{ pos=muser.tellg();
	  muser.read((char*)&u,sizeof(u));
	  if(u.returnuserid()==id)
	  {
	   found='y';
	   cout<<"\nThe Record was found. Please Enter the details of the new book: ";
	   umodifier.newuser();
	   muser.seekg(pos);
	   muser.write((char*)&umodifier,sizeof(u));
	   cout<<"Record Appended.";getch();
	  }
	  else
	  ;
	}
	if(found=='n')
	{
	 cout<<"\nThe record was not found. ";
	}

	found='n';

	break;

	case 7: //View Book DataBase
	clrscr();

	while(!ibook.eof())
	{
	 ibook.read((char*)&b,sizeof(b));
	 b.shbook();
	}
	getch();
	break;

	case 8: //View User Database
	while(!ibook.eof())
	{
	 iuser.read((char*)&u,sizeof(u));
	 u.shuser();
	}
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
      int bookid,userid;char found='n';
      user u,umodifier; book b;
      cout<<"\nEnter User Id: ";cin>>userid;

      while(!iuser.eof())
      {
       iuser.read((char*)&u,sizeof(u));
       if(u.returnuserid()==userid);
	{
	found='y';
	umodifier=u;
	}
      }

      if(found=='y')
      {
	   found='n';
	   cout<<"\nEnter Id of Book to be rented: "; cin>>bookid;
       while(!ibook.eof())
	   {
		iuser.read((char*)&u,sizeof(b));
		if(b.returnid()==bookid);
		 {
			found='y';
			umodifier.addbook(b);
		 }
		}
	if(found=='y')
		{
		cout<<"\nBook has been rented.";getch();
		int pos;
		while(!muser.eof())
		{ pos=muser.tellg();
		muser.read((char*)&u,sizeof(u));
		 if(u.returnuserid()==userid)
		 {
		  muser.seekg(pos);
	      muser.write((char*)&umodifier,sizeof(u));
	     }
	}

    }
    }
    else
       cout<<"\nInvalid User Id. ";

      break;
	//------------
      case 2: //Return Books

      found='n';
      cout<<"\nEnter User Id: ";cin>>userid;

      while(!iuser.eof())
      {
       iuser.read((char*)&u,sizeof(u));
       if(u.returnuserid()==userid);
	   {
	    found='y';
	    umodifier=u;
	   }
      }

      if(found=='y')
      {
	   umodifier.clearbooks();
	   int pos;
	   while(!muser.eof())
	   { pos=muser.tellg();
	     muser.read((char*)&u,sizeof(u));
	     if(u.returnuserid()==userid)
	     {
	      muser.seekg(pos);
	      muser.write((char*)&umodifier,sizeof(u));
	     }
	   }
      }
      else
       cout<<"\nInvalid User Id. ";

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
     ibook.close();
     iuser.close();
     obook.close();
     ouser.close();
     mbook.close();
     muser.close();
     exit(0);
 //----------------
     default: //Invalid Choice
     cout<<"\nInvalid Choice.";
   }

 }while(1);
}

