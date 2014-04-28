/*
 * hw5main.c
 * This is the main file for hw5.
 * It depends on event.h
 */
#include <stdio.h>
#include <string.h>
#include "event.h"

int main(int argc, char **argv) {
	char cmd[BUFLEN], buf[BUFLEN];
	int argoffset;
	InitTable();
	while (1) {
		PrintPrompt();
		if (fgets(buf, BUFLEN, stdin) == NULL) {
			break; /* user typed ^D to indicate EOF */
		}
		if (sscanf(buf, "%s%n", cmd, &argoffset) != 1) {
			continue;
		}
		if (!strcmp(cmd, CMD_HELP)) {
			PrintHelp();
		} else if (!strcmp(cmd, CMD_GOTO)) {
			/* scan n */
			int eventNum = -1;
			if (sscanf(buf+argoffset, "%d", &eventNum) != 1) {
				fprintf(stderr, "usage: " CMD_GOTO " eventNumber\n");
			} else {
				GotoEvent(eventNum);
			}
		} else if (!strcmp(cmd, CMD_LIST)) {
			/* try to scanf */
			int eventNum = -1;
			sscanf(buf+argoffset, "%d", &eventNum);
			ListEvent(eventNum);
		} else if (!strcmp(cmd, CMD_ADD)) {
			for (; buf[argoffset] && buf[argoffset] <= ' '; argoffset++) {
			}
			AddEvent(buf+argoffset);
		} else if (!strcmp(cmd, CMD_DEL)) {
			int eventNum = -1;
			sscanf(buf+argoffset, "%d", &eventNum);
			DeleteEvent(eventNum);
		} else if (!strcmp(cmd, CMD_QUIT)) {
			break;
		} else {
			fprintf(stderr, "unknown command: %s\n", cmd);
		}
	}
}
