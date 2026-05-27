/*
 * @Author: zenghw
 * @Date: 2026-05-27 22:49:58
 * @Description: 
 * @LastEditTime: 2026-05-27 23:29:44
 */

#include <unistd.h>
#include "common.h"
#include "page_prt.h"

/* 出栈 */
page_t *page_stack_pop(page_stack_t *s)
{
    page_t *page = NULL;
    if (s->top < 0) {
        log_err("stack is null, top:%d", s->top);
        return NULL;
    }

    /* 先出再减 */
    page = s->stack[s->top];
    s->top --;

    return page;
}

/* 入栈 */
int32_t page_stack_push(page_stack_t *s, page_t *page)
{
    if (s->top > MAX_PAGE_STACK_DEPTH) {
        log_err("stack is full, top:%d", s->top);
        return  -1;
    }

    /* 先加再入 */
    s->top ++;
    s->stack[s->top] = page;

    return 0;
}

/* 获取当前栈顶地址 */
page_t *page_stack_top(page_stack_t *s)
{
    if (s->top < 0) {
        log_err("stack is null, top:%d", s->top);
        return NULL;
    }

    return s->stack[s->top];
}