/* practicing of c pointer */

#include <stdio.h>
int main(){

	int i;

	char *titles[] = { "A tale of two cities,"
			"wuthering heights",
			"Don Quixote",
			"odyssey",
			"Moby-Dick",
			"Hamlet",
			"Gulliver's Travels"
	};

	char **bestBooks[3];
	char **englishBooks[4];


	bestBooks[0] = &titles[0];
	bestBooks[1] = &titles[3];
	bestBooks[2] = &titles[5];

	englishBooks[0] = &titles[1];
	englishBooks[1] = &titles[2];
	englishBooks[2] = &titles[5];
	englishBooks[3] = &titles[6];

	// print bestBooks
	for (i=0; i<3; i++)
		printf("bestBooks[%d]: %s\n", i, *bestBooks[i]);

	// print englishBooks
	for (i=0; i<4; i++)
		printf("englishBooks[%d]: %s\n", i, *englishBooks[i]);

}
