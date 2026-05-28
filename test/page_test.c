/*
 * @Author: zenghw
 * @Date: 2026-05-28 00:23:07
 * @Description: 
 * @LastEditTime: 2026-05-28 21:42:26
 */
#include <unistd.h>
#include "common.h"
#include "page_prt.h"
#include "app_page.h"

void page_test(void)
{
    page_register(&main_page);
    page_register(&setting_page);
    page_register(&wifi_page);

    page_navigate_to(MAIN_PAGE_ID);
    page_navigate_to(SETTING_PAGE_ID);
    page_navigate_to(WIFI_PAGE_ID);


    page_back_to_main_page();
}
