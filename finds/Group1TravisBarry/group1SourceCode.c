#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int scanInt() {   
    int number = 0;
   
    printf("Enter an integer: ");  
    
    // reads and stores input
    scanf("%d", &number);
    while (getchar() != '\n')
        continue;
    
    return number;
}

int compare(int x, int y)
{
	if (x == y)
	{
		return 0;
	}
	else if (x<y)
	{
		return -1;
	}
	return 1;
}

int getIndexFromSortedList(int* arr, int length, int value)
{
	for (int x=0;x<length;x++)
	{
		if (arr[x] == value)
		{
			return x;
		}
		else if (arr[x] > value)
		{
			break;
		}
	}
	return -1;
}

void validatePasswordRequirements(char * line)
{
	int validated = 1;
	int errorcode = 0;
	//TODO: Add password requirements check
	if (validated != 1)
	{
		strcpy(line, "PASSWORD ERROR:");
		if (line != NULL)
		{
			errorcode = 1;
		}
		else 
		{
			errorcode = 2;
		}
		char buffer[sizeof(errorcode)];
		sprintf(buffer, "%d", errorcode);
		strcat(line, buffer);
	}
	else
	{
		errorcode = -1;
	}
}

char* scanNewPassword()
{
	char * line = malloc(100), * linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        if(c == EOF)
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }
    *line = '\0';
	validatePasswordRequirements(line);
	return line;
}

int exampleMethod1(int a)
{
	int b = a;
	int exampleResult1 = 0;
	if (a > 0) 
	{
		exampleResult1 = pow((50/5),(a - b));
	}
	else 
	{
		exampleResult1 = pow((50*5),(a - b));
	}
	return exampleResult1;
}

int getFactorialOfTwo()
{
	int result = 0;
	int factorialBase = 2;
	int currentMultiplier = factorialBase;
	for (int x=factorialBase;x>1;x--)
	{
		result = currentMultiplier * (currentMultiplier - 1);
		currentMultiplier--;
	}
	return result;
}

int isEven(int number)
{
    int isEven = 0;
    if (number % 2 == 0)
    {
        isEven = 1;
    }
    else if (number % 2 == 1)
    {
        isEven = 0;
    }
    return isEven;
}

void main()
{
    printf("%d", scanInt());
    printf("\n");
    printf("%d", compare(2,2));
    printf("\n");
    int sortedList[] = {1,2,3,4,5};
    printf("%d", getIndexFromSortedList(sortedList, 5, 3));
    printf("\n");
    printf("%s", scanNewPassword());
    printf("%d",exampleMethod1(5));
    printf("\n");
    printf("%d", getFactorialOfTwo());
	printf("\n");
    printf("%d", isEven(5));
}