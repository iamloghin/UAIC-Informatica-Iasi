#include <ostream>
/*
namespace Color
{
    int FG_RED      = 31;
    int FG_GREEN    = 32;
    int FG_BLUE     = 34;
    int FG_DEFAULT  = 39;
    int BG_RED      = 41;
    int BG_GREEN    = 42;
    int BG_BLUE     = 44;
    int BG_DEFAULT  = 49;
    
class Modifier
    {
        int code;
    public:
        Modifier(int pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}
*/
void SetCursorPosition(int x, int y);
void PrintChar(char c, int foreground, int background);