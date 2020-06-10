#ifndef __common_threads_h__
#define __common_threads_h__

#include <pthread.h>
#include <assert.h>
#include <sched.h>

#ifdef __linux__
#include <semaphore.h>
#endif

#define pthread_create(thread, attr, start_routine, arg) assert(pthread_create(thread, attr, start_routine, arg) == 0);
#define pthread_join(thread, value_ptr)                  assert(pthread_join(thread, value_ptr) == 0);

#define pthread_mutex_lock(m)                            assert(pthread_mutex_lock(m) == 0);
#define pthread_mutex_unlock(m)                          assert(pthread_mutex_unlock(m) == 0);
#define pthread_cond_signal(cond)                        assert(pthread_cond_signal(cond) == 0);
#define pthread_cond_wait(cond, mutex)                   assert(pthread_cond_wait(cond, mutex) == 0);

#define mutex_init(m)                                    assert(pthread_mutex_init(m, NULL) == 0);
#define mutex_lock(m)                                    assert(pthread_mutex_lock(m) == 0);
#define mutex_unlock(m)                                  assert(pthread_mutex_unlock(m) == 0);
#define cond_init(cond)                                  assert(pthread_cond_init(cond, NULL) == 0);
#define cond_signal(cond)                                assert(pthread_cond_signal(cond) == 0);
#define cond_wait(cond, mutex)                           assert(pthread_cond_wait(cond, mutex) == 0);

#ifdef __linux__
#define sem_init(sem, value)                             assert(sem_init(sem, 0, value) == 0);
#define sem_wait(sem)                                    assert(sem_wait(sem) == 0);
#define sem_post(sem)                                    assert(sem_post(sem) == 0);
#endif // __linux__

#endif // __common_threads_h__
