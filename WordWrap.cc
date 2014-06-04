#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
 string theArg , theArgArg, theTest;



    int wraplen = 25, wordlen = 0, currlen= 0;
    //wraplen, length of ever lines wrap
    //wordlen, length of the current word
    //currlen, number of characters on current line

    theArg = argv[1];
    theArgArg = argv[2];

    ifstream infile;
    infile.open(theArg.c_str()); //This is a c-style string, For some reason it doesnt accept normal strings
    string word;

    fstream inarg;
    inarg.open(theArgArg.c_str());
    inarg >> wraplen;



    while (infile >> word)
    {

    wordlen = word.length();
        //cout << wordlen;
        if(currlen > 0 && currlen + wordlen < wraplen){
            cout<<' ';
            currlen++;
        }


        if (wordlen > wraplen){

            if(currlen > 0){
                cout<< endl;
            }
            currlen = 0;

            for(int i = 0; i < wraplen; i++){
                cout << word.at(i);
            }
            cout << endl;

            for(int i = wraplen; i < wordlen; i++){
                cout << word.at(i);
                currlen++;
            }


        }else if(wordlen + currlen > wraplen){

            currlen = 0;
            currlen += wordlen ;
            cout << endl;
            cout << word;

            //if(currlen > wraplen){
            //}


        }else if(wordlen + currlen <= wraplen){
            currlen += wordlen;
            cout << word ;
        }


    }

    cout << endl;

}

