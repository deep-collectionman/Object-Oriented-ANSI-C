#include <stdio.h>

#include "new.h"
#include "object.h"
#include "set.h"

int main() {
    void* set = newObject(Object);

    int* a = newObject(Object);
    *a = 2001; 
    a = add(set, a);

    void* b = add(set, newObject(Object));
    void* c = newObject(Object);

    if (contains(set, a) && contains(set, b)) {
        puts("Ok. Set contains 'a' & 'b'");
    } else {
        puts("Set doesn't 'a' or 'b'");
    }

    if (contains(set, c)) {
        puts("Ok. Set contains 'c'");
    } else {
        puts("Set doesn't contains 'c'");
    }

    if (!differ(a, add(set, a))) {
        puts("'a' doesn't differ from itself");
        printf("Value for 'a' is %d\n", *a);
    }

    if (!contains(set, drop(set, a))) {
        puts("'a' was dropped");
    } else {
        puts("'a' wasn't dropped yet");
    }

    deleteObject(drop(set, b));
    deleteObject(drop(set, c));

    return 0;
}