#include <stdio.h>

char str[200];
char trans[27] = 
   "yhesocvxduiglbkrztnwjpfmaq";
//   "y`esocvxduiglbkrztnwjpfma`";
//  abcdefghijklmnopqrstuvwxyz

//  h q

int main ()
{
    int n;

    scanf("%d", &n);
    fgets (str, 200, stdin);

    for (int i = 0; i < n; i ++)
    {
        fgets (str, 200, stdin);

        printf ("Case #%d: ", i + 1);

        for (int j = 0; str[j]; j ++)
            if (str[j] == ' ')
                printf (" ");
            else if (str[j] >= 'a' && str[j] <= 'z')
                printf ("%c", trans[str[j] - 'a']);
        printf ("\n");
    }

    return 0;
}
