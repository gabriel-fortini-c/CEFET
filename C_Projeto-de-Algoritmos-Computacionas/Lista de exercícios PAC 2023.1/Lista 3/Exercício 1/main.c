#include <stdio.h>

float calcula_idh (float ed, float longe, float riq)
{
    float idh;
    if (ed >= longe + riq)
    {
        idh = (ed * longe * riq) / ((ed + longe + riq) / 3);
    }
    else // ed < longe + riq
    {
        idh = ((ed + longe + riq) / 3);
    }
    return idh;
}

int main ()
{
    float ed, longe, riq;
    printf ("Insira a Educação, Longevidade e a Riqueza do país: ");
    scanf ("%f %f %f", &ed, &longe, &riq);
    printf ("O IDH é: %.03f", calcula_idh(ed, longe, riq));
    
    return 0;
}
