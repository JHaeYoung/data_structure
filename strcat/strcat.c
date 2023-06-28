#pragma once    
#include <stdio.h>
#define _CTR_SECURE_NO_WARNINGS

char* strcat(char* str1, char* str2) {
    char* str0 = str1;

    while (*str1 != '\0')
    {
        str1++;
        printf("%s", str1);

    }

    while (*str2 != NULL)
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return str0;

}
int strlen(char* ps) {
    int count = 0;
    char* pd = ps;
    while (*ps != '\0')
    {
        count++;
        ps++;
    }
    
    return count;
 }

int strcmp(char* ps1,char* ps2) {
    
    while ((*ps1 ==*ps2) && (*ps1 !='\0'))
    {
        ps1++;
        ps2++;
    }
    if (*ps1 > *ps2) return 1;
    else if (*ps1 < *ps2) return -1;
    else return 0;

}

int main()
{
    
    /*char* test =  "JHY" ;

    char* p = test;
    while (*p) {
        printf("%c", *p);
        p++;
    }*/
    //int i, j=0;

    //char* test[4] = { "JHY","NHJ","KMO", "JNJ"};
    //
    //char** pTest = test;
    //while (*pTest!=NULL) {
    //    //char* ppTest = *pTest;
    //    while (**pTest) {
    //        printf("%c\n", **pTest);
    //        (*pTest)++;
    //    }              
    //    pTest++;
    //}
    int a = 1;
    char b[4] = "asd";

    int* test1[4] = { &a, };

    printf("%d %s", *test1[0], b);

    /*int size = sizeof(test) / sizeof(test[0]);

    for (i = 0; i < size; i++)
    {
        while(test[i][j]!=NULL)
        {
            char a = test[i][j];
            printf("%c", a);


            j++;
        }
        j = 0;
    }*/

    //char fruit[80] = "straw";

    //char** pTest = test;

    //strcat(fruit, "berry");

    //printf("%s", fruit);

    //printf("%d",strlen(fruit));
   //printf("%d",strcmp(fruit,"straz"));

    return 1;

}

