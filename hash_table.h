#include"linked_list.h"
using namespace std;
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
	string find_in_dictionary(string key);
};