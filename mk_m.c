#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVNAME "device_mehdi"

MODULE_DESCRIPTION("Module affichant une simple chaine de caractere en boucle");
MODULE_AUTHOR("El Moussaoui Mehdi");
MODULE_LICENSE("MIT License");

// Notre device imaginaire
static char chaine[] = "Device imaginaire - hello\n";
static int chaine_len;
static int major;

// Primitive systeme read que l'on cherche a implementer pour notre device
static ssize_t device_read(struct file *, char *, size_t, loff_t *);

static struct file_operations fops = {
	.read = device_read
};

static int device_init(void) {
	// Allocation dynamique du major par le noyau
	major = register_chrdev(0, DEVNAME, &fops);
	if(major < 0) {
		printk("Erreur register_chrdev\n");
		return major;
	}
	chaine_len = strlen(chaine);
	return 0;
}

static void device_exit(void) {
	if(major != 0) {
		unregister_chrdev(major, DEVNAME);
	}
}

static ssize_t devide_read(struct file *, char *buf, size_t len, loff_t *off) {
	if(copy_to_user(buf, chaine, chaine_len) != 0) {
		printk("Erreur copy_to_user.\n");
		return -EFAULT;
	}
	return chaine_len;
}

module_init(device_init);
module_exit(device_exit);
