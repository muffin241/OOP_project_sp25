#pragma once
#include <iostream>
#include <string>

using namespace std;

///  Book class
class Books
{
private:
	string title;
	string author;
	int totalPages;
	int PagesRead;
	string favQuote;
protected:
	bool isFinished;
	int bookId;
	int bookRating;
public:
	Books(string, string, int, int, string, bool, int, int);

	//getters
	string getTitle();
	string getAuthor();
	int gettotalPages();
	int getPagesRead();
	string getfavQuote();
	//setter
	void UpdateReadPages(int);

	//pure virtual func to get genre
	virtual string getGenre()const = 0;
	
	
	void markAsFinished();

	float getReadingProgress();

	//virtual func for display
	virtual void display();
};

//inheritance (based on genres)
class Fiction : public Books
{
private:
	 
public:
	Fiction(string, string, int, int, string, bool, int, int);

	string getGenre()const override;
	void display()override;
};

class Nonfiction : public Books
{
private:

public:
	Nonfiction(string, string, int, int, string, bool, int, int);

	string getGenre()const override;
	void display()override;
};

class Poetry : public Books
{
private:

public:
	Poetry(string, string, int, int, string, bool, int, int);

	string getGenre()const override;
	void display()override;
};

// multi level inheritance (making further divisions for fiction books)
class Fantasy : public Fiction
{
private:

public:
	Fantasy(string, string, int, int, string, bool, int, int);

	string getGenre()const override;
	void display()override;
};

class Mystery : public Fiction
{
private:

public:
	Mystery(string, string, int, int, string, bool, int, int);

	string getGenre()const override;
	void display()override;
};

class ScienceFiction : public Fiction
{
private:

public:
	ScienceFiction(string, string, int, int, string, bool, int, int);

	string getGenre()const override;
	void display()override;
};

class CrimeFiction : public Fiction
{
private:

public:
	CrimeFiction(string, string, int, int, string, bool, int, int);

	string getGenre()const override;
	void display()override;
};
