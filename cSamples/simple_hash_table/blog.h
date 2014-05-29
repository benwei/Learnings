#ifndef BLOG_H
#define BLOG_H

#ifdef DEBUG
# define BLOG(...) printf(__VA_ARGS__)
#else
# define BLOG(...)
#endif

#endif /* BLOG_H */
