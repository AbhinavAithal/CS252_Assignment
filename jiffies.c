#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>
#include <linux/jiffies.h>
#define BUFFER_SIZE 1000
#define PROC_NAME "jiffies"

MODULE_LICENSE("ABC1");
MODULE_AUTHOR("ABHINAV");
MODULE_DESCRIPTION("DISPLAYING JIFFIES");

static int proc_init(void);
static void proc_exit(void);
struct proc_dir_entry *my_proc;

/* This function is called each time /proc/jiffies is read */
ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
  int result = 0;
  char buffer[BUFFER_SIZE];
  static int completed = 0;
  if (completed)
  {
	completed = 0;
	return 0;
  }
  completed = 1;
  result = sprintf(buffer, "Value of Jiffies: %lu\n", jiffies);

  /* copies kernel space buffer to user space usr buf */
  copy_to_user(usr_buf, buffer, result);
  return result;
}

/* File operation on proc */

static struct file_operations proc_ops =
{
  .owner=THIS_MODULE,
  .read=proc_read,
};


/*This function is called when the module is loaded. */

int proc_init(void)
{
  my_proc =  proc_create(PROC_NAME, 0666, NULL, &proc_ops); //creates the /proc/jiffies entry
  return 0;
}

/*This function is called when the module is removed. */
void proc_exit(void)
{
  remove_proc_entry(PROC_NAME, NULL); //removes the /proc/jiffies entry
}

module_init(proc_init);
module_exit(proc_exit);
