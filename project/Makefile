#makefile configureation
COMMON_OBJECTS =
CPU	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC	       = msp430-elf-gcc
AS	       = msp430-elf-as

all: toy.elf

#additional rules for files
toy.elf: ${COMMON_OBJECTS} stateMachine.o led.o wdInterruptHandler.o switches.o buzzer.o mainRun.o ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf
