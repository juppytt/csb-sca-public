include-dir := ../

.PHONY: all clean

all: flush-reload

clean:
	$(RM) flush-reload

flush-reload: flush-reload.c
	$(CC) $(cflags) -o $@ $^

plot-flush-reload: flush-reload flush-reload.p
	@echo "[+] Run FLUSH+RELOAD..."
	@./flush-reload > flush-reload.csv
	@echo "[*] Results recorded to flush-reload.csv"
	@echo "[+] Plot the result..."
	@gnuplot flush-reload.p

include ./Makefile.common
