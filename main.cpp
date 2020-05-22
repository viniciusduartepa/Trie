#include <iostream>
#include "Trie.h"

using namespace std;

int main() {
    Trie t;
    t.Insert("me-");
    t.Insert("ola");
    t.Insert("meu");
    t.Insert("mosso");
    t.Search("m");
    return 0;
}
