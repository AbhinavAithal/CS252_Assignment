# CS252_Assignment
## Course assignment for CS252(Operating Systems)
## Topic : Kernel Modules and Proc Files
This project aims to demonstrate the process of creating a kernel module and loading it into the Linux kernel and also the process of modifying the linux kernel in order to create an entry in the /proc file system.
This project has been developed on Ubuntu 16.04 LTS run on a Virtual Machine(VMware). It is suggested to use virtual machines as modifying the linux kernel configuration could cause a total system failure.
Creating kernel modules enables the user to establish direct communication/interaction with the kernel and invoke kernel functions.<br />
<br />
<br />
Proc file system is a virtual/pseudo file system created on the fly when the system boots and exists only in the kernel memory.It is used primarily for querying various kernel and per-process statistics and is regarded as the control and information center of the kernel. It basically provides a communication medium between the user space and kernel space. The proc filesystem is dissolved when the system shuts down. 
