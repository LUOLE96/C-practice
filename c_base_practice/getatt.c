#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *src = "asdfasdfafilename=\"table.txt\"\r\n\r\nhello world\r\n\r\nasdfasdfasdfa";
    char *filename = strstr(src,"filename=");
    if(NULL != filename){
        char *start = strstr(filename,"\r\n\r\n") + 4;
        char *end = strstr(start,"\r\n\r\n");
        int len =  end - start + 1;
        if(NULL != start && NULL != end){
            char atts[1024] = "";
            strncpy(atts,start,len);
            printf("atts = %s\n",atts);
        }    
    }
}
