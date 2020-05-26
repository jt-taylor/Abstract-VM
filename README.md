# Abstract-VM
A basic vm 
# What this is
The goal of this Project is to make a very basic asembly language interpreter
the `language' used for this project is described further in the project pdf
but for a simple explanation
* comments start with ';'
* push to stack int_8 int_16 int_32 float or double
* pop
* dump ; print the contents of the stack
- assert ; asserts that the head of the stack is equal to the this paramater
				else thow an exception
- add
- sub
- mul
- div
- mod
- print ; assert that the head of stack is int_8 and prints it char value
- exit ; if not present throw an errorThe goal of this Project is to make a very basic asembly language interpreter

#### Example
```  
; -------------
; sample.avm -
; -------------
push int32(42)
push int32(33)
add
push float(44.55)
mul
push double(42.42)
push int32(42)
dump
pop
assert double(42.42)
exit
;;
