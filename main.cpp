#include <iostream>
#include "Trie.h"

using namespace std;

int main() {
    Trie t;
    t.Insert("MEU");
    t.Insert("MANO");
    t.Insert("MULHER");
    t.Search("M");
    return 0;
}
