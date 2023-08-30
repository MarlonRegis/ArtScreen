#include <iostream>
#include <stdio.h>
#include "ScreenFactory.h"

using namespace std;
using namespace Core;

void PrintScreen()
{
    std::cout << "---ART Screen---" << std::endl;
    std::cout << "Choose an option: " << std::endl;
    std::cout << "1- Draw value" << std::endl;
    std::cout << "2- Change size" << std::endl;
    std::cout << "3- Show screen" << std::endl;
    std::cout << "4- Exit" << std::endl;
}

int main()
{
    bool exitProgram = false;
    int inputvalue;

    ScreenFactory screenFactory;
    screenFactory.CreateScreen(20,40);
    screenFactory.SetEmptyScreen();

    do 
    { 
        try
        {
            PrintScreen();
            cin >> inputvalue;

            int line;
            int column;
            char valueDraw;

            switch (inputvalue)
            {
                case 1:
                    cout<<"Enter the row: "<< endl;
                    cin >> line;
                    cout<<"Enter the column: "<< endl;
                    cin >> column;
                    cout<<"Enter the value: "<< endl;
                    cin >> valueDraw;
                    screenFactory.DrawScreen(line-1, column-1, valueDraw);
                    break;
                case 2:
                    cout << "Enter the number of rows" << std::endl;
                    cin >> line;
                    cout << "Enter the numbers of columns" << std::endl;
                    cin >> column;
                    
                    screenFactory.ResizeScreen(line, column);
                    break;
                case 3:
                    screenFactory.ReadScreen();
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