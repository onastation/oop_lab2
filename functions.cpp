#include "pch.h"
#include "functions.h"
using namespace std;
string find_in_line(string &line) {
	string key = "";
	string del = "  ";
	for (int i = 0; i < line.find(del); i++) {
		key += line[i];
	}
	line.erase(0, line.find(del) + 2);
	return key;
}
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