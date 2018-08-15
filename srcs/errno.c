
#include "../includes/ft_strace.h"

char *get_errno_name(int key)
{
	key = 0 - key;
	switch (key) {
		case (ENOENT):
			return ft_strjoin_nf(ft_strjoin("ENOENT (", strerror(ENOENT)), ")", 1);
		default:
			return "errno not found";
	}
 EPERM
“Operation not permitted.” Only the owner of the file (or other resource) or processes with special privileges can perform the operation.

Macro: int ENOENT
“No such file or directory.” This is a “file doesn’t exist” error for ordinary files that are referenced in contexts where they are expected to already exist.

Macro: int ESRCH
“No such process.” No process matches the specified process ID.

Macro: int EINTR
“Interrupted system call.” An asynchronous signal occurred and prevented completion of the call. When this happens, you should try the call again.

You can choose to have functions resume after a signal that is handled, rather than failing with EINTR; see Interrupted Primitives.

Macro: int EIO
“Input/output error.” Usually used for physical read or write errors.

Macro: int ENXIO
“No such device or address.” The system tried to use the device represented by a file you specified, and it couldn’t find the device. This can mean that the device file was installed incorrectly, or that the physical device is missing or not correctly attached to the computer.

Macro: int E2BIG
“Argument list too long.” Used when the arguments passed to a new program being executed with one of the exec functions (see Executing a File) occupy too much memory space. This condition never arises on GNU/Hurd systems.

Macro: int ENOEXEC
“Exec format error.” Invalid executable file format. This condition is detected by the exec functions; see Executing a File.

Macro: int EBADF
“Bad file descriptor.” For example, I/O on a descriptor that has been closed or reading from a descriptor open only for writing (or vice versa).

Macro: int ECHILD
“No child processes.” This error happens on operations that are supposed to manipulate child processes, when there aren’t any processes to manipulate.

Macro: int EDEADLK
“Resource deadlock avoided.” Allocating a system resource would have resulted in a deadlock situation. The system does not guarantee that it will notice all such situations. This error means you got lucky and the system noticed; it might just hang. See File Locks, for an example.

Macro: int ENOMEM
“Cannot allocate memory.” The system cannot allocate more virtual memory because its capacity is full.

Macro: int EACCES
“Permission denied.” The file permissions do not allow the attempted operation.

Macro: int EFAULT
“Bad address.” An invalid pointer was detected. On GNU/Hurd systems, this error never happens; you get a signal instead.

Macro: int ENOTBLK
“Block device required.” A file that isn’t a block special file was given in a situation that requires one. For example, trying to mount an ordinary file as a file system in Unix gives this error.

Macro: int EBUSY
“Device or resource busy.” A system resource that can’t be shared is already in use. For example, if you try to delete a file that is the root of a currently mounted filesystem, you get this error.

Macro: int EEXIST
“File exists.” An existing file was specified in a context where it only makes sense to specify a new file.

Macro: int EXDEV
“Invalid cross-device link.” An attempt to make an improper link across file systems was detected. This happens not only when you use link (see Hard Links) but also when you rename a file with rename (see Renaming Files).

Macro: int ENODEV
“No such device.” The wrong type of device was given to a function that expects a particular sort of device.

Macro: int ENOTDIR
“Not a directory.” A file that isn’t a directory was specified when a directory is required.

Macro: int EISDIR
“Is a directory.” You cannot open a directory for writing, or create or remove hard links to it.

Macro: int EINVAL
“Invalid argument.” This is used to indicate various kinds of problems with passing the wrong argument to a library function.

Macro: int EMFILE
“Too many open files.” The current process has too many files open and can’t open any more. Duplicate descriptors do count toward this limit.

In BSD and GNU, the number of open files is controlled by a resource limit that can usually be increased. If you get this error, you might want to increase the RLIMIT_NOFILE limit or make it unlimited; see Limits on Resources.

Macro: int ENFILE
“Too many open files in system.” There are too many distinct file openings in the entire system. Note that any number of linked channels count as just one file opening; see Linked Channels. This error never occurs on GNU/Hurd systems.

Macro: int ENOTTY
“Inappropriate ioctl for device.” Inappropriate I/O control operation, such as trying to set terminal modes on an ordinary file.

Macro: int ETXTBSY
“Text file busy.” An attempt to execute a file that is currently open for writing, or write to a file that is currently being executed. Often using a debugger to run a program is considered having it open for writing and will cause this error. (The name stands for “text file busy”.) This is not an error on GNU/Hurd systems; the text is copied as necessary.

Macro: int EFBIG
“File too large.” The size of a file would be larger than allowed by the system.

Macro: int ENOSPC
“No space left on device.” Write operation on a file failed because the disk is full.

Macro: int ESPIPE
“Illegal seek.” Invalid seek operation (such as on a pipe).

Macro: int EROFS
“Read-only file system.” An attempt was made to modify something on a read-only file system.

Macro: int EMLINK
“Too many links.” The link count of a single file would become too large. rename can cause this error if the file being renamed already has as many links as it can take (see Renaming Files).

Macro: int EPIPE
“Broken pipe.” There is no process reading from the other end of a pipe. Every library function that returns this error code also generates a SIGPIPE signal; this signal terminates the program if not handled or blocked. Thus, your program will never actually see EPIPE unless it has handled or blocked SIGPIPE.

Macro: int EDOM
“Numerical argument out of domain.” Used by mathematical functions when an argument value does not fall into the domain over which the function is defined.

Macro: int ERANGE
“Numerical result out of range.” Used by mathematical functions when the result value is not representable because of overflow or underflow.

Macro: int EAGAIN
}
