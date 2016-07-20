#Buffer Overflow Challenge - Shellcode
The goal of these challenges is to overwrite the instruction pointer register so that you may point it to your shellcode payload. Your shellcode payload should open a shell.
## Shellcode1

### Shellcode1 Solution
<details>
<summary>**SPOILER**</summary>
GDB Peda:</br>
To solve:
1. break main
2.step to gets
3. create pattern
4.input and step until EIP overwritten
5.calculate length
6.NOPS -> EIP + buf size + EIP size -> shellcode

</details>
