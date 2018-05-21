#include "screen.h"
//#include <exception>
using namespace scr;

void
Screen::set_rect(int x0, int y0, int x1, int y1, const Point& pt)
{
    // TODO : DONE
    if (coords_invalid(y0, x0) || coords_invalid(y1, x1))
        return;
    
    for (int x=x0; x<=x1; ++x) {
        set_point(x, x0, pt);
        set_point(x, y1, pt);
    }
    
    for (int y=y0+1; y<=y1-1; ++y) {
        set_point(x0, y, pt);
        set_point(x1, y, pt);
    }
}

void
Screen::set_line(int x0, int y0, int x1, int y1, const Point& pt)
{
    // TODO : DONE
    if (coords_invalid(y0, x0) || coords_invalid(y1, x1))
        return;
    
    //    (expression) ? true : false;
    
    if (y0 == y1) {
        int min = (x0<x1) ? x0 : x1;
        int max = (min==x0) ? x1 : x0;
        for (int x=min; x<=max; ++x)
            set_point(x, y0, pt);
    }
    else if (x0 == x1) {
        int min = (y0<y1) ? y0 : y1;
        int max = (min==y0) ? y1 : y0;
        for (int y=min; y<=max; ++y)
            set_point(x0, y, pt);
        
    }
    else if (abs((x1-x0))==abs((y1-y0))) { // fix
        
        int y_min = (y0<y1) ? y0 : y1;
        int x_of_min = (y_min==y0) ? x0 : x1;
        
        int y_max = (y_min==y0) ? y1 : y0;
        int x_of_max = (y_max==y0) ? x0 : x1;
        
        if (x_of_min < x_of_max) {
            for (int x=x_of_min, y=y_min; y<=y_max; ++x, ++y)
                set_point(x, y, pt);
        }
        else {
            for (int x=x_of_min, y=y_min; y<=y_max; --x, ++y)
                set_point(x, y, pt);
        }
    }
    else {
        try {
            throw 1;
        }
        catch(int e) {
            cout << "line not valid" << endl;
            cout << "\tx0=" << x0 << ", y0=" << y0 << ", x1=" <<  x1 << ", y1=" <<  y1 << endl;
            set_point(x0, y0, Point('X', 30, 37, true));
            set_point(x1, y1, Point('X', 30, 37, true));
        }
        
    }
    
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
    
    //TODO : DONE
    
    int size = get_nrows()*get_ncols();
    for (int i=0; i<size; ++i) {
        if ((i!=0) && (i % get_ncols() == 0))
            cout << /*"\033[0m" << */ endl;
        
        
        int fg_color = buffer[i].color_code;
        if (buffer[i].bright)
            fg_color += 60;
        
        //        cout << "\033[" << buffer[i].bright << ";" << buffer[i].color_code << ";" << buffer[i].bg_color_code << "m" << buffer[i].ch;
        cout << "\033[" << fg_color << "m\033[" << buffer[i].bg_color_code << "m" << buffer[i].ch;
        
    }
    
    //    cout << "\033[0m" << endl;
    cout << /*"\033[0m" << */ endl;
}

Screen::~Screen()
{
    //TODO: DONE
    int size = get_nrows()*get_ncols();
    for (int i=0; i <size; ++i) {
        buffer[i].~Point();
    }
    
    //    delete[]  this->buffer;
}

void
Screen::init()
{
    //TODO: DONE
    this->update_size();
    /*debug*/
    if (this->get_ncols()==0 && this->get_nrows()==-1) {
        this->ncols = 80;
        this->nrows = 23;
    }
    int size = get_ncols()*get_nrows();
    this->buffer = new Point [size];
    
    
    
}
