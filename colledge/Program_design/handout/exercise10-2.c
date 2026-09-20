#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// 全域常數用於 asctime 替換（如需）
const char *wday_names_full[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

/*
 * C 程式庫裡面的 asctime 有時格式不合要求，可自行替換
 * 這是作業說明中提供的 asctime 範例，確保格式一致
 */
char* my_asctime(const struct tm *timeptr)
{
    static const char wday_name[][4] = {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };
    static const char mon_name[][4] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    static char result[26];
    // 確保日期的 ' ' 對齊
    sprintf(result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
        wday_name[timeptr->tm_wday],
        mon_name[timeptr->tm_mon],
        timeptr->tm_mday, timeptr->tm_hour,
        timeptr->tm_min, timeptr->tm_sec,
        1900 + timeptr->tm_year);
    return result;
}

// 處理並輸出 struct tm 結構的資訊
void process_tm_output(struct tm *timeinfo) {
    char buffer[80];

    // (a) 星期幾 (需 mktime 計算 tm_wday)
    mktime(timeinfo);
    printf("%s\n", wday_names_full[timeinfo->tm_wday]);

    // (b) 使用 asctime 輸出
    printf("%s", my_asctime(timeinfo));

    // (c) 使用 strftime 輸出: 格式yyyy-mm-dd hh:mm:ss
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("%s\n", buffer);
}

int main() {
    int year, month, day, hour, min, sec;
    time_t x;
    
    // --- (1) 第一列輸入: 年、月、日、時、分、秒 ---
    if (scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &min, &sec) != 6) {
        // 讀取錯誤處理
        return 1;
    }

    struct tm timeinfo = {0}; // 初始化為 0

    // 填入 struct tm 結構
    timeinfo.tm_year = year - 1900; // 年份: 自 1900 年起
    timeinfo.tm_mon = month - 1;   // 月份: 0-11
    timeinfo.tm_mday = day;        // 日期: 1-31
    timeinfo.tm_hour = hour;
    timeinfo.tm_min = min;
    timeinfo.tm_sec = sec;
    timeinfo.tm_isdst = -1; // 讓 mktime 決定夏令時

    // 輸出處理
    process_tm_output(&timeinfo);

    // --- (2) 第二列輸入 time_t x (16 進位) ---
    // 檢查 time_t 大小 (64 位元編譯器通常為 8)
    if (sizeof(time_t) < 8) {
        //printf("Warning: time_t size is %zu bytes. May not handle 64-bit input.\n", sizeof(time_t));
    }

    if (scanf("%llx", &x) != 1) {
        // 讀取錯誤處理
        return 1;
    }
    
    // 將 time_t 轉換為 struct tm (使用 localtime 轉為本地時間)
    struct tm *timeinfo_ptr = localtime(&x);
    
    // 輸出處理
    process_tm_output(timeinfo_ptr);

    return 0;
}