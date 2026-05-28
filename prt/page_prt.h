/*
 * @Author: zenghw
 * @Date: 2026-05-27 22:50:04
 * @Description: 
 * @LastEditTime: 2026-05-27 23:58:26
 */

#ifndef PAGE_PRT_H
#define PAGE_PRT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct page {
    const char *name; // 页面名称
    int    id;        // 页面i

    void (*create_page)(struct page *self); // 创建
    void (*destroy_page)(struct page *self); // 销毁
    void (*resume_page)(struct page *self);  // 恢复/进入前台
    void (*pause_page)(struct page *self);   // 暂停/进入后台

    void *user_data;  // 用户数据
} page_t;

/* 通过栈结构特性 来维护页面跳转情况 */
#define MAX_PAGE_STACK_DEPTH  10
typedef struct page_stack {
    page_t *stack[MAX_PAGE_STACK_DEPTH];
    int top; // 栈顶指示 -1 说明没有栈数据
} page_stack_t;
page_t *page_stack_top(page_stack_t *s);
page_t *page_stack_pop(page_stack_t *s);
int32_t page_stack_push(page_stack_t *s, page_t *page);


void page_register(page_t *page);
void page_navigate_to(int page_id);
int page_go_back(void);

#ifdef __cplusplus
}
#endif
#endif