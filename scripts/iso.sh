#!/bin/sh

mkdir -pv isodir/boot/grub

cp kernel-i386 isodir/boot/kernel-i386

cat > isodir/boot/grub/grub.cfg << EOF
menuentry "Dart" {
	multiboot /boot/kernel-i386
}
EOF

grub-mkrescue -o dart-i386.iso isodir
