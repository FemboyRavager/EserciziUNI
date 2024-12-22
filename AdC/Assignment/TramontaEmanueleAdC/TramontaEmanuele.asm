.global main
.data
H: .space 256 #l*l*sizeOfInt
.align 2
l: .word 8
.align 2

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
#
#.macro print_str(%x)                    per debugging, ignorare
#	li a7, 4
#	la a0, %x
#	ecall
#.end_macro
#
#.macro print_int(%x)
#	li a7, 1
#	lw a0, (%x)
#	ecall
#.end_macro
#.align 2
#msgSpace: .string " "
#.align 2
#msgEqual: .string "="
#.align 2
#msgNL: .string "\n"
#.align 2
#msgHOpen: .string "H["
#.align 2
#msgHClose: .string "]"
#.align 2
#msgSpaces: .string "   \t"
#.align 2
#msgI: .string "i="
#.align 2
#msgJ: .string "|j="
#.align 2
#msgT: .string "|t="

.text
main:
 li s6, 0 #int s
 jal functionStart #chiama functionStart
 mv s6, a0 #assegna il return fi functionStart a s6
 print_i(s6)
 exit(0)
 
 
functionStart:
#Inizializzo variabili. Il programma dato non inizializza a valori specifici tranno per m, ma inizializzaarle a 0 è il modo più intuitivo
 li s0, 2 #m=2
 li s1, 0 #i=0
 li s2, 0 #j=0
 li s3, 0 #k=0
 li s4, 0 #t=0
 li s5, 0 #u=0
 
iLoop: #i e j già inizializzate a 0, ma j deve essere resettata a ogni ciclo i
 lw t6, l
 bge s1,t6, endFirstThreeFor  #se i>=l, salta il for, altrimenti prosegue dentro
 li s2,0 #j=0 resetto j per cicli successivi
 
jLoop:
 lw t6, l
 bge s2,t6, endILoop #se j>=l, salta a finalizzazione iLoop
 bne s1, zero, kLoopInitiate #i!=0
 bne s2, zero, kLoopInitiate #j!=0 siccome sono AND, posso metterli negati in sequenza per raggiungere l'else
 #se i==j==0, H[i+l+j] sarà sempre H[0], 
 #ma ricordo che il professore ha specificato di assemblare senza ottimizzazioni, quindi farò i calcoli comunque
 la t2, H # t2 = *H
 lw t1, l #t1=l=8  h
 mul t1,t1,s1 #t1=l*i
 add t1,t1,s2 #t1=t1+j. H offset è calcolato, anche se so già che è 0 :( .
 slli t1,t1,2 #shift per size di int
 add t2, t2, t1 #applico offset a *H
 li t3, 10 #carico valore 10 in t3
 sw t3, (t2) #salvo 10(in t2) a *H[i*l*j]
 j endJLoop
#else
kLoopInitiate:
 li s3,0 #k=0	già inizializzato, ma resetto per loop futuri 
kLoop:
 li t6, 5
 bgt s3,t6, endJLoop #se k>5, salta a finalizzazione jLoop
 add t0, s3, zero #set t0 to s3(k)
 li t6, 1 #t6=1
 sll s4, t6, s3 #t = 1 << k
 blt s1, s4, endKLoop #if i<t
 bge s2, s4, endKLoop #if j>=t	come prima, essendo in AND basta ne fallisca una (o si verifichi la negazione di una)
 
 #Calcolo H[i*l+j]
 la t2, H # t2 = *H
 lw t1, l #t1=l=8
 mul t1,t1,s1 #t1=l*i
 add t1,t1,s2 #t1=t1+j. H offset è calcolato
 slli t1, t1, 2 #shift per size di int
 add t2, t2, t1 #applico offset a *H
 
 #Calcolo H[(i-t) * l + j]
 la t3, H #t3 = *H
 lw t4, l #t4=l=8
 sub t5, s1,s4 #t5=i-t
 mul t4, t4, t5 #t4(l)=l*t5(i-t)
 add t4, t4, s2 #t4 = l*(i-t)+s2(j)
 slli t4, t4, 2 #shift per size di int
 add t3, t3, t4 #applico offset a t3(H)
 lw t3, (t3)
 
 #Assegno H[(i-t) * l + j] a H[i*l+j]
 #print_str(msgHOpen)
 srli t1, t1, 2
 #print_i(t1)
 slli t1,t1,2
 #print_str(msgHClose)
 #print_str(msgEqual)
 #print_i(t3)
 #print_str(msgSpaces)
 #print_str(msgI)
 #print_i(s1)
 #print_str(msgJ)
 #print_i(s2)
 #print_str(msgT)
 #print_i(s4)
 #print_str(msgNL)
 sw t3, (t2)
 #cascade nella fine del kLoop
endKLoop:
 addi s3, s3, 1 #incremento k
 j kLoop
 
endJLoop:
 addi s2, s2, 1 #incremento j
 j jLoop
 
endILoop:
 addi s1, s1, 1 #incremento i
 j iLoop
 
 
endFirstThreeFor:
 li s5, 0 #u=0 superfluo, ma asseemblo senza fare domande
 li t0, 16 #t0=16
secondKLoop:
 bge s3, t0, end #se k>=16 salta a fine funzione
 la t3, H #t3 = *H
 mv t4, s3 #t4=k(s3)
 slli t4, t4, 2 #shift per size di int
 add t3, t3, t4 # calcolo H[k]
 lw t2, (t3) #t2 = H[k]
 add s5, s5, t2
 #cascade nella fine del loop  
endSecondKLoop:
 addi s3, s3, 1 #k++
 j secondKLoop
 
end:
 add a0, s3, zero # a0= k(s3)
 ret
 

 
