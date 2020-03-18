
/*
 * https://www.poftut.com/mmap-tutorial-with-examples-in-c-and-cpp-programming-languages/
 * As programmers we generally use malloc() , free() and similar functions in order to allocate memory.
 * They are provided by glibc() library. The actual work is done by mmap() and munmap()which is a Linux systemcall.
 * mmap() provides flexible memory mapping it has a lot of parameters to use.
 * void *mmap(void *addr, size_t lengthint " prot ", int " flags ,int fd, off_t offset)
 * 	void *addr is the address we want to start mapping
 *  	size_t lengthint is the size we want to map in as integer
 *  	PROT_READ|PROT_WRITE|PROT_EXEC options about page
 *  	MAP_ANON|MAP_PRIVATE options about page
 * We have two option about memory mapping for sharing.
 *  MAP_SHARED will map given page and this will be also visible by other processes.
 *  MAP_PRIVATE will map given page and this will not visible to other processes.
 *  
 */
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
int main(void) {
	size_t pagesize = getpagesize();
	printf("System page size: %zu bytes\n", pagesize);
	char * region = mmap(
		(void*) (pagesize * (1 << 20)),	// Map from the start of the 2^20th page
		pagesize,			// for one page length
		PROT_READ|PROT_WRITE|PROT_EXEC,
		MAP_ANON|MAP_PRIVATE,		// to a private block of hardware memory
		0,
		0
	);
	if (region == MAP_FAILED) {
		perror("Could not mmap");
		return 1;
	}
	strcpy(region, "Hello, poftut.com");
	printf("Contents of region: %s\n", region);
	int unmap_result = munmap(region, 1 << 10);
	if (unmap_result != 0) {
		perror("Could not munmap");
		return 1;
	}
	// getpagesize
	return 0;
}
