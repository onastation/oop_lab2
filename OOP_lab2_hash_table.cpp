#include "pch.h"
#include"functions.h"
using namespace std;

int main()
{
	string word;
	string key = "";
	hash_table dictionary;
	ifstream fin("Oxford_Dictionary.txt");
	if (fin.is_open()) {
		cout << "Wait while the table is loading" << endl;
		fill_hash_table(fin, dictionary);
		while (true) {
			cout << "Input your word (type 'EXIT' to leave): ";
			getline(cin, word);
			if (word == "EXIT") {
				return 0;
			}
			else {
				for (int i = 0; i < word.length(); i++) {
					word[i] = tolower(word[i]);
				}
				cout << dictionary.find_in_table(word) << endl << endl;
			}
		}
		fin.close();
		system("pause");
	}
}