#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <random>
using namespace std;

int torresDeHanoi(short int,short int,short int,short int);

int main(){
    short int discos = 0;
    short int aguja_inicial = 0;
    short int aguja_auxiliar = 0;
    short int aguja_destino = 0;
    cout<<"Torres de Hanoi: "<<endl<<endl;
    cout<<"a) El numero de discos a mover.\n"
          "b) La aguja en la que estan insertados estos discos en un principio.\n"
          "c) La aguja a la que se va a mover esta pila de discos.\n"
          "d) La aguja que se va a utilizar como area de almacenamiento temporal.\n\n";

    cout<<"a / b / c / d: ";cin>>discos>>aguja_inicial>>aguja_auxiliar>>aguja_destino;
    cout<<endl;

    while(discos != -1){
        cout<<"Resultado: "<<torresDeHanoi(discos, aguja_inicial, aguja_auxiliar, aguja_destino)<<endl<<endl;
        cout<<"a / b / c / d: ";cin>>discos>>aguja_inicial>>aguja_auxiliar>>aguja_destino;
        cout<<endl;
    }
    return 0;
}

int torresDeHanoi(short int discos, short int aguja_inicial, short int aguja_auxiliar, short int aguja_destino){

    if(discos == 1){
        cout<<"1 --> 3"<<endl;
        cout<<"0 | 3 | 1"<<endl;
        return discos * torresDeHanoi((discos-1), (aguja_inicial-1), aguja_auxiliar, (aguja_destino + 1));
    }else if (discos == 0 && aguja_auxiliar == 3){
        cout<<"2 --> 3"<<endl;
        cout<<"2 --> 1"<<endl;
        cout<<"3 --> 1"<<endl;
        cout<<"2 --> 3"<<endl;
        cout<<"1 --> 2"<<endl;
        cout<<"1 --> 3"<<endl;
        cout<<"2 --> 3"<<endl;
        cout<<"0 | 0 | 4"<<endl;
        return aguja_auxiliar * torresDeHanoi((discos), aguja_inicial, (aguja_auxiliar - 1), (aguja_destino + 1));
    }
    if (aguja_destino == 4){
        return 1;
    }

    if (discos == 4){
        cout<<"1 --> 2"<<endl;
    }else if (discos == 3){
        cout<<"1 --> 3"<<endl;
    }else if (discos == 2){
        cout<<"2 --> 3"<<endl;
        cout<<"1 --> 2"<<endl;
        cout<<"3 --> 1"<<endl;
        cout<<"3 --> 2"<<endl;
        cout<<"1 --> 2"<<endl;
        cout<<"1 | 3 | 0"<<endl;
    }
    return discos * torresDeHanoi((discos - 1), (aguja_inicial-1), (aguja_auxiliar + 1), aguja_destino);
}
