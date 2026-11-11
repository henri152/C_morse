#include <unistd.h>
#include <string.h>
#include "morse.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(2, "Erreur : usage : ./morse encode|decode texte\n", 45);
        return (1);
    }
    if (strcmp(argv[1], "encode")==0)
    {
        ft_texte_vers_morse(argv[2]);
        write(1, "\n", 1);
    }
    else if (strcasecmp(argv[1], "decode")==0)
    {
        ft_morse_vers_texte(argv[2]);
        write(1, "\n", 1);
    }
    else
    {
        write(2, "Erreur : mode attendu : encode ou decode\n", 41);
        return (1);
    }
    return (0);
}
