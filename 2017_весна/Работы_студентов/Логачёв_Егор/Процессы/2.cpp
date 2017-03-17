#include <stdio.h>
int main(int argc, char *argv[])
{
int t, i;
for(t=0; t<argc; ++t)
{
i = 0;
while(argv[t][i])
{
printf("%c", argv[t][i]);
}
printf (" ");
}
return 0;
}
