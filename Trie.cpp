const int MAX_CHARACTERS = 30;
    
struct Trie {
    Trie *ch[MAX_CHARACTERS];
    bool end;
    Trie() {
        for (int i = 0 ; i < MAX_CHARACTERS; i++) {
            ch[i] = NULL;
        }
        end = false;
    }
};

Trie *root;

void insert(string s) {
    Trie *p = root;
    for (int i = 0 ; i < s.length(); i++) {
        if (p -> ch[s[i] - 'a'] == NULL) p -> ch[s[i] - 'a'] = new Trie();
        p = p -> ch[s[i] - 'a'];
    }
    p -> end = true;
}

bool find(string s) {
    Trie *p = root;
    for (int i = 0 ; i < s.length(); i++) {
        if (p -> ch[s[i] - 'a'] == NULL) return false;
        p = p -> ch[s[i] - 'a'];
    }
    return p -> end;
}
