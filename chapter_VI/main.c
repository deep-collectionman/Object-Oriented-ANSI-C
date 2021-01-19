#include "Object.h"


int main(int argc, char* argv[]) {
    void* object = createObject(Object_Descriptor);
    const void* Any_Descriptor = createObject(
        Class_Descriptor, 
        "Any", 
        Object_Descriptor,
        sizeOf(object),
        differ, "Any_differ",
        0
    );

    void* any = createObject(Any_Descriptor);

    objectInfo(Any_Descriptor, stdout);
    objectInfo(object, stdout);
    objectInfo(any, stdout);

    releaseObject(object);
    releaseObject(any);
    releaseObject(Any_Descriptor);

    return 0;
} 