#include "pch.h"
#include "functions.h"
using namespace std;
int count_words(string sentence) {
	int count = 0;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == ' ' || sentence[i] == ',') {
			count++;
			if (sentence[i + 1] == ' ' || sentence[i + 1] == ',') {
				count--;
			}
		}
	}
	return count;
}
string find_word_in_a_sentence(string &sentence, hash_table &dictionary) {
	string word = "";
	int j = 0;
	while (sentence[j] != ' ' && sentence[j] != ',') {
		sentence[j] = tolower(sentence[j]);
		word += sentence[j];
		j++;
	}
	sentence.erase(0, word.length());
	int k = 0;
	while (sentence[k] == ' ' || sentence[k] == ',') {
		k++;
	}
	sentence.erase(0, k);
	return word;
}
istream& fill_hash_table(ifstream &fin, hash_table &dictionary) {
	string word = "";
	string definition;
	string line;
	while (getline(fin, line)) {
		for (int i = 0; i < line.find("  "); i++) {
			line[i] = tolower(line[i]);
			word += line[i];
		}
		line.erase(0, word.length() + 2);
		definition = line;
		dictionary.add_term(word, definition);
		word = "";
	}
	return fin;
}