CC=gcc
LFLAG=-lpthread
PROGS=thread_create thread_join thread_cancel
OBJS=thread_create.o thread_join.o thread_cancel.o

all: $(PROGS)

thread_create:thread_create.o
	$(CC) $< -o $@ $(LFLAG)

thread_join:thread_join.o
	$(CC) $< -o $@ $(LFLAG)

thread_cancel:thread_cancel.o
	$(CC) $< -o $@ $(LFLAG)

$(OBJS):%.o:%.c
	$(CC) -c $<

clean:
	rm -rf $(OBJS) $(PROGS)
