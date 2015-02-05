

all: 
	gcc -g -o expense_s knapsack_simple.c
	gcc -g -o expense_e knapsack_enhanced.c

clean:
	rm -rf expense_s expense_e

install:
	./expense_s < test.txt
	./expense_e < test.txt

