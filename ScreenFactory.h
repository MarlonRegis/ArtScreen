#include <string>
#include <stdio.h>

namespace Core
{
    class ScreenFactory
    {
        public:
            void CreateScreen(int lines = 20, int columns = 40);
            bool ResizeScreen(int lines, int columns);
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