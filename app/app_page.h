/*
 * @Author: zenghw
 * @Date: 2026-05-28 00:13:57
 * @Description: 
 * @LastEditTime: 2026-05-28 10:14:30
 */

#ifndef APP_PAGE_H
#define APP_PAGE_H

#ifdef __cplusplus
extern "C" {
#endif
#include "page_prt.h"

typedef enum {
    MAIN_PAGE_ID = 0x0001,
    SETTING_PAGE_ID,
    ID_MAX
}page_id_t;

extern page_t main_page;
extern page_t setting_page;


#ifdef __cplusplus
}
#endif
#endif
