/* MACRO of CALLOC and REALLOC */

#define CALLOC(p, n, s)                                 \
        if ( !( (p) = calloc(n, s) ) ) {                \
                fprintf(stderr, "Insufficient memory"); \
                exit(EXIT_FAILURE);                     \
        }

#define REALLOC(p, n, s)                                \
        if ( !( (p) = realloc(p, s) ) ) {               \
                fprintf(stderr, "Insufficient memory"); \
                exit(EXIT_FAILURE);                     \
}
