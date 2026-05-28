/*
 * @Author: zenghw
 * @Date: 2026-05-28 10:02:53
 * @Description: 
 * @LastEditTime: 2026-05-28 10:13:38
 */

#include <stdlib.h>
#include "common.h"
#include "page_prt.h"
#include "app_page.h"

typedef struct main_data {
    int32_t timer;   // 定时器对象, 临时用基础变量表示
} main_data_t;

static void main_page_create(page_t *self)
{
    main_data_t *data = malloc(sizeof(main_data_t));
    self->user_data = data;  // destroy接口销毁

    data->timer = 50;
    log_info("main page create");
}

static void main_page_resume(page_t *self)
{
    main_data_t *data = self->user_data;
    log_info("main page resume, timer:%d", data->timer);
}

static void main_page_pause(page_t *self)
{
    main_data_t *data = self->user_data;

    log_info("main page pause, timer:%d", data->timer);
}

static void main_page_destroy(page_t *self)
{
    main_data_t *data = self->user_data;

    log_info("main page destroy, timer:%d", data->timer);
    free(data);
    self->user_data = NULL;
}

page_t main_page = {
    .name = "main",
    .id = MAIN_PAGE_ID,
    .create_page = main_page_create,
    .resume_page = main_page_resume,
    .pause_page = main_page_pause,
    .destroy_page = main_page_destroy,
};
