#include <unistd.h>

struct dict {
    unsigned int key;
    char *value;
};

int ft_strlen(char *str) {
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

unsigned int ft_atoi(char *str) {
    unsigned int i = 0;
    unsigned int sign = 1;
    unsigned int res = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
           || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

void ft_putstr(char *str) {
    write(1, str, ft_strlen(str));
}

void print_dict(int num) {
    struct dict d[32] = {
            {0,          "zero"},
            {1,          "one"},
            {2,          "two"},
            {3,          "three"},
            {4,          "four"},
            {5,          "five"},
            {6,          "six"},
            {7,          "seven"},
            {8,          "eight"},
            {9,          "nine"},
            {10,         "ten"},
            {11,         "eleven"},
            {12,         "twelve"},
            {13,         "thirteen"},
            {14,         "fourteen"},
            {15,         "fifteen"},
            {16,         "sixteen"},
            {17,         "seventeen"},
            {18,         "eighteen"},
            {19,         "nineteen"},
            {20,         "twenty"},
            {30,         "thirty"},
            {40,         "forty"},
            {50,         "fifty"},
            {60,         "sixty"},
            {70,         "seventy"},
            {80,         "eighty"},
            {90,         "ninety"},
            {100,        "hundred"},
            {1000,       "thousand"},
            {1000000,    "million"},
            {1000000000, "billion"}
    };
    int i;
    i = 31;

    if (num <= 20 && num >= 0) {
        ft_putstr(d[num].value);
        return;
    }

    while (i > 0) {
        if (num / d[i].key > 0) {
            if (d[i].key >= 100) {
                print_dict(num / d[i].key);
                ft_putstr(" ");
            }
            ft_putstr(d[i].value);
            num %= d[i].key;
            if (num > 0)
                ft_putstr(" ");
        }
        i--;
    }
}


int main(int argc, char **argv) {
    if (argc == 2) {
        int num = ft_atoi(argv[1]);
        print_dict(num);
        ft_putstr("\n");
    } else {
        ft_putstr("Error\n");
    }
    return (0);
}