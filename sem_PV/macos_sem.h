#ifdef __APPLE__
#include <dispatch/dispatch.h>
#else
#include <semaphore.h>
#endif

struct rk_sem {
#ifdef __APPLE__
    dispatch_semaphore_t    sem;
#else
    sem_t                   sem;
#endif
};


static inline void
// 初始化一个信号量
rk_sem_init(struct rk_sem *s, uint32_t value)
{
#ifdef __APPLE__
    dispatch_semaphore_t *sem = &s->sem;

    *sem = dispatch_semaphore_create(value);
#else
    sem_init(&s->sem, 0, value);
#endif
}

static inline void
// 对信号量进行P操作，即对信号量进行减一操作
rk_sem_wait(struct rk_sem *s)
{

#ifdef __APPLE__
    dispatch_semaphore_wait(s->sem, DISPATCH_TIME_FOREVER);
#else
    //int r;

    //do {
    //        r = sem_wait(&s->sem);
    //} while (r == -1 && errno == EINTR);
    sem_wait(&s->sem);
#endif
}

static inline void
// 对信号量进行V操作，即对信号量进行加一操作
rk_sem_post(struct rk_sem *s)
{

#ifdef __APPLE__
    dispatch_semaphore_signal(s->sem);
#else
    sem_post(&s->sem);
#endif
}
