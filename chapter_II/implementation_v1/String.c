#include <stdlib.h>
#include <stdarg.h>

#include "new.h"
#include "class.h"

struct String {
    const void* _class_;
    char* text; /* dynamic string */
};

/*
* In the constructor we only need to initialize .text because new() has already set up `class`
*/
static void* String_ctor(void* self, va_list* app) {
    struct String* _self_ = self;
    const char* text = va_arg(*app, const char*);

    _self_->text = malloc(strlen(text) + 1);
    assert(_self_->text);
    strcpy(_self_->text, text);

    return _self_;
}

static void* String_dtor(void* self) {
    struct String* _self_ = self;

    free(_self_->text); _self_->text = 0;
    return self; 
}

static void* String_clone(void* self) {
    const struct String* _self_ = self;

    return newObject(String, _self_->text); 
}

static int String_differ(const void* self, const void* other) {
    const struct String* _self_ = self;
    const struct String* _other_ = other;

    if (_self_ == _other_) {
        return 0;
    }

    if (!_other_ || _other_->_class_ != String) {
        return 1;
    }

    return strcmp(_self_->text, _other_->text);
}


static const struct Class _String = {
    sizeof(struct String), String_ctor, String_dtor, String_clone, String_differ
};

const void* String = &_String;