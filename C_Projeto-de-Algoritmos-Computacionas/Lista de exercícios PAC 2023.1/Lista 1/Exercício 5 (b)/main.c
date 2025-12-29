/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int calculo_minutos (int horas, int minutos)
{
    int horas_em_min;
    horas_em_min = horas * 60;
    return horas_em_min + minutos;
    
}

int diferenca_horas (int h_prevista, int m_previsto, int h_chegada, int m_chegada)
{
    int horario_previsto, horario_chegada;
    horario_previsto = calculo_minutos (h_prevista, m_previsto);
    horario_chegada = calculo_minutos (h_chegada, m_chegada);
    
    return horario_chegada - horario_previsto;
}

int main ()
{
    int h_prevista, m_previsto, h_chegada, m_chegada;
    printf ("Insira o horário previsto de chegada: ");
    scanf ("%d %d", &h_prevista, &m_previsto);
    printf ("Insira o horário efetivo de chegada: ");
    scanf ("%d %d", &h_chegada, &m_chegada);
    printf ("A diferença é de: %d minutos", diferenca_horas(h_prevista, m_previsto, h_chegada, m_chegada));
    
    return 0;
}



