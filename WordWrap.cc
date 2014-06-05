#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
 string theArg , theArgArg, theTest;



    int wraplen = 25, wordlen = 0, currlen= 0, emswitch= 0;
    //wraplen, length of ever lines wrap
    //wordlen, length of the current word
    //currlen, number of characters on current line

    if(argc == 2){

        theArgArg = argv[1];
        fstream inarg;
        inarg.open(theArgArg.c_str());
        inarg >> wraplen;

    }

    string content;
    string word;


    while(true){
        cin >> word;
        if(cin.fail()){
            cin.clear();
            break;
        }
        content = content + " " + word;
    }


        stringstream buffer(content);


    while (buffer >> word)
    {

	emswitch = 1;
    wordlen = word.length();
        //cout << wordlen;
        if(currlen > 0 && currlen + wordlen <= wraplen){
            cout<<' ';
            currlen++;
        }


        if (wordlen > wraplen){


            if(currlen > 0){
                cout<< endl;
            }
            currlen = 0;
        int a =0;
        while( a < wordlen / wraplen ){
           
	 for(int i = 0; i < wraplen; i++){
                cout << word.at(i+(a*wraplen));
            }
	//Changed to 0 from 1
     
	         if((wordlen - (a*wraplen))  != wraplen  ){
                    cout << endl;
                }
            a++;
        }


        for(int i = wraplen*a; i < wordlen; i++){
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

	if(emswitch == 1){
	    cout << endl;
	}
}

