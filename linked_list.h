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
	string search_in_dictionary(string key);
};
element::element() {
	key = "";
	data = "";
	next = nullptr;
}

element::element(string key, string data) {
	this->key = key;
	this->data = data;
	next = nullptr;
}

void element::setNext(element* next) {
	this->next = next;
}

void element::setKey(string key) {
	this->key = key;
}

void element::setData(string data) {
	this->data = data;
}

element* element::getNext() {
	return next;
}

string element::getKey() {
	return key;
}

string element::getData() {
	return data;
}

linked_list::linked_list() {
	SIZE = 0;
	front = nullptr;
	back = nullptr;
}

linked_list::~linked_list() {
	element *dlt = back;
	while (dlt) {
		dlt = back;
		if (!dlt) {
			break;
		}
		back = back->getNext();
		delete dlt;
	}
}

void linked_list::add_word(string key, string data) {
	SIZE++;
	element* last = back;
	back = new element(key, data);
	if (!last) {
		front = back;
	}
	else {
		last->setNext(back);
	}
}

element* linked_list::getWord(int index) {
	if (index >= SIZE || index < 0) {
		exit(1);
	}
	element* temp = front;
	int temp_index = 0;
	while (temp) {
		if (temp_index == index) {
			return temp;
		}
		temp_index++;
		temp = temp->getNext();
	}
	exit(1);
}

string linked_list::search_in_dictionary(string key) {
	element* temp = front;
	while (temp) {
		if (temp->getKey() == key) {
			return temp->getData();
		}
		temp = temp->getNext();
	}
	return "Sorry. The requested word wasn't found.";
}

int linked_list::getSIZE() {
	return SIZE;
}