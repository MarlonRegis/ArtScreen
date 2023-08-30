#include <string>
#include <stdio.h>

namespace Core
{
    class ScreenFactory
    {
        public:
            void CreateScreen(int lines, int columns);
            void SetEmptyScreen();
            void ResizeScreen(int lines, int columns);
            void DrawScreen(int lines, int columns, char valueDraw);
            void ReadScreen();
            void DeleteScreen();
            ScreenFactory() = default;
            ~ScreenFactory() = default;
        private:
            int _lines;
            int _columns;
            std::string **_screenMatriz;
    };
}