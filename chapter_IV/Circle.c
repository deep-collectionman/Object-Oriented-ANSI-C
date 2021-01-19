#include <stdarg.h>
#include <stdio.h>

#include "defines.h"
#include "new.h"

#include "CircleRep.h"

static void* Circle_ctor(void* self, va_list* app);
static void* Circle_dtor(void* self);
static void Circle_draw(const void* self);
static void Circle_move(void* self, const int dx, const int dy);

static const struct Class _Circle_ = {
    sizeof(struct Circle),
    Circle_ctor,
    Circle_dtor,
    Circle_draw,
    Circle_move 
};

const void* _Circle_Descriptor_ = &_Circle_;

static void* Circle_ctor(void* self, va_list* app) {
    struct Circle* _self_ = ((const struct Class*) _Point_Descriptor_)->ctor(self, app);
    _self_->radius = va_arg(*app, int);

    return _self_;
}

static void* Circle_dtor(void* self) {
    struct Circle* _self_ = self;

    release((void *)_self_->point);
}

static void Circle_draw(const void* self) {
    const struct Circle* _self_ = self;

    printf("circle \"o\" at %d, %d radius %d\n", get_x(_self_->point), get_y(_self_->point), _self_->radius);     
}

static void Circle_move(void* self, const int dx, const int dy) {
    struct Circle* _self_ = self;

    set_x(_self_->point) += dx, set_y(_self_->point) += dy;
}
