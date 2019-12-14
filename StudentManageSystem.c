#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN sizeof(struct scorenode)

struct scorenode
{
    int number;
    char name[10];
    int xiaofei;
    struct scorenode *next;
};
typedef struct scorenode score;

int n,k;

/*
*函数功能：创建学生链表
*返回值：返回指向链表的头指针
*参数：无
*/
score *creat(void)
{
    score *head;
    score *p1,*p2,*p3,*max;
    int i,j;
    char t[10];
    n=0;
    p1=p2=p3=(score *)malloc(LEN);
    printf("please input student's information,input 0 exit!\n");
repeat1:printf("please input student's number(number>0):");
    scanf("%d",p1->number);
    while(p1->number < 0)
    {
        getchar();
        printf("error,please input number again:");
        scanf("%d",p1->number);
    }
    if(p1->number == 0)
        goto end;
    else
    {
        p3 = head;
        if(n > 0)
        {
            for(i=0;i<n;i++)
            {
                if(p1->number != p3->number)
                {
                    p3 = p3->next;
                }
                else
                {
                    printf("number repeate,please input again!\n");
                    goto repeat1;
                }

            }
        }
    }
    printf("please input student's name:");
    scanf("%s",&p1->name);
    printf("please input student's consume money:");
    scanf("%d",&p1->xiaofei);

    while(p1->number != 0)
    {
        n=n+1;
        if(n==1)
         head = p1;
        else
            p2->next = p1;
            p2=p1;
            p1=(score *)malloc(LEN);
            printf("please inout student's information,input 0 exit!\n");
repeat2:printf("please inout student's number(number>0):");
            scanf("%d",&p1->number);

        while(p1->number < 0)
        {
            getchar();
            printf("error,please inout number again:");
                scanf("%d",&p1->number);
        }
        if(p1->number==0)
        {
            goto end;
        }
        else
        {
            p3=head;
            if(n>0)
            {
                for(i=0;i<n;i++)
                {
                    if(p1->number != p3->number)
                        p3=p3->next;
                    else
                    {
                        printf("number repeate,please inout again!\n");
                        goto repeat2;
                    }
                }
            }
        }
        printf("please inout student's name:");
        scanf("%s",&p1->name);
        printf("please inout student's consume money:");
        scanf("%d",&p1->xiaofei);
    }
end:
    p1=head;
    p3=p1;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            max=p1;
            p1=p1->next;

            if(max->number > p1->number)
            {
                k=max->number;
                max->number = p1->number;
                p1->number = k;

                strcpy(t,max->name);
                strcpy(max->name,p1->name);
                strcpy(p1->name,t);
            }
        }
        max = head;p1 = head;
    }
    p2->next = NULL;
    printf("input student's num:%d ge!\n",n);
    getchar();
    return head;

}

void menu(void)
{
    system("clean");
    printf("\n\n\n");
    printf("\t\t------------student consume---------\n");
    printf("\t\t------------ 0  exit----------------\n");
    printf("\t\t------------ 1  craet----------------\n");
    printf("\t\t------------ 2  load-----------------\n");
    printf("\t\t------------ 3  search---------------\n");
    printf("\t\t------------ 4  delete----------------\n");
    printf("\t\t------------ 5  add--------------------\n");
    printf("\t\t------------ 6  show------------------\n");
    printf("\t\t------------ 6  save------------------\n");
    printf("\t\t--------------------------------------\n");
    printf("\t\tchoose(0-7):\n");

}



int main(void)
{
    int num;
    score *head = 0,*stu = 0;
    menu();
    scanf("%d",&num);
    while(1)
    {
        switch(num)
        {
            case 1:head = creat();break;
            case 2:head = load(head);break;
            case 3:head = search(head);break;
            case 4:head = del(head);break;
            case 5:head = add(head);break;
            case 6:print(head);break;
            case 7:save(head);break;

            case 0:exit(0);
            default:printf("input error,please again!");
        }
        menu();
        scanf("%d",&num);
    }


}
