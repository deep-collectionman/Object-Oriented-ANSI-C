#include <stdarg.h>
#include <stdio.h>

#include "defines.h"
#include "new.h"

#include "PointRep.h"

static void* Point_void_ctor(void* self);
static void* Point_ctor(void* self, va_list* app);
static void Point_draw(const void* self);
static void Point_move(void* self, const int dx, const int dy);

static const struct Class _Point_ = {
    sizeof(struct Point),
    Point_ctor,
    NON_DTOR,
    Point_draw,
    Point_move 
};

const void* _Point_Descriptor_ = &_Point_;

static void* Point_void_ctor(void* self) {
    struct Point* _self_ = self;

    _self_->x = 0;
    _self_->y = 0;

    return _self_;
}

static void* Point_ctor(void* self, va_list* app) {
    struct Point* _self_ = self;

    _self_->x = va_arg(*app, int);
    _self_->y = va_arg(*app, int);

    return _self_;
}

static void Point_draw(const void* self) {
    const struct Point* _self_ = self;

    printf("\".\" at %d, %d\n", _self_->x, _self_->y); 
}

static void Point_move(void* self, const int dx, const int dy) {
    struct Point* _self_ = self;

    _self_->x += dx, _self_->y += dy;
}