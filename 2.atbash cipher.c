#include<stdio.h>
#include<string.h>
main()
{
//In this A-Z,B-Y....Z-A 
 int i;
 char str[1000];
 printf("Enter a sentence\n");
 gets(str); 
 i=0;
 printf("Atbash Cipher code\n");
  while(str[i]!='\0')
  {
 if(!((str[i]>=0&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127)))
 {
   if(str[i]>='A'&&str[i]<='Z')
   printf("%c",'Z'+'A'-str[i]);
   if(str[i]>='a'&&str[i]<='z')
   printf("%c",'z'+'a'-str[i]);
 } 
    
    if(((str[i]>=0&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127)))
    {
      printf("%c",str[i]);    
    }
    
   i++;
  }
  printf("\n");
 
}
