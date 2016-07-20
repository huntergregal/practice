#Buffer Overflow Challenge - Shellcode
The goal of these challenges is to overwrite the instruction pointer register so that you may point it to your shellcode payload. Your shellcode payload should open a shell.
## Shellcode1

### Shellcode1 Solution
<details>
<summary>**SPOILER**</summary>
GDB Peda:</br>
1. break main</br>
2. step to gets</br>
3. create pattern</br>
4. input and step until EIP overwritten</br>
5. calculate length of new EIP value</br>
6. New EIP value = Address of user input + buffer size in hex + size of EIP register (0x04 probably)</br>
7. Paylaod = NOPS (\x90) -> new EIP Value -> shellcode</br>

</details>
