const int MAX_CHARACTERS = 30;
    
struct Node {
    Node *ch[MAX_CHARACTERS];
    int cnt;
    Node() {
        for (int i = 0 ; i < MAX_CHARACTERS; i++) {
            ch[i] = NULL;
        }
        cnt = 0;
    }
};

Node *root;

void insert(string s) {
    Node *p = root;
    for (int i = 0 ; i < s.length(); i++) {
        if (p -> ch[s[i] - 'a'] == NULL) p -> ch[s[i] - 'a'] = new Node();
        p = p -> ch[s[i] - 'a'];
    }
    p -> cnt++;
}

int count(string s) {
    Node *p = root;
    for (int i = 0 ; i < s.length(); i++) {
        if (p -> ch[s[i] - 'a'] == NULL) return 0;
        p = p -> ch[s[i] - 'a'];
    }
    return p -> cnt;
}
