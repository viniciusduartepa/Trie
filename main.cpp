#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "Trie.h"

using namespace std;
int menu() {
    system("cls");
    int n;
    cout << "CORRETOR ORTOGRAFICO!!\n";
    cout << "(OBS: O CORRETOR SO FUNCIONA PARA CARACTERES MAIUSCULOS)\n";
    cout << "[1]-PARA CORRIGIR UM ARQUIVO.TXT\n";
    cout << "[2]-PARA PROCURAR PALAVRAS NO DICIONARIO\n";
    cout << "[3]-PARA ENCERRAR O PROGRAMA\n";
    cout << "DIGITE SUA OPCAO:";
    cin >> n;
    return n;
}

int main() {
    Trie t;
    int n;
    n = menu();
    while(n!=3) {
        switch(n) {
        case 1: {
            system("cls");
            cout << "DIGITE O DIRETORIO DO ARQUIVO QUE DESEJA CORRIGIR:";
            string dir;
            cin >> dir;
            string word;
            fstream file;
            fstream file1;
            file1.open("corrigido.txt",fstream::out);
            if(file1.is_open()) {
                file1 << "";
                file1.close();
            } else
                cout << "arquivo correcao nao aberto";
            file1.open("corrigido.txt",fstream::out|fstream::app);
            file.open(dir.c_str());
            if(file.is_open()&&file1.is_open()) {
                while(file>>word) {
                    char c[50];
                    strcpy(c,word.c_str());
                    string aux=t.Search(c);
                    file1 << aux << " ";
                }
                file.close();
            } else
                cout << "arquivos nao foram abertos";
            cout << "O ARQUIVO CORRIGIDO ESTA NO ARQUIVO: corrigido.txt";
            cout << endl ;
            system("pause");
        }
        break;
        case 2: {
            system("cls");
            char c[50];
            cout << "DIGITE O PREFIXO DAS PALAVRAS QUE DESEJA PROCURAR: ";
            cin >> c;
            t.Prefix(c);
            cout << endl << endl;
            system("pause");
        }
        break;
        case 3:
            break;

        default:
            cout << "OPCAO INVALIDA";
            system("pause");
        }
        n=menu();
    }
    return 0;

}
