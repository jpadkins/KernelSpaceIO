/* ============================================
 * Author: Jacob Adkins
 * Description: a linux kernel module that prints
 * numbers 1 - 100000 into a file when it is initialized.
 */

#include <linux/fs.h>
#include <linux/buffer_head.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/time.h>
#include <asm/segment.h>
#include <asm/uaccess.h>

struct file* file_open(const char* path, int flags, int rights)
{
        struct file* filp = NULL;
        mm_segment_t oldfs;
        int err = 0;

        oldfs = get_fs();
        set_fs(get_ds());
        filp = filp_open(path, flags, rights);
        set_fs(oldfs);
        if (IS_ERR(filp))
        {
                err = PTR_ERR(filp);
                return NULL;
        }
        return filp;
}

void file_close(struct file* filp)
{
        filp_close(filp, NULL);
}

int file_write(struct file* filp, unsigned long long offset, unsigned char* data, unsigned int size)
{
        mm_segment_t oldfs;
        int ret;
        
        oldfs = get_fs();
        set_fs(get_ds());

        ret = vfs_write(filp, data, size, &offset);

        set_fs(oldfs);
        return ret;
}

int file_sync(struct file* filp)
{
        vfs_fsync(filp, 0);
        return 0;
}

int init_module(void)
{ 
        int i;
        long delta;
        struct timespec begin, end;
        struct file* filp;
        unsigned long long offset = 0;
        char str[10];
        
        printk(KERN_INFO "starting write. . . .\n");
        getnstimeofday(&begin); 
                filp = file_open("/home/vagrant/shared/file", O_WRONLY|O_CREAT, 0644); 
                

                for (i = 0; i < 100000; i++)
                {
                        sprintf(str, "%d\n", i);
                        file_write(filp, offset, str, strlen(str));
                        offset += strlen(str);
                }
                
                file_sync(filp);
                file_close(filp);
        getnstimeofday(&end);
        delta = end.tv_nsec - begin.tv_nsec;

        
        
        printk(KERN_INFO "Time Spent: %ld\n", delta);
        return 0;
}

void cleanup_module(void)
{
        printk(KERN_INFO "Goodbye World\n");
}
