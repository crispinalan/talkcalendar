CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4)
LIBS = $(shell $(PKGCONFIG) --libs gtk4) -lm 

SRC = main.c diphone.c wavcat.c dictionary.c

OBJS = $(SRC:.c=.o)

all: talkcalendar

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) -Wall $<


talkcalendar: $(OBJS)
	$(CC) -o $(@F) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
	rm -f talkcalendar
