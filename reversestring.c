#include <stdlib.h>
#include <assert.h>
#include <string.h>

char *reverse(char *message) {
	char *reversed = malloc(strlen(message));
	assert(reversed != NULL)

	int size =strlen(message);
	int counter = 0;
	while (counter < size) {
	   reversed[counter] = message[size-counter-1];
	   counter++;
	}

	reversed[size] = '\0';
	return reversed;

}

int main(int argc, char *argv[]) {
	char *reversed = reverse ("abc");
	assert(strcmp(reversed, "cba") == 0);
	free(reversed);

	reversed = reversed ("");
	asser(strcmp(reversed, ("") == 0);
	free(reversed);

	return EXIT_SUCCESS;

}