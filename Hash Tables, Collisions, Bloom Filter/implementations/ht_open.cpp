#include <iostream>
#include <string> // only for reading commands

using namespace std;

const int HTLEN = 3 * 1000 * 1000 + 7; // must be > 2 * N
const int SLEN = 10 + 7;

int count_length(const char *s) {
    int idx = 0;
    while (s[idx] != '\0') {
        ++idx;
    } 
    return idx;
}

void str_copy(char *destptr, const char *srcptr) {
    size_t len = count_length(srcptr);
    for (int i = 0; i < len; ++i) {
        destptr[i] = srcptr[i];
    }
}

// returns true if string a == string b
bool str_compare(const char *a, const char *b) {
    size_t a_len = count_length(a);
    size_t b_len = count_length(b);
    if (a_len != b_len) {
        return false;
    } else {
        for (int i = 0; i < a_len; ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }
    }
    return true;
}


// polynomial hash function for string
unsigned long long count_hash(char *s, int mod = 0) {
    const int p = 31;
    unsigned long long hash = 0, p_pow = 1;
    int len = count_length(s);
    for (size_t i = 0; i < len; ++i) {
        hash += (s[i] - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    return mod ? hash % mod : hash;
}

char ht[HTLEN][SLEN];
bool is_deleted[HTLEN];

int ht_find(char *key) {
    unsigned long long idx = count_hash(key, HTLEN);
    while(true) {
        if (str_compare(ht[idx], "")) {
            return -1;
        }
        if (str_compare(ht[idx], key) && !is_deleted[idx]) {
            return idx;
        }
        ++idx;
        idx %= HTLEN;
    }
}

bool is_exist(char *key) {
    return ht_find(key) != -1;
}

void ht_delete(char *key) {
    unsigned long long idx = ht_find(key);
    if (idx != -1) {
        is_deleted[idx] = 1;
    }
}

void ht_insert(char *key) {
    unsigned long long idx = count_hash(key, HTLEN);
    while(!str_compare(ht[idx], "") && !is_deleted[idx]) {
        ++idx;
        idx %= HTLEN;
    }
    str_copy(ht[idx], key);
    is_deleted[idx] = 0;
}

void ht_init() {
    for (int i = 0; i < HTLEN; ++i) {
        is_deleted[i] = 0;
        str_copy(ht[i], "");
    }
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
