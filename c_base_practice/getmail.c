#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *src = "MAIL FROM :<123456@qq.com>\r\n";
    char *start = index(src,'<') + 1;
    char *end = rindex(src,'>') - 1;
    int len = end - start + 1;

    char mail[128] = "";
    strncpy(mail,start,len);
    printf("mail = %s\n",mail);

}