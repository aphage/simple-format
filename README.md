# simple-format
c++11 simple format

```c++
int main() {
    std::cout << format("Hello {} {}!\n", "world", "{}");
 
    std::string fmt;
    for (int i{}; i != 3; ++i) {
        fmt += "{} "; // constructs the formatting string
        std::cout << fmt << " : ";
        std::cout << format(fmt, "alpha", 'Z', 3.14, "unused");
        std::cout << '\n';
    }
}
```

Output:
```txt
Hello world {}
{}  : alpha 
{} {}  : alpha Z 
{} {} {}  : alpha Z 3.14
```
