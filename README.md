# Process List
This is a Kernel module that lists active processes.

## Author
Karim Abdel Hamid
American University in Cairo
900 143 463

## Building
Go to either folder. Use the makefile by calling `make` in the terminal.

## Usage
You must be inside the 
### Using Terminal
Call the following:
```bash
sudo insmod process_test.ko
sudo rmmod process_test
dmesg -c
```

### Using Makefile
Simply call `make run`.

## Settings
### part1regular:
Remove the following define from the top of the file to print state numbers rather than their textual representation:
`#define PRINT_NUMBERS`

### part2dfs:
In addition to the last define,
`#define PRINT_NUMBERS`
... you can also call the following define to remove tabs:
`#define PRINT_NO_TABS`