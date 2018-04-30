#include "xoverlay.h"
#include <glez/glez.hpp>
#include <glez/texture.hpp>
#include <glez/color.hpp>
#include <glez/font.hpp>
#include <glez/draw.hpp>

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

int main()
{
    // Initialize everything
    xoverlay_init();
    glez::init(xoverlay_library.width, xoverlay_library.height);
    
    // Load the textures and the font
    glez::texture texture("meme.png");
    texture.load();
    glez::font font("FreeSans.ttf", 24);
    
    // Show Xoverlay
    xoverlay_show();
    
    float x = 500;
    float y = 500;
    
    int tw = texture.getWidth();
    int th = texture.getHeight();
    
    int mx = 0;
    int my = 0;
    float deg = 0;
    
    while (1)
    {
        x += 1 * mx;
        y += 1 * my;
        
        if (x < 0 || x + tw > xoverlay_library.width) mx *= -1;
        if (y < 0 || y + th > xoverlay_library.height) my *= -1;
        
        // Must be called in that order.
        xoverlay_draw_begin();
        
        glez::begin();
        
        glez::draw::rect(100, 100, 200, 200, glez::color::green);
        glez::draw::rect_textured(150, 150, 100, 40, glez::color::white, texture, 0, 0, tw, th);
        //glez::draw::rect_textured(150, 200, 50, 50, glez::color::white, texture, 0, 0, 12, 12);
        glez::draw::string(100, 100, "Testing", font, glez::color::blue, nullptr, nullptr);
        glez::draw::outlined_string(100, 120, "Testing", font, glez::color::white, glez::color::black, nullptr, nullptr);
        
        glez::end();
              
        
        /*
        glez_begin();glez_rect(100, 300, 200, 100, purple);
        glez_rect_outline(500, 300, 200, 100, white, 2);
        glez_rect_textured(x, y, tw, th, white, texture, 0, 0, tw, th, deg);
        deg += 0.01f;
        if (deg >= 360.0f) deg = 0;

        glez_string_with_outline(100, 100, "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 123456789 !@#$%^&*()", font, white, black, 1.5f, 0, NULL, NULL);
        glez_string(100, 150, "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 123456789 !@#$%^&*()", font, purple, NULL, NULL);
        
        glez_end();*/
        xoverlay_draw_end();
    }
}