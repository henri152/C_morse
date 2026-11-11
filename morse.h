#ifndef MORSE_H
# define MORSE_H

# include <unistd.h>

# define MORSE_SIZE 36

typedef struct s_morse
{
    char    lettre;
    char    code[8];
}   t_morse;

extern const t_morse g_table_morse[MORSE_SIZE];

int     ft_longueur(const char *texte);
void    ft_texte_vers_morse(const char *texte);
void    ft_morse_vers_texte(const char *morse);

#endif

