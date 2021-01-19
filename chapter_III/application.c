#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>

#define BUFFERSIZE 1024

enum tokens {
    NON = 0,
    NUMBER
};

struct Node {
    enum tokens token;
    struct Node* left;
    struct Node* right;
};

const void * Add;
const void * Sub;

static enum tokens token; /* current input symbol */

static jmp_buf onError;
static double number;

void error(const char* format, ...);
static void* sum(void);
static enum tokens scan(const char * buffer);

void* new(const void* type, ...);
void process (const void * tree);
void delete (void * tree);

int main(void) {
    volatile int errors = 0;
    char buffer[BUFFERSIZE];

    if (setjmp(onError)) {
        ++errors;
    }

    while (gets(buffer)) {
        if (scan(buffer)) {
            void* e = sum();

            if (token) {
                error("trash after sum");
            }

            process(e);
            delete(e);
        }
    }
    
    return errors > 0;
}

void error(const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    vfprintf(stderr, format, ap), putc('\n', stderr);
    va_end(ap);
    longjmp(onError, 1);
}

static enum tokens scan(const char* buffer) {
    static const char* bp;

    if (buffer) {
        bp = buffer; /* new input line */
    }

    while (isspace(*bp)) {
        ++bp;
    }

    if (isdigit(*bp) || *bp == '.') {
        errno = 0;
        token = NUMBER, number = strtod(bp, (char **) & bp);

        if (errno == ERANGE) {
            error("bad value: %s", strerror(errno));
        } 
    } else {
        token = *bp ? *bp++ : 0;
    }

    return token;
}

static void* sum(void) {
    void* result = product();
    

    for (;;) {
        switch(token) {
        case '+':
        case '-':
            scan(0), product();
            continue;
        }

        return;
    }
}