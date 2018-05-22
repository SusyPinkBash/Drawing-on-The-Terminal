#ifndef __CSCREEN_H__
#define __CSCREEN_H__

#include "screen.h"
#include <vector>

namespace scr {
    using std::vector;
    using std::pair;
    
    class Color {
        
    public:
        static const int black = 30;
        static const int red = 31;
        static const int green = 32;
        static const int yellow = 33;
        static const int blue = 34;
        static const int magenta = 35;
        static const int cyan = 36;
        static const int white = 37;
        
        Color() {}
        ~Color() {}
    };
    
    class Pen {
    public:
        int foreground_color;
        int background_color;
        char ch;
        bool bright;
        
        
        Pen(int fg_color, int bg_color, char c, bool brightness)
        : foreground_color(fg_color)
        , background_color(bg_color + 10)
        , ch(c)
        , bright(brightness)
        {}
        ~Pen()
        {}
    };
    
    class Shape{
    public:
        Shape() {}
        virtual ~Shape() {}
        
        virtual void draw(Screen & screen, const Pen & p) const {};
        
    };
    
    class Rectangle : public Shape {
    private:
        int x0;
        int y0;
        int width;
        int height;
        
    public:
        Rectangle(int x, int y, int width, int height)
        : x0(x), y0(y), width(width), height(height) {}
        
        ~Rectangle() {}
        
        // getters
        int get_width () const { return width; }
        int get_height () const { return height; }
        int get_x () const { return x0; }
        int get_y () const { return y0; }
        
        void draw(Screen & screen, const Pen & p) const;
    };
    
    class Circle : public Shape {
    private:
        int xc;
        int yc;
        int r;
        
    public:
        Circle(int x, int y, int radius)
        : xc(x), yc(y), r(radius) {}
        
        ~Circle() {}
        
        int get_x() const {return xc; };
        int get_y() const {return yc; };
        int get_r() const {return r; };
        
        void draw(Screen & screen, const Pen & p) const;
        
    };
    
    class Line : public Shape {
    private:
        int x0;
        int y0;
        int x1;
        int y1;
        
    public:
        Line(int x0, int y0, int x1, int y1)
        : x0(x0), y0(y0), x1(x1), y1(y1)
        {
            if (!(y0 == y1 || x0 == x1 || abs(x1-x0)==abs(y1-y0)))
            {
                try { throw 1; }
                catch(int e) {
                    cout << "line not valid" << endl;
                }
            }
        }
        
        ~Line() {}
        
        int get_x0 () const { return x0; }
        int get_y0 () const { return y0; }
        int get_x1 () const { return x1; }
        int get_y1 () const { return y1; }
        
        void draw(Screen & screen, const Pen & p) const;
        
    };
    
    
    class Canvas {
    private:
        Screen & screen;
        vector<pair<Shape, Pen>> shapen;
        
        
    public:
        Canvas (Screen & screen) : screen(screen) {}
        
        ~Canvas() {}
        
        void add(Shape * shape, Pen & pen) const;
        void clear();
        void show();
    };
    
    
    
    
    
    
} // namespace scr

#endif
