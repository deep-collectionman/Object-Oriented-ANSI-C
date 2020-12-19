#ifndef new_h
#define new_h

/// @brief newObject() accepts a descriptor and possibly more arguments for initialization
/// and returns a pointer to a new data item with a representation conforming to the descriptor. 
void* newObject(const void* type, ...);

/// @brief deleteObject() accepts a pointer originally produced by new() and recycles the associated resources.
void deleteObject(void* object);

#endif // new_h