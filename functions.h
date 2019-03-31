#include "hash_table.h"
using namespace std;
string find_in_line(string &line); //function that separates a word from its definition and returns that word
istream& fill_hash_table(ifstream &fin, hash_table &dictionary); //function that parses the .txt file and fills a hash table