CC = g++
CFLAGS = -std=c++17 -Wall
OBJS = luckyTicket.o
OUTPUTNAME = luckyTicketFinder

all: $(OBJS)
	@echo $@
	$(CC) $(CFLAGS) $(OBJS) -o $(OUTPUTNAME)

luckyTicket.o:
	@echo $@
	$(CC) $(CFLAGS) -c luckyTicket/luckyTicket.cpp

clean:
	@echo $@
	rm -f *.o
