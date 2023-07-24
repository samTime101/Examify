# Examify
Just trying different funtions and experimenting
# References
https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
# Basic Principle
```c
#include <stdio.h>
void main()
{
    int numberOfOptions = 4;
    char questions[100];
    char options[numberOfOptions][100];
    FILE*fp;

    fp = fopen("main.txt", "r");
    fscanf(fp, "%99[^\n]%*c", questions); 
    printf("%s\n", questions);

    for (int i = 0; i < numberOfOptions; i++) 
    {
        fscanf(fp, "%99[^\n]%*c", options[i]); 
        printf("%s\n", options[i]);
    }

    fclose(fp);
}
```

```txt
q1
1:o1
2:o2
3:o3
4:o4
```
