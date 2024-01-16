# Pilote de périphérique pour un périphérique imaginaire

<a href="./README.en.md"><img alt="en" src="https://img.shields.io/badge/lang-en-red.svg"/></a>
<a href="./README.md"><img alt="fr" src="https://img.shields.io/badge/land-fr-yellow.svg"/></a>

Implementation d'un device driver (module kernel) sur un peripherique imaginaire.

## Installation du module

- **Compiler le module**

```
make
```

- **Inserer le module**

```
sudo insmod mk_m.ko
```

## Voir son impact sur le systeme

- **Verifier son installation**

```
lsmod|grep device_mehdi
```

- **Verifier que le device est bien installe et recuperer le numero de major**

```
sudo grep device_mehdi /proc/modules
```

- **Creer un node pour le module**

```
sudo mknod /dev/device_mehdi c {major issu de la commande precedente} 0
```
- **Affichage du contenu produit par le module**

```
sudo cat /dev/device_mehdi
```





