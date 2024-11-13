.global	main
.data
A: .space 120
msgNotValid: .string "\nNumero non inferiore a 30\n"
msgValid: .string "\nNumero valido\n"
msgArrayFilled: .string "\nArray has been filled, hopefully\n"
msgSum: .string "\nSomma: "
msgAvg: .string "\nMedia: "


.macro readInput
	addi a7, zero, 5
	ecall
.end_macro 

.macro checkValidity
	addi t0, zero, 30
	bge a0, t0, isNotValid
	add s1,  a0, zero  #S1 = K
	li a7, 4
	la a0, msgValid
	ecall
.end_macro

.macro exit (%x)
	li a7, 93
	li a0, %x
	ecall
.end_macro

.macro readK_ints(%x)
	
	
.end_macro

.text
main:
readInput
checkValidity
add s2, zero, zero	#uso s2 come indice per loop, e inizializzo a 0

loopRead:
readInput
add t2, zero, s2	# t2 = i
slli t2, t2, 2		# t2=i  *= 4(word)
	
la a1, A		#a1= address A
	
add a1, a1, t2		#a1 = address A + (i*4)
sw a0, (a1)		#store a0 (input) in address pointed to by a1
addi s2, s2, 1		#i++
blt s2, s1, loopRead	#if i<K goto loopRead
	
li a7, 4
la a0, msgArrayFilled
ecall


add s2, zero, zero	#uso s2 come indice per loop, inizializzo a 0
loopCalculate:
add t2, zero, s2	# t2 = i = s2
slli t2, t2, 2		# t2=i  *= 4(word)

la a1, A		#a1= address A[0]

add a1, a1, t2		#a1= address a[i]
lw t1, (a1)		#t1= val a[i]
add s3, s3, t1		#s3 += t1=a[i]

 addi s2, s2, 1		#i++
 blt s2, s1, loopCalculate	#if i<k goto loopCalculate
 
#Stampa somma
li a7, 4
la a0, msgSum
ecall
li a7, 1
add a0, zero, s3
ecall

#Calcola media
fcvt.s.w fs0, zero	#fs0=0
fcvt.s.w fs1, s3	#fs0=sum
fcvt.s.w fs2, s2	#fs1=K
fdiv.s fs1, fs1, fs2	#fs0=sum/K

#Stampa media
li a7, 4
la a0, msgAvg
ecall
li a7, 2
fadd.s fa0, fs1, fs0	#fa0=fs1=sum/K
ecall

exit(0)

isNotValid:
li a7, 4
la a0, msgNotValid
ecall
exit(0)



