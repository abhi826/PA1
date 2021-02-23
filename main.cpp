#include <iostream>
#include "lex.h"
#include <fstream>
#include <regex>
using namespace std;

int main(int argc, char* argv[] ) {
    //every  token  is  printed  when  it  is  seen followed  by  its lexeme between parentheses.
    bool vflag=false;
    //prints out all the unique integer constants in numeric order.
    bool inconstsflag=false;
    //prints out  all  the  unique real constants  in  numeric order.
    bool rconstsflag=false;
    //prints  out  all  the  unique string constants  in alphabetical order
    bool sconstsflag=false;
    //prints out  all  of  the  unique  identifiers  in  alphabetical order.
    bool idsflag=false;
    bool filePassed=false;
    string filename;

//argument parsing
    for(int i=1;i<argc;i++){
        string arg=argv[i];
        regex fileReg("[a-zA-Z0-9.]+");
        if(arg[0]=='-'){
            if(arg.compare("-v")==0){
                vflag=true;
            }
            else if( arg.compare("-iconsts")==0){
                inconstsflag=true;
            }
            else if( arg.compare("-rconsts")==0){
                rconstsflag=true;
            }
            else if(arg.compare("-sconsts")==0){
                sconstsflag=true;
            }
            else if(arg.compare("-ids")==0){
                idsflag=true;
            }
            else{
                cout<<"UNRECOGNIZED FLAG "<<arg<<endl;
                exit(1);
            }

        }
        else{
            if(regex_match(arg,fileReg)){
                if(filePassed==false){
                    filePassed=true;
                    filename=arg;
                }
                else{
                    cout<<"ONLY ONE FILE NAME ALLOWED"<<endl;
                    exit(1);
                }
            }
        }
    }
    if(filePassed==false){
       cout<<"No Specified Input File Name."<<endl;
        exit(1);
    }
    ifstream file;
    file.open(filename);
    if(!file){
        cout<<"CANNOT OPEN THE FILE "<<filename<<endl;
        exit(1);
    }






    return 0;
}
