struct String {
    const void* classImpl; /* must be first */
    char* text;
    struct String* next;
    unsigned count;
};

static struct String* ring; /* of all strings */

static void* String_clone(const void* self) {
    struct String* _self_ = (struct String*) self;

    ++_self_->count;
    return _self_;
}