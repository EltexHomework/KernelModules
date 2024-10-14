#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

static int major = 0;
static char test_string[15] = "Hello!\n";

ssize_t test_read(struct file *fd, char __user *buff, size_t size, loff_t *off) {
    size_t rc;

    rc = simple_read_from_buffer(buff, size, off, test_string, 15);

    return rc;
}

ssize_t test_write(struct file *fd, const char __user *buff, size_t size, loff_t *off) {
    size_t rc = 0;
    if (size > 15)
        return -EINVAL;

    rc = simple_write_to_buffer(test_string, 15, off, buff, size);

    return rc;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read = test_read,
    .write = test_write
};

int init_module(void) {
    pr_info("Test module is loaded.\n");
    major = register_chrdev(major, "test", &fops);

    if (major < 0)
        return major;
    pr_info("Major number is %d.\n", major);

    return 0;
}

void cleanup_module(void) {
  pr_info("Module unloaded\n");
}

MODULE_LICENSE("GPL");
