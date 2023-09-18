#include<stdio.h>
#include<string.h>
int top=-1;
int per( char a)
{
    switch(a)
    {
        case'+':return 1;
        case'-':return 1;
        case'*':return 3;
        case'/':return 3;
        case'(':return 0;
        
        default :return 0;
    }
}
void push(char st[],char val)
{
    top++;
    st[top]=val;
}
void pop(char st[])
{
    top--;
}
int main()
{
    char st[100],s[100],a[100];
    int l=0,i=0,j=0,k=0;
    char temp=0;
    printf("enter the string:\n");
    scanf("%s",s);
   
    l=strlen(s);
    k=l-1;
    for(i=0;i<l/2;i++)
    {
        temp=s[i];
        s[i]=s[k];
        s[k]=temp;
        k--;
    }
    for(i=0;i<l;i++)
    {
        if(s[i]=='(')
        {
            s[i]=')';
        }
        else if(s[i]==')')
        {
            s[i]='(';
        }
    }
    for(i=0;i<l;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            a[j]=s[i];
            j++;
        }
        else{
            if(top==-1  || s[i]=='(')
            {
                push(st,s[i]);
            }
            else
            {
                if(per(s[i])>per(st[top]))
                {
                    push(st,s[i]);
                }
                else if( s[i]==')')
                {
                    while(st[top]!='(')
                    {
                        a[j]=st[top];
                        j++;
                        pop(st);
                    }
                    pop(st);
                }
                else
                {
                    while(per(s[i])<=per(st[top]))
                    {
                        a[j]=st[top];
                        j++;
                        pop(st);
                    }
                    push(st,s[i]);
                }
            }
        }
    }
    while(top!=-1)
    {
        a[j]=st[top];
        j++;
        pop(st);
    }
    a[j]='\0';
   int m=strlen(a);
    k=m-1;
    for(i=0;i<m/2;i++)
    {
        temp=a[i];
        a[i]=a[k];
        a[k]=temp;
        k--;
    }
    printf("%s",a);
    return 0;
    
}