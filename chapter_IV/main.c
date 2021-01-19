#include "Point.h"
#include "Circle.h"
#include "new.h"

int main(int argc, char* argv[]) {
    void* drawable;

    while (*++argv) {

        switch (**argv) {
        case 'p':
            drawable = object(_Point_Descriptor_, 1, 2);
            break;
        case 'c':
            drawable = object(_Circle_Descriptor_, 10, 4, 5);
            break;
        default:
            continue; 
        }

        draw(drawable);
        move(drawable, 19, 34);
        draw(drawable);
        release(drawable);
    }

    return 0;
}