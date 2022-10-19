#include<stdio.h>
#include<string.h>
#include<ctype.h>
int lengthCheck(int l)
{
    int temp=0;
    if(l <= 10 && l >= 6){
        temp++;
    }
    return temp;
}
int upperCheck(char pss[])
{
    int i,temp=0;
    char ch;
    for ( i = 0; pss[i] != '\0'; i++)
    {
        ch = pss[i];
        if(isupper(ch)==1){
            temp++;
        }

    }
    return temp;
}
int lowerCheck(char pss[])
{
    int i,temp=0;
    char ch;
    for ( i = 0; pss[i] != '\0'; i++)
    {
        ch = pss[i];
        if(islower(ch)==1){
            temp++;
        }

    }
    return temp;
}
int digitCheck(char pss[])
{
    int i,temp=0;
    char ch;
    for ( i = 0; pss[i] != '\0'; i++)
    {
        ch = pss[i];
        if(isdigit(ch)==1){
            temp++;
        }

    }
    return temp;
}
int specialCharCheck(char pss[])
{
    int i,temp=0;
    char ch;
    for ( i = 0; pss[i] != '\0'; i++)
    {
        ch = pss[i];
        if(ch == '@' || ch == '#' || ch == '%' || ch == '!' || ch == '$'){
            temp++;
        }

    }
    return temp;
}
int main()
{
    char pss[10];
    int len;
    printf("\nEnter the password : ");
    gets(pss);
    len = strlen(pss);
    lengthCheck(len);
    upperCheck(pss);
    lowerCheck(pss);
    digitCheck(pss);
    specialCharCheck(pss);
    if(lengthCheck(len) >= 1 && upperCheck(pss) >= 1 && lowerCheck(pss) >= 1 && digitCheck(pss) >= 1 && specialCharCheck(pss) >= 1){
        printf("\nPASSWORD IS CORRECT");
    }
    if(lengthCheck(len) == 0 ){
        printf("\nLENGTH IS NOT CORRECT");
    }
    if(upperCheck(pss) == 0){
        printf("\nUPPERCASE MISSING");
    }
    if(lowerCheck(pss) == 0){
        printf("\nLOWERCASE MISSING");
    }
    if(digitCheck(pss) == 0 ){
        printf("\nDIGIT MISSING");
    }
    if(specialCharCheck(pss) == 0){
        printf("\nSPECIALCHAR MISSING");
    }
}