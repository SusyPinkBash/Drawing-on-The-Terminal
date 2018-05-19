#include "screen.h"
#include <iostream>

int
main()
{
    using namespace scr;
    
    Screen screen;
    screen.clear();
    
    Point ptred('-', 31, 46, false);
    Point ptred2('*', 31, 40, true);
    Point ptyellow('@', 33, 43, true);
    Point ptcyan('v', 36, 43, true);
    Point ptblue('#', 34, 40, false);
    
    screen.set_rect(0, 0, screen.get_ncols() - 1, screen.get_nrows() - 1, ptred);
    screen.set_rect(1, 1, screen.get_ncols() - 2, screen.get_nrows() - 2, ptyellow);
    screen.set_circle(30, 15, 10, ptblue);
    screen.set_circle(25, 12, 2, ptred2);
    screen.set_circle(35, 12, 2, ptred2);
    screen.set_circle(25, 12, 0, ptred2);
    screen.set_circle(35, 12, 0, ptred2);
    
    screen.set_line(27, 21, 33, 21, ptcyan);
    screen.set_line(25, 19, 26, 20, ptcyan);
    screen.set_line(33, 21, 35, 20, ptcyan);
    
    screen.render();
    
    return 0;
}
