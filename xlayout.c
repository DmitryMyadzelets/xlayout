#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/XKBlib.h>
#include <X11/extensions/XKBrules.h>

int main(int argc, char **argv) {
  Display *display = XOpenDisplay(NULL);

  if (display == NULL) {
    fprintf(stderr, "Cannot open display\n");
    exit(1);
  }

  XkbStateRec state;
  XkbGetState(display, XkbUseCoreKbd, &state);

  XkbDescPtr desc = XkbGetKeyboard(display, XkbAllComponentsMask, XkbUseCoreKbd);
  char *group = XGetAtomName(display, desc->names->groups[state.group]);

  XkbRF_VarDefsRec vd;
  XkbRF_GetNamesProp(display, NULL, &vd);

  char *tok = strtok(vd.layout, ",");

  for (int i = 0; i < state.group; i++) {
    tok = strtok(NULL, ",");
    if (tok == NULL) {
      return 1;
    }
  }

  printf("Full name: %s\n", group);
  printf("Layout name: %s\n", tok);

  XFree(group);
  XCloseDisplay(display);

  return 0;
}

