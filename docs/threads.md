# **Threading in C**

## **Thread Basics**
- **Thread creation**: Creating new threads using pthread_create(). Specify start routine and arguments.
- **Thread termination**: Ending threads via pthread_exit() or return from start routine. Clean up resources.
- **Thread IDs**: Unique identifiers for threads. Get with pthread_self(), compare with pthread_equal().
- **Thread attributes**: Configuration options like stack size, scheduling policy set via pthread_attr_t.
- **Thread states**: Running, ready, blocked, terminated. OS schedules thread execution.

## **Thread Synchronization**
- **Mutexes**: Mutual exclusion locks (pthread_mutex_t) to protect shared resources. Lock/unlock for critical sections.
- **Semaphores**: Counting semaphores (sem_t) for resource management. Wait/post operations control access.
- **Condition variables**: pthread_cond_t for thread signaling and coordination. Wait for conditions to be met.
- **Barriers**: pthread_barrier_t synchronizes multiple threads to wait at specific point before proceeding.
- **Spin locks**: Busy-waiting synchronization primitive. Useful for very short critical sections.

## **Data Sharing**
- **Shared memory**: Memory accessible by multiple threads. Must be protected from concurrent access.
- **Thread-local storage**: Per-thread private data using __thread or pthread_key_t. Avoids synchronization.
- **Race conditions**: Bugs from uncontrolled concurrent access to shared data. Prevent with proper synchronization.
- **Deadlock prevention**: Avoiding circular wait conditions through lock ordering and timeout mechanisms.
- **Memory ordering**: Memory barriers and atomic operations ensure proper visibility of shared data.

## **Thread Communication**
- **Message passing**: Structured communication between threads using message queues or channels.
- **Shared queues**: Thread-safe queues for passing data between threads. Often use mutex+condvar.
- **Signals**: Asynchronous notifications between threads using pthread_kill() and signal handlers.
- **Pipes**: Unidirectional communication channels between threads using pipe() system call.
- **Shared memory**: Direct memory sharing for efficient large data transfer between threads.

## **Best Practices**
- **Thread safety**: Design functions and data structures to work correctly with concurrent access.
- **Resource management**: Properly initialize/destroy synchronization objects. Prevent leaks.
- **Error handling**: Check return values from pthread functions. Handle errors gracefully.
- **Performance considerations**: Balance parallelism vs overhead. Avoid excessive synchronization.
- **Debugging threads**: Use thread-aware debuggers, logging, assertions to track threading issues.