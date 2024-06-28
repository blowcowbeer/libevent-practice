#include <stdio.h>
#include <event2/event-config.h>
#include <event.h>

struct event ev;
struct timeval tv;

void timer_callback(int fd, short event, void* argc) {
    printf("hello, world!\n");
    event_add(&ev, &tv);
}

int main(void) {
    struct event_base* base = event_init();
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    // 设置回调函数和事件
    evtimer_set(&ev, timer_callback, NULL);
    // 将ev注册到base上
    event_base_set(base, &ev);
    // 添加事件
    event_add(&ev, &tv);
    // 进入循环，等待事件就绪并处理
    event_base_dispatch(base);

    return 0;
}
