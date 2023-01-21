#include <stdio.h>
#include <string.h>
int global = 0;

struct data
{
    char name[200];
    char gender[200];
    char element[200];
    int star;
} list[3000];

void bubblesort()
{
    for (int j = 0; j < global; j++)
    {
        for (int k = 0; k < global - j - 1; k++)
        {
            if (strcmp(list[k].name, list[k + 1].name) > 0)
            {
                struct data temp = list[k];
                list[k] = list[k + 1];
                list[k + 1] = temp;
            }
        }
    }
}

void search_element()
{
    char choose[500];
    printf("==============================\n");
    printf("||      List of element     ||\n");
    printf("==============================\n");
    printf("Choose the element:\n");
    printf("pyro\nCryo\nelectro\nhydro\nanemo\ndendro\ngeo\n");
    printf("NOTE: case sensitive input\n");
    printf("Your input: ");
    scanf("%s", choose);

    for (int i = 0; i < global; i++)
    {
        if (strcmp(choose, "hydro") == 0)
        {
            if (strstr(list[i].element, "hydro"))
            {
                printf("%-10s | %-1s | %-10s | %i\n", list[i].name, list[i].gender, list[i].element, list[i].star);
            }
        }
        else if (strcmp(choose, "cryo") == 0)
        {
            if (strstr(list[i].element, "cryo"))
            {
                printf("%-10s | %-1s | %-10s | %i\n", list[i].name, list[i].gender, list[i].element, list[i].star);
            }
        }
        else if (strcmp(choose, "pyro") == 0)
        {
            if (strstr(list[i].element, "pyro"))
            {
                printf("%-10s | %-1s | %-10s | %i\n", list[i].name, list[i].gender, list[i].element, list[i].star);
            }
        }
        else if (strcmp(choose, "electro") == 0)
        {
            if (strstr(list[i].element, "electro"))
            {
                printf("%-10s | %-1s | %-10s | %i\n", list[i].name, list[i].gender, list[i].element, list[i].star);
            }
        }
        else if (strcmp(choose, "anemo") == 0)
        {
            if (strstr(list[i].element, "anemo") == 0)
            {
                printf("%-10s | %-1s | %-10s | %i\n", list[i].name, list[i].gender, list[i].element, list[i].star);
            }
        }
        else if (strcmp(choose, "dendro") == 0)
        {
            if (strstr(list[i].element, "dendro"))
            {
                printf("%-10s | %-1s | %-10s | %i\n", list[i].name, list[i].gender, list[i].element, list[i].star);
            }
        }
        else if (strcmp(choose, "geo") == 0)
        {
            if (strstr(list[i].element, "geo"))
            {
                printf("%-10s | %-1s | %-10s | %i\n", list[i].name, list[i].gender, list[i].element, list[i].star);
            }
        }
        else
        {
            printf("Try again!\n");
        }
    }
}

int main()
{
    char header[200];
    FILE *fptr = fopen("file.csv", "r");
    if (fptr == NULL)
    {
        printf("Can't open file!");
        return 1;
    }
    fgets(header, sizeof(header), fptr);
    while (!feof(fptr))
    {
        fscanf(fptr, "%[^,],%[^,],%[^,],%i\n", list[global].name, list[global].gender, list[global].element, &list[global].star);
        global++;
    }

    int choose;
    printf("===========================================\n");
    printf("||       Genshin Impact - database       ||\n");
    printf("===========================================\n");
    printf("1. Display all character in decending order\n");
    printf("2. Search charater by element\n");
    printf("3. Update file.csv\n");
    printf("4. About\n");
    printf("Choose input: ");
    scanf("%i", &choose);

    switch (choose)
    {
    case 1:
        bubblesort();
        for (int i = 0; i < global; i++)
        {
            printf("%-10s | %-1s | %-10s | %i\n", list[i].name, list[i].gender, list[i].element, list[i].star);
        }
        break;
    case 2:
        search_element();
        break;
    case 3:
        fptr = fopen("file.csv", "a");
        printf("format: name,gender,element,star\n");
        printf("input: ");
        fgets(header, sizeof(header), fptr);
        scanf("%[^,],%[^,],%[^,],%i", list[global].name, list[global].gender, list[global].element, &list[global].star);
        fprintf(fptr, "%s,%s,%s,%i", list[global].name, list[global].gender, list[global].element, list[global].star);

        fclose(fptr);
        break;
    case 4:
        printf("About:\n");
        printf("Program for display all Genshin Impact character,\n");
        printf("you can add character in the file.csv\n");
        break;
    }

    return 0;
}