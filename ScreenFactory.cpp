#include "ScreenFactory.h"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace Core;

ScreenFactory::~ScreenFactory()
{
    ScreenFactory::DeleteScreen(_screenMatriz);
}

void ScreenFactory::CreateScreen(int lines, int columns)
{

    _lines = lines;
    _columns = columns; 
    _screenMatriz = new std::string *[_lines];
    
    for (int i = 0; i < _lines; i++) {
        _screenMatriz[i] = new std::string[_columns];
    }
    cout << "Created Screen" << endl;
}

void ScreenFactory::SetEmptyScreen()
{

    for (int i = 0; i < _lines; i++) 
    {
        for (int j = 0; j < _columns; j++) 
        {
            _screenMatriz[i][j]=" ";
        }
    }
}

void ScreenFactory::DrawScreen(int lines, int columns, char valueDraw)
{
    _screenMatriz[lines][columns]=valueDraw;
}

void ScreenFactory::DeleteScreen(std::string** matriz)
{
    for (int i = 0; i < _lines; i++) {
        delete[] matriz[i]; // Libera memória das linhas
    }
    delete[] matriz;
}

void ScreenFactory::ReadScreen()
{

    for (int i = 0; i < _lines; i++) 
    {
        for (int j = 0; j < _columns; j++) 
        {
            cout << _screenMatriz[i][j];
        }
        cout << "\n"<< endl;
    }
}

void ScreenFactory::ResizeScreen(int lines, int columns)
{
    std::string ** oldScreen = _screenMatriz;
    ScreenFactory::CreateScreen(lines, columns);

    try
    {
        ScreenFactory::SetEmptyScreen(); 
    
        for (int i = 0; i < _lines; i++) 
        {
            for (int j = 0; j < _columns; j++) 
            {
                _screenMatriz[i][j] = oldScreen[i][j];
            }
        }

        ScreenFactory::DeleteScreen(oldScreen);
    }
    catch(const exception& ex)
    {
        cout << "Unnexpected error during the resize" << endl;
    }
}