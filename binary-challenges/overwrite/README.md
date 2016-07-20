#Buffer Overflow Challenge - Overwrite Variable
The goal of these challenges is to overwrite the "key" variable with the proper value in order to pass the program and execute a shell
## Overwrite1
Overwrite1 was taken from http://pwnable.kr/ challenge "bof". It is running live at **nc pwnable.kr 9000** and can be exploited there to receive a flag. It is important to note that the overwrite1 binary in this directory is compiled with stack-smashing protection. This means that even when succesfully exploited on your local system it will not pop a shell. However, the live version running at **nc pwnable.kr 9000** has no such protections and can be succesfully exploited. Use the local binary here to reverse and create a working payload to deliver to the live service and get the flag. (Compiling from overwrite1.c on x64 system with -m32 option will result in a binary with an additional "lea $esp+0x10" instruction and make this challenge nearly impossible)

### Overwrite1 Solution
<details>
<summary>**SPOILER**</summary>
GDB Peda:</br>
1. Break main</br>
2. step into first function (func)</br>
3. next down to <gets></br>
4. Break *func+35 for easy return (the call to gets)</br>
6. "pattern create 64" to make a string pattern of 64 bytes (we just guess the 64)</br>
7. next and input the pattern without the quotes</br>
8. Notice we now land on a cmp of ebp+0x8 with the correct key value of 0xcafebabe; ebp+0x8 is the location of our key variable contents</br>
9. We must overflow the buffer with our input so that it overwrites ebp+0x8 and allows us to input the correct key!</br>
10. We can view the address (and value) of ebp+0x8 with "x $ebp+0x8"</br>
11. To find the distance from our input to ebp+0x8 we telescope 25 to view the last 25 stack pushes</br>
12.Find the proper address and then due an offset search fo the pattern it holds to find how many bytes we need to fill to reach our target address ebp+0x8</br>
13. "pattern offset AAGAAcAA2AAH" (this is the string contained at the address of ebp+0x8...found from telescope or x) -- offset is 52 therefor it's 52 bytes from our input.</br>
14. Finally, we overflow the buffer with 52 bytes so that we can write the correct key to to the proper location (over the key variable)</br>
15. perl -e 'print "A"x52 . "\xbe\xba\xfe\xca"' | ./overflow (the location is backwards because it's little endian</br>
16. Somtimes binaries are compiled with stack protection so you may get an error. But that's normal. If you want to test this you can solve the original challenge at pwnable.kr:9000</br>
</details>

Use my bufoverflow_remote.py template from my "tools" repo for easy way to deploy the payload to pwnable.kr:9000 and get the flag!
