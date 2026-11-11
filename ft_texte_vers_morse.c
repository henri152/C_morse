#include <unistd.h>
#include "morse.h"

static char ft_majuscule(char caractere)
{
    if (caractere >= 'a' && caractere <= 'z')
        return (caractere - 32);
    return (caractere);
}

void    ft_texte_vers_morse(const char *texte)
{
    int     i;
    int     j;
    int     trouve;
    int     deja_ecrit;
    int     espace_en_attente;
    char    caractere;

    i = 0;
    deja_ecrit = 0;
    espace_en_attente = 0;
    while (texte[i] != '\0')
    {
        caractere = texte[i];
        if (caractere == ' ' || caractere == '\t')
        {
            if (deja_ecrit)
                espace_en_attente = 1;
        }
        else
        {
            caractere = ft_majuscule(caractere);
            trouve = 0;
            j = 0;
            while (j < MORSE_SIZE && trouve == 0)
            {
                if (caractere == g_table_morse[j].lettre)
                    trouve = 1;
                else
                    j++;
            }
            if (trouve == 1)
            {
                if (deja_ecrit)
                {
                    if (espace_en_attente)
                        write(1, " / ", 3);
                    else
                        write(1, " ", 1);
                }
                write(1, g_table_morse[j].code,
                    ft_longueur(g_table_morse[j].code));
                deja_ecrit = 1;
                espace_en_attente = 0;
            }
        }
        i++;
    }
}
