/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:35:37 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/17 15:35:38 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_strace.h"

char *get_syscall_name(int key)
{
	switch (key) {
		case (SYS_access):
			return "access";
		case (SYS_accept):
			return "accept";
		case (SYS_accept4):
			return "accept4";
		case (SYS_acct):
			return "acct";
		case (SYS_add_key):
			return "add_key";
		case (SYS_adjtimex):
			return "adjtimex";
		case (SYS_afs_syscall):
			return "afs_syscall";
		case (SYS_alarm):
			return "alarm";
		case (SYS_arch_prctl):
			return "arch_prctl";
		case (SYS_bind):
			return "bind";
		case (SYS_brk):
			return "brk";
		case (SYS_capget):
			return "capget";
		case (SYS_capset):
			return "capset";
		case (SYS_chdir):
			return "chdir";
		case (SYS_chmod):
			return "chmod";
		case (SYS_chown):
			return "chown";
		case (SYS_chroot):
			return "chroot";
		case (SYS_clock_adjtime):
			return "clock_adjtime";
		case (SYS_clock_getres):
			return "clock_getres";
		case (SYS_clock_gettime):
			return "clock_gettime";
		case (SYS_clock_nanosleep):
			return "clock_nanosleep";
		case (SYS_clock_settime):
			return "clock_settime";
		case (SYS_clone):
			return "clone";
		case (SYS_close):
			return "close";
		case (SYS_connect):
			return "connect";
		case (SYS_creat):
			return "creat";
		case (SYS_delete_module):
			return "delete_module";
		case (SYS_dup):
			return "dup";
		case (SYS_dup2):
			return "dup2";
		case (SYS_dup3):
			return "dup3";
		case (SYS_epoll_create):
			return "epoll_create";
		case (SYS_epoll_create1):
			return "epoll_create1";
		case (SYS_epoll_ctl):
			return "epoll_ctl";
		case (SYS_epoll_pwait):
			return "epoll_pwait";
		case (SYS_epoll_wait):
			return "epoll_wait";
		case (SYS_eventfd):
			return "eventfd";
		case (SYS_eventfd2):
			return "eventfd2";
		case (SYS_execve):
			return "execve";
		case (SYS_exit):
			return "exit";
		case (SYS_exit_group):
			return "exit_group";
		case (SYS_faccessat):
			return "faccessat";
		case (SYS_fadvise64):
			return "fadvise_64";
		case (SYS_fallocate):
			return "fallocate";
		case (SYS_fanotify_init):
			return "fanotify_init";
		case (SYS_fanotify_mark):
			return "fanotify_mark";
		case (SYS_fchdir):
			return "fchdir";
		case (SYS_fchmod):
			return "fchmod";
		case (SYS_fchmodat):
			return "fchmodat";
		case (SYS_fchown):
			return "fchown";
		case (SYS_fchownat):
			return "fchownat";
		case (SYS_fcntl):
			return "fcntl";
		case (SYS_fdatasync):
			return "fdatasync";
		case (SYS_fgetxattr):
			return "fgetxattr";
		case (SYS_finit_module):
			return "finit_module";
		case (SYS_flistxattr):
			return "flistxattr";
		case (SYS_flock):
			return "flock";
		case (SYS_fork):
			return "fork";
		case (SYS_fremovexattr):
			return "fremovexattr";
		case (SYS_fsetxattr):
			return "fsetxattr";
		case (SYS_fstat):
			return "fstat";
		case (SYS_fstatfs):
			return "fstatfs";
		case (SYS_fsync):
			return "fsync";
		case (SYS_ftruncate):
			return "ftruncate";
		case (SYS_futex):
			return "futex";
		case (SYS_futimesat):
			return "futimesat";
		case (SYS_get_mempolicy):
			return "get_mempolicy";
		case (SYS_get_robust_list):
			return "get_robust_list";
		case (SYS_getcpu):
			return "getcpu";
		case (SYS_getcwd):
			return "getcwd";
		case (SYS_getdents):
			return "getdents";
		case (SYS_getdents64):
			return "getdents64";
		case (SYS_getegid):
			return "getegid";
		case (SYS_geteuid):
			return "geteuid";
		case (SYS_getgid):
			return "getgid";
		case (SYS_getgroups):
			return "getgroups";
		case (SYS_getitimer):
			return "getitimer";
		case (SYS_getpeername):
			return "getpeername";
		case (SYS_getpgid):
			return "getpgid";
		case (SYS_getpgrp):
			return "getpgrp";
		case (SYS_getpid):
			return "getpid";
		case (SYS_getpmsg):
			return "getpmsg";
		case (SYS_getppid):
			return "getppid";
		case (SYS_getpriority):
			return "getpriority";
		case (SYS_getresgid):
			return "getresgid";
		case (SYS_getresuid):
			return "getresuid";
		case (SYS_getrlimit):
			return "getrlimit";
		case (SYS_getrusage):
			return "getrusage";
		case (SYS_getsid):
			return "getsid";
		case (SYS_getsockname):
			return "getsockname";
		case (SYS_getsockopt):
			return "getsockopt";
		case (SYS_gettid):
			return "gettid";
		case (SYS_gettimeofday):
			return "gettimeofday";
		case (SYS_getuid):
			return "getuid";
		case (SYS_getxattr):
			return "getxattr";
		case (SYS_init_module):
			return "init_module";
		case (SYS_inotify_add_watch):
			return "inotify_add_watch";
		case (SYS_inotify_init):
			return "inotify_init";
		case (SYS_inotify_init1):
			return "inotify_init1";
		case (SYS_inotify_rm_watch):
			return "inotify_rm_watch";
		case (SYS_io_cancel):
			return "io_cancel";
		case (SYS_io_destroy):
			return "io_destroy";
		case (SYS_io_getevents):
			return "io_getevents";
		case (SYS_io_setup):
			return "io_setup";
		case (SYS_io_submit):
			return "io_submit";
		case (SYS_ioctl):
			return "ioctl";
		case (SYS_ioperm):
			return "ioperm";
		case (SYS_iopl):
			return "iopl";
		case (SYS_ioprio_get):
			return "ioprio_get";
		case (SYS_ioprio_set):
			return "ioprio_set";
		case (SYS_kcmp):
			return "kcmp";
		case (SYS_kexec_load):
			return "kexec_load";
		case (SYS_keyctl):
			return "keyctl";
		case (SYS_kill):
			return "kill";
		case (SYS_lchown):
			return "lchown";
		case (SYS_lgetxattr):
			return "lgetxattr";
		case (SYS_link):
			return "link";
		case (SYS_linkat):
			return "linkat";
		case (SYS_listen):
			return "listen";
		case (SYS_listxattr):
			return "listxattr";
		case (SYS_llistxattr):
			return "llistxattr";
		case (SYS_lookup_dcookie):
			return "lookup_dcookie";
		case (SYS_lremovexattr):
			return "lremovexattr";
		case (SYS_lseek):
			return "lseek";
		case (SYS_lsetxattr):
			return "lsetxattr";
		case (SYS_lstat):
			return "lstat";
		case (SYS_madvise):
			return "madvise";
		case (SYS_mbind):
			return "mbind";
		case (SYS_migrate_pages):
			return "migrate_pages";
		case (SYS_mincore):
			return "mincore";
		case (SYS_mkdir):
			return "mkdir";
		case (SYS_mkdirat):
			return "mkdirat";
		case (SYS_mknod):
			return "mknod";
		case (SYS_mknodat):
			return "mknodat";
		case (SYS_mlock):
			return "mlock";
		case (SYS_mlockall):
			return "mlockall";
		case (SYS_mmap):
			return "mmap";
		case (SYS_modify_ldt):
			return "modify_ldt";
		case (SYS_mount):
			return "mount";
		case (SYS_move_pages):
			return "move_pages";
		case (SYS_mprotect):
			return "mprotect";
		case (SYS_mq_getsetattr):
			return "getsetattr";
		case (SYS_mq_notify):
			return "mq_notify";
		case (SYS_mq_open):
			return "mq_open";
		case (SYS_mq_timedreceive):
			return "mq_timedreceive";
		case (SYS_mq_timedsend):
			return "mq_timedsend";
		case (SYS_mq_unlink):
			return "mq_unlink";
		case (SYS_mremap):
			return "mremap";
		case (SYS_msgctl):
			return "msgctl";
		case (SYS_msgget):
			return "msgget";
		case (SYS_msgrcv):
			return "msgrcv";
		case (SYS_msgsnd):
			return "msgsnd";
		case (SYS_msync):
			return "msync";
		case (SYS_munlock):
			return "munlock";
		case (SYS_munlockall):
			return "munlockall";
		case (SYS_munmap):
			return "munmap";
		case (SYS_name_to_handle_at):
			return "name_to_handle_at";
		case (SYS_nanosleep):
			return "nanosleep";
		case (SYS_newfstatat):
			return "newftstatat";
		case (SYS_open):
			return "open";
		case (SYS_open_by_handle_at):
			return "open_by_handle_at";
		case (SYS_openat):
			return "openat";
		case (SYS_pause):
			return "pause";
		case (SYS_perf_event_open):
			return "perf_event_open";
		case (SYS_personality):
			return "personality";
		case (SYS_pipe):
			return "pipe";
		case (SYS_pipe2):
			return "pipe2";
		case (SYS_pivot_root):
			return "pivot_root";
		case (SYS_poll):
			return "poll";
		case (SYS_ppoll):
			return "ppoll";
		case (SYS_prctl):
			return "prctl";
		case (SYS_pread64):
			return "pread64";
		case (SYS_preadv):
			return "preadv";
		case (SYS_prlimit64):
			return "prlimit64";
		case (SYS_process_vm_readv):
			return "process_vm_readv";
		case (SYS_process_vm_writev):
			return "process_vm_writev";
		case (SYS_pselect6):
			return "pselect6";
		case (SYS_ptrace):
			return "ptrace";
		case (SYS_putpmsg):
			return "putpmsg";
		case (SYS_pwrite64):
			return "pwrite64";
		case (SYS_pwritev):
			return "pwritev";
		case (SYS_quotactl):
			return "quotactl";
		case (SYS_read):
			return "read";
		case (SYS_readahead):
			return "readahead";
		case (SYS_readlink):
			return "readlink";
		case (SYS_readlinkat):
			return "readlinkat";
		case (SYS_readv):
			return "readv";
		case (SYS_reboot):
			return "reboot";
		case (SYS_recvfrom):
			return "recvfrom";
		case (SYS_recvmmsg):
			return "recvmmsg";
		case (SYS_recvmsg):
			return "recvmsg";
		case (SYS_remap_file_pages):
			return "remap_file_pages";
		case (SYS_removexattr):
			return "removexattr";
		case (SYS_rename):
			return "rename";
		case (SYS_renameat):
			return "renameat";
		case (SYS_renameat2):
			return "renameat2";
		case (SYS_request_key):
			return "request_key";
		case (SYS_restart_syscall):
			return "restart_syscall";
		case (SYS_rmdir):
			return "rmdir";
		case (SYS_rt_sigaction):
			return "rt_sigaction";
		case (SYS_rt_sigpending):
			return "rt_sigpending";
		case (SYS_rt_sigprocmask):
			return "rt_sigprocmask";
		case (SYS_rt_sigqueueinfo):
			return "rt_sigqueueinfo";
		case (SYS_rt_sigreturn):
			return "rt_sigreturn";
		case (SYS_rt_sigsuspend):
			return "rt_sigsuspend";
		case (SYS_rt_sigtimedwait):
			return "rt_sigtimedwait";
		case (SYS_rt_tgsigqueueinfo):
			return "rt_tgsigqueueinfo";
		case (SYS_sched_get_priority_max):
			return "sched_get_priority_max";
		case (SYS_sched_get_priority_min):
			return "sched_get_priority_min";
		case (SYS_sched_getaffinity):
			return "sched_getaffinity";
		case (SYS_sched_getattr):
			return "sched_attr";
		case (SYS_sched_getparam):
			return "sched_getparam";
		case (SYS_sched_getscheduler):
			return "sched_get_scheduler";
		case (SYS_sched_rr_get_interval):
			return "sched_rr_get_interval";
		case (SYS_sched_setaffinity):
			return "sched_setaffinity";
		case (SYS_sched_setattr):
			return "sched_setattr";
		case (SYS_sched_setparam):
			return "sched_setparam";
		case (SYS_sched_setscheduler):
			return "sched_setscheduler";
		case (SYS_sched_yield):
			return "sched_yield";
		case (SYS_seccomp):
			return "seccomp";
		case (SYS_security):
			return "security";
		case (SYS_select):
			return "select";
		case (SYS_semctl):
			return "semctl";
		case (SYS_semget):
			return "semget";
		case (SYS_semop):
			return "semop";
		case (SYS_semtimedop):
			return "semtimedop";
		case (SYS_sendfile):
			return "sendfile";
		case (SYS_sendmmsg):
			return "sendmmsg";
		case (SYS_sendmsg):
			return "sendmsg";
		case (SYS_sendto):
			return "sendto";
		case (SYS_set_mempolicy):
			return "set_mempolicy";
		case (SYS_set_robust_list):
			return "set_robust_list";
		case (SYS_set_tid_address):
			return "set_tid_address";
		case (SYS_setdomainname):
			return "setdomainname";
		case (SYS_setfsgid):
			return "setfsgid";
		case (SYS_setfsuid):
			return "setfsuid";
		case (SYS_setgid):
			return "setgid";
		case (SYS_setgroups):
			return "setgroups";
		case (SYS_sethostname):
			return "sethostname";
		case (SYS_setitimer):
			return "setitimer";
		case (SYS_setns):
			return "setns";
		case (SYS_setpgid):
			return "setpgid";
		case (SYS_setpriority):
			return "setpriority";
		case (SYS_setregid):
			return "setregid";
		case (SYS_setresgid):
			return "setresgid";
		case (SYS_setresuid):
			return "setresuid";
		case (SYS_setreuid):
			return "setreuid";
		case (SYS_setrlimit):
			return "settrlimit";
		case (SYS_setsid):
			return "setsid";
		case (SYS_setsockopt):
			return "setsockopt";
		case (SYS_settimeofday):
			return "settimeofday";
		case (SYS_setuid):
			return "setuid";
		case (SYS_setxattr):
			return "setxattr";
		case (SYS_shmat):
			return "shmat";
		case (SYS_shmctl):
			return "shmctl";
		case (SYS_shmdt):
			return "shmdt";
		case (SYS_shmget):
			return "shmget";
		case (SYS_shutdown):
			return "shutdown";
		case (SYS_sigaltstack):
			return "sigaltstack";
		case (SYS_signalfd):
			return "signalfd";
		case (SYS_signalfd4):
			return "signalfd4";
		case (SYS_socket):
			return "socket";
		case (SYS_socketpair):
			return "socketpair";
		case (SYS_splice):
			return "splice";
		case (SYS_stat):
			return "stat";
		case (SYS_statfs):
			return "statfs";
		case (SYS_swapoff):
			return "swapoff";
		case (SYS_swapon):
			return "swapon";
		case (SYS_symlink):
			return "symlink";
		case (SYS_symlinkat):
			return "symlinkat";
		case (SYS_sync):
			return "sync";
		case (SYS_sync_file_range):
			return "sync_file_range";
		case (SYS_syncfs):
			return "syncfs";
		case (SYS_sysfs):
			return "sysfs";
		case (SYS_sysinfo):
			return "sysinfo";
		case (SYS_syslog):
			return "syslog";
		case (SYS_tee):
			return "tee";
		case (SYS_tgkill):
			return "tgkill";
		case (SYS_time):
			return "time";
		case (SYS_timer_create):
			return "timer_create";
		case (SYS_timer_delete):
			return "timer_delete";
		case (SYS_timer_getoverrun):
			return "timer_getoverrun";
		case (SYS_timer_gettime):
			return "timer_gettime";
		case (SYS_timer_settime):
			return "timer_settime";
		case (SYS_timerfd_create):
			return "timerfd_create";
		case (SYS_timerfd_gettime):
			return "timerfd_gettime";
		case (SYS_timerfd_settime):
			return "timerfd_settime";
		case (SYS_times):
			return "times";
		case (SYS_tkill):
			return "tkill";
		case (SYS_truncate):
			return "truncate";
		case (SYS_tuxcall):
			return "tuxcall";
		case (SYS_umask):
			return "umask";
		case (SYS_umount2):
			return "umount2";
		case (SYS_uname):
			return "uname";
		case (SYS_unlink):
			return "unlink";
		case (SYS_unlinkat):
			return "unlinkat";
		case (SYS_unshare):
			return "unshare";
		case (SYS_ustat):
			return "ustat";
		case (SYS_utime):
			return "utime";
		case (SYS_utimensat):
			return "utimensat";
		case (SYS_utimes):
			return "utimes";
		case (SYS_vfork):
			return "vfork";
		case (SYS_vhangup):
			return "vhangup";
		case (SYS_vmsplice):
			return "vmsplice";
		case (SYS_wait4):
			return "wait4";
		case (SYS_waitid):
			return "waitid";
		case (SYS_write):
			return "write";
		case (SYS_writev):
			return "writev";
		default:
			return "function not found";

	}

}
