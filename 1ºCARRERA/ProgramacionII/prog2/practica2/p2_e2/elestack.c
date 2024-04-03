#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "elestack.h"
#include "int.h"

struct _EleStack {
    int *e;
};

EleStack * EleStack_ini() {
    EleStack *ele = NULL;

    ele = (EleStack*) malloc(sizeof (EleStack));
    if (ele == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    ele->e = NULL;

    return ele;
}

void EleStack_destroy(EleStack * eld) {
    int_destroy(eld->e);
    free(eld);
    eld = NULL;
}

Status EleStack_setInfo(EleStack *ele, void *n) {
    if (ele == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return ERROR;
    }

    if (ele->e) int_destroy(ele->e);

    ele->e = int_copy((int*)n);

    if (ele->e == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return ERROR;
    }

    return OK;
}

void * EleStack_getInfo(EleStack * ele) {
    if (ele == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }
    return ele->e;
}

EleStack * EleStack_copy(const EleStack * elcons) {
    EleStack *elc = NULL;

    if (elcons == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    elc = (EleStack*) malloc(sizeof (EleStack));
    if (elc == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    elc->e = int_copy(elcons->e);

    return elc;
}

Bool EleStack_equals(const EleStack *ele1, const EleStack * ele2) {
    if (ele1 == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return ERROR;
    }

    if (ele2 == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return ERROR;
    }

    if (ele1->e == ele2->e) return TRUE;
    return FALSE;
}

int EleStack_print(FILE *f, const EleStack * elcons) {

    if (elcons == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        return -1;
    }

    return fprintf(f, "[%d]",*elcons->e);
}
