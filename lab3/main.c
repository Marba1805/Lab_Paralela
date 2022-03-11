#include <unistd.h>
#include <stdio.h>


int main()

{
    pid_t cpid;   
    int i, num, j;

    printf ("Enter the number: ");

    scanf ("%d", &num);

    j = num;



    cpid = fork();
    
    if (cpid<0)
    {
        printf("falha na criacao do filho\n");
        exit(0);
    }

  else if (cpid == 0)
  {
    for (i=1; j > 1; j = j -1)
    {
        i=i*j;
       }
      printf("The factorial of %d is %d\n",num,i);
  }

  else if (cpid > 0)
  {
    
    return 0;
    }
}
