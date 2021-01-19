#include <stdio.h>

#include "String.h"
#include "new.h"

int main() {
    void* aString = newObject(String, "a"); //, *cloneString = clone(aString);
    void* bString = newObject(String, "b");

    printf("sizeOf(aString) == %u\n", sizeOf(aString));

    if (differ(aString, bString)) {
        puts("ok");
    }

    deleteObject(aString);
    deleteObject(bString);

    return 0;
}