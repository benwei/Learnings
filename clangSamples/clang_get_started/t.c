typedef float V __attribute__((vector_size(16)));
V foo(V a, V b) { return a+b*a; }

int main(int argc, char **argv)
{
	V a = {3.0}, b = {4.0};
	foo(a, b);
	return 0;
}
