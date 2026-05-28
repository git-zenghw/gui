/*
 * @Author: zenghw
 * @Date: 2026-05-28 21:39:38
 * @Description: 
 * @LastEditTime: 2026-05-28 21:43:26
 */

#include <stdlib.h>
#include "common.h"
#include "page_prt.h"
#include "app_page.h"

typedef struct wifi_data {
    int32_t timer;   // 定时器对象, 临时用基础变量表示
} wifi_data_t;

static void wifi_page_create(page_t *self)
{
    wifi_data_t *data = malloc(sizeof(wifi_data_t));
    self->user_data = data;  // destroy接口销毁

    data->timer = 200;
    log_info("wifi page create");
}

static void wifi_page_resume(page_t *self)
{
    wifi_data_t *data = self->user_data;
    log_info("wifi page resume, timer:%d", data->timer);
}

static void wifi_page_pause(page_t *self)
{
    wifi_data_t *data = self->user_data;

    log_info("wifi page pause, timer:%d", data->timer);
}

static void wifi_page_destroy(page_t *self)
{
    wifi_data_t *data = self->user_data;

    log_info("wifi page destroy, timer:%d", data->timer);
    free(data);
    self->user_data = NULL;
}

page_t wifi_page = {
    .name = "wifi",
    .id = WIFI_PAGE_ID,
    .create_page = wifi_page_create,
    .resume_page = wifi_page_resume,
    .pause_page = wifi_page_pause,
    .destroy_page = wifi_page_destroy,
};

