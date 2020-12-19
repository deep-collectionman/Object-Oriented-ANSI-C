#ifndef set_h
#define set_h

extern const void* Set;

void* newObject(const void* type, ...);
void deleteObject(void* object);

void* add(void* set, const void* element);
void* drop(void* set, const void* element);
void* find(const void* set, const void* element);

int contains(const void* set, const void* element);

#endif // set_h