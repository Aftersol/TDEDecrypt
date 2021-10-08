#if (_MSC_VER)
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* const a = "599Cc51887A8cb0C20F9CdE34cf9e0A535E5cAd1C26c7b562596ACC207Ae9A0bfB3E3161f31af5bEf1c2f064b3628174D83BF6E0739D9D6918fD9C2Eba02D5aD\0";
const char* const b = "0C3b676fe8d7188Cde022F71632830F36b98b181aD48Fed160006eA59\0";

int main()
{
	char inputName[512], outputName[512];

	memset(inputName, '\0', 512);
	memset(outputName, '\0', 512);

	printf("Enter input file: ");
	fgets(inputName, 511, stdin);
	inputName[strlen(inputName) - 1] = '\0';

	printf("Enter output name: ");
	fgets(outputName, 511, stdin);
	outputName[strlen(outputName) - 1] = '\0';

	FILE* infile = fopen(inputName, "rb");
	FILE* outfile = fopen(outputName, "wb");

	if (!infile)
	{
		printf("Cannot read %s", inputName);
		return -1;
	}

	if (!outfile)
	{
		printf("Cannot output %s", outputName);
		return -1;
	}

	int dat, i = 0;
	while ((dat = fgetc(infile)) != EOF)
	{
		fputc(dat ^ a[i & 0x7F] ^ b[i % 57], outfile);
		i++;
	}

	fclose(infile);
	fclose(outfile);

	return 0;
}