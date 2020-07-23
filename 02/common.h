#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double get_time() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

void spin(int how_long) {
    double t = get_time();
    while ((get_time() - t) < (double) how_long)
	; // do nothing in loop
}

#endif // __common_h__
