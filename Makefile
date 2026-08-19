CC       := gcc
CFLAGS   := -Wall -Wextra -std=c11

SRCDIR   := src
BUILDDIR := build

TARGET   := $(BUILDDIR)/program

SRCS     := $(wildcard $(SRCDIR)/*.c)

OBJS     := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean
