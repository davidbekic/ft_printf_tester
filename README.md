# ft_printf_tester-dbekic
Very simple tester for the mandatory part of ft_printf.

#### Current Flaws
- Only tests with one input variable at a time(e.g. printf("%d", 24) and not printf("%d %d", 24, 24))
- Does not check for leaks. Be especially careful with hexadecimal conversions.

## How to run
Run command ./venga
