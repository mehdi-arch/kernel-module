# Device Driver for Imaginary Peripheral

<a href="./README.en.md"><img alt="en" src="https://img.shields.io/badge/lang-en-red.svg"/></a>
<a href="./README.md"><img alt="fr" src="https://img.shields.io/badge/land-fr-yellow.svg"/></a>

## Module Installation

- **Compile the module**

```
make
```

- **Insert the module**

```
sudo insmod mk_m.ko
```

## Check its Impact on the System

- **Verify its installation**

```
lsmod|grep device_mehdi
```

- **Check that the device is installed and retrieve the major number**

```
sudo grep device_mehdi /proc/modules
```

- **Create a node for the module**

```
sudo mknod /dev/device_mehdi c {major issu de la commande precedente} 0
```

- **Display the content produced by the module**

```
sudo cat /dev/device_mehdi
```
