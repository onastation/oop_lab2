#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class element {
private:
	string key;
	string data;
	element* next;
public:
	element();
	element(string key, string data);
	void setNext(element* next);
	void setKey(string key);
	void setData(string data);
	element* getNext();
	string getKey();
	string getData();
};

class linked_list {
private:
	int SIZE;
	element* front;
	element* back;
public:
	linked_list();
	~linked_list();
	int getSIZE();
	element* getWord(int index);
	void add_word(string key, string data);
	string search_by_the_key(string key);
};
