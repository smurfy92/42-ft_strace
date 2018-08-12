
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
		default:
			return "function not found";

	}

}
#define SYS_epoll_create __NR_epoll_create
#define SYS_epoll_create1 __NR_epoll_create1
#define SYS_epoll_ctl __NR_epoll_ctl
#define SYS_epoll_pwait __NR_epoll_pwait
#define SYS_epoll_wait __NR_epoll_wait
#define SYS_eventfd __NR_eventfd
#define SYS_eventfd2 __NR_eventfd2
#define SYS_execve __NR_execve
#define SYS_exit __NR_exit
#define SYS_exit_group __NR_exit_group
#define SYS_faccessat __NR_faccessat
#define SYS_fadvise64 __NR_fadvise64
#define SYS_fallocate __NR_fallocate
#define SYS_fanotify_init __NR_fanotify_init
#define SYS_fanotify_mark __NR_fanotify_mark
#define SYS_fchdir __NR_fchdir
#define SYS_fchmod __NR_fchmod
#define SYS_fchmodat __NR_fchmodat
#define SYS_fchown __NR_fchown
#define SYS_fchownat __NR_fchownat
#define SYS_fcntl __NR_fcntl
#define SYS_fdatasync __NR_fdatasync
#define SYS_fgetxattr __NR_fgetxattr
#define SYS_finit_module __NR_finit_module
#define SYS_flistxattr __NR_flistxattr
#define SYS_flock __NR_flock
#define SYS_fork __NR_fork
#define SYS_fremovexattr __NR_fremovexattr
#define SYS_fsetxattr __NR_fsetxattr
#define SYS_fstat __NR_fstat
#define SYS_fstatfs __NR_fstatfs
#define SYS_fsync __NR_fsync
#define SYS_ftruncate __NR_ftruncate
#define SYS_futex __NR_futex
#define SYS_futimesat __NR_futimesat
#define SYS_get_mempolicy __NR_get_mempolicy
#define SYS_get_robust_list __NR_get_robust_list
#define SYS_getcpu __NR_getcpu
#define SYS_getcwd __NR_getcwd
#define SYS_getdents __NR_getdents
#define SYS_getdents64 __NR_getdents64
#define SYS_getegid __NR_getegid
#define SYS_geteuid __NR_geteuid
#define SYS_getgid __NR_getgid
#define SYS_getgroups __NR_getgroups
#define SYS_getitimer __NR_getitimer
#define SYS_getpeername __NR_getpeername
#define SYS_getpgid __NR_getpgid
#define SYS_getpgrp __NR_getpgrp
#define SYS_getpid __NR_getpid
#define SYS_getpmsg __NR_getpmsg
#define SYS_getppid __NR_getppid
#define SYS_getpriority __NR_getpriority
#define SYS_getresgid __NR_getresgid
#define SYS_getresuid __NR_getresuid
#define SYS_getrlimit __NR_getrlimit
#define SYS_getrusage __NR_getrusage
#define SYS_getsid __NR_getsid
#define SYS_getsockname __NR_getsockname
#define SYS_getsockopt __NR_getsockopt
#define SYS_gettid __NR_gettid
#define SYS_gettimeofday __NR_gettimeofday
#define SYS_getuid __NR_getuid
#define SYS_getxattr __NR_getxattr
#define SYS_init_module __NR_init_module
#define SYS_inotify_add_watch __NR_inotify_add_watch
#define SYS_inotify_init __NR_inotify_init
#define SYS_inotify_init1 __NR_inotify_init1
#define SYS_inotify_rm_watch __NR_inotify_rm_watch
#define SYS_io_cancel __NR_io_cancel
#define SYS_io_destroy __NR_io_destroy
#define SYS_io_getevents __NR_io_getevents
#define SYS_io_setup __NR_io_setup
#define SYS_io_submit __NR_io_submit
#define SYS_ioctl __NR_ioctl
#define SYS_ioperm __NR_ioperm
#define SYS_iopl __NR_iopl
#define SYS_ioprio_get __NR_ioprio_get
#define SYS_ioprio_set __NR_ioprio_set
#define SYS_kcmp __NR_kcmp
#define SYS_kexec_load __NR_kexec_load
#define SYS_keyctl __NR_keyctl
#define SYS_kill __NR_kill
#define SYS_lchown __NR_lchown
#define SYS_lgetxattr __NR_lgetxattr
#define SYS_link __NR_link
#define SYS_linkat __NR_linkat
#define SYS_listen __NR_listen
#define SYS_listxattr __NR_listxattr
#define SYS_llistxattr __NR_llistxattr
#define SYS_lookup_dcookie __NR_lookup_dcookie
#define SYS_lremovexattr __NR_lremovexattr
#define SYS_lseek __NR_lseek
#define SYS_lsetxattr __NR_lsetxattr
#define SYS_lstat __NR_lstat
#define SYS_madvise __NR_madvise
#define SYS_mbind __NR_mbind
#define SYS_migrate_pages __NR_migrate_pages
#define SYS_mincore __NR_mincore
#define SYS_mkdir __NR_mkdir
#define SYS_mkdirat __NR_mkdirat
#define SYS_mknod __NR_mknod
#define SYS_mknodat __NR_mknodat
#define SYS_mlock __NR_mlock
#define SYS_mlockall __NR_mlockall
#define SYS_mmap __NR_mmap
#define SYS_modify_ldt __NR_modify_ldt
#define SYS_mount __NR_mount
#define SYS_move_pages __NR_move_pages
#define SYS_mprotect __NR_mprotect
#define SYS_mq_getsetattr __NR_mq_getsetattr
#define SYS_mq_notify __NR_mq_notify
#define SYS_mq_open __NR_mq_open
#define SYS_mq_timedreceive __NR_mq_timedreceive
#define SYS_mq_timedsend __NR_mq_timedsend
#define SYS_mq_unlink __NR_mq_unlink
#define SYS_mremap __NR_mremap
#define SYS_msgctl __NR_msgctl
#define SYS_msgget __NR_msgget
#define SYS_msgrcv __NR_msgrcv
#define SYS_msgsnd __NR_msgsnd
#define SYS_msync __NR_msync
#define SYS_munlock __NR_munlock
#define SYS_munlockall __NR_munlockall
#define SYS_munmap __NR_munmap
#define SYS_name_to_handle_at __NR_name_to_handle_at
#define SYS_nanosleep __NR_nanosleep
#define SYS_newfstatat __NR_newfstatat
#define SYS_open __NR_open
#define SYS_open_by_handle_at __NR_open_by_handle_at
#define SYS_openat __NR_openat
#define SYS_pause __NR_pause
#define SYS_perf_event_open __NR_perf_event_open
#define SYS_personality __NR_personality
#define SYS_pipe __NR_pipe
#define SYS_pipe2 __NR_pipe2
#define SYS_pivot_root __NR_pivot_root
#define SYS_poll __NR_poll
#define SYS_ppoll __NR_ppoll
#define SYS_prctl __NR_prctl
#define SYS_pread64 __NR_pread64
#define SYS_preadv __NR_preadv
#define SYS_prlimit64 __NR_prlimit64
#define SYS_process_vm_readv __NR_process_vm_readv
#define SYS_process_vm_writev __NR_process_vm_writev
#define SYS_pselect6 __NR_pselect6
#define SYS_ptrace __NR_ptrace
#define SYS_putpmsg __NR_putpmsg
#define SYS_pwrite64 __NR_pwrite64
#define SYS_pwritev __NR_pwritev
#define SYS_quotactl __NR_quotactl
#define SYS_read __NR_read
#define SYS_readahead __NR_readahead
#define SYS_readlink __NR_readlink
#define SYS_readlinkat __NR_readlinkat
#define SYS_readv __NR_readv
#define SYS_reboot __NR_reboot
#define SYS_recvfrom __NR_recvfrom
#define SYS_recvmmsg __NR_recvmmsg
#define SYS_recvmsg __NR_recvmsg
#define SYS_remap_file_pages __NR_remap_file_pages
#define SYS_removexattr __NR_removexattr
#define SYS_rename __NR_rename
#define SYS_renameat __NR_renameat
#define SYS_renameat2 __NR_renameat2
#define SYS_request_key __NR_request_key
#define SYS_restart_syscall __NR_restart_syscall
#define SYS_rmdir __NR_rmdir
#define SYS_rt_sigaction __NR_rt_sigaction
#define SYS_rt_sigpending __NR_rt_sigpending
#define SYS_rt_sigprocmask __NR_rt_sigprocmask
#define SYS_rt_sigqueueinfo __NR_rt_sigqueueinfo
#define SYS_rt_sigreturn __NR_rt_sigreturn
#define SYS_rt_sigsuspend __NR_rt_sigsuspend
#define SYS_rt_sigtimedwait __NR_rt_sigtimedwait
#define SYS_rt_tgsigqueueinfo __NR_rt_tgsigqueueinfo
#define SYS_sched_get_priority_max __NR_sched_get_priority_max
#define SYS_sched_get_priority_min __NR_sched_get_priority_min
#define SYS_sched_getaffinity __NR_sched_getaffinity
#define SYS_sched_getattr __NR_sched_getattr
#define SYS_sched_getparam __NR_sched_getparam
#define SYS_sched_getscheduler __NR_sched_getscheduler
#define SYS_sched_rr_get_interval __NR_sched_rr_get_interval
#define SYS_sched_setaffinity __NR_sched_setaffinity
#define SYS_sched_setattr __NR_sched_setattr
#define SYS_sched_setparam __NR_sched_setparam
#define SYS_sched_setscheduler __NR_sched_setscheduler
#define SYS_sched_yield __NR_sched_yield
#define SYS_seccomp __NR_seccomp
#define SYS_security __NR_security
#define SYS_select __NR_select
#define SYS_semctl __NR_semctl
#define SYS_semget __NR_semget
#define SYS_semop __NR_semop
#define SYS_semtimedop __NR_semtimedop
#define SYS_sendfile __NR_sendfile
#define SYS_sendmmsg __NR_sendmmsg
#define SYS_sendmsg __NR_sendmsg
#define SYS_sendto __NR_sendto
#define SYS_set_mempolicy __NR_set_mempolicy
#define SYS_set_robust_list __NR_set_robust_list
#define SYS_set_tid_address __NR_set_tid_address
#define SYS_setdomainname __NR_setdomainname
#define SYS_setfsgid __NR_setfsgid
#define SYS_setfsuid __NR_setfsuid
#define SYS_setgid __NR_setgid
#define SYS_setgroups __NR_setgroups
#define SYS_sethostname __NR_sethostname
#define SYS_setitimer __NR_setitimer
#define SYS_setns __NR_setns
#define SYS_setpgid __NR_setpgid
#define SYS_setpriority __NR_setpriority
#define SYS_setregid __NR_setregid
#define SYS_setresgid __NR_setresgid
#define SYS_setresuid __NR_setresuid
#define SYS_setreuid __NR_setreuid
#define SYS_setrlimit __NR_setrlimit
#define SYS_setsid __NR_setsid
#define SYS_setsockopt __NR_setsockopt
#define SYS_settimeofday __NR_settimeofday
#define SYS_setuid __NR_setuid
#define SYS_setxattr __NR_setxattr
#define SYS_shmat __NR_shmat
#define SYS_shmctl __NR_shmctl
#define SYS_shmdt __NR_shmdt
#define SYS_shmget __NR_shmget
#define SYS_shutdown __NR_shutdown
#define SYS_sigaltstack __NR_sigaltstack
#define SYS_signalfd __NR_signalfd
#define SYS_signalfd4 __NR_signalfd4
#define SYS_socket __NR_socket
#define SYS_socketpair __NR_socketpair
#define SYS_splice __NR_splice
#define SYS_stat __NR_stat
#define SYS_statfs __NR_statfs
#define SYS_swapoff __NR_swapoff
#define SYS_swapon __NR_swapon
#define SYS_symlink __NR_symlink
#define SYS_symlinkat __NR_symlinkat
#define SYS_sync __NR_sync
#define SYS_sync_file_range __NR_sync_file_range
#define SYS_syncfs __NR_syncfs
#define SYS_sysfs __NR_sysfs
#define SYS_sysinfo __NR_sysinfo
#define SYS_syslog __NR_syslog
#define SYS_tee __NR_tee
#define SYS_tgkill __NR_tgkill
#define SYS_time __NR_time
#define SYS_timer_create __NR_timer_create
#define SYS_timer_delete __NR_timer_delete
#define SYS_timer_getoverrun __NR_timer_getoverrun
#define SYS_timer_gettime __NR_timer_gettime
#define SYS_timer_settime __NR_timer_settime
#define SYS_timerfd_create __NR_timerfd_create
#define SYS_timerfd_gettime __NR_timerfd_gettime
#define SYS_timerfd_settime __NR_timerfd_settime
#define SYS_times __NR_times
#define SYS_tkill __NR_tkill
#define SYS_truncate __NR_truncate
#define SYS_tuxcall __NR_tuxcall
#define SYS_umask __NR_umask
#define SYS_umount2 __NR_umount2
#define SYS_uname __NR_uname
#define SYS_unlink __NR_unlink
#define SYS_unlinkat __NR_unlinkat
#define SYS_unshare __NR_unshare
#define SYS_ustat __NR_ustat
#define SYS_utime __NR_utime
#define SYS_utimensat __NR_utimensat
#define SYS_utimes __NR_utimes
#define SYS_vfork __NR_vfork
#define SYS_vhangup __NR_vhangup
#define SYS_vmsplice __NR_vmsplice
#define SYS_wait4 __NR_wait4
#define SYS_waitid __NR_waitid
#define SYS_write __NR_write
#define SYS_writev __NR_writev
