
#include <iostream>
#include <string.h>
#include <cstring>
#include <fstream>
#include <string>
#include <map>
#include "Trie.h"

#define CONST 28

using namespace std;

void Trie::Insert(char keys[]) {
    if(root==nullptr) {//inserção no caso da arvore vazia
        root=new Node();
        strcpy(root->word,keys);
        return;
    } else {//caso arvore nao esteja vazia
        Insert(keys,root,0);
        return;
    }
}
void Trie::Insert(char keys[],Node *p,int i) {
    int index;//avalia qual o filho correspondente a determinada chave
    if(keys[i]=='\0')
        index=26;
    else if(keys[i]=='-')
        index=27;
    else
        index=keys[i]-'A';
    if(p->pNode[index]==nullptr) {//caso para aquele chave o no nao apresente filhos
        if(strcmp(p->word,"")==0) {//caso seja um no externo
            p->pNode[index]=new Node();
             strcpy( p->pNode[index]->word,keys);
            return;
        } else {//caso nao seja um nó externo
            if(strcmp(keys,p->word)==0) {//palavra ja esta na lista
                cout << keys << " " << p->word;
                return;
            } else {//caso encontre uma palavra diferente
                Insert(keys,p->word,p,i);
                strcpy(p->word,"");
                return;
            }
        }
    } else {//se o filho para aquela chave avalia a proxima chave
        Insert(keys,p->pNode[index],(i+1));
        return;
    }
}
void Trie::Insert(char keys[],char aux[],Node *p,int i) {//inserção no caso de uma palavra diferente encontrada
    int index;
    if(keys[i]=='\0')
        index=26;
    else if(keys[i]=='-')
        index=27;
    else
        index=keys[i]-'A';
    if(keys[i]==aux[i]) {//se as chaves da duas palavras forem iguais
        p->pNode[index]=new Node();
        Insert(keys,aux,p->pNode[index],(i+1));
        return;
    } else {//caso sejam diferentes
        int index2;
        if(aux[i]=='\0')
            index2=26;
        else if(aux[i]=='-')
            index2=27;
        else
            index2=aux[i]-'A';
        p->pNode[index]=new Node();
        strcpy(p->pNode[index]->word,keys);
        p->pNode[index2]=new Node();
        strcpy(p->pNode[index2]->word,aux);
        return;
    }
}
string Trie::Search(char keys[]) {//procura
    if(root==nullptr) {//caso arvore vazia
        return "\narvore vazia";
    } else {//caso arvore nao esteja vazia
        return Search(keys,root,0);
    }
}
string Trie::Search(char keys[],Node *p,int i) {
    int index;
    if(keys[i]=='\0')
        index=26;
    else if(keys[i]=='-')
        index=27;
    else
        index=keys[i]-'A';
    if(p->pNode[index]==nullptr) {//caso o no nao tenha filhos para aquela chave
        if(strcmp(p->word,"")==0) {//caso nao tenha encontrado nenhuma palavra
            return Suggest(keys,p);//sugere todas palavras que tem aquele prefixo
        } else {//caso tenha encontrado uma palavra
            if(strcmp(keys,p->word)==0) {//palavra encontrada
                return keys;
            } else {//palavra diferente encontrada
                return Suggest(keys,p);
            }
        }
    } else {//caso o no tenha filhos para aquela chave analisa a proxima chave
        return Search(keys,p->pNode[index],i+1);

    }
}
string Trie::Suggest(char keys[],Node *p) {//sugere todas a palavras que compartilham daquele no
    if(strcmp(p->word,"")!=0){
        int n;
            cout << "1-DIGITAR UMA NOVA PALAVRA";
            cout << "\n2-SUBSTITUIR " << keys << " POR " << p->word;
            cout << "\n3-MANTER " << keys;
            cout << "\nDIGITE SUA OPCAO:";
            cin >> n;
            if(n==1){
                string str;
                cout << "DIGITE A PALAVRA:";
                cin >>str;
                return str;
            }else if(n==2) return p->word;
            else return keys;
    }else{
        map<int,string> mp;
        int n;
        int mpi=3;
        cout << "1-DIGITAR UMA NOVA PALAVRA";
        cout << "\n2-MANTER " << keys;
        Suggest(keys,p,mp,mpi);
        cout << "\nDIGITE SUA OPCAO:";
        cin >> n;
         if(n==1){
                string str;
                cout << "DIGITE A PALAVRA:";
                cin >>str;
                return str;
            }else if(n==2) return keys;
            else{
                for(auto x:mp){
                    if(x.first==n)return x.second;
                }
            }
            mp.clear();
            mpi=3;
    }
}
void Trie::Suggest(char keys[],Node *p,map<int,string> &mp,int &mpi) {
    for(int i=0;i<CONST;i++){
        if(p->pNode[i]!=nullptr){
            Suggest(keys,p->pNode[i],mp,mpi);
        }
    }
    if(strcmp(p->word,"")!=0){
        mp[mpi]=p->word;
        cout << "\n" << mpi <<"-SUBSTITUIR " << keys << " POR " << p->word;
        mpi++;
    }
}
void Trie::Creator() {
    fstream file("palavras_atualizado.txt");
    if(file.is_open()) {
        string line;
        while(getline(file,line)) {
            char ch[30];
            strcpy(ch,line.c_str());
            Insert(ch);
        }
        file.close();
    }
}
void Trie::Prefix(char keys[]){
    if(root==nullptr){
        cout << "Arvore Vazia\n";
    }else
    {
        Prefix(keys,root,0);
    }
}
void Trie::Prefix(char keys[],Node *p,int i){
    int index;
    if(keys[i]=='\0')
        index=26;
    else if(keys[i]=='-')
        index=27;
    else
        index=keys[i]-'A';
        if(p->pNode[index]==nullptr ){
            if(keys[i]=='\0')
                Suggest_Prefix(p);
                else
                cout << "nao a palavras com esse prefixo";
            }else
        if(keys[i]=='\0'){
            Suggest_Prefix(p);
        }else{
        Prefix(keys,p->pNode[index],i+1);
        return;
        }
}
void Trie::Suggest_Prefix(Node *p){
    for(int i=0;i<CONST;i++){
        if(p->pNode[i]!=nullptr){
            Suggest_Prefix(p->pNode[i]);
        }
    }
    if(strcmp(p->word,"")!=0){
        cout << "\n" << p->word;
    }
}
