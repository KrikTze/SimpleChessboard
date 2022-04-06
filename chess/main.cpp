#include <iostream>
#include <string>
#include "chessboard.h"
using namespace std;


int main()
{
    cout << "Hello World" << endl;
    chessboard *myboard;
    myboard = new chessboard();
    myboard->play();
    
    delete myboard;

}