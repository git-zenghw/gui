/*
 * @Author: zenghw
 * @Date: 2026-05-28 00:01:49
 * @Description: 
 * @LastEditTime: 2026-05-28 10:06:12
 */

#include <stdlib.h>
#include "common.h"
#include "page_prt.h"
#include "app_page.h"

typedef struct setting_data {
    int32_t timer;   // 定时器对象, 临时用基础变量表示
} setting_data_t;

static void setting_page_create(page_t *self)
{
    setting_data_t *data = malloc(sizeof(setting_data_t));
    self->user_data = data;  // destroy接口销毁

    data->timer = 1000;
    log_info("setting page create");
}

static void setting_page_resume(page_t *self)
{
    setting_data_t *data = self->user_data;
    log_info("setting page resume, timer:%d", data->timer);
}

static void setting_page_pause(page_t *self)
{
    setting_data_t *data = self->user_data;

    log_info("setting page pause, timer:%d", data->timer);
}

static void setting_page_destroy(page_t *self)
{
    setting_data_t *data = self->user_data;

    log_info("setting page destroy, timer:%d", data->timer);
    free(data);
    self->user_data = NULL;
}

page_t setting_page = {
    .name = "setting",
    .id = SETTING_PAGE_ID,
    .create_page = setting_page_create,
    .resume_page = setting_page_resume,
    .pause_page = setting_page_pause,
    .destroy_page = setting_page_destroy,
};