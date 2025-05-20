int foo();
int get_version(char *rbuf, int size);
#define MAX_BUF_SIZE 32
int main(int argc, char **argv)
{
	char buf[MAX_BUF_SIZE] = {0};
	int rc = get_version(buf, sizeof(buf) - 1);
	if (rc > 0) {
		printf("(rc=%d) version = %s\n", rc, buf);
	}
	return foo(3);
}
