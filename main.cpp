#include <iostream>

using namespace std;
#define ALPHABET_SIZE 26

class Trie {
private:
    class Node {
    public:
        Node *pNode[ALPHABET_SIZE];
        char *word;
        Node() {
            for(int j=0; j<ALPHABET_SIZE; j++)
                pNode[j]=nullptr;
            word=nullptr;
        };
    };
    Node *root;
public:
    void Insert(char keys[]);
    Trie() {
        root=nullptr;
    };
};
void Trie::Insert(char keys[]) {
    if(root==nullptr) {
        root=new Node();
        root->word=keys;
        return;
    }
}
int main(){
    return 0;
}
