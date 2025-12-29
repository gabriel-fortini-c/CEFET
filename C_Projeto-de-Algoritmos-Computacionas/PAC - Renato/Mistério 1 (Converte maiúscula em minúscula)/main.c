#include <stdio.h>
#include <string.h>


void misterio(char s[]) 
{
    int i = 0;
    while (s[i]) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
        i++;
    }
}

int main ()
{
    char s[7];
    strcpy (s, "ABDAJK");
    misterio(s);
    printf ("%s", s[7]);
    
    return 0;
}