.global	main
.data
A: .word 1, 5, 2, 0, 2, 2, 3,10,
          2, 8, 48, 1,2, 2, 40, 5,
          3,12, 7,14,3,18,31,30,
          15, 10, 11, 43, 2, 12, 7, 9,
          8,11, 9,10,6,18,17, 4,
          4,11,17, 4,3,15,12, 8
H: .space 80
msgSpace: .string " "
msgColon: .string " : "
msgNl: .string "\n"


.macro exit (%x)
	li a7, 93
	li a0, %x
	ecall
.end_macro

.macro print_i(%x)
	li a7, 1
	add a0, %x, zero
	ecall
.end_macro

.macro print_int(%x)
	li a7, 1
	lw a0, (%x)
	ecall
.end_macro 

.macro print_str(%x)
	li a7, 4
	la a0, %x
	ecall
.end_macro

.text
main:

add t0, zero, zero	#t0 è i=0
la s1, A		#s1=address(A)
addi s2, zero, 20	#s2=20
addi s3, zero, 192	#s3=192 (48*4)

loop:
la s1, A		#resetto s1 ad address(A) in quanto offset s1 aumenta di 4 ogni volta, e s1 deve resettarsi
add s1, s1, t0		#apply offset -> A[i]
lw t1, (s1)		#t1=A[i]
bge t1, s2, loopPartTwo	#if A[i]>=20, goto loopPartTwo

la s4, H		#s4=address(H)
slli t1, t1, 2		#t1(A[i] *= 4 (word)
add s4,s4, t1		#s4 += (word)A[i]
lw t2, (s4)		#t2= val of H[A[i]]
addi t2, t2, 1		#t2++
sw t2, (s4)		#H[A[i]]= t2 = H[A[i]]++ 


loopPartTwo:
addi t0, t0, 4		#t0(i) += 4 (word offset)
blt t0, s3, loop	#if i<192, goto loop


add t0, zero, zero	#t0 è i=0
add t3, s2, zero	#t3=20
slli t3, t3, 2		#t3=20*4=120 (word offset)

loopPrint:
la s4, H		#s4=address(H)
add s4, s4, t0		#s4 += (word)i
srli t5, t0, 2		#t5= i/4
print_i(t5) 		#stampa
print_str(msgColon)
print_int(s4)
print_str(msgNl)


addi t0, t0, 4		#t0(i) += 4 (word offset)
blt t0, t3, loopPrint	#if i(*4)<20 (*4) goto LoopPrint

exit(0)


