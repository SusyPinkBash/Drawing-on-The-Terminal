#ifndef __SCREEN_H__
#define __SCREEN_H__

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif

#include <cstdlib>
#include <iostream>
#include <sys/ioctl.h>

namespace scr {
    
    using std::cout;
    using std::endl;
    
    typedef unsigned char byte;
    
    class Point
    {
    public:
        char ch;
        byte color_code;
        byte bg_color_code;
        bool bright;
        
        static const int default_color = 37;
        static const int default_color_bg = 40;
        
        Point()
        : ch(' ')
        , color_code(default_color)
        , bg_color_code(default_color_bg)
        , bright(true)
        {}
        Point(char ch, byte color_code)
        : ch(ch)
        , color_code(color_code)
        , bg_color_code(default_color_bg)
        , bright(true)
        {}
        Point(char ch, byte color_code, byte bg_color_code, bool bright)
        : ch(ch)
        , color_code(color_code)
        , bg_color_code(bg_color_code)
        , bright(bright)
        {}
        // Added Copy constructor
        Point(Point & p)
        : ch(p.ch)
        , color_code(p.color_code)
        , bg_color_code(p.bg_color_code)
        , bright(p.bright)
        {}
        ~Point() {}
    };
    
    class Screen
    {
    private:
        Point* buffer;
        int    ncols;
        int    nrows;
        
    public:
        Screen()
        : buffer(0)
        {
            init();
        }
        ~Screen();
        
        int  get_ncols() const { return ncols; }
        int  get_nrows() const { return nrows; }
        void clear() const { cout << "\033[2J"; }
        void set_line(int x0, int y0, int x1, int y1, const Point& pt);
        void set_rect(int x0, int y0, int x1, int y1, const Point& pt);
        void set_circle(int x, int y, int rad, const Point& pt);
        void render();
        
    private:
        void set_point(int icol, int irow, const Point& pt)
        {
            ensure_initialized();
            if (coords_invalid(irow, icol))
                return;
            buffer[ncols * irow + icol] = pt;
        }
        void set_color(int color_code) const { cout << "\033[" << color_code << "m"; }
        bool coords_invalid(int irow, int icol)
        {
            ensure_initialized();
            return irow < 0 || icol < 0 || irow >= nrows || icol >= ncols;
        }
        void ensure_initialized()
        {
            if (!buffer)
                init();
        }
        void init();
        
        void update_size() {
#ifdef TIOCGSIZE
            struct ttysize ts;
            ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
            ncols = ts.ts_cols;
            nrows = ts.ts_lines;
#elif TIOCGWINSZ
            struct winsize ts;
            ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
            ncols = ts.ws_col;
            nrows = ts.ws_row;
#else
            ncols = 80;
            nrows = 40;
#endif
            --nrows;
        }
    };
} // namespace scr

#endif // __SCREEN_H__
