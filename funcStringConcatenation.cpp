void strcat(char *a,char *b){
int i=0,j=0;
char *t = a;
/*here important thing is accessing strings without any integer*/
/*i have copied this from  github.com/prateek27/Coding-Problems*/
while(*t!='\0'){
t++;
}

char *t2 = b;

while(*t2!='\0')
{ 
  *t = *t2 ;//important step
  t++;
  t2++;
}
//Dont forget to append a NULL.
*t = '\0';

return ;
}
