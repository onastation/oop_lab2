#include "pch.h"
#include"functions.h"
using namespace std;

int main()
{
	string word = "";
	string sentence;
	hash_table dictionary;
	ifstream fin("Oxford_Dictionary.txt");
	if (fin.is_open()) {
		cout << "Wait while the table is loading..." << endl;
		fill_hash_table(fin, dictionary);
		while (true) {
			cout << "Input your sentence (type 'EXIT' to leave)" << endl;
			getline(cin, sentence);
			if (sentence == "EXIT") {
				return 0;
			}
			else {
				sentence += ' ';
				int count = count_words(sentence);
				for (int i = 0; i < count; i++) {
					word = find_word_in_a_sentence(sentence, dictionary);
					cout << "The word is: " << word << endl;
					cout << dictionary.find_in_dictionary(word) << endl << endl;
				}
				fin.close();
				system("pause");
			}
		}
	}
	else {
		cout << "unable to open file";
	}
}