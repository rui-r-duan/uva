#include<stdio.h>
#include<string.h>
const char one[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const char two[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const long len=35;
bool Palindrome(const char *s)
{
    long begin=0,end=strlen(s)-1;
    while(begin<=end)
    {
       if(s[begin]==s[end])
       {
          begin++;
          end--;
       }
       else
         return false;
    }
    return true;
}
long pos(char ch)
{
    for(long i=0;i<len;i++)
      if(one[i]==ch)
        return i;
    return len;
}
bool Mirror(const char *s)
{
    long begin=0,end=strlen(s)-1;
    while(begin<=end)
    {
       long tmp=pos(s[begin]);
       if(s[end]==two[tmp])
       {
          begin++;
          end--;
       }
       else
         return false;
    }
    return true;
}
int main()
{
    char str[1000];
    while(gets(str)!=0)
    {
       bool a=false,b=false;
       a=Palindrome(str);
       b=Mirror(str);
       if(a&&b)
         printf("%s -- is a mirrored palindrome.\n",str);
       else if(a)
         printf("%s -- is a regular palindrome.\n",str);
       else if(b)
         printf("%s -- is a mirrored string.\n",str);
       else
         printf("%s -- is not a palindrome.\n",str);
       putchar('\n');
    }
return 0;
}
