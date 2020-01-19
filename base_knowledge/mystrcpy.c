#include <stdio.h>

char *mystrcpy(char *dest,const char *src)
{
    char *ret = dest;
    if(dest != NULL && src != NULL)
        while((*dest++ = *src++) != '\0');

    return ret;
}

char *mystrncpy(char *dest,const char *src,int n)
{
    int i;
    for(i = 0;i < n && (dest[i] = src[i]);i++){
    }

    dest[i] = '\0';

    return dest;
}

int main(void)
{
    char str1[] = "helloworld";
    char str2[128];

    //mystrcpy(str2,str1);
    mystrncpy(str2,str1,5);

    puts(str2);

    return 0;
}