// coppies str1[] into str2[]
void *strcpyy(char *destination, char *source)
{
	while (*source) {
		*destination++ = *source++;
	}

}

void main()
{
	char str1[] = "iva pl ach";
	char str2[] = "spi mi seee";
	strcpyy(str2, str1);
}