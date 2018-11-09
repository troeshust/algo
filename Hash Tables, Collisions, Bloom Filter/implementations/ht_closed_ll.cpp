#include <iostream>
#include <string>

using namespace std;

const int HTLEN = 3 * 1000 * 1000 + 7;
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

bool str_compare(char *a, char *b) {
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

struct LLNode {
    char key[SLEN];
    LLNode *next;
};

void ll_insert(LLNode **head, char *key) {
    LLNode *node = new LLNode();
    size_t len = count_length(key);
    str_copy(node->key, key);
    if (*head) {
        node->next = *head;
    } else {
        node->next = NULL;
    }
    *head = node;
}

LLNode* ll_find(LLNode **head, char *key) {
    LLNode *p = *head;
    while(p && !str_compare(p->key, key)) {
        p = p->next;
    }
    return p;
}

void ll_delete(LLNode **head, char *key) {
    LLNode *prev = NULL;
    LLNode *cur = *head;
    while(cur && !str_compare(cur->key, key)) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) {
        return;
    } else if (!prev) {
        *head = cur->next;
    } else {
        prev->next = cur->next;
    }
    delete cur;
}

LLNode *ht[HTLEN];

LLNode* ht_find(char *key) {
    unsigned long long idx = count_hash(key, HTLEN);
    LLNode *head = ht[idx];
    return ll_find(&head, key);
}

bool is_exist(char *key) {
    return ht_find(key) != NULL;
}

void ht_delete(char *key) {
    unsigned long long idx = count_hash(key, HTLEN);
    ll_delete(&ht[idx], key);
}

void ht_insert(char *key) {
    unsigned long long idx = count_hash(key, HTLEN);
    if (!ll_find(&ht[idx], key)) {
        ll_insert(&ht[idx], key);
    }
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
