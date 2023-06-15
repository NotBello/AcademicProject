#include "splashkit.h"
#define RADIUS 80

int main()
{
    double x;
    double y;
    color circle_color = COLOR_BLUE_VIOLET;
    open_window("Circle Mover by Bello", 800, 800);
    x = screen_width() / 2;
    y = screen_height() / 2;

    while (not quit_requested())
    {
        clear_screen(COLOR_WHITE);
        process_events();

        if (key_down(LEFT_KEY) and (key_down(UP_KEY)))
        {
            x -= 3;
            y -= 3;
        }
        if (key_down(LEFT_KEY) and (key_down(DOWN_KEY)))
        {
            x -= 3;
            y += 3;
        }
        if (key_down(RIGHT_KEY) and (key_down(UP_KEY)))
        {
            x += 3;
            y -= 3;
        }
        if (key_down(RIGHT_KEY) and (key_down(UP_KEY)))
        {
            x += 3;
            y += 3;
        }
        if (key_down(RIGHT_KEY))
        {
            x += 3;
        }
        if (key_down(LEFT_KEY))
        {
            x -= 3;
        }
        if (key_down(UP_KEY))
        {
            y -= 3;
        }
        if (key_down(DOWN_KEY))
        {
            y += 3;
        }
        if (key_typed(Q_KEY))
        {
            x = screen_width() / 2;
            y = screen_height() / 2;
        }
        if (key_typed(C_KEY))
        {
            circle_color = random_color();
        }

        if( x + RADIUS > screen_width())
        {
            x = screen_width() - RADIUS;
            circle_color = random_color();
        }
        if (x - RADIUS < 0)
        {
            x = RADIUS;
            circle_color = random_color();
        }
        if( y + RADIUS > screen_height())
        {
            y = screen_height() - RADIUS;
            circle_color = random_color();
        }
        if (y - RADIUS < 0)
        {
            y = RADIUS;
            circle_color = random_color();
        }


        fill_circle(circle_color, x, y, RADIUS);
        refresh_screen(60);
        
    }

    return 0;
}