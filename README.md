# PUSH_SWAP

Algorithm project : We have at our disposal a set of int values, 2 stacks and a set of instructions to manipulate.
and we have to print in STDOUT the minimum possible instructions to sort stack A (from args)

set of instructions :
```Any
sa : swap a - swap the first 2 elements at the top of stack a.
sb : swap b - swap the first 2 elements at the top of stack b.
ss : sa and sb at the same time
pa : push a - take the first element at the top of b an put it at the top of a.
pb : push b - take the first element at the top of a an put it at the top of b.
ra : rotate a - shift up all elements of stack a by 1. the first element becomes the last one.
rb : rotate b - shift up all elements of stack a by 1. the first element becomes the last one.
rr : ra and rb at the same time
rra : reverse rotate a - shift down all elements of stack a by 1. the last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack a by 1. the last element becomes the first one.
rrr : rra and rrb at the same time
```
# Virtualizer

This python script was created by @o-reo to visualize work with the PUSH_SWAP 42 Project.
you can use it with this command
```Bash
make && python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
```
