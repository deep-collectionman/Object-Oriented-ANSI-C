#include <stdio.h>

#include "new.h"
#include "object.h"
#include "set.h"

int main() {
    void* set = newObject(Object);
    void* a = add(set, newObject(Object));
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

    if (differ(a, add(set, a))) {
        puts("'a' doesn't differ from itself");
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