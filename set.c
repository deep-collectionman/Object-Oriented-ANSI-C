#include <assert.h>
#include <stdlib.h>

#if ! defined MANY || MANY < 1
#define MANY 10
#endif

struct Set { unsigned count; };
struct Object { unsigned count; struct Set* in; };

static const size_t _SetTypeSize = sizeof(struct Set);
static const size_t _ObjectTypeSize = sizeof(struct Object);

const void* Set = &_SetTypeSize;
const void* Object = &_ObjectTypeSize;

void* newObject(const void* type, ...) {
    const size_t size = *(const size_t *) type;
    void* pointer = calloc(1, size); // Allocate one element with the necessary size

    assert(pointer);

    return pointer;  
}

void deleteObject(void* object) {
    free(object);
}

void* add(void* set, const void* element) {
    struct Set* _set_ = set;
    struct Object* _element_ = (void*) element;

    assert(_set_);
    assert(_element_);

    if (!_element_->in) {
        _element_->in = _set_; // The set for this element will be _set_
    } else {
        assert(_element_->in == _set_);
    }

    ++_element_->count, ++_set_->count;
    
	return _element_;
}

void* find(const void* set, const void* element) {
	const struct Object* _element_ = element;

    assert(set);
    assert(_element_);

    return _element_->in == set ? (void*) _element_ : 0; // Check if the element is contained in this set
}

void* drop(void* set, const void* element) {
    struct Set* _set_ = set;
    struct Object* _element_ = find(_set_, element);

	if (_element_) {
        if (--_element_->count == 0) {
            _element_->in = 0;
        }

        --_set_->count;
    }

	return _element_;
}

unsigned count(const void* set) {
    const struct Set* _set_ = set;
    assert(_set_);

    return _set_->count;
}

int contains(const void* set, const void* element) {
	return find(set, element) != 0;
}

int differ(const void* lhs, const void* rhs) {
	return lhs != rhs;
}