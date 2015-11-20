TARGET = FFT
OBJS = fft.o
CFLAGS = --static -w
LDFLAGS = -lm 
MACROS = ../../null_macros/c.m4.null
CC = arm-linux-gnueabi-gcc
x = *

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET) $(LDFLAGS)

.SUFFIXES:
.SUFFIXES:	.o .c .C .h .H

.H.h:
	m4 ${MACROS} $*.H > $*.h

.C.c:
	m4 $(MACROS) $*.C > $*.c

.c.o:
	$(CC) -c $(CFLAGS) $*.c

.C.o:
	m4 $(MACROS) $*.C > $*.c
	$(CC) -c $(CFLAGS) $*.c
clean:
	rm fft.o FFT
