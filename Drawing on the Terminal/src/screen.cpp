#include "screen.h"
using namespace scr;

void
Screen::set_rect(int x0, int y0, int x1, int y1, const Point& pt)
{
    // TODO
}

void
Screen::set_line(int x0, int y0, int x1, int y1, const Point& pt)
{
    // TODO
}

void
Screen::set_circle(int x, int y, int rad, const Point& pt)
{
    int icol = rad;
    int irow = 0;
    int error = 1 - icol;
    while (icol >= irow) {
        set_point(icol + x, irow + y, pt);
        set_point(irow + x, icol + y, pt);
        set_point(-icol + x, irow + y, pt);
        set_point(-irow + x, icol + y, pt);
        set_point(-icol + x, -irow + y, pt);
        set_point(-irow + x, -icol + y, pt);
        set_point(icol + x, -irow + y, pt);
        set_point(irow + x, -icol + y, pt);
        
        irow++;
        
        if (error < 0) {
            error += 2 * irow + 1;
        } else {
            icol--;
            error += 2 * (irow - icol + 1);
        }
    }
}
void
Screen::render()
{
    ensure_initialized();
    //TODO
}

Screen::~Screen()
{
    //TODO
}

void
Screen::init()
{
    //TODO
}
