//
//  main.cpp
//  Drawing on the Terminal
//
//  Created by Susanna Ardigo' on 18.05.18.
//  Copyright © 2018 Susanna Ardigo'. All rights reserved.
//

#include <iostream>
#include "screen.h"
#include "cscreen.h"
#include <vector>

using namespace scr;
using std::vector;

int main() {
    Screen screen;
    Canvas canv(screen);
    
    // Create some pens
    Pen pen_red(Color::yellow, Color::red, '@', true);
    Pen pen_green(Color::white, Color::green, '$', false);
    Pen pen_blue(Color::blue, Color::blue, '*', true);
    Pen pen_white(Color::black, Color::white, 'O', true);
    
    cout << pen_red.ch << endl;
    
    // List of pens
    vector<Pen> pens;
    pens.push_back(pen_red);
//    pens.push_back(pen_green);
//    pens.push_back(pen_blue);
//    pens.push_back(pen_white);
   /*
    // Draw robot frame
    int width = (screen.get_ncols() - 2) / 2;
    int height = screen.get_nrows() - 2;
    for (int i = 1; i <= (screen.get_ncols() - 2) / 32; i++) {
        Shape *addr = new Rectangle(i, i, width, height);
        canv.add(addr, pens[i % pens.size()]);
        width -= 2;
        height -= 2;
        if (width <= 0 || height <= 0)
            break;
    }
    
    // Draw eyes
    for (int i = 0; i <= 1; ++i) {
        int x = 1 + 3 * (screen.get_ncols() - 2) / (18 - i*8);
        int y = (screen.get_nrows() - 2) / 2;
        for (int radius = ((screen.get_ncols() - 2) >> 4) - 2; radius >= 0; radius -= 1) {
            Shape *addr = new Circle(x, y, radius);
            canv.add(addr, pens[(radius >> 1) % pens.size()]);
        }
    }
    
    // Draw mouth
    Shape *addr = new Line(1 + 3 * (screen.get_ncols() - 2) / 18, (screen.get_nrows() - 2)/1.2, 1 + 3 * (screen.get_ncols() - 2) / 10, (screen.get_nrows() - 2) / 1.2);
    canv.add(addr, pens[0]);
    
    // Update screen
    canv.show();
    
    
    // TODO Clean the memory
    */
    return 0;
}
