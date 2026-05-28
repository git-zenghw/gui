/*
 * @Author: zenghw
 * @Date: 2026-05-28 00:23:07
 * @Description: 
 * @LastEditTime: 2026-05-28 10:15:03
 */
#include <unistd.h>
#include "common.h"
#include "page_prt.h"
#include "app_page.h"

void page_test(void)
{
    page_register(&main_page);
    page_register(&setting_page);

    page_navigate_to(MAIN_PAGE_ID);


    sleep(1);
    page_navigate_to(SETTING_PAGE_ID);
    page_go_back();
}
