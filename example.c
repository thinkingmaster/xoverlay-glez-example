#include "xoverlay.h"
#include "glez.h"

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

int main()
{
    // Initialize everything
    xoverlay_init();
    glez_init(xoverlay_library.width, xoverlay_library.height);
    
    // Load the textures and the font
    glez_texture_t texture = glez_texture_load_png_rgba("meme.png");
    glez_font_t font = glez_font_load("FreeSans.ttf", 24);
    
    int tw, th;
    glez_texture_size(texture, &tw, &th);
    
    // Show Xoverlay
    xoverlay_show();
    
    float x = 500;
    float y = 500;
    
    int mx = 0;
    int my = 0;
    float deg = 0;
    
    // Prepare the colors
    glez_rgba_t purple = glez_rgba(255, 0, 128, 255);
    glez_rgba_t white = glez_rgba(255, 255, 255, 255);
    glez_rgba_t black = glez_rgba(0, 0, 0, 255);
    
    while (1)
    {
        x += 1 * mx;
        y += 1 * my;
        
        if (x < 0 || x + tw > xoverlay_library.width) mx *= -1;
        if (y < 0 || y + th > xoverlay_library.height) my *= -1;
        
        // Must be called in that order.
        xoverlay_draw_begin();
        glez_begin();
        
        glez_rect(100, 300, 200, 100, purple);
        glez_rect_outline(500, 300, 200, 100, white, 2);
        glez_rect_textured(x, y, tw, th, white, texture, 0, 0, tw, th, deg);
        deg += 0.01f;
        if (deg >= 360.0f) deg = 0;

        glez_string_with_outline(100, 100, "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 123456789 !@#$%^&*()", font, white, black, 1.5f, 0, NULL, NULL);
        glez_string(100, 150, "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 123456789 !@#$%^&*()", font, purple, NULL, NULL);
        
        glez_end();
        xoverlay_draw_end();
    }
}