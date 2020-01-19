#include <stdio.h>
#include <string.h>


int main(void)
{
    const char *src = "asdfafdsafdsaSubject: 8LED 7 1\r\nDate:asdfasfsafa";
    char *start = strstr(src,"Subject:") + 9;
    char *end = strstr(start,"\r\n") - 1;
    int len = end - start + 1;

    char Subject[128] = "";
    strncpy(Subject,start,len);
    printf("subject = %s\n",Subject);

    return 0;
}