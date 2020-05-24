#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <fstream>
#include "Trie.h"

using namespace std;

int main() {
    Trie t;
    string a;
    cout << "\nDigite a palavra que deseja pesquisar:";
    cin >> a;
    while(a!="1") {
        char c[50];
        strcpy(c,a.c_str());
        t.Prefix(c);
        //cout << t.Search(c);
        cout << "\nDigite a palavra que deseja pesquisar:";
        cin >> a;
    }
    //t.Show();
    return 0;
}
