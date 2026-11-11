#include <unistd.h>
#include "morse.h"

static int  ft_memes_chaines(const char *a, const char *b)
{
    int i;

    i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
            return (0);
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0')
        return (1);
    return (0);
}

static void ft_decoder_code(const char *code, int code_trop_long)
{
    int j;
    int trouve;

    trouve = 0;
    j = 0;
    while (j < MORSE_SIZE && trouve == 0 && code_trop_long == 0)
    {
        if (ft_memes_chaines(code, g_table_morse[j].code))
            trouve = 1;
        else
            j++;
    }
    if (trouve == 1)
        write(1, &g_table_morse[j].lettre, 1);
    else
        write(1, "?", 1);
}

void    ft_morse_vers_texte(const char *morse)
{
    char    code[8];
    int     longueur_code;
    int     code_trop_long;
    int     i;
    int     deja_ecrit;
    int     espace_mot;

    longueur_code = 0;
    code_trop_long = 0;
    i = 0;
    deja_ecrit = 0;
    espace_mot = 0;
    while (1)
    {
        if (morse[i] == '.' || morse[i] == '-')
        {
            if (longueur_code < 7)
            {
                code[longueur_code] = morse[i];
                longueur_code++;
            }
            else
                code_trop_long = 1;
        }
        else if (morse[i] == ' ' || morse[i] == '/' || morse[i] == '\0')
        {
            if (longueur_code > 0 || code_trop_long)
            {
                code[longueur_code] = '\0';
                ft_decoder_code(code, code_trop_long);
                deja_ecrit = 1;
                espace_mot = 0;
                longueur_code = 0;
                code_trop_long = 0;
            }
            if (morse[i] == '/' && deja_ecrit && espace_mot == 0)
            {
                write(1, " ", 1);
                espace_mot = 1;
            }
            if (morse[i] == '\0')
                break;
        }
        else
        {
            if (longueur_code > 0 || code_trop_long)
            {
                code[longueur_code] = '\0';
                ft_decoder_code(code, code_trop_long);
                deja_ecrit = 1;
                espace_mot = 0;
                longueur_code = 0;
                code_trop_long = 0;
            }
        }
        i++;
    }
}
