#include "Books.h"
#include <iostream>
#include <string>

using namespace std;

//constructors
//DEFAULT AND PARAMETRISED CONST FOR BOOKS
Books::Books(string ttl = " ", string writer = " ", int totalP = 0, int Pgsread = 0, string favLine = " ", bool isFin = 0, int ID = 0, int bookR = 0)
{
	title = ttl;
	author = writer;
	totalPages = totalP;
	PagesRead = Pgsread;
	favQuote = favLine;
	isFinished = isFin;
	bookId = ID;
	bookRating = bookR;
}

//constructors for all derived classes
Fiction::Fiction(string ttl = { " " }, string writer = { " " }, int totalP = 0, int Pgsread = 0, string favLine = { " " }, bool isFin = 0, int ID = 0, int bookR = 0)
	: Books(ttl, writer, totalP, Pgsread, favLine, isFin, ID, bookR)
{
}

Nonfiction::Nonfiction(string ttl = { " " }, string writer = { " " }, int totalP = 0, int Pgsread = 0, string favLine = { " " }, bool isFin = 0, int ID = 0, int bookR = 0)
	: Books(ttl, writer, totalP, Pgsread, favLine, isFin, ID, bookR)
{
}

Poetry::Poetry(string ttl = { " " }, string writer = { " " }, int totalP = 0, int Pgsread = 0, string favLine = { " " }, bool isFin = 0, int ID = 0, int bookR = 0)
	: Books(ttl, writer, totalP, Pgsread, favLine, isFin, ID, bookR)
{
}

Fantasy::Fantasy(string ttl = { " " }, string writer = { " " }, int totalP = 0, int Pgsread = 0, string favLine = { " " }, bool isFin = 0, int ID = 0, int bookR = 0)
	: Fiction(ttl, writer, totalP, Pgsread, favLine, isFin, ID, bookR)
{
}

Mystery::Mystery(string ttl = { " " }, string writer = { " " }, int totalP = 0, int Pgsread = 0, string favLine = { " " }, bool isFin = 0, int ID = 0, int bookR = 0)
	: Fiction(ttl, writer, totalP, Pgsread, favLine, isFin, ID, bookR)
{
}

ScienceFiction::ScienceFiction(string ttl = { " " }, string writer = { " " }, int totalP = 0, int Pgsread = 0, string favLine = { " " }, bool isFin = 0, int ID = 0, int bookR = 0)
	: Fiction(ttl, writer, totalP, Pgsread, favLine, isFin, ID, bookR)
{
}

Classic::Classic(string ttl = { " " }, string writer = { " " }, int totalP = 0, int Pgsread = 0, string favLine = { " " }, bool isFin = 0, int ID = 0, int bookR = 0)
	: Fiction(ttl, writer, totalP, Pgsread, favLine, isFin, ID, bookR)
{
}

//getters
string Books::getTitle()
{
	return title;
}
string Books::getAuthor()
{
	return author;
}
int Books::gettotalPages()
{
	return totalPages;
}
int Books::getPagesRead()
{
	return PagesRead;
}
string Books::getfavQuote()
{
	return favQuote;
}
//setter
void Books::UpdateReadPages(int pages)
{
	if (pages <= totalPages && pages > 0)
	{
		PagesRead = pages;
	}
}

//functions
//update read pages

void Books::markAsFinished()
{
	isFinished = true;
	PagesRead = totalPages;
}

//get progress
float Books::getReadingProgress()
{
	if (totalPages != 0)
	{
		return (PagesRead / totalPages);
	}
}

//genre
string Fiction::getGenre()const 
{
	return "Fiction";
}

string Nonfiction::getGenre()const 
{
	return "Non-Fiction";
}

string Poetry::getGenre()const
{
	return "Poetry";
}

string Fantasy::getGenre()const
{
	return "Fantasy";
}

string Mystery::getGenre()const
{
	return "Mystery";
}

string ScienceFiction::getGenre()const
{
	return "Science Fiction";
}

string Classic::getGenre()const
{
	return "Crime Fiction";
}

//display
void Books::display()
{
	cout << bookId << ": '" << title << "' is written by " << author << ". You have read " << PagesRead << " of the " << totalPages << " pages. " << (isFinished ? "You have finished the book. " : "You have not finished the book. ") << endl;
	if (isFinished)
	{
		cout << "You gave the book " << bookRating << " stars. Your favourite quote is: " << favQuote << endl;
	}
}

void Fiction::display()
{
	cout << bookId << ": '" << getTitle() << "' is written by " << getAuthor() << " and is based on fiction. You have read " << getPagesRead() << " of the " << gettotalPages() << " pages. " << (isFinished ? "You have finished the book. " : "You have not finished the book. ") << endl;
	if (isFinished)
	{
		cout << "You gave the book " << bookRating << " stars. Your favourite quote is: " << getfavQuote() << endl;
	}
}

void Nonfiction::display()
{
	cout << bookId << ": '" << getTitle() << "' is written by " << getAuthor() << " and is based on non-fiction. You have read " << getPagesRead() << " of the " << gettotalPages() << " pages. " << (isFinished ? "You have finished the book. " : "You have not finished the book. ") << endl;
	if (isFinished)
	{
		cout << "You gave the book " << bookRating << " stars. Your favourite quote is: " << getfavQuote() << endl;
	}
}

void Poetry::display()
{
	cout << bookId << ": '" << getTitle() << "' is written by " << getAuthor() << " and is based on poetry. You have read " << getPagesRead() << " of the " << gettotalPages() << " pages. " << (isFinished ? "You have finished the book. " : "You have not finished the book. ") << endl;
	if (isFinished)
	{
		cout << "You gave the book " << bookRating << " stars. Your favourite quote is: " << getfavQuote() << endl;
	}
}

void Fantasy::display()
{
	cout << bookId << ": '" << getTitle() << "' is written by " << getAuthor() << " and is based on fantasy. You have read " << getPagesRead() << " of the " << gettotalPages() << " pages. " << (isFinished ? "You have finished the book. " : "You have not finished the book. ") << endl;
	if (isFinished)
	{
		cout << "You gave the book " << bookRating << " stars. Your favourite quote is: " << getfavQuote() << endl;
	}
}

void Mystery::display()
{
	cout << bookId << ": '" << getTitle() << "' is written by " << getAuthor() << " and is based on mystery. You have read " << getPagesRead() << " of the " << gettotalPages() << " pages. " << (isFinished ? "You have finished the book. " : "You have not finished the book. ") << endl;
	if (isFinished)
	{
		cout << "You gave the book " << bookRating << " stars. Your favourite quote is: " << getfavQuote() << endl;
	}
}

void ScienceFiction::display()
{
	cout << bookId << ": '" << getTitle() << "' is written by " << getAuthor() << " and is based on science fiction. You have read " << getPagesRead() << " of the " << gettotalPages() << " pages. " << (isFinished ? "You have finished the book. " : "You have not finished the book. ") << endl;
	if (isFinished)
	{
		cout << "You gave the book " << bookRating << " stars. Your favourite quote is: " << getfavQuote() << endl;
	}
}

void Classic::display()
{
	cout << bookId << ": '" << getTitle() << "' is written by " << getAuthor() << " and is based on crime fiction. You have read " << getPagesRead() << " of the " << gettotalPages() << " pages. " << (isFinished ? "You have finished the book. " : "You have not finished the book. ") << endl;
	if (isFinished)
	{
		cout << "You gave the book " << bookRating << " stars. Your favourite quote is: " << getfavQuote() << endl;
	}
}