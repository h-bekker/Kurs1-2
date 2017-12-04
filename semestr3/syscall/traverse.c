#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>


void 
traverse(char const *dir)
{
	char name[PATH_MAX];
	DIR *d;
	struct dirent *dd;
	off_t o;
	struct stat s;
	char *delim = "/";

	if (!strcmp(dir, "/")) delim = "";//we don't need delim, if it is root

	if (!(d = opendir(dir))) {
		perror(dir);
		return;
	}

	while ((dd = readdir(d))) {//while we have records
		if (!strcmp(dd->d_name, ".") || !strcmp(dd->d_name, ".."))
			continue;

		snprintf(name, PATH_MAX, "%s%s%s", dir, delim, dd->d_name);//construct the path
		if (lstat(name, &s) < 0) continue; //lstat returns information about symbolic links
		if (S_ISDIR(s.st_mode)) {
			o = telldir(d); // save current position
			closedir(d);
			traverse(name); //recursion

			if (!(d = opendir(dir))) {
				perror(dir);
				return;
			}
			seekdir(d, o);
		} else {

			printf("%s\n", name);
		}
	}
	closedir(d);
}

int 
main(void)
{
	traverse("/");
	return 0;
}
