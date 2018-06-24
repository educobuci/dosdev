#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <i86.h>

#define VIDEO_INT           0x10      /* the BIOS video interrupt. */

int main(int argc, char const *argv[])
{
  setVga();
  getchar();
  setText();
  return 0;
}

void setVga()
{
  union REGS regs;
  regs.h.ah = 0;
  regs.h.al = 0x13;
  int386(VIDEO_INT, &regs, &regs);
}

void setText()
{
  union REGS regs;
  regs.h.ah = 0;
  regs.h.al = 0x03;
  int386(VIDEO_INT, &regs, &regs);
}