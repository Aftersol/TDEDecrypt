#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* const a = "599Cc51887A8cb0C20F9CdE34cf9e0A535E5cAd1C26c7b562596ACC207Ae9A0bfB3E3161f31af5bEf1c2f064b3628174D83BF6E0739D9D6918fD9C2Eba02D5aD\0";
const char* const b = "0C3b676fe8d7188Cde022F71632830F36b98b181aD48Fed160006eA59\0";

const char* input = "marina.ogg.tde";
const char* output = "marina.ogg";
//auto input = "D:\\Steam\\steamapps\\common\\Teardown\\data\\gfx\\foam.png.tde";
//auto output = "D:\\Project\\TD\\test\\foam.png";

int main(int argc, char** argv)
{
	char inputName[512], outputName[512];

	/*
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	*/

	memset(inputName, '\0', 512);
	memset(outputName, '\0', 512);

	if (argc < 3)
	{
		printf("Enter input file: ");
		fgets(inputName, 511, stdin);
		inputName[strlen(inputName) - 1] = '\0';

		printf("Enter output name: ");
		fgets(outputName, 511, stdin);
		outputName[strlen(outputName) - 1] = '\0';
	}
	else
	{
		// Only copy 511 bytes to the buffer to prevent buffer overflow

		size_t inputNameSize = (strlen(argv[1]) < 511) ? strlen(argv[1]) : 511;
		size_t outputNameSize = (strlen(argv[2]) < 511) ? strlen(argv[2]) : 511;

		strncpy(inputName, argv[1], inputNameSize);
		inputName[strlen(inputName) - 1] = '\0';

		strncpy(outputName, argv[2], outputNameSize);
		outputName[strlen(outputName) - 1] = '\0';
	}

	/*
	printf("%s\n", inputName);
	printf("%s\n", outputName);
	*/

	FILE* infile = fopen(inputName, "rb");
	FILE* outfile = fopen(outputName, "wb");

	/*FILE* infile = fopen(input, "rb");
	FILE* outfile = fopen(output, "wb");*/

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