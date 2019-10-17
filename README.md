# Argon

A small compiler (interpreter at the moment) written in C++.

## Examples

```
> 1 + 2 * 3.
7
> (1 + 2) * 3.
9
> true and false.
false.
> false or true.
true
> true or 2.
TypeError: Unknown operator 'or' for operands Boolean and Integer.
> 1 <= 2.
true
> 1 > 0 or 2 > 3.
true
> x <- 123, y <- 2.
2
> x * y.
246
> x > 300.
false
```

## License

Licensed under the [MIT License](LICENSE.md).
