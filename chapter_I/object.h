#ifndef object_h
#define object_h

const void* Object; /* newObject(Object) */

/// @brief differ() can compare objects: it returns true if they are not equal and false if they are.
int differ (const void* lhs, const void* rhs);

#endif // object_h