#include <iostream>
#include <string>  // only for reading commands

using namespace std;

const int HTLEN = 3 * 1000 * 1000 + 7;  // must be at least 2 * N
const int SLEN = 10 + 7;

int count_length(const char *s) {
    // return string length, O(N)
}

void str_copy(char *destptr, const char *srcptr) {
    // copy string from src to dest, O(N)
}

bool str_compare(const char *a, const char *b) {
    // return true if string a == string b
}

unsigned long long count_hash(char *s, int mod = 0) {
    // polynomial hash function for string
}

char ht[HTLEN][SLEN];  // our hash table
bool is_deleted[HTLEN];

int ht_find(char *key) {
    // return index of given string in ht
}

bool is_exist(char *key) {
    // return true if key can be found in ht
}

void ht_delete(char *key) {
    // your code here
}

void ht_insert(char *key) {
    // your code here
}

void ht_init() {
    // init is_deleted and ht
}

int main() {
    ht_init();
    while (true) {
        string str;
        cin >> str;
        if (str == "#") {
            return 0;
        } else if (str == "+") {
            char key[SLEN];
            cin >> key;
            ht_insert(key);
        } else if (str == "-") {
            char key[SLEN];
            cin >> key;
            ht_delete(key);
        } else if (str == "?") {
            char key[SLEN];
            cin >> key;
            cout << (is_exist(key) ? "YES" : "NO") << endl;
        } else {
            cout << "wtf?.." << endl;
        }
    }
    return 0;
}
