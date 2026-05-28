/*
 * @Author: zenghw
 * @Date: 2026-05-27 23:35:18
 * @Description: 
 * @LastEditTime: 2026-05-27 23:57:54
 */

#include "common.h"
#include "page_prt.h"

#define MAX_PAGE_NUM  32
typedef struct page_manage {
    page_stack_t stack;         // 页面栈
    page_t *page_pool[MAX_PAGE_NUM]; // 注册的页面池
    int32_t page_count;              // 页面数
} page_manage_t;
static page_manage_t gs_pm = {0}; // 单例

void page_register(page_t *page)
{
    if (gs_pm.page_count > MAX_PAGE_NUM) {
        log_err("page count exceeded");
        return;
    }

    gs_pm.page_pool[gs_pm.page_count ++] = page;
}

/* 页面跳转到 */
void page_navigate_to(int page_id)
{
    page_t *target = NULL;
    int32_t idx = 0;

    for (idx = 0; idx < gs_pm.page_count; idx ++) {
        if (gs_pm.page_pool[idx]->id == page_id) {
            target = gs_pm.page_pool[idx];
            break;
        }
    }
    if (target == NULL) {
        log_err("not found page, id:%d", page_id);
    }

    // 获取当前页面，并放置后台
    page_t *current = page_stack_top(&gs_pm.stack);
    if (current && current->pause_page) {
        current->pause_page(current);
    }

    // 新页面入栈，并显示
    page_stack_push(&gs_pm.stack, target);
    if (target->create_page) {
        target->create_page(target);
    }
    if (target->resume_page) {
        target->resume_page(target);
    }
}

int page_go_back(void)
{
    page_t *current = page_stack_pop(&gs_pm.stack);
    if (NULL == current) {
        log_warn("already on the main page");
        return -1;
    }
    if (current->pause_page) {
        current->pause_page(current);
    }
    if (current->destroy_page) {
        current->destroy_page(current);
    }

    page_t *pre = page_stack_top(&gs_pm.stack);
    if (pre && pre->resume_page) {
        pre->resume_page(pre);  // 还原上一页面
    }

    return 0;
}