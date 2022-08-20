# push_swap

## Final algorithm

![pushswap](https://user-images.githubusercontent.com/93100775/185752366-1a301fc9-803b-430c-a1a2-66890e2ac866.gif)
This push_swap visualiser is offered by elijahkash : https://github.com/elijahkash/push_swap_gui

## Project

Push_swap is an algorithm project of the common core in 42 school. There is 2 stacks named `a` and `b`, and the goal is to sort in ascending order numbers into stack a with a limited set of operations :

`sa` (swap a) :  Swap the first 2 elements at the top of stack a,

`sb` (swap b) : Swap the first 2 elements at the top of stack b,

`ss` : sa and sb at the same time,

`pa` (push a) : Take the first element at the top of b and put it at the top of a,

`pb` (push b) : Take the first element at the top of a and put it at the top of b,

`ra` (rotate a) : Shift up all elements of stack a by 1, the first element becomes the last one,

`rb` (rotate b): Shift up all elements of stack b by 1, the first element becomes the last one,

`rr` : ra and rb at the same time,

`rra` (reverse rotate a): Shift down all elements of stack a by 1, the last element becomes the first one,

`rrb` (reverse rotate b) : Shift down all elements of stack b by 1, the last element becomes the first one,

`rrr` : rra and rrb at the same time.

In order to validate the project, it is necessary to sort the stack with the lowest possible number of operations. 
A scale is fixed to obtain the maximum points :

- With a list of **3 values**, the maximum of instructions is **2**, and for **5 values**, it's **12**.
- To have all the points with **100 values**, the worst case of instruction need to stay bellow **700**. For **500 values**, it's **5500**.


Some errors must be treated, for example : some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.

For the project, a checker is provided in order to check if the program sort the stack properly. The **bonus part** purpose to create our own checker.

## Installation

```shell
git clone git@github.com:Sleleu/push_swap.git
cd push_swap
make
```

## Run the program

### Run push_swap

To run push swap with values :

```shell
./push_swap 2 1 8 6 10 4 15
```

It will display the following operations :

![push_swap](https://user-images.githubusercontent.com/93100775/185756917-95794b57-10d5-468e-a3e9-964f7c7018b4.jpg)

To run push swap and count the number of instructions :

```shell
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

### Run push_swap with the checker

```shell
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker
```
