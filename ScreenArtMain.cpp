#include <iostream>
#include <stdio.h>
#include "ScreenFactory.h"

using namespace std;
using namespace Core;

int main()
{
    bool exitProgram = false;
    int inputvalue;

    ScreenFactory screenFactory;
    screenFactory.CreateScreen();

    do 
    { 
        try
        {
            cout<<"1) Desenhar,\n2) Redimensionar,\n3) Visualizar,\n4) Sair do Programa. "<< endl;
            cin >> inputvalue;
            
            switch (inputvalue)
            {
                case 1:
                    /* code */
                    break;
                case 2:
                    /* code */
                    break;
                case 3:
                    /* code */
                    break;
                case 4:
                    exitProgram = true;
                break;
            
            default:
                break;
           }
        }
        catch(const exception& e)
        {
            cout << "Unnexpected value, choice a correctly number." << endl;
            break;
        }
        
    } while (!exitProgram);

    return 0;
}