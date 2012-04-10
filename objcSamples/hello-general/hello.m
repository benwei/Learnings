// gcc -g -fgnu-runtime -O -c some_class.m 
#import "hello.h"

@implementation Hello

- (id) init
{
	self = [super init];
	NSLog(@"%s", __FUNCTION__);
	return self;
}

- (void) show
{
	NSLog(@"Hello GNUObjc with GNUstep");
}

- (void) dealloc
{
	NSLog(@"%s", __FUNCTION__);
	[super dealloc];
}

@end

