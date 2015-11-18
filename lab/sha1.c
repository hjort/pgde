#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char *argv[])
{
	int i = 0;
	unsigned char temp[SHA_DIGEST_LENGTH];
	char buf[SHA_DIGEST_LENGTH * 2];

	if (argc != 2) {
		printf("Usage: %s string\n", argv[0]);
		return -1;
	}

	memset(buf, 0x0, SHA_DIGEST_LENGTH * 2);
	memset(temp, 0x0, SHA_DIGEST_LENGTH);

	SHA1((unsigned char *) argv[1], strlen(argv[1]), temp);

	for (i=0; i < SHA_DIGEST_LENGTH; i++) {
		sprintf((char*)&(buf[i * 2]), "%02x", temp[i]);
	}

	printf("%s\n", buf);
	//printf("SHA1 of %s is %s\n", argv[1], buf);

	return 0;
}

/*
int main()
{
	const unsigned char ibuf[] = "Hello, World";
	char obuf[20];

	SHA1(ibuf, strlen(ibuf), obuf);
	//unsigned char *SHA1(const unsigned char *d, unsigned long n, unsigned char *md);

	int i;
	for (i = 0; i < 20; i++) {
		printf("%02x ", obuf[i]);
	}
	printf("\n");

	return 0;
}
*/
