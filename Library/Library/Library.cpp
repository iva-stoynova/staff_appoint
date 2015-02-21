// Library.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

//Max Lengths
const int BooksCapacity=100;
const int AuthorsCapacity=50;

const int DBFileNameLen=20;
int dbBooksCount = 0;
char dbBooks[DBFileNameLen];
int dbAuthorsCount = 0;
char dbAuthors[DBFileNameLen];

const int BkNLen=50; //Book Name MAXLength
const int AuthNLen=50; //Author Name MAXLength
const int ISBNLen=12; //ISBN MAXLength
const int GndrNLen=20; //Literal Gender MAXLength

const int PblshrNLen=20; //Publisher Name MAXLength

int StringCompare(char* str1, char* str2)
{
	int i=0;
	while((str1[i] != NULL) && (str2[i] != NULL))
	{
		if (str1[i] > str2[i])
			return 1;
		else if (str1[i] < str2[i])
			return -1;
		else
			i++;
	}

	if (str1[i] == str2[i])
		return 0;
	else if (str1[i] == NULL)
		return -1;
	else
		return 1;
}

void NullString(char* buff)
{
     for(int i=0;i<(int)strlen(buff);i++)
          buff[i]=NULL;
}

struct Book
{
	 char BkName[BkNLen];
	 char Athr[AuthNLen];
	 int YarOfRlse;
	 char ISBN[ISBNLen];
	 char Gndr[GndrNLen];

	 void AddTDB(fstream*);
	 void RdFrmDB(fstream*);
	 void AddTTXTRprt(char* fileName);
	 void RenderToDisplay();

	 void FillOBJ();
};

Book *books[BooksCapacity];

void Book::AddTDB(fstream* out)
{
     out->write((char*)(this) ,sizeof(*this));
}

void Book::RdFrmDB(fstream* in)
{
     in->read((char*)(this) ,sizeof(*this));
}

void Book::AddTTXTRprt(char *data)
{
     ofstream out(data , ios::app);
     out<<"------------------------------------------\n";
     out<<"Book's Name : "<<this->BkName<<"\n";
     out<<"Author : "<<this->Athr<<"\n";
     out<<"Year of Release : "<<this->YarOfRlse<<"\n";
     out<<"ISBN : "<<this->ISBN<<"\n";
	 out<<"Gender : "<<this->Gndr<<"\n";
     out<<"\n";
     out.close();
}

void Book::RenderToDisplay()
{
	cout<<"------------------------------------------\n";
	cout<<"Book's Name : "<<this->BkName<<"\n";
	cout<<"Author : "<<this->Athr<<"\n";
	cout<<"Year of Release : "<<this->YarOfRlse<<"\n";
	cout<<"ISBN : "<<this->ISBN<<"\n";
	cout<<"Gender : "<<this->Gndr<<"\n";
	cout<<"\n";
}

void Book::FillOBJ()
{
     char a[2];

     char buff1[BkNLen];
     NullString(buff1);
     cout<<"Title ...\t";
     cin.getline(a,2);
     cin.getline(buff1,BkNLen);
     strcpy(this->BkName,buff1);

     char buff2[AuthNLen];
     NullString(buff2);
     cout<<"Author...\t";
     cin.getline(buff2,AuthNLen);
     strcpy(this->Athr,buff2);

     int buff3;
     cout<<"Year of Release...\t";
     cin>>buff3;
     this->YarOfRlse=buff3;

     char buff4[ISBNLen];
     NullString(buff4);
     cout<<"ISBN... \t";
     cin.getline(a,2);
     cin.getline(buff4,ISBNLen);
     strcpy(this->ISBN,buff4);

	 char buff5[GndrNLen];
     NullString(buff5);
     cout<<"Gender... \t";
     cin.getline(buff5,GndrNLen);
     strcpy(this->Gndr,buff5);
}

struct Author
{
	 char Athr[AuthNLen];
	 int YarOfBirth;
	 int YarOfDeath;
	 char Gndr[GndrNLen];
	 char Pblshr[PblshrNLen];

	 void AddTDB(fstream*);
	 void RdFrmDB(fstream*);
	 void AddTTXTRprt(char* fileName);
	 void RenderToDisplay();

	 void FillOBJ();
};

Author *authors[AuthorsCapacity];

void Author::AddTDB(fstream* out)
{
     out->write((char*)(this) ,sizeof(*this));
}

void Author::RdFrmDB(fstream* in)
{
     in->read((char*)(this) ,sizeof(*this));
}

void Author::AddTTXTRprt(char *data)
{
     ofstream out(data , ios::app);
     out<<"------------------------------------------\n";
     out<<"Author : "<<this->Athr<<"\n";
     out<<"Year of Birth : "<<this->YarOfBirth<<"\n";
	 out<<"Year of Death : "<<this->YarOfDeath<<"\n";
	 out<<"Gender : "<<this->Gndr<<"\n";
	 out<<"Publisher : "<<this->Pblshr<<"\n";
     out<<"\n";
     out.close();
}

void Author::RenderToDisplay()
{
	cout<<"------------------------------------------\n";
	cout<<"Author : "<<this->Athr<<"\n";
	cout<<"Year of Birth : "<<this->YarOfBirth<<"\n";
	cout<<"Year of Death : "<<this->YarOfDeath<<"\n";
	cout<<"Gender : "<<this->Gndr<<"\n";
	cout<<"Publisher : "<<this->Pblshr<<"\n";
	cout<<"\n";
}

void Author::FillOBJ()
{
     char a[2];

     char buff1[AuthNLen];
     NullString(buff1);
     cout<<"Author...\t";
	 cin.getline(a, 2);
     cin.getline(buff1,AuthNLen);
     strcpy(this->Athr,buff1);

     int buff2;
     cout<<"Year of Birth...\t";
     cin>>buff2;
     this->YarOfBirth=buff2;

	 int buff3;
     cout<<"Year of Death...\t";
     cin>>buff3;
     this->YarOfDeath=buff3;

	 char buff4[GndrNLen];
     NullString(buff4);
     cout<<"Gender... \t";
     cin.getline(a,2);
     cin.getline(buff4,GndrNLen);
     strcpy(this->Gndr,buff4);

	 char buff5[PblshrNLen];
     NullString(buff5);
     cout<<"Publisher... \t";
     cin.getline(buff5,PblshrNLen);
     strcpy(this->Pblshr,buff5);
}

bool AuthorsContain(char author[AuthNLen])
{
	for(int i=0;i<dbAuthorsCount;i++)
		if (StringCompare(authors[i]->Athr, author) == 0)
			return true;

	return false;
}

void InitCollections()
{
	fstream *in = new fstream(dbBooks, ios::in);
	if (!in->is_open())
	{
		in->close();
		fstream out(dbBooks, ios::out);
		out.close();

		in = new fstream(dbBooks, ios::in);
	}

	Book *b = new Book();
	b->RdFrmDB(in);
	while(!in->eof())
	{
		books[dbBooksCount++] = b;
		b = new Book();
		b->RdFrmDB(in);
	}
	in->close();

	in = new fstream(dbAuthors, ios::in);
	if (!in->is_open())
	{
		in->close();
		fstream out(dbAuthors, ios::out);
		out.close();

		in = new fstream(dbAuthors, ios::in);
	}
	Author *a = new Author();
	a->RdFrmDB(in);
	while(!in->eof())
	{
		authors[dbAuthorsCount++] = a;
		a = new Author();
		a->RdFrmDB(in);
	}
	in->close();
}

void DBInit()
{
     ifstream frdb("library.ini");
     frdb>>dbBooks;
	 frdb>>dbAuthors;
     frdb.close();

	 InitCollections();
}

enum Choise
{
	ChangeDBFileNames = 'C',
	AddBook = 'A',
	EditBook = 'E',
	DeleteBook = 'D',
	AddAuthor = 'a',
	DeleteAuthor = 'd',
	SearchBooksByYear = 'Y',
	SearchBooksByAuthorISBN = 'I',
	SearchBooksByAuthorGender = 'G',
	SearchAuthorsPublisher = 'P',
	TotalReport = 'T',
	Exit = 'x'
};

void Swap(Book **book1, Book **book2)
{
	Book *book3;
	book3= *book1;
	*book1 = *book2;
	*book2 = book3;
}

void Swap(Author **auth1, Author **auth2)
{
	Author *auth3;
	auth3= *auth1;
	*auth1 = *auth2;
	*auth2 = auth3;
}

void EditBookByISBN()
{
	char ISBNToEdit[ISBNLen];

	cout<<"Please enter the ISBN of the target book...\t";
	cin>>ISBNToEdit;

	int i;
	for(i=0;i<dbBooksCount;i++)
		if (StringCompare(books[i]->ISBN, ISBNToEdit) == 0)
			break;

	if (dbBooksCount > i)
	{
		books[i]->FillOBJ();
	}
	else
	{
		system("cls");
		cout<<"The book was not found"<<endl;
		system("pause");
	}
}

void DeleteBookByISBN()
{
	char a[2];
	char ISBNToRemove[ISBNLen];

	cout<<"Please enter the ISBN of the target book...\t";
	cin.getline(a, 2);
	cin.getline(ISBNToRemove, ISBNLen);

	int i;
	for(i=0;i<dbBooksCount;i++)
		if (StringCompare(books[i]->ISBN, ISBNToRemove) == 0)
			break;

	if (dbBooksCount > i)
	{
		while(i<(dbBooksCount - 1))
		{
			Swap(&books[i], &books[i+1]);
			i++;
		}
		dbBooksCount--;
	}
	else
	{
		system("cls");
		cout<<"The book was not found"<<endl;
		system("pause");
	}
}

void DeleteBooksByAuthor(char targetAutor[AuthNLen])
{
	int i=0;
	while(i<dbBooksCount)
	{
		if (StringCompare(books[i]->Athr, targetAutor) == 0)
		{
			for(int j=i;j<dbBooksCount;j++)
				Swap(&books[j], &books[j+1]);
			dbBooksCount--;
			i--;
		}
		i++;
	}
}

void DeleteAuthorByName()
{
	char choise;
	cout<<"With the author you will also delete all books associated with him. Are you sure [Y/N]...\t";
	cin>>choise;
	if (choise == 'N')
		return;

	char a[2];
	char AuthorToRemove[AuthNLen];

	cout<<"Please enter the name of the target author...\t";
	cin.getline(a, 2);
	cin.getline(AuthorToRemove, AuthNLen);

	int i;
	for(i=0;i<dbAuthorsCount;i++)
		if (StringCompare(authors[i]->Athr, AuthorToRemove) == 0)
			break;

	if (dbAuthorsCount > i)
	{
		while(i<(dbAuthorsCount - 1))
		{
			Swap(&authors[i], &authors[i+1]);
			i++;
		}
		dbAuthorsCount--;

		DeleteBooksByAuthor(AuthorToRemove);
	}
	else
	{
		system("cls");
		cout<<"The author was not found"<<endl;
		system("pause");
	}
}

void SearchBooksByYearOrderedByAuthor(int year)
{
	char choise;
	char reportFile[DBFileNameLen];
	cout<<"Would you like to save the result in a file [Y/N]...\t";
	cin>>choise;
	if (choise == 'Y')
	{
		cout<<"\n\nSpecify file name for the report...\t";
		cin>>reportFile;
		fstream out(reportFile, ios::out);
		out.close();
	}
	system("cls");

	int i, j;
	for(i=0;i<dbBooksCount;i++)
		for(j=i;j<dbBooksCount;j++)
		{
			if (StringCompare(books[i]->Athr, books[j]->Athr) > 0)
				Swap(&books[i], &books[j]);
		}

	for(i=0;i<dbBooksCount;i++)
		if (books[i]->YarOfRlse == year)
		{
			if (choise == 'Y')
				books[i]->AddTTXTRprt(reportFile);
			books[i]->RenderToDisplay();
		}
}

void SearchBooksByAuthorOrderedByISBN(char author[AuthNLen])
{
	char choise;
	char reportFile[DBFileNameLen];
	cout<<"Would you like to save the result in a file [Y/N]...\t";
	cin>>choise;
	if (choise == 'Y')
	{
		cout<<"\n\nSpecify file name for the report...\t";
		cin>>reportFile;
		fstream out(reportFile, ios::out);
		out.close();
	}
	system("cls");

	int i, j;
	for(i=0;i<dbBooksCount;i++)
		for(j=i;j<dbBooksCount;j++)
		{
			if (StringCompare(books[i]->ISBN, books[j]->ISBN) > 0)
				Swap(&books[i], &books[j]);
		}

	for(i=0;i<dbBooksCount;i++)
		if (StringCompare(books[i]->Athr, author) == 0)
		{
			if (choise == 'Y')
				books[i]->AddTTXTRprt(reportFile);
			books[i]->RenderToDisplay();
		}
}

void SearchBooksByAuthorOrderedByGender(char author[AuthNLen])
{
	char choise;
	char reportFile[DBFileNameLen];
	cout<<"Would you like to save the result in a file [Y/N]...\t";
	cin>>choise;
	if (choise == 'Y')
	{
		cout<<"\n\nSpecify file name for the report...\t";
		cin>>reportFile;
		fstream out(reportFile, ios::out);
		out.close();
	}
	system("cls");

	int i, j;
	for(i=0;i<dbBooksCount;i++)
		for(j=i;j<dbBooksCount;j++)
		{
			if (StringCompare(books[i]->Gndr, books[j]->Gndr) > 0)
				Swap(&books[i], &books[j]);
		}

	for(i=0;i<dbBooksCount;i++)
		if (StringCompare(books[i]->Athr, author) == 0)
		{
			if (choise == 'Y')
				books[i]->AddTTXTRprt(reportFile);
			books[i]->RenderToDisplay();
		}
}

void SearchAuthorsOrderedByPublisher()
{
	char choise;
	char reportFile[DBFileNameLen];
	cout<<"Would you like to save the result in a file [Y/N]...\t";
	cin>>choise;
	if (choise == 'Y')
	{
		cout<<"\n\nSpecify file name for the report...\t";
		cin>>reportFile;
		fstream out(reportFile, ios::out);
		out.close();
	}
	system("cls");

	int i, j;
	for(i=0;i<dbAuthorsCount;i++)
		for(j=i;j<dbAuthorsCount;j++)
		{
			if (StringCompare(authors[i]->Pblshr, authors[j]->Pblshr) > 0)
				Swap(&authors[i], &authors[j]);
		}

	for(i=0;i<dbAuthorsCount;i++)
	{
		if (choise == 'Y')
			authors[i]->AddTTXTRprt(reportFile);
		authors[i]->RenderToDisplay();
	}
}

void RenderTotalReport()
{
	char choise;
	char reportFile[DBFileNameLen];
	cout<<"Would you like to save the result in a file [Y/N]...\t";
	cin>>choise;
	if (choise == 'Y')
	{
		cout<<"\n\nSpecify file name for the report...\t";
		cin>>reportFile;
		fstream out(reportFile, ios::out);
		out.close();
	}
	system("cls");

	int i;

	cout<<"#########BOOKS##########"<<endl;
	for(i=0;i<dbBooksCount;i++)
	{
		if (choise == 'Y')
			books[i]->AddTTXTRprt(reportFile);
		books[i]->RenderToDisplay();
	}

	cout<<endl<<endl<<"#########AUTHORS##########"<<endl;
	for(i=0;i<dbAuthorsCount;i++)
	{
		if (choise == 'Y')
			authors[i]->AddTTXTRprt(reportFile);
		authors[i]->RenderToDisplay();
	}
}

void ChangeDataBaseFileNames()
{
	cout<<"Enter name for the books storage file...\t";
	cin>>dbBooks;
	cout<<"\n\nEnter name for the authors storage file...\t";
	cin>>dbAuthors;

	fstream out("library.ini", ios::out);
	out<<dbBooks<<endl<<dbAuthors;
}

void PersistCollections()
{
	int i;

	fstream *out = new fstream(dbBooks, ios::out);
	for(i=0;i<dbBooksCount;i++)
		books[i]->AddTDB(out);
	out->close();

	out = new fstream(dbAuthors, ios::out);
	for(i=0;i<dbAuthorsCount;i++)
		authors[i]->AddTDB(out);
	out->close();
}

void main()
{
	DBInit();
	char choise;

	while(true)
    {
		cout<<"'C'hange DataBase Files Names ,\n\n"<<
			  "'A'dd Book to DataBase ,\n\n"<<
			  "'E'dit Book,\n\n"<<
			  "'D'elete Book,\n\n"<<
			  "'a'dd Author,\n\n"<<
			  "'d'elete Author,\n\n"<<
			  "Search books by 'Y'ear of release , \n\n"<<
			  "Search books by Author 'I'SBN ordered , \n\n"<<
			  "Search books by Author 'G'ender ordered , \n\n"<<
			  "Search authors ordered by 'P'ublisher, \n\n"<<
			  "'T'otal Report, \n\n"<<
			  "'E'x'it the program\n\n...";

		cin>>choise;
		switch(choise)
		{
			case ChangeDBFileNames : 
				{
					ChangeDataBaseFileNames();
					break;
				}
			case AddBook :
				{
					while (choise != 'N')
					{
						system("cls");

						Book *book = new Book();
						book->FillOBJ();

						if (AuthorsContain(book->Athr))
							books[dbBooksCount++] = book;
						else
						{ 
							system("cls");
							cout<<"The book was not added. The author \""<<book->Athr<<"\"\n"<<
								  "is not registered in the system. Please add the author before\n"<<
								  "registering the book."<<endl;
							system("pause");
						}

						system("cls");
						
						while(true)
						{
							cout<<"Do you want to add another book?\n\n['Y'es/'N'o]";
							cin>>choise;
							if(choise=='Y')
								break;
							if(choise=='N')
								break;
						}
					}
					system("cls");

					break;
				}
			case EditBook :
				{
					EditBookByISBN();
					system("cls");

					break;
				}
			case DeleteBook :
				{
					DeleteBookByISBN();
					system("cls");

					break;
				}
			case AddAuthor :
				{
					while (choise != 'N')
					{
						system("cls");

						Author *author = new Author();
						author->FillOBJ();
						authors[dbAuthorsCount++] = author;

						system("cls");
						
						while(true)
						{
							cout<<"Do you want to add another author?\n\n['Y'es/'N'o]";
							cin>>choise;
							if(choise=='Y')
								break;
							if(choise=='N')
								break;
						}
					}
					system("cls");

					break;
				}
			case DeleteAuthor:
				{
					DeleteAuthorByName();
					system("cls");

					break;
				}
			case SearchBooksByYear:
				{
					system("cls");

					int year;
					cout<<"Enter target year...\t";
					cin>>year;
					SearchBooksByYearOrderedByAuthor(year);
					cout<<endl;
					system("pause");
					system("cls");

					break;
				}
			case SearchBooksByAuthorISBN:
				{
					system("cls");

					char a[2];
					char author[AuthNLen];
					cout<<"Enter target author...\t";
					cin.getline(a, 2);
					cin.getline(author, AuthNLen);

					SearchBooksByAuthorOrderedByISBN(author);
					cout<<endl;
					system("pause");
					system("cls");

					break;
				}
			case SearchBooksByAuthorGender:
				{
					system("cls");

					char a[2];
					char author[AuthNLen];
					cout<<"Enter target author...\t";
					cin.getline(a, 2);
					cin.getline(author, AuthNLen);

					SearchBooksByAuthorOrderedByGender(author);
					cout<<endl;
					system("pause");
					system("cls");

					break;
				}
			case SearchAuthorsPublisher:
				{
					system("cls");

					SearchAuthorsOrderedByPublisher();
					cout<<endl;
					system("pause");
					system("cls");

					break;
				}
			case TotalReport:
				{
					system("cls");

					RenderTotalReport();
					cout<<endl;
					system("pause");
					system("cls");
					break;
				}
			case Exit : 
				{
					cout<<"Would you like to save the changes made in this session [Y/N]...\t";
					cin>>choise;
					
					if (choise != 'N')
						PersistCollections();

					exit(0);
				}
			default :
				{
					cout<<"Wrong choise"<<endl;
					system("pause");
					system("cls");
				}
          }
     }
}