#include"pch.h"
#include"hash_table.h"
using namespace std;
const int hash_table::init_SIZE = 200;
const double hash_table::resize_indicator = 160;

hash_table::hash_table() {
	num = 0;
	SIZE = init_SIZE;
	list = new linked_list[SIZE];
}

hash_table::hash_table(int size) {
	this->num = 0;
	this->SIZE = size;
	this->list = new linked_list[this->SIZE];
}

hash_table::~hash_table() {
	delete[] list;
}

void hash_table::resize() {
	linked_list* old_list = list;
	int old_size = SIZE;
	num = 0;
	SIZE *= 2;
	list = new linked_list[SIZE];
	for (int i = 0; i < old_size; i++) {
		for (int j = 0; j < old_list[i].getSIZE(); j++) {
			element* temp = old_list[i].getWord(j);
			this->add_term(temp->getKey(), temp->getData());
		}
	}
}

void hash_table::check_fill() {
	double verificator = num / SIZE * 100;
	if (verificator > resize_indicator) {
		resize();
	}
}

int hash_table::hash(string word) {
	int hash = 0;
	for (int i = 0; i < word.length(); i++) {
		hash += abs(static_cast<int>(word[i]))*(i + 1);
	}
	return hash % SIZE;
}

void hash_table::add_term(string key, string definition) {
	num++;
	list[hash(key)].add_word(key, definition);
	check_fill();
}

string hash_table::find_in_dictionary(string key)
{
	return list[hash(key)].search_by_the_key(key);
}