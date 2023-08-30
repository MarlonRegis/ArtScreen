#include "ScreenFactory.h"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace Core;

void ScreenFactory::CreateScreen(int lines, int columns){

    _lines = lines;
    _columns = columns; 
    _screenMatriz = new std::string *[_lines];
    
    for (int i = 0; i < _lines; i++) {
        _screenMatriz[i] = new std::string[_columns];
    }
    cout << "Created Screen" << endl;
}

void ScreenFactory::SetEmptyScreen(){

    for (int i = 0; i < _lines; i++) 
    {
        for (int j = 0; j < _columns; j++) 
        {
            _screenMatriz[i][j]=" ";
        }
    }
}

void ScreenFactory::DrawScreen(int lines, int columns, char valueDraw){
    _screenMatriz[lines][columns]=valueDraw;
}

void ScreenFactory::DeleteScreen(){
    
    for (int i = 0; i < _lines; i++) {
        delete[] _screenMatriz[i]; // Libera memória das linhas
    }
    delete[] _screenMatriz; 
}

void ScreenFactory::ReadScreen(){

    for (int i = 0; i < _lines; i++) 
    {
        for (int j = 0; j < _columns; j++) 
        {
            cout << _screenMatriz[i][j];
        }
        cout << "\n"<< endl;
    }
}

void ScreenFactory::ResizeScreen(int lines, int columns){
    int oldLines = _lines;
    int oldColumns = _columns;
    std::string ** oldScreen = new std::string *[oldLines];
    for (int i = 0; i < oldLines; i++) {
        _screenMatriz[i] = new std::string[oldColumns];
    }
    
    oldScreen =_screenMatriz;
    ScreenFactory::DeleteScreen();
    ScreenFactory::CreateScreen(lines, columns);

    try
    {
        ScreenFactory::SetEmptyScreen(); 
    
        for (int i = 0; i < _lines; i++) 
        {
            cout << "first for" << endl;    
    
            for (int j = 0; j < _columns; j++) 
            {
                cout << "second for "<< j  << " and old columns is "<< _columns << endl; 
                _screenMatriz[i][j] = oldScreen[i][j];
            }
        }
        cout << "for passed" << endl; 


        for (int i = 0; i < oldLines; i++) 
        {
            cout << "VALUE I IS "<< i << " AND THE OLD LINES IS "<< oldLines << endl; 
            cout << "matrix point "<< oldScreen[i] << endl; 
            cout << "matrix point "<< _screenMatriz[i] << endl; 
            delete[] oldScreen[i];
            cout << "deleting old screen" << endl; 
        }
        delete[] oldScreen; 
    }
    catch(const exception& ex)
    {
        cout << "Unnexpected error during the resize" << endl;
    }
}