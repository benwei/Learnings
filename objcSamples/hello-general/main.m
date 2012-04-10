// sample for using objc class with GNUstep

#import "hello.h"

int main(int argc, char **argv)
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	Hello *obj = [[Hello alloc] init];

	[obj show];

	[obj release];
	[pool drain];
	return 0;
}
