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
            if (!(cin >> inputvalue))
                throw std::invalid_argument("Unnexpected value, choice a correctly number!");

            int line;
            int column;
            char valueDraw;

            switch (inputvalue)
            {
                case 1:
                    cout<<"Enter the row: "<< endl;
                    if (!(cin >> line))
                        throw std::invalid_argument("Unnexpected line, choice a correctly line!");
                    cout<<"Enter the column: "<< endl;
                    if (!(cin >> column))
                        throw std::invalid_argument("Unnexpected column, choice a correctly column!");
                    cout<<"Enter the value: "<< endl;
                    cin >> valueDraw;
                    screenFactory.DrawScreen(line-1, column-1, valueDraw);
                    break;
                case 2:
                    cout << "Enter the number of rows" << std::endl;
                    if (!(cin >> line))
                        throw std::invalid_argument("Unnexpected line, choice a correctly line!");
                    cout << "Enter the numbers of columns" << std::endl;
                    if (!(cin >> column))
                        throw std::invalid_argument("Unnexpected column, choice a correctly column!");
                    
                    screenFactory.ResizeScreen(line, column);
                    break;
                case 3:
                    screenFactory.ReadScreen();
                    break;
                case 4:
                    exitProgram = true;
                    break;
                default:
                    cout << "Unnexpected value, choice a correctly number." << endl;
                    break;
           }
        }
        catch(const exception& e)
        {
            cout << e.what() << endl;
            break;
        }
        
    } while (!exitProgram);

    return 0;
}