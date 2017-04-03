/* 
 * The preprocessor statements protect the declarations: no matter
 * how many times we include Set.h, the C compiler only sees the 
 * declarations once.
 */

#ifndef	SET_H
#define	SET_H

extern const void * Set;

void * add (void * _set, const void * _element);
void * find (const void * set, const void * element);
void * drop (void * set, const void * element);
int contains (const void * set, const void * element);
unsigned count (const void * set);

#endif
