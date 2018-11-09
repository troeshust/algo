#include <iostream>
#include <string>

using namespace std;

const int HTLEN = 3 * 1000 * 1000 + 7;
const int SLEN = 10 + 7;

int count_length(const char *s) {
    // return string length, O(N)
}

void str_copy(char *destptr, const char *srcptr) {
    // copy string from src to dest, O(N)
}

bool str_compare(char *a, char *b) {
    // return true if string a == string b
}

unsigned long long count_hash(char *s, int mod = 0) {
    // polynomial hash function for string
}


// Linked List implementation

struct LLNode {
    // key, next
};

void ll_insert(LLNode **head, char *key) {
    // your code here
    // note that key already can be in ht
}

LLNode* ll_find(LLNode **head, char *key) {
    // your code here
    // return NULL if key doesnt exists in ht
}

void ll_delete(LLNode **head, char *key) {
    // your code here
    // note that key does not necessarily exist in ht
}

LLNode *ht[HTLEN];

LLNode* ht_find(char *key) {
    // your code here
}

bool is_exist(char *key) {
    // your code here
}

void ht_delete(char *key) {
    // your code here
}

void ht_insert(char *key) {
    // your code here
}

int main() {
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
