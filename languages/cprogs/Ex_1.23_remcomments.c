/*  Exercise 1.23
 *
 * Program to remove comments from a C Program.
 *
 * Program should echo quotes and character constants properly
 * C comments do not nest
 *
 */
// Aufgabe1-23 Schreiben Sie ein Programm, welches Kommentare aus einem C- Programm löscht
#include <stdio.h>
#define MAXLINE 1000000
int main(void) {
	int c, j;
	int len = 0;		
	char line[MAXLINE];	
	while ((c = getchar()) != EOF) {
		line[len] = c;
		len++;
	}
	for (j = 0; j < len; j++) {
		if (line[j] == '/' && line[j + 1] == '/') {	 
			while (line[j] != '\n') {
				++j;
			}
		}
		else if (line[j] == '/' && line[j + 1] == '*') {
			++j;
			++j;
			 
			while ((line[j] == '*' && line[j + 1] == '/')  || line[j] != '/') {
				++j;	
			}
		}
		else {
			printf("%c", line[j]);
		}
	}
	return 0;
}
