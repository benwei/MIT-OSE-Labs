system=`uname -s`

case $system in
CYGWIN*)
qemu -hda lab/obj/kern/kernel.img
;;
*)
echo "Unsupported: add suitable qemu command"
;;
esac

