#include <assert.h>

#if ! defined MANY || MANY < 1
#define MANY 10
#endif

static int heap [MANY];

void* newObject(const void* type, ...) {
    int* pointer;

    pointer = heap + 1;

    while (pointer < heap + MANY) {
        if (!*pointer) {
            break;
        }

        ++pointer;
    }

    
    assert(pointer < heap + MANY);

    *pointer = MANY;

    return (pointer);
}

void deleteObject(void* object) {
    int* _object_;

    _object_ = object;

    if (_object_) {
        assert(_object_ > heap && _object_ < heap + MANY);
		*_object_ = 0;
    }
}

void* add(void* set, const void* element) {
    int* _set_;
    const int* _element_;

    _set_ = set;
    _element_ = element;

    assert(_set_ > heap && _set_ < heap + MANY);
	assert(*_set_ == MANY);
	assert(_element_ > heap && _element_ < heap + MANY);

    if (*_element_ == MANY) {
        *(int*) _element_ = _set_ - heap;
    } else {
        assert(*_element_ == _set_ - heap);
    }
    
	return (void *) element;
}

void* find(const void* set, const void* element) {
	const int* _set_ = set;
	const int* _element_ = element;

	assert(_set_ > heap && _set_ < heap + MANY);
	assert(*_set_ == MANY);
	assert(_element_ > heap && _element_ < heap + MANY);
	assert(*_element_);

	return *_element_ == _set_ - heap ? (void *) _element_ : 0;
}

void* drop(void* set, const void* element) {
    int* _element_ = find(set, element);

	if (_element_) {
        *_element_ = MANY;
    }

	return _element_;
}

int contains(const void* set, const void* element) {
	return find(set, element) != 0;
}

int differ(const void* lhs, const void* rhs) {
	return lhs != rhs;
}