#ifndef object_h
#define object_h

#include <stdio.h>

extern const void* Class_Descriptor; /* new(Class, "name", super, size, methods, ...); */
extern const void* Object_Descriptor; /* Descriptor */

/// @brief object() accepts a descriptor and possibly more arguments for initialization
/// and returns a pointer to a new data item with a representation conforming to the descriptor.
/// @param descriptor The class descriptor 
void* createObject(const void* descriptor, ...);

/// @brief release() accepts a pointer originally produced by object() and recycles the associated resources.
/// @param object Object to release
void releaseObject(void* object);

/// @brief differ() compares two objects and return true if there are equal 
/// @param self The left side value to be compared
/// @param other The right side value to be compared
int differ(const void* self, const void* other);

/// @brief objectInfo() dumps all the object information into the specified file
/// @param self The object to be inspected
/// @param outputFile The file where the information is dumped
int objectInfo(const void* self, FILE* outputFile);

/// @brief sizeOf() is a polymorphic function which at run time returns the number of bytes of the object, 
/// to which the argument points.
size_t sizeOf(const void* self);

#endif // object_h