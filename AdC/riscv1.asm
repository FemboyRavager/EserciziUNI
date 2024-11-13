.global	main
.data
msg: .string "\nHello world"

.macro print_str (%x)
	li a7, 4
	la a0, %x
	ecall
.end_macro

.macro print_int (%x)
	li a7, 1
	mv a0, %x
	ecall
.end_macro

.macro scan_int
	li a7, 5
	ecall
.end_macro

.macro exit (%x)
	li a7, 93
	li a0, %x
	ecall
.end_macro

.text
main:
print_str(msg)
exit(0)