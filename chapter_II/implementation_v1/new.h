#ifndef new_h
#define new_h

#include <stdlib.h>

/// @brief newObject(descriptor) accepts a descriptor and possibly more arguments for initialization
/// and returns a pointer to a new data item with a representation conforming to the descriptor. 
void* newObject(const void* descriptor, ...); 

/// @brief deleteObject(self) accepts a pointer originally produced by new() and recycles the associated resources.
void deleteObject(void* self);

/// @brief clone(self) generates a clone from self
void* clone(const void* self);

/// @brief differ(self, other) can compare objects: it returns true if they are not equal and false if they are.
int differ (const void* self, const void* other);

/// @brief sizeOf(self) is a polymorphic function which at run time returns the number of bytes of the object, 
/// to which the argument points.
size_t sizeOf(const void* self);

#endif // new_h