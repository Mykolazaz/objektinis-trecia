#include <iostream>
#include <vector>
using namespace std;


struct Studentas{
    string vardas;
    string pavarde;
    int tarpRez[15];
    int egzamRez;
};


int main(){
    vector<Studentas> studentai;
    int studSk;

    cout << "Apie kiek studentų pildysite informaciją?:" << endl;
    cin >> studSk;
    studentai.resize(studSk);

    for (int i=0; i < studSk; i++){
        cout << "Įveskite studento vardą, pavardę ir egz. įvertinimą: " << endl;
        cin >> studentai[i].vardas >> studentai[i].pavarde >> studentai[i].egzamRez;
    }

    for (int i=0; i < studSk; i++){
        cout << studentai[i].vardas << studentai[i].pavarde << studentai[i].egzamRez << endl;
    }

    return 0;
}