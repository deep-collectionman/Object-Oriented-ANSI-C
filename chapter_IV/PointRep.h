#ifndef point_rep_h
#define point_rep_h

struct Point {
    const void* class;
    int x, y;
};

#define get_x(point) (((const struct Point*)(point))->x)
#define get_y(point) (((const struct Point*)(point))->y)

#define set_x(point) (((struct Point*)(point))->x)
#define set_y(point) (((struct Point*)(point))->y)

#endif // point_rep_h