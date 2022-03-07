# ft_printf_tester-dbekic
Very simple tester for the mandatory part of ft_printf.

#### Current Flaws
- Only tests with one input variable at a time(e.g. printf("%d", 24) and not printf("%d %d", 24, 24)). The "mix" category does test this however and and could help catch multi-variable issues.
- Does not check for leaks. Be especially careful with hexadecimal conversions.

## How to run
Clone repo into your ft_printf root directory and run command: 
```
./venga
```
