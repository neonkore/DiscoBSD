/*
 * head - give the first few lines of a stream or of each of a set of files
 *
 * Bill Joy UCB August 24, 1977
 *
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    copyout(int);
int     getnum(char *);

int linecnt = 10;
int argc;

int
main(Argc, argv)
    int Argc;
    char *argv[];
{
    register int argc;
    char *name;
    register char *argp;
    static int around;

    Argc--, argv++;
    argc = Argc;
    do {
        while (argc > 0 && argv[0][0] == '-') {
            linecnt = getnum(argv[0] + 1);
            argc--, argv++, Argc--;
        }
        if (argc == 0 && around)
            break;
        if (argc > 0) {
            close(0);
            if (freopen(argv[0], "r", stdin) == NULL) {
                perror(argv[0]);
                exit(1);
            }
            name = argv[0];
            argc--, argv++;
        } else
            name = 0;
        if (around)
            putchar('\n');
        around++;
        if (Argc > 1 && name)
            printf("==> %s <==\n", name);
        copyout(linecnt);
        fflush(stdout);
    } while (argc > 0);
}

void
copyout(cnt)
    register int cnt;
{
    register int c;
    char lbuf[BUFSIZ];

    while (cnt > 0 && fgets(lbuf, sizeof lbuf, stdin) != 0) {
        printf("%s", lbuf);
        fflush(stdout);
        cnt--;
    }
}

int
getnum(cp)
    register char *cp;
{
    register int i;

    for (i = 0; *cp >= '0' && *cp <= '9'; cp++)
        i *= 10, i += *cp - '0';
    if (*cp) {
        fprintf(stderr, "Badly formed number\n");
        exit(1);
    }
    return (i);
}
