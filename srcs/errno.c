
#include "../includes/ft_strace.h"

char *get_errno_name(int key)
{
	key = 0 - key;
	switch (key) {
		case (ENOENT):
			return ft_strjoin_nf(ft_strjoin("ENOENT (", strerror(ENOENT)), ")", 1);
			case EPERM:
	return ft_strjoin_nf(ft_strjoin("EPERM (" , strerror(EPERM)), ")", 1);
case ESRCH:
	return ft_strjoin_nf(ft_strjoin("ESRCH (" , strerror(ESRCH)), ")", 1);
case EINTR:
	return ft_strjoin_nf(ft_strjoin("EINTR (" , strerror(EINTR)), ")", 1);
case EIO:
	return ft_strjoin_nf(ft_strjoin("EIO: (" , strerror(EIO)), ")", 1);
case ENXIO:
	return ft_strjoin_nf(ft_strjoin("ENXIO (" , strerror(ENXIO)), ")", 1);
case E2BIG:
	return ft_strjoin_nf(ft_strjoin("E2BIG (" , strerror(E2BIG)), ")", 1);
case ENOEXEC:
	return ft_strjoin_nf(ft_strjoin("ENOEXEC (" , strerror(ENOEXEC)), ")", 1);
case EBADF:
	return ft_strjoin_nf(ft_strjoin("EBADF (" , strerror(EBADF)), ")", 1);
case ECHILD:
	return ft_strjoin_nf(ft_strjoin("ECHILD (" , strerror(ECHILD)), ")", 1);
case EDEADLK:
	return ft_strjoin_nf(ft_strjoin("EDEADLK (" , strerror(EDEADLK)), ")", 1);
case ENOMEM:
	return ft_strjoin_nf(ft_strjoin("ENOMEM (" , strerror(ENOMEM)), ")", 1);
case EACCES:
	return ft_strjoin_nf(ft_strjoin("EACCES (" , strerror(EACCES)), ")", 1);
case EFAULT:
	return ft_strjoin_nf(ft_strjoin("EFAULT (" , strerror(EFAULT)), ")", 1);
case ENOTBLK:
	return ft_strjoin_nf(ft_strjoin("ENOTBLK (" , strerror(ENOTBLK)), ")", 1);
case EBUSY:
	return ft_strjoin_nf(ft_strjoin("EBUSY (" , strerror(EBUSY)), ")", 1);
case EEXIST:
	return ft_strjoin_nf(ft_strjoin("EEXIST (" , strerror(EEXIST)), ")", 1);
case EXDEV:
	return ft_strjoin_nf(ft_strjoin("EXDEV (" , strerror(EXDEV)), ")", 1);
case ENODEV:
	return ft_strjoin_nf(ft_strjoin("ENODEV (" , strerror(ENODEV)), ")", 1);
case ENOTDIR:
	return ft_strjoin_nf(ft_strjoin("ENOTDIR (" , strerror(ENOTDIR)), ")", 1);
case EISDIR:
	return ft_strjoin_nf(ft_strjoin("EISDIR (" , strerror(EISDIR)), ")", 1);
case EINVAL:
	return ft_strjoin_nf(ft_strjoin("EINVAL (" , strerror(EINVAL)), ")", 1);
case EMFILE:
	return ft_strjoin_nf(ft_strjoin("EMFILE (" , strerror(EMFILE)), ")", 1);
case ENFILE:
	return ft_strjoin_nf(ft_strjoin("ENFILE (" , strerror(ENFILE)), ")", 1);
case ENOTTY:
	return ft_strjoin_nf(ft_strjoin("ENOTTY (" , strerror(ENOTTY)), ")", 1);
case ETXTBSY:
	return ft_strjoin_nf(ft_strjoin("ETXTBSY (" , strerror(ETXTBSY)), ")", 1);
case EFBIG:
	return ft_strjoin_nf(ft_strjoin("EFBIG (" , strerror(EFBIG)), ")", 1);
case ENOSPC:
	return ft_strjoin_nf(ft_strjoin("ENOSPC (" , strerror(ENOSPC)), ")", 1);
case ESPIPE:
	return ft_strjoin_nf(ft_strjoin("ESPIPE (" , strerror(ESPIPE)), ")", 1);
case EROFS:
	return ft_strjoin_nf(ft_strjoin("EROFS (" , strerror(EROFS)), ")", 1);
case EMLINK:
	return ft_strjoin_nf(ft_strjoin("EMLINK (" , strerror(EMLINK)), ")", 1);
case EPIPE:
	return ft_strjoin_nf(ft_strjoin("EPIPE (" , strerror(EPIPE)), ")", 1);
case EDOM:
	return ft_strjoin_nf(ft_strjoin("EDOM: (" , strerror(EDOM)), ")", 1);
case ERANGE:
	return ft_strjoin_nf(ft_strjoin("ERANGE (" , strerror(ERANGE)), ")", 1);
case EAGAIN:
	return ft_strjoin_nf(ft_strjoin("EAGAIN (" , strerror(EAGAIN)), ")", 1);
		default:
			return "errno not found";
	}

}
