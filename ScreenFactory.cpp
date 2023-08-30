#include "ScreenFactory.h"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace Core;

ScreenFactory::ScreenFactory()
{
    _screenFactory = new ScreenFactory();
}

ScreenFactory::~ScreenFactory()
{
    delete _screenFactory;
}

void ScreenFactory::CreateScreen(int lines = 20, int columns = 40){

    _lines = lines;
    _columns = columns; 
    _screenMatriz = new std::string *[_lines];
    
    for (int i = 0; i < _lines; i++) {
        _screenMatriz[i] = new std::string[_columns];
    }
}

bool ScreenFactory::DeleteScreen(){
    
    for (int i = 0; i < _lines; i++) {
        delete[] _screenMatriz[i]; // Libera memória das linhas
    }

    delete[] _screenMatriz; 

    return true;
}

bool ScreenFactory::ReadScreen(){

    for (int i = 0; i < _lines; i++) 
    {
        for (int j = 0; j < _columns; j++) 
        {
            cout << _screenMatriz[i][j];
        }
        cout << "\n"<< endl;
    }

    return true;
}

bool ScreenFactory::ResizeScreen(int lines, int columns){
    int oldLines = _lines;
    int oldColumns = _columns;
    std::string ** oldScreen = _screenMatriz;
    ScreenFactory::DeleteScreen();

    ScreenFactory::CreateScreen(lines, columns);

    try
    {
        for (int i = 0; i < oldLines && i <= _lines; i++) 
        {
            for (int j = 0; j < oldColumns && j <= _columns; j++) 
            {
                _screenMatriz[i][j] = oldScreen[i][j];
            }
        }

        return true;
    }
    catch(const exception& ex)
    {
        cout << "Unnexpected error during the resize" << endl;

        return true;
    }
}