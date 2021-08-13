/*
** EPITECH PROJECT, 2020
** myxml_getnbr.c
** File description:
** myxml_getnbr.c
*/

static int get_first_digit_idx(const char *str)
{
    int first_digit;

    for (first_digit = 0; str[first_digit] != '\0'; first_digit++) {
        if (str[first_digit] >= '0' && str[first_digit] <= '9')
            break;
    }
    return first_digit;
}

static int check_neg(const char *str, int first_digit)
{
    if (first_digit > 0 && str[first_digit - 1] == '-')
        return 1;
    else
        return 0;
}

static float iterate(const char *str, int *i, int first_digit, int *dot_idx)
{
    float extracted_float = 0.0f;
    int blocked = 0;

    for (*i = first_digit; str[*i] != '\0'; *i += 1) {
        if (str[*i] >= '0' && str[*i] <= '9') {
            extracted_float += (float)(str[*i] - '0');
            extracted_float *= 10.0f;
        } else if (str[*i] == '.') {
            *dot_idx = *i;
            blocked = 1;
        } else
            return 0;
        if (!blocked)
            *dot_idx = *i;
    }
    return extracted_float;
}

float myxml_getnbr_f(char const *str)
{
    int first_digit = get_first_digit_idx(str);
    int neg = check_neg(str, first_digit);
    int dot_idx;
    int i;
    float extracted_float = iterate(str, &i, first_digit, &dot_idx);

    if (!extracted_float)
        return 0;
    for (int n = 0; n < (i - dot_idx) - 1; n++) {
        extracted_float /= 10.0f;
    }
    if (neg)
        extracted_float *= -1.0f;
    return extracted_float / 10.0f;
}