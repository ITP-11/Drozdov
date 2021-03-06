#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

struct infoAboutFile
{
	int size;
	char name[100];
	int id;	
};

void addFile(struct infoAboutFile *file, int *memoryLeft, int *numberOfFile);
void deletFile(struct infoAboutFile *file, int *memoryLeft, int *numberOfFile);
void showTable(int size, struct infoAboutFile *file, int numberOfFile, int memoryLeft);
void defragment(int size, struct infoAboutFile *file, int *numberOfFile, int *memoryLeft);

int main()
{
	SetConsoleCP (1251); 
	SetConsoleOutputCP (1251);
	
	struct infoAboutFile files[1000];
	int sizeOfMemory, k = 1, memoryLeft, numberOfFile = 0;
	puts("Aaaaeoa ?acia? iaiyoe: ");
	scanf("%d", &sizeOfMemory);
	memoryLeft = sizeOfMemory;
	while(k != 0)
	{
		puts("1.Aiaaaeou oaee");
		puts("2.Oaaeeou oaee");
		puts("3.Oaaeeoa iaiyoe");
		puts("4.Aao?aaiaioaoey");
		puts("0.Auoia");
		printf("Aao auai?: ");
		scanf("%d", &k);
		system("cls");
		switch(k)
		{
			case 1:
				addFile(&files, &memoryLeft, &numberOfFile);
				break;
			case 2:
				deletFile(&files, &memoryLeft, &numberOfFile);
				break;
			case 3:
				showTable(sizeOfMemory, &files, numberOfFile, memoryLeft);
				break;
			case 4:
				defragment(sizeOfMemory, &files, &numberOfFile, &memoryLeft);
				break;
			case 0:
				break;
			default:
				break; 
		}
	}
	fflush(stdin);
	getchar();	
}

void addFile(struct infoAboutFile *file, int *memoryLeft, int *numberOfFile)
{
	puts("Aaaaeoa iacaaiea oaeea: ");
	scanf("%s", &(file+(*numberOfFile))->name);
	puts("Aaaaeoa ?acia? oaeea: ");
	scanf("%d", &(file+(*numberOfFile))->size);
	if((file+(*numberOfFile))->size > *memoryLeft)
		puts("Ianoi iaainoaoi?ii");
	else
	{
		(file+(*numberOfFile))->id = *numberOfFile + 1;
		*memoryLeft = *memoryLeft - (file+(*numberOfFile))->size;
    	*numberOfFile += 1;
	}
}

void deletFile(struct infoAboutFile *file, int *memoryLeft, int *numberOfFile)
{
	int i, k = 0; 
	char deletName[100];
	puts("Aaaaeoa iacaaiea oaeea: ");
	scanf("%s", &deletName);
	for(i = 0; i < *numberOfFile; i++)
	{
		if(strcmp(deletName, (file+i)->name) == 0)
		{
				*memoryLeft = *memoryLeft + (file+i)->size;
				(file+i)->id = 0;
				k = 1;
		}
	}
	if(k == 0)
		puts("Oaeiai oaeea iao");
}

void showTable(int size, struct infoAboutFile *file, int numberOfFile, int memoryLeft)
{
	int i, j, k = 1, fullMemoryLeft;
	fullMemoryLeft = memoryLeft;
	for(j = 0; j < numberOfFile; j++)
	{
		if((file+j)->id == 0)
		{
			for(i = 0; i < (file+j)->size; i++)
			{
				printf("%d", (file+j)->id);
				if(k % 50 == 0)
					printf("\n");
				k += 1;
				fullMemoryLeft -= 1;
			}
		}
		else
		{
			for(i = 0; i < (file+j)->size; i++)
			{
				printf("%d", (file+j)->id);
				if(k % 50 == 0)
					printf("\n");
				k += 1;
			}	
		}
    }
	for(i = 0; i < fullMemoryLeft; i++)
	{
		printf("%d", (file+j)->id);
		if(k % 50 == 0)
			printf("\n");
		k += 1;
	}
	printf("\n\n");
	printf("Nienie oaeeia\n");
	for(i = 0; i < numberOfFile; i++)
	{
		if((file+i)->id != 0)
		{
			printf("name: %s\n", (file+i)->name);
			printf("size: %d\n", (file+i)->size);
			printf("id: %d\n\n", (file+i)->id);
		}  
	}
}

void defragment(int size, struct infoAboutFile *file, int *numberOfFile, int *memoryLeft)
{
	int i, j;
	i = 0; 
	while(i < *numberOfFile)
	{
		if((file+i)->id == 0)
		{
			j = i;
			
			while(j < *numberOfFile)
			{
				*(file+j) = *(file+j+1);
				j++;
			}
			*numberOfFile -= 1;
			i -= 1;
		}
		i +=1;
	}
}
