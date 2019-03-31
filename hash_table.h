#include"linked_list.h"
class hash_table {
private:
	linked_list* list;
	int SIZE;
	int num;
	const static int init_SIZE;
	const static double resize_indicator;
	void resize();
	void check_fill();
	int hash(string key);
public:
	hash_table();
	hash_table(int size);
	~hash_table();
	void add_term(string key, string definition);
	string find_in_table(string key);
};
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

string hash_table::find_in_table(string key)
{
	if (list[hash(key)].getSIZE() == 0) {
		cout << "Sorry. The requested word wasn't found" << endl;
		exit(1);
	}
	return list[hash(key)].search_in_dictionary(key);
}
//function that separates a word from its definition and returns that word
string find_in_line(string &line) {
	string key = "";
	string del = "  ";
	for (int i = 0; i < line.find(del); i++) {
		key += line[i];
	}
	line.erase(0, line.find(del) + 2);
	return key;
}
//function that parces the .txt file and fills a hash table
istream& fill_hash_table(ifstream &fin, hash_table &dictionary) {
	string key = "";
	string line;
	while (getline(fin, line)) {
		key = find_in_line(line);
		for (int i = 0; i < key.length(); i++) {
			key[i] = tolower(key[i]);
		}
		dictionary.add_term(key, line);
	}
	return fin;
}