vec<int> kmppre(string& t){ //r[i]: longest border of t[0,i)
    vec<int> r(t.size()+1);
    r[0] = -1;
    int j = -1;
    for(int i = 0; t[i]; i++){
        while(j >= 0 && t[i] != t[j]) j = r[j];
        r[i+1] = ++j;
    }return r;
}

void kmp(string& s, string& t){ //find t in s
    int j = 0;
    vec<int> b = kmppre(t);
    for(int i = 0; s[i]; i++){
        while(j >= 0 && s[i] != t[j]) j = b[j];
        if(++j == t.size()) {
            cout << "Match at " << i - j + 1 << '\n';
            j = b[j];
        }
    }
}
