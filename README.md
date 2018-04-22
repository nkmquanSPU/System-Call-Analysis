# Two programs which measure the cost of a system call `fread()`. Each program
* Reads from the `test.txt` file which contains a string "Hello!" (quotation marks are excluded).
* Measures the cost of a 0-byte (`measure_0-byte`) and 1-byte (`measure_1-byte`) read using `gettimeofday()`
## Usage:
* `./measure_0-byte`
* `./measure_1-byte`

** Author: Quan Nguyen