/*
** EPITECH PROJECT, 2020
** myxml_getnbr.c
** File description:
** myxml_getnbr.c
*/

static int check_int(char const *str, int nSize, int nb)
{
    int bo = 0;
    int reNb = 0;
    if (nb > 0 && str[nb - 1] == '-')
        bo = 1;

    for (int i = 1; i <= nSize; i++) {
        reNb = reNb + (str[nb] - 48);
        reNb = reNb * 10;
        nb++;
    }
    reNb = reNb /10;
    if (bo == 1)
        reNb = reNb * (-1);
    if (reNb > 2147483647 || reNb < -2147483647)
        return (0);
    else
        return (reNb);
}

int myxml_getnbr(char const *str)
{
    int i = 0;
    int n;
    int size = 0;
    int rNb;

    while (str[i] && (str[i] < '0' || '9' < str[i]) )
        i++;
    n = i;
    while (str[i] && str[i] >= '0' && '9' >= str[i]) {
        size++;
        i++;
    }
    if ( size > 10 )
        return (0);
    rNb = check_int(str, size, n);
    return (rNb);
}