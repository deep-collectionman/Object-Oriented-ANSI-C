#ifndef defines_h
#define defines_h

#define NON_DTOR 0

#ifndef SWAP
#define SWAP(leftValue, rightValue) _swap_impl_(leftValue, rightValue)

inline void _swap_impl_(void* leftValue, void* rightValue) {
    void** temporal = &leftValue;
    leftValue = rightValue;
    rightValue = *temporal;
}

#endif 

#endif // defines_h