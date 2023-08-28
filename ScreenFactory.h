#include <string>
#include <stdio.h>

namespace Core
{
    class ScreenFactory
    {
        public:
            bool CreateScreen();
            bool ResizeScreen(int height, int width);
            bool ReadScreen();
            bool DeleteScreen();
            ScreenFactory();
            ~ScreenFactory();
        private:
            ScreenFactory* _screenFactory;
            int _lines;
            int _columns;
            std::string **_screenMatriz;
    };
}