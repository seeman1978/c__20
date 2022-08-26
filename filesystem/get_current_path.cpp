//
// Created by wq on 22-8-24.
//

#include <string>
#include <sys/stat.h>
#include <iostream>
#include <climits>
#include <unistd.h>

std::string get_process_path(const std::string &str_process){
    struct stat sb{};
    char *buf;
    ssize_t n_bytes, n_buf_size;

    if (lstat(str_process.c_str(), &sb) == -1) {
        std::cout << "lstat error\n";
        return {};
    }

    /* Add one to the link size, so that we can determine whether
       the buffer returned by readlink() was truncated. */

    n_buf_size = sb.st_size + 1;

    /* Some magic symlinks under (for example) /proc and /sys
       report 'st_size' as zero. In that case, take PATH_MAX as
       a "good enough" estimate. */

    if (sb.st_size == 0){
        n_buf_size = PATH_MAX;
    }

    buf = static_cast<char *>(malloc(n_buf_size));
    if (buf == nullptr) {
        std::cout << "malloc error\n";
        return {};
    }

    n_bytes = readlink(str_process.c_str(), buf, n_buf_size);
    if (n_bytes == -1) {
        perror("readlink");
        std::cout << "readlink error\n";
    }

    /* Print only 'nbytes' of 'buf', as it doesn't contain a terminating
       null byte ('\0'). */
    printf("'%s' points to '%.*s'\n", str_process.c_str(), (int) n_bytes, buf);

    /* If the return value was equal to the buffer size, then the
       link target was larger than expected (perhaps because the
       target was changed between the call to lstat() and the call to
       readlink()). Warn the user that the returned target may have
       been truncated. */

    if (n_bytes == n_buf_size){
        printf("(Returned buffer may have been truncated)\n");
    }

    std::string str_process_path{buf};

    free(buf);
    return str_process_path;
}

int main(int argc, char *argv[]) {
    //get_process_path(argv[0]);
    struct stat sb{};
    char *buf;
    ssize_t n_bytes, n_buf_size;

    if (lstat(argv[0], &sb) == -1) {
        std::cout << "lstat error\n";
        return {};
    }

    /* Add one to the link size, so that we can determine whether
       the buffer returned by readlink() was truncated. */

    n_buf_size = sb.st_size + 1;

    /* Some magic symlinks under (for example) /proc and /sys
       report 'st_size' as zero. In that case, take PATH_MAX as
       a "good enough" estimate. */

    if (sb.st_size == 0){
        n_buf_size = PATH_MAX;
    }

    buf = static_cast<char *>(malloc(n_buf_size));
    if (buf == nullptr) {
        std::cout << "malloc error\n";
        return {};
    }

    n_bytes = readlink(argv[0], buf, n_buf_size);
    if (n_bytes == -1) {
        perror("readlink");
        std::cout << "readlink error\n";
    }

    /* Print only 'nbytes' of 'buf', as it doesn't contain a terminating
       null byte ('\0'). */
    printf("'%s' points to '%.*s'\n", argv[0], (int) n_bytes, buf);

    /* If the return value was equal to the buffer size, then the
       link target was larger than expected (perhaps because the
       target was changed between the call to lstat() and the call to
       readlink()). Warn the user that the returned target may have
       been truncated. */

    if (n_bytes == n_buf_size){
        printf("(Returned buffer may have been truncated)\n");
    }

    std::string str_process_path{buf};

    free(buf);
}