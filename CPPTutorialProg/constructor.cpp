
#include "constructor.h"
#include <iostream>

using namespace std;


Bucky::Bucky(int num): h(num)
{
    //ctor
}


void Bucky::PrintCrap(){
    cout<<"h= " << h << endl;
    cout<<"this->h=" << this->h << endl;
    //Remember This Stores the address of the current object
    cout<<"(*this).h=" << (*this).h<< endl;
}


int main(){

    Bucky bkid(69);
    bkid.PrintCrap();
}
