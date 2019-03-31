#include "hash_table.h"
using namespace std;
int count_words(string sentence);
string find_word_in_a_sentence(string &sentence, hash_table &dictionary);
istream& fill_hash_table(ifstream &fin, hash_table &dictionary);